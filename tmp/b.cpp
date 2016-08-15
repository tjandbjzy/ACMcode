#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#define X first
#define Y second
#define mp make_pair
using namespace std;

const int maxn=1e6+10;
typedef unsigned long long LL;

const LL P=123;
int n,m;

LL pw[maxn];
LL ha[maxn];
void pre(){
    memset(ha,0,sizeof(ha));
    pw[0]=1;
    for(int i=1;i<maxn;i++) pw[i]=pw[i-1]*P;
}

int main(){
	freopen("E.in", "r", stdin);
    while(~scanf("%d%d",&n,&m)){
    pre();
	vector<pair<int,int> > egs;
    for(int i=0;i<m;i++){
        int u,v; 
        scanf("%d%d",&u,&v);
        egs.push_back(mp(u,v));
        ha[u]+=pw[v];
        ha[v]+=pw[u];
    }
    LL ans=0;
    for(int i=0;i<m;i++){
        int u=egs[i].X,v=egs[i].Y;
        if(ha[u]+pw[u]==ha[v]+pw[v]) ans++;
    }
    sort(ha+1,ha+n+1);
    for(int i=1;i<n;i++){
        if(ha[i]==ha[i+1]){
            int ed=i;
            while(ed+1<=n&&ha[ed]==ha[ed+1]) ed++;
            LL len=ed-i+1;
            ans+=len*(len-1)/2;
            i=ed;
        }
    }
    printf("%lld\n",ans);}
    return 0;
}
