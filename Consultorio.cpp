#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(bool &salir, bool &login, FILE *vet);
void inicioSesion(bool &login,int &copMatricula,FILE *vet);
void listaEspera(int copMatricula);
void registrarEvolucion();
bool comprobacion(int auxUsuario,char auxContrasena[20],FILE *vet);
typedef char palabra[60];


struct fecha //FECHA, CON UNA SOLA BASTA :)
{
	int dia;
	int mes;
	int anio;
};

struct veterinario{ //INFO DE LOS VETERINARIOS
	char apynom[60];
	int matricula;
	int dni;
	int telefono;
	char contra[10];
};

struct registro1//STRUCT PARA TURNOS
{
	int Matricula;
	fecha fech;
	int dni;
	palabra Atencion;
};

struct registro//DATOS DE MASCOTA
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
	FILE *vet; 
	bool salir=false,login=false;
	
		
	printf("BIENVENIDO AL MODULO CONSULTORIO");
	printf("\n-----------------------------------");
	do
	{
		menu(salir,login,vet);	
	}
	while(salir==false);
	
	printf("Adios popo");
	
}

void menu(bool &salir, bool &login, FILE *vet)
{
	int seleccion;
	int copMatricula=0;//copia el numero de matrucula para comparar en turnos, asi no se tiene que recargar;
	do
	{
		printf("\n\n1.- Iniciar Sesion\n2.- Visualizar Lista de Espera de Turnos (informe)\n3.- Registrar Evolucion de la Mascota\n4.- Cerrar la aplicacion.\n\nIngrese una opcion: ");
		scanf("%d",&seleccion);
		
		switch(seleccion)
		{
			case 1:
				system("CLS");
				inicioSesion(login,copMatricula,vet); 
				break;
				
			case 2:
				if (login==true)
				{
					system("CLS");
					listaEspera(copMatricula);	
				}
				else
				{
					printf("Error, necesita iniciar sesion para acceder a esta opcion\n");
					system("PAUSE");
				}
				break;
				
			case 3:
				if (login==true)
				{
					system("CLS");
					registrarEvolucion();	
				}
				else
				{
					printf("Error, necesita iniciar sesion para acceder a esta opcion\n");
					system("PAUSE");
				}
				break; 
				
			case 4:
				salir=true;
				break;
			
		}	
		system("CLS");		
	}
	while (salir==false);
	
}

void inicioSesion(bool &login,int &copMatricula,FILE *vet)
{
	char auxContrasena[20];
	int auxUsuario; 
	login=false; //borrar esto ma tarde	
	do{
		printf("\nMATRICULA: ");
		_flushall();
		scanf("%d",&auxUsuario);
		_flushall();
	
		printf("\nCONTRASENA: ");
		gets(auxContrasena);
		_flushall();
		
		if(comprobacion(auxUsuario,auxContrasena,vet)==true)
		{
			login=true;
			copMatricula=auxUsuario;//aqui se realizara la copia de la matricula
			break;
		}
		
		//comprobacion de usuario y contraseña que dara true o false en ingreso de sesion
		//
	}
	while(login==false);
	
	//se cierra
}

void listaEspera(int copMatricula)
{
	registro1 turno;
	registro mascota;
	
	FILE *T ,*M;//T por turno, M por mascota
	T=fopen("turnos.dat","r");
	M=fopen("mascotas.dat","r");
	int contador=1; //para numerar turnos, Puramente visual
	fread(&turno, sizeof(registro1), 1, T);
	fread(&mascota, sizeof(registro), 1, M);
	while(!feof(T))
	{
		if(turno.Matricula==copMatricula)
		{
			printf("Turno %d\n=========",contador);
			printf("\nFecha: %d|%d|%d", turno.fech.dia,turno.fech.mes,turno.fech.anio);
			printf("\nDNI: %d",turno.dni);
			if(turno.Atencion!=NULL)
			{
				printf("\nNotas anteriores: ");
				gets(turno.Atencion);	
			}
			else
			{
				printf("\nNo esxiten notas anteriores");	
			}
			while(!feof(M))
			{
				if(mascota.DNI==turno.dni)
				{
					printf("\nNombre de mascota: ");
					puts(mascota.ApeYNom);
					printf("Domicilio:");
					puts(mascota.Domicilio);
					printf("Localidad:");
					puts(mascota.Localidad);
					printf("Peso: %.2f Kg",mascota.Peso);
					printf("\nTelefono: %d",mascota.Telefono);
					printf("\n\n");		
				
					rewind(M);
					break;	
				}
				
			}
			
			//SI TENGO QUE MOSTRAR INFO DE LA MASCOTA AQUI, ABRO LA OTRA; COMPARO DNI; REWINDEO LA INFO DE MASCOTA DESPUES DE IMPRIMIRLA RE ABRO LA OTRA;
			
			//printf todos los datos\n
			//pasa al siguiente dato
			contador++;
		} 
		
		fread(&turno, sizeof(registro1), 1, T);			
	}
	fclose(M);
	fclose(T);
	system("PAUSE");
	//se carga el archivo y se muestra	
}

void registrarEvolucion()
{
	bool buscar;
	int auxDni;
	char auxEvolucion[380];
	
	printf("Buscar mascota");
	do
	{
		
	}
	while (buscar==true);
	
	//abre archivo de mascotas
	//leer
	//printf("DNI del dueño: ");//para identificar en que espacio del fichero se guardara la info, puedo usar dni o cualquier otro dato si es mas facil
	//scanf(auxDni)
	//while(!feof("turnos"))//seria turnos porque ahi se guardara la info de atencion segun el pdf
	{
		//if(auxDni==DniDelDueno)//comparara los datos si da dejara escribir en el archivo
		{
			//printear algo de info para confirmar de que mascota se trata
			
			printf("Evolucion de la mascota,(enter para finalizar");
			gets(auxEvolucion);
			//guardar en archivo
			
		}
		//fread pa pasar al siguiente dato
	}
	
	
}

bool comprobacion(int auxUsuario,char auxContrasena[20],FILE *vet)
{
	bool inicio=false;
	veterinario regVet;
	vet=fopen("Veterinarios.dat","r");
	
	fread(&regVet, sizeof(veterinario), 1, vet);

	if (vet==NULL)
	{
   		perror("No se puede abrir o no se registro ningun veterinario");
   		return -1;
	}
	while(!feof(vet))
	{
		if(auxUsuario==regVet.matricula)
		{
			printf("\nEl usuario existe");
			//a continuacion se compararia la contrasena
			inicio=true;
		}
		fread(&regVet, sizeof(veterinario), 1, vet);
		
	}
	
	if(inicio==true)
	{
		printf("Se inicio sesion correctamente");
		fclose(vet);
		return(true);
	}
	else
	{
		printf("No se pudo iniciar sesion, pruebe nuevamente");
		fclose(vet);
		return(false);
	}
	
	system("PAUSE");
	//hace falta una forma de mantener registrado el veterinario, con el aux que guarda la matricula registrada o un bool login
}
