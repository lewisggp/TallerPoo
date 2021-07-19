/*
    Autor: Lewis Garcia
    Asignacion: 4
    Fecha: 18 de junio de 2021

    Programa que muestra reporte de notas de N asignaturas de un estudiante. Con Final / Reparacion o sin derecho a presentar
*/

#include <stdio.h>

int size(char c[])
{
	int i;
	for (i = 0; c[i] != '\0'; i++);
	return i;
}

int countValue(int n[], int size, int m)
{
	int c = 0;
	for (int i = 0; i < size; i++)
		if (n[i] == m)
			c++;
	return c;
}

int getIndex(int n[], int size, int m)
{
	int i;
	for (i = 0; i < size; i++)
		if (m == n[i])
			return i;
	return -1;
}

int maxInt(int n[], int size)
{
	int max = n[0];
	for (int i = 0; i < size; i++)
		if (max < n[i])
			max = n[i];
	return max;
}

float maxFloat(float n[], int size)
{
	float max = n[0];
	for (int i = 0; i < size; i++)
		if (max < n[i])
			max = n[i];
	return max;
}

float sumFloat(float n[], int size)
{
	float total = 0;
	for (int i = 0; i < size; i++)
		total += n[i];
	return total;
}

float averageFloat(float n[], int size)
{
	if (size == 0)
		return 0;
	return sumFloat(n, size) / size;
}

void join(char a[], char b[], char c[])
{
	int i = 0;
	for (int j = 0; a[j] != '\0'; j++)
		c[i++] = a[j];
	c[i++] = ' ';
	for (int j = 0; b[j] != '\0'; j++)
		c[i++] = b[j];
	c[i] = '\0';
}

int roundFloat(float n)
{
	int r = n * 10;
	if (r % 10 >= 5)
		return r / 10 + 1;
	else
		return r / 10;
}

float absoluteFloat(float n)
{
	return (n > 0) ? n : -n;
}

float powInt(float base, int exponent)
{
	if (exponent == 0)
		return 1;
	float r = base;
	for (int i = 1; i < absoluteFloat(exponent); i++)
		r *= base;
	return (exponent > 0) ? r : 1 / r;
}

bool isWord(char c[])
{
	int i;
	for (i = 0; c[i] != '\0' && ((c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= 'a' && c[i] <= 'z') || c[i] == ' '); i++);
	if (c[i] == '\0')
		return true;
	else
		return false;
}

bool isInt(char c[])
{
	int i;
	for (i = 0; c[i] != '\0' && c[i] >= '0' && c[i] <= '9'; i++);
	if (c[i] == '\0')
		return true;
	else
		return false;
}

bool isFloat(char c[])
{
	int i;
	int decimal = 0;
	if (!(c[0] >= '0' && c[0] <= '9' || c[0] == '-'))
		return false;
	for (i = 1; c[i] != '\0' && ((c[i] >= '0' && c[i] <= '9') || c[i] == '.' || c[i] == ','); i++)
		if (c[i] == '.' || c[i] == ',')
			decimal++;
	if (c[i] == '\0' && decimal <= 1)
		return true;
	else
		return false;
}

int toInt(char c)
{
	if (c == '0')
		return 0;
	if (c == '1')
		return 1;
	if (c == '2')
		return 2;
	if (c == '3')
		return 3;
	if (c == '4')
		return 4;
	if (c == '5')
		return 5;
	if (c == '6')
		return 6;
	if (c == '7')
		return 7;
	if (c == '8')
		return 8;
	if (c == '9')
		return 9;
	return -1;
}

int toInt(char c[])
{
	int i = 0, n = 0;
	if (c[0] == '-')
		i++;
	while (c[i] != '\0')
		n = n * 10 + toInt(c[i++]);
	return (c[0] == '-') ? -n : n;
}

float toFloat(char c[])
{
	float n = 0;
	int i = 0, j = 0;
	if (c[0] == '-')
		i++;
	while (c[i] == '0')
		i++;
	while (c[i] != '\0' && c[i] != '.' && c[i] != ',')
	{
		int k = toInt(c[i++]);
		if (k != -1)
			n = n * 10 + k;
		else
			n = n * 10;
	}
	if (c[i] != '\0')
		while (c[i] != '\0' && j <= 4)
		{
			int k = toInt(c[i++]);
			if (k != -1)
				n += k * powInt(10, -j++);
			else
				j++;
		}
	return (c[0] == '-') ? -n : n;
}

int getInt()
{
	char opc[20];
	bool repetir = true;
	do
	{
		scanf("%[^\n]s", &opc);
		fflush(stdin);
		if (isInt(opc))
			repetir = false;
		else
			printf("%75s", "Numero invalido, ingrese de nuevo: ");
	} while (repetir);
	return toInt(opc);
}

float getFloat()
{
	char opc[20];
	bool repetir = true;
	float f = -1;
	do
	{
		scanf("%[^\n]s", &opc);
		fflush(stdin);
		if (isFloat(opc))
		{
			f = toFloat(opc);
			if (f >= 0 && f <= 10)
				repetir = false;
			else
				printf("%75s", "Numero invalido, ingrese de nuevo: ");
		}
		else
			printf("%75s", "Numero invalido, ingrese de nuevo: ");
	} while (repetir);
	return f;
}

void getString(char c[])
{
	bool repetir = true;
	do
	{
		scanf("%[^\n]s", c);
		fflush(stdin);
		if (!isWord(c))
			printf("%72s", "Dato invalido, ingrese de nuevo: ");
		else
			repetir = false;
	} while (repetir);
}

int countGreaterThan(float n[], int size, float m)
{
	int c = 0;
	for (int i = 0; i < size; i++)
		if (n[i] >= m)
			c++;
	return c;
}

float moda(float n[], int size)
{
	int c[size]{0};
	for (int i = 0; i < size; i++)
		for (int j = 0; j <= i; j++)
			if (n[i] == n[j])
			{
				c[j]++;
				break;
			}
	int max = maxInt(c, size);
	int cMax = countValue(c, size, max);
	return (cMax == 1) ? n[getIndex(c, size, max)] : -1;
}

int compareTo(char a[], char b[])
{
	//Devuelve 1 si a es mayor que b, 2 si b es mayor que a, 0 si son iguales
	int i, v = 0;
	for (i = 0; v == 0 && a[i] != '\0' && b[i] != '\0'; i++)
	{
		if (a[i] > b[i])
			v = 1;
		else if (a[i] < b[i])
			v = 2;
	}
	if (v == 0)
	{
		if (a[i] == '\0' && b[i] == '\0')
			v = 0;
		else if (a[i] == '\0')
			v = 1;
		else if (b[i] == '\0')
			v = 2;
	}
	return v;
}

void toUppercase(char a[])
{
	for (int i = 0; a[i] != '\0'; i++)
		if (a[i] >= 'a' && a[i] <= 'z')
			a[i] -= 32;
}

void toLowercase(char a[])
{
	for (int i = 0; a[i] != '\0'; i++)
		if (a[i] >= 'A' && a[i] <= 'Z')
			a[i] += 32;
}

void toTitlecase(char a[])
{
	toLowercase(a);
	if (a[0] >= 'a' && a[0] <= 'z')
		a[0] -= 32;
}

// Clases
class Estudiante
{
	private:
		char nombre[10];
		char apellido[10];
		int cedula;

	public:
		void asignarDatos()
		{
			printf("\n%118s", "---------------------------------------------- Datos del Estudiante ----------------------------------------------\n");
			printf("\n%65s", "Ingrese el nombre: ");
			getString(nombre);
			toTitlecase(nombre);
			printf("\n%67s", "Ingrese el apellido: ");
			getString(apellido);
			toTitlecase(apellido);
			printf("\n%65s", "Ingrese la cedula: ");
			cedula = getInt();
		}

		char *getNombre()
		{
			return nombre;
		}

		char *getApellido()
		{
			return apellido;
		}

		int getCedula()
		{
			return cedula;
		}
};

class Asignatura
{
	private:
		char nombre[25];
		char codigo[8];

		float *practicos, notaParciales;
		float *parciales, notaPracticos;
		int cPracticos = 0, cParciales = 0;
		float final;
		float reparacion;
		float definitiva;

	public:
		void asignarDatos()
		{
			printf("\n%118s", "--------------------------------------------- Datos de la Asignatura ---------------------------------------------\n");
			printf("\n%72s", "Ingrese el nombre de la asignatura: ");
			getString(nombre);
			toTitlecase(nombre);
			printf("\n%72s", "Ingrese el codigo de la asignatura: ");
			leerCodigo();
		}

		void leerCodigo()
		{
			bool repetir = true;
			do
			{
				scanf("%[^\n]s", codigo);
				fflush(stdin);

				int s = size(codigo);
				if (s <= 7 && isInt(codigo))
				{
					for (int i = s - 1, j = 7; j >= 0; j--)
						if (j == 3)
							codigo[j] = '-';
						else if (i >= 0)
							codigo[j] = codigo[i--];
						else
							codigo[j] = '0';
					repetir = false;
				}
				else if (s == 8 && codigo[3] == '-')
				{
					int i;
					for (i = 0; codigo[i] != '\0' && (toInt(codigo[i]) != -1 || (i == 3 && codigo[i] == '-')); i++);
					if (codigo[i] == '\0')
						repetir = false;
				}
				else
					printf("%70s", "Codigo invalido, ingrese de nuevo: ");

				if (codigo[7] == '0')
				{
					printf("%76s", "Numero de creditos invalido, ingrese de nuevo: ");
					repetir = true;
				}
				codigo[8] = '\0';
			} while (repetir);
		}

		void leerNotasPracticos()
		{
			printf("\n%118s", "--------------------------------------------------- Practicos ----------------------------------------------------\n");

			do
			{
				printf("\n%75s", "Ingrese la cantidad de practicos: ");
				cPracticos = getInt();
				if (cPracticos == 0)
				{
					printf("\n%97s", "ADVERTENCIA: Si la cantidad es 0, se perdera el porcentaje correspondiente");
					printf("\n%73s", "Ingrese de nuevo la cantidad: ");
					cPracticos = getInt();
				}
				if (cPracticos >= 100)
					printf("%76s", "No puede ingresar tantos practicos");
			} while (cPracticos >= 100);

			practicos = new float[cPracticos];
			for (int i = 0; i < cPracticos; i++)
			{
				printf("\n%71s%1d%2s", "Ingrese la nota del parcial ", i + 1, ": ");
				practicos[i] = getFloat();
			}
		}

		void leerNotasParciales()
		{
			printf("\n%118s", "--------------------------------------------------- Parciales ----------------------------------------------------\n");

			do
			{
				printf("\n%75s", "Ingrese la cantidad de parciales: ");
				cParciales = getInt();
				if (cParciales == 0)
				{
					printf("\n%97s", "ADVERTENCIA: Si la cantidad es 0, se perdera el porcentaje correspondiente");
					printf("\n%73s", "Ingrese de nuevo la cantidad: ");
					cParciales = getInt();
				}
				if (cParciales >= 100)
					printf("\n%76s", "No puede ingresar tantos parciales");
			} while (cParciales >= 100);

			parciales = new float[cParciales];
			for (int i = 0; i < cParciales; i++)
			{
				printf("\n%71s%1d%2s", "Ingrese la nota del parcial ", i + 1, ": ");
				parciales[i] = getFloat();
			}
		}

		void calcularPromedio()
		{
			notaParciales = averageFloat(parciales, cParciales) * 0.5;
			notaPracticos = averageFloat(practicos, cPracticos) * 0.2;
		}

		void calcularDefinitiva()
		{
			float acumulado = notaPracticos + notaParciales;
			if (acumulado >= 3.5)
			{
				printf("\n%118s", "------------------------------------------------------------------------------------------------------------------\n");
				printf("\n%72s", "Ingrese la nota del final: ");
				final = getFloat();
				definitiva = acumulado + final * 0.3;
			}
			else if (acumulado >= 2)
			{
				printf("\n%118s", "------------------------------------------------------------------------------------------------------------------\n");
				printf("\n%75s", "Ingrese la nota del reparacion: ");
				reparacion = getFloat();
				definitiva = reparacion;
			}
			else
			{
				definitiva = acumulado;
			}
		}

		void mostrarReporte(Estudiante estudiante)
		{
			char nombreCompleto[20];
			join(estudiante.getNombre(), estudiante.getApellido(), nombreCompleto);
			float acumulados = notaParciales + notaPracticos;
			int definitivaRedondeada = getDefinitivaRedondeada();
			float modaPracticos = moda(practicos, cPracticos);
			float modaParciales = moda(parciales, cParciales);

			printf("\n%118s", "------------------------------------------------------------------------------------------------------------------\n");
			printf("   |%114s", "|\n");

			printf("   |%64s%50s", "Reporte de notas", "|\n");
			printf("   |%114s", "|\n");

			printf("   |  Estudiante: %-30s %3s %-10i %25s %-25s |\n", nombreCompleto, "CI:", estudiante.getCedula(), "Asignatura:", nombre);
			printf("   |%114s", "|\n");

			// IMPRIMIR NOTAS
			int i = 0;				   // Numero de columna actual
			int j = 0;				   // Numero de caracter horizontal actual
			int contPracticos = 0;	   // Contador de nombre de practicos escritos
			int contNotaPracticos = 0; // Contador de nota de practicos escritos
			int contParciales = 0;	   // Contador de nombre de parciales escritos
			int contNotaParciales = 0; // Contador de nota de parciales escritos
			while (contPracticos < cPracticos || contParciales < cParciales)
			{

				int kPracticos = 0; // Cuantos practicos se van a escribir en este bucle
				int kParciales = 0; // Cuantos parciales se van a escribir en este bucle
				for (i = 0, kPracticos = contPracticos; kPracticos < cPracticos && i < 9; i++, kPracticos++);
				for (i = i, kParciales = contParciales; kParciales < cParciales && i < 9; i++, kParciales++);

				printf("   |  -");
				if (i == 9)
				{
					printf("-----------------------------------------------------------------------------------------------------------");
					j = 108;
				}
				else if (i == 8)
				{
					printf("------------------------------------------------------------------------------------------------");
					j = 97;
				}
				else
					for (j = 1; j < i * 12 + 24; j++)
						printf("-");
				for (j = j; j < 110; j++)
					printf(" ");
				printf("|\n");

				for (i = 0, contPracticos = contPracticos; contPracticos < cPracticos && i < 9; i++, contPracticos++)
				{
					if (i == 0)
						printf("   |  ");
					if (i == 8)
						printf("|%8s%-2d|  |\n", "Practico", contPracticos + 1);
					else if (contPracticos + 1 == cPracticos && contParciales == cParciales && i == 7)
						printf("| %8s%-2d|             |\n", "Practico", contPracticos + 1);
					else
						printf("| %8s%-2d", "Practico", contPracticos + 1);
				}
				for (i = i, contParciales = contParciales; contParciales < cParciales && i < 9; i++, contParciales++)
				{
					if (i == 0)
						printf("   |  ");
					if (i == 8)
						printf("| %7s%-2d|  |\n", "Parcial", contParciales + 1);
					else if (contParciales + 1 == cParciales && i == 7)
						printf("| %7s%-2d |             |\n", "Parcial", contParciales + 1);
					else
						printf("| %7s%-2d ", "Parcial", contParciales + 1);
				}
				if (i <= 7 && !(contPracticos < cPracticos || contParciales < cParciales))
				{
					printf("|  Final  | Reparacion |");
					for (j = i * 12 + 24; j < 110; j++)
						printf(" ");
					printf("|\n");
				}

				printf("   |  |");
				if (i == 9)
				{
					printf("----------------------------------------------------------------------------------------------------------");
					j = 107;
				}
				else if (i == 8)
				{
					printf("-----------------------------------------------------------------------------------------------");
					j = 96;
				}
				else
					for (j = 1; j < i * 12 + 23; j++)
						printf("-");
				printf("|");
				for (j = j; j < 109; j++)
					printf(" ");
				printf("|\n");

				for (i = 0, contNotaPracticos = contNotaPracticos; contNotaPracticos < cPracticos && i < 9; i++, contNotaPracticos++)
				{
					if (i == 0)
						printf("   |  ");
					if (i == 8)
						printf("|%7.2f   |  |\n", practicos[contNotaPracticos]);
					else if (contNotaPracticos + 1 == cPracticos && contNotaParciales == cParciales && i == 7)
						printf("|%8.2f   |             |\n", practicos[contNotaPracticos]);
					else
						printf("|%8.2f   ", practicos[contNotaPracticos]);
				}
				for (i = i, contNotaParciales = contNotaParciales; contNotaParciales < cParciales && i < 9; i++, contNotaParciales++)
				{
					if (i == 0)
						printf("   |  ");
					if (i == 8)
						printf("|%7.2f   |  |\n", parciales[contNotaParciales]);
					else if (contNotaParciales + 1 == cParciales && i == 7)
						printf("|%8.2f   |             |\n", parciales[contNotaParciales]);
					else
						printf("|%8.2f   ", parciales[contNotaParciales]);
				}

				if ((contPracticos < cPracticos || contParciales < cParciales) || i >= 8)
				{
					printf("   |  -");
					if (i == 9)
					{
						printf("-----------------------------------------------------------------------------------------------------------");
						j = 108;
					}
					else if (i == 8)
					{
						printf("------------------------------------------------------------------------------------------------");
						j = 97;
					}
					else
						for (j = 0; j < i * 12 + 23; j++)
							printf("-");
					for (j = j; j < 110; j++)
						printf(" ");
					printf("|\n");
					printf("   |%114s", "|\n");
				}
			}

			if (i >= 8 || (cPracticos == 0 && cParciales == 0))
			{
				printf("   |  ------------------------                                                                                      |\n");
				printf("   |  |  Final  | Reparacion |                                                                                      |\n");
				printf("   |  |----------------------|                                                                                      |\n");
				printf("   |  ");
				i = 0;
			}

			if (acumulados >= 3.50)
				printf("|%7.2f  |%7s     |", final, "NA");
			else if (acumulados >= 2)
				printf("|%6s   |%8.2f    |", "NA", reparacion);
			else
				printf("|%6s   |%7s     |", "NA", "SD");

			for (j = i * 12 + 24; j < 110; j++)
				printf(" ");
			printf("|\n");

			printf("   |  ");
			for (j = 0; j < i * 12 + 24; j++)
				printf("-");
			for (j = j; j < 108; j++)
				printf(" ");
			printf("  |\n");
			printf("   |%114s", "|\n");
			// FIN IMPRIMIR NOTAS

			printf("   |  Detalle de la evaluacion:%87s", "|\n");
			printf("   |%114s", "|\n");

			printf("   |%41s %-6.2f%66s", "Nota maxima (Parciales):", maxFloat(parciales, cParciales), "|\n");
			printf("   |%114s", "|\n");

			printf("   |%41s %-6.2f%66s", "Nota maxima (Practicos):", maxFloat(practicos, cPracticos), "|\n");
			printf("   |%114s", "|\n");

			printf("   |%57s %-2d%54s", "Cantidad de notas aprobadas (Parciales):", countGreaterThan(parciales, cParciales, 5), "|\n");
			printf("   |%114s", "|\n");

			printf("   |%57s %-2d%54s", "Cantidad de notas aprobadas (Practicos):", countGreaterThan(practicos, cPracticos, 5), "|\n");
			printf("   |%114s", "|\n");

			if (modaPracticos >= 0)
				printf("   |%35s %-5.2f", "Moda en Practicos:", modaPracticos);
			else
				printf("   |%35s %-5s", "Moda en Practicos:", "N/A");
			if (modaParciales >= 0)
				printf("%21s %-5.2f%46s", "Moda en Parciales:", modaParciales, "|\n");
			else
				printf("%21s %-5s%46s", "Moda en Parciales:", "N/A", "|\n");
			printf("   |%114s", "|\n");

			printf("   |%26s%25s %-6.2f%32s %-6.2f%17s", "SubTotal:", "Notas practicas (20%):", notaPracticos, "Notas parciales (50%):", notaParciales, "|\n");
			printf("   |%114s", "|\n");

			if (acumulados >= 3.5)
				printf("   |  Total:%21s %-5.2f%13s %-5.2f%19s %-5.2f = %-2d (Final)%22s", "Notas (70%):", acumulados, "Nota (30%):", final * 0.3, "Def.:", definitiva, definitivaRedondeada, "|\n");
			else if (acumulados >= 2)
				printf("   |  Total:%21s %-5.2f%13s %3s%21s %5.2f = %-2d (Reparacion)%17s", "Notas (70%):", acumulados, "Nota (30%):", "NA", "Def.:", definitiva, definitivaRedondeada, "|\n");
			else
				printf("   |  Total:%21s %-5.2f%13s %3s%21s %5.2f = %-2d%30s", "Notas (70%):", acumulados, "Nota (30%):", "NA", "Def.:", definitiva, definitivaRedondeada, "|\n");
			printf("   |%114s", "|\n");

			printf("%118s", "------------------------------------------------------------------------------------------------------------------\n");
		}

		char *getNombre()
		{
			return nombre;
		}

		char *getCodigo()
		{
			return codigo;
		}

		int getDefinitivaRedondeada()
		{
			return roundFloat(definitiva);
		}

		int getCreditos()
		{
			int n = toInt(codigo[7]);
			return n;
		}
};

void order(Asignatura asignaturas[], int n)
{
	int i, cambio;
	Asignatura aux;
	do
	{
		cambio = 0;
		for (i = 0; i < n - 1; i++)
			if (compareTo(asignaturas[i].getNombre(), asignaturas[i + 1].getNombre()) == 1) {				
				aux = asignaturas[i];
				asignaturas[i] = asignaturas[i + 1];
				asignaturas[i + 1] = aux;
				cambio = 1;
			}
	} while (cambio == 1);
}

bool exist(Asignatura asignaturas[], int n, char codigo[])
{
	for (int i = 0; i < n; i++)
		if (compareTo(asignaturas[i].getCodigo(), codigo) == 0)
			return true;
	return false;
}

// Menu y opciones
void menu()
{
	int opc = 0;
	int cAsignaturas = 0;
	Asignatura asignaturas[30];
	char periodo[25];
	int agno;
	Estudiante estudiante;
	estudiante.asignarDatos();

	// Leer semestre
	printf("\n%118s", "---------------------------------------------- Datos de la Semestre ----------------------------------------------\n");

	printf("\n%62s%c%3s", "Ingrese el a", 164, "o: ");
	do
	{
		agno = getInt();
		if (agno <= 0 || agno > 9999)
			printf("%43s%c%30s", "A", 164, "o invalido, ingrese de nuevo: ");
	} while (agno <= 0 || agno > 9999);

	printf("\n%70s", "Ingrese el periodo: ");
	bool repetir = true;
	do
	{
		repetir = false;
		scanf("%[^\n]s", periodo);
		fflush(stdin);

		if (isInt(periodo))
		{
			int nPeriodo = toInt(periodo);
			if (nPeriodo == 1)
			{
				periodo[0] = 'I';
				periodo[1] = '\0';
			}
			else if (nPeriodo == 2)
			{
				periodo[0] = 'I';
				periodo[1] = 'I';
				periodo[2] = '\0';
			}
			else if (nPeriodo == 3)
			{
				periodo[0] = 'I';
				periodo[1] = 'I';
				periodo[2] = 'I';
				periodo[3] = '\0';
			}
			else
				repetir = true;
		}
		else
		{
			int i = 0;
			for (i = 0; i < 3 && periodo[i] != '\0'; i++)
				if (!(periodo[i] == 'I' || periodo[i] == 'i'))
				{
					repetir = true;
					break;
				}
			if (periodo[i] != '\0')
				repetir = true;
		}

		if (repetir)
			printf("%76s", "Periodo invalido, ingrese de nuevo: ");
	} while (repetir);
	toUppercase(periodo);

	// Menu
	do
	{
		printf("\n%118s", "----------------------------------------------------- Menu -------------------------------------------------------\n");
		printf("\n%73s", "(1) Ingresar nota de asignatura");
		printf("\n%79s", "(2) Mostrar Listado de Calificaciones");
		printf("\n%79s", "(3) Mostrar Reporte de una Asignatura");
		printf("\n%51s", "(4) Salir");
		printf("\n%70s", "Opcion: ");

		do
		{
			opc = getInt();
			if (opc < 1 || opc > 4)
				printf("%70s", "Opcion invalida, ingrese de nuevo: ");
		} while (opc < 1 || opc > 4);

		switch (opc)
		{
			case 1:
			{
				cAsignaturas++;
				asignaturas[cAsignaturas - 1].asignarDatos();
				if (exist(asignaturas, cAsignaturas - 1, asignaturas[cAsignaturas - 1].getCodigo()))
				{
					printf("%78s", "Este codigo de asignatura ya esta evaluado");
					cAsignaturas--;
				}
				else
				{
					asignaturas[cAsignaturas - 1].leerNotasPracticos();
					asignaturas[cAsignaturas - 1].leerNotasParciales();
					asignaturas[cAsignaturas - 1].calcularPromedio();
					asignaturas[cAsignaturas - 1].calcularDefinitiva();
					asignaturas[cAsignaturas - 1].mostrarReporte(estudiante);
					order(asignaturas, cAsignaturas);
				}
			}
			break;

			case 2:
			{
				char nombreCompleto[20];
				join(estudiante.getNombre(), estudiante.getApellido(), nombreCompleto);

				printf("\n%118s", "------------------------------------------------------------------------------------------------------------------\n");
				printf("   |%114s", "|\n");

				printf("   |%68s %45s", "Listado de Calificaciones", "|\n");
				printf("   |%114s", "|\n");

				printf("   |  Estudiante: %-30s %3s %-10i %23s %3s - %-4d                  |\n", nombreCompleto, "CI:", estudiante.getCedula(), "Semestre:", periodo, agno);
				printf("   |%114s", "------------------------------------------------------------------------------------------------------------  |\n");
				printf("   |%114s", "|\n");

				printf("   |  %-35s%-45s%-30s|\n", "Asignatura", "Codigo", "Calificacion");
				printf("   |%114s", "|\n");

				for (int i = 0; i < cAsignaturas; i++)
					printf("   |  %-35s%-50s%-25d|\n", asignaturas[i].getNombre(), asignaturas[i].getCodigo(), asignaturas[i].getDefinitivaRedondeada());
				printf("   |%114s", "|\n");

				printf("   |%114s", "------------------------------------------------------------------------------------------------------------  |\n");
				float promedioGeneral = 0;
				float sumatoria = 0;
				float totalCreditos = 0;
				for (int i = 0; i < cAsignaturas; i++)
				{
					float creditoTemp = asignaturas[i].getCreditos();
					sumatoria += creditoTemp * asignaturas[i].getDefinitivaRedondeada();
					totalCreditos += creditoTemp;
				}
				if (cAsignaturas != 0)
					promedioGeneral = sumatoria / totalCreditos;

				printf("   |  Promedio General: %-5.2f%89s", promedioGeneral, "|\n");
				printf("   |%114s", "|\n");

				printf("%118s", "------------------------------------------------------------------------------------------------------------------\n");
			}
			break;

			case 3:
			{
				Asignatura asignatura;
				printf("\n%74s", "Ingrese el codigo de la asignatura: ");
				asignatura.leerCodigo();

				if (exist(asignaturas, cAsignaturas, asignatura.getCodigo()))
					for (int i = 0; i < cAsignaturas; i++)
						if (compareTo(asignaturas[i].getCodigo(), asignatura.getCodigo()) == 0)
						{
							asignaturas[i].mostrarReporte(estudiante);
							break;
						}
				else
					printf("%81s", "Este codigo de asignatura no esta registrado");
			}
			break;

			case 4:
			{
				printf("\n%64s", "HASTA LUEGO");
			}
			break;
		}
	} while (opc != 4);
}

int main()
{
	menu();
	return 0;
}
