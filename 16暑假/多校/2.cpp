#include <cstdio>
#include <algorithm>
#include <cstring>

typedef long long ll;
const int MAXN = 10000 + 100;
const int N = 100 + 30;

char s[MAXN], t[MAXN];
int nexta[MAXN], nextb[MAXN];
int ta[MAXN], tb[MAXN];
int a[N], b[N];

void KMP(char s[], char t[], int next[], int ex[]){
    next[0] = 0;    
    for (int i = 0, j = 0, p = -1; s[i] != '\0'; ++i, ++j, --p){
        if(p == -1){
            j = 0;
            do{
                ++p;
            }while(s[i + p] != '\0' && s[i + p] == t[j + p]);
            ex[i] = p;
        }else if(next[j] != p){
            ex[i] = std::min(next[j], p);
        }else{
            j = 0;
            while(s[i + p] != '\0' && s[i + p] == t[j + p]){
                ++p;
            }
            ex[i] = p;
        }
        if(s[i + 1] == '\0'){
            ex[i + 1] = 0;
        }
    }
    return;
}

void init(){
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    KMP(s + 1, s, nexta, nexta + 1);
    KMP(t, s, nexta, tb);
    KMP(t + 1, t, nextb, nextb + 1);
    KMP(s, t, nextb, ta);
    return;
}

int main(){
   freopen("2.in", "r", stdin);
    while(~scanf("%s %s", s, t)){
          init();
        int l = strlen(s);
        for (int i = 0; i < l; i++){
            ++a[s[i]];
            ++b[t[i]];
            bool f = true, flag;
            for(int j = 0; j < N; ++j){
                if(a[j] != b[j]){
                    f = false;
                    break;
                }
            }
            if(f){
                flag = false;
                for (int j = 0; j <= i; j++){
                    if(ta[i - j + 1] >= j && tb[j] >= i - j + 1){
                        flag = true;
						//printf("i=%d j=%d ta[i-j+1]=%d tb[j]=%d\n", i,j,ta[i-j+1],tb[j]);
						break;
                    }
                }
                if(flag){
                    putchar('1');
                }else{
                    putchar('0');
                } 
            }else{
                putchar('0');
            }
        }
        puts("");
    }
    return 0;
}
