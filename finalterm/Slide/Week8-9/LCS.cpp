#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

string s1, s2;
int F[1009][1009]; // F[i][j] la do dai day con chung dai nhat cua xau s1[1..i] va s2[1..j]

void dp()
{
    int n = s1.size();
    int m = s2.size();

    for (int i = 0; i <= n; i++)
        F[i][0] = 0;
    for (int j = 0; j <= m; j++)
        F[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                F[i][j] = F[i - 1][j - 1] + 1;
            else
                F[i][j] = max(F[i - 1][j], F[i][j - 1]);
        }
    }
    cout << F[n][m]<<endl;
}

void Trace(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (s1[i - 1] == s2[j - 1] && F[i][j] == F[i - 1][j - 1] + 1)
    {
        Trace(i - 1, j - 1);
        cout << s1[i - 1];
        return;
    }
    if (F[i][j] == F[i][j - 1])
    {
        Trace(i, j - 1);
        return;
    }
    if (F[i][j] == F[i - 1][j])
    {
        Trace(i - 1, j);
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s1 >> s2;
    dp();
    Trace(s1.size(), s2.size());

    return 0;
}