#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>
#include <stack>
#include <set>
#include <ctime>

typedef long long ll;
const int MAXN = 100 + 10;
char s[MAXN];
std::string p[10] = {"ling", "yi", "er", "san", "si", "wu","liu", "qi", "ba", "jiu"};
std::vector<int> v;

int main(){
    scanf("%s", s);
    int sum = 0;
    for(int i = 0; s[i]; ++i){
        sum += s[i] - '0';
    }
    while(sum){
        v.push_back(sum % 10);
        sum /= 10;
    }
    for(int i = v.size() - 1; i >= 0; --i){
        std::cout << p[v[i]];
        if(!i){
            std::cout << "\n";
        }else{
            std::cout << " ";
        }
    }
    
    
    return 0;
}
