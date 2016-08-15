#include <cstdio>
#include <cstring>

const int MAXN = 2000000 + 100;
typedef long long ll;

ll cnt[MAXN], suf[MAXN], pre[MAXN];
int s[MAXN];
bool vis[MAXN];

int main(){
    int n;
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; ++i){
            scanf("%d", s + i);
        }
        memset(vis, false, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));
        int j = 0;
        for(int i = 0; i < n; ++i){
            while(j < n){
                if(!vis[s[j]]){
                    vis[s[j]] = true;
                }else{
                    break;
                }
                ++j;
            }
            ++cnt[j - i];
            vis[s[i]] = false;
        }/*
        while(cur < n){
            while(tc < n){
                if(!vis[s[tc]]){
                    vis[s[tc]] = true;
                }
                else{
                    break;
                }
                ++tc;
            }
            ++cnt[tc - cur];
            vis[s[cur]] = false;
            ++cur;
        }*/
        suf[n] = cnt[n];
        for(int i = n - 1; i >= 1; --i){
            suf[i] = suf[i + 1] + cnt[i];
        }
        pre[0] = 0;
        for(int i = 1; i <= n; ++i){
            pre[i] = pre[i - 1] + suf[i];
        }
        int q;
        scanf("%d", &q);
        while(q--){
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%lld\n", pre[b] - pre[a - 1]);
        }
    }
    return 0;
}
