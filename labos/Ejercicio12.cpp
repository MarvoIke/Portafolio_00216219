#include <iostream>
using namespace std;

int main()
{
    int numero, numeroaux, cifras = 1;

    cout << "Escriba un numero" << endl;
    cin >> numero;
    numeroaux = numero;
    while (numero >= 10)
    {
        numero /= 10;
        cifras++;
    }

    int arr[cifras];

    for (int i = 0; i < cifras; i++)
    {
        arr[i] = numeroaux%10;
        numeroaux /= 10;
    }

    for (int j = 0; j < cifras; j++)
    {
        cout << arr[j];
    }

    return 0;
}
