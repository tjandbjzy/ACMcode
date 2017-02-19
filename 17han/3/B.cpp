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

int cal(std::string s){
    return (s == "+" || s == "-") ? 0 : 1;
}

int foo(int a, std::string b, int c){
    if(b == "+"){
        return a + c;
    }else if(b == "-"){
        return a - c;
    }else if(b == "*"){
        return a * c;
    }else if(b == "/"){
        return a / c;
    }else{
        return a % c;
    }
}

int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int a, b, c;
        std::string x, y;
        std::cin >> a >> x >> b >> y >> c;
        int ans;
        if(cal(x) >= cal(y)){
            ans = foo(a, x, b);
            ans = foo(ans, y, c);
        }else{
            ans = foo(b, y, c);
            ans = foo(a, x, ans);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
