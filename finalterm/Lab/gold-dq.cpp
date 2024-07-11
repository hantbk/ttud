#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, L1, L2;
int a[1000009];
int F[1000009];
int ans = 0;

void dp()
{
    deque<int> dq;
    for (int i = 1; i <= n; i++)
    {
        while (!dq.empty() && dq.front() < i - L2)
            dq.pop_front();
        if (i - L1 >= 1)
        {
            while (!dq.empty() && F[dq.back()] < F[i - L1])
                dq.pop_back();
            dq.push_back(i - L1);
        }
        if (dq.empty())
            F[i] = a[i];
        else
            F[i] = F[dq.front()] + a[i];
        ans = max(ans, F[i]);
    }
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