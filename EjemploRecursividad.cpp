//  Olivia Maricela Barrón Cano
//  Creación: 11/Agosto/2023
//  Última modificación: 11/Agosto/2023
//
// Este programa es para ejemplificar el uso de funciones recursivas 
// también se incluyen las versiones iterativas

# include <iostream>
# include <stdlib.h>

using namespace std;

// Implementaciones iterativas de factorial y fibonnaci

int factorial (int numero)
{ int resultado = 1;

    while (numero >1)
    {
        resultado = resultado * numero;
        numero--;
    }
    return resultado;

}

int fibonacci (int numero)
{ int resultado = 1, anterior = 1, nuevo;

  while (numero >1)
    {   
        nuevo = resultado + anterior;
        anterior = resultado;
        resultado = nuevo;
        numero--;
    }
    return resultado;
}

// Implementaciones recursivas de factorial y fibonacci
int factorialRecursivo(int numero)
{ int resultado;

  if (numero <2)
    resultado = 1;
  else
    resultado = numero * factorialRecursivo(numero-1);

  return resultado;
}

int fibonacciRecursivo(int numero)
{ int resultado;

  if (numero < 2)
    resultado = 1;
  else  
    resultado = fibonacciRecursivo(numero-1) + fibonacciRecursivo(numero-2);

  return resultado;
}

int main()
{
    string opcion_str;
    int opcion, resultado, numero;
 
    do
    {
        system("cls");
        cout << endl;
        cout << "1) Factorial iterativo"<< endl;
        cout << "2) Factorial recursivo"<< endl;
        cout << "3) Fibonacci iterativo"<< endl;
        cout << "4) Fibonacci recursivo"<< endl;
        cout << "5) Salir "<<endl;
        cout <<"    Opcion >>";
        cin >> opcion_str;

        opcion = atoi(opcion_str.c_str());

        switch (opcion)
        {
        case 1:
            cout << "¿De que numero quieres calcular el factorial? ";
            cin >> numero;
            resultado = factorial(numero);
            cout << "El factorial de "<<numero<<" es "<<resultado<<endl;
            system("pause");
            break;
        case 2:
            cout << "¿De que numero quieres calcular el factorial? ";
            cin >> numero;
            resultado = factorialRecursivo(numero);
            cout << "El factorial de "<<numero<<" es "<<resultado<<endl;
            system("pause");
            break;
        case 3:
            cout << "¿Que numero de elemento de la serie de Fibonacci quieres calcular? ";
            cin >> numero;
            resultado = fibonacci(numero);
            cout << "El elemento # "<<numero<<" de la serie de Fibonacci es "<<resultado<<endl;
            system("pause");
            break;
        case 4:
            cout << "¿Que numero de elemento de la serie de Fibonacci quieres calcular? ";
            cin >> numero;
            resultado = fibonacciRecursivo(numero);
            cout << "El elemento # "<<numero<<" de la serie de Fibonacci es "<<resultado<<endl;
            system("pause");
            break;    
        case 5:
            cout << "Vamos a salir"<<endl;
            system("pause");
            break;
        default:
            cout << "Por favor da una opcion valida (1, 2, 3, 4 o 5)"<<endl;
            system("pause");
            break;
        }
    } while (opcion != 5);
    
}
