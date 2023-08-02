#include <iostream>
#include <vector>
#include <string>

using namespace std;

// время входа и выхода из вершины
vector<int> in, out;
int timer = 0;
// будем красить вершины по мере их посещения в 3 цвета
vector<string> color;
vector<int> parent;

void dfs(int v, int p, vector<vector<int>> &graph) {
    in[v] = timer++;
    parent[v] = p;
    color[v] = "gray";
    std::cout << v + 1 << " ";
    // запускаем dfs от соседей вершины v
    for(int i = 0; i < graph[v].size(); ++i) {
        int u = graph[v][i];
        if (color[u] != "white") {
            continue;
        }
        dfs(u, v, graph);
    }
    out[v] = timer++;
    color[v] = "black";
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
    }

    in.resize(n), out.resize(n);
    parent.resize(n);
    color.resize(n, "white");
    // запустим обход графа
    dfs(0, -1, graph);

    std::cout << "\n" << "in: ";
    for(int i = 0; i < n; ++i) {
        std::cout << in[i] << " ";
    }
    std::cout << "\n" << "out: ";
    for(int i = 0; i < n; ++i) {
        std::cout << out[i] << " ";
    }
    std::cout << "\n";
}