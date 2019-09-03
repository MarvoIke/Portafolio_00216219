#include <iostream>
using namespace std;

int main(void)
{
    int mtx[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};

    cout << "introduzca los valores" << endl;

    for(int i = 0; i < 5; i++)
    {
        cin >> mtx[0][i];
    }

    for(int i = 0; i < 4; i++)
    {
        cin >> mtx[1][i+1];
    }

    for(int i = 0; i < 3; i++)
    {
        cin >> mtx[2][i+2];
    }

    for(int i = 0; i < 2; i++)
    {
        cin >> mtx[3][i+3];
    }

    cin >> mtx[4][4];

    for(int i = 0; i < 5; i++)
    {
        cout << endl;
        for(int j = 0; j < 5; j++)
        {
            cout << mtx[i][j]<< " ";
        }
    }

    return 0;
}
