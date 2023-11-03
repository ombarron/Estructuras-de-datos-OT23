# include <iostream>

using namespace std;



class Oracion
{
    
    private:
        string texto;
        int tamanio;
        string palabras[5];
        
    public:

        Oracion();
        void asignaTexto(string textoEntrada);
        bool esValida(ListaEncadenada<string> &ar,ListaEncadenada<string>&sus,ListaEncadenada<string> &adj,ListaEncadenada<string> &ver,ListaEncadenada<string> &obj );
        void despliega(ostream &out);
        friend ostream& operator<<(ostream& output, Oracion& oracion);
        

    
};


Oracion::Oracion()
{
    texto = "";
    tamanio = 0;
}


void Oracion::asignaTexto(string textoEntrada)
{
    string palabra="";
    int contadorLetras = 0;
    int contadorPalabras = 0;

    texto = textoEntrada;

    for (int i=0; i<textoEntrada.size();i++)
    {
        
        if (textoEntrada[i] != ' ')
        {
            palabra += textoEntrada[i];
            contadorLetras = contadorLetras + 1;
        }
        else
        {
            if (contadorLetras != 0)
            {
                if (contadorPalabras <=5)
                    palabras[contadorPalabras] = palabra;
                palabra = "";
                contadorLetras = 0;
                contadorPalabras = contadorPalabras + 1;
            }
        }
    }
    tamanio = contadorPalabras;
}

bool Oracion::esValida(ListaEncadenada<string> &ar,ListaEncadenada<string>&sus,ListaEncadenada<string> &adj,ListaEncadenada<string> &ver,ListaEncadenada<string> &obj )
{
    bool bandera = true;
    int valor;
    string siguiente;

    for (int i=0; i<5; i++)
    {
        siguiente = palabras[i];
        switch (i)
        {
            case 0: valor = ar.encontrarPosicionElemento(siguiente);
                    break;
            case 1: valor = sus.encontrarPosicionElemento(siguiente);
                    break; 
            case 2: valor = adj.encontrarPosicionElemento(siguiente);
                    break;    
            case 3: valor = ver.encontrarPosicionElemento(siguiente);
                    break;   
            case 4: valor = obj.encontrarPosicionElemento(siguiente);
                    break;
        }
        bandera = bandera && (valor!= 0);
    }
    return bandera;
}
        
void Oracion::despliega(ostream &out)
{
    out << texto << endl;
}


ostream& operator<<(ostream& output, Oracion& oracion)
{
    output << oracion.texto << endl;
    return output;
}
        