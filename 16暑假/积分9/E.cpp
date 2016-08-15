#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <vector>
typedef long long ll;
const double eps = 1e-8;

inline bool Gauss(std::vector< std::vector<double> >  a, std::vector<double> b){
	int r = a.size();
	std::vector< std::vector<double> > c(r, std::vector<double>(r + 1));
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < r; ++j){
			c[i][j] = a[i][j];
		}
	}
	for(int i = 0; i < r; ++i){
		c[i][r] = b[i];
	}
	for(int i = 0; i < r; ++i){
		int t = i;
		for(int j = i; j < r; ++j){
			if(abs(c[j][i] > abs(c[t][i]))){
				t = j;
			}
		}
		std::swap(c[i], c[t]);
		if(fabs(c[i][i]) < eps){
			return true;
		}
		for(int j = i + 1; j <= r; ++j){
			c[i][j] /= c[i][i];
		}
		for(int j = 0; j < r; ++j){
			if(i != j){
				for(int k = i + 1; k <= r; ++k){
					c[j][k] -= c[j][i] * c[i][k];
				}
			}
		}
	}
	return false;
}

int main(){

//	freopen("p.in","r",stdin);
	int cas, cnt = 1;
	scanf("%d", &cas);
	while(cas--){
		int n;
		scanf("%d", &n);
		std::vector< std::vector<double> > a(n, std::vector<double>(n));
		std::vector<double> b(n);
		for(int i = 0; i < b.size(); ++i){
			std::cout << b[i] << std::endl;
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				std::cin >> a[i][j];
				if(i == j){
					a[i][j] -= 1.0;	
				}
			}
		}
		bool flag = Gauss(a, b);
		printf(cnt % 5 == 0 ? "%c\n" : "%c ", flag ? '1' : '0');
		++cnt;
	}
	return 0;
}
