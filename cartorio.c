#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include<stdlib.h> //biblioteca de aloca��es de espa�o em mem�ria
#include<locale.h> // biblioteca de aloca��es de texto por regi�o
#include<string.h>
int registro() //fun��o para registro de nomes
{
   //in�cio cria��o de v�riaveis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   //final cria��o de v�riaveis/string
   
   
   printf("Digite o cpf a ser cadastrado: "); //coletando informa��es do usu�rio
   scanf("%s", cpf); //refere-se a string
   
   
   strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
   
  
   FILE *file; //cria o arquivo
   file = fopen(arquivo, "w"); //cria o arquivo na pasta
   fprintf(file,cpf); //salva o valor da v�ri�vel
   fclose(file); //fecha o arquivo
   
   
   
   file = fopen(arquivo,"a");
   fprintf(file,",");
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,"CPF: ");
   fclose(file);
      
   printf("Digite o nome a ser cadastrado: ");
   scanf("%s", nome);
   
   file = fopen(arquivo, "a");
   fprintf(file,"\n Nome: ");
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,nome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o sobrenome a ser cadastrado: ");
   scanf("%s", sobrenome);
   
   file = fopen(arquivo, "a");
   fprintf(file,"\n Sobrenome: ");
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,sobrenome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o cargo a ser cadastrado: ");
   scanf("%s", cargo);
   
   file = fopen(arquivo, "a");
   fprintf(file,"\n Cargo: ");
   fclose(file);
   
   file = fopen(arquivo,"a");
   fprintf(file,cargo);
   fclose(file);
   
}

int consulta() //fun��o para consultar nomes
{ 
   setlocale(LC_ALL, "Portuguese");
   
   char cpf[40];
   char conteudo[200];
   
   printf("Digite o cpf a ser consultado: ");
   scanf("%s",cpf);
   
   FILE *file;
   file = fopen(cpf, "r");
   
   if(file== NULL)
   {
   	   printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");
   	   
   }
   while(fgets(conteudo, 200, file)!=NULL)
   {
   	   printf("\nEssas s�o informa��es do usu�rio: ");
   	   printf("%s", conteudo);
   	   printf("\n\n");
   }
   
   system("pause");
}
int deletar ()
{
   char cpf[40];
   
   printf("Digite cpf a ser deletado: ");
   scanf("%s",cpf);
   
   remove(cpf);
   
   FILE *file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
   {
   	  printf("O usu�rio n�o se encontra no sistema! \n");
   	  system("pause");
   }
}
int main ()
{
	
	int opcao=0; //Defini��o de vari�veis
	int laco=1;
	  
	for(laco=1;laco=10;)
	  {
	  
	    system("cls");
	
	    setlocale(LC_ALL, "Portuguese");
	
	    printf("###Cart�rio da EBAC###\n\n");
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar os nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Op��o:"); //fim do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usu�rio
	 
	    system("cls");//respons�vel por limpar  a tela
	    
	    
	    
	    switch(opcao) //in�cio da sele��o
	    {
	    	case 1:
	    		registro(); // chamada de func�es
	        break;
	        case 2:
	        	consulta();
	 	    break;
			case 3:
			    deletar ();  
            break;
            
            case 4:
            	printf("Obrigado por utilizar o sistema!\n");
            	return 0;
            	break;
			
			default:
            	printf("Essa op��o n�o est� dispon�vel\n");
	            system("pause");
		}// fim da sole��o
	    
	   
    }
	printf("Esse Software � de livre uso dos alunos\n");

}
