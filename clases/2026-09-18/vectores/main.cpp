#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void imprimir(vector<int> &v)
{
    cout << "El tamaño de la lista es: "<< v.size() << endl;
    for (int n : v)
    {
        cout << n << ", ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {8, 4, 5, 9};

    v.push_back(6);
    v[0] = 3;
    v.push_back(45);

    imprimir(v);
    reverse(v.begin(), v.end());
    imprimir(v);
    v.pop_back();
    imprimir(v);

    return 0;
}
