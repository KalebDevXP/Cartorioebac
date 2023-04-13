#include <stdio.h> //biblioteca de comunica��o de usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registrar() // Fun��o responsavel para cadastrar o usu�rios
{
	// Inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informa��es do usu�rio 
	scanf("%s", cpf);                         //%s salvando uma string
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);          //salva o valor da variavel no arquivo
	fclose(file); //fecha o arquivo
	 
	file = fopen(arquivo, "a"); // atualiza��o
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consultar()
{
	setlocale(LC_ALL,"Portuguese"); // Definindo a Linguagem
	
	// inicio da cria��o de variaveis
	char cpf[40];
	char conteudo[200];
	// Final da cria��o de variaveis 
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O arquivo n�o foi localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");		
	}
	
	system("pause"); //pausa 
	
}

int excluir()
{
	char cpf[40];
	
	printf("Digite o CPF a ser excluido: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen (cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra mais no sistema.\n");
		system("pause");
	}
	
}



int main ()
{
	int opcao=0; // Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL,"Portuguese"); // Definindo a Linguagem
		
	
		printf(">>> Cart�rio da EBAC <<< \n\n"); // �nicio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Excluir Nomes\n"); 
		printf("\t4 - Sair do Sistema\n\n");
		printf("\nOp��es: "); // Fim do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
		system("cls");       // responsavel por limpar a tela
	
	
		switch(opcao)
		{
			case 1:
				registrar(); //chamada de fun��es
				break;
			
			case 2:
				consultar();
				break;
				
			case 3:
				excluir();
				break;
				
			case 4:
				printf("Obrigado por utilizar o sistema. Te vejo na pr�xima vez!\n");
				return 0;
				break;
			
			default:
				printf("Essa op��o n�o existe no sistema!\n");
				system("pause");
				break;
					
		}	//fim da sele��o
		
	}
}
		
