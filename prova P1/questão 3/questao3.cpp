#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
FILE *f, *f1, *s;
typedef struct _Registro Registro;
struct _Registro
{
	char chave[8];
	char nome[40];
	char email[40];
	char telefone[12];
	char quebralinha[1];
};
Registro registro;
Registro r;
long posicao, primeiro, ultimo1, meio;
int buscareg();

int main (int argc, char ** argv)
{
    int ultimo=0;
	f = fopen ("arq1.dat","r");
    f1 = fopen ("arq2.dat","r");
    s = fopen("arq3.dat","w");

	fseek(f,0,SEEK_END);
	ultimo = ((ftell(f))/sizeof(Registro));
	fseek(f1,0,SEEK_END);
	posicao = ftell(f1);
	primeiro = 0;
	ultimo1 = (posicao/sizeof(Registro))-1;
   	meio = (primeiro+ultimo1)/2;

	printf("Tamanho do Arquivo: %ld\n", ftell(f));
	printf("Tamanho do Registro: %ld\n", sizeof(Registro));
	printf("Tamanho do Arquivo em Registros: %ld\n\n", ultimo);

	rewind (f);
	for (int i=0; i<ultimo; i++)
    {	fseek(f, i*sizeof(Registro), SEEK_SET);
        cout <<"Posicao para leitura: "<<ftell(f)<< "\n";
		fread (&registro, sizeof(Registro),1,f);
		cout <<"Registro lido "<<registro.chave ;
		if (buscareg())
        {
            fwrite (&registro, sizeof(Registro),1,s);
            cout <<"Registro gravado\n\n";
        }
        fseek(f1,0,SEEK_END);
        posicao = ftell(f1);
        primeiro = 0;
        ultimo1 = (posicao/sizeof(Registro))-1;
        meio = (primeiro+ultimo1)/2;

	}
	 system("pause");

	fclose(f);
	fclose(f1);
	fclose(s);
}

int buscareg()
{
    fseek(f1, meio*sizeof(Registro), SEEK_SET);
    fread(&r,sizeof(Registro),1,f1);
	//cout << "Registor,r   :"<< registro.chave<< "              " << r.chave<<"\n";
    if( strncmp(registro.chave,r.chave,8)==0)
    {
        return 1;
    }
    else
    {   if ((atol(registro.chave) < atol(r.chave)) && !(primeiro==meio && ultimo1==primeiro+1) )
        {   ultimo1 = meio;
            meio = (primeiro+ultimo1)/2;
            buscareg();
        }
        else
        {   if ((atol(registro.chave) > atol(r.chave))&& !(primeiro==meio && ultimo1==primeiro+1))
            {   primeiro=meio;
                meio = (primeiro+ultimo1)/2;
                buscareg();
            }
            else
            {
                    cout <<"Registro nao localizado no arqiovo rq2.dat...."<<"\n\n";
                    return 0;
            }

        }

    }


}


