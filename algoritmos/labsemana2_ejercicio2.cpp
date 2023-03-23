#include <stdio.h>

struct elemento 
{
	int id;
};

struct inventario
{
	struct elemento *arrayElemento[100];
	
};

struct jugador 
{
	struct inventario *inventarioJugador;
};

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
			if(J2.inventarioJugador->arrayElemento[i] == NULL && J1.inventarioJugador->arrayElemento[indice] != NULL)
			{	
				J2.inventarioJugador->arrayElemento[i] = J1.inventarioJugador->arrayElemento[0];
				indice++;
			}
		}
	}
	else if(jugador == 2)
	{
		for(int i = 0; i < 100; i++)
		{
			if(J1.inventarioJugador->arrayElemento[i] == NULL && J2.inventarioJugador->arrayElemento[indice] != NULL)
			{	
				J1.inventarioJugador->arrayElemento[i] = J2.inventarioJugador->arrayElemento[0];
				indice++;
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

int main()
{
	struct elemento arrayElemento [5] = {0};
	
	for(int i = 0; i < 5; i++)
	{
		printf("Ingrese el numero del elemento encontrado: %d", i);
		scanf("%d", &arrayElemento[i].id);
		
	}
	
	buscarId(arrayElemento);
	
	return 0;
}
