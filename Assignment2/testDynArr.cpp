#include <iostream>
using namespace std;

#include "dynArr.hpp"

void example1() {

    DynArr<int> d;

    d.add(1);

    cout << "\n1. " << d[0];

    d.add(2);

    cout << "\n2. " << d[0] << d[1];

    cout << "\n3. " << d.show();

    d.reverse();

    cout << "\n4. " << d.show();

    d.append(d);

    cout << "\n5. " << d.show();

    DynArr<int> d2;

    d2 = d;

    cout << "\n6. " << d2.show();

    d.reverse();

    d2.append(d);

    cout << "\n7. " << d2.show();

}


template<typename T>
void someFunc(int i, DynArr<T> d) {
    d.reverse();

    cout << "\n" << i << ". " << d.show();
}


void example2() {

    DynArr<bool> d = DynArr<bool>();

    d.add(true);

    cout << "\n1. " << d[0];

    d.add(false);

    cout << "\n2. " << d[0] << d[1];

    cout << "\n3. " << d.show();

    someFunc<bool>(3,d);

    cout << "\n4. " << d.show();

    someFunc<bool>(5,DynArr<bool>(true, 2));

    DynArr<bool> d2;

    d2 = move(d);

    d2.add(false);

    cout << "\n6. " << d2.show();



}


int main() {
    cout << "\n\n *** example1 *** \n";
    example1();

    cout << "\n\n *** example2 *** \n";
    example2();
}
