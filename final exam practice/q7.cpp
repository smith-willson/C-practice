#include <iostream>
using namespace std;
class DATABUFFER
{
public:
    double capacity;
    double currentsize;
    int *data;

    DATABUFFER(double c = 10, double cs = 0)
    {
        capacity = c;
        currentsize = cs;
        data = new int[(int)c];
    }

    ~DATABUFFER()
    {
        delete[] data;
    }

    void set_value(int index, int value)
    {
        data[index] = value;
        currentsize++;
    }

    friend ostream &operator<<(ostream &os, const DATABUFFER &buffer)
    {
        for (int i = 0; i < buffer.currentsize; i++)
        {
            cout << buffer.data[i] << " ";
        }

        return os;
    }

    DATABUFFER operator+(DATABUFFER &buffer2)
    {
        if (currentsize == 0 | buffer2.currentsize == 0)
        {
            cout << "Empty Buffers can not concatenated." << endl;
            return 0;
        }
        DATABUFFER result(capacity + buffer2.capacity);
        for (int i = 0; i < currentsize; i++)
            result.data[i] = data[i];
        for (int i = 0; i < currentsize; i++)
            result.currentsize = currentsize + buffer2.currentsize;
        return result;
    }
};

int main()
{
    // Test 1: Normal case
    DATABUFFER b1(5);
    b1.set_value(0, 10);
    b1.set_value(1, 20);
    b1.set_value(2, 30);
    cout << "b1: " << b1 << endl;

    // Test 2: Concatenation with +
    DATABUFFER b2(3);
    b2.set_value(0, 40);
    b2.set_value(1, 50);
    cout << "b2: " << b2 << endl;

    DATABUFFER b3 = b1 + b2;
    cout << "b1 + b2: " << b3 << endl;

    // Test 3: invalid_argument (bad capacity)
    try
    {
        DATABUFFER bad(-1);
    }
    catch (invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    // Test 4: out_of_range (bad index)
    try
    {
        b1.set_value(99, 999);
    }
    catch (out_of_range &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    // Test 5: Empty buffer concatenation
    DATABUFFER empty(5);
    DATABUFFER b4 = empty + b1;

    return 0;
}