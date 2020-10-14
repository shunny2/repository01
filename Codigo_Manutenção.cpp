#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

struct estoque {
	int codigo, quantidade;
	char *descricao[20];
	float valor_unitario;
};

struct estoque produtoA;

FILE *est; //ponteiro estoque global

//protótipos de função
void sequenciaGravacao();
void inicioArquivo();
void fimArquivo();
void criarArquivo();
void inserirProdutos();
void limpaTela();
void menu();
float calcTotal(int quantidade, float valor_unitario);

void menu() {
	
	int op;

	printf("\n1 - Iniciar processo de criação do arquivo/inserção");
	printf("\n2 - Sair");
	printf("\nInforme uma das opções: ");
	scanf("%d",&op);
	switch (op) {
		case 1:
			criarArquivo();
		break;
		case 2:
			fimArquivo();
		break;
		default:
			printf("\nEssa opção não existe !!");
		break;	
	}

}

void criarArquivo() {
	
	char salvaUnidade[1];
    char arquivo[14];
    char concatena[15];
	char unidade[1];
	
	printf("\nInforme a unidade de gravação do arquivo txt: ");
	scanf("%s",&unidade);
	
    sprintf(salvaUnidade,unidade);
    sprintf(arquivo,"://estoque.txt");
    sprintf(concatena,"%s%s",salvaUnidade, arquivo);
       
	est = fopen(concatena, "a+");	

	if (est == NULL) {
		
		printf("\nErro na criação do arquivo !!!\n");
		printf("A unidade '%s' não existe.\n",salvaUnidade);
		getch();
        limpaTela();
		menu();
		
	}else {
		
		printf("\nSucesso na criação do arquivo !!!\n");
        getch();
        limpaTela();
		inicioArquivo();	        
		
	}
	
}

void inicioArquivo() {
	
	printf("\nCódigo do Produto: ");
	scanf("%d",&produtoA.codigo);
	fprintf(est, "\nCódigo: %d\n", produtoA.codigo);
	
	if (produtoA.codigo != NULL) {

		sequenciaGravacao();
				
	}
	
}

void fimArquivo() {
	
	printf("\nSaindo...\n");
	//system("pause");
	fclose(est);
	
}

void sequenciaGravacao() {
	
	printf("\nDescrição do Produto: ");
	scanf("%s",&produtoA.descricao);
	fprintf(est, "Descrição: %s\n", produtoA.descricao);
	
	printf("\nQuantidade do Produto: ");
	scanf("%d",&produtoA.quantidade);
	fprintf(est, "Quantidade: %d\n", produtoA.quantidade);
	
	printf("\nValor Unitário do Produto: ");
	scanf("%f",&produtoA.valor_unitario);
	fprintf(est, "Valor Unitário: %5.2f\n", produtoA.valor_unitario);
	
	printf("\nValor Total: %5.2f\n",calcTotal(produtoA.quantidade, produtoA.valor_unitario));
	fprintf(est, "Valor Total: %5.2f\n", calcTotal(produtoA.quantidade, produtoA.valor_unitario));
	printf("\nGravando produto...");
	
	if (est == NULL) {
		
		printf("\nErro na gravação do arquivo !!!");
		fimArquivo();
		
	}else {
		
		printf("\nSucesso na gravação do arquivo !!!");
		getch();
		limpaTela();
		
	}
	
	printf("\nExibindo dados...");
	printf ("\nCódigo: %d",produtoA.codigo);
	printf ("\nDescrição: %s",produtoA.descricao);
	printf ("\nQuantidade: %d",produtoA.quantidade);
	printf ("\nValor Unitário: %5.2f",produtoA.valor_unitario);
	printf("\nValor Total: %5.2f",calcTotal(produtoA.quantidade, produtoA.valor_unitario));
	printf ("\nProduto gravado com sucesso!\n");
	
	inserirProdutos();
	
}

void inserirProdutos() {
	
	int opcao;
	
	printf ("\nDeseja continuar inserindo produtos?");
	printf ("\nDigite 1 para SIM ou 2 para NÃO: ");
	scanf ("%d",&opcao);
	switch (opcao) {
		case 1:	
			limpaTela();
			inicioArquivo();
		break;	
		case 2:
			printf("\nFechando o arquivo !!!\n");
			fclose(est);
			getch();
			limpaTela();
			menu();
		break;	
		default: 
			printf("\nOpção Inválida !!!\n");	
		break;		
	}
	
}

float calcTotal(int quantidade,float valor_unitario) {
	
	float total;
	total = quantidade * valor_unitario;
	return total;
	
}

void limpaTela() {
	
	system("cls");
	
}

int main (int argc, char **argv) {
	
	//permite utlizar acentuações portuguesas
	setlocale (LC_ALL, "Portuguese");
	menu();
	
}
