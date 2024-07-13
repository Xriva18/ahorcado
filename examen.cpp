
#include<iostream>
#include<fstream>
#include <windows.h>
#include <cstdlib>
#include <string>
#define color SetConsoleTextAttribute
using namespace std;
HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
string leer_palabra(string dificil);
void screenOMGitsHard();
void el_ahorcado();
void no_ahorcado();
void casi_ahorcado();
void drawHollowRectangle(int n, int m);
void gotoxy(int x,int y)
{
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}
int menu();
int main()
{

    setlocale(LC_ALL, "");
    int op;
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            screenOMGitsHard();
        break;
        case 2:
            gotoxy(30,23);cout << "GRACIAS POR JUGAR :3 " << endl;
            gotoxy(30,24);system("PAUSE");
            system("CLS");
        break;
        default:
            gotoxy(30,23);cout << "OPCION INCORRECTA, INTENTELO DE NUEVO " << endl;
            gotoxy(30,24);system("PAUSE");
        break;
        }
    } while (op != 2);

    return 0;
}
void drawHollowRectangle(int n, int m) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(i==1 || i==n || j==1 || j==m)
                {
                    //color(hConsole, 6);
                cout << "* ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}


int menu(){
    system("CLS");
    int op;
    drawHollowRectangle(35,59);
    color(hConsole, 9);
    gotoxy(30,4);cout << " @@@@@ @   @ @@@@@ @@@@  @@@@@ @@@@@ @@@@  @@@@@ " << endl;
    gotoxy(30,5);cout << " @   @ @   @ @   @ @   @ @     @   @ @   @ @   @ "<< endl;
    gotoxy(30,6);cout << " @@@@@ @@@@@ @   @ @@@@  @     @@@@@ @   @ @   @ " << endl;
    gotoxy(30,7);cout << " @   @ @   @ @   @ @  @  @     @   @ @   @ @   @ " << endl;
    gotoxy(30,8);cout << " @   @ @   @ @   @ @   @ @     @   @ @   @ @   @ " << endl;
    gotoxy(30,9);cout << " @   @ @   @ @@@@@ @   @ @@@@@ @   @ @@@@  @@@@@  " << endl;
    color(hConsole, 2);
    gotoxy(45,20);cout << "PRESIONE UNA TECLA";
         color(hConsole, 5);
    gotoxy(47,21);cout<< " 1. PARA CONTINUAR." << endl;
    gotoxy(48,22);cout << "2. SALIR" << endl;
    gotoxy(72,20);cin >> op;
    return op;
}

// Funcion para imprimir el estado actual del juego

void imprimir_estado(int intentos, const string& palabra_secreta,const char* letras_adivinadas)
{
    gotoxy(3,32);cout << "VIDAS: " << intentos << endl;
    gotoxy(40,8);cout << "Palabra ha adivinar: ";
    for(int i = 0; i < palabra_secreta.length();i++){
        if(letras_adivinadas[i] != '_'){
            cout << letras_adivinadas[i] << " ";
        }else{
            cout << "_ ";
        }
    }
    cout << endl << endl;
}
// Funcion para adivinar una letra

bool adivinar_letra(char letra, const string& palabra_secreta, char* letras_adivinadas){
    bool acierto = false;
    for(int i = 0; i < palabra_secreta.length(); i++){
        if(palabra_secreta[i] == letra){
            letras_adivinadas[i] = letra;
            acierto = true;
        }
    }
    return acierto;
}

// funcion para comprobar si se ha adivinado la palabra secreta

bool adivinando_palabra(const string& palabra_secreta, const char* letras_adivinadas){
    for(int i = 0; i <= palabra_secreta.length(); i++){
        if(letras_adivinadas[i] == '_'){
            return false;
        }
    }
    return true;
}
string leer_palabra(string dificil) {
    string palabra;
    ifstream archivo(dificil);
    if (archivo.is_open()) {
        // Obtener la cantidad total de l�neas del archivo
        int num_lineas = 0;
        string linea;
        while (getline(archivo, linea)) {
            num_lineas++;
        }
        archivo.clear();
        archivo.seekg(0, ios::beg);

        // Generar un n�mero aleatorio entre 1 y el n�mero total de l�neas
        int num_linea = rand() % num_lineas + 1;

        // Leer la palabra de la l�nea aleatoria del archivo
        for (int i = 0; i < num_linea; i++) {
            getline(archivo, palabra);
        }
        archivo.close();
    }
    return palabra;
}

void screenOMGitsHard(){
    system("CLS");
    drawHollowRectangle(35,59);
    const int MAX_INTENTOS = 4;
    string palabrasRan = "palabras.dat";
    string palabra_secreta = leer_palabra(palabrasRan);
    char letras_adivinadas[palabra_secreta.length() + 1];
    for(int i = 0; i < palabra_secreta.length(); i++){
        letras_adivinadas[i] = '_';
    }
    letras_adivinadas[palabra_secreta.length()]= '\0';
    int intentos = MAX_INTENTOS;

        while(intentos > 0 && !adivinando_palabra(palabra_secreta, letras_adivinadas)){
            if(intentos ==4){
                no_ahorcado();
            }else if(intentos == 2){
                casi_ahorcado();
            }else if(intentos == 0){
                el_ahorcado();
            }
            imprimir_estado(intentos, palabra_secreta, letras_adivinadas);
            gotoxy(45,20);cout << "Adivina la letra:";
            char letra;
            cin >> letra;
            if(adivinar_letra(letra, palabra_secreta, letras_adivinadas)){
                gotoxy(30,26);cout << "Adivinaste una letra!" << endl;
            }else{
                gotoxy(30,26);cout << "La letra " << letra << " no esta en la palabra " <<endl;
                intentos --;
            }
        }
        if(adivinando_palabra(palabra_secreta, letras_adivinadas)){
            gotoxy(30,26);cout << "Felicidades!! Adivinaste la palabra: " <<palabra_secreta << endl;
            gotoxy(31,28);system("pause");
            screenOMGitsHard();
        }else{
            system("cls");
            drawHollowRectangle(35,59);
            el_ahorcado();
            gotoxy(15,12);cout << "PERDISTE :(" << endl;
            gotoxy(20,15); cout << " La palabra era: " << palabra_secreta << endl;
        }
    gotoxy(32,20);system("pause");
}

void el_ahorcado()
{

    gotoxy(10,1);cout <<  "    ##############################################################################################" << endl;
    gotoxy(10,2);cout <<  "         ######################################################################################" << endl;
    gotoxy(80,3);cout <<  "           ()" << endl;
    gotoxy(80,4);cout <<  "           ()" << endl;
    gotoxy(80,5);cout <<  "           ()" << endl;
    gotoxy(80,6);cout <<  "           ()" << endl;
    gotoxy(80,7);cout <<  "           ()" << endl;
    gotoxy(80,8);cout <<  "   @@@@@@  ()" << endl;
    gotoxy(80,9);cout <<  "  @ x  x @ ()"<< endl;
    gotoxy(80,10);cout << "  @  --- @ ()" << endl;
    gotoxy(80,11);cout << "   @@@@@@ ()" << endl;
    gotoxy(80,12);cout << "    (@@)()" << endl;
    gotoxy(80,13);cout << "    @@@@" << endl;
    gotoxy(80,14);cout << "   @ @@ @" << endl;
    gotoxy(80,15);cout << "   @ @@ @" << endl;
    gotoxy(80,16);cout << "   @ @@ @" << endl;
    gotoxy(80,17);cout << "     @@" << endl;
    gotoxy(80,18);cout << "    @  @" << endl;
    gotoxy(80,19);cout << "   @    @" << endl;
    gotoxy(80,20);cout << "   @    @" << endl;
    gotoxy(80,21);cout << "   @    @" << endl;
    gotoxy(80,22);cout << "   @    @" << endl;
    gotoxy(80,23);cout << "   @    @" << endl;

}

void casi_ahorcado(){
    gotoxy(10,1);cout <<  "    ##############################################################################################" << endl;
    gotoxy(10,2);cout <<  "         ######################################################################################" << endl;
    gotoxy(80,3);cout <<  "           ()" << endl;
    gotoxy(80,4);cout <<  "           ()" << endl;
    gotoxy(80,5);cout <<  "           ()" << endl;
    gotoxy(80,6);cout <<  "           ()" << endl;
    gotoxy(80,7);cout <<  "           ()" << endl;
    gotoxy(80,8);cout <<  "           ()" << endl;
    gotoxy(80,9);cout <<  "           ()"<< endl;
    gotoxy(80,10);cout << "            ()" << endl;
    gotoxy(80,11);cout << "             ()" << endl;
    gotoxy(80,12);cout << "              ()" << endl;
    gotoxy(80,13);cout << "             ()" << endl;
    gotoxy(80,14);cout << "           ()()" << endl;
    gotoxy(80,15);cout << "          ()                                  " << endl;
    gotoxy(80,16);cout << "   @@@@   ()" << endl;
    gotoxy(80,17);cout << "  @ O O@  ()" << endl;
    gotoxy(80,18);cout << "   @@@@  () " << endl;
    gotoxy(80,19);cout << "   (@)()()" << endl;
    gotoxy(80,20);cout << "  @@@@@ " << endl;
    gotoxy(80,21);cout << " @  @  @" << endl;
    gotoxy(80,22);cout << "  @ @ @  " << endl;
    gotoxy(80,23);cout << "   @@@ " << endl;
    gotoxy(80,24);cout << "  @   @" << endl;
    gotoxy(80,25);cout << "  @   @ " << endl;
    gotoxy(80,26);cout << "  @   @  " << endl;
    gotoxy(80,27);cout << "-------------" << endl;

    //alverga no se que onda


}

void no_ahorcado(){
    gotoxy(10,1);cout <<  "    ##############################################################################################" << endl;
    gotoxy(10,2);cout <<  "         ######################################################################################" << endl;
    gotoxy(80,3);cout <<  "           ()" << endl;
    gotoxy(80,4);cout <<  "           ()" << endl;
    gotoxy(80,5);cout <<  "           ()" << endl;
    gotoxy(80,6);cout <<  "           ()" << endl;
    gotoxy(80,7);cout <<  "           ()" << endl;
    gotoxy(80,8);cout <<  "           ()" << endl;
    gotoxy(80,9);cout <<  "           ()"<< endl;
    gotoxy(80,10);cout << "          ()" << endl;
    gotoxy(80,11);cout << "         ()" << endl;
    gotoxy(80,12);cout << "    (--)()" << endl;
    gotoxy(80,13);cout << "    " << endl;
    gotoxy(80,14);cout << "    " << endl;
    gotoxy(80,15);cout << "        " << endl;
    gotoxy(80,16);cout << "   @@@@   " << endl;
    gotoxy(80,17);cout << "  @ - -@ " << endl;
    gotoxy(80,18);cout << "   @@@@  " << endl;
    gotoxy(80,19);cout << "    @" << endl;
    gotoxy(80,20);cout << "  @@@@@ " << endl;
    gotoxy(80,21);cout << " @  @  @" << endl;
    gotoxy(80,22);cout << "@   @   @" << endl;
    gotoxy(80,23);cout << "   @@@ " << endl;
    gotoxy(80,24);cout << "  @   @" << endl;
    gotoxy(80,25);cout << "  @   @ " << endl;
    gotoxy(80,26);cout << "  @   @  " << endl;
    gotoxy(80,27);cout << "-------------" << endl;

}
