#include <stdio.h> //biblioteca de comunicação de usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registrar() // Função responsavel para cadastrar o usuários
{
	// Inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informações do usuário 
	scanf("%s", cpf);                         //%s salvando uma string
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);          //salva o valor da variavel no arquivo
	fclose(file); //fecha o arquivo
	 
	file = fopen(arquivo, "a"); // atualização
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
	
	// inicio da criação de variaveis
	char cpf[40];
	char conteudo[200];
	// Final da criação de variaveis 
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O arquivo não foi localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
		printf("O usuário não se encontra mais no sistema.\n");
		system("pause");
	}
	
}



int main ()
{
	int opcao=0; // Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL,"Portuguese"); // Definindo a Linguagem
		
	
		printf(">>> Cartório da EBAC <<< \n\n"); // Ínicio do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Excluir Nomes\n"); 
		printf("\t4 - Sair do Sistema\n\n");
		printf("\nOpções: "); // Fim do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usuário
	
		system("cls");       // responsavel por limpar a tela
	
	
		switch(opcao)
		{
			case 1:
				registrar(); //chamada de funções
				break;
			
			case 2:
				consultar();
				break;
				
			case 3:
				excluir();
				break;
				
			case 4:
				printf("Obrigado por utilizar o sistema. Te vejo na próxima vez!\n");
				return 0;
				break;
			
			default:
				printf("Essa opção não existe no sistema!\n");
				system("pause");
				break;
					
		}	//fim da seleção
		
	}
}
		
