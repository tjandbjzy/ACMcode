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
const double eps = 1e-3;

double NewtonMethod(double x){
    double res = 1;
    while(fabs(res * res - x) > eps){
        res = (res + x / res) / 2.0;
    }
    return res;
}

int main(){
    srand(time(NULL));
    double x;
    while(std::cin >> x){
        double ans = NewtonMethod(x);
        std::cout << "The square root is " << ans << std::endl;
    }
    
    return 0;
}
