#include <iostream>
#include <stack>

int main() {
    std::stack<std::pair<int, int>> st;
    char ch;
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        std::cin >> ch;
        if (ch == '+') {
            int a;
            std::cin >> a;
            int mini;
            if (st.empty()) {
                mini = a;
            } else {
                mini = std::min(a, st.top().second);
            }
            st.push({a, mini});
        }
        if (ch == '?') {
            std::cout << st.top().second << "\n";
        }
    }
    return 0;
}