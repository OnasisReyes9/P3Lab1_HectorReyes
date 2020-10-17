/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Onasis Reyes
 *
 * Created on 16 de octubre de 2020, 03:34 PM
 */
#include <iostream>

using namespace std;
/*
 * 
 */
double ejercicio2(int);
double exponente(int);
double sigmoide(int);
void menu();

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char** argv) {
    menu();
    return 0;
}

void menu() {
    int opcion = 0;
    bool continuar = true;
    while (continuar) {
        cout << "Menú" << endl
                << "0. Salir" << endl
                << "1. Ejercicio 1" << endl
                << "2. Ejercicio 2" << endl
                << "-> Escoja: ";
        cin >> opcion;
        cout << "" << endl;
        switch (opcion) {
            case 1:
            {
                int numIngresadoX = 0;
                cout << "Ingrese valor de x: ";
                cin >> numIngresadoX;
                cout << "" << endl;

                cout << "f(" << numIngresadoX << ") = " << sigmoide(numIngresadoX) << endl << endl;
                break;
            }
            case 2:
            {
                int limite = 0;
                cout << "Ingrese límite: ";
                cin >> limite;
                while (limite <= 0) {
                    cout << "El límite debe ser mayor que 0. " << endl
                            << "Ingrese límite: ";
                    cin >> limite;
                }
                cout << "" << endl;
                cout << "Resultado: " << ejercicio2(limite) << endl << endl;
                break;
            }
            case 0:
            {
                cout << "La ejecución a finalizado." << endl;
                continuar = false;
                break;
            }
            default:
            {
                cout << "Opción inexistente." << endl << endl;
                break;
            }
        }//fin switch
    }//fin while
}//fin menu

double sigmoide(int numIngresadoX) {
    double resultado = 0.0, limite = 0.0;
    if (numIngresadoX < 0) {
        limite = numIngresadoX * -1;
        resultado = 1.0 / (1.0 + exponente(limite));
    } else {
        limite = numIngresadoX;
        resultado = 1.0 / exponente(limite);
        resultado = 1.0 / (1.0 + resultado);
    }//fin else
    return resultado;
}//fin método

double exponente(int limite) {
    double eElevado = 1.0;
    for (int i = 1; i <= limite; i++) {
        eElevado *= 2.718;
    }//fin for
    return eElevado;
}//fin método

double ejercicio2(int limite) {
    double resultado = 0.0, numerador = -1.0, denominador = 0.0;
    for (int i = 0; i <= limite; i++) {
        if (i % 2 == 0) {
            numerador = 1.0;
        } else {
            numerador = -1.0;
        }//fin else
        denominador = (2.0 * (double) i) + 1.0;
        resultado += (numerador / denominador);
    }//fin for
    return 4.0 * resultado;
}//fin método