#include <stdio.h> // biblioteca de comunicação com o usuário
#include<stdlib.h> //biblioteca de alocações de espaço em memória
#include<locale.h> // biblioteca de alocações de texto por região

int registro() //função para registro de nomes
{
   //início criação de váriaveis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   //final criação de váriaveis/string
   
   
   printf("Digite o cpf a ser cadastrado: "); //coletando informações do usuário
   scanf("%s", cpf); //refere-se a string
   
   
   strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
   
  
   FILE *file; //cria o arquivo
   file = fopen(arquivo, "w"); //cria o arquivo na pasta
   fprintf(file,cpf); //salva o valor da váriável
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

int consulta() //função para consultar nomes
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
   	   printf("Não foi possível abrir o arquivo, não localizado! \n");
   	   
   }
   while(fgets(conteudo, 200, file)!=NULL)
   {
   	   printf("\nEssas são informações do usuário: ");
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
   	  printf("O usuário não se encontra no sistema! \n");
   	  system("pause");
   }
}
int main ()
{
	
	int opcao=0; //Definição de variáveis
	int laco=1;
	  
	for(laco=1;laco=10;)
	  {
	  
	    system("cls");
	
	    setlocale(LC_ALL, "Portuguese");
	
	    printf("###Cartório da EBAC###\n\n");
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar os nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Opção:"); //fim do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuário
	 
	    system("cls");//responsável por limpar  a tela
	    
	    
	    
	    switch(opcao) //início da seleção
	    {
	    	case 1:
	    		registro(); // chamada de funcões
	        break;
	        case 2:
	        	consulta();
	 	    break;
			case 3:
			    deletar ();  
            break;
            
			
			default:
            	printf("Essa opção não está disponível\n");
	            system("pause");
		}// fim da soleção
	    
	   
    }
	printf("Esse Software é de livre uso dos alunos\n");

}
