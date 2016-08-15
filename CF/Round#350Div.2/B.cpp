#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 100000 + 100;
int s[MAXN];
long long a[MAXN];

int main(int argc, char const *argv[]){
	int n;
	long long k;
	for(int i = 0; i < MAXN; ++i){
		a[i] = 1LL * (i + 1) * i / 2;
	}
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		scanf("%d", s + i);
	}
	int cur = 1;
	while(a[cur] < k){
		cur++;
	}
	cur--;
	k -=  a[cur];
	printf("%d\n", s[(int)k]);
	return 0;
}