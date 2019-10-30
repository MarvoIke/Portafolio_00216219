#include <iostream>
using namespace std;

int h=0;
int y=0;

struct nodo
{
    int dato;
    struct nodo *izq;
    struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *Arbol;

Arbol crearArbol(int x)
{
    Arbol p = new Nodo;
    p->dato = x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}

void asignarIzq(Arbol a, int unDato)
{
    if(a == NULL)
        cout << "Error arbol vacio" << endl;
    else if(a->izq != NULL)
        cout << "Error sub-arbol izquierdo ya existe" << endl;
    else
        a->izq = crearArbol(unDato);
}

void asignarDer(Arbol a, int unDato)
{
    if(a == NULL)
        cout << "Error arbol vacio" << endl;
    else if(a->der != NULL)
        cout << "Error sub-arbol derecho ya existe" << endl;
    else
        a->der = crearArbol(unDato);
}

void agregarNodo(Arbol a)
{
    int num = 0;
    cout << "Ingrese un numero: ";
    cin >> num;

    Arbol p = a;
    while(true)
    {
        if(num == p->dato)
        {
            cout <<"1. Error " << num << " ya existe" << endl;
            return;
        }
        else if(num < p->dato)
        {
            if(p->izq == NULL)
                break;
            else
                p = p->izq;
        }
        else
        {
            if(p->der == NULL)
                break;
            else
                p = p->der;
        }
    }
    if(num < p->dato)
        asignarIzq(p, num);
    else
        asignarDer(p, num);
}

void preorden(Arbol a)
{
    if(a != NULL)
    {
        cout << " " << a->dato;
        preorden(a->izq);
        preorden(a->der);
    }
}
void inorden(Arbol a)
{
    if(a != NULL)
    {
        inorden(a->izq);
        cout << " " << a->dato;
        inorden(a->der);
    }
}
void postorden(Arbol a)
{
    if(a != NULL)
    {
        postorden(a->izq);
        postorden(a->der);
        cout << " " << a->dato;
    }
}

void recorrerArbol(Arbol a)
{
    cout << "Recorrido PRE orden:"; preorden(a); cout << endl;
    cout << "Recorrido IN orden:"; inorden(a); cout << endl;
    cout << "Recorrido POST orden:"; postorden(a); cout << endl;
}

void profundidad(Arbol a)
{
    if(a!=NULL)
    {
        h++;
        profundidad(a->izq);
        profundidad(a->der);
        if(y<h){
        y=h;}
        h--;

    }
}

int main()
{
    int variable = 0;
    cout<<"Valor en la raiz: ";
    cin >> variable;

    Arbol arbol = crearArbol(variable);

    bool continuar = true;
    do
    {
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar\n\t2) Recorrer"
            << "\n\t3)Profundidad \n\t 4) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: agregarNodo(arbol);
            break;
            case 2: recorrerArbol(arbol);
            break;
            case 3: profundidad(arbol);
            cout<< "La profundidad es: " << y - 1<<endl;
            break;
            case 4: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}
