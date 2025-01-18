#include <stdlib.h>
#include <math.h>
#include <SDL.h>

// ���κ���
int isInHeart(float x, float y) {
    float a = x * x + y * y - 1;
    float b = x * x * y * y;
    return a * a * a - b <= 0;
}

// С���ǽṹ��
typedef struct Star {
    float x;
    float y;
    float vx;
    float vy;
} Star;

// ��ʼ��С����
void initStar(Star *star) {
    star->x = rand() % windowWidth;
    star->y = windowHeight;
    star->vx = (rand() % 5 - 2) / 10.0f;  // ˮƽ�ٶȽ�С�����ֵ
    star->vy = -(rand() % 5 + 1) / 10.0f;  // ���ϵ��ٶ�
}

// ����С����λ��
void updateStar(Star *star) {
    star->x += star->vx;
    star->y += star->vy;

    // ����Ч��
    star->vx += 0.01f * star->y;

    if (star->y < 0) {
        initStar(star);
    }
}

// ����С����
void drawStar(Star *star, SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawPointF(renderer, star->x, star->y);
}

// ���ӽṹ��
typedef struct Particle {
    float x;
    float y;
    float vx;
    float vy;
} Particle;

// ��ʼ������������������
void initParticle(Particle *particle) {
    do {
        particle->x = (rand() % (windowWidth + 1)) - windowWidth / 2;
        particle->y = (rand() % (windowHeight + 1)) - windowHeight / 2;
    } while (!isInHeart(particle->x, particle->y));

    particle->vx = (rand() % 20 - 10) / 10.0f;
    particle->vy = (rand() % 20 - 10) / 10.0f;
}

// ��������״̬������������������
void updateParticle(Particle *particle) {
    particle->x += particle->vx;
    particle->y += particle->vy;

    if (!isInHeart(particle->x, particle->y)) {
        // ���㷴������
        float normalX = particle->x;
        float normalY = particle->y;
        float length = sqrt(normalX * normalX + normalY * normalY);
        normalX /= length;
        normalY /= length;

        // ����
        particle->vx = -particle->vx * 0.8;
        particle->vy = -particle->vy * 0.8;

        // ����λ�ûص��߽���
        particle->x = (isInHeart(particle->x + particle->vx, particle->y + particle->vy))? particle->x + particle->vx : particle->x - particle->vx;
        particle->y = (isInHeart(particle->x + particle->vx, particle->y + particle->vy))? particle->y + particle->vy : particle->y - particle->vy;
    }
}

// �������ӣ���ɫ��
void drawParticle(Particle *particle, SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawPointF(renderer, particle->x, particle->y);
}

int main() {
    // ��ʼ��ͼ�ο�ʹ���
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Particle Effect in Heart with Stars", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // ������������
    const int numParticles = 100;
    struct Particle particles[numParticles];
    for (int i = 0; i < numParticles; i++) {
        initParticle(&particles[i]);
    }

    // ����С��������
    const int numStars = 50;
    struct Star stars[numStars];
    for (int i = 0; i < numStars; i++) {
        initStar(&stars[i]);
    }

    int running = 1;
    while (running) {
        // �����¼�
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // ��������״̬
        for (int i = 0; i < numParticles; i++) {
            updateParticle(&particles[i]);
        }

        // ����С����״̬
        for (int i = 0; i < numStars; i++) {
            updateStar(&stars[i]);
        }

        // �����Ļ
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // ��������
        for (int i = 0; i < numParticles; i++) {
            drawParticle(&particles[i], renderer);
        }

        // ����С����
        for (int i = 0; i < numStars; i++) {
            drawStar(&stars[i], renderer);
        }

        // ��ʾ����
        SDL_RenderPresent(renderer);
    }

    // ������Դ
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
