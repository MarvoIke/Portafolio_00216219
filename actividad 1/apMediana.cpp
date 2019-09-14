
#include <iostream>
using namespace std;

int main()
{
    int n, med2;
    float par1, par2, med1;

    cout << "Ingrese el numero de elementos a tomar en cuenta: " << endl;
    cin >> n;
    cout << "Ingrese los datos ordenados..." << endl;

    int data[n];
    for (int i=0; i<n; i++)
    {
        cin >> data[i];
    }

    if (n%2 == 0)
    {
        par1 = data[(n-1)/2];
        par2 = data[n/2];
        med1 = (par1 + par2) / 2;
        cout << endl << "La mediana de los datos introducidos es: " << med1 << endl;
    }
    else
    {
        med2 = data[n/2];
        cout << "La mediana de los datos introducidos es: " << med2 << endl;

    }

    return 0;
}
