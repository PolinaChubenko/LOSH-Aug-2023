#include <iostream>
#include <vector>

int main() {
    std::vector<int> a = {1, 3, 5, 6, 9, 15};
    int x = 3;
    int left = 0;
    int right = a.size() - 1;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (a[middle] <= x) {
            left = middle;
        } else {
            right = middle;
        }
    }

    if (a[left] == x || a[right] == x) {
        std::cout << "success\n";
    } else {
        std::cout << ":(\n";
    }
}