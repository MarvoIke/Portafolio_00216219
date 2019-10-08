#include <iostream>
#include <string>
using namespace std;

struct orden{
    int R;
    int FQ;
    int Q;
    bool A;
};
typedef struct orden porden;

porden solicitarorden(){
    porden p;
    cout << "De arroz o maiz: "; cin >> p.A;
    cout << "Cuantas revueltas: "; cin >> p.R;
    cout << "Cuantas de frijol con queso: ";   cin >> p.FQ;
    cout << "Cuantas de queso: "; cin >> p.Q;
    return p;
}

void mostrarorden(porden p){
    cout << "revueltas: " << p.R << endl;
    cout << "frijol con queso: " << p.FQ << endl;
    cout << "queso: " << p.Q << endl;
    if(p.A == true)
    cout << "son de: Arroz" << endl;
    else
    cout << "son de: Maiz" << endl;
    cout << endl;
}

struct TNodo{
    porden dato;
    struct TNodo *sig;
};
typedef struct TNodo Nodo;
Nodo *pInicio;

void insertarInicio(porden p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = pInicio;

    pInicio = nuevo;
}

void insertarFinal(porden p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = NULL;

    if (pInicio == NULL) {
        pInicio = nuevo;
    } else {
        Nodo *p = pInicio;
        Nodo *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->sig;
        }
        q->sig = nuevo;
    }
}

void agregarorden(){
    porden p = solicitarorden();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n\t2) Al final"
            << "\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: insertarInicio(p);
                continuar = false;
            break;
            case 2: insertarFinal(p);
                continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
}

void mostrarorden() {
    Nodo *s = pInicio;

    while (s != NULL) {
        mostrarorden(s->dato);
        s = s->sig;
    }
}

int main(){
    cout << "Inicializando..." << endl;
    pInicio = NULL;

    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar orden\n\t2) Ver ordenes"
            << "\n\t3) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarorden();
            break;
            case 2: cout << "Listando..." << endl;
                mostrarorden();
            break;
            case 3: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}
