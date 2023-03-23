#include <stdio.h>

struct elemento 
{
	int id;
};

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
