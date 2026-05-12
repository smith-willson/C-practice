#include <iostream>
using namespace std;

template <class T>
T findMax(T arr[], int size) {
    T max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main() {
    
    int intArr[] = {3, 7, 1, 9, 4};
    int intSize = 5;
    cout << "Max int: " << findMax(intArr, intSize) << endl;


    
    double dblArr[] = {2.5, 8.1, 3.7, 6.2};
    int dblSize = 4;
    cout << "Max double: " << findMax(dblArr, dblSize) << endl;

    
    char charArr[] = {'b', 'z', 'a', 'm'};
    int charSize = 4;
    cout << "Max char: " << findMax(charArr, charSize) << endl;

    return 0;
}
