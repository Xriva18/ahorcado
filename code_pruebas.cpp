//Juego de ahorcado
//Fernado Guanoluisa
//25/02/2023
#include<iostream>
#include<iostream>
#include <fstream>
#include <vector>
using namespace std;

string p_original;
string p_mostrar;
int vidas;
int pos_actual = 0; //Variable para llevar un registro de la posición actual en la lista de palabras

void mostrar();
void juego();
void ingresar(char x);
void empezar();
string word();
vector<string> palabra_file();

int main ()
{
    juego();
    return 0;
}

void juego()
{
    empezar();
    mostrar();
    while (vidas>0 && p_mostrar != p_original)
    {
        char x;
        cout << "\nIngrese una letra: ";
        cin >> x;
        ingresar(x);
        mostrar();
    }
    if (vidas>0)
    {
        cout<<"Ganaste"<<endl;
    }
    else
        cout << "Perdiste, la palabra es: "<<p_original;

    pos_actual++; //Moverse a la siguiente palabra en la lista
    if (pos_actual == palabra_file().size()) //Si se han utilizado todas las palabras, restablecer la posición actual a cero
    {
        pos_actual = 0;
    }
    juego(); //Volver a jugar con la siguiente palabra
}

void empezar ()
{
    vidas = 3;
    p_original = word();
    //hacer minusculas
    for ( string::size_type i = 0; i < p_original.length(); i++)
    {
        if (p_original[i]>='A' && p_original[i] <= 'Z')
        {
            p_original[i]+=32;
        }
    }
    //poner guiones bajos
    for ( string::size_type i = 0; i < p_original.length(); i++)
    {
       if (p_original[i]>='a' && p_original[i] <= 'z')
        {
            p_mostrar+="_";
        }
        else
        {
            p_mostrar+=p_original[i];
        }
    }

}

//Envia la palabra
string word()
{
    int n = pos_actual; //Obtener la posición actual en la lista
    vector<string> word;
    word = palabra_file();
    return word[n];
}

//Saca la palabra del archivo y lo enviada
vector<string> palabra_file()
{
    vector<string> word;

    ifstream file ("words.dat");
    string palabra;
    while (getline(file,palabra))
    {
        word.push_back(palabra);
    }
    file.close();

    return word;
}

void mostrar()
{
    system("ClS");
    cout << "AHORCADO \n"<<endl;
    cout<<"Vidas: "<<vidas<<endl;
    cout<<p_mostrar<<endl;
}

void ingresar(char x)
{
    bool sinvida = true;
    for ( string::size_type i = 0; i < p_original.length(); i++) //cambair string::size_type por int en code
    {
        if (x == p_original[i])
        {
            sinvida=false;
            p_mostrar[i]=x;
        }
    }
    if (sinvida)
        {
            vidas--;
        }
}