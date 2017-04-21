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

int main(){
    std::string s;
    while(std::cin >> s){
        int sz = 0;
        std::stack<char> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '['){
                st.push('[');
            }else{
                st.pop();
            }
            sz = std::max(sz, (int)st.size());
        }

    }
    
    return 0;
}
