#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int fibonacci_string_length(int n)
{
    if (n == 0)
        return 1; // F[0] = "a" có độ dài 1
    if (n == 1)
        return 1; // F[1] = "b" có độ dài 1

    int Fn_minus_1_length = 1;
    int Fn_minus_2_length = 1;
    int Fn_length;

    for (int i = 2; i <= n; i++)
    {
        Fn_length = Fn_minus_1_length + Fn_minus_2_length;
        Fn_minus_2_length = Fn_minus_1_length;
        Fn_minus_1_length = Fn_length;
    }

    return Fn_length;
}

char find_kth_char(int n, int k)
{
    if (n == 0)
        return 'a';
    if (n == 1)
        return 'b';

    int Fn_length = fibonacci_string_length(n);

    if (k > Fn_length)
    {
        return ' ';
    }

    if (n == 2)
    {
        if (k == 1)
            return 'a';
        if (k == 2)
            return 'b';
    }

    int Fn_minus_1_length = fibonacci_string_length(n - 1);
    int Fn_minus_2_length = fibonacci_string_length(n - 2);

    if (k <= Fn_minus_1_length)
    {
        return find_kth_char(n - 2, k);
    }
    else
    {
        return find_kth_char(n - 1, k - Fn_minus_1_length);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    char result = find_kth_char(n, k);
    cout << result << endl;

    return 0;
}