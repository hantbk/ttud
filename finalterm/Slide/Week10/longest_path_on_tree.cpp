#include <bits/stdc++.h>

using namespace std;

const int maxN = 100010;
const int maxW = 110;

int N;
vector<int> a[maxN];
vector<int> c[maxN];
int d[maxN], p[maxN];

void BFS(int u){
    queue<int> Q;
    d[u] = 0;
    Q.push(u);
    while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        int a_leng = a[v].size();
        for (int i = 0; i < a_leng; i++){
            int x = a[v][i];
            if (p[x] > -1) continue;
            Q.push(x);
            int w = c[v][i];
            d[x] = d[v] + w;
            p[x] = v;
        }
    }
}

int find_max(){
    int max_d = -1;
    int u = -1;
    for (int v = 1; v <= N; v++){
        if (max_d < d[v]){
            max_d = d[v];
            u = v;
        }
    }
    return u;
}

void init(){
    for (int i = 1; i <= N; i++){
        d[i] = -1;
        p[i] = -1;
    }
}

void solve(){
    cin >> N;
    for (int i = 1; i <= N-1; i++){
        int x, y, w;
        cin >> x >> y >> w;
        a[x].push_back(y);
        c[x].push_back(w);
        a[y].push_back(x);
        c[y].push_back(w);
    }
    init();
    BFS(1);
    int u = find_max();
    init();
    BFS(u);
    cout << d[find_max()];
}

int main(){
    solve();
    return 0;
}
