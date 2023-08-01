#include <iostream>
#include <vector>
 
int main() {
    int x;
    std::vector<int> a;
    while (std::cin >> x) {  // читаем числа, пока не закончится ввод
        a.push_back(x);  // добавляем очередное число в вектор
    }
 
    while (!a.empty() && a.back() == 0) {
        // Пока вектор не пуст и последний элемент равен нулю
        a.pop_back();  // удаляем этот нулевой элемент
    }
    
    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << " ";
    }

}