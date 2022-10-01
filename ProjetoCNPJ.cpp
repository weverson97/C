#include<stdio.h>
#include<stdbool.h>
#include<string.h>
/*

	Instruções
Projeto Validador de CNPJ
------------------------------------

Este projeto destina-se à fixação dos conceitos aprendidos até aqui (vetores, strings e, especialmente, funções e procedimentos).
Como a lógica de validação do CNPJ é muito similar à do CPF, você poderá reforçar suas habilidades de programação.
O algoritmo é explicado no link:

http://www.macoratti.net/alg_cnpj.htm


1) No link acima você encontra a explicação do algoritmo usado pela Receita Federal para validação de um CNPJ.
Estude-o e monte uma planilha em Excel ou Calc para implementar a ideia.

2) Crie um código "base" em C que valida o primeiro dígito verificador. Faça um CTRL+C e CTRL+V com atenção, visto que o algoritmo para o segundo dígito é muito parecido com o do primeiro.

3) Agora vamos melhorar o código anterior com o uso de uma função para validação de um dígito, que você escreverá uma vez e usará duas vezes.

4) Vamos melhorar mais ainda o código anterior trabalhando na nova entrada dos dígitos do CNPJ. Vamos lê-los com uma string e processá-la adequadamente.
    CNPJ -> vetor com os dígitos do CNPJ
    mult -> vetor com os multiplicadores, de tamanho N
    N -> Tamanho do vetor mult e também a quantidade de operações (9 ou 10)
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
    Retorna true se todos os 11 dígitos de um CNPJ forem iguais, caso contrário,
    retorna false.
*/

//  ###### ROTINA PARA VERIFICAÇÃO DOS NUMEROS IGUAIS ###### 
bool todosRepetidos(int CNPJ[])
{   int i;
    for(i=1; i<14; i++)
    {   if(CNPJ[0]!=CNPJ[i])
            return false;
    }
    return true;
}


/*
    Imprime a região onde o CNPJ foi inscrito
*/

//  ###### ROTINA PARA VERIFICAR LOCAL DE ORIGEM DO CPF ###### 
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
    {   CNPJ[j] = 0;  //zero à esquerda
        j--;
    }
}

/*
    Imprime um CNPJ com pontos e hífen nas posições corretas 
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
	   printf("  ->  CNPJ válido, inscrito na seguinte região: ");
	   imprimeRegiaoOrigem(CNPJ);
	}
	else printf("\nErro no CNPJ.");
	return 0;
}

