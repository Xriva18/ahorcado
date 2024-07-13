// Juego del ahorcado
// Fernado Guanoluisa
// inicio 25/02/2023 23:09
// fin 27/02/2023 21:08

#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include "posicion_color.h"
using namespace std;

string p_original, p_mostrar, lifes;
int vidas, rep;

void pantalla_de_inicio();
void mostrar();
void juego();
void ingresar(char x);
void empezar();
void datos_empresa();
void ejecucion();
int menu();
void salir();
void dibujo_ahorcado();
void margen();
void margen_interno();
void gana();
void pierde();
void corazones();
void like();
void sin_vida();
void tres_vida();
void dos_vida();
void una_vida();
void resultado(int victorias, int derrotas, int n);
void instrucciones();
void cara_feliz();
string word();
vector<string> palabra_file();

int main()
{
    int op;
    pantalla_de_inicio(); // muestra la pantalla de incio
    rojo_claro();
    margen();
    blanco();
    dibujo_ahorcado();
    datos_empresa();
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            ejecucion();
            break;

        case 2:
            instrucciones();
            break;

        case 3:
            salir();
            break;

        default:
            rojo_claro();
            gotoxy(55, 18);
            cout << "Ingrese una opcion correcta";
            blanco();
            gotoxy(43, 22);
            cout << ". . . ";
            system("Pause");
        }
    } while (op != 3);
    return 0;
}

int menu()
{
    pantalla_de_inicio();
    azul_oscuro();
    margen();
    blanco();
    dibujo_ahorcado();
    int op, x = 55, y = 13;
    gotoxy(x, y++);
    cout << "\tMENU DE OPCIONES";
    gotoxy(x, y++);
    cout << "\t----------------";
    gotoxy(x, y++);
    cout << "1. Jugar ";
    gotoxy(x, y++);
    cout << "2. Instrucciones ";
    gotoxy(x, y++);
    cout << "3. Salir";
    gotoxy(x, y + 1);
    cout << "Elija una opcion: ";
    cin >> op;
    return op;
}

// ejecuta el juego
void ejecucion()
{
    int n = palabra_file().size();
    int victorias = 0;
    int derrotas = 0;
    for (rep = 0; rep < n; rep++)
    {
        juego();
        if (vidas > 0)
        {
            gana();
            victorias++;
        }
        else
        {
            pierde();
            derrotas++;
        }
        gotoxy(27, 22);
        cout << ". . . ";
        system("Pause");
    }
    resultado(victorias, derrotas, n);
}

// muestras los resultados depues de acabr con la lisat de palabras
void resultado(int victorias, int derrotas, int n)
{
    system("ClS");
    purpura_claro();
    margen();
    blanco();
    gotoxy(60, 3);
    cout << "Resultados:";
    verde();
    gotoxy(46, 10);
    cout << "Numero de partidas";
    blanco();
    cout << "....................";
    verde();
    cout << n;
    gotoxy(46, 11);
    cout << "Victorias";
    blanco();
    cout << ".............................";
    verde();
    cout << victorias;
    gotoxy(46, 12);
    cout << "Derrotas";
    blanco();
    cout << "..............................";
    verde();
    cout << derrotas;
    blanco();
    gotoxy(43, 22);
    cout << ". . . ";
    system("Pause");
}

// Envia la palabra
string word()
{
    vector<string> word;
    word = palabra_file();
    return word[rep];
}

// Saca la palabra del archivo y lo enviada
vector<string> palabra_file()
{
    vector<string> word;

    ifstream file("palabras.dat");
    string palabra;
    while (getline(file, palabra))
        word.push_back(palabra);
    file.close();

    return word;
}

// pide el ingreso de una letra
void juego()
{
    empezar();
    mostrar();
    amarillo_oscuro();
    margen();
    blanco();
    margen_interno();
    while (vidas > 0 && p_mostrar != p_original)
    {
        char x;
        corazones();
        gotoxy(21, 22);
        cout << "Ingrese una letra: ";
        cin >> x;
        ingresar(x);
        mostrar();
    }
}

// las palabras lo combierte en minusculas y asigna un guion bajo a letra y numeros
void empezar()
{
    p_mostrar = ""; // se reinicia la variable
    vidas = 3;
    p_original = word();

    // hacer minusculas
    for (string::size_type i = 0; i < p_original.length(); i++)
    {
        if (p_original[i] >= 'A' && p_original[i] <= 'Z')
        {
            p_original[i] += 32;
        }
    }

    // poner guiones bajos
    for (string::size_type i = 0; i < p_original.length(); i++)
    {
        if ((p_original[i] >= 'a' && p_original[i] <= 'z') || (p_original[i] >= '0' && p_original[i] <= '9'))
        {
            p_mostrar += "_";
        }
        else
        {
            p_mostrar += p_original[i];
        }
    }
}

// comprueba que las letras ingresadas sean las de la palabra
void ingresar(char x)
{
    bool sinvida = true;
    for (string::size_type i = 0; i < p_original.length(); i++)
    {
        if (x == p_original[i])
        {
            sinvida = false;
            p_mostrar[i] = x;
        }
    }
    if (sinvida)
    {
        vidas--;
    }
}

// muestra la palabra con guiones y el numero de poalabra que va
void mostrar()
{
    system("ClS");
    amarillo_oscuro();
    margen();
    blanco();
    margen_interno();
    gotoxy(60, 3);
    cout << "Game #" << rep + 1 << endl;
    gotoxy(48, 12);
    cout << p_mostrar << endl;
}

// name del jeugo
void pantalla_de_inicio()
{
    int x = 25, y = 3;
    system("CLS");
    verde();
    gotoxy(x, y++);
    cout << "  /$$$$$$  /$$                                                     /$$          ";
    gotoxy(x, y++);
    cout << " /$$__  $$| $$                                                    | $$         ";
    gotoxy(x, y++);
    cout << "| $$  \\ $$| $$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$$  /$$$$$$   /$$$$$$$  /$$$$$$  ";
    gotoxy(x, y++);
    cout << "| $$$$$$$$| $$__  $$ /$$__  $$ /$$__  $$ /$$_____/ |____  $$ /$$__  $$ /$$__  $$";
    gotoxy(x, y++);
    cout << "| $$__  $$| $$  \\ $$| $$  \\ $$| $$  \\__/| $$        /$$$$$$$| $$  | $$| $$  \\ $$";
    gotoxy(x, y++);
    cout << "| $$  | $$| $$  | $$| $$  | $$| $$      | $$       /$$__  $$| $$  | $$| $$  | $$";
    gotoxy(x, y++);
    cout << "| $$  | $$| $$  | $$|  $$$$$$/| $$      |  $$$$$$$|  $$$$$$$|  $$$$$$$|  $$$$$$/";
    gotoxy(x, y++);
    cout << "|__/  |__/|__/  |__/ \\______/ |__/       \\_______/ \\_______/ \\_______/ \\______/ ";
    blanco();
    // y=10
}

// dibujo para patalal de inicio
void dibujo_ahorcado()
{
    int x = 37, y = 12;
    agua();
    gotoxy(x, y++);
    cout << "  ========";
    gotoxy(x, y++);
    cout << "  |      |";
    gotoxy(x, y++);
    cout << "  |      O";
    gotoxy(x, y++);
    cout << "  |     /|\\";
    gotoxy(x, y++);
    cout << "  |      |";
    gotoxy(x, y++);
    cout << "  |     / \\"; // x=15
    gotoxy(x, y++);
    cout << "  |";
    gotoxy(x, y++);
    cout << "  |";
    gotoxy(x, y++);
    cout << "[====]";
    blanco();
}

// datos pantalla de bienvenida
void datos_empresa() // aprece en pantalla 1
{
    int x = 55, y = 14;
    gotoxy(x, y++);
    cout << "BY FEERNANDO GUANOLUISA";
    gotoxy(x, y++);
    cout << "FUNDAMENTOS DE PROGRAMACION";
    gotoxy(x, y++);
    cout << "PRIMER SEMESTRE";
    gotoxy(x, y++);
    cout << "ESPE";
    gotoxy(x, y++);
    cout << "CREADO 26/02/23";
    gotoxy(43, 22);
    cout << ". . . ";
    system("Pause");
}

// dibuja un margen principal
void margen()
{
    // margen horizontal
    for (int i = 20; i < 110; i++)
    {
        gotoxy(i, 1);
        cout << char(205);
        gotoxy(i, 24);
        cout << char(205);
    }
    // margen vertical
    for (int i = 2; i < 24; i++)
    {
        gotoxy(19, i);
        cout << char(186);
        gotoxy(110, i);
        cout << char(186);
    }
    // esquinas
    gotoxy(19, 1);
    cout << char(201); // esquina superior izquierda
    gotoxy(19, 24);
    cout << char(200); // esquina inferior izquierda
    gotoxy(110, 24);
    cout << char(188); // esquina inferior derecha
    gotoxy(110, 1);
    cout << char(187); // esquina superior derecha
}

// dibuja el marge interrior para la opcion 1
void margen_interno()
{
    blanco_grisaseo();
    // margen horizontal
    for (int i = 20; i < 110; i++)
    {
        gotoxy(i, 5);
        cout << char(196);
        gotoxy(i, 20);
        cout << char(196);
    }
    // margen vertical
    for (int i = 6; i < 20; i++)
    {
        gotoxy(80, i);
        cout << char(179);
    }
    // uniones
    gotoxy(80, 5);
    cout << char(194);
    gotoxy(80, 20);
    cout << char(197);
    // margen vertical 2
    for (int i = 21; i < 24; i++)
    {
        gotoxy(80, i);
        cout << char(179); // │
    }
    blanco();
}

// se ejecuta cuando adivina la palabra correcta
void gana()
{
    azul_oscuro();
    margen();
    blanco();
    corazones();
    gotoxy(43, 12);
    cout << "Ganastes !!!!      ";
    like();
}

// se ejecuta cuando no adivina la palabra
void pierde()
{
    rojo_oscuro();
    margen();
    blanco();
    gotoxy(37, 12);
    cout << "Perdistes, la palabra era: ";
    gotoxy(45, 14);
    cout << p_original;
    corazones();
}

// vida clasica
void corazones()
{
    gotoxy(82, 22);
    if (vidas == 1)
    {
        cout << "Vidas: " << vidas << " ";
        rojo_oscuro();
        cout << char(3);
        blanco();
        una_vida();
    }
    if (vidas == 2)
    {
        cout << "Vidas: " << vidas << " ";
        rojo_oscuro();
        cout << char(3) << char(3);
        blanco();
        dos_vida();
    }
    if (vidas == 3)
    {
        cout << "Vidas: " << vidas << " ";
        rojo_oscuro();
        cout << char(3) << char(3) << char(3);
        blanco();
        tres_vida();
    }
    if (vidas == 0)
    {
        cout << "Has muerto";
        gotoxy(104, 22);
        cout << "F";
        sin_vida();
    }
}

// dibuja un like
void like()
{
    int x = 88, y = 8;
    gotoxy(x, y++);
    cout << "               ";
    gotoxy(x, y++);
    cout << "      ||||     ";
    gotoxy(x, y++);
    cout << "      ||||      ";
    gotoxy(x, y++);
    cout << "      |||||||||";
    gotoxy(x, y++);
    azul_claro();
    cout << "||||| ";
    blanco();
    cout << "|||||||||";
    gotoxy(x, y++);
    azul_claro();
    cout << "||  | ";
    blanco();
    cout << "|||||||||";
    gotoxy(x, y++);
    azul_claro();
    cout << "||||| ";
    blanco();
    cout << "|||||||||";
    gotoxy(x, y++);
    azul_claro();
    cout << "|||||          ";
    blanco();
    gotoxy(x, y++);
    cout << "               ";
}

// dibujo del ahorcado
void sin_vida()
{
    int x = 91, y = 8;
    rojo_claro();
    gotoxy(x, y++);
    cout << "  ========";
    gotoxy(x, y++);
    cout << "  |      |";
    gotoxy(x, y++);
    cout << "  |      O";
    gotoxy(x, y++);
    cout << "  |     /|\\";
    gotoxy(x, y++);
    cout << "  |      |";
    gotoxy(x, y++);
    cout << "  |     / \\"; // x=15
    gotoxy(x, y++);
    cout << "  |";
    gotoxy(x, y++);
    cout << "  |";
    gotoxy(x, y++);
    cout << "[====]";
    blanco();
}

void una_vida()
{
    int x = 91, y = 8;
    agua();
    gotoxy(x, y++);
    cout << "  ========";
    gotoxy(x, y++);
    cout << "  |      |";
    gotoxy(x, y++);
    cout << "  |      O";
    gotoxy(x, y++);
    cout << "  |     /|\\";
    gotoxy(x, y++);
    cout << "  |      |";
    gotoxy(x, y++);
    cout << "  |"; // x=15
    gotoxy(x, y++);
    cout << "  |";
    gotoxy(x, y++);
    cout << "  |";
    gotoxy(x, y++);
    cout << "[====]";
    blanco();
}

void dos_vida()
{
    int x = 91, y = 8;
    agua();
    gotoxy(x, y++);
    cout << "  ========";
    gotoxy(x, y++);
    cout << "  |      |";
    gotoxy(x, y++);
    cout << "  |      O";
    gotoxy(x, y++);
    cout << "  |     /|\\";
    gotoxy(x, y++);
    cout << "  |";
    gotoxy(x, y++);
    cout << "  |"; // x=15
    gotoxy(x, y++);
    cout << "  |";
    gotoxy(x, y++);
    cout << "  |";
    gotoxy(x, y++);
    cout << "[====]";
    blanco();
}

void tres_vida()
{
    int x = 91, y = 8;
    agua();
    gotoxy(x, y++);
    cout << "  ========";
    gotoxy(x, y++);
    cout << "  |      |";
    gotoxy(x, y++);
    cout << "  |";
    gotoxy(x, y++);
    cout << "  |";
    gotoxy(x, y++);
    cout << "  |";
    gotoxy(x, y++);
    cout << "  |"; // x=15
    gotoxy(x, y++);
    cout << "  |";
    gotoxy(x, y++);
    cout << "  |";
    gotoxy(x, y++);
    cout << "[====]";
    blanco();
}

// para la opcion 2 de intrucciones
void instrucciones()
{
    system("CLS");
    int x = 24, y = 6;
    purpura_oscuro();
    margen();
    blanco();
    gotoxy(60, 3);
    cout << "Instruciones" << endl;

    rojo_claro();
    gotoxy(x, y++);
    cout << "> ";
    blanco();
    cout << "Para jugar elija la opcion 1" << endl;
    rojo_claro();
    gotoxy(x, y++);
    cout << "> ";
    blanco();
    cout << "Debe ingresar solo una letra " << endl;
    rojo_claro();
    gotoxy(x, y++);
    cout << "> ";
    blanco();
    cout << "Cuenta con 3 vidas" << endl;
    rojo_claro();
    gotoxy(x, y++);
    cout << "> ";
    blanco();
    cout << "Si ingresa una letra que no pertenece a la palabra se le resta una vida" << endl;
    rojo_claro();
    gotoxy(x, y++);
    cout << "> ";
    blanco();
    cout << "AL que darse sin vida el perosnaje es ahorcado" << endl;
    // y=11
    cara_feliz();
    blanco();
    gotoxy(43, 22);
    cout << ". . . ";
    system("Pause");
}

// dibuja un emoji
void cara_feliz()
{
    int x = 50, y = 12;
    amarillo_oscuro();
    gotoxy(x, y++);
    cout << " /||||||||||||||||||||||||||||";
    gotoxy(x, y++);
    cout << "| ||||||||   ||||||   ||||||||";
    gotoxy(x, y++);
    cout << "| ||||||||";
    blanco();
    cout << " |";
    amarillo_oscuro();
    cout << " ||||||";
    blanco();
    cout << " |";
    amarillo_oscuro();
    cout << " ||||||||";
    gotoxy(x, y++);
    cout << "| ||||||||   ||||||   ||||||||";
    gotoxy(x, y++);
    cout << "| ||||||||||||||||||||||||||||";
    gotoxy(x, y++);
    cout << "| ||||||   ||||||||||   ||||||";
    gotoxy(x, y++);
    cout << "| ||||||||            ||||||||";
    gotoxy(x, y++);
    cout << "| ||||||||||||||||||||||||||||";
    gotoxy(x, y++);
    cout << "|/___________________________/";
    blanco();
}

// pantalla de salida
void salir()
{
    system("CLS");
    agua();
    margen();
    blanco();
    int x = 40, y = 5;
    verde();
    gotoxy(x, y++);
    cout << "       _____                _                       ";
    gotoxy(x, y++);
    cout << "      / ____|              (_)                     ";
    gotoxy(x, y++);
    cout << "     | |  __ _ __ __ _  ___ _  __ _ ___           ";
    gotoxy(x, y++);
    cout << "     | | |_ | '__/ _` |/ __| |/ _` / __|           ";
    gotoxy(x, y++);
    cout << "     | |__| | | | (_| | (__| | (_| \\__ \\           ";
    gotoxy(x, y++);
    cout << "      \\_____|_|  \\__,_|\\___|_|\\__,_|___/          ";
    gotoxy(x, y++);
    cout << "                       _                          _ ";
    gotoxy(x, y++);
    cout << "                      (_)                        | |";
    gotoxy(x, y++);
    cout << "  _ __   ___  _ __     _ _   _  __ _  __ _ _ __  | |";
    gotoxy(x, y++);
    cout << " | '_ \\ / _ \\| '__|   | | | | |/ _` |/ _` | '__| | |";
    gotoxy(x, y++);
    cout << " | |_) | (_) | |      | | |_| | (_| | (_| | |    |_|";
    gotoxy(x, y++);
    cout << " | .__/ \\___/|_|      | |\\__,_|\\__, |\\__,_|_|    (_)";
    gotoxy(x, y++);
    cout << " | |                 _/ |       __/ |               ";
    gotoxy(x, y++);
    cout << " |_|                |__/       |___/               ";
    blanco();
    gotoxy(43, 27);
    cout << "  ";
}