#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

struct node
{
    int d, n;
} a[200010];

bool cmp(node x, node y)
{
    return x.d < y.d;
}

int main()
{
    int sumd(0);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i].d);
        a[i].n = i + 1;
        sumd += a[i].d;
    }
    if(sumd % 2 == 1 || sumd / 2 != n - 1)
        puts("-1");
    else
    {
        sort(a, a + n, cmp);
        int pos(0);
        for(int i = 0; i < n; i++)
        {
            if(a[i].d > 1)
            {
                pos = i;
                break;
            }
        }
        for(int i = 0; i < n - 2; i++)
        {
            printf("%d %d\n", a[i].n, a[pos].n);
            a[pos].d--;
            if(a[pos].d == 1) pos++;
        }
        printf("%d %d\n", a[n - 2].n, a[n - 1].n);
    }

    return 0;
}
Distributed under GPLv3. | Project Homepage | Developer: 51isoft crccw | Current Style: Cerulean.

Select Style:   Fluid Width?
 
