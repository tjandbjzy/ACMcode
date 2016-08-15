#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge{
    int u, v;
    long long val;
}e[1000005];
int father[100005];
double res;
int n;
vector<pair<int, long long> >V[100005];
bool vis[100005];

bool cmp(Edge aa, Edge bb){
    return aa.val<bb.val;
}

int getFather(int x){
    if(father[x]==x) return x;
    father[x]=getFather(father[x]);
    return father[x];
}

void uni(int x, int y){
    father[x]=y;
}

int dfs(int u, int fa){
    int i, v, cnt=1, tmp;
	vis[u] = true;
    for(i=0;i<V[u].size();i++){
        v=V[u][i].first;
        if(vis[v]) continue;
        tmp=dfs(v, u);
        res+=1.0*tmp*(n-tmp)*V[u][i].second / (1.0 * n * (n - 1));
        cnt+=tmp;
    }
    return cnt;
}

int main(){
    int m, t, i, fa, fb;
    long long ans;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(i=0;i<m;i++){
            scanf("%d %d %lld", &e[i].u, &e[i].v, &e[i].val);
        }
        sort(e, e+m, cmp);
        for(i=1;i<=n;i++){
            V[i].clear();
            father[i]=i;
        }
        ans=0;
        for(i=0;i<m;i++){
            fa=getFather(e[i].u);
            fb=getFather(e[i].v);
            if(fa!=fb){
                ans+=e[i].val;
                uni(fa, fb);
                V[e[i].u].push_back(make_pair(e[i].v, e[i].val));
                V[e[i].v].push_back(make_pair(e[i].u, e[i].val));
            }
        }
		memset(vis, false, sizeof(vis));
        res=0;
        dfs(1,0);
        printf("%lld %.2f\n", ans, res*2.0);
    }
    return 0;
}
