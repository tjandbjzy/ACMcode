#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;
const int MAXN = 1000 + 100;
vector<int> G[MAXN];

int main(int argc, char const *argv[]){
    int n;
    while(~scanf("%d", &n)){
        for(int i = 0; i < MAXN; ++i){
            G[i].clear();
        }
        for(int i = 0; i < n; ++i){
            int a, b;
            scanf("%d %d", &a, &b);
            G[a].push_back(b);
        }
        int k = INF, cnt = 0;
        for(int i = 0; i < MAXN; ++i){
            if(k < i){
                ++cnt;
                k = INF;
            }
            for(int j = 0; j < G[i].size(); ++j){
                k = min(k, G[i].at(j));
            }
        }
        if(k < INF){
            ++cnt;
        }
        printf("%d\n",cnt);
    }
    return 0;
}