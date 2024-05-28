#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, M;
map<int, int> mp;
int f[MAX];
int res;
int a[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> M;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
        res = (res + mp[M - a[i]]) % MOD;
        mp[a[i]]++;
    }
    
    cout << res;
    return 0;
}