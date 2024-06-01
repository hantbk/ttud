#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
pair<pair<int, int>, int> a[MAX]; // a[i] là thời gian bắt đầu và kết thúc thuê máy i và giá thuê máy i
int L[MAX];                       // L[i] là giá thuê lớn nhất có thể đạt được khi thuê máy từ 1 -> i kết thúc tại i
int res = 0;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.first.second < b.first.second;
}

void dp()
{
    sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= n; i++)
    {
        L[i] = a[i].second;
        for (int j = 1; j < i; j++)
        {
            if (a[j].first.second < a[i].first.first)
            {
                L[i] = max(L[i], L[j] + a[i].second);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        res = max(res, L[i]);
    }
    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;
    }
    dp();

    return 0;
}