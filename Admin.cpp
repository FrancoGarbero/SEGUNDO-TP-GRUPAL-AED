#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct usuario{
	char user[10];
	char contra[32];
	char apynom[60];
};

struct veterinario{
	char apynom[60];
	int matricula;
	int dni;
	int telefono;
	char contra[32];
};

int menuPrincipal();
void registroVet(FILE *archVet);
void comprobarContVet(veterinario regVet, int &b,char auxCont[32]);
void registroAsist(FILE *archUs);
void comprobarUserAsist(usuario regUs, int &b,FILE *&archUs,char auxUs[10]);
void comprobarContAsist(usuario regUs, int &b,char auxC[32]);
int usuarioRepetido(FILE *&archUs, usuario regUs,char auxUs[10]);
int atenciones();
int ranking();

main()
{
	FILE *archUs = fopen("Usuarios.dat","r+b");
	if(archUs == NULL){
		fclose(archUs);
		archUs = fopen("Usuarios.dat","a+b");
	}
	
	FILE *archVet = fopen("Veterinarios.dat","r+b");
	if(archVet == NULL){
		fclose(archVet);
		archVet = fopen("Veterinarios.dat","a+b");
	}
	
	veterinario revVet;
	usuario regUs;
		
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
	archVet=fopen("Veterinarios.dat","r+b");
	veterinario regVet;
	int b;
	char auxCont[32];
	
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
	printf("\n\n\t\t Requisitos de la contrasenia para ingreso\n");
	printf("\n\n\t *Debe contener como m�nimo una letra mayuscula, una minuscula y un numero\n");
	printf("\n\n\t *Debe tener entre 6-32 caracteres\n");	
	printf("\n\n\t *Solo puede contener caracteres alfanumericos\n");
	printf("\n\n\t *No debe tener mas de 3 caracteres numericos consecutivos\n");
	printf("\n\n\t *No debe tener 2 letras consecutivas ascendentes\n");
	
	_flushall();
	b=0;
	while (b==0)
	{
		printf("\n\n\t\t Contrasenia: ");
		gets(auxCont);
		comprobarContVet(regVet,b,auxCont);
	}	
	
	fwrite(&regVet, sizeof(veterinario), 1, archVet);
	fclose(archVet);
	
}

void comprobarContVet(veterinario regVet, int &b,char auxCont[32])
{
	char aux,aux1;
	int largo,min=0,may=0,num=0;
	FILE *archVet;
	
	largo = strlen(auxCont);
	if(largo>= 6 && largo <= 32)
	{
		for(int i=0;i<largo;i++)
		{
			if(isalnum(auxCont[i])==0)
			{
				num=1;
			}	
		}
		if(num==0)
		{
			for(int i=0;i<largo;i++)
			{
				if(isupper(auxCont[i])!=0)
				{
					may=1;
				}
				else if(islower(auxCont[i])!=0)
				{
					min=1;
				}
				else if(isdigit(auxCont[i])!=0)
				{
					num=1;
				}
			}
			if(num==1 && min==1 && may==1)
			{
				num=0;
				may=0;
				for(int i=0;i<largo;i++)
				{
					if(isdigit(auxCont[i])!=0)
					{
						num++;
						if(num==4)
						{
							may=1;
							i=largo;
						}
					}
					else if(isalpha(auxCont[i])!=0)
					{
						num=0;
					}
				}
				if(may==0)
				{
					num=0;
					for(int i=0;i<largo;i++)
					{
						if(isalpha(auxCont[i])!=0)
						{
							num++;
							if(num==2)
							{
								aux = toupper(auxCont[i]);
								aux1 = toupper(auxCont[i-1]);
								
								if(aux1 == aux-1)
								{
									may=1;
									i=largo;
								}
							}
						}
						else
						{
							num=0;
						}
					}
					if(may==0)
					{
						b=1;
					}
					else
					{
						printf("\n\tError: No puede ingresar dos letras consecutivas ascendentes\n");
					}
				}
				else
				{
					printf("\n\tError: No debe tener mas de 3 caracteres numericos consecutivos\n");
				}	
			}
			else
			{
				printf("\n\tError: Debe contener al menos una letra mayuscula, una letra minuscula y un numero\n");
			}
		}
		else
		{
			printf("\n\tError: Solo debe ingresar caracteres alfanumericos\n");
		}
	}
	else
	{
		printf("\n\tError: la contrasenia debe tener entre 6-32 caracteres\n");
	}
	
	strcpy(regVet.contra,auxCont);		
	fwrite(&regVet,sizeof(veterinario),1,archVet);
}

void registroAsist(FILE *archUs)
{
	usuario regUs;
	archUs = fopen("Usuarios.dat","r+b");
	int b;
	char auxUs[10],auxC[32];
	
	_flushall();
	system("CLS");
	printf("\n\n\t\t");
	printf("\n\n\t\t           INICIO REGISTRO ASISTENTE                  ");
	printf("\n\n\t\t======================================================");
	printf("\n\n\t\t Ingrese Apellido y nombre: ");
	gets(regUs.apynom);
	printf("\n\n\t\t Requisitos del usuario para ingreso: ");
	printf("\n\n\t\t *Debe ser unico");
	printf("\n\n\t\t *Debe comenzar con una letra min�scula");
	printf("\n\n\t\t *Debe tener al menos 2 letras mayusculas");
	printf("\n\n\t\t *Debe tener como m�ximo 3 digitos");
	printf("\n\n\t\t *Debe tener entre 6-10 caracteres");
	
	_flushall();
	b=0;
	while(b==0)
	{
		printf("\n\n\t\t Usuario: ");
		gets(auxUs);
		comprobarUserAsist(regUs,b,archUs,auxUs);
	}

	printf("\n\n\t\t Requisitos de la contrasenia para ingreso\n");
	printf("\n\n\t *Debe contener como m�nimo una letra mayuscula, una minuscula y un numero\n");
	printf("\n\n\t *Debe tener entre 6-32 caracteres\n");	
	printf("\n\n\t *Solo puede contener caracteres alfanumericos\n");
	printf("\n\n\t *No debe tener mas de 3 caracteres numericos consecutivos\n");
	printf("\n\n\t *No debe tener 2 letras consecutivas ascendentes\n");
	
	_flushall();
	b=0;
	while (b==0)
	{
		printf("\n\n\t\t Contrasenia: ");
		gets(auxC);
		comprobarContAsist(regUs,b,auxC);
	}
	
	fwrite(&regUs, sizeof(usuario), 1, archUs);
	
	fclose(archUs);
}

int usuarioRepetido(FILE *&archUs, usuario regUs,char auxUs[10])
{

	int b=1;
	
	rewind(archUs);
	fread(&regUs,sizeof(usuario),1,archUs);
	while(!feof(archUs))
	{
		if(strcmp(regUs.user,auxUs)==0)
		{
			return b=0;
		}
		fread(&regUs,sizeof(usuario),1,archUs);
	}
	return b;
}

void comprobarUserAsist(usuario regUs, int &b,FILE *&archUs,char auxUs[10])
{
	int largo,rep,c=0;
	
	largo = strlen(auxUs);
	rep = usuarioRepetido(archUs,regUs,auxUs);
	if(rep==1)
	{
		if(largo>= 6 && largo<=10)
		{
			if(islower(auxUs[0])!=0)
			{
				for(int i=0;i<largo;i++)
				{
					if(isupper(auxUs[i])!=0)
					{
						c++;
					}
				}
				if(c>=2)
				{
					c=0;
					for(int i=0;i<largo;i++)
					{
						if(isdigit(auxUs[i])!=0)
						{
							c++;
						}
					}
					if(c<=3)
					{
						b=1;
					}
					else
					{
						printf("\n\tError: No puede contener mas de 3 digitos consecutivos\n");
					}
				}
				else
				{
					printf("\n\tError: Debe contener como minimo 2 letras mayusculas\n");
				}
			}
			else
			{
				printf("\n\tError: La primer letra debe ser minuscula\n");
			}
		}
		else
		{
			printf("\n\tError: El usuario ingresado debe contener entre 6-10 caracteres\n");
		}
	}
	else
	{
		printf("\n\tError: el usuario ingresado ya existe\n");
	}
	
	strcpy(regUs.user,auxUs);
	fwrite(&regUs,sizeof(usuario),1,archUs);
}

void comprobarContAsist(usuario regUs, int &b,char auxC[32])
{
	char aux,aux1;
	int largo,min=0,may=0,num=0;
	FILE *archUs;
	
	largo = strlen(auxC);
	if(largo>= 6 && largo <= 32)
	{
		for(int i=0;i<largo;i++)
		{
			if(isalnum(auxC[i])==0)
			{
				num=1;
			}	
		}
		if(num==0)
		{
			for(int i=0;i<largo;i++)
			{
				if(isupper(auxC[i])!=0)
				{
					may=1;
				}
				else if(islower(auxC[i])!=0)
				{
					min=1;
				}
				else if(isdigit(auxC[i])!=0)
				{
					num=1;
				}
			}
			if(num==1 && min==1 && may==1)
			{
				num=0;
				may=0;
				for(int i=0;i<largo;i++)
				{
					if(isdigit(auxC[i])!=0)
					{
						num++;
						if(num==4)
						{
							may=1;
							i=largo;
						}
					}
					else if(isalpha(auxC[i])!=0)
					{
						num=0;
					}
				}
				if(may==0)
				{
					num=0;
					for(int i=0;i<largo;i++)
					{
						if(isalpha(auxC[i])!=0)
						{
							num++;
							if(num==2)
							{
								aux = toupper(auxC[i]);
								aux1 = toupper(auxC[i-1]);
								
								if(aux1 == aux-1)
								{
									may=1;
									i=largo;
								}
							}
						}
						else
						{
							num=0;
						}
					}
					if(may==0)
					{
						b=1;
					}
					else
					{
						printf("\n\tError: No puede ingresar dos letras consecutivas ascendentes\n");
					}
				}
				else
				{
					printf("\n\tError: No debe tener mas de 3 caracteres numericos consecutivos\n");
				}	
			}
			else
			{
				printf("\n\tError: Debe contener al menos una letra mayuscula, una letra minuscula y un numero\n");
			}
		}
		else
		{
			printf("\n\tError: Solo debe ingresar caracteres alfanumericos\n");
		}
	}
	else
	{
		printf("\n\tError: la contrasenia debe tener entre 6-32 caracteres\n");
	}
	
	strcpy(regUs.contra,auxC);
	fwrite(&regUs,sizeof(usuario),1,archUs);
}

int atenciones()
{
	
}

int ranking()
{
	
}
