#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>
#include <stack>
#include <set>
#include <ctime>

typedef long long ll;
const int MAXN = 1000 +10;
char s[MAXN];

int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        scanf("%s", s);
        int t, sum = 0, sq = 0, len = strlen(s);
        for(int i = 0; i < len; ++i){
            t = s[i] - '0';
            sum += t;
            sq += t * t;
        }
        if(sq % 8 == 0 || sum % 8 == 0){
            puts("Lucky number!");
            continue;
        }
        sum = 0;
        if(len >= 3){
            for(int i = len - 3; i < len; ++i){
                sum = sum * 10 + s[i] - '0';
            }
        }else{
            for(int i = 0; i < len; ++i){
                sum = sum * 10 + s[i] - '0';
            }
        }
        if(sum % 8 == 0){
            puts("Lucky number!");
        }else{
            puts("What a pity!");
        }
    }
    
    return 0;
}
