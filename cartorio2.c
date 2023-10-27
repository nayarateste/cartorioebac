#include<stdio.h> //biblioteca de comunicação com o usuário
#include<stdlib.h> //biblioteca de alocação de espaço de memória
#include<locale.h> //biblioteca de alocação de texto por região
#include<string.h> //biblioteca responável por cuidar das strings



int registro()  //Função responsável por cadastrar usuários no sistema
{
	//inicio criação de variáveis/strings
	char arquivo[40]; //arquivo = cpf
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/strings
	
	printf("Digite CPF a ser cadastrado: "); //colatando informação do usuário
	scanf("%s", cpf);	//%s -string
	
	
	strcpy(arquivo, cpf); //responsável por copiar valores da string
	
	FILE *file; //procurar FILE para criar arquivo
	file = fopen(arquivo, "w"); //abrir/criar arquivo \ nome do arquivo tipo w (write)
	fprintf(file,cpf); //salvo valor da variavel
	fclose(file); //fechar arquivo
	
	file=fopen(arquivo, "a"); //a (atualizar)
	fprintf(file, ",");
	fclose(file);
	
	
	printf("Digite NOME a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);	


	printf("Digite SOBRENOME a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	

	printf("Digite o CARGO a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}



int consulta() //Função responsável por consultar usuário no sistema
{
	setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");  //r(read)
	
	if(file == NULL)  //NULL - nulo
	{
		printf("Não foi possivel abrir o arquivo, não localizado.\n");
	}	

	while(fgets(conteudo, 200, file)!= NULL)  //fgets - buscar no arquivo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n\n");		
	}
	
	system("pause");
}



int deletar() //Função responsávelpor deletar dados do usuário no sistema
{
    char cpf[40];

	printf("Digite CPF a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf); //deletar arquivo
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    	printf("Usuário não se encontra no sistema.\n");
    	system("pause");
	}
    
}


int main()
{
	int opcao=0; //Definindo variaveis
	int x=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("Cartório da EBAC\n\n");
	printf("Login de administrador\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{

    system ("cls");
	for(x=1;x=1;)
	{	
	
	    system("cls"); //responsável por limpar a tela
			
		
    	setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
	
	    printf("### CARTÓRIO EBAC ### \n\n");  //inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
    	printf("\t1. REGISTRAR NOMES\n");
    	printf("\t2. CONSULTAR NOMES\n");
    	printf("\t3. DELETAR NOMES\n\n\n");  
    	printf("OPÇÃO: "); //fim da seleção
	
    	scanf("%d", &opcao); //armazenando a escolha do usuario
	
	    system("cls");  //troca de tela
	
	
    		switch(opcao) //inicio da seleção do menu
		{
			case 1:
		    registro();//chamada de funções
    		break;
    		
    		case 2:
    		consulta();
    		break;
    		
    		case 3:
    		deletar();
    		break;
    		
    		default:
    		printf("Esta opcao não está disponivel.\n\n");  //fim da seleção
    		system("pause");
    		break;
    			//fim da seleção do menu
		}	
		
		}
	
    }
	
	else
	printf("SENHA INCORRETA");
}
