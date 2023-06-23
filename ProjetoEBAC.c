#include <stdio.h> // biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca resopnsavel por cuidas das strings
 
int registro()
{
	
	printf("Voc� escolheu consultar nomes!\n\n");	

	char arquivo[40]; //v�riavel do arquivo 
	char cpf[40]; //v�riavel do cpf 
	char nome[40]; //v�riavel do nome
	char sobrenome[40]; //v�riavel do sobrenome
	char cargo[40]; //v�riavel do cargo
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf); // responsavel por salvar as informa��es do "cpf" nas strings
		
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo 
	fprintf(file, "\nCPF: ");
	fprintf(file,cpf); //salvo o valor da variavel 
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo,"a");
	fprintf(file, "\nNOME: "); //adiciona uma virgula ao fim
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);	
	
	file = fopen(arquivo, "a"); //abre o arquivo criado e o "a" o edita 
	fprintf(file,nome); //salva o valor da variavel no arquivo j� criado
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSOBRENOME: ");
	fclose(file);
		
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);

	file = fopen(arquivo, "a");
	fprintf(file,sobrenome); // salva o valor da variavel no aquivo j� criado
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nCARGO: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo); //salva o valor da variavel no arquivo j� criado
	fprintf(file,"\n\n");
	fclose(file);
	
	system("pause");
	
	}

int consultar()
{
	setlocale(LC_ALL, "portuguese");// para identificar que � no Brasil
	
	printf("Voc� escolheu consultar nomes!\n\n");
	
	char cpf[40]; //variavel do cpf 
	char conteudo[200];//variavel do conteudo 
	
	printf("Digite o CPF a ser consultado: ");//texto ao selecionar o 2 no menu
	scanf("%s",cpf)	; //salvar as informa��es
	
	FILE *file;
	file = fopen(cpf,"r"); //vai abrir o arquivo file e ler oq est� dentro 
	
	if(file == NULL) //se o arquivo n�o possuir as informa��es buscadas
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	printf("\nEssas s�o as informa��es do usu�rio:\n");
	
	while(fgets(conteudo,200, file)!=NULL)//abrir o arquivo e procurar dentro do seu conteudo
	{
		
		printf("%s", conteudo);
		
	}
	
	 	system("pause");
	 	
		}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado:  ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");

	
	if(file == NULL)
	{
		printf("O usu�rio n�o foi encontrado!\n");
	}
	

	if(file != NULL)
	{
		printf("O usu�rio foi excluido com sucesso!\n");
	}
	
	system("pause");
}


int main() //cria��o do menu
{ 
	int opcao=0;
	
	int x=0;
	
	for(x=1;x=1;)
	{
		
	system("cls");
		
	setlocale(LC_ALL, "portuguese");
	
	printf("\t\Cart�rio da EBAC\t\n\n");   
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1-Incluir nomes\n");
	printf("\t2-consultar nomes\n");
	printf("\t3-deletar usu�rios\n");
	printf("\t4-Sair da aplica��o\n\n");
	printf("Uso exclusivo dos alunos EBAC\n\n");
	printf("Op��o:");
	
	scanf("%d", &opcao);
	
	system("cls");
	
	switch (opcao) // variaveis de escolha
	{
		case 1:
			registro();
			break;
		
		case 2:
			consultar();
			break;
			
		case 3:
			deletar();
			break;
			
		case 4:
			printf("Obrigado por utilizar o aplicativo!");
			return 0;
			break;
		
		default:
		    printf("Esta op��o � inexistente!\n\n");
		    system("pause");
			break;	
				
	}
	
}
}
