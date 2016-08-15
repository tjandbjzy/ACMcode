#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

const int MAXN = 100 + 10;
char s[MAXN];
std::vector<char> v;

void show(std::vector<char> q){
    for(int i = 0; i < q.size(); ++i){
        printf("%c", q[i]);
    }
    puts("");
}

int main(){
    freopen("1039.in", "r", stdin);
    int cas;
    scanf("%d", &cas);
    while(cas--){
        scanf("%s", s);
        v.clear();
        for(int i = 0; s[i] != '\0'; ++i){
            v.push_back(s[i]);
        }
        int ans = 0;
        for(int k = 0; k < 3; ++k){
            char a = 'A' + k;
            //puts("hehe");
            for(int i = 0; i <= v.size(); ++i){
                //puts("hhee");
                std::vector<char> tmp(v);
                tmp.insert(tmp.begin() + i, a);
                int res = 0, cur = 0;
                while(cur != tmp.size() - 1){
                    if(tmp[cur] == tmp[cur + 1]){
                        while(cur != tmp.size() - 1){
                            if(cur == tmp.size() + 1){
                                break;
                            }
                            if(tmp[cur] == tmp[cur + 1]){
                                char t = tmp[cur];
                                //show(tmp);
                                while(cur != tmp.size() && tmp[cur] == t){
                                    ++res;
                                    //printf("%d %lu\n", cur, tmp.size());
                                    tmp.erase(tmp.begin() + cur);
                                    //printf("%d %lu\n", cur, tmp.size());
                                }
                                //show(tmp);
                                //printf("done\n");
                            }
                            ++cur;
                        }
                        cur = 0;
                        continue;
                    }
                    ++cur;
                }
                ans = std::max(ans, res);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
