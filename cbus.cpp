#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define INF 1000000009
#define endl "\n"

int n, K, D;
int load = 0;
int d[100][100];
int x[100];
int cmin = INF;
bool visited[100];
int f[50]; // f[v] là các chi phí để đi từ 0 đến v
int best = INF;

bool check(int k, int v)
{
    if (visited[v])
        return false;

    if (v > n)
    {
        if (!visited[v - n])
            return false;
    }
    else if (load + 1 > K)
    {
        return false;
    }

    if (v > n && f[x[k - 1]] - f[v - n] + d[x[k - 1]][v] > D)
    {
        return false;
    }

    return true;
}

void updateBest(int v)
{
    if (f[v] + d[x[2 * n]][0] < best)
    {
        best = f[v] + d[x[2 * n]][0];
    }
}

void Try(int k)
{
    for (int v = 1; v <= 2 * n; v++)
    {
        if (check(k, v))
        {
            x[k] = v;
            f[v] = f[x[k - 1]] + d[x[k - 1]][x[k]];
            visited[v] = true;

            if (v <= n)
            {
                load++;
            }
            else
            {
                load--;
            }

            if (k == 2 * n)
                updateBest(v);
            else
            {
                if (f[v] + cmin * (2 * n + 1 - k) < best)
                    Try(k + 1);
            }

            if (v <= n)
            {
                load--;
            }
            else
            {
                load++;
            }

            visited[v] = false;
            f[v] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> K >> D;

    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> d[i][j];
            if (i != j && d[i][j] > 0)
            {
                cmin = min(cmin, d[i][j]);
            }
        }
    }

    x[0] = 0;
    f[0] = 0;
    visited[0] = true;

    Try(1);
    if (best == INF)
        cout << -1;
    else
        cout << best;

    return 0;
}
