---
layout: page 
title: Lanaguage cookbook
text: Quick reference for implementations in different programming languages
---

## Remove If

[ideone](https://ideone.com/dHjA38)

~~~cpp
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

~~~

Output

~~~
Before : 1 2 3 4 5
After remove_if : 3 4 5 4 5
After erase: 3 4 5
Before : 1 2 3 4 5
After remove_if_and_resize : 1 2
~~~

#### Reference

* [std remove if @ stackoverflow](http://stackoverflow.com/questions/4478636/stdremove-if-lambda-not-removing-anything-from-the-collection)

* [lambda function @ cppreference](http://en.cppreference.com/w/cpp/language/lambda)


## Bit Manipulation

[ideone](http://ideone.com/YP7rSS)

~~~ cpp
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

~~~

Output

~~~
000000010
000000110
0 is set : NO
1 is set : YES
2 is set : YES
3 is set : NO
4 is set : NO
5 is set : NO
6 is set : NO
7 is set : NO
000000100
000000000
000001000
000101000
000100000
000000000
~~~

Reference

* [Bitwise operator](http://www.cprogramming.com/tutorial/bitwise_operators.html)

* [Bit manipulation @ stackovrflow](http://stackoverflow.com/questions/3920307/how-can-i-remove-a-flag-in-c)


## Unique 

[ideone](https://ideone.com/tKZ3Eg)

~~~ cpp
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
~~~

[ideone](https://ideone.com/1YSeHv)

~~~ python
line = input();
ints = list(map(int, line.split()));

def print_list(msg, ll):
    print(msg, end='', sep='');
    for x in ints:
        print(' ', x, end='', sep='');
    print();

print_list('Before unique :', ints);

# unique
ints = list(set(ints));

print_list('After unique :', ints);
~~~


Input

~~~
4 2 1 3 1 2 4 5
~~~

Output

~~~
Before unique : 4 2 1 3 1 2 4 5
After unique : 1 2 3 4 5
~~~

#### Reference

* [Get unique values @ stackoverflow](http://stackoverflow.com/questions/12897374/get-unique-values-from-a-list-in-python)

---

## Compute the nth root (Newton's method) 

~~~ cpp
#include <cmath>
double nth_root(double A, int nth) {
	double x = A, dx = 10;
	while (fabs(dx) > 0.01) {
		dx = (A/pow(x, nth-1) - x)/nth;
		x = x + dx;
	}
	return x;
}

int nth_root_to_closest_integer(double A, int nth) {
	return (nth_root(A, nth)+0.5+10E-6);
}
~~~

~~~ python
def nth_root(A, n):
    x = A;
    while True:
        dx = (1/n) * (A/(x ** (n-1)) - x);
        if abs(dx) < 0.01:
            break;
        x = x + dx;
    return x;

for i in range(1, 100):
    nth = 3;
    print('nth_root(', i, ',', nth, ') = ', nth_root(i, nth));
~~~

#### Reference
* [nth root algorithm](https://en.wikipedia.org/wiki/Nth_root_algorithm)

## Fill multi-dimensional array with constants

~~~ cpp
#include <algorithm>

int computed[100][100];

std::fill(&computed[0][0], &computed[0][0]+sizeof(computed)/sizeof(computed[0][0]), -1);
~~~ 
