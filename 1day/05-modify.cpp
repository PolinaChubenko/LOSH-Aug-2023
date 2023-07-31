#include <iostream>

int main () {
    // v, k
    int cnt;
    int j = 1;
    for (int i = 0; i < n; ++i) {
        while (j != n - 1 && v[j] - v[i] <= k) {
            ++j;
        }
        cnt += n - j;
    }
    std::cout << cnt;
}