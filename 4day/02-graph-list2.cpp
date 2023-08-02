#include <iostream>
#include <vector>

using namespace std;

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

    cout << "\nYour graph is\n";
    for (int i = 0; i < n; ++i) {
        cout << "vertex" << i << " neighbours: ";
        for (int j = 0; j < graph[i].size(); ++j) {
            cout << graph[i][j] << ", ";
        }
        cout << "\n";
    }

    int a, b;
    cin >> a >> b;
    --a;
    --b;
    bool edge_found = false;
    for (int i = 0; i < graph[a].size(); ++i) {
        if (graph[a][i] == b) {
            cout << "There is such edge\n";
            edge_found = true;
        }
    }
    if (!edge_found) {
        cout << "No such edge\n";
    }
}