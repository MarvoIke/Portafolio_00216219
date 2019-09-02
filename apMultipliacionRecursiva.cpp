#include <iostream>
using namespace std;

int mult(int a , int b)
{
	if(b==1)
	{
		return a;
	}
	else
	{
		return a+mult(a , b-1);
	}
}
int main(void)
{
	int a = 0, b = 0;
	cout << "escriba a:" << endl;
	cin >> a;
	cout << "escriba b:" << endl;
	cin >> b;

	cout << "la multiplicacion es:" << mult(a,b) << endl;
	
	return 0;
}