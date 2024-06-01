#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

ll n, a[MAX], sum[MAX], sumChan, sumLe;
ll res = -INF;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sumChan = 0;
    sumLe = INF;

    sum[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
        if (sum[i] % 2 == 0)
        {
            res = max(res, sum[i] - sumChan);
            sumChan = min(sumChan, sum[i]);
        }
        else
        {
            if (sumLe == INF)
            {
                sumLe = sum[i];
            }
            else
            {
                res = max(res, sum[i] - sumLe);
                sumLe = min(sumLe, sum[i]);
            }
        }
    }
    if (res == -INF)
        cout << "NOT_FOUND" << endl;
    cout << res << endl;

    return 0;
}