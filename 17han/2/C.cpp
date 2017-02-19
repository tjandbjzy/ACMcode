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
const int MAXN = 1000;
char s[MAXN];


bool ok(char c){
    return ((c >= 'a' && c <= 'z') || c == ' ' || c == '\n' || c == '\t');
}

int main(){
    while(true){
        gets(s);
        int l = strlen(s), i = 0;
        while(i < l){
            if(s[i] == 'E' && s[i + 1] == 'O' && s[i + 2] == 'F' && i + 2 < l){
                goto END;
            }else if(s[i] == 'd' && s[i + 1] == 'd' && i + 1 < l){
                printf("p");
                i += 2;
            }else if(s[i] == 'c' && s[i + 1] == 'e' && s[i + 2] == 'i' && i + 2 < l){
                printf("cei");
                i += 3;
            }else if(s[i] == 'e' && s[i + 1] == 'i' && i + 1 < l){
                printf("ie");
                i += 2;
            }else if(s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'n' && s[i + 3] == 'k' && i + 3 < l){
                printf("floyd");
                i += 4;
            }else if(ok(s[i])){
                printf("%c", s[i]);
                ++i;
            }else{
                ++i;
            }
        } 
        puts("");
    }
    END:

    return 0;
}
