#include <cstdlib>
#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo *sig;
}*inicio;

class ListaEnlazada {

public:

    ListaEnlazada() {
        inicio = nullptr;
    }

    Nodo* crearNodo(int valor) {
        Nodo *n = new Nodo;
        n->dato = valor;
        n->sig = nullptr;
        return n;
    }

    void agregarElemento(int valor) {
        Nodo *n = crearNodo(valor), *temp;
        if(!inicio) {
            inicio = n;
        }
        else {
            for(temp=inicio; temp->sig; temp = temp->sig);
            temp->sig = n;
        }
    }

    Nodo* getInicio() {
        return inicio;
    }

    int contarElementos(Nodo* inicio) {
        if(inicio == NULL) {
            return 0;
        }
        return 1 + contarElementos(inicio->sig);
    }

    void mostrarLista() {
        Nodo *temp = inicio;
        if(!inicio) {
            cout<<"La lista no posee elementos"<<endl;
        }
        else {
            while(temp) {
                cout<<temp->dato<<" ";
                temp = temp->sig;
            }
        }
    }

    void cambiarPosiciones(int x, int y) {
        int aux;
        Nodo *saltarin = inicio;
        Nodo *tempX;
        Nodo *tempY;

        if(x > contarElementos(inicio) || y >  contarElementos(inicio)) {
            cout << "Alguna de las dos posiciones que se desea cambiar es mayor al tamaño de la lista";
            return;
        }
        else {
            for(int i=1; i <= x; i++) {
                if(i == x) {
                    tempX = saltarin;
                    saltarin = inicio;
                }
                else {
                    saltarin = saltarin->sig;
                }
            }

            for(int j=1; j <= y; j++) {
                if(j == y) {
                    tempY = saltarin;
                    saltarin = inicio;
                }
                else {
                    saltarin = saltarin->sig;
                }
            }

            aux = tempX->dato;
            tempX->dato = tempY->dato;
            tempY->dato = aux;
        }
    }

};

int main() {

    ListaEnlazada lista;

    lista.agregarElemento(1);
    lista.agregarElemento(2);
    lista.agregarElemento(3);

    lista.mostrarLista();

    cout<<"\n";

    lista.cambiarPosiciones(1,3);

    lista.mostrarLista();

    return 0;
}
