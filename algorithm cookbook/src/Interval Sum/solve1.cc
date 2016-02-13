#include <cstdio>
const int SIZE = 100;
int A[SIZE];
int prefix_sum[SIZE];

int main() {
    int N;
    scanf("%d", &N);
    prefix_sum[0] = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d", A+i);
        prefix_sum[i+1] = prefix_sum[i] + A[i];
    }

    int begin, end;
    while (scanf("%d%d", &begin, &end) == 2) {
        for (int i = begin; i < end; ++i)
            printf("%d ", A[i]);
        printf("-> sum = %d\n", prefix_sum[end]-prefix_sum[begin]);
    }

    return 0;
}
