#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int c[105][105];
int x[100];
bool visited[105];
int f;
int f_best = INF;
int cmin = INF;

void inp()
{
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
}

bool check(int v, int k)
{
    if (visited[v])
        return false;
    return true;
}

void updateBest()
{
    if (f + c[x[n]][1] < f_best)
        f_best = f + c[x[n]][1];
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            visited[v] = true;
            f += c[x[k - 1]][x[k]];
            if (k == n)
                updateBest();
            else{ if(f + cmin*(n + 1 - k) < f_best)

                Try(k + 1);
            }
            visited[v] = false;
            f -= c[x[k - 1]][x[k]];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    inp();
    x[1] = 1;
    visited[1] = true;
    Try(2);
    cout << f_best << endl;

    return 0;
}