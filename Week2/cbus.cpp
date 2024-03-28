#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e+18
#define endl "\n"

int c[100][100], result = MOD, cmin = MOD;
int n, k;
int a[100];

void Try(int pos, int sl, int sum)
{

    int dem = 0;

    // Dieu kien dung
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 2)
            dem++;
        if (dem == n)
        {
            result = min(result, sum + c[pos][0]);
            return;
        }
    }

    // Cat tia nhanh neu khong the tot hon
    int sum_a = 0;
    for (int i = 1; i <= n; i++)
    {
        sum_a += a[i];
    }
    if (sum + (2*n + 2 - sum_a) * cmin > result)
        return;
    
    // Don hanh khach
    if (sl < k)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0)
            {
                a[i] = 1;
                Try(i, sl + 1, sum + c[pos][i]);
                a[i] = 0;
            }
        }
    }

    // Tra hanh khach
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            a[i] = 2;
            Try(i + n, sl - 1, sum + c[pos][i + n]);
            a[i] = 1;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < 2 * n + 1; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {
            cin >> c[i][j];
            if (c[i][j] > 0)
            {
                cmin = min(cmin, c[i][j]);
            }
        }
    }

    Try(0, 0, 0);
    cout << result;
    return 0;
}
