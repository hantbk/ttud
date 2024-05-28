#include <bits/stdc++.h>
using namespace std;
#define maxn 1000005

int a[maxn];
int M[22][maxn];
int n;
int res;

void preprocess()
{
    for (int i = 0; i < n; i++)
    {
        M[0][i] = i;
    }

    for (int i = 1; (1 << i) <= n; i++)
    {
        for (int j = 0; j + (1 << i) - 1 < n; j++)
        {
            if (a[M[i - 1][j]] < a[M[i - 1][j + (1 << (i - 1))]])
            {
                M[i][j] = M[i - 1][j];
            }
            else
            {
                M[i][j] = M[i - 1][j + (1 << (i - 1))];
            }
        }
    }
}

void rmq(int l, int r)
{
    int k = log2(r - l + 1);
    if (a[M[k][l]] < a[M[k][r - (1 << k) + 1]])
    {
        res += a[M[k][l]];
    }
    else
    {
        res += a[M[k][r - (1 << k) + 1]];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    preprocess();
    cin >> k;
    while (k--)
    {
        int l, r;
        cin >> l >> r;
        rmq(l, r);
    }
    
    cout << res << endl;

    return 0;
}