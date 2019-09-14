#include <iostream>
using namespace std;

void hanoi(int n,char A,char C,char B)
{
    if(n==1)
    {
            cout << "Disco " << n << " de " << A << " a  " << C << endl;

    }
    else
    {
        hanoi(n-1,A,B,C);
        cout << "Disco " << n << " de " << A << " a  " << C << endl;
        hanoi(n-1,B,C,A);
    }
}

int main()
{
    int n;
    char A,B,C;
    cout << "Numero de discos: ";
    cin >> n;
    hanoi(n,'A','C','B');

    return 0;
}
