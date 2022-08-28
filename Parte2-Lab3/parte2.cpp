/*---------------------------------------
UNIVERSIDAD DEL VALLE DE GUATEMALA
CC3056 - Programacion de Microprocesadores
Realizado por: Angel Castellanos

LAB3 - Parte 2
Pide una cantidad de threads y una rango de numeros para poder sumar todos los numeros primos dentro del rango.
---------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
using namespace std;


void *Sumatoria(void *n ) {
    float resultado = 0;
    int Numero = 0;
    Numero = *(int*)n;

    resultado = Numero * (Numero + 1);
    resultado = 1/resultado;
    
    cout << resultado << endl;
    
    return (void*) resultado;
    //pthread_exit(NULL);
    //pthread_exit((void *) IntResultado);
}

int main() {
    float SumaTotal = 0;
    int n = 0;
    int i;
    float SumaPorHilo = 0;
    pthread_t idThread;

    cout << "Ingrese el numero n maximo: " << endl;
    cin >> n;
    

    for(i = 1; i <= n; i++){
        
        pthread_create(&idThread, NULL, Sumatoria, ( void *)&i);
        //pthread_join(idThread, NULL);
        
        pthread_join(idThread, (void **)&SumaPorHilo);
        float result = (float) SumaPorHilo;

        SumaTotal = SumaTotal + result;
    }

    cout << "La sumatoria de n = 0 hasta n = " << n << " es de: "  << SumaTotal << endl;

    printf ("\n --- Fin --- \n");
}