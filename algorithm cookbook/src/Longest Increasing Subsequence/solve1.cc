#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> A, lis, lis_pos, pos_prev;
int last_pos;
void print_prev(int pos) {
    if (pos != pos_prev[pos])
        print_prev(pos_prev[pos]);
    printf("%d ", A[pos]);
}

int main() {
    int x;
    for (int pos = 0; scanf("%d", &x) == 1; ++pos) {
        A.push_back(x);
        pos_prev.push_back(pos);
        if (lis.size() == 0 or lis.back() < x) {
            lis.push_back(x);
            lis_pos.push_back(pos);
            if (lis.size() > 1)
                pos_prev[pos] = lis_pos[lis.size()-2];
            last_pos = pos;
        } else {
            auto it = std::lower_bound(lis.begin(), lis.end(), x);
            size_t pos_replace = it - lis.begin();
            lis[pos_replace] = x;
            lis_pos[pos_replace] = pos;
            if (pos_replace > 0)
                pos_prev[pos] = lis_pos[pos_replace-1];
            if (pos_replace == lis.size()-1)
                last_pos = pos;
        }
    }

    print_prev(last_pos);
    printf("\n");

    return 0;
}
