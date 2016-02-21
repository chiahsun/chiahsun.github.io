---
layout: page
title: Algorithm Cookbook 
text: Algorithm for quick reference
---

### Get interval sum <small>[ideone](https://ideone.com/czSP43)</small>

~~~ cpp
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
~~~ 

Input

~~~
10
1 2 3 4 5 6 7 8 9 10
0 1
1 3
2 4
5 8
9 10
~~~

Output

~~~
1 -> sum = 1
2 3 -> sum = 5
3 4 -> sum = 7
6 7 8 -> sum = 21
10 -> sum = 10
~~~

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


### Longest Strictly Increasing / Decreasing Subsequence <small>[ideone](https://ideone.com/XYtuU7)</small>

~~~ cpp
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

~~~ 

The above code computes the LIS and prints the last longest stricly increasing sequence.

Input

~~~
8 10 4 13 16 5 3 3 1 13 18 10 2 8 17
~~~

Output 

~~~
8 10 13 16 17 
~~~

#### Online judge

[(UVA 481 What Goes Up, medium)](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=422)
[(UVA 11456 Trainsorting, medium)](https://uva.onlinejudge.org/external/114/11456.pdf)

### Longest Common Subsequence <small>[ideone](http://ideone.com/KikDRt)</small>

~~~ cpp
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

~~~ 

Input

~~~
8
1 3 2 4 3 5 4 6
4
3 4 5 6
~~~

Output 

~~~
lcc length : 4
3 4 5 6 
~~~

#### Online judge

[(UVA 531 Compromise, elementary)](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=472)



{% comment %}

### Title <small>[ideone]()</small>

~~~ cpp
~~~ 

Input

~~~
~~~

Output 

~~~
~~~

#### Online judge

[(UVA )]()


{% endcomment %}

---

## Challenges

<table class="table table-bordered table-hover">
    <thread>
            <th>Dynamic programming</th>
            <th>Difficulty</th>
            <th>Description</th>
            <th>Solution</th>
    </thread>
    <tbody>
        <tr class="info">
            <td><a href="https://algospot.com/judge/problem/read/QUANTIZE">Algospot QUANTIZE</a></td>
            <td>hard</td>
            <td>Good problem to test a problem can be solved by its sub-problem</td>
            <td><a href="https://github.com/chiahsun/problem_solving/tree/master/Algospot/QUANTIZE/solve1.cc">github</a></td>
        </tr>
    </tbody>
</table>

<table class="table table-bordered table-hover">
    <thread>
            <th>Combinatorial search</th>
            <th>Difficulty</th>
            <th>Description</th>
            <th>Solution</th>
    </thread>
    <tbody>
        <tr class="info">
            <td><a href="http://poj.org/problem?id=2676">POJ 2676 - Sudoku</a></td>
            <td>simple</td>
            <td>Constraint satisfaction problem, learn how to do constraint propogation efficiently</td>
            <td><a href="https://github.com/chiahsun/problem_solving/blob/master/POJ/2676%20-%20Sudoku/solve1.cc">github</a></td>
        </tr>
        <tr class="info">
            <td><a href="https://algospot.com/judge/problem/read/KAKURO2">Algospot KAKURO2</a></td>
            <td>intermediate</td>
            <td>Constraint satisfaction problem, learn how to do constraint propogation efficiently</td>
            <td><a href="https://github.com/chiahsun/problem_solving/blob/master/Algospot/KAKURO2/solve1.cc">github</a></td>
        </tr>
    </tbody>
</table>

