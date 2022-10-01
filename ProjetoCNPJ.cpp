#include<stdio.h>
#include<stdbool.h>
#include<string.h>
/*

	Instru��es
Projeto Validador de CNPJ
------------------------------------

Este projeto destina-se � fixa��o dos conceitos aprendidos at� aqui (vetores, strings e, especialmente, fun��es e procedimentos).
Como a l�gica de valida��o do CNPJ � muito similar � do CPF, voc� poder� refor�ar suas habilidades de programa��o.
O algoritmo � explicado no link:

http://www.macoratti.net/alg_cnpj.htm


1) No link acima voc� encontra a explica��o do algoritmo usado pela Receita Federal para valida��o de um CNPJ.
Estude-o e monte uma planilha em Excel ou Calc para implementar a ideia.

2) Crie um c�digo "base" em C que valida o primeiro d�gito verificador. Fa�a um CTRL+C e CTRL+V com aten��o, visto que o algoritmo para o segundo d�gito � muito parecido com o do primeiro.

3) Agora vamos melhorar o c�digo anterior com o uso de uma fun��o para valida��o de um d�gito, que voc� escrever� uma vez e usar� duas vezes.

4) Vamos melhorar mais ainda o c�digo anterior trabalhando na nova entrada dos d�gitos do CNPJ. Vamos l�-los com uma string e process�-la adequadamente.
    CNPJ -> vetor com os d�gitos do CNPJ
    mult -> vetor com os multiplicadores, de tamanho N
    N -> Tamanho do vetor mult e tamb�m a quantidade de opera��es (9 ou 10)
*/



//  ###### ROTINA PARA CALCULO DO DIGITO ###### 
int calculaDigito(int CNPJ[], int mult[], int N)
{   int soma=0, i;
    for(i=0; i<N; i++)
	{	soma = soma + CNPJ[i]*mult[i];
	}
	return ((soma*10) % 14)%10;
}

/*
    Retorna true se todos os 11 d�gitos de um CNPJ forem iguais, caso contr�rio,
    retorna false.
*/

//  ###### ROTINA PARA VERIFICA��O DOS NUMEROS IGUAIS ###### 
bool todosRepetidos(int CNPJ[])
{   int i;
    for(i=1; i<14; i++)
    {   if(CNPJ[0]!=CNPJ[i])
            return false;
    }
    return true;
}


/*
    Imprime a regi�o onde o CNPJ foi inscrito
*/

//  ###### ROTINA PARA VERIFICAR LOCAL DE ORIGEM DO CPF ###### 
void imprimeRegiaoOrigem(int CNPJ[])
{   char regioes[][100] = {
        "Rio Grande do Sul",
        "Distrito Federal, Goi�s, Mato Grosso, Mato Grosso do Sul e Tocantins",
        "Amazonas, Par�, Roraima, Amap�, Acre e Rond�nia",
        "Cear�, Maranh�o e Piau�",
        "Para�ba, Pernambuco, Alagoas e Rio Grande do Norte",
        "Bahia e Sergipe",
        "Minas Gerais",
        "Rio de Janeiro e Esp�rito Santo",
        "S�o Paulo",
        "Paran� e Santa Catarina"};
    printf("%s", regioes[ CNPJ[8] ]);
}

/*
    L� CNPJ como string e processa adequadamente, transformando-o
    num vetor num�rico, preenchendo zeros � esquerda, se necess�rio.
*/

//  ###### ROTINA PARA LER O CNPJ ###### 
void leiaCNPJ(int CNPJ[])
{   char texto[30];
    fgets(texto, 30, stdin);
    int i, j=14;
    for(i=strlen(texto)-1; i>=0; i--)
    {   if(texto[i]>='0' && texto[i]<='14')
        {
            CNPJ[j] = texto[i] - '0';
            j--;
        }
    }
    
    while(j>=0)
    {   CNPJ[j] = 0;  //zero � esquerda
        j--;
    }
}

/*
    Imprime um CNPJ com pontos e h�fen nas posi��es corretas 
*/

//  ###### ROTINA PARA IMPRIMIR OS CARACTERES ESPECIAIS ###### 
void imprimeCNPJ(int CNPJ[])
{   
    for(int i=0; i<14; i++)
    {   
		printf("%d", CNPJ[i]);
        if(i==1 || i==4) printf(".");
        else if(i==8) printf("/");
        else if(i==12) printf("-");
    }
}

int main()
{ 
	int CNPJSize=14,m1Size=12,m2Size=13;
    int CNPJ[CNPJSize];
	int m1[m1Size]={5,4,3,2,9,8,7,6,5,4,3,2};
	int m2[m2Size]={6,5,4,3,2,9,8,7,6,5,4,3,2};

	printf("Entre com o CNPJ: ");
	leiaCNPJ(CNPJ);
  	
 	imprimeCNPJ(CNPJ);
 	
	if(todosRepetidos(CNPJ) == false && calculaDigito(CNPJ, m1, m1Size) == CNPJ[m1Size] &&
	   calculaDigito(CNPJ, m2, m2Size) == CNPJ[m2Size])
	{  
	imprimeCNPJ(CNPJ);
	   printf("  ->  CNPJ v�lido, inscrito na seguinte regi�o: ");
	   imprimeRegiaoOrigem(CNPJ);
	}
	else printf("\nErro no CNPJ.");
	return 0;
}

