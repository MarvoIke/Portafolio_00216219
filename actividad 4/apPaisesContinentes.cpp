//Actividad portafolio #4 00216219

#include <iostream>
using namespace std;

struct pais
{
    string nombre;
    string capital;
    int poblacion;
    double promedad;
};
typedef struct pais pais;

string mayorpob(pais continente[5])
{
    int mayorparcial, mayorfinal;
    string mayornombre;
    for (int i=0;i<4;i++)
    {
        if(continente[i].poblacion > continente[i+1].poblacion)
        {
            mayorfinal = continente[i].poblacion;
            mayornombre = continente[i].nombre;
        }
        else if(continente[i].poblacion < continente[i+1].poblacion)
        {
            mayorfinal = continente[i+1].poblacion;
            mayornombre = continente[i+1].nombre;
        }
        else
        {
            mayorfinal = continente[i].poblacion;
            mayorparcial = continente[i+1].poblacion;
            mayornombre = continente[i].nombre;
        }
    }
    return mayornombre;
}

int main()
{
    int i = 0, contadorPM = 0;
    float promedadM = 0;

    pais continente1[5];
    int poblacont1 = 0;
    for (i=0;i<5;i++)
    {
        cout << "Ingrese el nombre del pais #" << i+1 << endl;
        cin >> continente1[i].nombre;

        cout << "Cual es la capital de " << continente1[i].nombre << "?" << endl;
        cin >> continente1[i].capital;

        cout << "Cuantas personas viven en " << continente1[i].nombre << "?" << endl;
        cin >> continente1[i].poblacion;
        poblacont1 += continente1[i].poblacion;

        cout << "Cual es la edad promedio de los habitantes?" << endl;
        cin >> continente1[i].promedad;
        promedadM =+ continente1[i].promedad;
    }
    cout << "La poblacion total de este continente es:" << poblacont1 << endl;
    cout << "El pais con mayor poblacion del continente1 es: " << mayorpob(continente1) << endl;

    pais continente2[5];
    int poblacont2 = 0;
    for (i=0;i<5;i++)
    {
        cout << "Ingrese el nombre del pais #" << i+1 << endl;
        cin >> continente2[i].nombre;

        cout << "Cual es la capital de " << continente2[i].nombre << "?" << endl;
        cin >> continente2[i].capital;

        cout << "Cuantas personas viven en " << continente2[i].nombre << "?" << endl;
        cin >> continente2[i].poblacion;
        poblacont2 += continente2[i].poblacion;

        cout << "Cual es la edad promedio de los habitantes?" << endl;
        cin >> continente2[i].promedad;
        promedadM =+ continente2[i].promedad;
    }
    cout << "La poblacion total de este continente es:" << poblacont2 << endl;
    cout << "El pais con mayor poblacion del continente2 es: " << mayorpob(continente2) << endl;

    pais continente3[5];
    int poblacont3 = 0;
    for (i=0;i<5;i++)
    {
        cout << "Ingrese el nombre del pais #" << i+1 << endl;
        cin >> continente3[i].nombre;

        cout << "Cual es la capital de " << continente3[i].nombre << "?" << endl;
        cin >> continente3[i].capital;

        cout << "Cuantas personas viven en " << continente3[i].nombre << "?" << endl;
        cin >> continente3[i].poblacion;
        poblacont3 += continente3[i].poblacion;

        cout << "Cual es la edad promedio de los habitantes?" << endl;
        cin >> continente3[i].promedad;
        promedadM =+ continente3[i].promedad;
    }
    cout << "La poblacion total de este continente es:" << poblacont3 << endl;
    cout << "El pais con mayor poblacion del continente3 es: " << mayorpob(continente3) << endl;

    pais continente4[5];
    int poblacont4 = 0;
    for (i=0;i<5;i++)
    {
        cout << "Ingrese el nombre del pais #" << i+1 << endl;
        cin >> continente4[i].nombre;

        cout << "Cual es la capital de " << continente4[i].nombre << "?" << endl;
        cin >> continente4[i].capital;

        cout << "Cuantas personas viven en " << continente4[i].nombre << "?" << endl;
        cin >> continente4[i].poblacion;
        poblacont4 += continente4[i].poblacion;

        cout << "Cual es la edad promedio de los habitantes?" << endl;
        cin >> continente4[i].promedad;
        promedadM =+ continente4[i].promedad;
    }
    cout << "La poblacion total de este continente es:" << poblacont4 << endl;
    cout << "El pais con mayor poblacion del continente4 es: " << mayorpob(continente4) << endl;

    pais continente5[5];
    int poblacont5 = 0;
    for (i=0;i<5;i++)
    {
        cout << "Ingrese el nombre del pais #" << i+1 << endl;
        cin >> continente5[i].nombre;

        cout << "Cual es la capital de " << continente5[i].nombre << "?" << endl;
        cin >> continente5[i].capital;

        cout << "Cuantas personas viven en " << continente5[i].nombre << "?" << endl;
        cin >> continente5[i].poblacion;
        poblacont5 += continente5[i].poblacion;

        cout << "Cual es la edad promedio de los habitantes?" << endl;
        cin >> continente5[i].promedad;
        promedadM =+ continente5[i].promedad;
    }
    cout << "La poblacion total de este continente es:" << poblacont5 << endl;
    cout << "El pais con mayor poblacion del continente5 es: " << mayorpob(continente5) << endl;
    cout << "El promedio de edad mundial es: " << promedadM/25 << endl;

    return 0;
}
