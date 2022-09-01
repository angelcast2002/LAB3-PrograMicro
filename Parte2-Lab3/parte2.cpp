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


void *Sumatoria(void *argument ) {

    float *total = (float *)malloc(sizeof(float));
    float resultado = 0.0;
	float *input = (float *)argument;

    float numeroSumatoria = *input;

    resultado = (numeroSumatoria) * (numeroSumatoria + 1);
    *total = (1/resultado);
    
    cout << "Cuando n = " << numeroSumatoria << " el subtotal es de  --- " << *total << " ---" << endl;

    return (void *) total;
    //pthread_exit(NULL);
    //pthread_exit((void *) IntResultado);
}

int main() {

    float SumaTotal = 0;
    int n = 0;

    pthread_t idThread;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    cout << "Ingrese el numero n maximo: " << endl;
    cin >> n;
    void *exit_value;

    for(int i = 1; i <= n; i++){

        float v = (float)i;
        pthread_create(&idThread, &attr, Sumatoria, ( void *)&v);
        //pthread_join(idThread, NULL);
        
        pthread_join(idThread, &exit_value);
        float *result = (float*) exit_value;

        SumaTotal = SumaTotal + *(result);
        free(exit_value);
    }

    cout << "La sumatoria de n = 1 hasta n = " << n << " es de: "  << SumaTotal << endl;

    printf ("\n --- Fin --- \n");
    pthread_attr_destroy(&attr);
	pthread_exit(NULL);
    return 0;
}