#include <iostream>
#include <vector>

bool check(int x, int k, std::vector<int> &coords) {
    int cows_cnt = 1;
    int last_cow = coords[0];
    for (int c : coords) {
        if (c - last_cow >= x) {
            ++cows_cnt;
            last_cow = c;
        }
    }
    return cows_cnt >= k;
}

int main () {
    int n;
    std::cin >> n;
    std::vector<int> coords(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> coords[i];
    }
    int k;
    std::cin >> k;

    int left = 0;
    int right = coords.back() - coords[0] + 1; // coord[coord.size() - 1] = coord.back()
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (check(middle, k, coords)) {
            left = middle;
        } else {
            right = middle;
        }
    }
}