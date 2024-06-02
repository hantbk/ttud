#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 10009
#define ll long long
#define MOD 1000000009

int n, k;
int a[MAX];
int sum[MAX];    // sum[i] là tổng giá trị thẩm mỹ của các bó hoa từ 1 đến i
int v[MAX][MAX]; // v[i][j] là giá trị thẩm mỹ tương ứng khi cắm hoa i vào lọ j
int F[MAX][MAX]; // F[i][j] là tổng giá trị thẩm mỹ lớn nhất khi xét đến hoa i và lọ j

void dp()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            F[i][j] = -INF;

    for (int i = 1; i <= k; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (i == j)
                F[i][j] = sum[i];
            else if (i > j)
            {
                F[i][j] = -INF;
            }
            else
            {
                F[i][j] = max(F[i][j - 1], F[i - 1][j - 1] + v[i][j]);
            }
        }
    }

    cout << F[k][n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
            cin >> v[i][j];

    dp();

    return 0;
}
