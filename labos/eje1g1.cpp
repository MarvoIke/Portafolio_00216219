#include <iostream>
using namespace std;

int mcd(int may , int men)
{
  int macodi , res = may % men;

  if(res == 0)
  {
    macodi = men;
    return macodi;
  }
  else
    mcd(men , res);
}

int main()
{
  int mayor = 0 , menor = 0;
  cout << "Ingrese dos numeros enteros" << endl;
  cin >> mayor;
  cin >> menor;

  cout << "El MCD de " << mayor << " y " << menor << " es: " << mcd(mayor , menor) << endl;

  return 0;
}
