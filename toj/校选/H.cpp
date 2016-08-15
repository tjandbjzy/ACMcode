#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int MAXN = 100000 + 100;

int a[MAXN];
int tmp[MAXN];
int ans;

void Merge(int l,int m,int r)
{
    int i = l;
    int j = m + 1;
    int k = l;
    while(i <= m && j <= r)
    {
        if(a[i] > a[j])
        {
            tmp[k++] = a[j++];
            ans += m - i + 1;
        }
        else
        {
            tmp[k++] = a[i++];
        }
    }
    while(i <= m)
	{
		tmp[k++] = a[i++];
	}
	while(j <= r)
	{
		tmp[k++] = a[j++];
	}
	for(int i = l; i <= r; i++)
	{
        a[i] = tmp[i];
	}
	return;
}

void Merge_sort(int l,int r)
{
    if(l < r)
    {
        int m = (l + r) >> 1;
        Merge_sort(l, m);
        Merge_sort(m + 1, r);
        Merge(l, m, r);
    }
	return;
}

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++)
		{
            scanf("%d",a + i);
		}
        ans = 0;
        Merge_sort(0, n - 1);
        printf("%d\n", ans);
    }
    return 0;
}
