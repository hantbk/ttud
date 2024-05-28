#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e+7
#define INF 1e+18
#define endl "\n"

int a[10000][10000], S[10000][10000] = {0};
int n,m,p;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>>a[i][j];   
        }
    }
    
    for (int i = 0; i <= n ; i++)
    {
        S[i][0] = 0;
    }
    for (int j = 0; j <= m; j++)
    {
        S[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + a[i][j];
        }
    }

    cin>>p;
    while (p--)
    {
        int a,b,c,d;
        int res = S[c][d] - S[c][b-1] - S[a-1][d] + S[a-1][b-1];
        cout<<res<<endl;
    }
    
    return 0;
}
