# include <iostream>  // Librería para utilizar cin y cout
# include <stdlib.h>  // Libreria para poder usar comandos del sistema y funciones de conversion de datos


using namespace std; // Para no tener que usar el prefijo std 

// Este programa es un ejemplo de uso de arreglos 
// Permite capturar calificaciones, sacar su promedio, y encontrar la calificación más alta
// No declara clases nuevas

const int MAXIMO_ALUMNOS = 5;
int calificaciones[MAXIMO_ALUMNOS];

void pideCalificaciones()
{   
   for (int i=0; i<MAXIMO_ALUMNOS; i++)
   { 
    cout << "Ingrese la calificacion del alumno "<<i+1<<endl;
    cin >> calificaciones[i];
   }
}

 
double calculaPromedio()
{   
   double promedio = 0.0;

   for (int i= 0; i<MAXIMO_ALUMNOS; i++)
   promedio += calificaciones[i];
 
   
   promedio = promedio / MAXIMO_ALUMNOS;
   return promedio;
}

int encontrarMejor(int &mejor)
{
    int indice = 0;
    mejor = calificaciones[0];

    for (int i=1; i<MAXIMO_ALUMNOS; i++)
        if (calificaciones[i] > mejor)
        { 
            mejor = calificaciones[i];
            indice = i;
        }
    
    return indice;
}
    
// Esta rutina despliega el menu principal
void despliegaMenu()
{
    // Declaramos constantes para manejo de valores auxiliares
    const string linea_blanco_100 = "                                                                                                    ";
    const string linea_blanco_65 = "                                                                 ";   

    // Primero limpiamos la pantalla
    system("cls");
    // Hacemos primera linea del marco
    cout << "          "<<char(201);
    for (int i=1; i<=100;i++) 
    {
        cout << char(205); 
    }
    cout << char(187)<<endl;
    // Y ahora hacemos 3 lineas hacia abajo
    for (int i=1; i<=3;i++)
    {
            cout << "          " << char(186) << linea_blanco_100 << char(186) << endl;
     }
    // Ponemos el letrero principal
    cout << "          " << char(186) << "                                         MENU PRINCIPAL                                             "<< char(186) << endl;
    // Y ahora hacemos 3 lineas hacia abajo
    for (int i=1; i<=3;i++)
    {
            cout << "          " << char(186) << linea_blanco_100 << char(186) << endl;
    }
    // Ponemos las opciones
    cout << "          " << char(186) << "      01 Pedir calificaciones      " << linea_blanco_65 << char(186) << endl;
    cout << "          " << char(186) << "      02 Calcular promedio         " << linea_blanco_65 << char(186) << endl;
    cout << "          " << char(186) << "      03 Encontrar mejor           " << linea_blanco_65 << char(186) << endl;
    cout << "          " << char(186) << "      04 Salir del programa        " << linea_blanco_65 << char(186) << endl;
    // Y ahora hacemos 5 lineas hacia abajo
    for (int i=1; i<=5;i++)
    {
        cout << "          " << char(186) << linea_blanco_100 << char(186) << endl;
    }
    //Ponemos la linea de abajo
    cout << "          "<<char(200);
    for (int i=1; i<=100;i++) 
    {
        cout << char(205); 
    }
    cout << char(188)<<endl;
    cout << "                                  Opcion ";

}


int main()
{
    // Declaramos variables de entrada
    string opcion_str;
    int opcion, mejor,indice;

    // Todo el código se va a repetir hasta que el usuario indique que quiere terminar
    do
    {
  
        // Llamamos a la función que dibuja el menu
        despliegaMenu(); 
        //Pedimos la opción al usuario, la capturamos como string para no tener problemas si el usurio se equivoca
        cin >> opcion_str;

        // Cambiamos de string a entero
        opcion = atoi(opcion_str.c_str());

        // Y utilizamos un switch para ejecutar las diferentes opciones
        switch (opcion)
        {
        case 1:
            cout << "Pedir calificaciones"<<endl;
            pideCalificaciones();
            system("pause");
            break;
        case 2:
            cout << "Calcular promedio"<<endl;
            cout << "El promedio de las calificaciones es "<<calculaPromedio()<<endl;
            system("pause");
            break;
        case 3:
            cout << "Encontrar mejor"<<endl;
            indice = encontrarMejor(mejor);
            cout << "El alumno # "<<indice+1<<"obtuvo la mejor calificacion que es "<<mejor<<endl;
            system("pause");
            break;
        case 4:
            cout << "Vamos a salir"<<endl;
            system("pause");
            break;
        default:
            cout << "Por favor da una opcion valida (1, 2, 3 o 4)"<<endl;
            system("pause");
            break;
        }
    } while (opcion != 4);
    
    return 0;
}