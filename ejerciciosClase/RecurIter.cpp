#include <iostream>
using namespace std;

int main()
{
    int num , cont = 0;
    cin >> num;
    for(int i=0; i<=num; i++)
    {
        cont += i;
    }
    cout << cont << endl;
    return 0;
}
