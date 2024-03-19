#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e+7
#define INF 1e+18
#define endl "\n"

int arr[100000], S[100000]={0}, cmd, n;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
        S[i] = S[i-1] + arr[i];
    }
    
    cin>>cmd;
    while (cmd--)
    {
        int i,j;
        cin>>i>>j;
        int res = S[j] - S[i-1];
        cout<<res<<"\n";
    }
    
    return 0;
}
