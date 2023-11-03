# include <iostream>
# include <fstream>
# include "Fila.h"
# include "Palabra.h"

using namespace std;

 void leerArchivo(ListaEncadenada<string> &lista)
 {
    ifstream archivo;
    string nombre, palabra;

    /*cout << "Dame el nombre del archivo con las palabras a ignorar"<<endl;
    cin >> nombre;*/

    //archivo.open(nombre+".txt");
    archivo.open("stopWords.txt");

    while (!archivo.eof())
    {
        getline(archivo,palabra);
        lista.insertarElementoFinal(palabra);
    }
 }

void leerArchivo(ListaEncadenada<Palabra> &lista)
 {
    ifstream archivo;
    string nombre, pal;
    int polaridad;
    Palabra palabra;

    /* cout << "Dame el nombre del archivo del diccionario"<<endl;
     cin >> nombre;

    archivo.open(nombre+".txt");*/
    archivo.open("diccionario.txt");
    while (!archivo.eof())
    {
        archivo >> polaridad >> pal;
        palabra.asignaValores(polaridad, pal);
        lista.insertarElementoFinal(palabra);
    }
 }

void leerArchivo(Fila<string> &fila)
{
    ifstream archivo;
    string nombre, palabra;
  

    /*cout << "Dame el nombre del archivo del texto a analizar"<<endl;
     cin >> nombre;

    archivo.open(nombre+".txt");*/
    archivo.open("texto.txt");
    while (!archivo.eof())
    {
        archivo >> palabra;
        fila.mete(palabra);
    }
}

void leerArchivo(int rangos[])
{
    ifstream archivo;
    string nombre;
    int indice=0;
  

    /*cout << "Dame el nombre del archivo con los rangos"<<endl;
    cin >> nombre;

    archivo.open(nombre+".txt");*/
    archivo.open("rangos.txt");
    while (!archivo.eof())
    {
        archivo >> rangos[indice++];
    
    }
}

int main()
{ 
   ListaEncadenada<string> stopWords;
   ListaEncadenada<Palabra> palabras;
   Fila<string> filaTexto;
   int rangos[3];
   int polaridadTotal = 0;
   string textoActual;
   Palabra palabraActual;
   int posicion;

   leerArchivo(stopWords);
   leerArchivo(palabras);
   leerArchivo(filaTexto);
   leerArchivo(rangos);

   while (!filaTexto.estaVacia())
   {
        textoActual = filaTexto.siguiente();

        if (stopWords.encontrarPosicionElemento(textoActual) == 0)
        {
           palabraActual.asignaValores(0,textoActual);
           posicion = palabras.encontrarPosicionElemento(palabraActual);
           if (posicion != 0)
           {
            palabraActual = palabras.traerDatosPosicion(posicion);
            polaridadTotal = polaridadTotal + palabraActual.traePolaridad();
           }
        }
        filaTexto.saca();
   }
    
    cout << "La polaridad del texto tiene un valor de "<<polaridadTotal<<endl;
    if (polaridadTotal >= rangos[0])
    {  
        cout << "La polaridad del texto es positiva"<<endl;
    }
    else if (polaridadTotal <rangos[0] && polaridadTotal>=rangos[1])
    {
        cout << "La polaridad del texto es neutral"<<endl;
    }
    else if (polaridadTotal<rangos[1] && polaridadTotal>=rangos[2])
    {
        cout << "La polaridad del texto es negativa"<<endl;
    }
    else
    {   
        cout<<"La polaridad del texto está fuera de rango"<<endl;
    }

    return 0;
}
    