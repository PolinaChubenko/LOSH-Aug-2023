#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; // количество вершин
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    // матрица смежности

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    cout << "\nYour graph is\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    int i, j;
    cin >> i >> j;
    --i;
    --j;
    if (graph[i][j]) {
        cout << "There is such edge\n";
    } else {
        cout << "No such edge\n";
    }
}