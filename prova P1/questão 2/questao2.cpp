#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
FILE *f, *s;
typedef struct _Registro Registro;
struct _Registro
{
	char chave[8];
	char nome[40];
	char email[40];
	char telefone[12];
	char qurbralinha[1];
};
int terminarCom(char* a, char* b);


int main (int argc, char ** argv){
	Registro registro;
	long ultimo=0;
	f = fopen ("arq1.dat","r");
	s = fopen("arq2.dat","w");
	fseek(f,0,SEEK_END);
	ultimo = ((ftell(f))/sizeof(registro));
	cout << "Numero de registro:" <<ultimo<< "\n";
	cout << "Tamanho do arquivo :" << (ftell(f))<<"\n";

	for (int i=0; i<ultimo; i++)
    {
		fseek(f, i*sizeof(Registro),SEEK_SET);
		cout <<"posicao "<< i*sizeof(registro)<<"\n";
		fread (&registro, sizeof(Registro),1,f);
		cout <<"Registro lido "<<registro.chave <<"\n";
		if (terminarCom(registro.email,"gmail.com"))
        {   fwrite (&registro, sizeof(Registro),1,s);
            cout <<"Email terminado com gmail.com, registro gravado" << "\n";
        }


	}
	 system("pause");

	fclose(f);
	fclose(s);
}

int terminarCom(char* a, char* b)
{   int cti=0;
    int cta=0;

    while (a[cti]!=' ')
    { cti++;
    }
    while (a[cta]!='@')
    {cta++;
    }
    for (int i=0; i<strlen(b); i++)
    {
        if (a[i+(cti-strlen(b))]!=b[i])
        {
            return 0;
        }
    }
    return 1;
}

