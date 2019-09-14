#include <iostream>
using namespace std;

struct nuplex
{
    int real;
    int imaginaria;
};
typedef nuplex nuplex;

nuplex suplex(nuplex a , nuplex b)
{
    nuplex ans;
    ans.real = a.real + b.real;
    ans.imaginaria = a.imaginaria + b.imaginaria;

    return ans;
}

int main()
{
    nuplex nx1 , nx2 , res;
    cout << "Escriba dos numeros complejos, con parte real + parte imaginaria(i)" << endl;

    cout << "Parte real de complejo 1: ";
    cin >> nx1.real;
    cout << "Parte imaginaria de complejo 1: ";
    cin >> nx1.imaginaria;

    cout << "Parte real de complejo 2: ";
    cin >> nx2.real;
    cout << "Parte imaginaria de complejo 2: ";
    cin >> nx2.imaginaria;

    cout << suplex(nx1,nx2) << "i" << endl;

    return 0;
}
