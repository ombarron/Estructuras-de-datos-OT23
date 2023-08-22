//  Olivia Maricela Barrón Cano
//  Creación: 15/Agosto/2023
//  Última modificación: 15/Agosto/2023
//
// Solución de la actividad 5 de recursividad
# include <iostream>

using namespace std;

double potencia (double base, int exponente)
{
    if (exponente == 1)
        return base;
    else
        return base * potencia(base, exponente -1);
}

int main()
{ 
    double base;
    int exponente;

    cout << "Dame la base "<<endl;
    cin >> base;
    cout << "Dame el exponente"<<endl;
    cin >> exponente;
    cout << base << " elevado a la "<< exponente <<" = "<<potencia(base,exponente);
    
}