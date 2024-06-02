#include <bits/stdc++.h>
using namespace std;

int cur_num = 1;
int res = 0;
stack<int> S;
vector<int> adj[100005];
int Num[100005], Low[100005];
bool Articulation[100005]; // To store articulation points
vector<pair<int, int>> Bridges; // To store bridges
int N, M;
int numArticulation = 0;
int numBridges = 0;

void SCC(int u, int pv) {
    Low[u] = Num[u] = cur_num++;
    S.push(u);
    int children = 0; // Count of children in DFS tree

    for (int v : adj[u]) {
        if (Num[v] == -1) {
            children++;
            SCC(v, u);
            Low[u] = min(Low[u], Low[v]);

            // (u, v) is a bridge if Low[v] > Num[u]
            if (Low[v] > Num[u]) {
                Bridges.push_back({u, v});
            }

            // u is an articulation point if u is root of DFS tree and has two or more children
            // or if u is not root and Low[v] >= Num[u]
            if (pv == u && children > 1) {
                Articulation[u] = true;
            }
            if (pv != u && Low[v] >= Num[u]) {
                Articulation[u] = true;
            }

        } else if (v != pv) {
            Low[u] = min(Low[u], Num[v]);
        }
    }

    if (Num[u] == Low[u]) {
        res++;
        while (true) {
            int v = S.top();
            S.pop();
            Low[v] = Num[v] = 1e9;
            if (v == u) {
                break;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Note: For undirected graph, add edge in both directions
    }
    for (int i = 1; i <= N; i++) {
        Num[i] = -1;
        Articulation[i] = false;
    }
    for (int i = 1; i <= N; i++) {
        if (Num[i] == -1) {
            SCC(i, i);
        }
    }

    // cout << "Number of Strongly Connected Components: " << res << endl;
    // cout << "Articulation Points: ";
    for (int i = 1; i <= N; i++) {
        if (Articulation[i]) {
            numArticulation++;
            // cout << i << " ";
        }
    }
    cout<<numArticulation<<" ";
    numBridges = Bridges.size();
    cout<<numBridges<<endl;
    // cout << endl;
    // cout << "Bridges: ";
    // for (auto bridge : Bridges) {
    //     cout << "(" << bridge.first << ", " << bridge.second << ") ";
    // }
    // cout << endl;

    return 0;
}
