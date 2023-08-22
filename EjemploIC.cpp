//  Olivia Maricela Barrón Cano
//  Creación: 15/Agosto/2023
//  Última modificación: 15/Agosto/2023
//
// Solución de la actividad 3 de recursividad
# include <iostream>

using namespace std;

double interesCompuesto(double capitalInicial, double interesAnual, int tiempo)
{ double acumulado = 0;
    if (tiempo==0)
     return capitalInicial;
    else
    {
      acumulado = (1+interesAnual) * interesCompuesto(capitalInicial, interesAnual, tiempo-1);
      cout << "monto acumulado al periodo es "<< acumulado << endl;
      return acumulado;
    }
}
     

int main()
{ double interesFinal, capital, interesAnual;
  int plazo;
  
  cout << "Calculo del interes compuesto"<<endl;
  cout << "Cantidad inicial: ";
  cin >> capital;
  cout << "Ingresa meses de inversion:";
  cin >> plazo;
  cout << "Tasa de interes%:";
  cin >> interesAnual;

  interesFinal = interesCompuesto(capital, interesAnual/100.0,plazo);

  cout << "Monto final es: "<<interesFinal<<endl;
  
}
