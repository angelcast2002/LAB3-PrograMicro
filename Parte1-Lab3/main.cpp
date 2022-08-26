/*---------------------------------------
UNIVERSIDAD DEL VALLE DE GUATEMALA
CC3056 - Programacion de Microprocesadores
Realizado por: Angel Castellanos

LAB3 - Parte 1
Pide una cantidad de threads y una rango de numeros para poder sumar todos los numeros primos dentro del rango.
---------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
using namespace std;


struct sumPrimos {

    int maximo;
    int idHilo;
    int cantHilos;
    int noPorCadaHilo;

};

void *calculoPrimos(void *structura ) {
    sumPrimos *ps;
    ps = (sumPrimos *)structura;
    int suma = 0;

    int minimo = (ps -> idHilo)*(ps -> noPorCadaHilo);
    int maximo = minimo + ((ps -> noPorCadaHilo)-1);
    cout << "Hilo " << ps -> idHilo << ": " << endl;

    if (ps -> idHilo == (ps -> cantHilos) - 1){
        maximo = maximo + 1;
        cout << "Los numeros primos son:" << endl;
        for (int i = minimo; i <= maximo; i++){
            int n, h, flag = 0;
            n = i;
            // 0 and 1 are not prime numbers
            // change flag to 1 for non-prime number
            if (n == 0 || n == 1)
                flag = 1;

            for (h = 2; h <= n / 2; h++) {

                // if n is divisible by i, then n is not prime
                // change flag to 1 for non-prime number
                if (n % h == 0) {
                    flag = 1;
                    break;
                }
            }

            //Codigo obtenido de https://www.programiz.com/c-programming/examples/prime-number
            //para verificar si un numero es primo o no

            if (flag == 0){
                cout << i << endl;
                suma = suma + i;
            }

        }

        cout << "Suma: " << suma << endl;
    }
    else{
        cout << "Los numeros primos son:" << endl;
        for (int i = minimo; i <= maximo; i++){
            int n, h, flag = 0;
            n = i;
            // 0 and 1 are not prime numbers
            // change flag to 1 for non-prime number
            if (n == 0 || n == 1)
                flag = 1;

            for (h = 2; h <= n / 2; h++) {

                // if n is divisible by i, then n is not prime
                // change flag to 1 for non-prime number
                if (n % h == 0) {
                    flag = 1;
                    break;
                }
            }

            //Codigo obtenido de https://www.programiz.com/c-programming/examples/prime-number
            //para verificar si un numero es primo o no

            if (flag == 0){
                cout << i << endl;
                suma = suma + i;
            }

        }

        cout << "Suma: " << suma << endl;
    }


    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    int i;
    sumPrimos p;

    cout << "Ingrese el numero maximo: " << endl;
    cin >> p.maximo;
    cout << "Ingrese el numero de hilos: " << endl;
    cin >> p.cantHilos;

    p.noPorCadaHilo = p.maximo / p.cantHilos;

    for(i=0; i<p.cantHilos; i++){
        p.idHilo = i;
        pthread_create(&thread, NULL, calculoPrimos, ( void *)&p);
        pthread_join(thread, NULL);

    }


    printf ("\n --- Fin --- \n");
}