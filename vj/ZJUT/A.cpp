#include <cstdio>
#include <iostream>

int a[1000];

int main(){
	int cas;
	for(int j = 0; j < 26; ++j){
		a['A' + j] = (j + 1);
		a['a' + j] = -(j + 1);
	}
	scanf("%d", &cas);
	while(cas--){
		char ch;
		int y;
		std::cin >> ch >> y;
		printf("%d\n", a[ch] + y);
	}

	return 0;
}
