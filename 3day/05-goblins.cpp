#include <iostream>
#include <deque>

int main()
{
    int n;
    std::cin >> n;
    std::deque<int> deq_1, deq_2;

    for (int i = 0; i < n; ++i)
    {
        char ch;
        std::cin >> ch;
        if (ch == '+')
        {
            int goblin;
            std::cin >> goblin;
            deq_2.push_back(goblin);
        }
        else if (ch == '*')
        {
            int goblin;
            std::cin >> goblin;
            deq_2.push_front(goblin);
        }
        else if (ch == '-') {
            std::cout << deq_1.front() << std::endl;
            deq_1.pop_front();
        }
        if (deq_2.size() > deq_1.size()) {
            int goblin = deq_2.front();
            deq_2.pop_front();
            deq_1.push_back(goblin);
        }
    }
    return 0;
}