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

const int MAXN = 300 + 100;
int s[MAXN];

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}


int main(){
    int n;
    while(std::cin >> n){
        for(int i = 0; i < n; ++i){
            std::cin >> s[i];
        }
        for(int i = 0; i < n; ++i){
            int cnt = 0;
            for(int j = 0; j < n; ++j){
                if(gcd(s[i], s[j]) != 1){
                    cnt++;
                }
            }
            if(cnt == n){
                printf("%d\n", s[i]);
            }
        }
    }
    
    return 0;
}
