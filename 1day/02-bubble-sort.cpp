#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::milliseconds milliseconds;



/* ---------------------------------------------------- */

void bubbleSort(std::vector<int> &a) {
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a.size() - 1; ++j) {
            if (a[j] > a[j + 1])
                std::swap(a[j], a[j + 1]);
        }
    }
}

/* ---------------------------------------------------- */





/* ---------------------------------------------------- */

void betterBubbleSort(std::vector<int> &a) {
    for (size_t i = 0; i < a.size() - 1; ++i) {
        for (size_t j = 0; j < a.size() - i - 1; ++j) {
            if (a[j] > a[j + 1])
                std::swap(a[j], a[j + 1]);
        }
    }
}

/* ---------------------------------------------------- */




int main() {
    int n = 50000;
    std::vector<int> a(n);
    for (size_t i = 0; i < n; ++i) {
        a[i] = rand() % 999983 + 1;
    }

    Clock::time_point t0 = Clock::now();

    bubbleSort(a);

    Clock::time_point t1 = Clock::now();

    milliseconds ms = std::chrono::duration_cast<milliseconds>(t1 - t0);
    std::cout <<  "Bubble sort of " << n << " elements: " << ms.count() << "ms\n";
}

/*
1000: 16ms
2000: 93ms
4000: 222ms
10000: 902ms
20000: 3625ms
50000: 24294ms
*/
