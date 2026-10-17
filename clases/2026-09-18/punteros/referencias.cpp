#include <iostream>

using namespace std;


void incrementar(int &valor)
{
    valor += 1;
}

int main()
{
    // int a = 5;
    // cout << a << endl;
    // cout << &a << endl;
    // incrementar(a); 
    // cout << a << endl;
    // cout << &a << endl;
    int a = 5;
    int b = a;
    int &c = a;
    b = 7;
    c = 11;
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<b<<endl;
    cout<<&b<<endl;
    cout<<c<<endl;
    cout<<&c<<endl;
    return 0;
}
