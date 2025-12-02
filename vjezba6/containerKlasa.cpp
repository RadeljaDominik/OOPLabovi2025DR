#include <iostream>
#include <utility>

using namespace std;

class Container {
private:
    int* data;
    size_t sz;
    size_t cap;

public:
    Container(size_t initial_capacity = 0)
        : data(nullptr), sz(0), cap(initial_capacity)
    {
        if (cap > 0)
            data = new int[cap];
    }

    Container(const Container& other)
        : sz(other.sz), cap(other.cap)
    {
        data = (cap > 0) ? new int[cap] : nullptr;
        for (size_t i = 0; i < sz; i++)
            data[i] = other.data[i];
    }

    Container(Container&& other) noexcept
        : data(other.data), sz(other.sz), cap(other.cap)
    {
        other.data = nullptr;
        other.sz = 0;
        other.cap = 0;
    }

    ~Container() {
        delete[] data;
    }

    void push_back(int value) {
        if (sz == cap) {
            size_t newcap = (cap == 0 ? 1 : cap * 2);
            int* newdata = new int[newcap];

            for (size_t i = 0; i < sz; i++)
                newdata[i] = data[i];

            delete[] data;
            data = newdata;
            cap = newcap;
        }

        data[sz++] = value;
    }

    size_t size() const { return sz; }
    size_t capacity() const { return cap; }

    int& at(size_t index) {
        if (index >= sz) throw out_of_range("Index out of range");
        return data[index];
    }

    const int& at(size_t index) const {
        if (index >= sz) throw out_of_range("Index out of range");
        return data[index];
    }

    void clear() {
        sz = 0;
    }
};

void test_by_value(Container c) {
    cout << "Container primljen po vrijednosti (copy)\n";
}

Container create_container() {
    Container c(2);
    c.push_back(10);
    c.push_back(20);
    return c;
}

int main() {
    Container a(2);
    a.push_back(5);
    a.push_back(10);
    a.push_back(15);

    Container b = a;

    Container c = std::move(a);

    test_by_value(b);

    Container d = create_container();

    d.push_back(30);
    d.push_back(40);
    d.push_back(50);

    cout << endl<<"Ispis svih elemenata containera d"<<endl;
    for (size_t i = 0; i < d.size(); i++)
        cout << "Index " << i << " = " << d.at(i) << endl;

    return 0;
}
