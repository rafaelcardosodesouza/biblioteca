#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define qtd 20

struct book {
    int cod;
    char nome[150];
    char editora[20];
    char nomeAutor[20];
};

void limparTela() {
    for (int i = 0; i < 50; i++) {
        printf(" .\n");
    }
}

int cadastroLivro() {
    int qtdLivro, j = 1;

    struct book cadastro[qtd];

    printf("Bem-vindo à seção de cadastro\n");
    printf("Quantos livros deseja cadastrar? ");
    scanf("%d", &qtdLivro);
    getchar(); // Limpar o caractere de nova linha do buffer

    printf("======================\n");
    printf("Okay, vamos cadastrar %i livros.\n", qtdLivro);
    printf("======================\n");

    for (int i = 0; i < qtdLivro; i++) {
        printf("Nome do livro: ");
        fgets(cadastro[i].nome, sizeof(cadastro[i].nome), stdin);
        cadastro[i].nome[strcspn(cadastro[i].nome, "\n")] = '\0';

        printf("Editora: ");
        fgets(cadastro[i].editora, sizeof(cadastro[i].editora), stdin);
        cadastro[i].editora[strcspn(cadastro[i].editora, "\n")] = '\0';

        printf("Autor: ");
        fgets(cadastro[i].nomeAutor, sizeof(cadastro[i].nomeAutor), stdin);
        cadastro[i].nomeAutor[strcspn(cadastro[i].nomeAutor, "\n")] = '\0';

        printf("Codigo do Livro: ");
        scanf("%d", &cadastro[i].cod);

        getchar(); // Limpar o caractere de nova linha do buffer

        printf("********************************************\n");
        printf("O Livro: %s foi cadastrado\n", cadastro[i].nome);
        printf("********************************************\n");

        if (j < qtdLivro) {
            printf("Cadastrar o próximo livro\n");
        }
        j++;
    }
    limparTela();
    printf("----------------------------------\n");
    printf("Todos os livros foram registrados\n");
    printf("----------------------------------\n");
    return qtdLivro;
}

void infoLivro(int qtdLivro) {
    int i;
    struct book cadastrados[qtd];

    printf("Lista de livros cadastrados: \n");
    for (i = 0; i < qtdLivro; i++) {
        printf("Nome: %s\n", cadastrados[i].nome);
        printf("Autor: %s\n", cadastrados[i].nomeAutor);
        printf("Editora: %s\n", cadastrados[i].editora);
        printf("Codigo: %i\n", cadastrados[i].cod);
        printf("______________________________________\n");
    }
}
void ordenado(int qtdLivro) {
    struct book cadastrados[qtd];
    int temp;

    printf("Os livros em ordem por código ficam: \n");
    for (int i = 0; i < qtdLivro; i++) {
        for (int j = i + 1; j < qtdLivro; j++) {
            if (cadastrados[i].cod > cadastrados[j].cod) {
                temp = cadastrados[i].cod;
                cadastrados[i].cod = cadastrados[j].cod;
                cadastrados[j].cod = temp;
            }
        }
    }
    
    for (int i = 0; i < qtdLivro; i++) {
        printf("Nome: %s\n", cadastrados[i].nome);
        printf("Autor: %s\n", cadastrados[i].nomeAutor);
        printf("codigo: %i\n", cadastrados[i].cod);
    }

    printf("-------------------------\n");
}
void bucascarBook(int qtdLivro){
    int busca, encontrado=0;
   
    struct book cadastrados[qtd];
    printf("Digite o codigo do livro que deseja buscar: ");
    scanf("%d", &busca);
    for(int i = 0; i<qtdLivro; i++){
        if(cadastrados[i].cod == busca){
            printf("Livro encontrado:\n");
            printf("Nome: %s\n", cadastrados[i].nome);
            printf("Autor: %s\n", cadastrados[i].nomeAutor);
            printf("Editora: %s\n", cadastrados[i].editora);
            printf("Codigo: %i\n", cadastrados[i].cod);
            printf("----------------------------------\n");
            encontrado=1;
        } 
    }
    if(!encontrado){
         printf("Livro com código %d não encontrado.\n", busca);
        printf("----------------------------------\n");
    }
}

int main() {
    int op;
    int qtdLivro = 0; // Variável para armazenar a quantidade de livros cadastrados
    fflush(stdin);
    do {
        printf("\nOla, o que gostaria?\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Imprimir as informações dos livros cadastrados\n");
        printf("3 - Pesquisar por código\n");
        printf("4 - Ordenar livros por codigo\n");
        printf("0 - Sair\n");
        scanf("%d", &op);

        switch (op) {
            case 0: {
                printf("Finalizando o programa, tenha um bom dia!\n");
                break;
            }
            case 1: 2
            }
            case 3: {
                bucascarBook(qtdLivro);
                break;
            }
            case 4: {
                ordenado(qtdLivro);
                break;
            }
            default: {
                printf("Opção inválida. Por favor, tente novamente.\n");
                break;
            }
        }
    } while (op != 0);

    return 0;
}
