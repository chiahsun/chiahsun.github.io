#include <cstdio>
#include <vector>
#include <algorithm>

void print_vector(const char* msg, const std::vector<int> & v) {
    printf("%s :", msg);
    for (auto x : v)
        printf(" %d", x);
    printf("\n");
}

int main() {
    int x;
    std::vector<int> v;
    while (scanf("%d", &x) == 1) v.push_back(x);

    print_vector("Before unique", v);

    // unique
    std::sort(v.begin(), v.end());
    auto it = std::unique(v.begin(), v.end());
    v.resize(it-v.begin());

    print_vector("After unique", v);

    return 0;
}
