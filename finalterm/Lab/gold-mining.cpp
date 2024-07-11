#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, L1, L2;
int a[1000009];
int F[1000009]; // F[i] là số lượng vàng lớn nhất có thể lấy được từ 1...i nếu kho i là kho cuối cùng lấy vàng

void dp()
{
    for (int i = 1; i <= n; i++)
        F[i] = a[i];

    for (int i = L1; i <= n; i++)
    {
        for (int j = i - L2; j <= i - L1; j++)
        {
            F[i] = max(F[i], F[j] + a[i]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, F[i]);

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp();

    return 0;
}