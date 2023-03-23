#include <stdio.h>
#include <stdlib.h>
typedef struct elemento 
{
	int id;
	int cantidad;
}Elemento;

typedef struct inventario
{
	Elemento *arrayElemento[100];
	
}Inventario;

typedef struct jugador 
{
	Inventario inventarioJugador;
}Jugador;

void fusionarInventario(struct jugador J1, struct jugador J2)
{
	int jugador = 0;
	printf("Ingrese el usuario del jugador con el que se quiere fusionar: ");
	scanf("%d", &jugador);
	
	int indice = 0;
	
	if(jugador == 1)
	{
		for(int i = 0; i < 100; i++)
		{
			if(J2.inventarioJugador.arrayElemento[i]->id == 0 && J1.inventarioJugador.arrayElemento[indice]->id != 0)
			{	
				J2.inventarioJugador.arrayElemento[i] = J1.inventarioJugador.arrayElemento[indice];
				indice++;
			}
		}
		
		printf("Inventario actualizado del jugador 2");
		for(int i = 0; i < 100; i++)
		{
			if(J2.inventarioJugador.arrayElemento[i]->id != 0)
			{	
				printf("Objeto n° %d: %d",(i+1),J2.inventarioJugador.arrayElemento[i]->id);
			}
		}
		
	}
	else if(jugador == 2)
	{
		for(int i = 0; i < 100; i++)
		{
			if(J1.inventarioJugador.arrayElemento[i]->id == 0 && J2.inventarioJugador.arrayElemento[indice]->id != 0)
			{	
				J1.inventarioJugador.arrayElemento[i] = J2.inventarioJugador.arrayElemento[indice];
				indice++;
			}
		}
		
				
		printf("Inventario actualizado del jugador 1");
		for(int i = 0; i < 100; i++)
		{
			if(J1.inventarioJugador.arrayElemento[i]->id != 0)
			{	
				printf("Objeto n° %d: %d",(i+1),J1.inventarioJugador.arrayElemento[i]->id);
			}
		}
	}
}

void buscarId (struct elemento arrayElemento[])
{
	int objeto;
	
	printf("Ingrese el elemento que desea buscar: ");
	scanf("%d", &objeto);
	
	int contador = 0;
	
	for(int i = 0; i < 5; i++)
	{
		if(objeto == arrayElemento[i].id)
		{
			contador++;			
		}
	}
	
	printf("La cantidad de elementos encontrados es igual a: %d", contador);	
}

void mostrarInventario(Jugador J1)
{
	for(int i = 0; i < 100; i++)
	{
		if(J1.inventarioJugador.arrayElemento[i]->id != 0)
		{
			printf("\nCantidad de elementos %d: id: %d",J1.inventarioJugador.arrayElemento[i]->cantidad , 
			J1.inventarioJugador.arrayElemento[i]->id);
		}
	}
}

void agregarElemento(Jugador J1)
{
	int opcion = 0;
	
	printf("Que tipo de objeto desea agregar?: ");
	scanf("%d", &opcion);
	
	for(int i = 0; i < 100; i++)
	{
		if(opcion == J1.inventarioJugador.arrayElemento[i]->id)
		{
			J1.inventarioJugador.arrayElemento[i]->cantidad += 1;
			i = 100;
		}
		else
		{
			if(J1.inventarioJugador.arrayElemento[i]->id == 0)
			{
				J1.inventarioJugador.arrayElemento[i]->id = opcion;
				J1.inventarioJugador.arrayElemento[i]->cantidad += 1;
				i = 100;
			}
		}
	}
	
	mostrarInventario(J1);
}

void eliminarElemento(Jugador J1)
{
	int opcion = 0;
	
	printf("Que tipo de objeto desea eliminar?");
	scanf("%d", &opcion);
	
	for(int i = 0; i < 100; i++)
	{
		if(opcion == J1.inventarioJugador.arrayElemento[i]->id)
		{
			
			J1.inventarioJugador.arrayElemento[i]->cantidad -= 1;
			if(J1.inventarioJugador.arrayElemento[i]->cantidad <= 0)
			{
				J1.inventarioJugador.arrayElemento[i]->id = 0;
			}
		}
	}
	
	mostrarInventario(J1);
}

int main()
{
	Jugador J1;
	Jugador J2;
	
	for(int i = 0; i < 100; i++){
		J1.inventarioJugador.arrayElemento[i] = malloc(sizeof(Elemento));
		J1.inventarioJugador.arrayElemento[i]->id = 0;	
		J2.inventarioJugador.arrayElemento[i] = malloc(sizeof(Elemento));
		J2.inventarioJugador.arrayElemento[i]->id = 0;
	}

	for(int i = 0; i < 3; i++){
		printf("Ingrese un objeto al inventario del jugador 1: ");
		scanf("%d", &J1.inventarioJugador.arrayElemento[i]->id);
		
		printf("Ingrese la cantidad de elementos del objeto ingresado: ");
		scanf("%d", &J1.inventarioJugador.arrayElemento[i]->cantidad);
	}
	
	for(int i = 0; i < 2; i++){
		printf("Ingrese un objeto al inventario del jugador 2: ");
		scanf("%d",&J2.inventarioJugador.arrayElemento[i]->id);
		
		printf("Ingrese la cantidad de elementos del objeto ingresado: ");
		scanf("%d", &J2.inventarioJugador.arrayElemento[i]->cantidad);
	}
	
	agregarElemento(J1);
	eliminarElemento(J1);
	
	
	return 0;
}
