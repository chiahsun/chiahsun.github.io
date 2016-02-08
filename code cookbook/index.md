---
layout: page
title: Code Cookbook 
text: Code for quick reference
---

### Determine if a specific number is prime <small>[ideone](https://ideone.com/iB13l8)</small>

~~~ cpp
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

~~~

Input

~~~
100
~~~

Output 

~~~
Primes less than 100 : 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
~~~

#### Online judge

[(UVA 10533 digit primes)](https://uva.onlinejudge.org/external/105/10533.pdf)

#### Reference

* [Determine if a number is prime @ stackoverflow](http://stackoverflow.com/questions/1538644/c-determine-if-a-number-is-prime)

---

### 0-1 Knapsack Problem <small>[ideone](https://ideone.com/5XZhWQ)</small>

~~~cpp
#include <cstdio>
#include <cassert>
#include <algorithm>

const int MAX_NUM_OBJECTS = 30;
const int MAX_NUM_WEIGHTS = 100;
int knapsack[MAX_NUM_OBJECTS+5][MAX_NUM_WEIGHTS+5];
bool knapsack_taken[MAX_NUM_OBJECTS+5][MAX_NUM_WEIGHTS+5];
int knapsack_n_taken[MAX_NUM_OBJECTS+5][MAX_NUM_WEIGHTS+5];

struct Object { 
    int _weight, _value; 
    int weight() const { return _weight; } 
    int value() const { return _value; } 
} objects[MAX_NUM_OBJECTS];

void print_object(int nObject, int nWeight) {
    if (nObject != 0 and nWeight != 0) {
        if (knapsack_n_taken[nObject][nWeight]) {
            int cur_object_value = objects[nObject].value();
            int cur_object_weight = objects[nObject].weight();
            print_object(nObject-1, nWeight-cur_object_weight);
            printf("  %d %d\n", cur_object_weight, cur_object_value);
        } else {
            print_object(nObject-1, nWeight);
        }
    }
}

int main() {
    int max_weight, nObject, posCase = 1;
    while (scanf("%d%d", &max_weight, &nObject) == 2) {
        assert(max_weight <= MAX_NUM_WEIGHTS);
        assert(nObject < MAX_NUM_OBJECTS);
        for (int i = 1; i <= nObject; ++i) {
            scanf("%d%d", &objects[i]._weight, &objects[i]._value);
            assert(objects[i].weight() <= MAX_NUM_WEIGHTS);
        }

        for (int i = 0; i <= max_weight; ++i) knapsack[0][i] = knapsack_n_taken[0][i] = 0;
        for (int i = 0; i <= nObject; ++i) knapsack[i][0] = knapsack_n_taken[i][0] = 0;

        for (int i = 1; i <= nObject; ++i)
            for (int k = 1; k <= max_weight; ++k) {
                int cur_object_weight = objects[i].weight();
                int cur_object_value = objects[i].value();
                    
                int prev_value = knapsack[i-1][k];
                int reduced_weight = k-cur_object_weight;
                int taken_value = cur_object_value + knapsack[i-1][reduced_weight];

                knapsack[i][k] = prev_value;
                knapsack_taken[i][k] = false;
                knapsack_n_taken[i][k] = knapsack_n_taken[i-1][k];

                if (k >= cur_object_weight and taken_value > prev_value) {
                    knapsack[i][k] = taken_value;
                    knapsack_taken[i][k] = true;
                    knapsack_n_taken[i][k] = knapsack_n_taken[i-1][reduced_weight] + 1; 
                }
            }


        printf("Case #%d\n", posCase++);
        printf("  max value : %d\n", knapsack[nObject][max_weight]);
        printf("  num of object : %d\n", knapsack_n_taken[nObject][max_weight]);
        print_object(nObject, max_weight);
    }
    return 0;
}

~~~

Input

~~~
50
3
10 60
20 100
30 120
~~~

Output 

~~~
Case #1
  max value : 220
  num of object : 2
  20 100
  30 120
~~~

#### Online judge

[(UVA 990 Diving for Gold)](https://uva.onlinejudge.org/external/9/990.pdf)

