/*
    Autor: Lewis Garcia
    Asignacion: 3
    Fecha: 5 de febrero de 2021

    Programa que muestra reporte de notas de un estudiante. Con Final / Reparacion o sin derecho a presentar
*/

#include <stdio.h>

// Maximo flotante de un arreglo
float maxFloat(float n[], int size) 
{
	float max = n[0];
	for(int i = 0; i < size; i++)
		if(max < n [i])
			max = n[i];
	return max;
}

// Suma de flotantes
float sumFloat(float n[], int size) 
{
	float total = 0;
	for(int i = 0; i < size; i++) total += n[i];
	return total;
}

// Promedio de flotantes
float averageFloat(float n[], int size)
{
	return sumFloat(n, size) / size;
}

// Concatenar dos cadenas de caracteres en el tercer parametro
void join(char nombre[], char apellido[], char nombreCompleto[]) 
{
	int i = 0;
	for(int j = 0; nombre[j] != '\0'; j++)
		nombreCompleto[i++] = nombre[j];
	nombreCompleto[i++] = ' ';
	for(int j = 0; apellido[j] != '\0'; j++)
		nombreCompleto[i++] = apellido[j];
	nombreCompleto[i] = '\0';
}

// Redondear flotante
int roundFloat(float n) 
{
	int round = n * 10;
	if(round % 10 >= 5)
		return round / 10 + 1;
	else return round / 10;
}

// Valor absoluto de un flotante
float absoluteFloat(float n) 
{
	return (n > 0) ? n : -n;
}

// Devuelve resultado de una potencia entera
float powInt(float base, int exponent) 
{
	if (exponent == 0) return 1;
	float r = base;
	for(int i = 1; i < absoluteFloat(exponent); i++)
		r *= base;
	return (exponent > 0) ? r : 1 / r;
}

// Valida el ingreso de una palabra (No acentos)
bool isWord(char pal[]) 
{
	int i;
	for(i = 0; pal[i] != '\0' && ((pal[i]>= 'A' && pal[i] <= 'Z') || (pal[i] >= 'a' && pal[i] <= 'z') || pal[i] == ' '); i++);
	if(pal[i] == '\0') return true;
	else return false;     
}

// Devuelve True si todos los caracteres son numeros
bool isInt(char pal[]) 
{
	int i;
	for(i = 0; pal[i] != '\0' && pal[i] >= '0' && pal[i] <= '9'; i++);
	if(pal[i] == '\0') return true;
	else return false;     
}

// Devuelve True si los caracteres cumple como float positivo o negativo con coma o punto
bool isFloat(char pal[]) 
{
     int i;
     int decimal = 0;
     if(!(pal[0] >= '0' && pal[0] <= '9' || pal[0] == '-')) return false;
     for(i = 1; pal[i] != '\0' && ((pal[i] >= '0' && pal[i] <= '9') || pal[i] == '.' || pal[i] == ','); i++) if(pal[i] == '.'|| pal[i] == ',') decimal++;
     if(pal[i] == '\0' && decimal <= 1) return true;
     else return false;     
}

// Transforma un caracter a entero
int toInt(char c) 
{
	if(c== '0') return 0;
	if(c== '1') return 1;
	if(c== '2') return 2;
	if(c== '3') return 3;
	if(c== '4') return 4;
	if(c== '5') return 5;
	if(c== '6') return 6;
	if(c== '7') return 7;
	if(c== '8') return 8;
	if(c== '9') return 9;
	return 0;
}

// Devuelve el parametro transformado en numero. Tiene que ya estar validado
int toInt(char pal[]) 
{
    int i = 0, n = 0;
    
    if(pal[0] == '-') i++;
	while(pal[i] != '\0') n = n * 10 + toInt(pal[i++]);
	
    return (pal[0] == '-') ? -n : n;
}

// Devuelve el parametro transformado en float negativo o positivo. Tiene que ya estar validado
float toFloat(char pal[]) 
{
    float n = 0;
    int i = 0, j = 0;
    
    if(pal[0] == '-') i++;
    while(pal[i] == '0') i++;
    while(pal[i] != '\0' && pal[i] != '.' && pal[i] != ',') n = n * 10 + toInt(pal[i++]);
    if(pal[i] != '\0') while(pal[i] != '\0' && j <= 4) n += toInt(pal[i++]) * powInt(10, -j++);
    
    return (pal[0] == '-') ? -n : n;
}

// Pedir un entero
int getInt() 
{
	char opc[20];
    bool repetir = true;
    do {
    	scanf("%[^\n]s", &opc);
		fflush(stdin);
    	if(!isInt(opc))
    		printf("%70s","Numero invalido, ingrese de nuevo: ");
    	else repetir = false;
	} while (repetir);
    return toInt(opc);
}

// Pedir un flotante
float getFloat() 
{
	char opc[20];
    bool repetir = true;
    do {
    	scanf("%[^\n]s", &opc);
		fflush(stdin);
    	if(!isFloat(opc) || !(toFloat(opc) >= 0 && toFloat(opc) <= 10))
    		printf("%70s","Numero invalido, ingrese de nuevo: ");
    	else repetir = false;
	} while (repetir);
    return toFloat(opc);
}

// Pide una arreglo de letras (Sin acentos)
void getString(char nombre[]) 
{
    bool repetir = true;
    do {
		scanf("%[^\n]s", nombre);
		fflush(stdin);
		if(!isWord(nombre))
    		printf("%70s","Dato invalido, ingrese de nuevo: ");
    	else repetir = false;
	} while (repetir);
}

// Cantidad de aprobados de un arreglo ( > 5 )
int cantidadAprobados(float n[], int size) 
{
	int a = 0;
	for(int i = 0; i < size; i++)
		if(n[i] > 5) a++;
	return a;
}

void reporte(char asignatura[], char nombre[], char apellido[], int cedula, float parciales[], float practicos[], float notaParciales, float notaPracticos, float final, float reparacion, float definitiva)
{
	char nombreCompleto[20];
	join(nombre, apellido, nombreCompleto);
	float acumulados = notaParciales + notaPracticos;
	int  definitivaRedondeada = roundFloat(definitiva);
	
	printf("\n%118s","------------------------------------------------------------------------------------------------------------------\n");
    printf("   |%114s","|\n");
    printf("   |%64s%50s","Reporte de notas","|\n");
    printf("   |%114s","|\n");
    printf("   |  Estudiante: %-30s %3s %-10i %25s %-25s |\n", nombreCompleto, "CI:", cedula, "Asignatura:", asignatura);
    printf("   |%114s","|\n");
    printf("   |%114s","------------------------------------------------------------------------------------------------------------  |\n");
    printf("   |%114s","| Practico1 | Practico2 | Practico3 | Practico4 | Parcial1 | Parcial2 | Parcial3 |    Final   | Reparacion |  |\n");
    printf("   |%114s","|----------------------------------------------------------------------------------------------------------|  |\n");
    printf("   |  ");
    for(int i = 0; i < 4; i++) printf("|%8.2f   ", practicos[i]);
    for(int i = 0; i < 3; i++) printf("|%7.2f   ", parciales[i]);
    if(acumulados >= 3.50)
    	printf("|%8.2f    |%7s     |  |\n", final, "NA");
    else if(acumulados >= 2)
    	printf("|%7s     |%8.2f    |  |\n", "NA", reparacion);
    else
    	printf("|%7s     |%7s     |  |\n", "NA", "SD");
    printf("%118s","|  ------------------------------------------------------------------------------------------------------------  |\n");
    printf("   |%114s","|\n");
    printf("   |  Detalle de la evaluacion:%87s","|\n");
    printf("   |%114s","|\n");
    printf("   |%41s %-6.2f%66s","Nota maxima (Parciales):", maxFloat(parciales, 3), "|\n");
    printf("   |%114s","|\n");
    printf("   |%41s %-6.2f%66s","Nota maxima (Practicos):", maxFloat(practicos, 4), "|\n");
    printf("   |%114s","|\n");
    printf("   |%57s %-2d%54s","Cantidad de notas aprobadas (Parciales):", cantidadAprobados(parciales, 3), "|\n");
    printf("   |%114s","|\n");
    printf("   |%57s %-2d%54s","Cantidad de notas aprobadas (Practicos):", cantidadAprobados(practicos, 4), "|\n");
    printf("   |%114s","|\n");
    printf("   |%26s%25s %-6.2f%32s %-6.2f%17s","SubTotal:","Notas practicas (20%):", notaPracticos, "Notas parciales (50%):", notaParciales, "|\n");
    printf("   |%114s","|\n");
    if(acumulados >= 3.5)
    	printf("   |  Total:%21s %-5.2f%13s %-5.2f%19s %-2.2f = %-2d (Final)%23s", "Notas (70%):", acumulados, "Nota (30%):", final * 0.3, "Def.:", definitiva, definitivaRedondeada, "|\n");
    else if(acumulados >= 2)
    	printf("   |  Total:%21s %-5.2f%13s %3s%21s %-2.2f = %-2d (Reparacion)%18s", "Notas (70%):", acumulados, "Nota (30%):", "NA", "Def.:", definitiva, definitivaRedondeada, "|\n");
	else
    	printf("   |  Total:%21s %-5.2f%13s %3s%21s %-2.2f = %-2d%31s", "Notas (70%):", acumulados, "Nota (30%):", "NA", "Def.:", definitiva, definitivaRedondeada,"|\n");
    printf("   |%114s","|\n");
    printf("%118s","------------------------------------------------------------------------------------------------------------------\n");
}

// Pide el nombre de la asignatura
void datosAsignatura(char asignatura[]) 
{
	printf("\n%118s","--------------------------------------------- Datos de la Asignatura ---------------------------------------------\n");
	printf("\n%72s","Ingrese el nombre de la asignatura: ");
    getString(asignatura);
}

// Pide los datos de un estudiante
int datosEstudiante(char nombre[], char apellido[]) 
{
	printf("\n%118s","---------------------------------------------- Datos del Estudiante ----------------------------------------------\n");
	printf("\n%64s","Ingrese el nombre: ");
    getString(nombre);
    printf("\n%66s","Ingrese el apellido: ");
    getString(apellido);
    printf("\n%64s","Ingrese la cedula: ");
    return getInt();
}

// Pide las notas de los practicos
void datosPracticos(float practicos[])
{
	printf("\n%118s","--------------------------------------------------- Practicos ----------------------------------------------------\n");
	printf("\n%73s", "Ingrese la nota del practico 1: ");
	practicos[0] = getFloat();
	printf("\n%73s", "Ingrese la nota del practico 2: ");
	practicos[1] = getFloat();
	printf("\n%73s", "Ingrese la nota del practico 3: ");
	practicos[2] = getFloat();
	printf("\n%73s", "Ingrese la nota del practico 4: ");
	practicos[3] = getFloat();
}

// Pide la nota de los parciales
void datosParciales(float parciales[]) 
{
	printf("\n%118s","--------------------------------------------------- Parciales ----------------------------------------------------\n");
	printf("\n%73s", "Ingrese la nota del parcial 1: ");
	parciales[0] = getFloat();
	printf("\n%73s", "Ingrese la nota del parcial 2: ");
	parciales[1] = getFloat();
	printf("\n%73s", "Ingrese la nota del parcial 3: ");
	parciales[2] = getFloat();
}

// Funcion principal para pedir y dar el reporte
void asignatura() 
{
	char asignatura[20];
	char nombre[10];
	char apellido[10];
	int cedula;
	float practicos[4];
	float parciales[3];
	float acumulado = 0;
	float final = 0;
	float reparacion = 0;
	float definitiva = 0;
	
	datosAsignatura(asignatura);
	cedula = datosEstudiante(nombre, apellido);
	datosPracticos(practicos);
	datosParciales(parciales);
	
	float notaParciales = averageFloat(parciales, 3) * 0.5;
	float notaPracticos = averageFloat(practicos, 4) * 0.2;
	acumulado = notaPracticos + notaParciales;
	if(acumulado >= 3.5) {
    	printf("\n%118s","------------------------------------------------------------------------------------------------------------------\n");
		printf("\n%71s","Ingrese la nota del final: ");
		final = getFloat();
		definitiva = acumulado + final * 0.3;
	} else if (acumulado >= 2) {
    	printf("\n%118s","------------------------------------------------------------------------------------------------------------------\n");
		printf("\n%74s","Ingrese la nota del reparacion: ");
		reparacion = getFloat();
		definitiva = reparacion;
	} else {
		definitiva = acumulado;
	}
	
	reporte(asignatura, nombre, apellido, cedula, parciales, practicos, notaParciales, notaPracticos, final, reparacion, definitiva);
}

// Menu y opciones
void menu() 
{	
    int opc = 0;
    do {
    	printf("\n%118s","----------------------------------------------------- Menu -------------------------------------------------------\n");
		printf("\n%73s", "(1) Ingresar nota de asignatura");
		printf("\n%51s", "(2) Salir");
	    printf("\n%70s","Opcion: ");
	    
	    do {
	    	opc = getInt();
	    	if(opc < 1 || opc > 2)
	    		printf("%70s", "Opcion invalida, ingrese de nuevo: ");
		} while (opc < 1 || opc > 2);
    	
		switch(opc) {
			case 1:
				asignatura();
				break;
			case 2:
				printf("\n%64s","HASTA LUEGO");
				break;
		}
	} while (opc != 2);
}

int main()
{
	menu();	
    return 0;
}