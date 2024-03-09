#include <bits/stdc++.h>

using namespace std;

int m, n, r, c;
queue<pair<int, pair<int, int>>> q;
int step = 0;
int hang[4] = {-1, 1, 0, 0};
int cot[4] = {0, 0, 1, -1};
int stepMin = 100000;
int visited[1001][1001];
int a[1001][1001];

int main()
{

    memset(visited, -1, sizeof(visited));

    cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    q.push({0, {r, c}});
    visited[r][c] = 0;
    while (!q.empty())
    {
        pair<int, pair<int, int>> p1 = q.front();
        q.pop();
        for (int i = 0; i <= 3; i++)
        {
            int x_new = p1.second.first + hang[i];
            int y_new = p1.second.second + cot[i];

            if (x_new == 0 || x_new == n + 1 || y_new == 0 || y_new == m + 1)
            {
                stepMin = min(stepMin, p1.first + 1);
                continue;
            }

            if (a[x_new][y_new] == 0)
            {
                if (visited[x_new][y_new] > visited[p1.second.first][p1.second.second] + 1 || visited[x_new][y_new] == -1)
                {
                    visited[x_new][y_new] = p1.first + 1;
                    q.push({p1.first + 1, {x_new, y_new}});
                }
            }
        }
    }
    if (stepMin == 100000)
    {
        stepMin = -1;
    }
    cout << stepMin << "\n";
    return 0;
}