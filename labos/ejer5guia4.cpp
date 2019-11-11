#include <iostream>
using namespace std;

int o = 0;

struct lnodo
{
    int dato;
    struct lnodo *sig;
};
typedef struct lnodo *lodo;
lodo lista = NULL;


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
  a->izq = crearArbol(unDato);
}

void asignarDer(Arbol a, int unDato)
{
  a->der = crearArbol(unDato);
}

void mostrar(lodo lista)
{
  if(lista == NULL)
  {
    cout << "\n\tLa lista esta vacia\n";
  }
  else
  cout << endl << '\t';
  while (lista != NULL)
  {
    cout << lista->dato << " ";
    lista = lista->sig;
  }
}

void agrega(lodo &lista , int p)
{
    lodo nuevo;
    nuevo = new (struct lnodo);
    nuevo->dato = p;
    nuevo->sig = lista;

    lista = nuevo;
}

void agregar(Arbol a)
{
    int num = 0;
    cout << "\n\tIngrese el numero a agregar: ";
    cin >> num;

    Arbol p = a;
    while(true)
    {
        if(num == p->dato)
        {
            cout <<"\n\tError " << num << " ya existe" << endl;
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

    cout << "\n\tEl elemento " << num << " se agrego correctamente\n";
}

void preorden(Arbol a , int n)
{
  if (a != NULL)
  {
    if(n == a->dato)
    {
      agrega(lista , n);
      o++;
      return;
    }
    else
    {
      preorden(a->izq , n);
      preorden(a->der , n);
    }
  }
  else
  {
    return;
  }
}

void buscar(Arbol a)
{
  int n;

  cout << "\n\tIngrese el elemento a buscar: ";
  cin >> n;

  preorden(a , n);
  if(o > 0)
  {
    cout << "\n\tEl elemento se encontro y se agrego a la lista.\n";
    o = 0;
  }
  else
  {
    cout << "\n\tEl elemento no se encontro en el arbol\n";
  }
}

double promedio(lodo lista)
{
  double prom = 0;
  int cant = 0;
  while (lista != NULL)
  {
    cant++;
    prom += lista->dato;
    lista = lista->sig;
  }
  return prom / cant;
}

int main()
{
  int variable = 0;
  cout<<"Valor en la raiz: ";
  cin >> variable;
  cout << "\n\tEl elemento " << variable << " se agrego correctamente\n";

  Arbol arbol = crearArbol(variable);
  bool continuar = true;
  do
  {
    int opcion = 0;
    cout << "\nMenu:"
         << "\n\t1) Agregar"
         << "\n\t2) Buscar nodo"
         << "\n\t3) Mostrar lista"
         << "\n\tPara salir ingrese -1"
         << "\n\tOpcion elegida: ";
    cin >> opcion;
      switch(opcion)
      {
        case -1: continuar = false;
        break;
        case 1: agregar(arbol);
        break;
        case 2: buscar(arbol);
        break;
        case 3: mostrar(lista);
        break;
        default: cout << "\tOpcion erronea!" << endl;
        break;
    }
  }while(continuar);

    cout << "\n\tEl promedio de la lista de los elementos buscados y encontrados en el arbol es: " << promedio(lista) << endl;

  return 0;
}
