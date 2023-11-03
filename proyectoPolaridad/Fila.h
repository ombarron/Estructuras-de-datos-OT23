//  Olivia Maricela Barrón Cano
//  Creación: 26/Septiembre/2023
//  Última modificación: 6/Octubre/2023

# include <iostream>
# include "ListaEncadenada.h"

using namespace std;


// Definición de la clase Pila
template <class T>
class Fila : public ListaEncadenada<T>
{
    public:
        bool mete(T &info);
        void saca();
        T siguiente();

};



template <class T>
void Fila<T>::saca()
{
    this->borrarElementoInicio();
}

template <class T>
bool Fila<T>::mete(T &info)
{
    return this->insertarElementoFinal(info);
}

template <class T>
T Fila<T>::siguiente()
{
    if (!this->estaVacia())
        return this->traerDatosInicio();
    else
        return T ();
}

