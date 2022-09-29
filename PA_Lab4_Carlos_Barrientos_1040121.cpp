#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

struct probabilidadesTabla{
    //Tortuga
    int probabilidadMovimientoTortuga(int numero) {
        int *p_numero = &numero;
        if (*p_numero >=1 && *p_numero <=5){
            return 3;
        }
        else if (*p_numero >= 6 && *p_numero <= 7){
            return -6;
        }
        else if (*p_numero >= 8 && *p_numero <= 10) {
            return 1;
        }
    }
    int probabilidadMovimientoLiebre(int numero) {
        int* p_numero = &numero;
        if (*p_numero >= 1 && *p_numero <= 2) {
            return 0;
        }
        else if (*p_numero >= 3 && *p_numero <= 4) {
            return 9;
        }
        else if (*p_numero == 5) {
            return -12;
        }
        else if (*p_numero >= 6 && *p_numero <= 8) {
            return 1;
        }
        else if (*p_numero >= 9 && *p_numero <= 10) {
            return -2;
        }
    }
}liebre, tortuga;

//procedimiento para retrasar el tiempo
void delay(int segundos) {
    for (int i = (time(NULL) + segundos); time(NULL) != i; time(NULL));
}

//procedicimiento para impresion de la pista
void imprimirPista(string pista[]) {

    for (int i = 0; i < 70; i++)
    {
        cout << pista[i];
    }
    cout << endl;
}

//procedimiento para generar numero random
int generarRandom() {
    int random;
    random= 1 + rand() % (11 - 1);
    return random;
}
//llenado de pista
void llenadoPista(string pista[]) {
    for (int i = 0; i < 70; i++)
    {
        pista[i] = "_";
    }
}



int main()
{
    int opcion = 1;
    while (opcion == 1)
    {
    //declaracion de variables
    string pista[70];
    int posicionTortuga = 0, * p_posicionTortuga = &posicionTortuga;
    int posicionTortugaAnterior = 0, *p_posicionTortugaAnterior=&posicionTortugaAnterior;
    int posicionLiebre = 0, * p_posicionLiebre = &posicionLiebre;
    int posicionLiebreAnterior = 0, *p_posicionLiebreAnterior=&posicionLiebreAnterior;
    int posicionOuch = 0, *p_posicionOuch=&posicionOuch,i = 0;


    //llenado de pista
    llenadoPista(pista);

    //ciclo de carrera


        cout << "¡BANG! " << endl << "¡ARRANCAN!" << endl;
        while (i < 70)
        {

            int numeroRandom = generarRandom(), *p_numeroRandom = &numeroRandom;
            int retornadoTortuga = tortuga.probabilidadMovimientoTortuga(*p_numeroRandom);
            int retornadoLiebre = liebre.probabilidadMovimientoLiebre(*p_numeroRandom);


            pista[*p_posicionTortugaAnterior] = "_";
            pista[*p_posicionLiebreAnterior] = "_";

            posicionTortuga = *p_posicionTortuga + retornadoTortuga;
            posicionLiebre = *p_posicionLiebre + retornadoLiebre;
            if (*p_posicionLiebre >= 70)
            {
                cout << "La liebre gana ni hablar" << endl;
                break;
            }
            else if (*p_posicionTortuga >= 70) {
                cout << "LA TORTUGA GANA ¡BRAVO!" << endl;
                break;
            }
            else if (*p_posicionTortuga >= 70 && *p_posicionLiebre >= 70) {
                cout << "Es un empate, pero gano la tortuga por conquistar nuestros corazones" << endl;
                break;
            }

            if (*p_posicionTortuga < 0)
            {
                *p_posicionTortuga = 0;
            }
            if (*p_posicionLiebre < 0)
            {
                *p_posicionLiebre = 0;
            }
            if (*p_posicionLiebre == *p_posicionTortuga)
            {
                *p_posicionLiebre = *p_posicionOuch;
                pista[*p_posicionOuch] = "OUCH!";
            }
            else
            {
                pista[*p_posicionTortuga] = " T ";
                pista[*p_posicionLiebre] = " L ";
            }

            imprimirPista(pista);
            posicionTortugaAnterior = *p_posicionTortuga;
            posicionLiebreAnterior = *p_posicionLiebre;

            delay(1);
            i++;
        }
        cout << "¿Desea volver a repetir la simulacion? \n1. Si \n2.No" << endl;
        cin >> opcion;
    }


    cout << "Simulacion terminada" << endl;


}