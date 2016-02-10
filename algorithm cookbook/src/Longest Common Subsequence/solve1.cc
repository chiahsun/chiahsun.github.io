#include <cstdio>
#include <cstring>
#include <utility>

const int MAX_LENGTH = 100;

int A[MAX_LENGTH], B[MAX_LENGTH];
int lis[MAX_LENGTH][MAX_LENGTH];
std::pair<int, int> lis_prev[MAX_LENGTH][MAX_LENGTH];

void print_longest_common_subsequence(int i, int k) {
    if (i != 0 and k != 0) {
        const auto & pr = lis_prev[i][k];
        print_longest_common_subsequence(pr.first, pr.second);
        if (pr.first == i-1 and pr.second == k-1)
            printf("%d ", A[pr.first]);
    }
}

int main() {
    int na, nb;
    while (scanf("%d", &na) == 1) {
        for (int i = 0; i < na; ++i) scanf("%d", A+i);
        scanf("%d", &nb);
        for (int i = 0; i < nb; ++i) scanf("%d", B+i);
        memset(lis, 0, sizeof(lis));

        for (int i = 0; i < na; ++i)
            for (int k = 0; k < nb; ++k) {
                if (A[i] == B[k]) {
                    lis[i+1][k+1] = lis[i][k] + 1;
                    lis_prev[i+1][k+1] = std::make_pair(i, k);
                } else {
                    if (lis[i+1][k] >= lis[i][k+1]) {
                        lis[i+1][k+1] = lis[i+1][k];
                        lis_prev[i+1][k+1] = std::make_pair(i+1, k);
                    } else {
                        lis[i+1][k+1] = lis[i][k+1];
                        lis_prev[i+1][k+1] = std::make_pair(i, k+1);
                    }
                }
            }
        printf("lcc length : %d\n", lis[na][nb]);
        print_longest_common_subsequence(na, nb);
        printf("\n");

    }
    return 0;
}
