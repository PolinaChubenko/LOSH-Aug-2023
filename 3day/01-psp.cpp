#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string s;
    std::cin >> s;
    std::stack<char> st;
    bool flag = false;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else {
            if (st.empty()) {
               std::cout << "no\n";
               flag = true;
               break; 
            }
            if (s[i] == ')' && st.top() != '(') {
                std::cout << "no\n";
                flag = true;
                break;
            }
            if (s[i] == ']' && st.top() != '[') {
                std::cout << "no\n";
                flag = true;
                break;
            }
            if (s[i] == '}' && st.top() != '{') {
                std::cout << "no\n";
                flag = true;
                break;
            }
            st.pop();
        }
    }
    if (!flag) {
        if (!st.empty()) {
            std::cout << "no\n";
        } else {
            std::cout << "yes\n";
        }
    }
    return 0;
}