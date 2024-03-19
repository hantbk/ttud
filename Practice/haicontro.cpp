#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e+7
#define INF 1e+18
#define endl "\n"

int n,a[10000],res,q;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>n>>q;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }

    // O(n^2)
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = i+1; j <= n; j++)
    //     {
    //         if (a[i] + a[j] ==q)
    //         {
    //             res = res + 1;
    //         }
    //     }
    // }

    // O(n)
    // int i = 1;
    // int j = n;
    // while (i < j)
    // {
    //     if (a[i] + a[j] == q)
    //     {
    //         res+=1;
    //         i++;
    //         j--;
    //     } else if (a[i] + a[j] < q)
    //     {
    //         i++;
    //     } else j--;
    // }
    
    cout<<res;

    return 0;
}
