#ifndef __ROUTE_H__
#define __ROUTE_H__

#include "lib_io.h"

/************************************************************************/
/* 函数部分*/
/************************************************************************/
void deploy_server(char * graph[MAX_EDGE_NUM], int edge_num, char * filename);
void prepareData(char * graph[MAX_EDGE_NUM], int edge_num);
void freeData();
int getIntFromLine(char* line, int order);

/************************************************************************/
/* 数据结构部分*/
/************************************************************************/

//网络节点之间的链路，只有两个节点
struct Route{
	int startNode;
	int endNode;
	int bandWidth;
	int cost;
};

//消费节点到网络节点的链路,只有两个节点
struct Link{
	int consumerNode;
	int netNode;
	int demand;
};

//从服务器节点到消费节点的路径，有若干节点；但题目对节点数有限制
struct Path{
	int * nodes;
	int size;
	int cost;
};

#endif
