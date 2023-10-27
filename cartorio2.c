#include<stdio.h> //biblioteca de comunica��o com o usu�rio
#include<stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include<locale.h> //biblioteca de aloca��o de texto por regi�o
#include<string.h> //biblioteca respon�vel por cuidar das strings



int registro()  //Fun��o respons�vel por cadastrar usu�rios no sistema
{
	//inicio cria��o de vari�veis/strings
	char arquivo[40]; //arquivo = cpf
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/strings
	
	printf("Digite CPF a ser cadastrado: "); //colatando informa��o do usu�rio
	scanf("%s", cpf);	//%s -string
	
	
	strcpy(arquivo, cpf); //respons�vel por copiar valores da string
	
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



int consulta() //Fun��o respons�vel por consultar usu�rio no sistema
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
		printf("N�o foi possivel abrir o arquivo, n�o localizado.\n");
	}	

	while(fgets(conteudo, 200, file)!= NULL)  //fgets - buscar no arquivo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n\n");		
	}
	
	system("pause");
}



int deletar() //Fun��o respons�velpor deletar dados do usu�rio no sistema
{
    char cpf[40];

	printf("Digite CPF a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf); //deletar arquivo
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    	printf("Usu�rio n�o se encontra no sistema.\n");
    	system("pause");
	}
    
}


int main()
{
	int opcao=0; //Definindo variaveis
	int x=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("Cart�rio da EBAC\n\n");
	printf("Login de administrador\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{

    system ("cls");
	for(x=1;x=1;)
	{	
	
	    system("cls"); //respons�vel por limpar a tela
			
		
    	setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
	
	    printf("### CART�RIO EBAC ### \n\n");  //inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
    	printf("\t1. REGISTRAR NOMES\n");
    	printf("\t2. CONSULTAR NOMES\n");
    	printf("\t3. DELETAR NOMES\n\n\n");  
    	printf("OP��O: "); //fim da sele��o
	
    	scanf("%d", &opcao); //armazenando a escolha do usuario
	
	    system("cls");  //troca de tela
	
	
    		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
		    registro();//chamada de fun��es
    		break;
    		
    		case 2:
    		consulta();
    		break;
    		
    		case 3:
    		deletar();
    		break;
    		
    		default:
    		printf("Esta opcao n�o est� disponivel.\n\n");  //fim da sele��o
    		system("pause");
    		break;
    			//fim da sele��o do menu
		}	
		
		}
	
    }
	
	else
	printf("SENHA INCORRETA");
}
