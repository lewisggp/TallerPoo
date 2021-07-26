/*
    Autor: Lewis Garcia
    Asignacion: 5
    Fecha: 26 de julio de 2021

    Programa de reportes de notas de asignaturas de un estudiante
*/

#include <stdio.h>

int size(char c[])
{
	int i;
	for (i = 0; c[i] != '\0'; i++)
		;
	return i;
}

void copy(char a[], char b[])
{
	int i;
	for (i = 0; a[i] != '\0'; i++)
	{
		b[i] = a[i];
	}
	b[i] = '\0';
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
	for (i = 0; c[i] != '\0' && ((c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= 'a' && c[i] <= 'z') || c[i] == ' '); i++)
		;
	if (c[i] == '\0')
		return true;
	else
		return false;
}

bool isInt(char c[])
{
	int i;
	for (i = 0; c[i] != '\0' && c[i] >= '0' && c[i] <= '9'; i++)
		;
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

		if (opc[0] == '\0' || isInt(opc))
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

		if (opc[0] == '\0' || isFloat(opc))
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

		if (c[0] == '\0' || !isWord(c))
			printf("%72s", "Dato invalido, ingrese de nuevo: ");
		else
			repetir = false;
	} while (repetir);
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
class Nota
{
	private:
		float nota;
		int porcentaje;

	public:
		void setNota(float n)
		{
			nota = n;
		}

		void setPorcentaje(int p)
		{
			porcentaje = p;
		}

		float getNota()
		{
			return nota;
		}

		int getPorcentaje()
		{
			return porcentaje;
		}
};

int imprimirModas(Nota n[], int size)
{
	if (size == 0)
		return 0;

	int c[size]{0};
	for (int i = 0; i < size; i++)
		for (int j = 0; j <= i; j++)
			if (n[i].getNota() == n[j].getNota())
			{
				c[j]++;
				break;
			}
	int max = maxInt(c, size);
	int cMax = countValue(c, size, max);

	for(int i = 0, j = 0; i < size; i++)
		if(c[i] == max)
		{
			printf("%-5.2f", n[i].getNota());
			if(++j != cMax) printf(", ");
		}
	return cMax;
}

int indexMaxNota(Nota n[], int size)
{
	if (size == 0)
		return -1;

	int iMax = 0;
	Nota max = n[0];
	for (int i = 0; i < size; i++)
		if (max.getNota() < n[i].getNota())
		{
			max = n[i];
			iMax = i;
		}
	return iMax;
}

int notasAprovadas(Nota n[], int size)
{
	int c = 0;
	for (int i = 0; i < size; i++)
		if (n[i].getNota() >= 5)
			c++;
	return c;
}

float sumaNotas(Nota n[], int size)
{
	float total = 0;
	for (int i = 0; i < size; i++)
		total += n[i].getNota() * n[i].getPorcentaje() / 100;
	return total;
}

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
	protected:
		static const int MAX = 100;
		static const int MAX_PRERRE = 2;
		static const int PORC_PARCI = 50;
		static const int PORC_PRACT = 20;
		static const int PORC_FINAL = 30;

		char nombre[25];
		char codigo[8];

		int cantidadPrerrequisitos = 0;
		char prerrequisitos[2][9];

		char periodo[3];
		int agno;
		char area[25];

		Nota practicos[MAX], parciales[MAX];
		float notaPracticos, notaParciales;
		int cPracticos = 0, porc_pract_acum = 0, cParciales = 0, porc_parci_acum = 0;

		float final;
		float reparacion;
		float definitiva;
		int estado = 0;

	public:
		void asignarDatos()
		{
			printf("\n%118s", "--------------------------------------------- Datos de la Asignatura ---------------------------------------------\n");
			leerNombre();
			leerCodigo();
		}

		void leerNombre()
		{
			printf("\n%72s", "Ingrese el nombre de la asignatura: ");
			getString(nombre);
			toTitlecase(nombre);
		}

		void leerCodigo(char c[])
		{
			bool repetir = true;
			do
			{
				scanf("%[^\n]s", c);
				fflush(stdin);
				repetir = true;

				int s = size(c);
				if (c[s - 1] == '0')
				{
					printf("%76s", "Numero de creditos invalido, ingrese de nuevo: ");
					repetir = true;
				}
				else if (s > 0 && s <= 7 && isInt(c))
				{
					for (int i = s - 1, j = 7; j >= 0; j--)
						if (j == 3)
							c[j] = '-';
						else if (i >= 0)
							c[j] = c[i--];
						else
							c[j] = '0';
					repetir = false;
				}
				else if (s == 8 && c[3] == '-')
				{
					int i;
					for (i = 0; c[i] != '\0' && (toInt(c[i]) != -1 || (i == 3 && c[i] == '-')); i++);
					if (c[i] == '\0')
						repetir = false;
				}
				else
					printf("%70s", "Codigo invalido, ingrese de nuevo: ");				
				c[8] = '\0';
			} while (repetir);
		}

		void leerCodigo()
		{
			printf("\n%72s", "Ingrese el codigo de la asignatura: ");
			leerCodigo(codigo);
		}

		void leerPrerrequisitos()
		{
			printf("\n%118s", "------------------------------------------------- PRERREQUISITOS -------------------------------------------------\n");

			do
			{
				printf("\n%75s", "Ingrese la cantidad de prerrequisitos: ");
				cantidadPrerrequisitos = getInt();
				if (cantidadPrerrequisitos < 0 || cantidadPrerrequisitos > MAX_PRERRE)
					printf("%77s", "Cantidad de prerrequisitos invalido");
			} while (cantidadPrerrequisitos < 0 || cantidadPrerrequisitos > MAX_PRERRE);

			for (int i = 0; i < cantidadPrerrequisitos; i++)
			{
				bool invalido = true;
				do
				{
					printf("\n%73s%-2i%2s", "Ingrese el prerrequisito ", i + 1, ": ");
					leerCodigo(prerrequisitos[i]);
					if (compareTo(codigo, prerrequisitos[i]) == 0)
						printf("%82s", "Codigo invalido. Identico al de la asignatura");
					else
						invalido = false;
				} while (invalido);
			}
		}

		void leerNotasPracticos()
		{
			printf("\n%118s", "--------------------------------------------------- Practicos ----------------------------------------------------\n");
			cPracticos = 0;
			porc_pract_acum = 0;
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
				if (cPracticos >= MAX)
					printf("%76s", "No puede ingresar tantos practicos");
			} while (cPracticos >= MAX);

			for (int i = 0; i < cPracticos; i++)
			{
				leerNotaPractico(i + 1);
				int p;
				if (i + 1 != cPracticos)
				{
					do
					{
						printf("\n%77s", "Ingrese el porcentaje del practico: ");
						p = getInt();
						if (p < 0)
							printf("%68s", "Porcentaje invalido");
						else if (p > PORC_PRACT - porc_pract_acum)
							printf("%83s\n", "El porcentaje acumulado es mayor al porcentaje");
					} while (p < 0 || p > PORC_PRACT - porc_pract_acum);
				}
				else
					p = PORC_PRACT - porc_pract_acum;
				porc_pract_acum += p;
				practicos[i].setPorcentaje(p);
			}
		}

		void leerNotaPractico(int numero)
		{
			if (numero < 0 || numero > cPracticos)
				return;
			float n;
			do
			{
				printf("\n%71s%1d%2s", "Ingrese la nota del practico ", numero, ": ");
				n = getFloat();
				if (n < 0 || n > 10)
					printf("%65s", "Nota invalida");
			} while (n < 0 || n > 10);
			practicos[numero - 1].setNota(n);
		}

		void leerNotasParciales()
		{
			printf("\n%118s", "--------------------------------------------------- Parciales ----------------------------------------------------\n");
			cParciales = 0;
			porc_parci_acum = 0;
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
				if (cParciales >= MAX)
					printf("%76s", "No puede ingresar tantos parciales");
			} while (cParciales >= MAX);

			for (int i = 0; i < cParciales; i++)
			{
				leerNotaParcial(i + 1);
				int p;
				if (i + 1 != cParciales)
				{
					do
					{
						printf("\n%77s", "Ingrese el porcentaje del practico: ");
						p = getInt();
						if (p < 0)
							printf("%68s", "Porcentaje invalido");
						else if (p > PORC_PARCI - porc_parci_acum)
							printf("%83s\n", "El porcentaje acumulado es mayor al porcentaje");
					} while (p < 0 || p > PORC_PARCI - porc_parci_acum);
				}
				else
					p = PORC_PARCI - porc_parci_acum;
				porc_parci_acum += p;
				parciales[i].setPorcentaje(p);
			}
		}

		void leerNotaParcial(int numero)
		{
			if (numero < 0 || numero > cParciales)
				return;
			float n;
			do
			{
				printf("\n%70s%1d%2s", "Ingrese la nota del parcial ", numero, ": ");
				n = getFloat();
				if (n < 0 || n > 10)
					printf("%65s", "Nota invalida");
			} while (n < 0 || n > 10);
			parciales[numero - 1].setNota(n);
		}

		void leerPeriodo()
		{
			printf("\n%118s", "----------------------------------------------- Datos del Periodo ------------------------------------------------\n");

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

				if (periodo[0] == '\0')
					repetir = true;
				else if (isInt(periodo))
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
		}

		void leerAreaConocimiento()
		{
			printf("\n%118s", "---------------------------------------------- AREA DE CONOCIMIENTO ----------------------------------------------\n");
			printf("\n%72s", "Ingrese el area de conocimiento: ");
			getString(area);
			toTitlecase(area);
		}

		void calcularDefinitiva(bool force)
		{
			// 0: Sin derecho, 1: Reparacion, 2: Final, 3: Final con Reparacion
			notaParciales = sumaNotas(parciales, cParciales);
			notaPracticos = sumaNotas(practicos, cPracticos);
			float acumulado = notaParciales + notaPracticos;
			int estadoTemp = 0;
			if(acumulado >= 3.5) estadoTemp = 2;
			else if(acumulado >= 2) estadoTemp = 1;

			if(force || (estado == 3 && estadoTemp != 2) || (estado != 3 && estadoTemp != estado)) {
				estado = 0;
				if (acumulado >= 3.5)
				{
					printf("\n%118s", "------------------------------------------------------------------------------------------------------------------\n");
					printf("\n%72s", "Ingrese la nota del final: ");
					final = getFloat();
					definitiva = acumulado + final * 0.3;
					estado = 2;
				}
				if((estado == 2 && definitiva < 4.5) || (estado != 2 && acumulado >= 2 && acumulado < 4.5))
				{
					printf("\n%118s", "------------------------------------------------------------------------------------------------------------------\n");
					printf("\n%75s", "Ingrese la nota del reparacion: ");
					reparacion = getFloat();
					definitiva = reparacion;
					estado = (estado == 2) ? 3 : 1;
				}
			}
			
			if(estado == 3) {
				definitiva = reparacion;
			} else if (estado == 2) {
				definitiva = acumulado + final * 0.3;
			} else if (estado == 1) {
				definitiva = reparacion;
			} else if (estado == 0) {
				definitiva = acumulado;
			}
		}

		float getAcumulado() {
			return notaPracticos + notaParciales;
		}

		char *getNombre()
		{
			return nombre;
		}

		char *getCodigo()
		{
			return codigo;
		}

		char *getPeriodo()
		{
			return periodo;
		}

		char *getPrerrequisito(int numero)
		{
			if (numero < 1 || numero > cantidadPrerrequisitos)
				return new char{'\0'};
			return prerrequisitos[numero - 1];
		}

		int getAgno()
		{
			return agno;
		}

		int getDefinitivaRedondeada()
		{
			return roundFloat(definitiva);
		}

		int getCreditos()
		{
			return toInt(codigo[7]);
		}

		char *getAreaConocimiento()
		{
			return area;
		}

		int getCPracticos()
		{
			return cPracticos;
		}

		int getCParciales()
		{
			return cParciales;
		}

		int getCPrerrequisitos()
		{
			return cantidadPrerrequisitos;
		}

		int getEstado()
		{
			return estado;
		}

		void mostrarNotas()
		{
			// IMPRIMIR NOTAS
			int i = 0;			   // Numero de columna actual
			int j = 0;			   // Numero de caracter horizontal actual
			int contPracticos = 0; // Contador de practicos escritos
			int contParciales = 0; // Contador de parciales escritos
			bool seguir = true;
			while (seguir)
			{
				int kPracticos = 0; // Cuantos practicos se van a escribir en este bucle
				int kParciales = 0; // Cuantos parciales se van a escribir en este bucle
				for (i = 0, kPracticos = 0; kPracticos + contPracticos < cPracticos && i < 9; i++, kPracticos++)
					;
				for (i = i, kParciales = 0; kParciales + contParciales < cParciales && i < 9; i++, kParciales++)
					;

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
				{
					for (j = 1; j < i * 12 + 24; j++)
						printf("-");
				}

				for (j = j; j < 110; j++)
					printf(" ");
				printf("|\n");

				for (i = 0; i < kPracticos; i++)
				{
					if (i == 0)
						printf("   |  ");
					if (i == 8)
						printf("|%8s%-2d|  |\n", "Practico", contPracticos + i + 1);
					else if (contPracticos + i + 1 == cPracticos && contParciales == cParciales && i == 7)
						printf("| %8s%-2d|             |\n", "Practico", contPracticos + i + 1);
					else
						printf("| %8s%-2d", "Practico", contPracticos + i + 1);
				}
				for (i = i; i - kPracticos < kParciales; i++)
				{
					if (i == 0)
						printf("   |  ");
					if (i == 8)
						printf("| %7s%-2d|  |\n", "Parcial", contParciales + i - kPracticos + 1);
					else if (contParciales + i - kPracticos + 1 == cParciales && i == 7)
						printf("| %7s%-2d |             |\n", "Parcial", contParciales + i - kPracticos + 1);
					else
						printf("| %7s%-2d ", "Parcial", contParciales + i - kPracticos + 1);
				}
				if (i <= 7 && !(contPracticos + kPracticos < cPracticos || contParciales + kParciales < cParciales))
				{
					if (i == 0)
						printf("   |  ");
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
				{
					for (j = 1; j < i * 12 + 23; j++)
						printf("-");
				}

				printf("|");
				for (j = j; j < 109; j++)
					printf(" ");
				printf("|\n");

				for (i = 0; i < kPracticos; i++)
				{
					if (i == 0)
						printf("   |  ");
					if (i == 8)
						printf("|%7.2f   |  |\n", practicos[contPracticos + i].getNota());
					else if (contPracticos + i + 1 == cPracticos && contParciales == cParciales && i == 7)
						printf("|%8.2f   |             |\n", practicos[contPracticos + i].getNota());
					else
						printf("|%8.2f   ", practicos[contPracticos + i].getNota());
				}
				for (i = i; i - kPracticos < kParciales; i++)
				{
					if (i == 0)
						printf("   |  ");
					if (i == 8)
						printf("|%7.2f   |  |\n", parciales[contParciales + i - kPracticos].getNota());
					else if (contParciales + i - kPracticos + 1 == cParciales && i == 7)
						printf("|%8.2f   |             |\n", parciales[contParciales + i - kPracticos].getNota());
					else
						printf("|%8.2f   ", parciales[contParciales + i - kPracticos].getNota());
				}
				if (i <= 7 && !(contPracticos + kPracticos < cPracticos || contParciales + kParciales < cParciales))
				{
					if (i == 0)
						printf("   |  ");
					if (estado == 3)
						printf("|%7.2f  |%8.2f    |", final, reparacion);
					else if (estado == 2)
						printf("|%7.2f  |%7s     |", final, "NA");
					else if (estado == 1)
						printf("|%6s   |%8.2f    |", "NA", reparacion);
					else if (estado == 0)
						printf("|%6s   |%7s     |", "NA", "SD");
					for (j = i * 12 + 24; j < 110; j++)
						printf(" ");
					printf("|\n");
				}

				for (i = 0; i < kPracticos; i++)
				{
					if (i == 0)
						printf("   |  ");
					if (i == 8)
						printf("|%5i%%    |  |\n", practicos[contPracticos + i].getPorcentaje());
					else if (contPracticos + i + 1 == cPracticos && contPracticos == cParciales && i == 7)
						printf("|%6i%%    |             |\n", practicos[contPracticos + i].getPorcentaje());
					else
						printf("|%6i%%    ", practicos[contPracticos + i].getPorcentaje());
				}
				for (i = i; i - kPracticos < kParciales; i++)
				{
					if (i == 0)
						printf("   |  ");
					if (i == 8)
						printf("|%5i%%    |  |\n", parciales[contParciales + i - kPracticos].getPorcentaje());
					else if (contParciales + i - kPracticos + 1 == cParciales && i == 7)
						printf("|%6i%%    |             |\n", parciales[contParciales + i - kPracticos].getPorcentaje());
					else
						printf("|%6i%%    ", parciales[contParciales + i - kPracticos].getPorcentaje());
				}
				if (i <= 7 && !(contPracticos + kPracticos < cPracticos || contParciales + kParciales < cParciales))
				{
					if (i == 0)
						printf("   |  ");
					if (estado == 3)
						printf("|%5i%%   |    100%%    |", PORC_FINAL);
					else if (estado == 2)
						printf("|%5i%%   |            |", PORC_FINAL);
					else if (estado == 1)
						printf("|         |    100%%    |");
					else if (estado == 0)
						printf("|         |            |");
					for (j = i * 12 + 24; j < 110; j++)
						printf(" ");
					printf("|\n");
					seguir = false;
				}

				printf("   |  ");
				if (i == 9)
				{
					for (j = 0; j < 108; j++)
						printf("-");
				}
				else if (i == 8)
				{
					for (j = 0; j < 97; j++)
						printf("-");
				}
				else
				{
					for (j = 0; j < i * 12 + 24; j++)
						printf("-");
				}

				for (j = j; j < 110; j++)
					printf(" ");
				printf("|\n");
				printf("   |%114s", "|\n");

				contPracticos += kPracticos;
				contParciales += kParciales;
			}
			// FIN IMPRIMIR NOTAS
		}

		void mostrarDetalles()
		{
			float acumulados = notaParciales + notaPracticos;
			int definitivaRedondeada = getDefinitivaRedondeada();

			printf("   |  Detalle de la evaluacion:%87s", "|\n");
			printf("   |%114s", "|\n");

			int indexParcialMaximo = indexMaxNota(parciales, cParciales);
			if(indexParcialMaximo != -1) printf("   |%41s %-6.2f%29s%-2i%35s", "Nota maxima (Parciales):", parciales[indexParcialMaximo].getNota(), "Nro. Parcial: ", indexParcialMaximo + 1, "|\n");
			else printf("   |%41s %-6s%29s%-3s%34s", "Nota maxima (Parciales):", "N/A", "Nro. Parcial: ", "N/A", "|\n");
			printf("   |%114s", "|\n");

			int indexPracticoMaximo = indexMaxNota(practicos, cPracticos);
			if(indexPracticoMaximo != -1) printf("   |%41s %-6.2f%30s%-2i%34s", "Nota maxima (Practicos):", practicos[indexPracticoMaximo].getNota(), "Nro. Practico: ", indexPracticoMaximo + 1, "|\n");
			else printf("   |%41s %-6s%30s%-3s%33s", "Nota maxima (Practicos):", "N/A", "Nro. Practico: ", "N/A", "|\n");
			printf("   |%114s", "|\n");

			printf("   |%57s %-2d%54s", "Cantidad de notas aprobadas (Parciales):", notasAprovadas(parciales, cParciales), "|\n");
			printf("   |%114s", "|\n");

			printf("   |%57s %-2d%54s", "Cantidad de notas aprobadas (Practicos):", notasAprovadas(practicos, cPracticos), "|\n");
			printf("   |%114s", "|\n");

			printf("   |%35s ", "Moda en Practicos:");
			int cModasPracticos = imprimirModas(practicos, cPracticos);
			if(cModasPracticos == 0) printf("N/A%24s", "");
			else for(int x = cModasPracticos * 7 - 2; x < 27; x++) printf(" ");
			printf("%21s ", "Moda en Parciales:");
			int cModasParciales = imprimirModas(parciales, cParciales);
			if(cModasParciales == 0) printf("N/A%24s", "");
			else for(int x = cModasParciales * 7 - 2; x < 27; x++) printf(" ");
			if(cModasPracticos <= 4 && cModasParciales <= 4) printf("|");
			printf("\n");
			printf("   |%114s", "|\n");

			printf("   |%26s%25s %-6.2f%32s %-6.2f%17s", "SubTotal:", "Notas practicas (20%):", notaPracticos, "Notas parciales (50%):", notaParciales, "|\n");
			printf("   |%114s", "|\n");

			if(estado == 3)
				printf("   |  Total:%21s %-5.2f%13s %-5.2f%19s %5.2f = %-2d (Reparacion)%17s", "Notas (70%):", acumulados, "Nota (30%):", final * 0.3, "Def.:", definitiva, definitivaRedondeada, "|\n");
			else if(estado == 2)
				printf("   |  Total:%21s %-5.2f%13s %-5.2f%19s %-5.2f = %-2d (Final)%22s", "Notas (70%):", acumulados, "Nota (30%):", final * 0.3, "Def.:", definitiva, definitivaRedondeada, "|\n");
			else if(estado == 1)
				printf("   |  Total:%21s %-5.2f%13s %3s%21s %5.2f = %-2d (Reparacion)%17s", "Notas (70%):", acumulados, "Nota (30%):", "NA", "Def.:", definitiva, definitivaRedondeada, "|\n");
			else if(estado == 0)
				printf("   |  Total:%21s %-5.2f%13s %3s%21s %5.2f = %-2d%30s", "Notas (70%):", acumulados, "Nota (30%):", "NA", "Def.:", definitiva, definitivaRedondeada, "|\n");
			printf("   |%114s", "|\n");
		}

		void mostrarReporte(Estudiante estudiante)
		{
			char nombreCompleto[20];
			join(estudiante.getNombre(), estudiante.getApellido(), nombreCompleto);

			printf("\n%118s", "------------------------------------------------------------------------------------------------------------------\n");
			printf("   |%114s", "|\n");

			printf("   |%64s%50s", "Reporte de notas", "|\n");
			printf("   |%114s", "|\n");

			printf("   |  Estudiante: %-30s CI: %-10i %25s %3s - %-19d |\n", nombreCompleto, estudiante.getCedula(), "Semestre:", periodo, agno);
			printf("   |%114s", "|\n");

			printf("   |  Asignatura: %-30s Codigo: %-10s %49s\n", nombre, codigo, "|");
			printf("   |%114s", "|\n");

			mostrarNotas();
			mostrarDetalles();

			printf("%118s", "------------------------------------------------------------------------------------------------------------------\n");
		}
};

class Electiva : public Asignatura
{
	private:
		char tipo[25];

	public:
		void leerTipoElectiva()
		{
			printf("\n%118s", "------------------------------------------------ TIPO DE ELECTIVA ------------------------------------------------\n");
			bool valido = false;
			char tecnica[] = {'T', 'e', 'c', 'n', 'i', 'c', 'a', '\0'};
			char humanistica[] = {'H', 'u', 'm', 'a', 'n', 'i', 's', 't', 'i', 'c', 'a', '\0'};
			do
			{
				printf("\n%72s", "Ingrese el tipo (Tecnica/Humanistica): ");
				getString(tipo);
				toTitlecase(tipo);
				if (compareTo(tecnica, tipo) == 0 || compareTo(humanistica, tipo) == 0)
				{
					valido = true;
				}
				else
				{
					printf("\n%74s", "Tipo de electiva no valido");
				}
			} while (!valido);
		}

		char *getTipoElectiva()
		{
			return tipo;
		}

		void mostrarReporte(Estudiante estudiante)
		{
			char nombreCompleto[20];
			join(estudiante.getNombre(), estudiante.getApellido(), nombreCompleto);
			float acumulados = notaParciales + notaPracticos;
			int definitivaRedondeada = getDefinitivaRedondeada();

			printf("\n%118s", "------------------------------------------------------------------------------------------------------------------\n");
			printf("   |%114s", "|\n");

			printf("   |%64s%50s", "Reporte de notas", "|\n");
			printf("   |%114s", "|\n");

			printf("   |  Estudiante: %-30s CI: %-10i %22s %3s - %-22d |\n", nombreCompleto, estudiante.getCedula(), "Semestre:", periodo, agno);
			printf("   |%114s", "|\n");

			printf("   |  Asignatura: %-30s Codigo: %-10s %19s%-28s |\n", nombre, codigo, "Tipo: ", tipo);
			printf("   |%114s", "|\n");

			mostrarNotas();
			mostrarDetalles();

			printf("%118s", "------------------------------------------------------------------------------------------------------------------\n");
		}
};

class Obligatoria : public Asignatura
{
	private:
		int semestre = 1;

	public:
		void leerSemestre()
		{
			printf("\n%118s", "---------------------------------------------------- SEMESTRE ----------------------------------------------------\n");

			do
			{
				printf("\n%75s", "Ingrese el numero de semestre: ");
				semestre = getInt();
				if (semestre <= 0)
					printf("%73s", "Numero de semestre invalido");
			} while (semestre <= 0);
		}

		int getSemestre()
		{
			return semestre;
		}

		void mostrarReporte(Estudiante estudiante)
		{
			char nombreCompleto[20];
			join(estudiante.getNombre(), estudiante.getApellido(), nombreCompleto);
			float acumulados = notaParciales + notaPracticos;
			int definitivaRedondeada = getDefinitivaRedondeada();

			printf("\n%118s", "------------------------------------------------------------------------------------------------------------------\n");
			printf("   |%114s", "|\n");

			printf("   |%64s%50s", "Reporte de notas", "|\n");
			printf("   |%114s", "|\n");

			printf("   |  Estudiante: %-30s CI: %-10i %22s %3s - %-22d |\n", nombreCompleto, estudiante.getCedula(), "Semestre:", periodo, agno);
			printf("   |%114s", "|\n");

			printf("   |  Asignatura: %-30s Codigo: %-10s     Nro. Semestre: %-2i     Tipo: %-15s |\n", nombre, codigo, semestre, "Obligatoria");
			printf("   |%114s", "|\n");

			mostrarNotas();
			mostrarDetalles();

			printf("%118s", "------------------------------------------------------------------------------------------------------------------\n");
		}
};

bool exist(Asignatura asignaturas[], int n, char codigo[])
{
	for (int i = 0; i < n; i++)
		if (compareTo(asignaturas[i].getCodigo(), codigo) == 0)
			return true;
	return false;
}

void order(Asignatura asignaturas[], int n)
{
	int i, cambio;
	Asignatura aux;
	do
	{
		cambio = 0;
		for (i = 0; i < n - 1; i++)
			if (compareTo(asignaturas[i].getNombre(), asignaturas[i + 1].getNombre()) == 1)
			{
				aux = asignaturas[i];
				asignaturas[i] = asignaturas[i + 1];
				asignaturas[i + 1] = aux;
				cambio = 1;
			}
	} while (cambio == 1);
}

void order(Obligatoria asignaturas[], int n)
{
	int i, cambio;
	Obligatoria aux;
	do
	{
		cambio = 0;
		for (i = 0; i < n - 1; i++)
			if (compareTo(asignaturas[i].getNombre(), asignaturas[i + 1].getNombre()) == 1)
			{
				aux = asignaturas[i];
				asignaturas[i] = asignaturas[i + 1];
				asignaturas[i + 1] = aux;
				cambio = 1;
			}
	} while (cambio == 1);
}

void order(Electiva asignaturas[], int n)
{
	int i, cambio;
	Electiva aux;
	do
	{
		cambio = 0;
		for (i = 0; i < n - 1; i++)
			if (compareTo(asignaturas[i].getNombre(), asignaturas[i + 1].getNombre()) == 1)
			{
				aux = asignaturas[i];
				asignaturas[i] = asignaturas[i + 1];
				asignaturas[i + 1] = aux;
				cambio = 1;
			}
	} while (cambio == 1);
}

int indexOf(Asignatura asignaturas[], int n, char codigo[])
{
	for (int i = 0; i < n; i++)
		if (compareTo(asignaturas[i].getCodigo(), codigo) == 0)
			return i;
	return -1;
}

int indexOf(Obligatoria asignaturas[], int n, char codigo[])
{
	for (int i = 0; i < n; i++)
		if (compareTo(asignaturas[i].getCodigo(), codigo) == 0)
			return i;
	return -1;
}

int indexOf(Electiva asignaturas[], int n, char codigo[])
{
	for (int i = 0; i < n; i++)
		if (compareTo(asignaturas[i].getCodigo(), codigo) == 0)
			return i;
	return -1;
}

// Opciones de menu
int *ingresarAsignatura(Estudiante estudiante, Asignatura asignaturas[], int cAsignaturas, Obligatoria obligatorias[], int cObligatorias, Electiva electivas[], int cElectivas)
{
	int opc2;
	do
	{
		printf("\n%118s", "----------------------------------------------------- TIPO -------------------------------------------------------\n");
		printf("\n%80s", "(1) Ingresar una asignatura obligatoria");
		printf("\n%77s", "(2) Ingresar una asignatura electiva");
		printf("\n%51s", "(3) Volver");
		printf("\n%70s", "Opcion: ");

		opc2 = 0;
		do
		{
			opc2 = getInt();
			if (opc2 < 1 || opc2 > 4)
				printf("%70s", "Opcion invalida, ingrese de nuevo: ");
		} while (opc2 < 1 || opc2 > 4);

		switch (opc2)
		{
			case 1:
			{
				Obligatoria temp;
				temp.asignarDatos();
				if (exist(asignaturas, cAsignaturas, temp.getCodigo()))
				{
					printf("%78s", "Este codigo de asignatura ya esta evaluado");
				}
				else
				{
					temp.leerSemestre();
					temp.leerPeriodo();
					temp.leerPrerrequisitos();
					temp.leerAreaConocimiento();
					temp.leerNotasPracticos();
					temp.leerNotasParciales();
					temp.calcularDefinitiva(true);
					temp.mostrarReporte(estudiante);
					asignaturas[cAsignaturas++] = temp;
					obligatorias[cObligatorias++] = temp;

					order(asignaturas, cAsignaturas);
					order(obligatorias, cObligatorias);
				}
			}
			break;

			case 2:
			{
				Electiva temp;
				temp.asignarDatos();
				if (exist(asignaturas, cAsignaturas, temp.getCodigo()))
				{
					printf("%78s", "Este codigo de asignatura ya esta evaluado");
				}
				else
				{
					temp.leerPeriodo();
					temp.leerPrerrequisitos();
					temp.leerAreaConocimiento();
					temp.leerTipoElectiva();
					temp.leerNotasPracticos();
					temp.leerNotasParciales();
					temp.calcularDefinitiva(true);
					temp.mostrarReporte(estudiante);
					asignaturas[cAsignaturas++] = temp;
					electivas[cElectivas++] = temp;

					order(asignaturas, cAsignaturas);
					order(electivas, cElectivas);
				}
			}
			break;
		}
	} while (opc2 != 3);
	return new int[3]{cAsignaturas, cObligatorias, cElectivas};
}

void mostrarPeriodo(Estudiante estudiante, Asignatura asignaturas[], int cAsignaturas)
{
	Asignatura asignaturaTemp;
	asignaturaTemp.leerPeriodo();

	char nombreCompleto[20];
	join(estudiante.getNombre(), estudiante.getApellido(), nombreCompleto);

	printf("\n%118s", "------------------------------------------------------------------------------------------------------------------\n");
	printf("   |%114s", "|\n");

	printf("   |%68s %45s", "Listado de Calificaciones", "|\n");
	printf("   |%114s", "|\n");

	printf("   |  Estudiante: %-30s %3s %-10i %23s %3s - %-4d                  |\n", nombreCompleto, "CI:", estudiante.getCedula(), "Semestre:", asignaturaTemp.getPeriodo(), asignaturaTemp.getAgno());
	printf("   |%114s", "------------------------------------------------------------------------------------------------------------  |\n");
	printf("   |%114s", "|\n");

	printf("   |  %-35s %7s %30s %28s       |\n", "Asignatura", "Codigo", "Calificacion", "Prerrequisitos");
	printf("   |%114s", "|\n");

	float promedioGeneral = 0;
	float sumatoria = 0;
	float totalCreditos = 0;
	for (int i = 0; i < cAsignaturas; i++)
	{
		if (asignaturaTemp.getAgno() == asignaturas[i].getAgno() && compareTo(asignaturaTemp.getPeriodo(), asignaturas[i].getPeriodo()) == 0)
		{
			int cPrerrequisitos = asignaturas[i].getCPrerrequisitos();
			if (cPrerrequisitos == 0)
			{
				printf("   |  %-36s%-32s%-24d%18s|\n", asignaturas[i].getNombre(), asignaturas[i].getCodigo(), asignaturas[i].getDefinitivaRedondeada(), "");
			}
			else
			{
				printf("   |  %-36s%-32s%-24d%-18s|\n", asignaturas[i].getNombre(), asignaturas[i].getCodigo(), asignaturas[i].getDefinitivaRedondeada(), asignaturas[i].getPrerrequisito(1));
				for (int j = 2; j <= cPrerrequisitos; j++)
					printf("   |  %100s          |\n", asignaturas[i].getPrerrequisito(j));
			}

			float creditoTemp = asignaturas[i].getCreditos();
			sumatoria += creditoTemp * asignaturas[i].getDefinitivaRedondeada();
			totalCreditos += creditoTemp;
		}
	}
	if (totalCreditos != 0)
	{
		promedioGeneral = sumatoria / totalCreditos;
		printf("   |%114s", "|\n");

		printf("   |%114s", "------------------------------------------------------------------------------------------------------------  |\n");

		printf("   |  Promedio General: %-5.2f%89s", promedioGeneral, "|\n");
		printf("   |%114s", "|\n");
	}
	printf("%118s", "------------------------------------------------------------------------------------------------------------------\n");
}

void mostrarElectivas(Estudiante estudiante, Electiva electivas[], int cElectivas)
{
	Electiva asignaturaTemp;
	asignaturaTemp.leerTipoElectiva();

	char nombreCompleto[20];
	join(estudiante.getNombre(), estudiante.getApellido(), nombreCompleto);

	printf("\n%118s", "------------------------------------------------------------------------------------------------------------------\n");
	printf("   |%114s", "|\n");

	if (compareTo(asignaturaTemp.getTipoElectiva(), new char[8]{'T', 'e', 'c', 'n', 'i', 'c', 'a', '\0'}) == 0)
		printf("   |%70s %43s", "Reporte de Electivas Tecnicas", "|\n");
	else if (compareTo(asignaturaTemp.getTipoElectiva(), new char[12]{'H', 'u', 'm', 'a', 'n', 'i', 's', 't', 'i', 'c', 'a', '\0'}) == 0)
		printf("   |%72s %41s", "Reporte de Electivas Humanisticas", "|\n");
	else
		printf("   |%68s %45s", "Listado de Calificaciones", "|\n");
	printf("   |%114s", "|\n");

	printf("   |  Estudiante: %-30s %3s %-10i %54s", nombreCompleto, "CI:", estudiante.getCedula(), "|\n");
	printf("   |%114s", "------------------------------------------------------------------------------------------------------------  |\n");
	printf("   |%114s", "|\n");

	printf("   |  %-35s %7s %30s %28s       |\n", "Asignatura", "Codigo", "Calificacion", "Prerrequisitos");
	printf("   |%114s", "|\n");

	float promedioGeneral = 0;
	float sumatoria = 0;
	float totalCreditos = 0;
	int cantidad = 0;
	for (int i = 0; i < cElectivas; i++)
	{
		if (compareTo(asignaturaTemp.getTipoElectiva(), electivas[i].getTipoElectiva()) == 0)
		{
			int cPrerrequisitos = electivas[i].getCPrerrequisitos();
			if (cPrerrequisitos == 0)
			{
				printf("   |  %-36s%-32s%-24d%18s|\n", electivas[i].getNombre(), electivas[i].getCodigo(), electivas[i].getDefinitivaRedondeada(), "");
			}
			else
			{
				printf("   |  %-36s%-32s%-24d%-18s|\n", electivas[i].getNombre(), electivas[i].getCodigo(), electivas[i].getDefinitivaRedondeada(), electivas[i].getPrerrequisito(1));
				for (int j = 2; j <= cPrerrequisitos; j++)
					printf("   |  %100s          |\n", electivas[i].getPrerrequisito(j));
			}

			float creditoTemp = electivas[i].getCreditos();
			sumatoria += creditoTemp * electivas[i].getDefinitivaRedondeada();
			totalCreditos += creditoTemp;
			cantidad++;
		}
	}
	if (totalCreditos != 0)
	{
		promedioGeneral = sumatoria / totalCreditos;
		printf("   |%114s", "|\n");

		printf("   |%114s", "------------------------------------------------------------------------------------------------------------  |\n");

		if (compareTo(asignaturaTemp.getTipoElectiva(), new char[8]{'T', 'e', 'c', 'n', 'i', 'c', 'a', '\0'}) == 0)
			printf("   |  %7s%-2i %57s %-5.2f %38s", "Cant.: ", cantidad, "Promedio de Electivas Tecnicas:", promedioGeneral, "|\n");
		else if (compareTo(asignaturaTemp.getTipoElectiva(), new char[12]{'H', 'u', 'm', 'a', 'n', 'i', 's', 't', 'i', 'c', 'a', '\0'}) == 0)
			printf("   |  %7s%-2i %61s %-5.2f %34s", "Cant.: ", cantidad, "Promedio de Electivas Humanisticas:", promedioGeneral, "|\n");
		printf("   |%114s", "|\n");
	}
	printf("%118s", "------------------------------------------------------------------------------------------------------------------\n");
}

void mostrarArea(Estudiante estudiante, Asignatura asignaturas[], int cAsignaturas)
{
	Asignatura asignaturaTemp;
	asignaturaTemp.leerAreaConocimiento();

	char nombreCompleto[20];
	join(estudiante.getNombre(), estudiante.getApellido(), nombreCompleto);

	printf("\n%118s", "------------------------------------------------------------------------------------------------------------------\n");
	printf("   |%114s", "|\n");

	printf("   |%71s %42s", "Reporte de Area de Conocimiento", "|\n");
	printf("   |%114s", "|\n");

	printf("   |  Estudiante: %-30s %3s %-10i %54s", nombreCompleto, "CI:", estudiante.getCedula(), "|\n");
	printf("   |%114s", "------------------------------------------------------------------------------------------------------------  |\n");
	printf("   |%114s", "|\n");

	printf("   |  %-35s %7s %30s %28s       |\n", "Asignatura", "Codigo", "Calificacion", "Prerrequisitos");
	printf("   |%114s", "|\n");

	float promedioGeneral = 0;
	float sumatoria = 0;
	float totalCreditos = 0;
	int cantidad = 0;
	for (int i = 0; i < cAsignaturas; i++)
	{
		if (compareTo(asignaturaTemp.getAreaConocimiento(), asignaturas[i].getAreaConocimiento()) == 0)
		{
			int cPrerrequisitos = asignaturas[i].getCPrerrequisitos();
			if (cPrerrequisitos == 0)
			{
				printf("   |  %-36s%-32s%-24d%18s|\n", asignaturas[i].getNombre(), asignaturas[i].getCodigo(), asignaturas[i].getDefinitivaRedondeada(), "");
			}
			else
			{
				printf("   |  %-36s%-32s%-24d%-18s|\n", asignaturas[i].getNombre(), asignaturas[i].getCodigo(), asignaturas[i].getDefinitivaRedondeada(), asignaturas[i].getPrerrequisito(1));
				for (int j = 2; j <= cPrerrequisitos; j++)
					printf("   |  %100s          |\n", asignaturas[i].getPrerrequisito(j));
			}

			float creditoTemp = asignaturas[i].getCreditos();
			sumatoria += creditoTemp * asignaturas[i].getDefinitivaRedondeada();
			totalCreditos += creditoTemp;
			cantidad++;
		}
	}
	if (totalCreditos != 0)
	{
		promedioGeneral = sumatoria / totalCreditos;
		printf("   |%114s", "|\n");

		printf("   |%114s", "------------------------------------------------------------------------------------------------------------  |\n");

		printf("   |  %7s%-2i %44s %-5.2f %51s", "Cant.: ", cantidad, "Promedio del area:", promedioGeneral, "|\n");
		printf("   |%114s", "|\n");
	}
	printf("%118s", "------------------------------------------------------------------------------------------------------------------\n");
}

void mostrarSemestre(Estudiante estudiante, Obligatoria obligatorias[], int cObligatorias, Electiva electivas[], int cElectivas)
{
	Obligatoria asignaturaTemp;
	asignaturaTemp.leerSemestre();

	char nombreCompleto[20];
	join(estudiante.getNombre(), estudiante.getApellido(), nombreCompleto);

	printf("\n%118s", "------------------------------------------------------------------------------------------------------------------\n");
	printf("   |%114s", "|\n");

	printf("   |%66s %47s", "Reporte por semestre", "|\n");
	printf("   |%114s", "|\n");

	printf("   |  Estudiante: %-30s %3s %-10i %23s %-2i                          |\n", nombreCompleto, "CI:", estudiante.getCedula(), "Semestre:", asignaturaTemp.getSemestre());
	printf("   |%114s", "------------------------------------------------------------------------------------------------------------  |\n");
	printf("   |%114s", "|\n");

	printf("   |  %-35s %7s %30s %28s       |\n", "Asignatura", "Codigo", "Calificacion", "Prerrequisitos");
	printf("   |%114s", "|\n");

	float promedioGeneral = 0;
	float sumatoria = 0;
	float totalCreditos = 0;
	for (int i = 0; i < cObligatorias; i++)
	{
		if (asignaturaTemp.getSemestre() == obligatorias[i].getSemestre())
		{
			int cPrerrequisitos = obligatorias[i].getCPrerrequisitos();
			if (cPrerrequisitos == 0)
			{
				printf("   |  %-36s%-32s%-24d%18s|\n", obligatorias[i].getNombre(), obligatorias[i].getCodigo(), obligatorias[i].getDefinitivaRedondeada(), "");
			}
			else
			{
				printf("   |  %-36s%-32s%-24d%-18s|\n", obligatorias[i].getNombre(), obligatorias[i].getCodigo(), obligatorias[i].getDefinitivaRedondeada(), obligatorias[i].getPrerrequisito(1));
				for (int j = 2; j <= cPrerrequisitos; j++)
					printf("   |  %100s          |\n", obligatorias[i].getPrerrequisito(j));
			}

			float creditoTemp = obligatorias[i].getCreditos();
			sumatoria += creditoTemp * obligatorias[i].getDefinitivaRedondeada();
			totalCreditos += creditoTemp;
		}
	}
	if (totalCreditos != 0)
	{
		promedioGeneral = sumatoria / totalCreditos;
		printf("   |%114s", "|\n");

		printf("   |%114s", "------------------------------------------------------------------------------------------------------------  |\n");

		printf("   |  %19s%-2.0f %36s %-5.2f %47s", "Total de creditos: ", totalCreditos, "Promedio del semestre:", promedioGeneral, "|\n");
		printf("   |%114s", "|\n");
	}

	printf("%118s", "------------------------------------------------------------------------------------------------------------------\n");
}

void mostrarReporte(Estudiante estudiante, Obligatoria obligatorias[], int cObligatorias, Electiva electivas[], int cElectivas)
{
	Asignatura asignatura;
	char codigo[8];
	printf("\n%74s", "Ingrese el codigo de la asignatura: ");
	asignatura.leerCodigo(codigo);
	int index;
	printf("\n%8s\n", codigo);

	index = indexOf(obligatorias, cObligatorias, codigo);
	if (index != -1)
	{
		obligatorias[index].mostrarReporte(estudiante);
		return;
	}

	index = indexOf(electivas, cElectivas, codigo);
	if (index != -1)
	{
		electivas[index].mostrarReporte(estudiante);
		return;
	}

	printf("%81s", "Este codigo de asignatura no esta registrado");
}

void mostrarTodo(Estudiante estudiante, Asignatura asignaturas[], int cAsignaturas, Obligatoria obligatorias[], int cObligatorias, Electiva electivas[], int cElectivas)
{
	char nombreCompleto[20];
	join(estudiante.getNombre(), estudiante.getApellido(), nombreCompleto);

	printf("\n%118s", "------------------------------------------------------------------------------------------------------------------\n");
	printf("   |%114s", "|\n");

	printf("   |%68s %45s", "Listado de Calificaciones", "|\n");
	printf("   |%114s", "|\n");

	float promedioGeneral, sumatoria, totalCreditos;

	if (cAsignaturas > 0)
	{
		printf("   |%114s", "------------------------------------------------------------------------------------------------------------  |\n");
		printf("   |%114s", "|\n");
		printf("   |  %-35s %7s %30s %28s       |\n", "Asignatura", "Codigo", "Calificacion", "Prerrequisitos");
		printf("   |%114s", "------------------------------------------------------------------------------------------------------------  |\n");
		promedioGeneral = 0;
		sumatoria = 0;
		totalCreditos = 0;
		for (int i = 0; i < cAsignaturas; i++)
		{
			int cPrerrequisitos = asignaturas[i].getCPrerrequisitos();
			if (cPrerrequisitos == 0)
			{
				printf("   |  %-36s%-32s%-24d%18s|\n", asignaturas[i].getNombre(), asignaturas[i].getCodigo(), asignaturas[i].getDefinitivaRedondeada(), "");
			}
			else
			{
				printf("   |  %-36s%-32s%-24d%-18s|\n", asignaturas[i].getNombre(), asignaturas[i].getCodigo(), asignaturas[i].getDefinitivaRedondeada(), asignaturas[i].getPrerrequisito(1));
				for (int j = 2; j <= cPrerrequisitos; j++)
					printf("   |  %100s          |\n", asignaturas[i].getPrerrequisito(j));
			}

			float creditoTemp = asignaturas[i].getCreditos();
			sumatoria += creditoTemp * asignaturas[i].getDefinitivaRedondeada();
			totalCreditos += creditoTemp;
		}
		if (totalCreditos != 0)
		{
			promedioGeneral = sumatoria / totalCreditos;
			printf("   |%114s", "|\n");

			printf("   |%114s", "------------------------------------------------------------------------------------------------------------  |\n");

			printf("   |  Promedio General: %-5.2f%89s", promedioGeneral, "|\n");
			printf("   |%114s", "|\n");
		}
	}

	if (cObligatorias > 0)
	{
		printf("   |%114s", "|\n");
		printf("   |%114s", "----------------------------------------------- OBLIGATORIAS -----------------------------------------------  |\n");
		printf("   |  %-35s %7s %30s %28s       |\n", "Asignatura", "Codigo", "Calificacion", "Prerrequisitos");
		printf("   |%114s", "------------------------------------------------------------------------------------------------------------  |\n");
		promedioGeneral = 0;
		sumatoria = 0;
		totalCreditos = 0;
		for (int i = 0; i < cObligatorias; i++)
		{
			int cPrerrequisitos = obligatorias[i].getCPrerrequisitos();
			if (cPrerrequisitos == 0)
			{
				printf("   |  %-36s%-32s%-24d%18s|\n", obligatorias[i].getNombre(), obligatorias[i].getCodigo(), obligatorias[i].getDefinitivaRedondeada(), "");
			}
			else
			{
				printf("   |  %-36s%-32s%-24d%-18s|\n", obligatorias[i].getNombre(), obligatorias[i].getCodigo(), obligatorias[i].getDefinitivaRedondeada(), obligatorias[i].getPrerrequisito(1));
				for (int j = 2; j <= cPrerrequisitos; j++)
					printf("   |  %100s          |\n", obligatorias[i].getPrerrequisito(j));
			}

			float creditoTemp = obligatorias[i].getCreditos();
			sumatoria += creditoTemp * obligatorias[i].getDefinitivaRedondeada();
			totalCreditos += creditoTemp;
		}
		if (totalCreditos != 0)
		{
			promedioGeneral = sumatoria / totalCreditos;
			printf("   |%114s", "|\n");

			printf("   |%114s", "------------------------------------------------------------------------------------------------------------  |\n");

			printf("   |  Promedio General: %-5.2f%89s", promedioGeneral, "|\n");
			printf("   |%114s", "|\n");
		}
	}

	if (cElectivas > 0)
	{
		printf("   |%114s", "|\n");
		printf("   |%114s", "------------------------------------------------ ELECTIVAS -------------------------------------------------  |\n");
		printf("   |  %-35s %7s %30s %28s       |\n", "Asignatura", "Codigo", "Calificacion", "Prerrequisitos");
		printf("   |%114s", "------------------------------------------------------------------------------------------------------------  |\n");
		promedioGeneral = 0;
		sumatoria = 0;
		totalCreditos = 0;
		for (int i = 0; i < cElectivas; i++)
		{
			int cPrerrequisitos = electivas[i].getCPrerrequisitos();
			if (cPrerrequisitos == 0)
			{
				printf("   |  %-36s%-32s%-24d%18s|\n", electivas[i].getNombre(), electivas[i].getCodigo(), electivas[i].getDefinitivaRedondeada(), "");
			}
			else
			{
				printf("   |  %-36s%-32s%-24d%-18s|\n", electivas[i].getNombre(), electivas[i].getCodigo(), electivas[i].getDefinitivaRedondeada(), electivas[i].getPrerrequisito(1));
				for (int j = 2; j <= cPrerrequisitos; j++)
					printf("   |  %100s          |\n", electivas[i].getPrerrequisito(j));
			}

			float creditoTemp = electivas[i].getCreditos();
			sumatoria += creditoTemp * electivas[i].getDefinitivaRedondeada();
			totalCreditos += creditoTemp;
		}
		if (totalCreditos != 0)
		{
			promedioGeneral = sumatoria / totalCreditos;
			printf("   |%114s", "|\n");

			printf("   |%114s", "------------------------------------------------------------------------------------------------------------  |\n");

			printf("   |  Promedio General: %-5.2f%89s", promedioGeneral, "|\n");
			printf("   |%114s", "|\n");
		}
	}

	printf("%118s", "------------------------------------------------------------------------------------------------------------------\n");

}

void modificarAsignatura(Estudiante estudiante, Asignatura asignaturas[], int cAsignaturas, Obligatoria obligatorias[], int cObligatorias, Electiva electivas[], int cElectivas)
{
	Asignatura asignatura;
	char codigo[8];
	printf("\n%74s", "Ingrese el codigo de la asignatura: ");
	asignatura.leerCodigo(codigo);
	int index;

	index = indexOf(obligatorias, cObligatorias, codigo);
	if (index != -1)
	{
		int opc2;
		do
		{
			printf("\n%118s", "--------------------------------------------------- MODIFICAR ----------------------------------------------------\n");
			printf("\n%50s", "(1) Nombre");
			printf("\n%50s", "(2) Codigo");
			printf("\n%52s", "(3) Semestre");
			printf("\n%51s", "(4) Periodo");
			printf("\n%58s", "(5) Prerrequisitos");
			printf("\n%64s", "(6) Area de Conocimiento");
			printf("\n%63s", "(7) Nota de un practico");
			printf("\n%71s", "(8) Nota de todos los practicos");
			printf("\n%62s", "(9) Nota de un parcial");
			printf("\n%71s", "(10) Nota de todos los parciales");
			printf("\n%54s", "(11) Definitiva");
			printf("\n%59s", "(12) Mostrar reporte");
			printf("\n%50s", "(13) Volver");
			printf("\n%70s", "Opcion: ");

			opc2 = 0;
			do
			{
				opc2 = getInt();
				if (opc2 < 1 || opc2 > 13)
					printf("%70s", "Opcion invalida, ingrese de nuevo: ");
			} while (opc2 < 1 || opc2 > 13);

			switch (opc2)
			{
				case 1:
				{
					obligatorias[index].leerNombre();
					obligatorias[index].mostrarReporte(estudiante);
					order(obligatorias, cObligatorias);
					index = indexOf(obligatorias, cObligatorias, codigo);
					obligatorias[index].mostrarReporte(estudiante);
					asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = obligatorias[index];
					order(asignaturas, cAsignaturas);
					break;
				}
				case 2:
				{
					obligatorias[index].leerCodigo();
					asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = obligatorias[index];
					copy(obligatorias[index].getCodigo(), codigo);
					break;
				}
				case 3:
				{
					obligatorias[index].leerSemestre();
					asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = obligatorias[index];
					break;
				}
				case 4:
				{
					obligatorias[index].leerPeriodo();
					asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = obligatorias[index];
					break;
				}
				case 5:
				{
					obligatorias[index].leerPrerrequisitos();
					asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = obligatorias[index];
					break;
				}
				case 6:
				{
					obligatorias[index].leerAreaConocimiento();
					asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = obligatorias[index];
					break;
				}
				case 7:
				{
					printf("\n%74s", "Ingrese el numero del practico: ");
					int numero = getInt();
					if (numero < 0 || numero > obligatorias[index].getCPracticos())
						printf("%70s%-2i", "Numero invalido, maximo ", obligatorias[index].getCPracticos());
					else
					{
						obligatorias[index].leerNotaPractico(numero);
						obligatorias[index].calcularDefinitiva(false);
						asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = obligatorias[index];
					}
					break;
				}
				case 8:
				{
					obligatorias[index].leerNotasPracticos();
					obligatorias[index].calcularDefinitiva(false);						
					asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = obligatorias[index];
					break;
				}
				case 9:
				{
					printf("\n%71s", "Ingrese el numero del parcial: ");
					int numero = getInt();
					if (numero < 0 || numero > obligatorias[index].getCParciales())
						printf("%70s%-2i", "Numero invalido, maximo ", obligatorias[index].getCParciales());
					else
					{
						obligatorias[index].leerNotaParcial(numero);
						obligatorias[index].calcularDefinitiva(false);
						asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = obligatorias[index];
					}
					break;
				}
				case 10:
				{
					obligatorias[index].leerNotasParciales();
					obligatorias[index].calcularDefinitiva(false);
					asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = obligatorias[index];
					break;
				}
				case 11:
				{
					obligatorias[index].calcularDefinitiva(true);
					asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = obligatorias[index];
					break;
				}
				case 12:
				{
					obligatorias[index].mostrarReporte(estudiante);
					break;
				}
			}
		} while (opc2 != 13);
		return;
	}

	index = indexOf(electivas, cElectivas, codigo);
	if (index != -1)
	{
		int opc2;
		do
		{
			printf("\n%118s", "--------------------------------------------------- MODIFICAR ----------------------------------------------------\n");
			printf("\n%50s", "(1) Nombre");
			printf("\n%50s", "(2) Codigo");
			printf("\n%48s", "(3) Tipo");
			printf("\n%51s", "(4) Periodo");
			printf("\n%58s", "(5) Prerrequisitos");
			printf("\n%64s", "(6) Area de Conocimiento");
			printf("\n%63s", "(7) Nota de un practico");
			printf("\n%71s", "(8) Nota de todos los practicos");
			printf("\n%62s", "(9) Nota de un parcial");
			printf("\n%71s", "(10) Nota de todos los parciales");
			printf("\n%54s", "(11) Definitiva");
			printf("\n%59s", "(12) Mostrar reporte");
			printf("\n%50s", "(13) Volver");
			printf("\n%70s", "Opcion: ");

			opc2 = 0;
			do
			{
				opc2 = getInt();
				if (opc2 < 1 || opc2 > 13)
					printf("%70s", "Opcion invalida, ingrese de nuevo: ");
			} while (opc2 < 1 || opc2 > 13);

			switch (opc2)
			{
				case 1:
				{
					electivas[index].leerNombre();
					order(electivas, cElectivas);
					index = indexOf(electivas, cElectivas, codigo);
					asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = electivas[index];
					order(asignaturas, cAsignaturas);
					break;
				}
				case 2:
				{
					electivas[index].leerCodigo();
					asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = electivas[index];
					copy(electivas[index].getCodigo(), codigo);
					break;
				}
				case 3:
				{
					electivas[index].leerTipoElectiva();
					asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = electivas[index];
					break;
				}
				case 4:
				{
					electivas[index].leerPeriodo();
					asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = electivas[index];
					break;
				}
				case 5:
				{
					electivas[index].leerPrerrequisitos();
					asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = electivas[index];
					break;
				}
				case 6:
				{
					electivas[index].leerAreaConocimiento();
					asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = electivas[index];
					break;
				}
				case 7:
				{
					printf("\n%74s", "Ingrese el numero del practico: ");
					int numero = getInt();
					if (numero < 0 || numero > electivas[index].getCPracticos())
						printf("%70s%-2i", "Numero invalido, maximo", electivas[index].getCPracticos());
					else
					{
						electivas[index].leerNotaPractico(numero);
						electivas[index].calcularDefinitiva(false);
						asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = electivas[index];
					}
					break;
				}
				case 8:
				{
					electivas[index].leerNotasPracticos();
					electivas[index].calcularDefinitiva(false);
					asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = electivas[index];
					break;
				}
				case 9:
				{
					printf("\n%71s", "Ingrese el numero del parcial: ");
					int numero = getInt();
					if (numero < 0 || numero > electivas[index].getCParciales())
						printf("%70s%-2i", "Numero invalido, maximo ", electivas[index].getCParciales());
					else
					{
						electivas[index].leerNotaParcial(numero);
						electivas[index].calcularDefinitiva(false);
						asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = electivas[index];
					}
					break;
				}
				case 10:
				{
					electivas[index].leerNotasParciales();
					electivas[index].calcularDefinitiva(false);
					asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = electivas[index];
					break;
				}
				case 11:
				{
					electivas[index].calcularDefinitiva(true);
					asignaturas[indexOf(asignaturas, cAsignaturas, codigo)] = electivas[index];
					break;
				}
				case 12:
				{
					electivas[index].mostrarReporte(estudiante);
					break;
				}
			}
		} while (opc2 != 13);
		return;
	}

	printf("%81s", "Este codigo de asignatura no esta registrado");
}

// Menu
void menu()
{
	int opc = 0;
	int cAsignaturas = 0;
	Asignatura asignaturas[70];
	int cObligatorias = 0;
	Obligatoria obligatorias[60];
	int cElectivas = 0;
	Electiva electivas[10];
	Estudiante estudiante;
	estudiante.asignarDatos();

	// Menu
	do
	{
		printf("\n%118s", "----------------------------------------------------- Menu -------------------------------------------------------\n");
		printf("\n%73s", "(1) Ingresar nota de asignatura");
		printf("\n%79s", "(2) Mostrar Listado de Calificaciones");
		printf("\n%83s", "(3) Mostrar Listado por tipo de electivas");
		printf("\n%86s", "(4) Mostrar Listado por area de conocimiento");
		printf("\n%74s", "(5) Mostrar Listado por semestre");
		printf("\n%79s", "(6) Mostrar Reporte de una Asignatura");
		printf("\n%74s", "(7) Mostrar todas las asignatura");
		printf("\n%66s", "(8) Modificar asignatura");
		printf("\n%51s", "(9) Salir");
		printf("\n%70s", "Opcion: ");

		opc = 0;
		do
		{
			opc = getInt();
			if (opc < 1 || opc > 9)
				printf("%70s", "Opcion invalida, ingrese de nuevo: ");
		} while (opc < 1 || opc > 9);

		switch (opc)
		{
			// INGRESAR
			case 1:
			{
				int *cantidades = ingresarAsignatura(estudiante, asignaturas, cAsignaturas, obligatorias, cObligatorias, electivas, cElectivas);
				cAsignaturas = cantidades[0];
				cObligatorias = cantidades[1];
				cElectivas = cantidades[2];
			}
			break;

			// FIGURA B. PERIODO
			case 2:
			{
				mostrarPeriodo(estudiante, asignaturas, cAsignaturas);
			}
			break;

			// FIGURA C. ELECTIVAS TECNICAS / HUMANISTICAS
			case 3:
			{
				mostrarElectivas(estudiante, electivas, cElectivas);
			}
			break;

			// FIGURA D. AREA DE CONOCIMIENTO
			case 4:
			{
				mostrarArea(estudiante, asignaturas, cAsignaturas);
			}
			break;

			// FIGURA E. SEMESTRE
			case 5:
			{
				mostrarSemestre(estudiante, obligatorias, cObligatorias, electivas, cElectivas);
			}
			break;

			// FIGURA A. REPORTE ASIGNATURA
			case 6:
			{
				mostrarReporte(estudiante, obligatorias, cObligatorias, electivas, cElectivas);
			}
			break;

			// TODAS
			case 7:
			{
				mostrarTodo(estudiante, asignaturas, cAsignaturas, obligatorias, cObligatorias, electivas, cElectivas);
			}
			break;

			// MODIFICAR
			case 8:
			{
				modificarAsignatura(estudiante, asignaturas, cAsignaturas, obligatorias, cObligatorias, electivas, cElectivas);
			}
			break;

			// SALIR
			case 9:
			{
				printf("\n%64s", "HASTA LUEGO");
			}
			break;
		}
	} while (opc != 9);
}

int main()
{
	menu();
	return 0;
}
