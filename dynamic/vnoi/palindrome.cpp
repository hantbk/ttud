/*
Cho 1 xâu S. Hãy tìm số kí tự ít nhất cần thêm vào xâu S để xâu S trở thành xâu Palindrome.
*/
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

string s;
int n;
int F[MAX][MAX]; // F[i][j] là số kí tự ít nhất cần thêm vào xâu S[i..j] để xâu S[i..j] trở thành xâu Palindrome

void dp()
{
    for (int i = 0; i < n; i++)
        F[i][i] = 0;

    // for (int len = 2; len <= n; len++)
    // {
    //     for (int i = 0; i <= n - len + 1; i++)
    //     {
    //         int j = i + len - 1;
    //         if (s[i] == s[j])
    //             F[i][j] = F[i + 1][j - 1];
    //         else
    //             F[i][j] = min(F[i + 1][j], F[i][j - 1]) + 1;
    //     }
    // }

    // cout << F[0][n - 1];

    for(int j = 1; j < n; j++)
    {
        for(int i = j - 1; i >= 0; i--)
        {
            if(s[i] == s[j])
                F[i][j] = F[i + 1][j - 1];
            else
                F[i][j] = min(F[i + 1][j], F[i][j - 1]) + 1;
        }
    }

    cout << F[0][n - 1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.size();
    dp();

    return 0;
}