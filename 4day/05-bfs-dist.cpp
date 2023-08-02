#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int s, vector<vector<int>> &graph,
        vector<int> &dist, vector<int> &parent) {
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : graph[v]) {
            if (dist[u] == -1) {
                q.push(u);
                dist[u] = dist[v] + 1;
                parent[u] = v;
            }
        }
    }
} 

int main() {
    int n; // количество вершин
    cin >> n;
    vector<std::vector<int>> graph(n); 
    // graph[i] = массив соседей i-ой вершины

    int m; // количество ребер
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int start, end;
    std::cin >> start >> end;
    --start;
    --end;

    vector<int> dist(n, -1), parent(n);
    bfs(start, graph, dist, parent);
    
    std::cout << dist[end] << "\n";

    // восстановим маршрут
    while (end != start) {
        cout << end << endl;
        end = parent[end];
    }
}
