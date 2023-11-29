#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include <regex>

using namespace std;

int entradaAlfabeto(void);
char *menu(int,char*);
char *unoPoruno(char*,char*,int*);
char *porRango(char*,char*,int*);
char *leerCadena(char*,char*,int);
int menuAlfabeto(void);
int menuAlterno(void);
void menuPrincipal(char*,char*,char*);
bool prefijo(string, string);
bool sufijo(string, string);
bool subcadena(string, string);
bool subsecuencia(string, string);
void op3(char*,char*,char*); 
void op4y5(char*,char*,char*);
void potencia(char*,char*,char*); 
void expresionesRegul(char*,char*,char*);
void expB(void);

int main (void)
{
	srand(time(NULL));
	setlocale(LC_ALL, "spanish");
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
    int menu1;
    char letrasynumeros[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
    char *alfabeto,*w1,*w2;
    cout<<"\n\t ===ALFABETOS, LENGUAJES Y EXPRESIONES REGULARES===\n"<<endl;
    menu1=entradaAlfabeto();
    system("cls");
    cout<<"\n\t ===ALFABETOS, LENGUAJES Y EXPRESIONES REGULARES===\n"<<endl;
    alfabeto=menu(menu1,letrasynumeros);
    system("cls");
    cout<<"\n\t ===ALFABETOS, LENGUAJES Y EXPRESIONES REGULARES===\n"<<endl;
    w1=leerCadena(alfabeto,letrasynumeros,1);
    w2=leerCadena(alfabeto,letrasynumeros,2);
    menuPrincipal(alfabeto,w1,w2);
}

int entradaAlfabeto(void)
{
    int opcion,i=0;
    cout<<"\t¿Como desea ingresar su alfabeto?"<<endl;
    cout<<"   1. De uno en uno"<<endl;
    cout<<"   2. Por rango"<<endl;
    while(i==0)
	{
		cout<<"   Digite una opcion: ";cin>>opcion;
        if(opcion==1||opcion==2)
		{
			return opcion;
		}
        else
		{
            cout<<"\n La opcion ingresada no es correcta, por favor ingrese una opcion valida"<<endl;
            i=0;
		}
	}
}

char *menu(int op,char *letrasynumeros)
{
    int nl=0;
    char *alfabeto;
    switch(op)
    {
        case 1: alfabeto=unoPoruno(letrasynumeros,alfabeto,&nl);
                break;
                
        case 2: alfabeto=porRango(letrasynumeros,alfabeto,&nl);
                break;
        default: break;
    }
    return alfabeto;
}

char *unoPoruno(char *letrasynumeros,char *alfabeto,int *nl)
{
	int x,y,comp;
	char *alf;
	fflush(stdin);
    cout<<"\n   ¿Cuantos elementos va a ingresar a su alfabeto?: ";cin>>*nl;
    alf=(char*)malloc((*nl+1)*sizeof(char));
    memset(alf,0,*nl);
    alf[*nl]='\0';
    if(alf==NULL)
	{
		cout<<"\n\tNo se pudo reservar la memoria necesaria... se reiniciara el programa"<<endl;
		exit(-1);
	}
    if(*nl!=0)
    {
    	system("cls");
    	cout<<"\n\t ===ALFABETOS, LENGUAJES Y EXPRESIONES REGULARES===\n"<<endl;
        cout<<"\n   Digite el alfabeto uno por uno: \n"<<endl;
        for(x=0; x<(*nl) ;x++)
        {
        	comp=0;
        	fflush(stdin);
            cout<<"   Digite el "<<x+1<<" elemento del alfabeto: ";cin>>alf[x];
            for(y=0;y<strlen(letrasynumeros);y++)
            {
            	if(alf[x]==letrasynumeros[y])
            	{
            		comp=1;
            		y=strlen(letrasynumeros);
            		break;
				}
			}
			if(comp==0)
			{
				cout<<"\n\t El elemento no es ni un numero ni una letra, por favor ingrese otro"<<endl;
				x--;
			}
        }
    }
    return alf;
}

char *porRango(char *letrasynumeros,char *alfabeto,int *nl)
{
	int x=0,y,comp,count=0;
	char temp1='\0',temp2='\0',temp3='\0',temp4='\0',temp5='\0',temp6='\0';
	char *alf;
	string cadena;
	fflush(stdin);
    cout<<"\n   Digite su rango (a-z,A-Z,0-9): ";cin>>cadena;
    while(cadena[x]!='\0')
    {
    	count++;
    	x++;
	}
	if(count<=3)
	{
		temp1=cadena[0];
    	temp2=cadena[2];
	}
	else if(count<=7)
	{
		temp1=cadena[0];
    	temp2=cadena[2];
		temp3=cadena[4];
		temp4=cadena[6];
	}
	else
	{
		temp1=cadena[0];
    	temp2=cadena[2];
		temp3=cadena[4];
		temp4=cadena[6];
		temp5=cadena[8];
		temp6=cadena[10];
	}
	x=0;
	count=0;
	while(x<strlen(letrasynumeros))
	{
		if(temp1==letrasynumeros[x])
		{
			while(temp2!=letrasynumeros[x])
			{
				count++;
				x++;
			}
			if(temp2==letrasynumeros[x])
			{
				count++;
			}
			x=strlen(letrasynumeros);
		}
		x++;
	}
	x=0;
	while(x<strlen(letrasynumeros))
	{
		if(temp3==letrasynumeros[x])
		{
			while(temp4!=letrasynumeros[x])
			{
				count++;
				x++;
			}
			if(temp4==letrasynumeros[x])
			{
				count++;
			}
			x=strlen(letrasynumeros);
		}
		x++;
	}
	x=0;
	while(x<strlen(letrasynumeros))
	{
		if(temp5==letrasynumeros[x])
		{
			while(temp6!=letrasynumeros[x])
			{
				count++;
				x++;
			}
			if(temp6==letrasynumeros[x])
			{
				count++;
			}
			x=strlen(letrasynumeros);
		}
		x++;
	}
	alf=(char*)malloc((count+1)*sizeof(char));
    memset(alf,0,count);
    alf[count]='\0';
    if(alf==NULL)
	{
		cout<<"\n\tNo se pudo reservar la memoria necesaria... se reiniciara el programa"<<endl;
		exit(-1);
	}
	x=0;
	y=0;
	while(x<strlen(letrasynumeros))
	{
		if(temp1==letrasynumeros[x])
		{
			while(temp2!=letrasynumeros[x])
			{
				fflush(stdin);
				alf[y]=letrasynumeros[x];
				y++;
				x++;
			}
			fflush(stdin);
			alf[y]=letrasynumeros[x];
			y++;
			x=strlen(letrasynumeros);
		}
		x++;
	}
	x=0;
	while(x<strlen(letrasynumeros))
	{
		if(temp3==letrasynumeros[x])
		{
			while(temp4!=letrasynumeros[x])
			{
				fflush(stdin);
				alf[y]=letrasynumeros[x];
				y++;
				x++;
			}
			fflush(stdin);
			alf[y]=letrasynumeros[x];
			y++;
			x=strlen(letrasynumeros);
		}
		x++;
	}
	x=0;
	while(x<strlen(letrasynumeros))
	{
		if(temp5==letrasynumeros[x])
		{
			while(temp6!=letrasynumeros[x])
			{
				fflush(stdin);
				alf[y]=letrasynumeros[x];
				y++;
				x++;
			}
			fflush(stdin);
			alf[y]=letrasynumeros[x];
			x=strlen(letrasynumeros);
		}
		x++;
	}
    return alf;
}

char *leerCadena(char *alfabeto,char *letrasynumeros,int n)
{
	string w1;
	char *cad;
	int x,y,count,comp=0;
	while(comp==0)
	{
		x=0;
		count=0;
		fflush(stdin);
    	cout<<"\tDigite los elementos de W"<<n<<": ";cin>>w1;
    	while(w1[x]!='\0')
  		{
    		for(y=0;y<strlen(alfabeto);y++)
    		{
    			if(w1[x]==alfabeto[y])
    			{
    				count++;
    				y=strlen(alfabeto);
				}
			}
    		x++;
		}
		if(count!=x)
		{
			cout<<"\n  No existen dichos elementos en el alfabeto, la cadena W"<<n<<" ingresada es incorrecta\n"<<endl;
			comp=0;
		}
		else
		{
			comp=1;
		}
	}
	cad=(char*)malloc((x+1)*sizeof(char));
	memset(cad,0,x);
    cad[x]='\0';
	if(cad==NULL)
	{
		cout<<"\n\tNo se pudo reservar la memoria necesaria... se reiniciara el programa"<<endl;
		exit(-1);
	}
	x=0;
	while(w1[x]!='\0')
  	{
    	for(y=0;y<strlen(alfabeto);y++)
    	{
    		if(w1[x]==alfabeto[y])
    		{
    			fflush(stdin);
    			cad[x]=alfabeto[y];
    			y=strlen(alfabeto);
			}
		}
    	x++;
	}
	return cad;
}

int menuAlfabeto(void)
{
	int op;
	system("cls");
    cout<<"\n\t ===ALFABETOS, LENGUAJES Y EXPRESIONES REGULARES===\n"<<endl;
	cout<<"\t1. Comparar W1 y W2 (subfijo,subcadena,prefijo,subsecuencia)"<<endl;
	cout<<"\t2. Generar 2 lenguajes y diferencia"<<endl;
	cout<<"\t3. Potencia del alfabeto"<<endl;
	cout<<"\t4. Expresiones regulares"<<endl;
	cout<<"\t5. Salir"<<endl;
	cout<<"\n  Digite una opcion: ";cin>>op;
	if(op<1||op>5)
	{
		cout<<"\n\t La opcion no esta en la lista...";
		op=menuAlfabeto();
	}
	return op;
}

void menuPrincipal(char *alfabeto,char *w1,char *w2)
{
	int op;
	op=menuAlfabeto();
	switch(op)
	{
		case 1: op3(alfabeto,w1,w2);
			break;
		case 2: op4y5(alfabeto,w1,w2);
			break;
		case 3: potencia(alfabeto,w1,w2);
			break;
		case 4: expresionesRegul(alfabeto,w1,w2);
			break;
		case 5: free(alfabeto);
    			free(w1);
    			free(w2);
				exit(-1);
			break;
	}
}

void op3(char *alfabeto,char *w1,char *w2) 
{
    system("cls");
    cout<<"\n\t ===ALFABETOS, LENGUAJES Y EXPRESIONES REGULARES==="<<endl;
    cout <<"\n   =CADENAS COMPARADAS= " << endl;
    if (prefijo(w1,w2)) 
	{
        cout<< "\t - "<<w1<<" si es prefijo de "<<w2<<endl;
    } 
	else 
	{
        cout<<"\t - "<<w1<<" no es prefijo de "<<w2<<endl;
    }
    if (sufijo(w1, w2)) 
	{
        cout<<"\t - "<<w1<<" si es sufijo de "<<w2<<endl;
    } 
	else 
	{
        cout<<"\t - "<<w1<<" no es sufijo de "<<w2<<endl;
    }
    if (subcadena(w1, w2)) 
	{
        cout<<"\t - "<<w1<<" si es subcadena de "<<w2<<endl;
    } 
	else 
	{
        cout<<"\t - "<<w1<<" no es subcadena de "<<w2<<endl;
    }
    
    if (subsecuencia(w1, w2))
	{
        cout<<"\t - "<<w1<<" si es subsecuencia de "<<w2<<endl;
    } 
	else 
	{
        cout<<"\t - "<<w1<<" no es subsecuencia de "<<w2<<endl;
    }
    cout<<"\n   ";
	system("pause");
    menuPrincipal(alfabeto,w1,w2);
}

bool subsecuencia(string a, string b)
{
    bool band = true;
    int cont=0,k=0;
    for (int i = 0; i < b.length(); i++) 
	{
        if (a[k] == b[i]) 
		{
            while(k<a.length())
			{
                cont++;
                k++;
            }
        }
    }
    if (cont>=a.length())
	{
        band = true;
    }
	else
	{
        band = false;
    }
    return band;
}

bool subcadena(string a, string b)
{
    bool band = false;
    int k = 0;
    for (int i = 0; i < b.length(); i++) 
	{
        if (a[k] == b[i]) 
		{
            for (int j = i; j < b.length(); j++)
			{
                if(a[k]==b[j])
				{
                    k++;
                    if(k==a.length())
					{
                        return true;
                    }
                }
				else
				{
                    k = 0;
                    band = false;
                    break;
                }
            }
        }
    }
    return band;
}

bool prefijo(string a, string b)
{
    bool band = true;
    for (int i = 0; i < a.length(); i++) 
	{
        if (!(a[i] == b[i])) 
		{
            band = false;
            break;
        }
    }
    return band;
}

bool sufijo(string a, string b) 
{
    bool band = true;
    string w1 = a, w2 = b; 
    reverse(w1.begin(), w1.end());
    reverse(w2.begin(), w2.end());
    for (int i = 0; i < w1.length(); i++) 
	{
        if (!(w1[i] == w2[i])) 
		{
            band = false;
            break;
        }
    }
    return band;
}

void op4y5(char *alfabeto,char *w1,char *w2)
{
	int np[2],l[2],x,y,k,num,z;
	string *L1,*L2,*Ld;
	char cadenaTemporal[2],*cadenaTemporal2,*cadenaTemporal3;
	system("cls");
    cout<<"\n\t ===ALFABETOS, LENGUAJES Y EXPRESIONES REGULARES==="<<endl;
    cout<<"\n   En caso de que los lenguajes tengan la misma longitud se realizara la diferencia"<<endl;
    for(x=0;x<2;x++)
    {
    	fflush(stdin);
   		cout<<"\n   Ingrese la longitud de las palabras: ";cin>>l[x];
   		fflush(stdin);
		cout<<"   Ingrese la cantidad de palabras: ";cin>>np[x];
	}
	cadenaTemporal2=(char*)malloc((l[0]+1)*sizeof(char));
	memset(cadenaTemporal2,0,l[0]);
    cadenaTemporal2[l[0]]='\0';
	cadenaTemporal3=(char*)malloc((l[1]+1)*sizeof(char));
	memset(cadenaTemporal3,0,l[1]);
    cadenaTemporal3[l[1]]='\0';
	L1=new string[np[0]];
	L2=new string[np[1]];
	if(L1==NULL||L2==NULL||cadenaTemporal2==NULL||cadenaTemporal3==NULL)
	{
		cout<<"\n\tNo se pudo reservar la memoria necesaria... se reiniciara el programa"<<endl;
		exit(-1);
	}
	for(y=0;y<np[0];y++)
   	{
   		memset(cadenaTemporal2,0,l[0]);
   		for(z=0;z<l[0];z++)
   		{
   			num=rand()%strlen(alfabeto);
   			fflush(stdin);
			cadenaTemporal[0] = alfabeto[num];
			fflush(stdin);
			cadenaTemporal[1] = '\0';
			fflush(stdin);
			strcat(cadenaTemporal2,cadenaTemporal);
		}
		fflush(stdin);
		L1[y]=cadenaTemporal2;
		for(z=1;z<=y;z++)
		{
			if(L1[z-1].compare(L1[z])==0)
			{
				y--;
			}
		}
	}
	for(y=0;y<np[1];y++)
   	{
   		memset(cadenaTemporal3,0,l[1]);
   		for(z=0;z<l[1];z++)
   		{
   			num=rand()%strlen(alfabeto);
   			fflush(stdin);
			cadenaTemporal[0] = alfabeto[num];
			fflush(stdin);
			cadenaTemporal[1] = '\0';
			fflush(stdin);
			strcat(cadenaTemporal3,cadenaTemporal);
	 	}
		fflush(stdin);
		L2[y]=cadenaTemporal3;
		for(z=1;z<=y;z++)
		{
			if(L2[z-1].compare(L2[z])==0)
			{
				y--;
			}
		}
 	}
	cout<<"\n   Lenguaje L1: ";
	for (x=0;x<np[0];x++)
	{
        cout <<L1[x];
        if(x!=(np[0]-1))
        {
        	cout<<",";
		}
    }
    cout<<"\n   Lenguaje L2: ";
    for (x=0;x<np[1];x++) 
	{
        cout <<L2[x];
        if(x!=(np[1]-1))
        {
        	cout<<",";
		}
    }
    cout<<endl;
    if(l[0]==l[1])
    {
    	z=1;
    	for(x=0;x<np[0];x++)
    	{
    		num=0;
    		for(y=0;y<np[1];y++)
    		{
    			if(L1[x].compare(L2[y])==0)
    			{
    				num=1;
				}
			}
			if(num==0)
			{
				z++;
			}
		}
		Ld=new string[z];
		k=0;
    	for(x=0;x<np[0];x++)
    	{
    		num=0;
    		for(y=0;y<np[1];y++)
    		{
    			if(L1[x].compare(L2[y])==0)
    			{
    				num=1;
				}
			}
			if(num==0)
			{
				Ld[k]=L1[x];
    			k++;
			}
		}
		cout<<"\n   Lenguaje Ld: ";
    	for (x=0;x<k;x++)
		{
       		cout <<Ld[x];
        	if(x!=k-1)
       		{
        		cout<<",";
			}
		}
		delete(Ld);
	}
	else
	{
		cout<<"\n\n No se ingreso una longitud igual, no se puede realizar diferencia"<<endl;
	}
	cout<<"\n\n   ";
	system("pause");
    free(cadenaTemporal2);
    free(cadenaTemporal3);
	delete(L1);
    delete(L2);
    menuPrincipal(alfabeto,w1,w2);
}

void potencia(char *alfabeto,char *w1,char *w2) 
{
	system("cls");
    cout<<"\n\t ===ALFABETOS, LENGUAJES Y EXPRESIONES REGULARES===\n"<<endl;
    string cad, *resultados, *aux;
    int pot, tam, cont = 1,j = 0,k = 0,z;  
    char cadenaTemporal[2],*cadenaTemporal2;
	cadenaTemporal2=(char*)malloc(strlen(alfabeto)*sizeof(char));
	memset(cadenaTemporal2,0,strlen(alfabeto)-1);
    cadenaTemporal2[strlen(alfabeto)-1]='\0';
	if(cadenaTemporal2==NULL)
	{
		cout<<"\n\tNo se pudo reservar la memoria necesaria... se reiniciara el programa"<<endl;
		exit(-1);
	}
  	for(z=0;z<strlen(alfabeto);z++)
  	{
   		fflush(stdin);
		cadenaTemporal[0] = alfabeto[z];
		fflush(stdin);
		cadenaTemporal[1] = '\0';
		fflush(stdin);
		strcat(cadenaTemporal2,cadenaTemporal);
	}
	fflush(stdin);
	cad=cadenaTemporal2;
	    
    cout<<" Digite un numero para la potencia: ";cin >> pot;
    if (pot < 0) 
	{
        reverse(cad.begin(), cad.end());  
        pot *= (-1);
    }
    tam = pow(cad.length(), pot);
    resultados = new string[tam];
    aux = new string[tam];
    for (int i = 0; i < cad.length(); i++) 
	{
        aux[i] = cad[i];
    }
    if (pot == 1) 
	{  
        for (int i = 0; i < tam; i++) 
		{
            resultados[i] = aux[i];
        }
    } 
	else 
	{ 
        while (cont < pot) 
		{
            cont++;
            j = 0;                                               
            k = 0;                                               
            for (int i = 0; i < pow(cad.length(), cont); i++) 
			{  
                resultados[i] = (aux[j] + cad[k]);
                j++;
                if (j == pow(cad.length(), cont - 1)) 
				{
                    j = 0;
                    k++;
                }
            }
            for (int i = 0; i < pow(cad.length(), cont); i++) 
			{
                aux[i] = resultados[i];
            }
        }
    }
    cout <<"\n   Resultado: \n"<<endl;
    for (int i = 0; i < tam; i++) 
	{
        cout<<" "<<resultados[i];
    }
    delete[] resultados;
    delete[] aux;
    free(cadenaTemporal2);
    cout<<"\n\n   ";
	system("pause");
    menuPrincipal(alfabeto,w1,w2);
}

void expresionesRegul(char *alfabeto,char *w1,char *w2)
{
	int op;
	op=menuAlterno();
	switch(op)
	{
		case 1: expB();
			break;
	}
	menuPrincipal(alfabeto,w1,w2);
}

int menuAlterno(void)
{
	int op;
	system("cls");
    cout<<"\n\t ===ALFABETOS, LENGUAJES Y EXPRESIONES REGULARES===\n"<<endl;
	cout<<"\t1. Identificar si se repite algun digito"<<endl;
	cout<<"\n  Digite una Opcion: ";cin>>op;
	if(op<1||op>2)
	{
		cout<<"\n\t La opcion no existe...";
		op=menuAlterno();
	}
	return op;
}

void expB(void)
{
	string num;
	system("cls");
    cout<<"\n\t ===ALFABETOS, LENGUAJES Y EXPRESIONES REGULARES===\n"<<endl;
	fflush(stdin);
    cout<<"   Digite la cadena a Identificar: ";cin>>num;
    if(std::regex_match(num,std::regex("^\\d*?(\\d)\\d*?\\1\\d*"))==true&&num.length()>=5)
    {
    	cout<<"\n   La cadena es valida"<<endl;
	}
	else
	{
		cout<<"\n   La cadena es invalida"<<endl;
	}
	cout<<"\n   ";
	system("pause");
}