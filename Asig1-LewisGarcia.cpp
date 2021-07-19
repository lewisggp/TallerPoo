/*
    Autor: Lewis Garcia
    Asignacion: 1
    Fecha: 28 de febrero de 2021

    Programa que muestra la sumatorsia de enteros positivos de i = 1 hasta i = N
*/

#include <iostream>
using namespace std;

int main(){
    int n, suma;

    cout << "Ingrese porfavor un numero entero positivo.\nN = ";
    cin >> n;
    
    if(!cin.fail() && n > 0){
        suma = (n + 1) * n / 2;
        cout << "La sumatoria de 1 hasta " << n << " es de " << suma;
    }else{
        cout << "No ingresaste un numero entero positivo";
    }

    return 0;
}
