#include <cstdio>
#include <vector>
#include <algorithm>

void print_vec(const char * msg = 0, const std::vector<int> & v = std::vector<int>()) {
    printf("%s", msg ? msg : "");
    for (auto x : v)
        printf(" %d", x);
    printf("\n");
}

template <class _Container, class _Predicate>
void remove_if_and_resize(_Container & c, _Predicate p) {
    auto new_end = std::remove_if(c.begin(), c.end(), p);
    c.erase(new_end, c.end());    
}

int main() {
    {
    int value = 3;
    std::vector<int> v = {1, 2, 3, 4, 5};
    print_vec("Before :", v);
    auto new_end = std::remove_if(v.begin(), v.end(), [value] (int x) { return x < value; });
    print_vec("After remove_if :", v);
    v.erase(new_end, v.end());
    print_vec("After erase:", v);
    }

    {
    int value = 2;
    std::vector<int> v = {1, 2, 3, 4, 5};
    print_vec("Before :", v);
    remove_if_and_resize(v, [value] (int x) { return x > value; });
    print_vec("After remove_if_and_resize :", v);
    }
    return 0;
}
