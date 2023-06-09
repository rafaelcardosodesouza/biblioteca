#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define qtd 20
//rafarafoso
#include <locale.h>

struct book {
    int cod;
    char nome[150];
    char editora[20];
    char nomeAutor[20];
};

void limparTela() {
    system("cls");
}

int cadastroLivro(struct book cadastrados[], int qtdLivro) {
    int j = 1;//rafarafoso

    printf("Bem-vindo à seção de cadastro\n");
    printf("Quantos livros deseja cadastrar? ");
    scanf("%d", &qtdLivro);
    getchar(); // Limpar o caractere de nova linha do buffer

    printf("======================\n");
    printf("Okay, vamos cadastrar %i livros.\n", qtdLivro);
    printf("======================\n");

    for (int i = 0; i < qtdLivro; i++) {
        printf("Nome do livro: ");
        fgets(cadastrados[i].nome, sizeof(cadastrados[i].nome), stdin);
        cadastrados[i].nome[strcspn(cadastrados[i].nome, "\n")] = '\0';

        printf("Editora: ");
        fgets(cadastrados[i].editora, sizeof(cadastrados[i].editora), stdin);
        cadastrados[i].editora[strcspn(cadastrados[i].editora, "\n")] = '\0';

        printf("Autor: ");
        fgets(cadastrados[i].nomeAutor, sizeof(cadastrados[i].nomeAutor), stdin);
        cadastrados[i].nomeAutor[strcspn(cadastrados[i].nomeAutor, "\n")] = '\0';

        printf("Codigo do Livro: ");
        scanf("%d", &cadastrados[i].cod);

        getchar(); // Limpar o caractere de nova linha do buffer

        printf("****************\n");
        printf("O Livro: %s foi cadastrado\n", cadastrados[i].nome);
        printf("****************\n");

        if (j < qtdLivro) {
            printf("Cadastrar o próximo livro\n");
        }
        j++;
    }
    //rafarafoso
    printf("----------------------------------\n");
    printf("Todos os livros foram registrados\n");
    printf("----------------------------------\n");
    return qtdLivro;
}

void infoLivro(struct book cadastrados[], int qtdLivro) {
    printf("Lista de livros cadastrados: \n");
    for (int i = 0; i < qtdLivro; i++) {
        printf("Nome: %s\n", cadastrados[i].nome);
        printf("Autor: %s\n", cadastrados[i].nomeAutor);
        printf("Editora: %s\n", cadastrados[i].editora);
        printf("Codigo: %i\n", cadastrados[i].cod);
        printf("______________\n");
    }
}

void ordenado(struct book cadastrados[], int qtdLivro) {
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
        printf("Autor: %i\n", cadastrados[i].cod);
    }

    printf("-------------------------\n");
}//rafarafoso

void buscarLivro(struct book cadastrados[], int qtdLivro) {
    int busca, encontrado = 0;
   
    printf("Digite o código do livro que deseja buscar: ");
    scanf("%d", &busca);
    for (int i = 0; i < qtdLivro; i++) {
        if (cadastrados[i].cod == busca) {
            printf("Livro encontrado:\n");
            printf("Nome: %s\n", cadastrados[i].nome);
            printf("Autor: %s\n", cadastrados[i].nomeAutor);
            printf("Editora: %s\n", cadastrados[i].editora);
            printf("Codigo: %i\n", cadastrados[i].cod);
            printf("----------------------------------\n");
            encontrado = 1;
            break;
        } 
    }
    if (!encontrado) {
        printf("Livro com código %d não encontrado.\n", busca);
        printf("----------------------------------\n");
    }
}

void salvarLivros(struct book cadastrados[], int qtdLivro) {
    FILE *arquivo; //rever o conseito do * <-
    arquivo = fopen("livros.txt", "w"); // Abre o arquivo para escrita
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }//rafarafoso
    for (int i = 0; i < qtdLivro; i++) {
        fprintf(arquivo, "%d\n", cadastrados[i].cod);
        fprintf(arquivo, "%s\n", cadastrados[i].nome);
        fprintf(arquivo, "%s\n", cadastrados[i].editora);
        fprintf(arquivo, "%s\n", cadastrados[i].nomeAutor);
    }
    fclose(arquivo); // Fecha o arquivo
}

int carregarLivros(struct book cadastrados[]) {
    FILE *arquivo; //rever o conseito do * <-
    arquivo = fopen("livros.txt", "r"); // Abre o arquivo para leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }
    int qtdLivro = 0;
    while (!feof(arquivo)) {
        fscanf(arquivo, "%d", &cadastrados[qtdLivro].cod);
        fscanf(arquivo, "%s", cadastrados[qtdLivro].nome);
        fscanf(arquivo, "%s", cadastrados[qtdLivro].editora);
        fscanf(arquivo, "%s", cadastrados[qtdLivro].nomeAutor);
        qtdLivro++;
    }
    fclose(arquivo); // Fecha o arquivo
    return qtdLivro;
}
//rafarafoso
int main() {
    setlocale(LC_ALL, "");
    int op;
    struct book cadastrados[qtd];
    int qtdLivro = carregarLivros(cadastrados); // Carrega os dados dos livros do arquivo

    do {
        printf("\nOla, o que gostaria?\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Imprimir as informações dos livros cadastrados\n");
        printf("3 - Pesquisar por código\n");
        printf("4 - Ordenar livros por código\n");
        printf("5 - Limpar a tela\n");
        printf("0 - Sair\n");
        scanf("%d", &op);

        switch (op) {
            case 0: {
                printf("Finalizando o programa, tenha um bom dia!\n");
                salvarLivros(cadastrados, qtdLivro); // Salva os dados dos livros no arquivo
                break;
            }
            case 1: {
                qtdLivro = cadastroLivro(cadastrados, qtdLivro);
                break;
            }
            case 2: {
                infoLivro(cadastrados, qtdLivro);
                break;
            }
            case 3: {
                buscarLivro(cadastrados, qtdLivro);
                break;
            }
            case 4: {
                ordenado(cadastrados, qtdLivro);
                break;
            }
            case 5: {
                limparTela();
                break;
            }
            default: {
                printf("Opção inválida. Por favor, tente novamente.\n");
                break;
            }
        }
        //rafarafoso
    } while (op != 0);

    return 0;
}
