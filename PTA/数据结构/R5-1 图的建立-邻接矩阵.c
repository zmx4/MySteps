#include <stdio.h>
#define MVNum 100 // 最大顶点数
typedef struct
{
	char vexs[MVNum];		// 存放顶点的一维数组
	int arcs[MVNum][MVNum]; // 邻接矩阵
	int vexnum, arcnum;		// 图的当前顶点数和边数
} MGraph;
void CreatMGraph(MGraph *G); /* 创建图 */
void printGraph(MGraph G);	 /*输出图 */
int main()
{
	MGraph G;
	CreatMGraph(&G);
	printGraph(G);
	return 0;
}
void CreatMGraph(MGraph *G)
{
	int i, j, k;
	char a;
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
		G->arcs[j][i] = 1; // 无向图
	}
}
void printGraph(MGraph G)
{
	int i, j;
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%c:", G.vexs[i]);
		for (j = 0; j < G.vexnum; j++)
			if (G.arcs[i][j])
				printf(" %c", G.vexs[j]);
		printf("\n");
	}
}