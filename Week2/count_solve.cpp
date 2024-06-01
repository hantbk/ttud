// Count solutions to an integer linear equation
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e+7
#define INF 1e+18
#define endl "\n"

int n, m, res = 0;
int a[100];
int x[100];

void Try(int k, int sum)
{
    for (int j = 1; j <= (m - sum) / a[k]; j++)
    {
        x[k] = j;
        sum += a[k] * x[k];
        if (k == n - 1)
        {
            if (sum == m)
                res++;
        }
        Try(k + 1, sum);
        sum -= a[k] * x[k];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Try(0, 0);
    cout << res;
    return 0;
}
