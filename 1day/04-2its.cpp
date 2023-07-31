#include <iostream>
#include <vector>

int main () {
    std::vector<int> v; 
    int k;
    std::cin >> k;
    int i = 0;
    int j = v.size() - 1;
    while (i < j) {
        if (v[i] + v[j] == k) {
            std::cout << "YYUUHU\n;";
            return 0;
        }
        if (v[i] + v[j] > k) {
            --j; // j -= 1
        }
        if (v[i] + v[j] < k) {
            ++i; // i += 1
        }
    }
    std::cout << i << j;
}