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
std::priority_queue<int> q;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int x;
    for(int i = 0; i < k; ++i){
        scanf("%d", &x);
        q.push(x);
    }
    for(int i = 0; i < n - k; ++i){
        scanf("%d", &x);
        if(x < q.top()){
            q.pop();
            q.push(x);
        }
    }
    printf("%d\n", q.top());
    
    return 0;
}
