/*
Cho 2 xâu X, Y. Hãy tìm xâu con chung dài nhất của X và Y.
Biết xâu con của 1 xâu thu được bằng cách xóa đi một số kí tự của xâu đó.
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

string X, Y;
int n, m;
int L[MAX][MAX]; // L[i][j] la do dai xau con chung dai nhat cua X[1..i] va Y[1..j]
int L1[MAX];     // L1[j] la do dai xau con chung dai nhat cua X[1..i] va Y[1..j] ket thuc tai X[i]
int P1[MAX];     // P1[j] la do dai xau con chung dai nhat cua X[1..i] va Y[1..j] ket thuc tai Y[j]

// O(n*m)
void dp1()
{
    for (int i = 0; i <= n; i++)
        L[i][0] = 0;
    for (int j = 0; j <= m; j++)
        L[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    cout << L[n][m];
}

void dp2()
{
    for (int j = 0; j <= n; j++)
        P1[j] = 0;

    for (int i = 1; i <= m; i++)
    {
        L1[0] = 0;
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
                L1[j] = P1[j - 1] + 1;
            else
                L1[j] = max(L1[j - 1], P1[j]);
        }
        for (int j = 1; j <= n; j++)
            P1[j] = L1[j];
    }
    cout << P1[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> X >> Y;
    n = X.size();
    m = Y.size();
    dp1();

    return 0;
}