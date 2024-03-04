#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void dfsRecursive(const vector<vector<int>>& graph, int v, vector<bool>& visited) {
    cout << v << " ";
    visited[v] = true;

    for (int w : graph[v]) {
        if (!visited[w]) {
            dfsRecursive(graph, w, visited);
        }
    }
}

void dfs(const vector<vector<int>>& graph, int start, vector<bool>& visited) {
    dfsRecursive(graph, start, visited);
}

void bfs(const vector<vector<int>>& graph, int start, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    for (int caseNum = 1; caseNum <= t; ++caseNum) {
        int n;
        cin >> n;

        vector<vector<int>> graph(n + 1);

        for (int i = 1; i <= n; ++i) {
            int v, m;
            cin >> v >> m;
            graph[v].resize(m);
            for (int j = 0; j < m; ++j) {
                cin >> graph[v][j];
            }
        }

        cout << "graph " << caseNum << endl;
        int v, method;
        while (true) {
            cin >> v >> method;
            if (v == 0 && method == 0) break;

            vector<bool> visited(n + 1, false);

            if (method == 0) {
                dfs(graph, v, visited);
            }
            else {
                bfs(graph, v, visited);
            }
            cout << endl;
        }
    }
    return 0;
}
