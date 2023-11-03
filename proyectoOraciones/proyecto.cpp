# include <iostream>
# include <fstream>
# include "Fila.h"
# include "Oracion.h"

using namespace std;

 void leerArchivo(string etiqueta, ListaEncadenada<string> &lista)
 {
    ifstream archivo;
    string nombre, palabra;

    //cout << "Dame el nombre del archivo de "<<etiqueta<<endl;
    //cin >> nombre;
    nombre = etiqueta;

    archivo.open(nombre+".txt");

    while (!archivo.eof())
    {
        getline(archivo,palabra);
        lista.insertarElementoFinal(palabra);
    }
 }

void leerArchivo(string etiqueta, Fila<Oracion> &fila)
 {
    ifstream archivo;
    string nombre, palabra;
    Oracion oracion;

    //cout << "Dame el nombre del archivo de "<<etiqueta<<endl;
    // cin >> nombre;

    nombre = etiqueta;
    archivo.open(nombre+".txt");
    while (!archivo.eof())
    {
        getline(archivo,palabra);
        oracion.asignaTexto(palabra);
        fila.mete(oracion);
    }
 }

int main()
{ 

    ListaEncadenada<string> articulos, sustantivos, adjetivos, verbos, objetos;
    Fila<Oracion> oraciones;
    Oracion auxiliar;

    leerArchivo("articulos", articulos);
    leerArchivo("sustantivos", sustantivos);
    leerArchivo("adjetivos", adjetivos);
    leerArchivo("verbos", verbos);
    leerArchivo("objetos", objetos);
    leerArchivo("oraciones", oraciones);   
    
    cout << "Oraciones validas "<<endl;
    while (!oraciones.estaVacia())
    { 
        auxiliar = oraciones.siguiente();
        if (auxiliar.esValida(articulos, sustantivos, adjetivos, verbos, objetos))
         cout << auxiliar;
        oraciones.saca();
    }

    return 0;
}
    