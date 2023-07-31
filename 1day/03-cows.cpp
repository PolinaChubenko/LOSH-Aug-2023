#include <iostream>

// vector<int> coord
// k 

bool check(int x) {
    int cows_cnt = 1;
    int last_cow = coords[0];
    // for (int i = 0; i < coord.size(); ++i) {
    //     coord[i]
    // }
    for (int c : coords) {
        if (c - last_cow >= x) {
            ++cows_cnt;
            last_cow = c;
        }
    }
    return cows_cnt >= k;
}

int main () {
    int left = 0;
    int right = coord.back() - coord[0]; // coord[coord.size() - 1] = coord.back()
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (check(middle)) {
            left = middle;
        } else {
            right = middle;
        }
    }
}