#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef long long ll;

int main(){
    ll l1, r1, l2, r2, k;
    std::cin >> l1 >> r1 >> l2 >> r2 >> k;
    ll l, r;
    if(r1 < l2 || l1 > r2){
        puts("0");
        return 0;
    } 
    if(l1 >= l2 && r1 <= r2){
        l = l1;
        r = r1;
    }else if(l1 >= l2 && r1 >= r2){
        l = l1;
        r = r2;
    }else if(l1 <= l2 && r1 <= r2){
        l = l2;
        r = r1;
    }else{
        l = l2;
        r = r2;
    }
    //std::cout << l << "  " << r << std::endl;
    if(k >= l && k <= r){
        std::cout << r - l << std::endl;
    }else{
        std::cout << r - l + 1 << std::endl;
    }
    
    return 0;
}
