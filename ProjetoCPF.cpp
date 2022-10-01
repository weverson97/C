#include<stdio.h>
#include<stdbool.h>
#include<string.h>
/*
    CNPJ -> vetor com os dígitos do CNPJ
    mult -> vetor com os multiplicadores, de tamanho N
    N -> Tamanho do vetor mult e também a quantidade de operações (9 ou 10)
*/
int calculaDigito(int CNPJ[], int mult[], int N)
{   int soma=0, i;
    for(i=0; i<N; i++)
	{	soma = soma + CNPJ[i]*mult[i];
	}
	return ((soma*10) % 11)%10;
}

/*
    Retorna true se todos os 11 dígitos de um CNPJ forem iguais, caso contrário,
    retorna false.
*/
bool todosRepetidos(int CNPJ[])
{   int i;
    for(i=1; i<11; i++)
    {   if(CNPJ[0]!=CNPJ[i])
            return false;
    }
    return true;
}

/*
    Imprime a região onde o CNPJ foi inscrito
*/
void imprimeRegiaoOrigem(int CNPJ[])
{   char regioes[][100] = {
        "Rio Grande do Sul",
        "Distrito Federal, Goiás, Mato Grosso, Mato Grosso do Sul e Tocantins",
        "Amazonas, Pará, Roraima, Amapá, Acre e Rondônia",
        "Ceará, Maranhão e Piauí",
        "Paraíba, Pernambuco, Alagoas e Rio Grande do Norte",
        "Bahia e Sergipe",
        "Minas Gerais",
        "Rio de Janeiro e Espírito Santo",
        "São Paulo",
        "Paraná e Santa Catarina"};
    printf("%s", regioes[ CNPJ[8] ]);
}

/*
    Lê CNPJ como string e processa adequadamente, transformando-o
    num vetor numérico, preenchendo zeros à esquerda, se necessário.
*/
void leiaCNPJ(int CNPJ[])
{   char texto[30];
    fgets(texto, 30, stdin);
    int i, j=10;
    for(i=strlen(texto)-1; i>=0; i--)
    {   if(texto[i]>='0' && texto[i]<='9')
        {
            CNPJ[j] = texto[i] - '0';
            j--;
        }
    }
    
    while(j>=0)
    {   CNPJ[j] = 0;  //zero à esquerda
        j--;
    }
}

/*
    Imprime um CNPJ com pontos e hífen nas posições corretas 
*/
void imprimeCNPJ(int CNPJ[])
{   int i;
    for(i=0; i<11; i++)
    {   printf("%d", CNPJ[i]);
        if(i==2 || i==5) printf(".");
        else if(i==8) printf("-");
    }
}

int main()
{   int CNPJ[11];
	int m1[9]={10,9,8,7,6,5,4,3,2};
	int m2[10]={11,10,9,8,7,6,5,4,3,2};
	int i;
	printf("Entre com o CNPJ: ");
	leiaCNPJ(CNPJ);
  	
	if(todosRepetidos(CNPJ) == false && calculaDigito(CNPJ, m1, 9) == CNPJ[9] &&
	   calculaDigito(CNPJ, m2, 10) == CNPJ[10])
	{  imprimeCNPJ(CNPJ);
	   printf("  ->  CNPJ válido, inscrito na seguinte região: ");
	   imprimeRegiaoOrigem(CNPJ);
	}
	else printf("\nErro no CNPJ.");
	return 0;
}

