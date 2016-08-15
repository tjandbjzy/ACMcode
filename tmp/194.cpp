#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 100;
int ha[MAXN];

bool ok(int x){
	if(x == 1 || x == 0){
		return false;
	}
	if(x == 2 || x == 3){
		return true;
	}
	for(int i = 2; i < x; ++i){
		if(x % i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	string s;
	while(std::cin >> s){
		memset(ha, 0, sizeof(ha));
		for(int i = 0; i < s.size(); ++i){
			ha[s[i] - 'a']++;
		}
		int mi = 1 << 30, ma = -1;
		for(int i = 0; i < 26; ++i){
			if(ha[i]){
				mi = std::min(ha[i], mi);
				ma = std::max(ha[i], ma);
			}
		}
//		printf("%d %d\n", ma, mi);
		if(ok(ma - mi)){
			printf("Lucky Word\n%d\n\n", ma - mi);
		}else{
			printf("No Answer\n0\n\n");
		}
	}


	return 0;
}

