#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int c[1009][1009];
bool visited[1009];
int x[1009];
int f = 0;
int f_best = INF;
int cmin = INF;

void updateBest()
{
    if (f + c[x[n]][1] < f_best)
        f_best = f + c[x[n]][1];
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (!visited[v])
        {
            x[k] = v;
            visited[v] = true;
            f = f + c[x[k - 1]][x[k]];
            if (k == n)
                updateBest();
            else if (f + cmin * (n - k + 1) < f_best)
                Try(k + 1);
            visited[v] = false;
            f = f - c[x[k - 1]][x[k]];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (j != i && c[i][j] < cmin)
                cmin = c[i][j];
        }
    }
    memset(visited, false, sizeof(visited));

    x[1] = 1;
    visited[1] = true;
    Try(2);
    cout << f_best << endl;

    return 0;
}