#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct usuario{
	char user[10];
	char contra[10];
	char apynom[60];
};

struct veterinario{
	char apynom[60];
	int matricula;
	int dni;
	int telefono;
	char contra[10];
};

int menuPrincipal();
void registroVet(FILE *archVet);
void registroAsist(FILE *archUs);
int atenciones();
int ranking();

main()
{
	FILE *archUs = fopen("Usuarios.dat","r+b");
	if(archUs == NULL){
		fclose(archUs);
		archUs = fopen("Usuarios.dat","a+b")
	}
	
	FILE *archVet = fopen("Veterinarios.dat","r+b");
	if(archVet == NULL){
		fclose(archVet);
		archVet = fopen("Veterinarios.dat","a+b")
	}
		
	int opc=0;
	
	do{
		opc= menuPrincipal();
		switch(opc){
			case 1:
			{				
				registroVet(archVet);
				break;
			}
			case 2:
			{
				registroAsist(archUs);				
				break;
			}
			case 3:
			{
				atenciones();
				break;
			}	
			case 4:
			{
				ranking();
				break;
			}
			
			default:
				system("PAUSE");	
		}
	}while(opc != 5);
	
}

int menuPrincipal()
{
	int op;
	system("CLS");
	printf("\n\n\t\t");
	printf("\n\n\t\t            Modulo  Administracion                    ");
	printf("\n\n\t\t======================================================");
	printf("\n\n\t\t     1. - Registrar Veterinario                       ");
	printf("\n\n\t\t     2. - Registrar Ususario Asistente                ");
	printf("\n\n\t\t     3. - Atenciones por Veterinarios                 ");
	printf("\n\n\t\t     4. - Ranking de Veterinarios por Atenciones      ");
	printf("\n\n");
	printf("\n\n\t\t     5. - Cerrar la aplicacion                        ");
	printf("\n\n\t\t     Ingrese una opcion: "); 
	scanf("%d", &op);
	return op;
}

void registroVet(FILE *archVet)
{
	veterinario regVet;
	
	_flushall();
	system("CLS");
	printf("\n\n\t\t");
	printf("\n\n\t\t           INICIO REGISTRO VETERINARIO                ");
	printf("\n\n\t\t======================================================");
	printf("\n\n\t\t Ingrese Apellido y nombre: ");
	gets(regVet.apynom);
	printf("\n\n\t\t Matricula: ");
	scanf("%d",&regVet.matricula);
	printf("\n\n\t\t DNI: ");
	scanf("%d",&regVet.dni);
	printf("\n\n\t\t Telefono: ");
	scanf("%d",&regVet.telefono);
	printf("\n\n\t\t Contrasenia para ingreso: ");
	
	
}

void registroAsist(FILE *archUs)
{
	usuario regUs;
	
	_flushall();
	system("CLS");
	printf("\n\n\t\t");
	printf("\n\n\t\t           INICIO REGISTRO ASISTENTE                  ");
	printf("\n\n\t\t======================================================");
	printf("\n\n\t\t Ingrese Apellido y nombre: ");
	gets(regUs.apynom);
	printf("\n\n\t\t Usuario para ingreso: ");

	printf("\n\n\t\t Contrasenia para ingreso: ");
}

int atenciones()
{
	
}

int ranking()
{
	
}
