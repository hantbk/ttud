#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000007
#define ull unsigned long long

ull x, n;

// int Pow1(int x, int n){
//     int res = 1;
//     for (int i = 0; i < n; i++)
//     {
//         res = res * x;
//     }
//     return res;
// }

// int Pow2(int x, int n){
//     if(n == 0) return 1;
//     return x * Pow2(x, n-1);
// }

ull Pow3(ull x, ull n)
{
    x = x % MOD; // Reduce x modulo MOD initially
    if (n == 1)
        return x;               // Base case: x^0 = 1
    ull half = Pow3(x, n / 2);  // Compute x^(n/2)
    half = (half * half) % MOD; // Square the result

    if (n % 2 != 0)
    {
        half = (half * x) % MOD; // If n is odd, multiply by x
    }
    return half;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> n;
    cout << Pow3(x, n) << endl;

    return 0;
}