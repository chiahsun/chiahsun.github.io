#include <cstdio>

void print_bit_repr(int x) {
    for (int i = 1<<8; i > 0; i>>=1)
        printf("%c", (x & i) ? '1' : '0');
    printf("\n");
}

void set(int & x, int pos) { x |= (1 << pos); }
void unset(int & x, int pos) { x &= ~(1 << pos); }
bool is_set(int & x, int pos) { return x & (1 << pos); }

void unset_lowest_bit(int & x) { x &= (x-1); }

int main() {
    int a = 0;

    set(a, 1); print_bit_repr(a); 
    set(a, 2); print_bit_repr(a);
    for (int i = 0; i < 8; ++i)
        printf("%d is set : %s\n", i, is_set(a, i) ? "YES" : "NO");
    unset(a, 1); print_bit_repr(a); 
    unset(a, 2); print_bit_repr(a);
    
    set(a, 3); print_bit_repr(a); 
    set(a, 5); print_bit_repr(a);
    unset_lowest_bit(a); print_bit_repr(a); 
    unset_lowest_bit(a); print_bit_repr(a); 

    return 0;
}
