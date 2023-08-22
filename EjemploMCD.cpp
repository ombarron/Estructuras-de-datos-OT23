//  Olivia Maricela Barrón Cano
//  Creación: 15/Agosto/2023
//  Última modificación: 15/Agosto/2023
//
// Solución de la actividad 5 de recursividad
# include <iostream>

using namespace std;

int maximoComunDivisor(int a, int b)
{
    if (b==0)
     return a;
    else
     return maximoComunDivisor(b, a%b);
}

int main()
{ int primerNumero;
  int segundoNumero;
  
  do
  {
    cout << "Dame un numero entero positivo ";
    cin >> primerNumero;
    if (primerNumero <= 0)
      cout << "El numero debe ser mayor o igual a cero"<<endl;
  } while (primerNumero<=0);

 do
  {
    cout << "Dame un numero entero positivo ";
    cin >> segundoNumero;
    if (segundoNumero <= 0)
      cout << "El numero debe ser mayor o igual a cero"<<endl;
  } while (segundoNumero<=0);
  
  cout << "El maximo comun divisor de los numeros "<<primerNumero<<" y "<<segundoNumero<<" es "<<maximoComunDivisor(primerNumero,segundoNumero)<<endl;
}
