#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char palabra[60];

int menuPrincipal();
void inicioSesion(bool &login);
bool comprobacion(char auxUsuario[10], char auxContrasena[20]);

struct usuario{
	char user[10];
	char contra[10];
	char apynom[60];
};

struct fecha
{
	int dia;
	int mes;
	int anio;
};

struct registro//Mascota
{
	palabra ApeYNom;
	palabra Domicilio;
	int DNI;
	palabra Localidad;
	float Peso;
	int Telefono;
	fecha fec;
};

struct fecha1
{
	int dia;
	int mes;
	int anio;
};

struct registro1//Turno
{
	int Matricula;
	fecha1 fech;
	int dni;
	char Atencion[380];
};

struct veterinario//Veterinario
{
	char apynom[60];
	int matricula;
	int dni;
	int telefono;
	char contra[32];
};

main()
{
	int opc=0;
	int v=0;
	registro mascota; //Declarar registro de mascotas
	FILE*arch;//Variable puntero de mascotas
	
	registro1 turno; //Declarar registro de turnos
	FILE*arch1;//Variable puntero de turnos
	
	veterinario revVet;//Declarar registro de veterinarios
	FILE *archVet;//Variable puntero de veterinarios
	
	bool salir=false,login=false; //Se usa para comprbar eñ inicio de sesion
	int guardar; // ingresa el valor de la comprobacion.
	usuario regUs;
	
	printf("-Inicie sesion para contiuar-");
	do
	{
		inicioSesion(login);
		guardar = login;
	}while(guardar!=1);
	
	
	if (guardar == 1)
	{		
	do{
		opc = menuPrincipal();
		switch(opc)
		{
			case 1:
			{
				system("CLS");
				inicioSesion(login); 
				break;
			} 
		    	break;
			case 2:
			{
				system("CLS");
				arch = fopen("Mascotas.dat","a+b");
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
			{
				system("CLS");	
				arch1 = fopen("Turnos.dat","r+b");
				if(arch1 == NULL)
				{
					fclose(arch1);
					arch1= fopen("Turnos.dat","w+b");
				}
				
				printf("-Registrar turno-\n\n");
				_flushall();
				
				printf("Matricula del Veterinario: ");
				scanf("%d", &turno.Matricula);
				
				printf("\n*Fecha*");
				printf("\n\nDia: ");
				scanf("%2d", &turno.fech.dia);
				printf("\nMes: ");
				scanf("%2d",  &turno.fech.mes);
				printf("\nAnio: ");
				scanf("%4d", &turno.fech.anio);
				
				printf("\n\nDNI del duenio: ");
				scanf("%d", &turno.dni);
				_flushall();
				
				printf("\nDetalle de la atencion: ");
				gets(turno.Atencion);
				
				fwrite(&turno, sizeof (registro1), 1, arch1 );
				
				fclose(arch1);
				
				system("Pause");
				
				break;
			}
			case 4:
			{
				system ("CLS");
				
				printf("*Listado de atenciones: \n\n");
				
				archVet = fopen("Veterinarios.dat","r+b");
				
				arch = fopen("Mascotas.dat","r+b");
				
				arch1 = fopen("Turnos.dat","r+b");
				
			
				
				fread(&revVet, sizeof (veterinario), 1, archVet);
				fread(&mascota, sizeof (registro), 1, arch);
				fread(&turno, sizeof (registro1), 1, arch1);
				
				
				while(!feof(arch) &&  !feof(arch1) && !feof(archVet))
				{
					if(turno.Matricula==revVet.matricula)
					{
						puts(revVet.apynom);
						puts(mascota.ApeYNom);
						fread(&mascota, sizeof(registro), 1, arch);
						
						printf("Matricula del veterinario: %d\n", turno.Matricula);
						printf("Fecha: %d/%d/%d\n", turno.fech.dia, turno.fech.mes, turno.fech.anio);
						fread(&turno, sizeof(registro1), 1, arch1);
					}
					else
					{
						printf("Matricula incorrecta.");
					}	
				}
				
				fclose (archVet);
				fclose(arch);
				fclose(arch1);
				
				system("Pause");
				break;
			}
			default:	
				system("PAUSE");
		}	
	}while(opc != 5);
	}
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


/*--------------------------------------------------------*/


void inicioSesion(bool &login)
{
	FILE *archUs = fopen("Usuarios.dat","r+b");
	char auxContrasena[20];
	char auxUsuario[10]; 
	login=false; 
	do{
		printf("\nUSUARIO: ");
		_flushall();
		gets(auxUsuario);
		_flushall();
	
		printf("\nCONTRASENA: ");
		gets(auxContrasena);
		_flushall();
		
		if(comprobacion(auxUsuario,auxContrasena)==true)
		{
			login=true;
			//copMatricula=auxUsuario;//aqui se realizara la copia de la matricula
			break;
		}
		
		//comprobacion de usuario y contraseña que dara true o false en ingreso de sesion
	}
	while(login==false);
	
	//se cierra
}


/*-----------------------------------------------------------------*/


bool comprobacion(char auxUsuario[10],char auxContrasena[20])
{
	bool inicio=false;
	
	FILE *archUs = fopen("Usuarios.dat","r+b");
	
	usuario regUs;
	
	fread(&regUs, sizeof(usuario), 1, archUs);

	if (archUs==NULL)
	{
   		perror("No se puede abrir o no se registro ningun veterinario");
   		return -1;
	}
	while(!feof(archUs))
	{
		if(strcmp(auxUsuario, regUs.user)==0)
		{
			printf("\nEl usuario existe");
			//a continuacion se compararia la contrasena
			inicio=true;
			system("PAUSE");
		}
		fread(&regUs, sizeof(usuario), 1, archUs);	
	}
	
	if(inicio==true)
	{
		printf("Se inicio sesion correctamente");
		fclose(archUs);
		return(true);
		system("PAUSE");
	}
	else
	{
		printf("No se pudo iniciar sesion, pruebe nuevamente");
		fclose(archUs);
		return(false);
		system("PAUSE");
		
	}
	
	system("PAUSE");
}
