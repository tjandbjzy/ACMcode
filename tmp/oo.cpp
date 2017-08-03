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

int *cal(){
    int a[2];
    a[0] = 3;
    a[1] = 4;
    int *x = a;
    return x;
}

int main(){
    int a[2];
    a[0] = 1;
    a[1] = 2;
    int *x = a;
    std::cout << x[0] << " " << x[1] << std::endl;
    x = cal();
    std::cout << x[0] << " " << x[1] << std::endl;
    return 0;
}
