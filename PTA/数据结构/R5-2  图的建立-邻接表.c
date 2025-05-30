#include <stdio.h>
#include <stdlib.h>
#define MVNum 100 // 最大顶点数
typedef struct ArcNode
{							 // 表结点
	int adjvex;				 // 邻接点的位置
	struct ArcNode *nextarc; // 指向下一个表结点的指针
} ArcNode;
typedef struct VNode
{
	char data;			 // 顶点信息
	ArcNode *firstarc;	 // 指向第一个表结点的指针
} VNode, AdjList[MVNum]; // AdjList表示邻接表类型
typedef struct
{
	AdjList vertices;	// 头结点数组
	int vexnum, arcnum; // 图的当前顶点数和边数
} ALGraph;
void CreatMGraph(ALGraph *G); /* 创建图 */
void printGraph(ALGraph G);	  /*输出图 */
int main()
{
	ALGraph G;
	CreatMGraph(&G);
	printGraph(G);
	return 0;
}
void CreatMGraph(ALGraph *G)
{
	int i, j, k;
	ArcNode *s;
	scanf("%d%d", &G->vexnum, &G->arcnum);
	getchar();
	for (i = 0; i < G->vexnum; i++)
		scanf("%c", &G->vertices[i].data);
	for (i = 0; i < G->vexnum; i++)
		G->vertices[i].firstarc = NULL; // 初始化
	for (k = 0; k < G->arcnum; k++)
	{
		scanf("%d%d", &i, &j);
		s = (ArcNode *)malloc(sizeof(ArcNode));
		s->adjvex = j;
		s->nextarc = G->vertices[i].firstarc;
		G->vertices[i].firstarc = s; // 插入到表头
		s = (ArcNode *)malloc(sizeof(ArcNode));
		s->adjvex = i;
		s->nextarc = G->vertices[j].firstarc;
		G->vertices[j].firstarc = s; // 插入到表头
	}
}
void printGraph(ALGraph G)
{
	int i, j;
	ArcNode *p;
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%c:", G.vertices[i].data);
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)
			printf(" %c", G.vertices[p->adjvex].data);
		printf("\n");
	}
}