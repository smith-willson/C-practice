#include <iostream>
#include <cmath>
using namespace std;
class complex_no {
    private:

        int real;
        int imag;

    public:

        complex_no(){
            real = 0;
            imag = 0;
        }

        complex_no(int r, int i){
            real = r;
            imag = i;
        }

        complex_no(const complex_no &obj){
            real = obj.real;
            imag = obj.imag;
        }

        void display(){
            if(imag >= 0){
                cout<< real << " + " << imag << "i"<< endl; 
            }

            else 
                cout<< real << " - " << imag << "i"<< endl;
        }

        double Magnitude(){
            return sqrt((real * real) + (imag * imag));
        }

        complex_no operator+(complex_no &obj){
            complex_no temp;

            temp.real = real + obj.real;
            temp.imag = imag + obj.imag;

            return temp;
        }

        complex_no operator-(complex_no &obj){
            complex_no temp;

            temp.real = real - obj.real;
            temp.imag = imag - obj.imag;

            return temp;
        }

};


class counter
{
    private:
        int value;

    public:
        counter()
        {
            value = 0;
        }

        int increament(){
            return ++value;
        }

        int decreament(){
            return --value;
        }

        void display(){
            cout<<"NEW VALUE: "<<value<<endl;
        }
};


int main(){

    complex_no cn1(12, 12);
    complex_no cn2(12, 12);

    cout<<"THE FIRST COMPLEX NUMBER: ";
    cn1.display();
    
    cout<<"THE SECOND COMPLEX NUMBER: ";
    cn2.display();

    cout<<"THE ADDITION OF CN1 and CN2: ";
    complex_no cn3 = cn1 + cn2;
    cn3.display();

    cout<<"THE subtraction OF CN1 and CN2: ";
    complex_no cn4 = cn1 - cn2;
    cn4.display();

    counter c1;

    c1.increament();
    c1.increament();
    c1.display();

    c1.decreament();
    c1.display();

    return 0;
}