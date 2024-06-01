#include <bits/stdc++.h>
using namespace std;

int n, K;
int c[23][23];
int x[23];
bool visited[23];
int load = 0;
int best = 10000000;
int cmin = 1000000;
int f;

// Kiem tra xem có thể dùng đỉnh v cho chặng thứ k hay không
bool check(int v, int k)
{
    if (visited[v])
        return false;
    if (v > n)
    {
        if (!visited[v - n])
            return false;
    }
    else
    {
        if (load + 1 > K)
            return false;
    }
    return true;
}

void updateBest()
{
    if ((f + c[x[2 * n]][0]) < best)
        best = f + c[x[2 * n]][0];
}

void Try(int k)
{
    for (int v = 1; v <= 2 * n; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            f = f + c[x[k - 1]][x[k]];
            visited[v] = true;

            if (v <= n)
                load++;
            else
                load--;

            if (k == 2 * n)
                updateBest();
            else
            {
                if (f + cmin * (2 * n + 1 - k) < best)
                    Try(k + 1);
            }

            if (v <= n)
                load--;
            else
                load++;

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

    cin >> n >> K;
    for (int i = 0; i < 2 * n + 1; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {
            cin >> c[i][j];
            if (c[i][j] > 0)
                cmin = min(cmin, c[i][j]);
        }
    }
    Try(1);
    cout << best;

    return 0;
}