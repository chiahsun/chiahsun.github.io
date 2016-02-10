#include <cstdio>

bool is_prime(int x) {
    if (x < 4) return (x == 2 or x == 3);
    if (x % 2 == 0 or x % 3 == 0) return false;

    for (int i = 5; i * i <= x; i += 6)
        if ((x % i == 0) or (x % (i+2) == 0))
            return false;
    return true;
}

int main() {
    int bound;
    while (scanf("%d", &bound) == 1) {
        printf("Primes less than %d :", bound);
        for (int i = 0; i < bound; ++i)
            if (is_prime(i))
                printf(" %d", i);
        printf("\n");
    }
    return 0;
}
