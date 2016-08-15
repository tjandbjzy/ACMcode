#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int x[27], y[27], l, l1, l2, i, j, p;
    char key[5][5], str1[1001], str2[1001], str[2001], ch;
    bool flag[27];
    l1 = 0;
    while (1)
    {
        ch = getchar();
        if (ch == '\n')
            break;
        if (ch == ' ')
            continue;
        l1 = l1 + 1;
        str1[l1 - 1] = ch - 32;
    }
    for (i = 1; i <= 26; i++)
        if (i != 17)
        {
            l1 = l1 + 1;
            str1[l1 - 1] = i + 64;
        }
    memset (flag, true, sizeof(flag));
    flag[17] = false;
    p = 0;
    for (i = 0; i <= 4; i++)
        for (j = 0; j <= 4; j++)
        {
            while (!flag[str1[p] - 64])
                p = p + 1;
            key[i][j] = str1[p];
            x[str1[p] - 64] = i;
            y[str1[p] - 64] = j;
            flag[str1[p] - 64] = false;
        }
/*
    for (i = 0; i <= 4; i++)
    {
        for (j = 0; j <= 4; j++)
            cout << key[i][j] << ' ';
        cout << endl;
    }
*/
/*
    for (i = 1; i <= 26; i++)
        if (i != 17)
            cout << x[i] << ' ';
    cout << endl;
    for (i = 1; i <= 26; i++)
        if (i != 17)
            cout << y[i] << ' ';
    cout << endl;
*/
    cin.getline (str2, 1000);
    l2 = strlen(str2);
    l = 0;
    for (i = 0; i <= l2 - 1; i++)
    {
        if (str2[i] == ' ')
            continue;
        if (l % 2 == 1 && str2[i] == str2[i - 1])
        {
            l = l + 1;
            str[l - 1] = 'X';
        }
        l = l + 1;
        str[l - 1] = str2[i] - 32;
    }
    if (l % 2 == 1)
    {
        l = l + 1;
        str[l - 1] = 'X';
    }
/*
    for (i = 0; i <= l - 1; i++)
        cout << str[i];
    cout << endl;
*/
    for (i = 0; i <= l - 1; i = i + 2)
    {
        if (x[str[i] - 64] == x[str[i + 1] - 64])
            cout << key[x[str[i] - 64]][(y[str[i] - 64] + 1) % 5] << key[x[str[i + 1] - 64]][(y[str[i + 1] - 64] + 1) % 5];
        else if (y[str[i] - 64] == y[str[i + 1] - 64])
            cout << key[(x[str[i] - 64] + 1) % 5][y[str[i] - 64]] << key[(x[str[i + 1] - 64] + 1) % 5][y[str[i + 1] - 64]];
        else
            cout << key[x[str[i] - 64]][y[str[i + 1] - 64]] << key[x[str[i + 1] - 64]][y[str[i] - 64]];
    }
    cout << endl;
    return 0;
}
