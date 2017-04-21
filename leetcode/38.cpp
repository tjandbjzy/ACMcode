#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>
#include <stack>
#include <set>
#include <ctime>
using namespace std;

typedef long long ll;

string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string a = "1", ans = "";
        for(int i = 1; i < n; ++i){
            int cnt;
            //cout << a.size() << endl;
            for(int j = 0; j < a.size();){
                cnt = 0;
                char c = a[j];
                while(a[j] == c){
                    cnt++;
                    j++;
                }
                ans += to_string(cnt);
                int x = c - '0';
                ans += to_string(x);
            }
            a = ans;
            ans = "";
        }
        return a;
    }

int main(){
    int n;
    while(cin >> n){
        cout << countAndSay(n) << "\n";
    }
    return 0;
}
