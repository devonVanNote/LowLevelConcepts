#include<iostream> 

using namespace std;

void printExamples();

int main()
{
    // initial value of X 
    int X = 10;

    cout << "Before placement new --> (int X = 10) :" << endl;
    cout << "X : " << X << endl;
    cout << "&X : " << &X << endl;

    // Placement new changes the value of X to 100 
    int* mem = new (&X) int(100);

    cout << "\nAfter placement new --> (int* mem = new (&X) int(100)) :" << endl;
    cout << "X : " << X << endl;
    cout << "mem : " << mem << endl;
    cout << "&X : " << &X << endl;

    printExamples();

    return 0;
}

void printExamples() {
    
    cout << endl << endl << "Valid:" << endl
        << "int i = 10;" << endl
        << "int* ipt = &i;" << endl
        << "int* i1 = new(ipt) int(9);" << endl;

    cout << endl << endl << "Incorrect as ip may not be a valid address (it's not pointing to anything)" << endl
        << "int* ip;" << endl
        << "int* i2 = new(ip) int(4);" << endl;

    cout << endl << endl << "Void pointers are valid:" << endl
        << "void* vd = &i;" << endl
        << "int* i3 = new(vd) int(34);" << endl;

    cout << endl << endl << "Incorrect as x is not an address: " << endl
        << "int x;" << endl
        << "int* i5 = new(x) int(3);" << endl;
}