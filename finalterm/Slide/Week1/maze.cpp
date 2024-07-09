#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, m, r, c;
int A[1009][1009];
bool visited[1009][1009];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int minStep = INF;
queue<pair<int, pair<int, int>>> q; // {step, {x, y}}

void input(){
    cin >> n >> m >> r >> c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> A[i][j];
        }
    }
}

void findPath(){
    q.push({0, {r, c}});
    visited[r][c] = true;

    while(!q.empty()){
        int step = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int x_new = x + dx[i];
            int y_new = y + dy[i];

            if(x_new == 0 || x_new == n + 1 || y_new == 0 || y_new == m + 1) {
                minStep = min(minStep, step + 1);
                continue;
            }

            if(A[x_new][y_new] == 0 && !visited[x_new][y_new]){
                visited[x_new][y_new] = true;
                q.push({step + 1, {x_new, y_new}});
            }
        }
    }

    if(minStep == INF) cout << -1;
    else cout << minStep;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    findPath();

    return 0;
}