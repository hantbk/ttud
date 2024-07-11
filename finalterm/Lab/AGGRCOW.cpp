#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, c;
int x[100009];
int s[100009];

bool check(int d)
{
    s[1] = 1;
    for (int i = 2; i <= c; i++)
    {
        s[i] = -1;
        int k = s[i - 1];
        for (int j = k; j <= n; j++)
        {
            if (x[j] - x[k] >= d)
            {
                s[i] = j;
                break;
            }
        }
        if (s[i] == -1)
            return false;
    }
    return true;
}

int solution()
{
    int minD = 0;
    int maxD = x[n] - x[1];
    int res = 0;
    while (minD <= maxD)
    {
        int d = (minD + maxD) / 2;
        if (check(d))
        {
            res = d;
            minD = d + 1;
        }
        else
        {
            maxD = d - 1;
        }
    }
    return res;
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
        {
            cin >> x[i];
        }
        sort(x + 1, x + n + 1);
        cout << solution() << endl;
    }

    return 0;
}