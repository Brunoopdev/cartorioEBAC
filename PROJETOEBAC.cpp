#include<stdio.h> // Biblioteca de comunica��o com o usu�rio 
#include<stdlib.h> //Biblioteca responsav�l por alocar v�riaveis
#include<locale.h> //Biblioteca de aloca��o de texto por regi�o 
#include<string.h> // Biblioteca responsavel por alocar strings


int registrar() // cria a fun��o para registrar as informa��es
{
	char arquivo[40]; //variavel char
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //texto 
	scanf("%s", cpf); //armazenar o valor digitado na string cpf
	
	strcpy(arquivo,cpf); //iguala o arquivo ao cpf, mesmo valor
	
	FILE *file; //cria o arquivo file 
	file = fopen(arquivo, "w"); // abre o arquivo e escreve nela
	fprintf(file,"\n\tCPF:");
	fprintf(file,cpf); // salva no arquivo file a variavel cpf
	fclose(file);	//fecha o arquivo file 
	
	file = fopen(arquivo,"a"); //abre o arquivo e adiciona informa��es
	fprintf(file,"\n\tNOME:");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);//salva o valor digitado na spring por causa do "%s"

	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n\tSOBRENOME: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\n\tCARGO: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf(file, "\n\n");
	fclose(file);
	
	system("pause"); //pausa o sistema aqui 
}

int consultar() //cria a fun��o para consultar o cpf
{
	char cpf[40]; //tem que ser escrita novamente pois � uma fun��o separada 
	char conteudo[200]; // cria a variavel conteudo com uma quantidade de caracteres que vai ser usada no while
	
	printf("Digite o CPF a ser consultado: "); //pede para digitar o cpf
	scanf("%s", cpf); //salva o valor digitado na string cpf, busca o valor 
	
	FILE *file; //cria o file nessa fun��o tamb�m
	file = fopen(cpf,"r"); //abre o file e pede pra ler oq est� dentro de acordo com a busca
	
	if (file == NULL) //cria uma variavel caso o valor da busca seja nulo 
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n"); //texto 
	}
	
	printf("Essas s�o as informa��es do usu�rio:\n ");
	
	while(fgets(conteudo,200,file)!=NULL) // cria uma variavel para funcionar enquanto o valor buscado for verdadeiro 
	{
		printf("%s", conteudo);
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40]; //tem que ser escrita novamente pois � uma fun��o diferente 
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //fun��o que ser� usada para deletar as informa��es da variavel cpf
	
	FILE *file;
	file = fopen(cpf,"r"); //abre o arquivo file e l� o cpf por conta do "r"
	fclose(file);
	
	if(file == NULL) //variavel para saber se encontrou no sistema
	{
		printf("\nEste usu�rio n�o se encontra no sistema!\n\n");
	}
	
	if(file != NULL) //variavel para saber se excluiu com sucesso (n�o est� funcionando direito n�o sei o pq)
	{
		printf("O usu�rio foi excluido com sucesso!\n");
	}
	
	system("pause");
	
			
	}
	
int main() //fun��o principal
{
	int opcao = 0; //cria��o de uma variavel
	
	int x=1; //variavel criada para ser usada na repeti��o 
	
	for(x=1;x=1;){
		
		system("cls");

	setlocale(LC_ALL ,"portuguese");
	
	char senhalogin[10]="a";
	char nomelogin[10]="a";
	int comparacao;
	
	printf("_Cart�rio da EBAC_\n\n");
	printf("Login de administrador!\n\n");
	printf("Digite seu login: ");
		scanf("%s",nomelogin);
	printf("Digite sua senha: ");
		scanf("%s",senhalogin);
		
		comparacao = strcmp(nomelogin,"admin");
		comparacao = strcmp(senhalogin,"123admin");
	
		if(comparacao == 0)
		{
			system("cls");

	
	for(x=1;x=1;) // variavel de repeti��o
	{
		
		system("cls"); //apagar os c�digos para deixar o menu limpo 
	
	setlocale(LC_ALL, "portuguese");// selecionado o idioma portugues
	
	printf("\t\t_Cart�rio da EBAC_\n\n");//adicionado texto
	printf("\tEscolha a op��o desejada do menu:\n");
	printf("\t1-Registrar nomes:\n");
	printf("\t2-Consultar nomes:\n");
	printf("\t3-Deletar nomes:\n\n");
	printf("\t4-Sair do Site\n\n");
	printf("Op��o:");
	
	scanf("%d", &opcao);//armazenando oq o usu�rio digitar na variavel com o &

	system("cls");//limpar a tela ap�s o scanf
	
	switch (opcao) // variavel de valida��o 
	{
		case 1:
			registrar(); //chama a variavel registrar 
			break; //quebra a variavel, como o }
			
		case 2:
			consultar();
			break;
			
		case 3:
			deletar();
			break;
			
		case 4:
		
			printf("Obrigado por ulitizar nosso site!");
				return 0;
				break;
			
		default: // tudo que n�o existe no c�digo voltar� para c�
			printf("Esta op��o n�o existe\n");
			system("pause");
			break;		
		
		
			}
		}		
	}

	
	else 
     	printf("\nInforma��es incorretas!\n\n");
     	system("pause");
}
}

