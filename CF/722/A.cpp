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

int main(){
    int a, b, c;
    scanf("%d", &c);
    scanf("%d:%d", &a, &b);
    
    if(c == 12){
        if(a == 0){
            a = 10;
        }else if(a >= 13 && a <= 19){
            a = 11;
        }else if(a >= 20 && a % 10 > 2){
            a = 10 + a % 10;
        }else if(a >= 20 && a % 10 <= 2){
            a = a % 10;
        }
    }
    if(c == 24){
        if(a == 0){
            a = 10;
        }else if(a >= 24 && a <= 29){
            a = 21;
        }else if(a >= 30 && a % 10 >= 4){
            a = 10 + a % 10;
        }else if(a >= 30 && a % 10 < 4){
            a = a % 10;
        }
    }
    if(b > 59){
        b = b % 10;
    }
    if(a > 9){
        printf("%d", a);
    }else{
        printf("0%d", a);
    }
    printf(":");
    if(b > 9){
        printf("%d\n", b);
    }else{
        printf("0%d\n", b);
    }
    
    return 0;
}
