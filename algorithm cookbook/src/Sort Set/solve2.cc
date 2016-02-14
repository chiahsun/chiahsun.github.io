#include <set>

char cmd[50];

int main() {

    int x;
    std::set<int> ss;
    while (scanf("%s", cmd) == 1) {
        if (!strcmp(cmd, "ADD")) {
            scanf("%d", &x);
            ss.insert(x);
        } else if (!strcmp(cmd, "QUERY")) {
            scanf("%d", &x);
            if (ss.count(x)) printf("%d is in set\n", x);
            else printf("%d is not in set\n", x);
        }
    }

    return 0;
}
