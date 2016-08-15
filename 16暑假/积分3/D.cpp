#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 200000 + 10;
int a[MAXN];

int main(int argc, char const *argv[]){
        int n;
        bool flag = true;
        scanf("%d",&n);
        for (int i = 0; i < n; i++){
                scanf("%d", a + i);
                a[i] += i + 1;
        }
        sort(a, a + n);
        for (int i = 0; i < n - 1; i++)
        if (a[i] == a[i + 1]) {
                flag = false;
                break;
        }
        if(!flag){
                printf(":(\n");
        }
        else{
                for (int i = 0; i < n; i++){
                       printf(i == n - 1 ? "%d\n" : "%d ",a[i] - i - 1);
                }
        }
        return 0;
}
