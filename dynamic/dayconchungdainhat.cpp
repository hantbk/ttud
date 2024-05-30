#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

string a, b;
int F[1001][1001]; // F[i][j] là độ dài dãy con chung dài nhất của 2 xâu X[1..i] và Y[1..j

void dp()
{
    for (int i = 0; i <= a.size(); i++)
        F[i][0] = 0;
    for (int j = 0; j <= b.size(); j++)
        F[0][j] = 0;

    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                F[i][j] = 1 + F[i - 1][j - 1];
            }
            else
            {
                F[i][j] = max(F[i - 1][j], F[i][j - 1]);
            }
        }
    }
    cout << F[a.size()][b.size()] << endl;
}

void Trace(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (a[i - 1] == b[j - 1] && F[i][j] == 1 + F[i - 1][j - 1])
    {
        Trace(i - 1, j - 1);
        cout << a[i - 1];
        return;
    }
    if (F[i][j] == F[i - 1][j])
    {
        Trace(i - 1, j);
        return;
    }
    if (F[i][j] == F[i][j - 1])
    {
        Trace(i, j - 1);
        return;
    }
}

void IterTrace()
{
    int i = a.size(), j = b.size();
    stack<char> stk;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1] && F[i][j] == 1 + F[i - 1][j - 1])
        {
            stk.push(a[i - 1]);
            i--;
            j--;
        }
        if (F[i][j] == F[i - 1][j])
        {
            i--;
        }
        if (F[i][j] == F[i][j - 1])
        {
            j--;
        }
    }

    while (!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    dp();
    // Trace(a.size(), b.size());
    IterTrace();

    return 0;
}
