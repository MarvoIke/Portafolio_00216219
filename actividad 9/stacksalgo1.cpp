//Algoritmo 1
#include <iostream>
#include <stack>
using namespace std;

int main()
{
  int elemento;
  int n, opc = 1;
  bool flag = true;


	stack<int> s;


  do{
    cout << "Introducir elemento(1)" << endl << "Salir(2)" << endl;
    cin >> opc;
    if(opc == 1)
    {
      cout << "Elemento: ";
      cin >> n;
      s.push(n);
    }
    else if(opc == 2){
      flag = false;
      break;
    }
    else
      flag = false;
  }while (flag == true);

	s.pop();	// removing the top ("D")
  elemento = s.top();
	s.pop();	// removing the next top ("C")

  // Returns the number of elements present in the stack
  cout << "Stack size is " << s.size() << endl;

  // Prints the top of the stack ("D")
  cout << "Top element is: " << s.top() << endl;

  cout << "El segundo elemento es: " << elemento << endl;

	return 0;
}
