/*
    Autor: Lewis Garcia
    Asignacion: 2
    Fecha: 21 de febrero de 2021

    Programa que muestra reporte de notas de un estudiante. Con Final / Reparacion o sin derecho a presentar
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    
    setlocale(LC_ALL, "");
    //-------------------------------------------------------------------- Datos del Estudiante --------------------------------------------------------------------
    
    string nombre, 
		apellido;
    int cedula;
    
    printf("\n%118s","---------------------------------------------- Datos del Estudiante ----------------------------------------------\n");
    printf("\n%64s","Ingrese el nombre: ");
    cin >> nombre;
    printf("\n%66s","Ingrese el apellido: ");
    cin >> apellido;
    printf("\n%64s","Ingrese la cédula: ");
    cin >> cedula;
    if(cin.fail()){
    	printf("\n%67s","Cédula Inválida");
    	return 0;
	}
    
    //-------------------------------------------------------------------- Practicos --------------------------------------------------------------------
    
    printf("\n%118s","--------------------------------------------------- Prácticos ----------------------------------------------------\n");
    float practico1, practico2, practico3, practico4, notaMaximaPractico = 0;
    int cantidadPracticosAprobados = 0;
    
    //Practico 1
	printf("\n%74s","Ingrese la nota del práctico 1: ");
    cin >> practico1;
    if(cin.fail()){
    	printf("\n%89s","Ingresaste mal la nota. Solo números o decimales con punto");
    	return 0;
	}
	if(practico1 < 0 ||  practico1 > 10){
    	printf("\n%77s","Nota inválida. Mínimo 0 - Máximo 10");
    	return 0;
	}
    if(practico1 >= 5) cantidadPracticosAprobados++;
    if(practico1 > notaMaximaPractico) notaMaximaPractico = practico1;
    
    //Practico 2
	printf("\n%74s","Ingrese la nota del práctico 2: ");
    cin >> practico2;
    if(cin.fail()){
    	printf("\n%89s","Ingresaste mal la nota. Solo números o decimales con punto");
    	return 0;
	}
	if(practico2 < 0 ||  practico2 > 10){
    	printf("\n%77s","Nota inválida. Mínimo 0 - Máximo 10");
    	return 0;
	}
    if(practico2 >= 5) cantidadPracticosAprobados++;
    if(practico2 > notaMaximaPractico) notaMaximaPractico = practico2;
    
    //Practico 3
	printf("\n%74s","Ingrese la nota del práctico 3: ");
    cin >> practico3;
    if(cin.fail()){
    	printf("\n%89s","Ingresaste mal la nota. Solo números o decimales con punto");
    	return 0;
	}
	if(practico3 < 0 ||  practico3 > 10){
    	printf("\n%77s","Nota inválida. Mínimo 0 - Máximo 10");
    	return 0;
	}
    if(practico3 >= 5) cantidadPracticosAprobados++;
    if(practico3 > notaMaximaPractico) notaMaximaPractico = practico3;
    
    //Practico 4
	printf("\n%74s","Ingrese la nota del práctico 4: ");
    cin >> practico4;
    if(cin.fail()){
    	printf("\n%89s","Ingresaste mal la nota. Solo números o decimales con punto");
    	return 0;
	}
	if(practico4 < 0 ||  practico4 > 10){
		cout << "";
    	printf("\n%77s","Nota inválida. Mínimo 0 - Máximo 10");
    	return 0;
	}
    if(practico4 >= 5) cantidadPracticosAprobados++;
    if(practico4 > notaMaximaPractico) notaMaximaPractico = practico4;
    float subTotalPracticos = (practico1 + practico2 + practico3 + practico4) * 0.2 / 4;
    
    //-------------------------------------------------------------------- Parciales --------------------------------------------------------------------
    
    printf("\n%118s","--------------------------------------------------- Parciales ----------------------------------------------------\n");
    float parcial1, parcial2, parcial3, notaMaximaParcial = 0;
    int cantidadParcialesAprobados = 0;
    
    //Parcial 1
	printf("\n%73s","Ingrese la nota del parcial 1: ");
    cin >> parcial1;
    if(cin.fail()){
    	printf("\n%89s","Ingresaste mal la nota. Solo números o decimales con punto");
    	return 0;
	}
	if(parcial1 < 0 ||  parcial1 > 10){
    	printf("\n%77s","Nota inválida. Mínimo 0 - Máximo 10");
    	return 0;
	}
    if(parcial1 >= 5) cantidadParcialesAprobados++;
    if(parcial1 > notaMaximaParcial) notaMaximaParcial = parcial1;
    
    //Parcial 2
	printf("\n%73s","Ingrese la nota del parcial 2: ");
    cin >> parcial2;
    if(cin.fail()){
    	printf("\n%89s","Ingresaste mal la nota. Solo números o decimales con punto");
    	return 0;
	} 
	if(parcial2 < 0 || parcial2 > 10){
    	printf("\n%77s","Nota inválida. Mínimo 0 - Máximo 10");
    	return 0;
	}
    if(parcial2 >= 5) cantidadParcialesAprobados++;
    if(parcial2 > notaMaximaParcial) notaMaximaParcial = parcial2;
    
    //Parcial 3
	printf("\n%73s","Ingrese la nota del parcial 3: ");
    cin >> parcial3;
    if(cin.fail()){
    	printf("\n%89s","Ingresaste mal la nota. Solo números o decimales con punto");
    	return 0;
	}
	if(parcial3 < 0 || parcial3 > 10){
    	printf("\n%77s","Nota inválida. Mínimo 0 - Máximo 10");
    	return 0;
	}
    if(parcial3 >= 5) cantidadParcialesAprobados++;
    if(parcial3 > notaMaximaParcial) notaMaximaParcial = parcial3;
    float subTotalParciales = (parcial1 + parcial2 + parcial3) * 0.5 / 3;
   
    //-------------------------------------------------------------------- Total --------------------------------------------------------------------
    
    float notas = subTotalPracticos + subTotalParciales;
    float final, reparacion, definitiva;
    int definitivaRedondeada;
    if(notas >= 3.5){
		printf("\n%71s","Ingrese la nota del final: ");
    	cin >> final;
		if(cin.fail()){
    	printf("\n%89s","Ingresaste mal la nota. Solo números o decimales con punto");
	    	return 0;
		}
		if(final < 0 || final > 10){
    	printf("\n%77s","Nota inválida. Mínimo 0 - Máximo 10");
	    	return 0;
		}
    	definitiva = notas + final * 0.3;
	}else if(notas >= 2){
		printf("\n%74s","Ingrese la nota del reparación: ");
		cin >> reparacion;
		if(cin.fail()){
    	printf("\n%89s","Ingresaste mal la nota. Solo números o decimales con punto");
	    	return 0;
		}
		if(reparacion < 0 || reparacion > 10){
    	printf("\n%77s","Nota inválida. Mínimo 0 - Máximo 10");
	    	return 0;
		}
    	definitiva = reparacion;
	}else{
		definitiva = notas;
	}
	definitivaRedondeada = definitiva * 10;
	if(definitivaRedondeada % 10 >= 5){
		definitivaRedondeada /= 10;
		definitivaRedondeada++;
	}
	else definitivaRedondeada /= 10;
	
    //-------------------------------------------------------------------- Mostrar --------------------------------------------------------------------
    
    printf("\n%118s","------------------------------------------------------------------------------------------------------------------\n");
    printf("   |%114s","|\n");
    printf("   |%64s%50s","Reporte de notas","|\n");
	cout << "   |  Estudiante: " << nombre << " " << apellido << "	 Cédula: " << cedula << endl;
    printf("   |%114s","|\n");
    printf("   |%114s","------------------------------------------------------------------------------------------------------------  |\n");
    printf("   |%114s","| Práctico1 | Práctico2 | Práctico3 | Práctico4 | Parcial1 | Parcial2 | Parcial3 |    Final   | Reparación |  |\n");
    printf("   |%114s","|----------------------------------------------------------------------------------------------------------|  |\n");
    if(notas >= 3.50)
    	printf("   |  |%8.2f   |%8.2f   |%8.2f   |%8.2f   |%7.2f   |%7.2f   |%7.2f   |%8.2f    |%7s     |  |\n", practico1, practico2, practico3, practico4, parcial1, parcial2, parcial3, final, "NA");
    else if(notas >= 2)
    	printf("   |  |%8.2f   |%8.2f   |%8.2f   |%8.2f   |%7.2f   |%7.2f   |%7.2f   |%7s     |%8.2f    |  |\n", practico1, practico2, practico3, practico4, parcial1, parcial2, parcial3, "NA", reparacion);
    else
    	printf("   |  |%8.2f   |%8.2f   |%8.2f   |%8.2f   |%7.2f   |%7.2f   |%7.2f   |%7s     |%7s     |  |\n", practico1, practico2, practico3, practico4, parcial1, parcial2, parcial3, "NA", "SD");
    printf("%118s","|  ------------------------------------------------------------------------------------------------------------  |\n");
    printf("   |%114s","|\n");
    printf("   |  Detalle de la evaluación:%87s","|\n");
    printf("   |%114s","|\n");
    printf("   |%41s%6.2f%67s","Nota máxima (Parciales):", notaMaximaParcial, "|\n");
    printf("   |%114s","|\n");
    printf("   |%41s%6.2f%67s","Nota máxima (Prácticos):", notaMaximaPractico, "|\n");
    printf("   |%114s","|\n");
    printf("   |%57s%2d%55s","Cantidad de notas aprobadas (Parciales):", cantidadParcialesAprobados, "|\n");
    printf("   |%114s","|\n");
    printf("   |%57s%2d%55s","Cantidad de notas aprobadas (Prácticos):", cantidadPracticosAprobados, "|\n");
    printf("   |%114s","|\n");
    printf("   |%26s%25s%6.2f%33s%6.2f%18s","SubTotal:","Notas prácticas (20%):", subTotalPracticos, "Notas parciales (50%):", subTotalParciales, "|\n");
    printf("   |%114s","|\n");
    if(notas >= 3.5)
    	printf("   |  Total:%21s%5.2f%14s%5.2f%20s %2.2f = %2d (Final)%23s", "Notas (70%):", notas, "Nota (30%):", final * 0.3, "Def.:", definitiva, definitivaRedondeada, "|\n");
    else if(notas >= 2)
    	printf("   |  Total:%21s%5.2f%14s%3s%22s %2.2f = %2d (Reparación)%18s", "Notas (70%):", notas, "Nota (30%):", "NA", "Def.:", definitiva, definitivaRedondeada, "|\n");
	else
    	printf("   |  Total:%21s%5.2f%14s%3s%22s %2.2f = %2d%31s", "Notas (70%):", notas, "Nota (30%):", "NA", "Def.:", definitiva, definitivaRedondeada,"|\n");
    printf("   |%114s","|\n");
    printf("%118s","------------------------------------------------------------------------------------------------------------------\n");
	    
    return 0;
    
}
