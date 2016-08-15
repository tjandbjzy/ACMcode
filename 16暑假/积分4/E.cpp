#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

typedef long long ll;
const int MAXN = 100 + 10;
ll a[MAXN][MAXN];
ll sum[MAXN], all;

int main(){
    int n;
    while(std::cin >> n){
        all = 0;
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
				std::cin >> a[i][j];
				sum[i] += a[i][j];
                all += a[i][j];
            }
		}
        ll s = all / (n - 1);
        for(int i = 0; i < n; ++i){
            a[i][i] = s - sum[i];
		}
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
            	std::cout << a[i][j];
				if(j == n - 1){
					std::cout << "\n";	
				}else{
					std::cout << " ";
				}
			}
		}
    }
    return 0;
}
