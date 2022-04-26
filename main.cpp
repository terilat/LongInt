#include <iostream>
#include <fstream>
//#define N 5

#include "CIntN.h"
#include "CIntN.cpp"


using namespace std;

int main(){
    CIntN a(5), b(10);
    cin >> a >> b;
    cout << endl;
    cout << (a + b) << endl;
    cout << (a - b) << endl;
    return 0;
}
