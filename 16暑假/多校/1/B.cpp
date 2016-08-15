#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = (1 << 20) + 1;;
int dp[maxn];
int cnt = 0;
int n,m;
int dfs(int k)
{
	if(dp[k]!=-1) return dp[k];
	for(int i=0;i<=19;i++){
		int temp = k;
		if((k & (1 << i))!=0) {//printf("i: %d\n",i);
			for(int j=i+1;j<=19;j++){//printf("k: %d  j:  %d\n",k,1 << j);
			//printf("j:  %d\n",1 << j);
				if((k & (1 << j)) == 0) {//printf("llsll  j:  %d\n",j);
					temp = k;
					temp -= (1 << i);
					temp += (1 << j);//printf("dgss %d\n",temp);
					if(dfs(temp) == 0) {//printf("YEEEEEAH  %d\n",temp);
						dp[k] = 1;
						return 1;
					}
					break;
				}
			}
		}
	}
	dp[k]=0;
	return 0;
}
int main()
{
    freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);//cout << 1 << endl;
	memset(dp,-1,sizeof(dp));
	int temp = 0;
	for(int i=19;i>=0;i--){
		temp += 1 << i;
		dp[temp] = 0;
	}
//	printf("%d %d\n",1 << 19,dp[1 << 19]);
//	printf("%d",262144 &  524288);
	int kase;scanf("%d",&kase);
	while(kase--){
		int temp = 0,a;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			temp = 0;
			scanf("%d",&m);
			for(int j=1;j<=m;j++){
				scanf("%d",&a);
			    temp += 1 << (a-1);//printf("temp:  %d\n",temp);
			}
			int flag = dfs(temp);//printf("flag: %d\n",flag);
			if(dp[temp]==1) cnt++;printf("i: %d dp[temp]: %d\n",n,i,dp[temp]);
		}
		if(cnt%2==1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
