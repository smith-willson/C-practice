#include <iostream>
using namespace std;
class Findvolume {
    public:
    
        double Area(double r){
            return  (4.0 / 3.0) * 3.14159 * r * r * r;
        }

        double Area(double w, double h, double l){
            return w * h * l;
        }

        double Area(double r, double h){
            return 3.14159 * r * r * h;
        }
};
int main(){

    Findvolume s1;

    cout <<"Sphere Volume: "<< s1.Area(3.0)  << endl;

    cout <<"Box Volume: "<< s1.Area(3.0, 3.9, 3.2)  << endl;

    cout <<"Cylinder Volume: "<< s1.Area(3.0, 1.6)  << endl;






    return 0;
}