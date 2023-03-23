#include <stdio.h>

struct paciente
{
	char nombre[20];
	int edad;
	int numHabitacion;
	float registroTemperatura[7];
};

void convertirGrados(float grados)
{
	
	float fahrenheit = (grados * (9/5))+ 32;
	printf("\nLa temperatura del paciente es de %f fahrenheit", fahrenheit);
}

int tieneFiebre(float grados, int dia)
{
	if(grados >= 37.5)
	{
		printf("\nEl paciente tiene fiebre el %d dia", dia);
		return 1;
	}
	else
	{
		printf("\nEl paciente no tiene fiebre el %d dia ", dia);
		return 0;
	}
}

void registroFiebre(float registroTemperatura[])
{
	float promTemperatura = 0;
	int sumaFiebre = 0; 
	
	for(int i = 0; i < 7; i++)
	{
		promTemperatura += registroTemperatura[i];
		sumaFiebre += tieneFiebre(registroTemperatura[i], i+1);
	}
	
	if(sumaFiebre >= 3)
	{
		printf("\nEl paciente tuvo fiebre durante %d dias", sumaFiebre);
	}
	
	printf("\nEl promedio de su temperatura ha sido de: %f", (promTemperatura/7));
}

int main()
{
	struct paciente numPacientes[100] = {0};
	
	printf("Ingrese los datos del primer paciente");
	printf("\nIngrese el nombre del paciente: ");
	scanf("%s", &numPacientes[0].nombre);
	printf("\nIngrese la edad del paciente: ");
	scanf("%d", &numPacientes[0].edad);
	printf("\nIngrese el numero de habitacion del paciente: ");
	scanf("%d", &numPacientes[0].numHabitacion);
	
	for(int i = 0; i < 7; i++)
	{
		printf("\nIngrese la temperatura del dia %d: ", i+1);
		scanf("%f", &numPacientes[0].registroTemperatura[i]);
		
		tieneFiebre(numPacientes[0].registroTemperatura[i], i+1);
		
		convertirGrados(numPacientes[0].registroTemperatura[i]);
	}
	
	registroFiebre(numPacientes[0].registroTemperatura);
	
}
