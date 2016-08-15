#include <cstdio>
#include <algorithm>
#include <iostream> 

typedef long long ll;
const int MAXN =  100000 + 100;
int s[MAXN];
int n;

int cal(){
	//int tn = std::unique(s + 1, s + 1 + n) - s - 1;
	std::sort(s + 1, s + 1 + n);
	int cur = 1;
	for(int i = 1; i <= n; ++i){
		if(s[i] >= cur){
			++cur;
		}
	}
	return cur;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", s + i);
	}
	int mex = cal();
	printf("%d\n", mex);
	
	return 0;
}
