#include <iostream>
using namespace std;
class battery
{
public:
    virtual void charge(){
        cout<<"Charging........."<<endl;
    }  
};

class phone : public battery
{
public:
    battery obj;
    void powerON(){
        obj.charge();
        cout<<"Phone ON"<<endl;
    } 
};
int main(){
    phone p1;
    p1.powerON();


    return 0;
}