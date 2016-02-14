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
