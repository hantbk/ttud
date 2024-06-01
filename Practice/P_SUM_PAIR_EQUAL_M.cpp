#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, M;
int res;
int a[MAX];
unordered_set<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> M;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
        if (s.find(M - a[i]) != s.end())
        {
            res++;
        }
        s.insert(a[i]);
    }
    
    cout << res;
    return 0;
}