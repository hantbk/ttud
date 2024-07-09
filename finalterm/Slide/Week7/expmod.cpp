#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

ull a, b;

ull pow(ull a, ull b)
{
    if (b == 0)
        return 1;
    if (b % 2 != 0)
        return (a * pow(a, b - 1)) % MOD;
    ull res = pow(a, b / 2);
    return (res * res) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    a = a % MOD;

    cout << pow(a, b) << endl;

    return 0;
}