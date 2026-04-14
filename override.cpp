#include <iostream>
using namespace std;
class Shape {
    public:
    virtual void draw(){
        cout<<"Drawing Shape ..........."<<endl;
    }

    virtual ~Shape(){ }  //important and also a Good practice.....
};

class circle : public Shape {
    public:
    void draw() override {
        cout<<"Drawing circle ............"<<endl;
    }
};


int main(){

    circle c;
    c.draw();

    Shape* s = new circle();
    s->draw();

    return 0;
}