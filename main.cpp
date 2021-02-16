#include <iostream>
#include <vector>

void SwapVec(std::vector<int>& a, int* b) {
    for (int i = 0; i < a.size(); ++i) {
        int c = a[i];
        a[i] = b[i];
        b[i] = c;
    }
}

int main() {
    std::vector<int> a = {1, 2, 3, 4};
    int b[] = {2, 4, 6, 8};

    SwapVec(a, b);

    for (auto i : a) {
        std::cout << i;
    }
    std::cout << std::endl;
    for (auto i : b) {
        std::cout << i;
    }
    return 0;
}
