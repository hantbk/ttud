#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, k;

string find_kth_char(int n, int k)
{
    if (n == 0)
        return "a";
    if (n == 1)
        return "b";

    string Fn_minus_1 = "b";
    string Fn_minus_2 = "a";
    string Fn;

    for (int i = 2; i <= n; i++)
    {
        Fn = Fn_minus_2 + Fn_minus_1;
        Fn_minus_2 = Fn_minus_1;
        Fn_minus_1 = Fn;
    }
    return Fn.substr(k - 1, 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    string result = find_kth_char(n, k);
    cout << result << endl;

    return 0;
}