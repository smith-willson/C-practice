#include <iostream>
using namespace std;
class Force {
    public:
    
    double calculate(int mass, int acceleration){
        return mass * acceleration;
    }

    double calculate(double mass, double acceleration){
        return mass * acceleration;
    }

    double calculate(int mass, int acceleration, double friction){
        return (mass * acceleration) - friction;
    }

};

int main(){

    Force f1;

    cout<<"Force = "<<f1.calculate(5, 3) << " N" <<endl;
    cout<<"Force = "<<f1.calculate(5.5, 3.2) << " N" <<endl;
    cout<<"Force = "<<f1.calculate(5, 3, 2.0) << " N" <<endl;


    return 0;
}