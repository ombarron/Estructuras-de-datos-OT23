//  Olivia Maricela Barrón Cano
//  Creación: 22/Agosto/2023
//  Última modificación: 22/Agosto/2023
//
// Solución de la actividad 6
# include <iostream>
# include <fstream>

using namespace std;

int busquedaSecuencial(int arreglo[], int tamanio, int valor)
{   
    int indice = -1;

    for (int i=0; i < tamanio; i++)
      if (arreglo[i] == valor)
        indice = i;

    return indice;
}

int busquedaBinaria(int arreglo[], int indInf, int indSup, int valor)
{
    int indice, mitad;

    if (indInf > indSup)
        indice = -1;
    else
    {
      mitad = (indSup - indInf) / 2 + indInf;

      if (valor < arreglo[mitad])
        indice = busquedaBinaria(arreglo, indInf, mitad-1, valor);
      else if (valor == arreglo[mitad])
        indice = mitad;
        else
           indice = busquedaBinaria(arreglo, mitad+1,indSup, valor);
    }    
    return indice;
}

int main()
{
    string nombreArchivo;
    ifstream archivo;
    int tamanio, elemento, indice;

    cout << "Dame el nombre del archivo, incluyendo su extension ";
    cin >> nombreArchivo;

    archivo.open(nombreArchivo);
    archivo >> tamanio;
    cout << "El tamanio es "<<tamanio <<endl;
    
    int arreglo[tamanio];

    for (int i=0; i<tamanio; i++)
     archivo >> arreglo[i];

    archivo.close();

    cout << "Dame el elemento que deseas buscar ";
    cin >> elemento;

   indice = busquedaSecuencial(arreglo, tamanio, elemento);

    if (indice == -1)
     cout << "El elemento "<<elemento<<" no se encuentra en el arreglo"<<endl;
    else
     cout << "El elemento "<<elemento<<" se encuentra en la posicion "<<indice<< " del arreglo"<<endl;
   
    indice = busquedaBinaria(arreglo, 0, tamanio-1, elemento);
    if (indice == -1)
     cout << "El elemento "<<elemento<<" no se encuentra en el arreglo"<<endl;
    else
     cout << "El elemento "<<elemento<<" se encuentra en la posicion "<<indice<< " del arreglo"<<endl;

}
