#include <bits/stdc++.h>
using namespace std;

#define maxn 10000000
int n, q, mi[22][maxn], a[maxn], sum;

int rmq(int l, int r)
{
    int k = log2(r - l + 1);
    return min(mi[k][l], mi[k][r - (1 << k) + 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mi[0][i] = a[i];
    }
    for (int i = 1; i <= log2(n); i++)
    {
        for (int j = 1; j <= (n - (1 << i) + 1); j++)
        {
            mi[i][j] = min(mi[i - 1][j], mi[i - 1][j + (1 << (i - 1))]);
        }
    }
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        sum += rmq(l + 1, r + 1);
    }
    cout << sum;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define maxn 1000000

// int n, a[maxn], f[maxn][22];
// int sum = 0;

// int getMin(int l, int r)
// {

//     int k = log2(r - l + 1);
//     return min(f[1][k], f[r - (1 << k) + 1][k]);
// }

// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         f[i][0] = a[i];
//     }
//     for (int j = 1; (1 << j) <= n; j++)
//     {
//         for (int i = 1; i + (1 << j) - 1 <= n; i++)
//         {
//             f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
//         }
//     }
//     int q;
//     cin>>q;
//     while (q--)
//     {
//         int l, r;
//         cin >> l >> r;
//         cout<< l <<" "<< r <<" "<<getMin(l + 1, r + 1);
//     }

//     return 0;
// }