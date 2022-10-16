#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<stdexcept>
#include<sstream>
#include<cmath>
#include<fstream>
using namespace std;
const int F = 0;
const int C = 1;
/*---- Prototipos de Funciones -----*/
void LlenarCarton(int SumaPIndice, int SumaSIndice, int Jug1, int Jug2, int PosicionDelJugador[2][2], string Tablero[11][8], int MatrizAux[11][8]);
void EvaluarMovimiento(int SumaPIndice, int SumaSIndice, int Jug1, int Jug2, int Total, int Total2, string Jugador1, string Jugador2, string Tablero[11][8], int MatrizAux[11][8], int PosicionDelJugador[2][2]);
void ImprimirTablero(int Jug1, int Jug2, string Jugador1, string Jugador2, string Tablero[11][8], int MatrizAux[11][8], int PosicionDelJugador[2][2]);

int main(){
    srand(time(NULL));
        int Total = 0, Total2 = 0, Jug1 = 0, Jug2 = 1, SumaPIndice = 0, SumaSIndice = 0, PosicionDelJugador[2][2], op = 0, MatrizAux[11][8];
        string Jugador1 = "", Jugador2 = "", Tablero[11][8];
bool continuar = true;
    do{
        LlenarCarton(SumaPIndice, SumaSIndice, Jug1, Jug2, PosicionDelJugador, Tablero, MatrizAux); //Llenamos las matrices con las que vamos a trabajar
        cout << R"(
                .d88b.       .d88b.       .d88b.       .d88b.
              d0888" "b    d0888" "b    d0888" "b    d0888" "b
              00888. .P    00888. .P    00888. .P    00888. .P
              00888888     00888888     00888888     00888888
                888888       888888       888888       888888
                88''88       88''88       88''88       88''88)" << '\n';
        cout << "\n\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
        cout << "\272\      BIENVENIDOS AL JUEGO MONSTRUOS COME SUMAS ESTOS SON LOS MONSTRUOS      \272\n";
        cout << "\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270\n" << endl;
        system("pause");
        system("cls");
		cout << "\nJugador, digite su nombre: "; //Pedimos el nombre del primer jugador
        cin >> Jugador1;
		cout << "Bienvenido " << Jugador1 << " usted es el [1] jugador" << endl;
		cout << "\nJugador, digite su nombre: "; //Pedimos el nombre del segundo jugador
        cin >> Jugador2;
		cout << "Bienvenido " << Jugador2 << " usted es el [2] jugador" << endl;
        bool saliendo = false; bool ok = false;
            do{
                do{
                    cout << "\n\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
                    cout << "\272" <<  "  MENU DE OPCIONES" << right << setw(25) << "\272" << endl;
                    cout << "\272" <<  "  [1] Continuar con el juego de monstruos" << right << setw(2) << "\272" << endl;
                    cout << "\272" <<  "  [2] Intrucciones del juego" << right << setw(15) << "\272" << endl;
                    cout << "\272" <<  "  [0] Salir del juego" << right << setw(22) << "\272" << endl;
                    cout << "\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
                    cout << "\n  Ingrese una opcion: ";
                    cin >> op;
                    system("cls");
					switch(op){
                        case 1: //En este case se carga el juego de monstruos come sumas
                            system("pause");
                            system("cls");
                                PosicionDelJugador[Jug1][F] = 0; //Inicializamos al jugador 1 en la casilla de inicio
                                PosicionDelJugador[Jug1][C] = 0;
                                PosicionDelJugador[Jug2][F] = 0; //Inicializamos al jugador 2 en la casilla de inicio
                                PosicionDelJugador[Jug2][C] = 0;
                            cout << "\nJUGADORES ESTAS SON SUS POSICIONES INICIALES :" << endl; cout << "" << endl;
                            ImprimirTablero(Jug1, Jug2, Jugador1, Jugador2, Tablero, MatrizAux, PosicionDelJugador); cout << "" << endl; //Imprimimos el tablero para mostrar en donde comenzaran los jugadores
                            system("pause");
                            system("cls");
                            EvaluarMovimiento(SumaPIndice, SumaSIndice, Jug1, Jug2, Total, Total2, Jugador1, Jugador2, Tablero, MatrizAux, PosicionDelJugador);
                            system("pause");
                            system("cls");break;

                        case 2: //En este case se cargan las instrucciones del juego
                            cout << "\n* Instrucciones: " << endl;
                            cout << "\t- Cada vez que conteste una suma de manera incorrecta, se les devolvera al monstruo mas cercano" << endl;
                            cout << "\t- Evita contestar incorrectamente para que los monstruos no los devoren" << endl;
                            cout << "\t- Gana el jugador que llegue primero a la meta" << endl;
                            cout << "\t- Los turno son de manera alternada" << endl;
                            cout << "\nSuerte jugadores----JAJAJAJAJAJAJAJA" << endl;break;

                        case 0:         //Este case nos da la posibilidad de salir del juego monstruo come sumas
                            saliendo = true;
                            continuar = false;break;
                    }
                    if(!cin.fail()){    //Estos condicionales para validar la entrada de datos fueron tomados de www.cristalab.com
                            ok = true;  //cita: (esutaraiki. 2010)
                    } else {
                        cin.clear();
                        cin.ignore(256,'\n');
                        cout << "Esto es un caracter, prueba con un numero" << endl;
                    }
                }while(!ok);       //Aqu� establecemos este do para validar estradas de caracteres en los case
        }while(saliendo == false); //Aqu� establecemos este do while para el switch y  que exista la opcion de salir
    }while(continuar == true);     //Establecemos este do para cargar con el contenido del juego
return 0;
}

void LlenarCarton(int SumaPIndice, int SumaSIndice, int Jug1, int Jug2, int PosicionDelJugador[2][2], string Tablero[11][8], int MatrizAux[11][8]){
    for(int i = 0; i < 11; i++){                        //Este for es para llenar el tablero a utilizar y la matriz auxiliar que contendra las sumas para poder calcular, pero no imprimir
        for(int j = 0; j < 8; j++){
            SumaPIndice = 10 + rand() % 15;             //Esta variable trendra valores entre 10 y 15 porque se sumara en l0 y el 15 asi nos dara un 25 como valor maximo entonces cuando se sume 25 con otro posible 25 dara 50
            SumaSIndice = 10 + rand() % 15;             //Esta variable trendra valores entre 10 y 25 porque se sumara en l0 y el 15 asi nos dara un 25 como valor maximo entonces cuando se sume 25 con otro posible 25 dara 50
            Tablero[i][j] = to_string(SumaPIndice) + "+" + to_string(SumaSIndice); //Convertimos a string las variables que contendran las sumas y las concatenamos obteniendo por ejemplo 3 + 5
            MatrizAux[i][j] = SumaPIndice + SumaSIndice;//El resultado de las sumas se guardara en las correspondientes posiciones dentro de la matriz auxiliar para comparar su resultado con el digitado por el usuario
        }
    }
    Tablero[0][0] = "INICIO"; Tablero[10][0] = "META";  //Inicializamos las posiciones de inicio y meta
    for(int i = 0; i < 11; i += 2){                     //For para llenar las posiciones con columnas 2 de MONSTRUOS
        Tablero[i][2] = "MONSTRUO";
    } for(int i = 0; i < 11; i += 2){                   //For para llenar las posiciones con columnas 6 de MONSTRUOS
        Tablero[i][6] = "MONSTRUO";
    }
    for(int i = 1; i < 2; i++){                         //Los siguientes for son para vaciar las filas que no se ocupan del tablero
        for(int j = 0; j < 7; j++){
            Tablero[i][j] = "";
        }
    } for(int i = 3; i < 4; i++){
        for(int j = 1; j < 8; j++){
            Tablero[i][j] = "";
        }
    } for(int i = 5; i < 6; i++){
        for(int j = 0; j < 7; j++){
            Tablero[i][j] = "";
        }
    } for(int i = 7; i < 8; i++){
        for(int j = 1; j < 8; j++){
            Tablero[i][j] = "";
        }
    } for(int i = 9; i < 10; i++){
        for(int j = 0; j < 7; j++){
            Tablero[i][j] = "";
        }
    }
}

void EvaluarMovimiento(int SumaPIndice, int SumaSIndice, int Jug1, int Jug2, int Total, int Total2, string Jugador1, string Jugador2, string Tablero[11][8], int MatrizAux[11][8], int PosicionDelJugador[2][2]){
int Dado; int Dado2; int Lanzar; int Lanzar2; int AvanzarPosiciones = 0; int AvanzarPosiciones2 = 0; bool TerminarBucle = false; bool ok = false;
int opc = 0; int *Dir_AvanzarPosiciones = &AvanzarPosiciones; int *Dir_AvanzarPosiciones2 = &AvanzarPosiciones2;
do{
    do{
        do{
            cout << "\n" << Jugador1 << " Ingrese [1] para lanzar los dados : ";    //Este codigo para lanzar dados y despues mostrarlos de manera similar se obtuvo de es.stackoverflow.com Cita: Acero, J. (19 de mayo del 2020)
            cin >> Lanzar;                                                          //Leemos la opcion digitada
                if(Lanzar == 1){                                                    //Si la opcion digitada es 1 se lanzara el dado
                    Dado = 8 + rand() % 10;                                          //Dado de 1 a 6
                } else {
                    cout << "\nLa opcion es invalida vuelva a intentarlo..." << endl;
                }
                if(!cin.fail()){
                    ok = true;
                } else {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "\tEsto es un caracter, prueba con un numero..." << endl;
                }
        }while(!ok);                                                                //Este do es para evaluar la entrada de caracteres
     }while(Lanzar != 1);                                                           //Este do es para evaluar que el programa tire dados unicamente cuando se digite el numero 1

        *Dir_AvanzarPosiciones = *Dir_AvanzarPosiciones + Dado; //Estas son las casillas que avanza el jugador se iran sumando en el juego conforme al valor del dado
        cout << "\272" << "  Obtuviste un" << right << setw( 8 ) << ": " << "[" << Dado << "]" << endl; //Mostramos el numero que saco del dado
        cout << "\272" << "  Casillas avanzadas" << right << setw( 1 ) << ": " << "[" << *Dir_AvanzarPosiciones << "]" << endl; //Mostramos las casillas que va avanzando el jugador 1
        cout << "\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270\n" << endl;

        if(*Dir_AvanzarPosiciones == 1){ //Estos if son para condicionar conforme a las casillas que avanza el jugador moverlo dentro de las posiciones del tablero y para devolverlo y cambiar el valor de las casillas avanzadas en caso de caer en un MONSTRUO
            PosicionDelJugador[Jug1][F] = 0;PosicionDelJugador[Jug1][C] = 1;
        } if(*Dir_AvanzarPosiciones == 2){
            PosicionDelJugador[Jug1][F] = 0;PosicionDelJugador[Jug1][C] = 2;
        } if(*Dir_AvanzarPosiciones == 3){
            PosicionDelJugador[Jug1][F] = 0;PosicionDelJugador[Jug1][C] = 3;
        } if(*Dir_AvanzarPosiciones == 4){
            PosicionDelJugador[Jug1][F] = 0;PosicionDelJugador[Jug1][C] = 4;
        } if(*Dir_AvanzarPosiciones == 5){
            PosicionDelJugador[Jug1][F] = 0;PosicionDelJugador[Jug1][C] = 5;
        } if(*Dir_AvanzarPosiciones == 6){
            PosicionDelJugador[Jug1][F] = 0;PosicionDelJugador[Jug1][C] = 6;
        } if(*Dir_AvanzarPosiciones == 6){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones = 2;
            PosicionDelJugador[Jug1][F] = 0;PosicionDelJugador[Jug1][C] = 2;
        } if(*Dir_AvanzarPosiciones == 7){
            PosicionDelJugador[Jug1][F] = 0;PosicionDelJugador[Jug1][C] = 7;
        } if(*Dir_AvanzarPosiciones == 8){
            PosicionDelJugador[Jug1][F] = 1;PosicionDelJugador[Jug1][C] = 7;
        } if(*Dir_AvanzarPosiciones == 9){
            PosicionDelJugador[Jug1][F] = 2;PosicionDelJugador[Jug1][C] = 7;
        } if(*Dir_AvanzarPosiciones == 10){
            PosicionDelJugador[Jug1][F] = 2;PosicionDelJugador[Jug1][C] = 6;
        } if(*Dir_AvanzarPosiciones == 10){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones = 6;
            PosicionDelJugador[Jug1][F] = 0;PosicionDelJugador[Jug1][C] = 6;
        } if(*Dir_AvanzarPosiciones == 11){
            PosicionDelJugador[Jug1][F] = 2;PosicionDelJugador[Jug1][C] = 5;
        } if(*Dir_AvanzarPosiciones == 12){
            PosicionDelJugador[Jug1][F] = 2;PosicionDelJugador[Jug1][C] = 4;
        } if(*Dir_AvanzarPosiciones == 13){
            PosicionDelJugador[Jug1][F] = 2;PosicionDelJugador[Jug1][C] = 3;
        } if(*Dir_AvanzarPosiciones == 14){
            PosicionDelJugador[Jug1][F] = 2;PosicionDelJugador[Jug1][C] = 2;
        } if(*Dir_AvanzarPosiciones == 14){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones = 10;
            PosicionDelJugador[Jug1][F] = 2;PosicionDelJugador[Jug1][C] = 6;
        } if(*Dir_AvanzarPosiciones == 15){
            PosicionDelJugador[Jug1][F] = 2;PosicionDelJugador[Jug1][C] = 1;
        } if(*Dir_AvanzarPosiciones == 16){
            PosicionDelJugador[Jug1][F] = 2;PosicionDelJugador[Jug1][C] = 0;
        } if(*Dir_AvanzarPosiciones == 17){
            PosicionDelJugador[Jug1][F] = 3;PosicionDelJugador[Jug1][C] = 0;
        } if(*Dir_AvanzarPosiciones == 18){
            PosicionDelJugador[Jug1][F] = 4;PosicionDelJugador[Jug1][C] = 0;
        } if(*Dir_AvanzarPosiciones == 19){
            PosicionDelJugador[Jug1][F] = 4;PosicionDelJugador[Jug1][C] = 1;
        } if(*Dir_AvanzarPosiciones == 20){
            PosicionDelJugador[Jug1][F] = 4;PosicionDelJugador[Jug1][C] = 2;
        } if(*Dir_AvanzarPosiciones == 20){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones = 14;
            PosicionDelJugador[Jug1][F] = 2;PosicionDelJugador[Jug1][C] = 2;
        } if(*Dir_AvanzarPosiciones == 21){
            PosicionDelJugador[Jug1][F] = 4;PosicionDelJugador[Jug1][C] = 3;
        } if(*Dir_AvanzarPosiciones == 22){
            PosicionDelJugador[Jug1][F] = 4;PosicionDelJugador[Jug1][C] = 4;
        } if(*Dir_AvanzarPosiciones == 23){
            PosicionDelJugador[Jug1][F] = 4;PosicionDelJugador[Jug1][C] = 5;
        } if(*Dir_AvanzarPosiciones == 24){
            PosicionDelJugador[Jug1][F] = 4;PosicionDelJugador[Jug1][C] = 6;
        } if(*Dir_AvanzarPosiciones == 24){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones = 20;
            PosicionDelJugador[Jug1][F] = 4;PosicionDelJugador[Jug1][C] = 2;
        } if(*Dir_AvanzarPosiciones == 25){
            PosicionDelJugador[Jug1][F] = 4;PosicionDelJugador[Jug1][C] = 7;
        } if(*Dir_AvanzarPosiciones == 26){
            PosicionDelJugador[Jug1][F] = 5;PosicionDelJugador[Jug1][C] = 7;
        } if(*Dir_AvanzarPosiciones == 27){
            PosicionDelJugador[Jug1][F] = 6;PosicionDelJugador[Jug1][C] = 7;
        } if(*Dir_AvanzarPosiciones == 28){
            PosicionDelJugador[Jug1][F] = 6;PosicionDelJugador[Jug1][C] = 6;
        } if(*Dir_AvanzarPosiciones == 28){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones = 24;
            PosicionDelJugador[Jug1][F] = 4;PosicionDelJugador[Jug1][C] = 6;
        } if(*Dir_AvanzarPosiciones == 29){
            PosicionDelJugador[Jug1][F] = 6;PosicionDelJugador[Jug1][C] = 5;
        } if(*Dir_AvanzarPosiciones == 30){
            PosicionDelJugador[Jug1][F] = 6;PosicionDelJugador[Jug1][C] = 4;
        } if(*Dir_AvanzarPosiciones == 31){
            PosicionDelJugador[Jug1][F] = 6;PosicionDelJugador[Jug1][C] = 3;
        } if(*Dir_AvanzarPosiciones == 32){
            PosicionDelJugador[Jug1][F] = 6;PosicionDelJugador[Jug1][C] = 2;
        } if(*Dir_AvanzarPosiciones == 32){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones = 28;
            PosicionDelJugador[Jug1][F] = 6;PosicionDelJugador[Jug1][C] = 6;
        } if(*Dir_AvanzarPosiciones == 33){
            PosicionDelJugador[Jug1][F] = 6;PosicionDelJugador[Jug1][C] = 1;
        } if(*Dir_AvanzarPosiciones == 34){
            PosicionDelJugador[Jug1][F] = 6;PosicionDelJugador[Jug1][C] = 0;
        } if(*Dir_AvanzarPosiciones == 35){
            PosicionDelJugador[Jug1][F] = 7;PosicionDelJugador[Jug1][C] = 0;
        } if(*Dir_AvanzarPosiciones == 36){
            PosicionDelJugador[Jug1][F] = 8;PosicionDelJugador[Jug1][C] = 0;
        } if(*Dir_AvanzarPosiciones == 37){
            PosicionDelJugador[Jug1][F] = 8;PosicionDelJugador[Jug1][C] = 1;
        } if(*Dir_AvanzarPosiciones == 38){
            PosicionDelJugador[Jug1][F] = 8;PosicionDelJugador[Jug1][C] = 2;
        } if(*Dir_AvanzarPosiciones == 38){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones = 32;
            PosicionDelJugador[Jug1][F] = 6;PosicionDelJugador[Jug1][C] = 2;
        } if(*Dir_AvanzarPosiciones == 39){
            PosicionDelJugador[Jug1][F] = 8;PosicionDelJugador[Jug1][C] = 3;
        } if(*Dir_AvanzarPosiciones == 40){
            PosicionDelJugador[Jug1][F] = 8;PosicionDelJugador[Jug1][C] = 4;
        } if(*Dir_AvanzarPosiciones == 41){
            PosicionDelJugador[Jug1][F] = 8;PosicionDelJugador[Jug1][C] = 5;
        } if(*Dir_AvanzarPosiciones == 42){
            PosicionDelJugador[Jug1][F] = 8;PosicionDelJugador[Jug1][C] = 6;
        } if(*Dir_AvanzarPosiciones == 42){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones = 38;
            PosicionDelJugador[Jug1][F] = 8;PosicionDelJugador[Jug1][C] = 2;
        } if(*Dir_AvanzarPosiciones == 43){
            PosicionDelJugador[Jug1][F] = 8;PosicionDelJugador[Jug1][C] = 7;
        } if(*Dir_AvanzarPosiciones == 44){
            PosicionDelJugador[Jug1][F] = 9;PosicionDelJugador[Jug1][C] = 7;
        } if(*Dir_AvanzarPosiciones == 45){
            PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 7;
        } if(*Dir_AvanzarPosiciones == 46){
            PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 6;
        } if(*Dir_AvanzarPosiciones == 46){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones = 42;
            PosicionDelJugador[Jug1][F] = 8;PosicionDelJugador[Jug1][C] = 6;
        } if(*Dir_AvanzarPosiciones == 47){
            PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 5;
        } if(*Dir_AvanzarPosiciones == 48){
            PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 4;
        } if(*Dir_AvanzarPosiciones == 49){
            PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 3;
        } if(*Dir_AvanzarPosiciones == 50){
            PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 2;
        } if(*Dir_AvanzarPosiciones == 50){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones = 46;
            PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 6;
        } if(*Dir_AvanzarPosiciones == 51){
            PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 1;
        } if(*Dir_AvanzarPosiciones == 52){
            PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 0;
        } if(*Dir_AvanzarPosiciones == 53){
            PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 0;
        } if(*Dir_AvanzarPosiciones == 54){
            PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 0;
        } if(*Dir_AvanzarPosiciones == 55){
            PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 0;
        } if(*Dir_AvanzarPosiciones == 56){
            PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 0;
        } if(*Dir_AvanzarPosiciones == 57){
            PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 0;
        } if(*Dir_AvanzarPosiciones == 58){
            PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 0;
        }

        ImprimirTablero(Jug1, Jug2, Jugador1, Jugador2, Tablero, MatrizAux, PosicionDelJugador); //Imprimimos el tablero para mostrar al jugador 1 en la posicion en donde se encuntre dentro del tablero
            if(*Dir_AvanzarPosiciones == 2 || *Dir_AvanzarPosiciones == 6 || *Dir_AvanzarPosiciones == 10 || *Dir_AvanzarPosiciones == 14 || *Dir_AvanzarPosiciones == 20 || *Dir_AvanzarPosiciones == 24 || *Dir_AvanzarPosiciones == 28 || *Dir_AvanzarPosiciones == 32 || *Dir_AvanzarPosiciones == 38 || *Dir_AvanzarPosiciones == 42 || *Dir_AvanzarPosiciones == 46 || *Dir_AvanzarPosiciones == 50){                                                          //Estos if son para condicionar los casos en los que el jugador caiga en un MONSTRUO si esto ocurre se le mostrara un mensaje de que a caido en un MONSTRUO
                cout << "\nCaiste en un (MONSTRUO) te devuelves al (MONSTRUO) anterior" << endl;
            } if(*Dir_AvanzarPosiciones >= 52){
                cout << "\nO--FIN DEL JUEGO--O" << endl;
            }

            //Este if es para evaluar si el jugador esta en una columna de MONSTRUO o no si no ya que si no se evalua y el jugador 1 cae en un MONSTRUO el juego le preguntara calcular MONSTRUO y eso es un error ya que MONSTRUO no se puede calcular igual cuando llega a la META
            if(PosicionDelJugador[Jug1][C] != 2 && PosicionDelJugador[Jug1][C] != 6 && Tablero[PosicionDelJugador[Jug1][F]][PosicionDelJugador[Jug1][C]] != Tablero[10][0]){
                cout << "\nEscribe tu respuesta : " << Tablero[PosicionDelJugador[Jug1][F]][PosicionDelJugador[Jug1][C]] << " = "; //Aqui mostramos las operaciones dependiendo de en que posicion se encuentre el jugador // Aqui falta evaluar numeros y no caracteres
                cin >> opc;
                Total = MatrizAux[PosicionDelJugador[Jug1][F]][PosicionDelJugador[Jug1][C]]; //Igualamos el total a las pociciones de la matriz auxiliar con la posicion en la que esta el jugador asi la posicion del jugador sera la misma de la matriz auxiliar por ende su operaion tambien
                if(Total == opc){                                                        //If para evaluar si la operacion esta bien o si esta mal, si esta bien es correta sino esta sera incorrecta
                    cout << "Tu respuesta es correcta" << endl;
                } else {                                                                 //Si el jugador resuelve incorrectamente la operacion sera devuelto al MONSTRUO mas cercano para eso son los siguientes if
                    cout << "Tu respuesta es incorrecta, te devulves al MONSTRUO MAS CERCANO" << endl;

                if(*Dir_AvanzarPosiciones == 3){                                          //Estos if son para devolver al jugador 2 a los monstruos
                    *Dir_AvanzarPosiciones = 2;
                    PosicionDelJugador[Jug1][F] = 0;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 4){
                    *Dir_AvanzarPosiciones = 2;
                    PosicionDelJugador[Jug1][F] = 0;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 5){
                    *Dir_AvanzarPosiciones = 2;
                    PosicionDelJugador[Jug1][F] = 0;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 7){
                    *Dir_AvanzarPosiciones = 6;
                    PosicionDelJugador[Jug1][F] = 0;PosicionDelJugador[Jug1][C] = 6;
                } if(*Dir_AvanzarPosiciones == 8){
                    *Dir_AvanzarPosiciones = 6;
                    PosicionDelJugador[Jug1][F] = 0;PosicionDelJugador[Jug1][C] = 6;
                } if(*Dir_AvanzarPosiciones == 9){
                    *Dir_AvanzarPosiciones = 6;
                    PosicionDelJugador[Jug1][F] = 0;PosicionDelJugador[Jug1][C] = 6;
                } if(*Dir_AvanzarPosiciones == 11){
                    *Dir_AvanzarPosiciones = 10;
                    PosicionDelJugador[Jug1][F] = 2;PosicionDelJugador[Jug1][C] = 6;
                } if(*Dir_AvanzarPosiciones == 12){
                    *Dir_AvanzarPosiciones = 10;
                    PosicionDelJugador[Jug1][F] = 2;PosicionDelJugador[Jug1][C] = 6;
                } if(*Dir_AvanzarPosiciones == 13){
                    *Dir_AvanzarPosiciones = 10;
                    PosicionDelJugador[Jug1][F] = 2;PosicionDelJugador[Jug1][C] = 6;
                } if(*Dir_AvanzarPosiciones == 15){
                    *Dir_AvanzarPosiciones = 14;
                    PosicionDelJugador[Jug1][F] = 2;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 16){
                    *Dir_AvanzarPosiciones = 14;
                    PosicionDelJugador[Jug1][F] = 2;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 17){
                    *Dir_AvanzarPosiciones = 14;
                    PosicionDelJugador[Jug1][F] = 2;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 18){
                    *Dir_AvanzarPosiciones = 14;
                    PosicionDelJugador[Jug1][F] = 2;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 19){
                    *Dir_AvanzarPosiciones = 14;
                    PosicionDelJugador[Jug1][F] = 2;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 21){
                    *Dir_AvanzarPosiciones = 20;
                    PosicionDelJugador[Jug1][F] = 4;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 22){
                    *Dir_AvanzarPosiciones = 20;
                    PosicionDelJugador[Jug1][F] = 4;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 23){
                    *Dir_AvanzarPosiciones = 20;
                    PosicionDelJugador[Jug1][F] = 4;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 25){
                    *Dir_AvanzarPosiciones = 24;
                    PosicionDelJugador[Jug1][F] = 4;PosicionDelJugador[Jug1][C] = 6;
                } if(*Dir_AvanzarPosiciones == 26){
                    *Dir_AvanzarPosiciones = 24;
                    PosicionDelJugador[Jug1][F] = 4;PosicionDelJugador[Jug1][C] = 6;
                } if(*Dir_AvanzarPosiciones == 27){
                    *Dir_AvanzarPosiciones = 24;
                    PosicionDelJugador[Jug1][F] = 4;PosicionDelJugador[Jug1][C] = 6;
                } if(*Dir_AvanzarPosiciones == 29){
                    *Dir_AvanzarPosiciones = 28;
                    PosicionDelJugador[Jug1][F] = 6;PosicionDelJugador[Jug1][C] = 6;
                } if(*Dir_AvanzarPosiciones == 30){
                    *Dir_AvanzarPosiciones = 28;
                    PosicionDelJugador[Jug1][F] = 6;PosicionDelJugador[Jug1][C] = 6;
                } if(*Dir_AvanzarPosiciones == 31){
                    *Dir_AvanzarPosiciones = 28;
                    PosicionDelJugador[Jug1][F] = 6;PosicionDelJugador[Jug1][C] = 6;
                } if(*Dir_AvanzarPosiciones == 33){
                    *Dir_AvanzarPosiciones = 32;
                    PosicionDelJugador[Jug1][F] = 6;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 34){
                    *Dir_AvanzarPosiciones = 32;
                    PosicionDelJugador[Jug1][F] = 6;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 35){
                    *Dir_AvanzarPosiciones = 32;
                    PosicionDelJugador[Jug1][F] = 6;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 36){
                    *Dir_AvanzarPosiciones = 32;
                    PosicionDelJugador[Jug1][F] = 6;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 37){
                    *Dir_AvanzarPosiciones = 32;
                    PosicionDelJugador[Jug1][F] = 6;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 39){
                    *Dir_AvanzarPosiciones = 38;
                    PosicionDelJugador[Jug1][F] = 8;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 40){
                    *Dir_AvanzarPosiciones = 38;
                    PosicionDelJugador[Jug1][F] = 8;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 41){
                    *Dir_AvanzarPosiciones = 38;
                    PosicionDelJugador[Jug1][F] = 8;PosicionDelJugador[Jug1][C] = 2;
                } if(*Dir_AvanzarPosiciones == 43){
                    *Dir_AvanzarPosiciones = 42;
                    PosicionDelJugador[Jug1][F] = 8;PosicionDelJugador[Jug1][C] = 6;
                } if(*Dir_AvanzarPosiciones == 44){
                    *Dir_AvanzarPosiciones = 42;
                    PosicionDelJugador[Jug1][F] = 8;PosicionDelJugador[Jug1][C] = 6;
                } if(*Dir_AvanzarPosiciones == 45){
                    *Dir_AvanzarPosiciones = 42;
                    PosicionDelJugador[Jug1][F] = 8;PosicionDelJugador[Jug1][C] = 6;
                } if(*Dir_AvanzarPosiciones == 47){
                    *Dir_AvanzarPosiciones = 46;
                    PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 6;
                } if(*Dir_AvanzarPosiciones == 48){
                    *Dir_AvanzarPosiciones = 46;
                    PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 6;
                } if(*Dir_AvanzarPosiciones == 49){
                    *Dir_AvanzarPosiciones = 46;
                    PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 6;
                } if(*Dir_AvanzarPosiciones == 51){
                    *Dir_AvanzarPosiciones = 50;
                    PosicionDelJugador[Jug1][F] = 10;PosicionDelJugador[Jug1][C] = 2;
                }
          }
    }
    cout << "" << endl;
    if(*Dir_AvanzarPosiciones < 51){ //Este if es muy importante ya que es para determinar el ganador porque si el jugador 1 llega a la meta, pero en el turno del jugador 2 este tambien llega a la meta, el jugador 2 podria ser el ganador
    do{
        do{
            cout << Jugador2 << " Ingrese [1] para lanzar los dados : ";
            cin >> Lanzar2;                                                         //Leemos la opcion digitada
                if(Lanzar2 == 1){                                                   //Si la opcion digitada es 1 se lanzara el dado
                    Dado2 = 8 + rand() % 10;                                         //Dado de 1 a 6
                } else {
                    cout << "\nLa opcion es invalida vuelva a intentarlo..." << endl;
                }
                if(!cin.fail()){
                    ok = true;
                } else {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "\tEsto es un caracter, prueba con un numero..." << endl;
                }
        }while(!ok);                                                                //Este do es para evaluar la entrada de caracteres
     }while(Lanzar2 != 1);                                                          //Este do es para evaluar que el programa tire dados unicamente cuando se digite el numero 1

        *Dir_AvanzarPosiciones2 = *Dir_AvanzarPosiciones2 + Dado2; //Estas son las casillas que avanza el jugador 2 se iran sumando en el juego conforme al valor del dado
        cout << "\272" << "  Obtuviste un" << right << setw( 8 ) << ": " << "[" << Dado2 << "]" << endl; //Mostramos el numero que saco del dado
        cout << "\272" << "  Casillas avanzadas" << right << setw( 1 ) << ": " << "[" << *Dir_AvanzarPosiciones2 << "]" << endl; //Mostramos las casillas que va avanzando el jugador 2
        cout << "\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270\n" << endl;

        if(*Dir_AvanzarPosiciones2 == 1){ //Estos if son para condicionar conforme a las casillas que avanza el jugador 2 moverlo dentro de las posiciones del tablero y para devolverlo y  c a m biar el valor de las casillas avanzadas en caso de caer en un MONSTRUO
            PosicionDelJugador[Jug2][F] = 0;PosicionDelJugador[Jug2][C] = 1;
        } if(*Dir_AvanzarPosiciones2 == 2){
            PosicionDelJugador[Jug2][F] = 0;PosicionDelJugador[Jug2][C] = 2;
        } if(*Dir_AvanzarPosiciones2 == 3){
            PosicionDelJugador[Jug2][F] = 0;PosicionDelJugador[Jug2][C] = 3;
        } if(*Dir_AvanzarPosiciones2 == 4){
            PosicionDelJugador[Jug2][F] = 0;PosicionDelJugador[Jug2][C] = 4;
        } if(*Dir_AvanzarPosiciones2 == 5){
            PosicionDelJugador[Jug2][F] = 0;PosicionDelJugador[Jug2][C] = 5;
        } if(*Dir_AvanzarPosiciones2 == 6){
            PosicionDelJugador[Jug2][F] = 0;PosicionDelJugador[Jug2][C] = 6;
        } if(*Dir_AvanzarPosiciones2 == 6){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones2 = 2;
            PosicionDelJugador[Jug2][F] = 0;PosicionDelJugador[Jug2][C] = 2;
        } if(*Dir_AvanzarPosiciones2 == 7){
            PosicionDelJugador[Jug2][F] = 0;PosicionDelJugador[Jug2][C] = 7;
        } if(*Dir_AvanzarPosiciones2 == 8){
            PosicionDelJugador[Jug2][F] = 1;PosicionDelJugador[Jug2][C] = 7;
        } if(*Dir_AvanzarPosiciones2 == 9){
            PosicionDelJugador[Jug2][F] = 2;PosicionDelJugador[Jug2][C] = 7;
        } if(*Dir_AvanzarPosiciones2 == 10){
            PosicionDelJugador[Jug2][F] = 2;PosicionDelJugador[Jug2][C] = 6;
        } if(*Dir_AvanzarPosiciones2 == 10){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones2 = 6;
            PosicionDelJugador[Jug2][F] = 0;PosicionDelJugador[Jug2][C] = 6;
        } if(*Dir_AvanzarPosiciones2 == 11){
            PosicionDelJugador[Jug2][F] = 2;PosicionDelJugador[Jug2][C] = 5;
        } if(*Dir_AvanzarPosiciones2 == 12){
            PosicionDelJugador[Jug2][F] = 2;PosicionDelJugador[Jug2][C] = 4;
        } if(*Dir_AvanzarPosiciones2 == 13){
            PosicionDelJugador[Jug2][F] = 2;PosicionDelJugador[Jug2][C] = 3;
        } if(*Dir_AvanzarPosiciones2 == 14){
            PosicionDelJugador[Jug2][F] = 2;PosicionDelJugador[Jug2][C] = 2;
        } if(*Dir_AvanzarPosiciones2 == 14){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones2 = 10;
            PosicionDelJugador[Jug2][F] = 2;PosicionDelJugador[Jug2][C] = 6;
        } if(*Dir_AvanzarPosiciones2 == 15){
            PosicionDelJugador[Jug2][F] = 2;PosicionDelJugador[Jug2][C] = 1;
        } if(*Dir_AvanzarPosiciones2 == 16){
            PosicionDelJugador[Jug2][F] = 2;PosicionDelJugador[Jug2][C] = 0;
        } if(*Dir_AvanzarPosiciones2 == 17){
            PosicionDelJugador[Jug2][F] = 3;PosicionDelJugador[Jug2][C] = 0;
        } if(*Dir_AvanzarPosiciones2 == 18){
            PosicionDelJugador[Jug2][F] = 4;PosicionDelJugador[Jug2][C] = 0;
        } if(*Dir_AvanzarPosiciones2 == 19){
            PosicionDelJugador[Jug2][F] = 4;PosicionDelJugador[Jug2][C] = 1;
        } if(*Dir_AvanzarPosiciones2 == 20){
            PosicionDelJugador[Jug2][F] = 4;PosicionDelJugador[Jug2][C] = 2;
        } if(*Dir_AvanzarPosiciones2 == 20){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones2 = 14;
            PosicionDelJugador[Jug2][F] = 2;PosicionDelJugador[Jug2][C] = 2;
        } if(*Dir_AvanzarPosiciones2 == 21){
            PosicionDelJugador[Jug2][F] = 4;PosicionDelJugador[Jug2][C] = 3;
        } if(*Dir_AvanzarPosiciones2 == 22){
            PosicionDelJugador[Jug2][F] = 4;PosicionDelJugador[Jug2][C] = 4;
        } if(*Dir_AvanzarPosiciones2 == 23){
            PosicionDelJugador[Jug2][F] = 4;PosicionDelJugador[Jug2][C] = 5;
        } if(*Dir_AvanzarPosiciones2 == 24){
            PosicionDelJugador[Jug2][F] = 4;PosicionDelJugador[Jug2][C] = 6;
        } if(*Dir_AvanzarPosiciones2 == 24){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones2 = 20;
            PosicionDelJugador[Jug2][F] = 4;PosicionDelJugador[Jug2][C] = 2;
        } if(*Dir_AvanzarPosiciones2 == 25){
            PosicionDelJugador[Jug2][F] = 4;PosicionDelJugador[Jug2][C] = 7;
        } if(*Dir_AvanzarPosiciones2 == 26){
            PosicionDelJugador[Jug2][F] = 5;PosicionDelJugador[Jug2][C] = 7;
        } if(*Dir_AvanzarPosiciones2 == 27){
            PosicionDelJugador[Jug2][F] = 6;PosicionDelJugador[Jug2][C] = 7;
        } if(*Dir_AvanzarPosiciones2 == 28){
            PosicionDelJugador[Jug2][F] = 6;PosicionDelJugador[Jug2][C] = 6;
        } if(*Dir_AvanzarPosiciones2 == 28){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones2 = 24;
            PosicionDelJugador[Jug2][F] = 4;PosicionDelJugador[Jug2][C] = 6;
        } if(*Dir_AvanzarPosiciones2 == 29){
            PosicionDelJugador[Jug2][F] = 6;PosicionDelJugador[Jug2][C] = 5;
        } if(*Dir_AvanzarPosiciones2 == 30){
            PosicionDelJugador[Jug2][F] = 6;PosicionDelJugador[Jug2][C] = 4;
        } if(*Dir_AvanzarPosiciones2 == 31){
            PosicionDelJugador[Jug2][F] = 6;PosicionDelJugador[Jug2][C] = 3;
        } if(*Dir_AvanzarPosiciones2 == 32){
            PosicionDelJugador[Jug2][F] = 6;PosicionDelJugador[Jug2][C] = 2;
        } if(*Dir_AvanzarPosiciones2 == 32){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones2 = 28;
            PosicionDelJugador[Jug2][F] = 6;PosicionDelJugador[Jug2][C] = 6;
        } if(*Dir_AvanzarPosiciones2 == 33){
            PosicionDelJugador[Jug2][F] = 6;PosicionDelJugador[Jug2][C] = 1;
        } if(*Dir_AvanzarPosiciones2 == 34){
            PosicionDelJugador[Jug2][F] = 6;PosicionDelJugador[Jug2][C] = 0;
        } if(*Dir_AvanzarPosiciones2 == 35){
            PosicionDelJugador[Jug2][F] = 7;PosicionDelJugador[Jug2][C] = 0;
        } if(*Dir_AvanzarPosiciones2 == 36){
            PosicionDelJugador[Jug2][F] = 8;PosicionDelJugador[Jug2][C] = 0;
        } if(*Dir_AvanzarPosiciones2 == 37){
            PosicionDelJugador[Jug2][F] = 8;PosicionDelJugador[Jug2][C] = 1;
        } if(*Dir_AvanzarPosiciones2 == 38){
            PosicionDelJugador[Jug2][F] = 8;PosicionDelJugador[Jug2][C] = 2;
        } if(*Dir_AvanzarPosiciones2 == 38){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones2 = 32;
            PosicionDelJugador[Jug2][F] = 6;PosicionDelJugador[Jug2][C] = 2;
        } if(*Dir_AvanzarPosiciones2 == 39){
            PosicionDelJugador[Jug2][F] = 8;PosicionDelJugador[Jug2][C] = 3;
        } if(*Dir_AvanzarPosiciones2 == 40){
            PosicionDelJugador[Jug2][F] = 8;PosicionDelJugador[Jug2][C] = 4;
        } if(*Dir_AvanzarPosiciones2 == 41){
            PosicionDelJugador[Jug2][F] = 8;PosicionDelJugador[Jug2][C] = 5;
        } if(*Dir_AvanzarPosiciones2 == 42){
            PosicionDelJugador[Jug2][F] = 8;PosicionDelJugador[Jug2][C] = 6;
        } if(*Dir_AvanzarPosiciones2 == 42){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones2 = 38;
            PosicionDelJugador[Jug2][F] = 8;PosicionDelJugador[Jug2][C] = 2;
        } if(*Dir_AvanzarPosiciones2 == 43){
            PosicionDelJugador[Jug2][F] = 8;PosicionDelJugador[Jug2][C] = 7;
        } if(*Dir_AvanzarPosiciones2 == 44){
            PosicionDelJugador[Jug2][F] = 9;PosicionDelJugador[Jug2][C] = 7;
        } if(*Dir_AvanzarPosiciones2 == 45){
            PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 7;
        } if(*Dir_AvanzarPosiciones2 == 46){
            PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 6;
        } if(*Dir_AvanzarPosiciones2 == 46){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones2 = 42;
            PosicionDelJugador[Jug2][F] = 8;PosicionDelJugador[Jug2][C] = 6;
        } if(*Dir_AvanzarPosiciones2 == 47){
            PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 5;
        } if(*Dir_AvanzarPosiciones2 == 48){
            PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 4;
        } if(*Dir_AvanzarPosiciones2 == 49){
            PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 3;
        } if(*Dir_AvanzarPosiciones2 == 50){
            PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 2;
        } if(*Dir_AvanzarPosiciones2 == 50){ //MONSTRO se devuelve al anterior y se cambia el valor de las casillas
            *Dir_AvanzarPosiciones2 = 46;
            PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 6;
        } if(*Dir_AvanzarPosiciones2 == 51){
            PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 1;
        } if(*Dir_AvanzarPosiciones2 == 52){
            PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 0;
        } if(*Dir_AvanzarPosiciones2 == 53){
            PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 0;
        } if(*Dir_AvanzarPosiciones2 == 54){
            PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 0;
        } if(*Dir_AvanzarPosiciones2 == 55){
            PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 0;
        } if(*Dir_AvanzarPosiciones2 == 56){
            PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 0;
        } if(*Dir_AvanzarPosiciones2 == 57){
            PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 0;
        } if(*Dir_AvanzarPosiciones2 == 58){
            PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 0;
        }

        ImprimirTablero(Jug1, Jug2, Jugador1, Jugador2, Tablero, MatrizAux, PosicionDelJugador); //Imprimimos el tablero para mostrar al jugador 2 en la posicion en donde se encuntre dentro del tablero
            if(*Dir_AvanzarPosiciones2 == 2 || *Dir_AvanzarPosiciones2 == 6 || *Dir_AvanzarPosiciones2 == 10 || *Dir_AvanzarPosiciones2 == 14 || *Dir_AvanzarPosiciones2 == 20 || *Dir_AvanzarPosiciones2  == 24 || *Dir_AvanzarPosiciones2  == 28 || *Dir_AvanzarPosiciones2  == 32 || *Dir_AvanzarPosiciones2  == 38 || *Dir_AvanzarPosiciones2  == 42 || *Dir_AvanzarPosiciones2  == 46 || *Dir_AvanzarPosiciones2  == 50){                                                          //Estos if son para condicionar los casos en los que el jugador caiga en un MONSTRUO si esto ocurre se le mostrara un mensaje de que a caido en un MONSTRUO
                cout << "\nCaiste en un (MONSTRUO) te devuelves al (MONSTRUO) anterior" << endl;
            } if(*Dir_AvanzarPosiciones2 >= 52){
                cout << "\nO--FIN DEL JUEGO--O" << endl;
            }
            //Estos dos if son para evaluar si el jugador esta en un MONSTRUO o no ya que si no se evalua y el jugador cae en un MONSTRUO el juego le preguntara calcular MONSTRUO y eso es un error ya que MONSTRUO no se puede calcular igual con la llegada a la META
            if(PosicionDelJugador[Jug2][C] != 2 && PosicionDelJugador[Jug2][C] != 6 && Tablero[PosicionDelJugador[Jug2][F]][PosicionDelJugador[Jug2][C]] != Tablero[10][0]){
                cout << "\nEscribe tu respuesta : " << Tablero[PosicionDelJugador[Jug2][F]][PosicionDelJugador[Jug2][C]] << " = "; //Aqui mostramos las operaciones dependiendo de en que posicion se encuentre el jugador // Aqui falta evaluar numeros y no caracteres
                cin >> opc;
                Total2 = MatrizAux[PosicionDelJugador[Jug2][F]][PosicionDelJugador[Jug2][C]]; //Igualamos el total a las pociciones de la matriz auxiliar con la posicion en la que esta el jugador asi la posicion del jugador 2 sera la misma de la matriz auxiliar por ende su operaion tambien
                if(Total2 == opc){                                                        //If para evaluar si la operacion esta bien o si esta mal, si esta bien es correta sino esta sera incorrecta
                    cout << "Tu respuesta es correcta" << endl;
                } else {                                                                  //Si el jugador resuelve incorrectamente la operacion sera devuelto al MONSTRUO mas cercano para eso son los siguientes if
                    cout << "Tu respuesta es incorrecta, te devuelves al MONSTRUO MAS CERCANO" << endl;

                if(*Dir_AvanzarPosiciones2 == 3){                                          //Estos if son para devolver al jugador 2 a los monstruos
                    *Dir_AvanzarPosiciones2 = 2;
                    PosicionDelJugador[Jug2][F] = 0;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 4){
                    *Dir_AvanzarPosiciones2 = 2;
                    PosicionDelJugador[Jug2][F] = 0;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 5){
                    *Dir_AvanzarPosiciones2 = 2;
                    PosicionDelJugador[Jug2][F] = 0;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 7){
                    *Dir_AvanzarPosiciones2 = 6;
                    PosicionDelJugador[Jug2][F] = 0;PosicionDelJugador[Jug2][C] = 6;
                } if(*Dir_AvanzarPosiciones2 == 8){
                    *Dir_AvanzarPosiciones2 = 6;
                    PosicionDelJugador[Jug2][F] = 0;PosicionDelJugador[Jug2][C] = 6;
                } if(*Dir_AvanzarPosiciones2 == 9){
                    *Dir_AvanzarPosiciones2 = 6;
                    PosicionDelJugador[Jug2][F] = 0;PosicionDelJugador[Jug2][C] = 6;
                } if(*Dir_AvanzarPosiciones2 == 11){
                    *Dir_AvanzarPosiciones2 = 10;
                    PosicionDelJugador[Jug2][F] = 2;PosicionDelJugador[Jug2][C] = 6;
                } if(*Dir_AvanzarPosiciones2 == 12){
                    *Dir_AvanzarPosiciones2 = 10;
                    PosicionDelJugador[Jug2][F] = 2;PosicionDelJugador[Jug2][C] = 6;
                } if(*Dir_AvanzarPosiciones2 == 13){
                    *Dir_AvanzarPosiciones2 = 10;
                    PosicionDelJugador[Jug2][F] = 2;PosicionDelJugador[Jug2][C] = 6;
                } if(*Dir_AvanzarPosiciones2 == 15){
                    *Dir_AvanzarPosiciones2 = 14;
                    PosicionDelJugador[Jug2][F] = 2;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 16){
                    *Dir_AvanzarPosiciones2 = 14;
                    PosicionDelJugador[Jug2][F] = 2;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 17){
                    *Dir_AvanzarPosiciones2 = 14;
                    PosicionDelJugador[Jug2][F] = 2;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 18){
                    *Dir_AvanzarPosiciones2 = 14;
                    PosicionDelJugador[Jug2][F] = 2;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 19){
                    *Dir_AvanzarPosiciones2 = 14;
                    PosicionDelJugador[Jug2][F] = 2;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 21){
                    *Dir_AvanzarPosiciones2 = 20;
                    PosicionDelJugador[Jug2][F] = 4;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 22){
                    *Dir_AvanzarPosiciones2 = 20;
                    PosicionDelJugador[Jug2][F] = 4;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 23){
                    *Dir_AvanzarPosiciones2 = 20;
                    PosicionDelJugador[Jug2][F] = 4;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 25){
                    *Dir_AvanzarPosiciones2 = 24;
                    PosicionDelJugador[Jug2][F] = 4;PosicionDelJugador[Jug2][C] = 6;
                } if(*Dir_AvanzarPosiciones2 == 26){
                    *Dir_AvanzarPosiciones2 = 24;
                    PosicionDelJugador[Jug2][F] = 4;PosicionDelJugador[Jug2][C] = 6;
                } if(*Dir_AvanzarPosiciones2 == 27){
                    *Dir_AvanzarPosiciones2 = 24;
                    PosicionDelJugador[Jug2][F] = 4;PosicionDelJugador[Jug2][C] = 6;
                } if(*Dir_AvanzarPosiciones2 == 29){
                    *Dir_AvanzarPosiciones2 = 28;
                    PosicionDelJugador[Jug2][F] = 6;PosicionDelJugador[Jug2][C] = 6;
                } if(*Dir_AvanzarPosiciones2 == 30){
                    *Dir_AvanzarPosiciones2 = 28;
                    PosicionDelJugador[Jug2][F] = 6;PosicionDelJugador[Jug2][C] = 6;
                } if(*Dir_AvanzarPosiciones2 == 31){
                    *Dir_AvanzarPosiciones2 = 28;
                    PosicionDelJugador[Jug2][F] = 6;PosicionDelJugador[Jug2][C] = 6;
                } if(*Dir_AvanzarPosiciones2 == 33){
                    *Dir_AvanzarPosiciones2 = 32;
                    PosicionDelJugador[Jug2][F] = 6;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 34){
                    *Dir_AvanzarPosiciones2 = 32;
                    PosicionDelJugador[Jug2][F] = 6;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 35){
                    *Dir_AvanzarPosiciones2 = 32;
                    PosicionDelJugador[Jug2][F] = 6;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 36){
                    *Dir_AvanzarPosiciones2 = 32;
                    PosicionDelJugador[Jug2][F] = 6;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 37){
                    *Dir_AvanzarPosiciones2 = 32;
                    PosicionDelJugador[Jug2][F] = 6;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 39){
                    *Dir_AvanzarPosiciones2 = 38;
                    PosicionDelJugador[Jug2][F] = 8;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 40){
                    *Dir_AvanzarPosiciones2 = 38;
                    PosicionDelJugador[Jug2][F] = 8;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 41){
                    *Dir_AvanzarPosiciones2 = 38;
                    PosicionDelJugador[Jug2][F] = 8;PosicionDelJugador[Jug2][C] = 2;
                } if(*Dir_AvanzarPosiciones2 == 43){
                    *Dir_AvanzarPosiciones2 = 42;
                    PosicionDelJugador[Jug2][F] = 8;PosicionDelJugador[Jug2][C] = 6;
                } if(*Dir_AvanzarPosiciones2 == 44){
                    *Dir_AvanzarPosiciones2 = 42;
                    PosicionDelJugador[Jug2][F] = 8;PosicionDelJugador[Jug2][C] = 6;
                } if(*Dir_AvanzarPosiciones2 == 45){
                    *Dir_AvanzarPosiciones2 = 42;
                    PosicionDelJugador[Jug2][F] = 8;PosicionDelJugador[Jug2][C] = 6;
                } if(*Dir_AvanzarPosiciones2 == 47){
                    *Dir_AvanzarPosiciones2 = 46;
                    PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 6;
                } if(*Dir_AvanzarPosiciones2 == 48){
                    *Dir_AvanzarPosiciones2 = 46;
                    PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 6;
                } if(*Dir_AvanzarPosiciones2 == 49){
                    *Dir_AvanzarPosiciones2 = 46;
                    PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 6;
                } if(*Dir_AvanzarPosiciones2 == 51){
                    *Dir_AvanzarPosiciones2 = 50;
                    PosicionDelJugador[Jug2][F] = 10;PosicionDelJugador[Jug2][C] = 2;
                }
            }
        }
    }
    cout << "" << endl;
        if(*Dir_AvanzarPosiciones > 51){    //Si las casillas son mayores a 51 osea que el jugador este en la meta el bucle terminara
            TerminarBucle = true;
        } if(*Dir_AvanzarPosiciones2 > 51){ //Si las casillas son mayores a 51 osea que el jugador este en la meta el bucle terminara
            TerminarBucle = true;
        }
        system("pause");
        system("cls");
    }while(TerminarBucle == false);         //Este do es para cuando termine el juego
        Jugador1 = Jugador1.substr(0, 3);   //Esta funcion es para modificar el tama�o de los nombres de los jugadores en el tablero y a la hora de mostrar el ganador fue obtenida de www.geeksforgeeks.org
        Jugador2 = Jugador2.substr(0, 3);   //Cita (GeeksforGeeks. 2022)
        cout << R"(
             .d888888b.                                 888
            d88P                                        888
            888                                          888
            888 8888b.   8888b.  88888b.   8888b.   .d88888  .d88b.  888d888
 888888888  888    "88b     "88b 888 "88b     "88b d88" 888 d88""88b 888P"    888888888
 888888888  888     888 .d888888 888  888 .d888888 888  888 888  888 888      888888888
            888b. .d888 888  888 888  888 888  888 Y88b 888 Y88..88P 888
             "Y88888P"  "Y888888 888  888  Y888888  "Y88888  "Y88P"  888
    )" << '\n';
        if(*Dir_AvanzarPosiciones >= 52){   //Si gana el jugador 1
            cout << "\n\t\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
            cout << "\t\272                EN ORA BUENA, TENEMOS UN GANADOR" << right << setw( 23 ) << " \272" << endl;
            cout << "\t\272  El jugador ganador de nuestro juego MONSTRUO come SUMAS es : " << Jugador1 << right << setw( 5 ) << " \272" << endl;
        } else if(*Dir_AvanzarPosiciones2 >= 52){ //Si gana el jugador 2
            cout << "\t\272                EN ORA BUENA, TENEMOS UN GANADOR" << right << setw( 23 ) << " \272" << endl;
            cout << "\t\272  El jugador ganador de nuestro juego MONSTRUO come SUMAS es : " << Jugador2 << right << setw( 5 ) << " \272" << endl;
        }
            cout << "\t\272" << right << setw( 71 ) << " \272" << endl;
            cout << "\t\272       FELICIDADES JUGADORES HAN HECHO UN ECXELENTE TRABAJO" << right << setw( 12 ) << " \272" << endl;
            cout << "\t\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270\n" << endl;
}

void ImprimirTablero(int Jug1, int Jug2, string Jugador1, string Jugador2, string Tablero[11][8], int MatrizAux[11][8], int PosicionDelJugador[2][2]) {
Jugador1 = Jugador1.substr(0, 3);                                                         //Esto es para reducir la longitud de los nombres de los jugadores a tres letras para no descuadrar el tablero del jugador 1
Jugador2 = Jugador2.substr(0, 3);                                                         //Esto es para reducir la longitud de los nombres de los jugadores a tres letras para no descuadrar el tablero del jugador 2
    for(int i = 0; i < 11; i++){                                                          //Fors para mostrar el tablero
        for(int j = 0; j < 8; j++){                                                       //La idea para el siguiente bloque de codigo viene de fue tomada de es.stackoverflow.com Cita: Romero, A. (27 de noviembre del 2021)
            string Contador = " ";                                                        //Esta variable es para concatenar el jugador a ella y acomodarlo para que no se redimencione
                Contador = Tablero[i][j];
                if(PosicionDelJugador[Jug1][F] == i && PosicionDelJugador[Jug1][C] == j){ //Si la posicion del jugador 1 es igual a la fila y columna de el tablero se imprime el jugador 1 en esa posicion
                    Contador = Contador + "(" + Jugador1 + ")";                           //La variable sera igual a ella misma concatenando al jugador 1
                }
                if(PosicionDelJugador[Jug2][F] == i && PosicionDelJugador[Jug2][C] == j){ //Si la posicion del jugador 2 es igual a la fila y columna de el tablero se imprime el jugador 2 en esa posicion
                    Contador = Contador + "(" + Jugador2 + ")";                           //La variable sera igual a ella misma concatenando al jugador 2
                }
            cout << right << setw( 20 ) << Contador;                                      //Imprimimos la variable limpiar que en realidad es el tablero del juego
        }
        cout << endl;
    }
}
/* Referencias Bibliograficas:
esutoraiki. (29 de noviembre del 2010). Validacion de tipos de datos en C++. www.cristalab.com https://www.cristalab.com/tutoriales/validacion-de-tipos-de-datos-en-c--c92149l/
GeeksforGeeks. (11 de julio del 2022). Subcadena en C++. wwwgeeksforgeeks.org https://www.geeksforgeeks.org/substring-in-cpp/
Acero, J. (19 de mayo del 2020). Juego de dados en c++ sintaxis. es.stackoverflow. com https://es.stackoverflow.com/questions/357252/juego-de-dados-en-c-sintaxis
Romero, A. (27 de noviembre del  2021). �C�mo muestro la posici�n de un numero con la matriz?. es.stackoverflow.com https://es.stackoverflow.com/questions/499808/c%c3%b3mo-muestro-la-posici%c3%b3n-de-un-numero-con-la-matriz
*/
