#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e+7
#define INF 1e+18
#define endl "\n"

int res, n, a[10000], Q, S;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>n>>Q;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     int S = 0;
    //     for (int j = i; j <= n; j++)
    //     {
    //         S = S + a[j];
    //         if (S <= q)
    //         {
    //             res = max(res, j-i+1);
    //         }
    //     }
    // }

    int L = 1;
    for (int R = 1; R <= n; R++)
    {
        S = S + a[R];
        while (S > Q)
        {
            S = S - a[L];
            L++;
        }
        res = max(res, R - L + 1);
    }
    cout<<res;

    return 0;
}
