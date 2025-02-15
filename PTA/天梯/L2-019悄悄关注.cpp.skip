#include <iostream>
#include <string>
using namespace  std;

int main()
{
    int N;cin>>N;
    string human[N];
    for(int i = 0;i < N;i++)
    {
        cin>>human[i];
    }
    int M;cin>>M;
    string humanList[M];int population[M] = {0};
    int sum = 0, ave = 0;
    for(int i = 0;i < M;i++)
    {
        cin>>humanList[i]>>population[i];
        sum += population[i];
    }
    ave = sum / M;
    for(int i = 0;i < M;i++)
    {
        if(population > ave)
        {
            for(int j = 0;j < N;j++)
            {
                if(humanList[i] == human[N])
                {
                    break;
                }
            }
        }
    }
}