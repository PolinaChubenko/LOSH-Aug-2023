#include <iostream>
#include <string>

struct Node {
    int value = 0;
    Node* prev = nullptr;
    Node(int v, Node* p) : value(v), prev(p) {}
};

struct Stack {
    Node* top = nullptr;
    int size = 0;

    Stack() = default;
    ~Stack() {
        Clear();
    }
    int Top() {
        if (!Empty()) {
            return top->value;
        }
        return -1;
    }
    void Push(int n) {
        top = new Node(n, top);
        ++size;
    }
    void Pop() {
        Node* temp = top;
        top = top->prev;
        delete temp;
        --size;
    }

    void Clear() {
        while(top != nullptr) {
            Pop();
        }
    }

    bool Empty() {
        return top == nullptr;
    }

    int Size() {
        return size;
    }

};


int main() {
    std::string command;
    Stack st;

    while (std::cin >> command) {
        if (command == "top") {
            std::cout << st.Top() << "\n";
        } else if (command == "push") {
            int n;
            std::cin >> n;
            st.Push(n);
        } if (command == "exit") {
            break;
        } if (command == "pop") {
            st.Pop();
        } if (command == "clear") {
            st.Clear();
        } if (command == "Size") {
            std::cout << st.Size() << "\n";
        }
    }

    return 0;
}
