#include <iostream>
#include <string>
using namespace std;

struct persona{
    int carne;
    string nombre;
    string apellido;
    int edad;
    int tel;
    string correo;
};
typedef struct persona pipol;

pipol solicitar()
{
    pipol p;
    cout << "Carnet: "; cin >> p.carne;
    cin.ignore();
    cout << "Nombre: "; getline(cin , p.nombre);
    cout << "Apellido: "; cin >> p.apellido;
    cout << "Edad: "; cin >> p.edad;
    cout << "Telefono: "; cin >> p.tel;
    cout << "Correo electronico: "; cin >> p.correo;

    return p;
}

void mostrar(pipol p)
{
  cout << endl;
  cout << "Carnet: " << p.carne << endl;
  cout << "Nombre: " << p.nombre << endl;
  cout << "Apellido: " << p.apellido << endl;
  cout << "Edad: " << p.edad << endl;
  cout << "Telefono: " << p.tel << endl;
  cout << "Correo electronico: " << p.correo << endl;
}

struct cnodo
{
    pipol dato;
    struct cnodo *sig;
};
typedef struct cnodo nodo;

nodo *pInicio;

void eliminar()
{
  if(pInicio == NULL)
  cout << "La lista esta vacia, por favor agregue datos primero." << endl;

  else{
    int uncarne = 0;
    cout << "Carnet de la persona a eliminar: ";
    cin >> uncarne;

    if(pInicio == NULL)
    cout << "La lista esta vacia, por favor agregue datos primero." << endl;

    else{
      nodo *p = pInicio, *q = NULL;

      while(p != NULL && (p->dato).carne != uncarne)
      {
          q = p;
          p = p->sig;
      }
      if(p == NULL){
          cout << "Persona a borrar NO existe" << endl;
      }
      if(q == NULL)
          pInicio = p->sig;
      else
          q->sig = p->sig;
      delete(p);
      cout << "Persona eleiminada correctamente" << endl;
    }
  }
}

void insertarInicio(pipol p) {
    nodo *nuevo = new nodo;
    nuevo->dato = p;
    nuevo->sig = pInicio;

    pInicio = nuevo;
}

void insertarFinal(pipol p) {
    nodo *nuevo = new nodo;
    nuevo->dato = p;
    nuevo->sig = NULL;

    if (pInicio == NULL) {
        pInicio = nuevo;
    } else {
        nodo *p = pInicio;
        nodo *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->sig;
        }
        q->sig = nuevo;
    }
}

void insertarDespuesDe(pipol p) {
    int uncarne;
    cout << "Caret de la persona de referencia: ";
    cin >> uncarne;

    nodo *s = pInicio;

    while(s != NULL && (s->dato).carne != uncarne)
        s = s->sig;
    if(s == NULL){
        cout << "Carnet de referencia NO existe" << endl;
        return;
    }

    nodo *nuevo = new nodo;
    nuevo->dato = p;
    nuevo->sig = s->sig;

    s->sig = nuevo;
    cout << "Persona insertada con exito" << endl;
}

void insertarAntesDe(pipol p) {
    int uncarne = 0;
    cout << "Carnet de libro de referencia: ";
    cin >> uncarne;

    nodo *s = pInicio, *q = NULL;

    while(s != NULL && (s->dato).carne != uncarne){
        q = s;
        s = s->sig;
    }
    if(s == NULL){
        cout << "Carnet de referencia NO existe" << endl;
        return;
    }

    nodo *nuevo = new nodo;
    nuevo->dato = p;
    nuevo->sig = s;

    if(q == NULL)
        pInicio = nuevo;
    else
        q->sig = nuevo;
    cout << "Persona insertada con exito" << endl;
}

void agregar()
{
  bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n\t1) Al principio\n\t2) Al final"
            << "\n\t3) Despues de\n\t4) Antes de"
            << "\n\tOpcion elegida: ";
        cin >> opcion;
        pipol p = solicitar();
        switch(opcion){
            case 1: insertarInicio(p);  continuar = false;
            break;
            case 2: insertarFinal(p);   continuar = false;
            break;
            case 3: insertarDespuesDe(p);   continuar = false;
            break;
            case 4: insertarAntesDe(p);   continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
    cout << "Persona agregada exitosamente" << endl;
}

void mostrarpersonas()
{
  if(pInicio == NULL)
  cout << "La lista esta vacia, por favor agregue datos primero." << endl;

  else{
    nodo *s = pInicio;

    while (s != NULL)
    {
        mostrar(s->dato);
        s = s->sig;
    }
  }
}

void actualizar()
{
  if(pInicio == NULL)
  cout << endl << "La lista esta vacia, por favor agregue datos primero." << endl;

  else{
    int uncarne = 0;
    cout << "Carnet de persona a actualizar: ";
    cin >> uncarne;

    nodo *p = pInicio, *q = NULL;

    while(p != NULL && (p->dato).carne != uncarne){
        q = p;
        p = p->sig;
    }
    if(p == NULL){
        cout << "Persona a actualizar NO existe" << endl;
        return;
    }
    if(q == NULL)
        pInicio = p->sig;
    else
        q->sig = p->sig;
    agregar();
  }
}


void menux()
{
  bool continuar = true;
  do {
    char opcion;
    cout << "\n\ta) Llenar la lista"
         << "\n\tb) Eliminar una persona"
         << "\n\tc) Actualizar los datos de una persona"
         << "\n\td) Mostrar todas las personas"
         << "\n\te) Salir"
         << "\n\t Opcion elegida: ";
         cin >> opcion;
         switch (opcion) {
           case 'A':
           case 'a': agregar();
           break;

           case 'B':
           case 'b': eliminar();
           break;

           case 'C':
           case 'c': actualizar();
           break;

           case 'D':
           case 'd': mostrarpersonas();
           break;

           case 'E':
           case 'e': continuar = false;
           break;

           default: cout << "Opcion erronea!" << endl;
           break;
         }
  } while(continuar);
}

int main(){
    cout << "Inicializando..." << endl;
    pInicio = NULL;

    menux();

    return 0;
}
