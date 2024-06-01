#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int N, T, D;
int a[10005];
int t[10005];

int F[10009][10009]; // F[i][k] là số lượng hàng lớn nhất có thể lấy được nếu chỉ xét những
// warehouse từ 1 -> i -1, lấy hàng ở kho i và thời gian lấy hàng không vượt quá k

void dp()
{
    for (int i = 1; i <= N; i++)
    {
        for (int k = t[i]; k <= T; k++)
        {
            F[i][k] = a[i];

            if (k < t[i])
            {
                F[i][k] = 0;
                continue;
            }
            else
            {
                for (int j = max(1, i - D); j <= i - 1; j++)
                {
                    F[i][k] = max(F[i][k], F[j][k - t[i]] + a[i]);
                }
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int k = 1; k <= T; k++)
        {
            res = max(res, F[i][k]);
        }
    }
    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> T >> D;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i <= N; i++)
        cin >> t[i];

    dp();

    return 0;
}