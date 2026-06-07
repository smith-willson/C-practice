#include <iostream>
using namespace std;
class box
{
public:
    int vol;

    box(int v) { vol = v; }
    box operator+(box other)
    {
        return box(vol + other.vol);
    }

    friend ostream &operator<<(ostream &out, box b)
    {
        out << "Volume: " << b.vol;
        return out;
    }
};
int main()
{
    box b1(12), b2(18);
    box b3 = b1 + b2;
    cout << b3;

    return 0;
}