#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//conta quantos elementos um vetor possui (util para os sinais)
int contaElementos(char *sinais[]) {

    int count = 0;
    while (sinais[count] != NULL) {
        count++;
    }

    return count;
}

int main() {

    FILE *ptr;                                   //ponteiro do arquivo
    FILE *fp;
    char nome_arquivo[50];                       //nome do arquivo a ser lido
    char armazenamento_arquivo[1023][1023];      //vetor com todo conteudo do arquivo
    char *sinais[1000] = { NULL };               //vetor com cada sinal em um indice
    char *pontos[4000] = { NULL };               //vetor com cada ponto em um indice

    printf("Digite o nome do arquivo a ser processado (com a extensao): ");
	scanf("%s", nome_arquivo);
    ptr = fopen(nome_arquivo, "r");

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
            for (int j = 0; j < 30; j++) {

                armazenamento_arquivo[i][j] = tmp2[j];
            }
        }

        // -- copia pontos --
        int v = 0;
        for (int i = 0; i < 1010; i++) {

            char *aux2 = strtok(armazenamento_arquivo[i], ",");  //separa os pontos das " , "

            for ( ; aux2 != NULL; v++) {

                pontos[v] = aux2;           //armazena cada ponto em um indice
                aux2 = strtok(NULL, ",");   //separa a proxima string (ponto)
            }
        }

        //remove os elementos duplicados da ultima posicao
        for (int i = 0; i < contaElementos(sinais); i++) {

            pontos[(contaElementos(pontos)) - 1] = NULL;
        }

        // -- parte final, gera o arquivo --
        //transforma em txt
        int size = strlen(nome_arquivo);
        nome_arquivo[size-3] = 't';
        nome_arquivo[size-2] = 'x';
        nome_arquivo[size-1] = 't';

        fp = fopen(nome_arquivo, "a");

        //escreve o titulo (const unsigned...)
        char titulo[50] = { NULL };
        int qtd_pontos = (contaElementos(pontos)/contaElementos(sinais));

        for (int i = 0; i < contaElementos(sinais); i++) {

        sprintf(titulo, "const unsigned char %s[%d] = {", sinais[i], qtd_pontos);
        fwrite(titulo, 50, 1, fp);
        int count = 0;

            //escreve cada ponto, a cada 10 pontos quebra a linha
            for (int j = i; j < contaElementos(pontos); j += contaElementos(sinais)) {

                if (((count % 10) == 0)) {
                    fwrite("\n", 1, 1, fp);
                }
                fwrite(pontos[j], 3, 1, fp);

                if (j + contaElementos(sinais) < contaElementos(pontos)) {
                    fwrite(", ", 2, 1, fp);
                }

                count++;
            }
            fwrite(" };\n\n", 5, 1, fp);
        }

        fclose(fp);
        fclose(ptr);

    } else {   //caso digite errado
        printf("Deu errado!");
    }

    return 0;
}

//tratar "deu errado!"
//bugzinho de dois numeros no txt