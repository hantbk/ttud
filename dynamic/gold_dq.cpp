#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, L1, L2;
int a[MAX];
int F[MAX]; // F[i] là lượng vàng nhiều nhất nếu nhà kho i là nhà kho cuối cùng được chọn
int res = 0;

void dp()
{
    deque<int> q;
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && (q.front() < i - L2))
            q.pop_front();
        if (i - L1 >= 1)
        {
            while (!q.empty() && F[q.back()] < F[i - L1])
                q.pop_back();
            q.push_back(i - L1);
        }
        if (q.empty())
        {
            F[i] = a[i];
        }
        else
            F[i] = a[i] + F[q.front()];
        res = max(res, F[i]);
    }
    cout << res << endl;
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