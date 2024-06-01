#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int a[1000009];
int n, c;

bool check(int distance)
{
    int cnt = 1;
    int pos = 1; // Place the first element at the first position

    for (int i = 2; i <= n; i++)
    {
        if (a[i] - a[pos] >= distance)
        {
            cnt++;
            pos = i; // Update the position
        }
        if (cnt == c)
            return true;
    }
    return false;
}

int subSeq()
{
    sort(a + 1, a + n + 1);
    int left = 0;
    int right = a[n-1];
    int result = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (check(mid))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return result;
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
        cin >> n >> c;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cout << subSeq() << endl;
    }

    return 0;
}