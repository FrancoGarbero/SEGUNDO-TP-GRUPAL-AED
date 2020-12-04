#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char palabra[60];

int menuPrincipal();





struct fecha
{
	int dia;
	int mes;
	int anio;
};

struct registro
{
	palabra ApeYNom;
	palabra Domicilio;
	int DNI;
	palabra Localidad;
	float Peso;
	int Telefono;
	fecha fec;
};

main()
{
	int opc=0;
	registro mascota; //Declarar registro de mascotas
	FILE*arch;//Variable puntero de mascotas
	
	do{
		opc = menuPrincipal();
		switch(opc)
		{
			case 1: 
		    	break;
			case 2:
			{
				system("CLS");
				arch = fopen("Mascotas.dat","r+b");
				if(arch == NULL)
				{
					fclose(arch);
					arch= fopen("Mascotas.dat","w+b");
				}
				
				printf("-Registrar mascota-\n\n");
				_flushall();
				
				printf("Apellido y nombre: ");
				gets(mascota.ApeYNom);
				
				printf("\nDomicilio: ");
				gets(mascota.Domicilio);
				
				printf("\nDNI del duenio: ");
				scanf("%d", &mascota.DNI);
				_flushall();
				
				
				printf("\nLocalidad: ");
				gets(mascota.Localidad);
				
				
				printf("\nPeso de la mascota: ");
				scanf("%f", &mascota.Peso);
				
				printf("\nTelefono: ");
				scanf("%d", &mascota.Telefono);
				
				printf("\n*Fecha de Nacimiento*");
				printf("\n\nDia: ");
				scanf("%2d", &mascota.fec.dia);
				printf("\nMes: ");
				scanf("%2d",  &mascota.fec.mes);
				printf("\nAnio: ");
				scanf("%4d", &mascota.fec.anio);
				
				fwrite(&mascota, sizeof (registro), 1, arch );
				
				fclose(arch);
				
				system("PAUSE");	
				break;
			}
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
