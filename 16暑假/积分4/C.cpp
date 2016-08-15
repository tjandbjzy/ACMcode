#include <cstdio>
#include <algorithm>

const int MAXN = 100000 + 100;
char s[MAXN];

int main(){
    scanf("%s", s);
    int ans1 = 0, ans2 = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '0') {
			++ans1;	
		}else{
			++ans2;
		}
    }
    printf("%d\n", std::min(ans1, ans2));
    return 0;
}
