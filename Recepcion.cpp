#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int menuPrincipal();

main()
{
	int opc=0;
	
	do{
		opc = menuPrincipal();
		switch(opc)
		{
			case 1: 
		    	break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
				
			default:	
				system("PAUSE");
		}	
	}while(opc != 5);
	
}

int menuPrincipal(){
	int op;
	system("CLS");
	printf("\n\n\t\t");
	printf("\n\n\t\t|-------------------------------------------------------|");
	printf("\n\n\t\t|          M E N U   P R I N C I P A L                  |");
	printf("\n\n\t\t|-------------------------------------------------------|");
	printf("\n\n\t\t|     1 - Iniciar Sesion                                |");
	printf("\n\n\t\t|     2 - Registrar Mascota                             |");
	printf("\n\n\t\t|     3 - Registrar Turno                               |");
	printf("\n\n\t\t|     4 - Listado de Atenciones por Veterinario y Fecha |");
	printf("\n\n\t\t|     5 - Cerrar la aplicacion                          |");
	printf("\n\n\t\t|-------------------------------------------------------|");
	printf("\n\n\t\t     Seleccione una Opcion: "); 
	scanf("%d", &op);
	return op;
}
