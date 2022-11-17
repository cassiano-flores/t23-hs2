#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//conta quantos sinais existem no arquivo
int contaSinais(char *sinais[]) {

    int count = 0;
    while (sinais[count] != NULL) {
        count++;
    }

    return count;
}

//funcao que escreve no arquivo, na main eh chamado varias vezes
void escreveArquivo(char nome[], char *pontos[]) {

    FILE *fp;

    int size = strlen(nome);
    nome[size-3] = 't';
    nome[size-2] = 'x';
    nome[size-1] = 't';

    fp = fopen(nome, "a");

    fwrite(pontos, sizeof(pontos), 2, fp);

    fclose(fp);
}

int main() {

    FILE *ptr;                                   //ponteiro do arquivo
    char nome_arquivo[50];                       //nome do arquivo a ser lido
    char armazenamento_arquivo[1023][1023];      //vetor com todo conteudo do arquivo
    char *sinais[1000] = { NULL };               //vetor com cada sinal em um indice
    char *pontos[4000] = { NULL };               //vetor com cada ponto em um indice

    printf("Digite o nome do arquivo a ser processado (com a extensao): ");
	scanf("%s", nome_arquivo);
    ptr = fopen(nome_arquivo, "r");
    //ptr = fopen("data.csv", "r");

    if (ptr != NULL) {    //se conseguiu ler...

        int k = 0;
        while(!feof(ptr)) {   //armazena todo arquivo em um vetor ate chegar no final

            fscanf(ptr, "%s", armazenamento_arquivo[k]);
            k++;
        }

        // -- copia sinais --
        char tmp[1000];
        strcpy(tmp, armazenamento_arquivo[0]);  //copia os sinais, que estao na linha '0'

        char *aux = strtok(tmp, ",");

        for (int i = 0; aux != NULL; i++) {

            sinais[i] = aux;           //armazena cada sinal em um indice
            aux = strtok(NULL, ",");   //separa a proxima string (sinal)
        }

        // -- exclui o 1 indice (sinais) do vetor que contem o conteudo do arquivo lido --
        char tmp2[1000];
        for (int i = 0; i < 1000; i++) {

            strcpy(tmp2, armazenamento_arquivo[i+1]);
            for (int j = 0; j < 15; j++) {

                armazenamento_arquivo[i][j] = tmp2[j];
            }
        }

        // -- copia pontos --
        int j = 0;
        for (int i = 0; i < 1010; i++) {

            char *aux2 = strtok(armazenamento_arquivo[i], ",");  //separa os pontos das " , "

            for ( ; aux2 != NULL; j++) {

                pontos[j] = aux2;           //armazena cada ponto em um indice
                aux2 = strtok(NULL, ",");   //separa a proxima string (ponto)
            }
        }

        puts(pontos[0]);
        escreveArquivo(nome_arquivo, pontos[0]);

        //está acontecendo o seguinte comportamento:
        //de 3 sinais, o 1° ponto (indice):
        //128 128 0

        //de 3 sinais, o 2° ponto (indice):
        //128 0

        //de 3 sinais, o 3° ponto (indice):
        // 0

        //...







        fclose(ptr);

    } else {
        printf("Deu errado!");
    }

    return 0;
}