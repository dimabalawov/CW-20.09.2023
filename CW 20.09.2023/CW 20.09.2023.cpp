


#include <iostream>
using namespace std;

class Array
{
    int* ptr;
    int size;
public:
    Array() = default;
    Array(int s)
    {
        ptr = new int[s];
        size = s;
    }
    Array(const Array& b)
    {
        size = b.size;
        ptr = new int[b.size];
        for (size_t i = 0; i < b.size; i++)
        {
            ptr[i] = b.ptr[i];
        }
    }
    Array(Array&& a)
    {
        cout << "move constructor" << endl;
        size = a.size;
        a.size = 0;
        ptr = a.ptr;
        a.ptr = nullptr;
    }
    ~Array()
    {
        delete[] ptr;
    }
    Array& operator=(const Array& b)
    {
        if (this == &b)
            return *this;
        delete[] ptr;
        ptr = new int[b.size];
        size = b.size;
        for (size_t i = 0; i < size; i++)
            ptr[i] = b.ptr[i];
        return *this;
    }
    Array& operator=(Array&& b)
    {
        if (this == &b)
            return *this;
        size = b.size;
        b.size = 0;
        ptr = b.ptr;
        b.ptr = 0;
        return *this;
    }
    void ByVal(Array obj)
    {

    }
    Array ByVal()
    {
        Array arr(5);
        return arr;
    }
};

int main()
{
    
}

