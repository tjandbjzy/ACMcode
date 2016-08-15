/*
1、	g[v] = 0(v = 1)
	g[v] = min{g[u] + w[u][v]|(u, v) ∈ E}(v != 1)

2、见程序
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

const int INF = 1 << 30; //无穷大
const int MAXN = 1000 + 10;
std::vector<int> G[MAXN];	//存图的方式是vector模拟链表,只存反向边
int g[MAXN];	//g[i]表示到i的最短路径长
int pre[MAXN];	//表示到i的最短路径中i前面点的编号
std::vector<int> ans;	//最短路径

int main(){
	int E, V;
	std:: cin >> V >> E;
	for(int i = 0; i < E; ++i){
		int x, y, z;
		std::cin >> x >> y >> z;
		G[y].push_back(x);	//x到y存在一条有向边
		G[y].push_back(z);	//权值为z
	}

	for(int i = 1; i <= V; ++i){
		g[i] = INF;		//初值设为INF
	}
	g[1] = 0;

	for(int i = 2; i <= V; ++i){
		int v = i;
		for(int j = 0; j < G[i].size(); j += 2){
			int u = G[i][j], w = G[i][j + 1];
			if(g[v] > g[u] + w){	//满足转移条件时发生转移
				pre[v] = u;    //实质是Bellan-Ford算法中的relax操作
				g[v] = g[u] + w;    //并更新pre数组
			}
		}
	}

	for(int i = V; i != 1; i = pre[i]){
		ans.push_back(i);	//读取pre数组并存到ans中
	}
	ans.push_back(1);
	reverse(ans.begin(), ans.end());	//vector的反转操作很方便
	std::cout << "The ans is " << g[V] << "\n";
	std::cout << "The path is ";
	for(int i = 0; i < ans.size(); ++i){
		std::cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
	}

	return 0;
}
/*

样例:

7 10
1 2 1
1 3 4
1 4 6
2 5 7
2 6 6
3 5 1
3 6 5
4 6 8
5 7 2
6 7 1

*/
/*
样例答案:
The ans is 7
The path is 1 3 5 7

*/
