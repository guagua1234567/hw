#include "deploy.h"
#include <stdio.h>

//以下是做出修改部分
#include<cstdlib>
#include <string>
//声明全局变量
Route** graphics;		//使用矩阵保存网络节点拓扑图
Link* links;			//使用数组保存消费节点和网络节点的关系
int serverCost;			//服务器部署费用
int netNodeNum;			//网络节点数目
int routeNum;			//网络节点之间链路数目
int consumerNodeNum;	//消费节点数目

void deploy_server(char * topo[MAX_EDGE_NUM], int line_num, char * filename)
{
	//1、对数据预处理
	prepareData(topo, line_num);

	//2、处理数据

	//3、写入结果到指定文件
	//write_result(topo_file, filename);

	//4、释放资源
	freeData();
}

void prepareData(char * graph[MAX_EDGE_NUM], int edge_num){
	netNodeNum = getIntFromLine(graph[0], 0);
	routeNum = getIntFromLine(graph[0], 1);
	consumerNodeNum = getIntFromLine(graph[0], 2);
	serverCost = getIntFromLine(graph[2], 0);

	graphics = new Route*[netNodeNum];
	for (int i = 0; i < netNodeNum; i++){
		graphics[i] = new Route[netNodeNum];
	}

	//网络节点拓扑图置空值
	Route emptyRoute = { -1, -1, -1, -1 };
	for (int i = 0; i < netNodeNum; i++){
		for (int j = 0; j < netNodeNum; j++){
			graphics[i][j] = emptyRoute;
		}
	}

	//填充网络节点拓扑图
	Route tmpRoute = { 0, 0, 0, 0 };
	for (int i = 4; i < 4 + routeNum; i++){
		tmpRoute.startNode = getIntFromLine(graph[i], 0);
		tmpRoute.endNode = getIntFromLine(graph[i], 1);
		tmpRoute.bandWidth = getIntFromLine(graph[i], 2);
		tmpRoute.cost = getIntFromLine(graph[i], 3);
		graphics[tmpRoute.startNode][tmpRoute.endNode] = tmpRoute;
	}

	//填充数组links
	Link tmpLink = { 0, 0, 0 };
	links = new Link[consumerNodeNum];
	for (int i = 5 + routeNum; i < 5 + routeNum + consumerNodeNum; i++){
		tmpLink.consumerNode = getIntFromLine(graph[i], 0);
		tmpLink.netNode = getIntFromLine(graph[i], 1);
		tmpLink.demand = getIntFromLine(graph[i], 2);
		links[i - 5 - routeNum] = tmpLink;
	}
}

int getIntFromLine(char* line, int order){
	char* tmp = line;
	for (int i = 0; i < order; i++){
		tmp = strchr(tmp, ' ') + 1;
	}
	return atoi(tmp);
}

void freeData(){
	delete[] links;
	for (int i = 0; i < netNodeNum; i++){
		delete[] graphics[i];
	}
	delete[] graphics;
}