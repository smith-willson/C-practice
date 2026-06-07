#include <iostream>
using namespace std;
class Animal
{
    public:

    virtual void sound(){};
};

class dog : public Animal
{
    public:
        virtual void sound(){
            cout<<" baow baow baow ......."<<endl;
        }
};

class cat : public Animal
{
    public:
        virtual void sound(){
            cout<<" meow meaow meow ......."<<endl;
        }
};

int main(){
    cat c1;
    dog d1;

    c1.sound();
    d1.sound();
}