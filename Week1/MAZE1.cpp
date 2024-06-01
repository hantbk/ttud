#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, m, r, c;
int A[1001][1001];
bool visited[1001][1001];
queue<tuple<int, int, int>> q; // {step, x, y}
int cot[4] = {0, 0, 1, -1};
int hang[4] = {-1, 1, 0, 0};
int minstep = INF; 

void input() {
    cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }
}

void solution() {
    memset(visited, false, sizeof(visited));
    minstep = INF;

    q.push({0, r, c});
    visited[r][c] = true;

    while (!q.empty()) {
        auto [step, x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x_1 = x + hang[i];
            int y_1 = y + cot[i];
            int new_step = step + 1;

            if (x_1 <= 0 || x_1 > n || y_1 <= 0 || y_1 > m) {
                minstep = min(minstep, new_step);
                continue;
            }

            if (A[x_1][y_1] == 0 && !visited[x_1][y_1]) {
                visited[x_1][y_1] = true;
                q.push({new_step, x_1, y_1});
            }
        }
    }

    if (minstep == INF) {
        minstep = -1;
    }
    cout << minstep << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();

    return 0;
}
