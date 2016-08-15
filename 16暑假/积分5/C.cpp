#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include <iostream>

typedef long long ll;
const int MAXN = 200000 + 10;
struct node{
    int d, id;
};

node a[MAXN];
bool cmp(node x, node y){
    return x.d < y.d;
}

int main(){
	std::ios::sync_with_stdio(false);
	int n, sum = 0;
	bool flag = false;
	std::cin >> n;
    for(int i = 0; i < n; ++i){
		std::cin >> a[i].d;
		if(a[i].d > n - 1){
			flag = true;
		}
		sum += a[i].d;
    	a[i].id = i;
	}
    if(flag || sum & 1 || sum != 2 * (n - 1)){
		std::cout << "-1\n";
    }else{
		std::sort(a, a + n, cmp);
        int pos = 0;
		for(int i = 0; i < n; ++i){
			if(a[i].d > 1){
				pos = i;
				break;
			}
		}	
        for(int i = 0; i < n - 2; i++){
			std::cout << a[i].id + 1 << " " << a[pos].id + 1 << "\n";
            a[pos].d--;
           	if(a[pos].d == 1){
				pos++;
			}
		}
		std::cout << a[n - 2].id + 1 << " " << a[n - 1].id + 1 << "\n";
    }
    return 0;
}
