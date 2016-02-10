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
