//  Olivia Maricela Barrón Cano
//  Creación: 11/Agosto/2023
//  Última modificación: 11/Agosto/2023
//
// Este programa resuelve el problema de cálculo de bacterias de manera recursiva

# include <iostream>
# include <stdlib.h>

using namespace std;

int bacterias(int dias)
{
    int resultado, nacimientos, muertes;

    if (dias == 0)
        resultado = 1;
    else
    {
        resultado = bacterias(dias-1);
        nacimientos = resultado * 3.78;
        muertes = resultado * 2.34;
        resultado = resultado + nacimientos - muertes;
    }

    return resultado;
}

int main()
{
    int dias;

    cout << "¿Cuantos dias han pasado ? ";
    cin >> dias;
    cout <<" Despues de "<<dias<<" dias  hay "<<bacterias(dias)<<" bacteria(s)"<< endl;

}