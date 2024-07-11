#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> graph;
int n, k;

int backtrack(int node, int depth, unordered_set<int>& visited) {
    if (depth == k) {
        return 1;
    }
    int count = 0;
    for (int neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            visited.insert(neighbor);
            count += backtrack(neighbor, depth + 1, visited);
            visited.erase(neighbor);
        }
    }
    return count;
}

int count_k_paths() {
    int total_paths = 0;
    for (int start_node = 1; start_node <= n; ++start_node) {
        unordered_set<int> visited;
        visited.insert(start_node);
        total_paths += backtrack(start_node, 0, visited);
    }
    return total_paths / 2; // Divide by 2 to account for double counting in undirected graph
}

int main() {
    int m;
    cin >> n >> k;
    cin >> m;
    
    graph.resize(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    cout << count_k_paths() << endl;
    return 0;
}