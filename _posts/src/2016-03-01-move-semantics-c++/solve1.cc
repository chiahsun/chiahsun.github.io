#include <cstdlib>
#include <cassert>
#include <iostream>
#include <utility> // for std::swap, std::move

class Vector {
    int* _p_array;
    int _capacity, _size;
public:
    Vector() { std::cout << "Call constructor" << std::endl; init(2); }
    Vector(size_t cap) { std::cout << "Call constructor 2" << std::endl; init(cap); }
    Vector(const Vector & rhs) { 
        std::cout << "Call copy constuctor" << std::endl; 
        init(rhs.capacity());
        for (int i = 0; i < rhs.size(); ++i) _p_array[i] = rhs[i];
        _size = rhs._size;
    }
    Vector(Vector && rhs) : Vector() {  // IMPORTANT!: call default constructor to ensure that after swap, it is safe to desstruct 
        std::cout << "Call move constuctor" << std::endl; 
        swap(*this, rhs); 
    } 
    ~Vector() { 
        std::cout << "Call destuctor" << std::endl; 
        delete [] _p_array; _p_array = nullptr; _capacity = _size = 0; 
    }
    Vector& operator = (Vector rhs) {
        std::cout << "Assignment operator" << std::endl;
        swap(*this, rhs); 
        return *this;
    }
    friend void swap(Vector & x, Vector & y) {
        using std::swap;
        swap(x._p_array, y._p_array);
        swap(x._capacity, y._capacity);
        swap(x._size, y._size);
    }
    void init(size_t cap) { 
        _p_array = new int [cap]; _capacity = cap; _size = 0;
        if (_p_array == nullptr) {
            printf("Out of memory"); assert(0);
            exit(1);
        }
    }
    int size() const { return _size; }
    int capacity() const { return _capacity; }
    void resize(size_t new_cap) { 
        assert(size() <= new_cap);
        int* p_new_array = new int[new_cap]; _capacity = new_cap;
        for (int i = 0; i < size(); ++i)
            p_new_array[i] = _p_array[i];
        delete [] _p_array; _p_array = nullptr;
        _p_array = p_new_array;
    }
    void push_back(int x) {
        if (size() == capacity())
            resize(2*capacity());
        _p_array[_size++] = x;
    }
    int& operator [] (int pos) { return _p_array[pos]; }
    int operator [] (int pos) const { return _p_array[pos]; }
    friend std::ostream & operator << (std::ostream & os, const Vector & v) {
        for (int i = 0; i < v.size(); ++i)
            os << ((i != 0) ? " " : "") << v[i];
        return os;
    } 
};

Vector read_vector() {
    Vector v;
    int x;
    while (scanf("%d", &x) == 1)
        v.push_back(x);
    return v;
}


int main() {
    std::cout << "Return value optimization" << std::endl;
    // C++ Return value optimization 
    // https://www.wikiwand.com/en/Return_value_optimization
    Vector v = read_vector(); 
    std::cout << "  v contains : " << v << std::endl;

    std::cout << "Copy vector" << std::endl;
    Vector v2(v); 
    std::cout << "  v2 contains : " << v2 << std::endl;

    Vector v3(std::move(v2));
    std::cout << "  v2 contains : " << v2 << std::endl;
    std::cout << "  v3 contains : " << v3 << std::endl;

    Vector v4 = v3;
    std::cout << "  v3 contains : " << v3 << std::endl;
    std::cout << "  v4 contains : " << v4 << std::endl;
    
    Vector v5;
    v5 = v3;
    std::cout << "  v3 contains : " << v3 << std::endl;
    std::cout << "  v5 contains : " << v5 << std::endl;

    return 0;
}
