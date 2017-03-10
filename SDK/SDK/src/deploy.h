#ifndef __ROUTE_H__
#define __ROUTE_H__

#include "lib_io.h"

/************************************************************************/
/* ��������*/
/************************************************************************/
void deploy_server(char * graph[MAX_EDGE_NUM], int edge_num, char * filename);
void prepareData(char * graph[MAX_EDGE_NUM], int edge_num);
void freeData();
int getIntFromLine(char* line, int order);

/************************************************************************/
/* ���ݽṹ����*/
/************************************************************************/

//����ڵ�֮�����·��ֻ�������ڵ�
struct Route{
	int startNode;
	int endNode;
	int bandWidth;
	int cost;
};

//���ѽڵ㵽����ڵ����·,ֻ�������ڵ�
struct Link{
	int consumerNode;
	int netNode;
	int demand;
};

//�ӷ������ڵ㵽���ѽڵ��·���������ɽڵ㣻����Ŀ�Խڵ���������
struct Path{
	int * nodes;
	int size;
	int cost;
};

#endif
