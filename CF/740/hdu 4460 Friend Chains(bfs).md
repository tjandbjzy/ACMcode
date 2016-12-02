题目链接：http://acm.split.hdu.edu.cn/showproblem.php?pid=4460

题意：给出n个点m条边的关系网，求一个最小的k使得任意两个人之间的距离不大于k。其中，$2 \le n \le 1000$。

想法：此题出在了我们的组队赛里，比赛时刚看觉得只是单纯地Floyd最短路，后来发现n的范围有点大，想法就被否了。后来发现我们并不需要那么多次操作，事实上我们只需要跑两次bfs即可，第一次从任意点出发找到一个最远点，然后再从此最远点出发，找到最大距离即可。对于无解的判断需要用到并查集，当且仅当出现环时k为无穷大，所以像Kruskal那样判断是否存在环即可。赛后和其他队交流时发现他们用的n次bfs，interesting。

代码如下：

```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <map>

typedef long long ll;
const int MAXN = 1000 + 100;
std::map<std::string, int> m;
std::vector<int> G[MAXN];
std::string str, s, t;
std::queue<int> q;
int fa[MAXN], dis[MAXN], n, mx;
bool vis[MAXN];


void init(){
    for(int i = 1; i <= n; ++i){
        fa[i] = i;
        G[i].clear();
    }
    m.clear();
    return;
}

int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int bfs(int s){
    memset(vis, false, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    vis[s] = true;
    dis[s] = 0;
    while(!q.empty()){
        q.pop();
    }
    q.push(s);
    int fr, e, res = 0;
    while(!q.empty()){
       fr = q.front();
       q.pop();
       for(int i = 0; i < G[fr].size(); ++i){
           e = G[fr][i];
           if(!vis[e]){
                vis[e] = true;
                q.push(e);
                dis[e] = dis[fr] + 1;
                if(res < dis[e]){
                    res = dis[e];
                    mx = G[fr][i];
                }
            }
       }
    }
    return res;
}

int main(){
    //freopen("H.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    while(std::cin >> n && n){
        init();
        for(int i = 1; i <= n; ++i){
            std::cin >> str;
            m[str] = i;
        }
        int e;
        //std::cout << "1s\n";
        std::cin >> e;
        int a, b;
        for(int i = 1; i <= e; ++i){
            std::cin >> s >> t;
            a = m[s];
            b = m[t];
            G[a].push_back(b);
            G[b].push_back(a);
            a = find(a);
            b = find(b);
            if(a != b){
                fa[a] = b;
            }
        }
        int cur = 1;
        while(cur < n){
            if(find(cur) != find(cur + 1)){
                break;
            }
            ++cur;
        }
        if(cur < n){
            std::cout << "-1\n";
            continue;
        }else{
            //std::cout <<"hehe\n";
            int ans = bfs(1);
            ans = bfs(mx);
            std::cout << ans << std::endl;
        }
    }
    return 0;
}
```

