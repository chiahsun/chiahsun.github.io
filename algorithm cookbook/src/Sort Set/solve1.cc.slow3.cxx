#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

class SortSet {
    std::vector<std::vector<int> > _vec;
public:
    SortSet() { _vec.resize(2); }
    
    int count(int x) const {
        // for (size_t i = 0; i < _vec.size(); ++i) {
        for (int i = _vec.size()-1; i >= 0; --i) {
            if (_vec[i].size() != 0) {
                if (x >= _vec[i].front() and x <= _vec[i].back()) {
                    auto it = std::lower_bound(_vec[i].begin(), _vec[i].end(), x);
                    if (it != _vec[i].end() and *it == x)
                        return 1;
                }
            }
        }
        return 0;
    }

    void insert(int x) {
        if (count(x))
            return;

        assert(_vec[0].size() == 0);
        _vec[0].push_back(x);

        if (_vec.back().size() != 0)
            _vec.push_back(std::vector<int>());
        for (size_t i = 0; i < _vec.size(); ++i) {
            if (i == 0) {
                if (_vec[1].size() == 0) {
                    std::swap(_vec[1], _vec[0]);
                    break;
                } else merge(0, 1);
            } else {
                if (_vec[i+1].size() == _vec[i].size()) merge(i, i+1);
                else { merge(i, i+1); break; }
            }
        }
    }
private:
    void merge(int x, int y) {
        assert(x >= 0 and x < _vec.size() and y >= 0 and y < _vec.size());
        std::vector<int> & A = _vec[x];
        std::vector<int> B(_vec[y]);
        std::vector<int> & C = _vec[y];
        C.resize(A.size() + B.size());
        for (size_t i = 0, pos1 = 0, pos2 = 0; i < C.size(); ++i) {
            if (pos1 < A.size() and pos2 < B.size()) {
                C[i] = (A[pos1] < B[pos2]) ? A[pos1++] : B[pos2++];
            } else if (pos1 < A.size()) {
                C[i] = A[pos1++];
            } else {
                C[i] = B[pos2++];
            }
        }
#if 0
        C.clear(); C.reserve(A.size() + B.size());
        for (size_t pos1 = 0, pos2 = 0; pos1 < A.size() or pos2 < B.size();) {
            if (pos2 >= B.size() or (pos1 < A.size() and A[pos1] <= B[pos2]))
                C.push_back(A[pos1++]);
            else
                C.push_back(B[pos2++]);
        }
#endif
        A.clear();
    }

public:
    void print() const {
        for (size_t i = 0; i < _vec.size(); ++i) {
            printf("%zu :", i);
            for (auto x : _vec[i])
                printf(" %d", x);
            printf("\n");
        }
    }
};


void test_insert() {
    SortSet ss;
    for (int i = 0; i < 10; ++i) {
        printf("Now add : %d\n", i);
        ss.insert(i);
        ss.print();
    }
    for (int i = 10; i >= 0; --i) {
        printf("Now add : %d\n", i);
        ss.insert(i);
        ss.print();
    }
}

char cmd[50];

int main() {

    int x;
    SortSet ss;
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
