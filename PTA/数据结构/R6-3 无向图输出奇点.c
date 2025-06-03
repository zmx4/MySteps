#include <stdio.h>
#define MVNum 100 // 最大顶点数
typedef struct
{
	char vexs[MVNum];		// 存放顶点的一维数组
	int arcs[MVNum][MVNum]; // 邻接矩阵
	int vexnum, arcnum;		// 图的当前顶点数和边数
} MGraph;
void PrintV(MGraph G);
void CreatMGraph(MGraph *G); /* 创建图 */
int main()
{
	MGraph G;
	CreatMGraph(&G);
	PrintV(G);
	return 0;
}
void CreatMGraph(MGraph *G)
{
	int i, j, k;
	scanf("%d%d", &G->vexnum, &G->arcnum);
	getchar();
	for (i = 0; i < G->vexnum; i++)
		scanf("%c", &G->vexs[i]);
	for (i = 0; i < G->vexnum; i++)
		for (j = 0; j < G->vexnum; j++)
			G->arcs[i][j] = 0;
	for (k = 0; k < G->arcnum; k++)
	{
		scanf("%d%d", &i, &j);
		G->arcs[i][j] = 1;
		G->arcs[j][i] = 1;
	}
}
/* 你的代码将被嵌在这里 */
void PrintV(MGraph G)
{
	int i, j;
	int cnt = 0;
	int isOdd[MVNum] = {0};

	for (i = 0; i < G.vexnum; i++)
	{
		int deg = 0;
		for (j = 0; j < G.vexnum; j++)
		{
			deg += G.arcs[i][j];
		}
		if (deg % 2 == 1)
		{
			isOdd[i] = 1;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	if (cnt > 0)
	{
		for (i = 0; i < G.vexnum; i++)
		{
			if (isOdd[i])
			{
				printf("%c ", G.vexs[i]);
			}
		}
		printf("\n");
	}
}
