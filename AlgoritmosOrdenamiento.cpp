//  Olivia Maricela Barrón Cano
//  Creación: 25/Agosto/2023
//  Última modificación: 25/Agosto/2023
//
// Solución de la tarea 4
# include <iostream>
using namespace std;

int buscaMenor(int arreglo[], int inicio, int tamanio)
{
    int indiceMenor = inicio;
    for (int i = inicio+1; i<tamanio; i++)
       if (arreglo[indiceMenor] > arreglo[i])
         indiceMenor = i;

    return indiceMenor;
}

void ordenaSeleccion(int arreglo[], int tamanio)
{   int indiceMenor, temporal;

    for (int i=0; i<tamanio;i++)
    {
       indiceMenor = buscaMenor(arreglo, i, tamanio);
       temporal = arreglo[i];
       arreglo[i] = arreglo[indiceMenor];
       arreglo[indiceMenor] = temporal;
    }

}

void inserta(int arreglo[], int inicio, int fin, int valor)
{
    int posicion, temporal;

    posicion = inicio;

    while (arreglo[posicion]< valor)
        posicion++;

    for (int i=posicion; i<=fin; i++)
    {
        temporal = arreglo[i];
        arreglo[i] = valor;
        valor = temporal;
    }
}

void ordenaInsercion(int arreglo[], int tamanio)
{
    int tamanioOrdenado = 1;

    do
    {
        inserta(arreglo,0,tamanioOrdenado,arreglo[tamanioOrdenado]);
        tamanioOrdenado++;
        /* code */
    } while (tamanioOrdenado != tamanio);
    

}

void ordenaBurbuja(int arreglo[], int tamanio)
{
    bool intercambio;
    int temporal, indFinal;

    indFinal = tamanio;
    do
     {
        intercambio = false;
        for (int i=0; i<indFinal-1; i++)
          if (arreglo[i] > arreglo[i+1])
            {
                intercambio = true;
                temporal = arreglo[i];
                arreglo[i] = arreglo[i+1];
                arreglo[i+1] = temporal;
            }
        indFinal--;
     } while (intercambio);
}

void mezcla(int arreglo[], int inicio, int medio, int fin)
{
   int cantidadElementos = fin - inicio + 1;
   int arregloAuxiliar[cantidadElementos];
   int finIzquierdo = medio - 1;
   int indiceIzquierdo = inicio;
   int indiceDerecho = medio;
   int indiceAuxiliar = 0;

   while (indiceIzquierdo <= finIzquierdo && indiceDerecho <= fin)
        if (arreglo[indiceIzquierdo] <= arreglo[indiceDerecho])
          arregloAuxiliar[indiceAuxiliar++] = arreglo[indiceIzquierdo++];
        else
         arregloAuxiliar[indiceAuxiliar++] = arreglo[indiceDerecho++];

    while (indiceIzquierdo <= finIzquierdo)
        arregloAuxiliar[indiceAuxiliar++] = arreglo[indiceIzquierdo++];

    while (indiceDerecho <= fin)
        arregloAuxiliar[indiceAuxiliar++] = arreglo[indiceDerecho++];

    for (int i = 0, j = inicio; i<cantidadElementos; i++, j++)
        arreglo[j] = arregloAuxiliar[i];
  
}

void ordenaMezcla(int arreglo[], int inicio, int fin)
{
    int mitad;

    if (inicio < fin)
    {
        mitad = (inicio + fin)/2 ;

        ordenaMezcla(arreglo, inicio, mitad);
        ordenaMezcla(arreglo, mitad+1, fin);
        mezcla(arreglo, inicio, mitad+1, fin);
    }
}

int main()
{
    int arreglo[21], opcion; 
    char sigue = 's';

    while (sigue != 'N')
    {
        cout << "Dame 21 numeros enteros "<<endl;
        for (int i=0; i<21;i++)
          cin >> arreglo[i];

        cout << " Indica el algoritmo de ordenamiento que quieres usar"<<endl;
        cout << " 1 Insercion" << endl;
        cout << " 2 Seleccion" << endl;
        cout << " 3 Burbuja" << endl;
        cout << " 4 Mezcla" << endl;
        cin >> opcion;

        switch (opcion)
        {
            case 1: ordenaInsercion(arreglo, 21);
                    break;
            case 2: ordenaSeleccion(arreglo, 21);
                    break;
            case 3: ordenaBurbuja(arreglo, 21);
                    break;
            case 4: ordenaMezcla(arreglo, 0, 20);
                    break;
            default: cout << "Lo ordenare por el metodo de Burbuja"<<endl;
                     ordenaBurbuja(arreglo, 21);
        }

        cout << "El arreglo ya ordenado es ";

        for (int i=0; i<20;i++)
         cout << arreglo[i] << ",";
        cout << arreglo[20] <<endl;

        cout << "Deseas ordenar otro arreglo (S/N)";
        cin >> sigue;
    }

}
 