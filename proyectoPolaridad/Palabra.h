# include <iostream>
using namespace std;

class Palabra
{
    
    private:
        string texto;
        int polaridad;
        
    public:

        Palabra();
        void asignaValores(int pol, string tex);
        string traeTexto();
        int traePolaridad();
        friend bool operator !=(const Palabra &pal1, const Palabra &pal2);
        friend bool operator ==(const Palabra &pal1, const Palabra &pal2);
        friend std::ostream& operator<<(std::ostream& output, Palabra& palabra);
        
        

    
};

Palabra::Palabra()
{
    texto = "";
    polaridad = 0;
}

void Palabra::asignaValores(int pol, string tex)
{
    texto = tex;
    polaridad = pol;
}

string Palabra::traeTexto()
{
    return texto;
}

int Palabra::traePolaridad()
{
    return polaridad;
}

bool operator !=(const Palabra &pal1, const Palabra &pal2)
{
    return pal1.texto != pal2.texto;
}

bool operator ==(const Palabra &pal1, const Palabra &pal2)
{
    return pal1.texto == pal2.texto;
}

std::ostream& operator<<(std::ostream& output, Palabra& palabra)
{
    output << palabra.polaridad << " --> "<<palabra.texto<<endl;
}
