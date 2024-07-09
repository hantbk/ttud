#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int a[100009];
int F[100009];

void dp()
{
    
    for (int i = 1; i <= n; i++)
    {
        F[i] = 1; 
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if ((a[i] + a[j]) % 2 != 0 && a[j] < a[i])
            {
                F[i] = max(F[i], F[j] + 1);
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, F[i]);
    }
    cout << res << endl;
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
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        dp();
    }

    return 0;
}
