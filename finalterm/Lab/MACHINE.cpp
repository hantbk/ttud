#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int s[2000009];
int t[2000009];
int maxs[2000009]; // maxs[x] là giá trị đoạn lớn nhất có điểm cuối <= x

void dp()
{
    for (int i = 1; i <= n; i++)
    {
        maxs[t[i]] = max(maxs[t[i]], t[i] - s[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        maxs[i] = max(maxs[i], maxs[i - 1]);
    }

    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        if (maxs[s[i] - 1] > 0)
        {
            ans = max(ans, maxs[s[i] - 1] + t[i] - s[i]);
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> t[i];
    }
    dp();

    return 0;
}