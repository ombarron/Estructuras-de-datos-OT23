//  Olivia Maricela Barrón Cano
//  Creación: 15/Agosto/2023
//  Última modificación: 15/Agosto/2023
//
// Solución de la actividad reto de recursividad
# include <iostream>

using namespace std;

void movimientoDiscos(int numeroDiscos, int posteInicial, int posteFinal, int posteTemporal)
{
    if (numeroDiscos == 1)
      cout << posteInicial << " -> "<<posteFinal<<endl;
    else {
        movimientoDiscos(numeroDiscos-1, posteInicial, posteTemporal, posteFinal );
        movimientoDiscos(1, posteInicial, posteFinal, posteTemporal);
        movimientoDiscos(numeroDiscos-1, posteTemporal, posteFinal, posteInicial);
    }
}

int main()
{ 
    int numeroDiscos;

    cout << "¿Cuantos discos hay en el poste 1 ";
    cin >> numeroDiscos;
    cout << "Para mover "<< numeroDiscos << "del poste 1 al 3 realiza los siguientes movimientos "<<endl;
    movimientoDiscos(numeroDiscos, 1, 3, 2);
}