#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int N, C;
int a[100009];

bool check(int distance)
{
    int cnt = 1;
    int pos = 1; // Place the first cow at the first position

    for (int i = 2; i <= N; i++)
    {
        if (a[i] - a[pos] >= distance)
        {
            cnt++;
            pos = i;
        }
        if (cnt == C)
            return true;
    }
    return false;
}

int SubSeqMax()
{
    sort(a + 1, a + N + 1);
    int left = 1, right = a[N];
    int ans = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (check(mid))
        {
            ans = max(ans, mid);
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> N >> C;
        for (int i = 1; i <= N; i++)
            cin >> a[i];
        cout<<SubSeqMax()<<endl;
    }

    return 0;
}