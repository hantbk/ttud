/*
    Tim day con chung co tong lon nhat cua 2 day
    f(m,n) la tong lon nhat cua 2 day a[1..m] va b[1..n]
    f(m,n) = 0 if m = 0 or n = 0
    f(m,n) = f(m-1,n-1) + a[m] if a[m] = b[n]
    f(m,n) = max(f(m-1,n),f(m,n-1)) if a[m] != b[n]
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000007

int n, m, a[MAX], b[MAX], c[MAX][MAX];

// int f(int m, int n)
// {
//     if (m == 0 || n == 0)
//         return 0;
//     if (a[m] == b[n])
//         return f(m - 1, n - 1) + a[m];
//     return max(f(m - 1, n), f(m, n - 1));
// }

void dp()
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                c[i][j] = 0;
            }
            else if (a[i] == b[j])
            {
                c[i][j] = c[i - 1][j - 1] + a[i];
            }
            else
            {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }
}

// void trace()
// {
//     int i = m, j = n;
//     while (i > 0 && j > 0)
//     {
//         if (a[i] == b[j])
//         {
//             cout << a[i] << " ";
//             i--;
//             j--;
//         }
//         else if (f(i - 1, j) > f(i, j - 1))
//         {
//             i--;
//         }
//         else
//         {
//             j--;
//         }
//     }
// }


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cout << "Nhap m = ";
    cin >> m;
    // cout << "Nhap n = ";
    cin >> n;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    dp();
    cout<<c[m][n];

    // cout << "Day con co tong lon nhat = " << f(m, n) << endl;
    // cout << "Day con co tong lon nhat = " << c[m][n] << endl;
    // trace();

    return 0;
}