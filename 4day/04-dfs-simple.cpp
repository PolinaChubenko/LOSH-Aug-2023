#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<vector<int>> &graph,
        vector<bool> &visited) {
    //помечаем вершинку посещенной
    visited[v] = true;
    // запускаем dfs от соседей вершины v
    for(int i = 0; i < graph[v].size(); ++i) {
        int u = graph[v][i];
        if (!visited[u]) {
            dfs(u, graph, visited);
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

    // посещена ли вершина
    vector<bool> visited(n, false);
    // запустим обход графа
    dfs(0, graph, visited);

    // А что если граф несвязный?
    // Тогда используем код ниже :)

    // for (int v = 0; v < n; ++v) {
    //     if (!visited[v]) {
    //         dfs(v, graph, visited);
    //     }
    // }
}



// 7 7
// 1 2
// 1 3
// 1 4
// 2 4
// 2 6
// 3 7
// 5 6