#include <iostream>
using namespace std;

int main()
{
	int v = 0 , sum = 0;
	int arr[10];
	cout << "Ingrese 10 enteros" << endl;
	while (v < 10)
	{
		cin >> arr[v];
		sum += arr[v];
		v++;
	}
	cout << "La sumatoria de todos los elementos es: " << sum << endl;
	cout << "El promedio de todos los elementos es: " << sum/10 << endl;	
	
	return 0;
}
