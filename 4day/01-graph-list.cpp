#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m; // количество ребер
    cin >> m;
    vector<pair<int, int>> graph(m); 
    // хранит ребра как пары {вершина, вершина}

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        graph[i] = {a, b};
    }

    cout << "\nYour graph is\n";
    for (int i = 0; i < m; ++i) {
        cout << graph[i].first << " " << graph[i].second << "\n";
    }

    int a, b;
    cin >> a >> b;
    --a;
    --b;
    bool edge_found = false;
    for (int i = 0; i < m; ++i) {
        pair<int, int> edge = graph[i];
        if (edge == make_pair(a, b) || 
            edge == make_pair(b, a)) {

            cout << "There is such edge\n";
            edge_found = true;
        }
    }
    if (!edge_found) {
        cout << "No such edge\n";
    }
}