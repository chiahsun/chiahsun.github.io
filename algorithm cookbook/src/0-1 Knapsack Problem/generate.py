import random;

random.seed(0);

def generate_case(max_weight = 30, n_object = 3):
    MAX_VALUE = 100;
    print(max_weight);
    print(n_object);
    for _ in range(n_object):
        print(random.randint(1, max_weight), random.randint(0, MAX_VALUE));

for _ in range(1):
    generate_case();
