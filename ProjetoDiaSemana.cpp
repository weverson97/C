#include <stdio.h>
#include <locale.h>
        //decida se vai usar A1 ou A2
    	//com o mês eu terei uma coluna na matriz B
    	// (Janeiro é mês 1 mas corresponde à coluna 0,
    	// Fevereiro é mês 2 mas corresponde à coluna 1, ........)
    	//some o dia de nascimento com o valor encontrado na matriz B
    	//procure este último cálculo na matriz C   ------> linha
    	// linha == 0 ---> Domingo
    	// linha == 1 ---> Segunda 
    	// ....
   
int procurarLinha(int L, int C, int mat[L][C], int proc)
{   int l, c;
    for(l=0;l<L;l++)
    {  for(c=0;c<C;c++)
        {   if(mat[l][c]== proc)
            {   return l;
            }
        }
    }
}

int procurarConteudoLinha(int x, int y, int mat[x][y])
{ 
   return mat[x][y];
}

//Calendário permanente de 1901 a 2092
    
    int B[28][12]=
	{{4,0,0,3,5,1,3,6,2,4,0,2},
	 {5,1,1,4,6,2,4,0,3,5,1,3},
	 {6,2,2,5,0,3,5,1,4,6,2,4},
	 {0,3,4,0,2,5,0,3,6,1,4,6},
	 {2,5,5,1,3,6,1,4,0,2,5,0},
	 {3,6,6,2,4,0,2,5,1,3,6,1},
	 {4,0,0,3,5,1,3,6,2,4,0,2},
	 {5,1,2,5,0,3,5,1,4,6,2,4},
	 {0,3,3,6,1,4,6,2,5,0,3,5},
	 {1,4,4,0,2,5,0,3,6,1,4,6},
	 {2,5,5,1,3,6,1,4,0,2,5,0},
	 {3,6,0,3,5,1,3,6,2,4,0,2},
	 {5,1,1,4,6,2,4,0,3,5,1,3},
	 {6,2,2,5,0,3,5,1,4,6,2,4},
	 {0,3,3,6,1,4,6,2,5,0,3,5},
	 {1,4,5,1,3,6,1,4,0,2,5,0},
	 {3,6,6,2,4,0,2,5,1,3,6,1},
	 {4,0,0,3,5,1,3,6,2,4,0,2},
	 {5,1,1,4,6,2,4,0,3,5,1,3},
	 {6,2,3,6,1,4,6,2,5,0,3,5},
	 {1,4,4,0,2,5,0,3,6,1,4,6},
	 {2,5,5,1,3,6,1,4,0,2,5,0},
	 {3,6,6,2,4,0,2,5,1,3,6,1},
	 {4,0,1,4,6,2,4,0,3,5,1,3},
	 {6,2,2,5,0,3,5,1,4,6,2,4},
	 {0,3,3,6,1,4,6,2,5,0,3,5},
	 {1,4,4,0,2,5,0,3,6,1,4,6},
	 {2,5,6,2,4,0,2,5,1,3,6,1}};

int main()
{   
    int dia, mes, ano, linhaA,ConteudoB,EnviaC,linhaC, l, c, x;
    
    int A1[28][4], A2[28][4];
    int C[7][6];
    
    
    
    x=-3;
	for(c=0;c<4;c++) {
	   for(l=0;l<28;l++, x++) {
	       if(x<1) A1[l][c]=-1;
			else if(x<100) A1[l][c]=x;
			else if(x==100) A1[l][c]=0;
			else A1[l][c]=-1;
	   }
	}
	
	x=-19;
	for(c=0;c<4;c++)
		for(l=0;l<28;l++, x++)
			if(x<1) A2[l][c]=-1;
			else A2[l][c]=x;
			
	
	x=1;
	for(c=0;c<6;c++)
		for(l=0;l<7;l++, x++)
			if(x>37) C[l][c]=-1;
			else C[l][c]=x;		
			

	setlocale(LC_ALL, "Portuguese");
	printf("\nEntre com uma data no formato DD/MM/AAAA: ");
	scanf("%d/%d/%d", &dia, &mes, &ano);

	if(ano<1901 || ano>2092) printf("Erro!! O ano deve ser de 1901 a 2092.\n");
    else
    {
    	//decida se vai usar A1 ou A2
    	if(ano > 1900 && ano < 2001)
    	{   //extraia os dois últimos dígitos para procurar em A1 ou A2
    	    if(ano < 2000)
    	    {
    	        ano = ano - 1900;
    	    }
    	    else
    	    {
    	        ano = ano - 2000;
    	    }
    	   //A1
    	   //-----> encontrei uma linha para olhar na matriz B
    	   linhaA = procurarLinha(28, 4, A1, ano);
    	}
    	else
    	{   //extraia os dois últimos dígitos para procurar em A1 ou A2
    	    ano = ano - 2000;
    	    //A2
    	    //-----> encontrei uma linha para olhar na matriz B
    	    linhaA = procurarLinha(28, 4, A2, ano);
    	}
    	
    
    	ConteudoB=B[linhaA][mes-1];
    	
    	EnviaC=ConteudoB+dia;
    	
    	linhaC = procurarLinha(7, 6, C, EnviaC);
    	
    	switch(linhaC)
        {
            
            case 0:
            printf ("\n Você nasceu no domingo");
            break;
            
            case 1:
            printf ("\n  Você nasceu na segunda");
            break;
            
            case 2:
            printf ("\n  Você nasceu na terça");
            break;
            
            case 3:
            printf ("\n  Você nasceu na quarta");
            break;
            
            case 4:
            printf ("\n  Você nasceu na quinta");
            break;
            
            case 5:
            printf ("\n  Você nasceu na sexta");
            break;
            
            case 6:
            printf ("\n  Você nasceu no sabado");
            break;
        }
    }

    
	return 0;
}





