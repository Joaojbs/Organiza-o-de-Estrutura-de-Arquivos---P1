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
	char quebralinha[1];
};

int main (int argc, char ** argv){

	Registro registro;
	long ultimo=0;
	f = fopen ("arq1.dat","r");
	s = fopen("arq2.dat","w");
	fseek(f,0,SEEK_END);
	ultimo = ((ftell(f))/sizeof(registro))-1;
	cout << "Numero de registro:" <<ultimo+1<< "\n";
	cout << "Tamanho do arquivo :" << (ftell(f))<<"\n";

	while (ultimo >=0){
		fseek(f, ultimo*sizeof(Registro),SEEK_SET);
		cout <<"posicao "<< ultimo*sizeof(registro)<<"\n";
		fread (&registro, sizeof(Registro),1,f);
		cout <<"Registro lido "<<registro.chave <<"\n";
		fwrite (&registro, sizeof(Registro),1,s);
		ultimo --;
	}
	 system("pause");

	fclose(f);
	fclose(s);
}

