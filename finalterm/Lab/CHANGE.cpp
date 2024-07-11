#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int a[6] = {1, 5, 10, 50, 100, 500};
int res = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    n = 1000 - n;
    for (int i = 5; i >= 0; i--)
    {
        res += n / a[i];
        n %= a[i];
    }
    cout << res;

    return 0;
}