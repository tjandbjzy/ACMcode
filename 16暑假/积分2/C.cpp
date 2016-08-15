#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

typedef long long ll;
const int MAXN = 100000 + 10;
int a[MAXN];

bool judge(int a ,int b ,int c ,int d){
	return a + b + c > d && a + b < c + d;
}

int main(){
	int n;
	scanf("%d", &n);
    for (int i = 1; i <= n ; ++i){
        scanf("%d", a + i);
	}
	std::sort(a + 1, a + n + 1);
    bool flag = false;
	for (int i = n - 3; i >= 1 ; --i){
        if(judge(a[i] , a[i + 1] , a[i + 2] , a[i + 3])){
            printf("%d\n", a[i] + a[i + 1] + a[i + 2] + a[i + 3]);
        	flag = true;
			break;
		}
	}
	if(!flag){
		puts("-1");
	}
	return 0;
}
