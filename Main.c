#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {

    FILE *ptr;                                   //ponteiro do arquivo
    char nome_arquivo[50];                       //nome do arquivo a ser lido
    char armazenamento_arquivo[1023][1023];      //vetor com todo conteudo do arquivo
    char *sinais[1000];                          //vetor com cada sinal em um indice
    char *pontos[1000];                          //vetor com cada ponto em um indice

    //printf("Digite o nome do arquivo a ser processado (com a extensao): ");
	//scanf("%s", nome_arquivo);
    //ptr = fopen(nome_arquivo, "r");
    ptr = fopen("data.csv", "r");

    if (ptr != NULL) {    //se conseguiu ler...

        int k = 0;
        while(!feof(ptr)) {   //armazena todo arquivo em um vetor ate chegar no final

            fscanf(ptr, "%s", armazenamento_arquivo[k]);
            k++;
        }

        char tmp[1000];
        strcpy(tmp, armazenamento_arquivo[0]);  //copia os sinais, que estao na linha '0'

        char *aux = strtok(tmp, ",");

        for (int i = 0; aux != NULL; i++) {

            sinais[i] = aux;           //armazena cada sinal em um indice
            aux = strtok(NULL, ",");   //separa a proxima string (sinal)
        }

        // === exclui o 1 indice (sinais) do vetor que contem o conteudo do arquivo lido ===
        char tmp2[1000];
        for (int i = 0; i < 1000; i++) {  // !!!!!!!!!!!!!!!!!!!!!!!!!!

            strcpy(tmp2, armazenamento_arquivo[i+1]);
            for (int j = 0; j < 15; j++) {

                armazenamento_arquivo[i][j] = tmp2[j];
            }
        }
        // =================================================================================
        int j = 0;
        for (int i = 0; i < 1010; i++) { // !!!!!!!!!!!!!!!!!!!!!!!!!!

            char tmp3[1000];
            strcpy(tmp3, armazenamento_arquivo[i]);  //copia os pontos, que estao no restante do arquivo

            char *aux2 = strtok(tmp3, ",");

            for ( ; aux2 != NULL; j++) {

                pontos[j] = aux2;           //armazena cada ponto em um indice
                aux2 = strtok(NULL, ",");   //separa a proxima string (ponto)
            }
        }

        //ja que esta fazendo inumeros strcpy dentro do for, ele esta copiando a referencia
        //(para os sinais, nao da erro, ja que os sinais só consomem uma vez)
        //para os pontos, a partir da 2 vez ja da erro, substituindo pelas referencias

        //tenho que fazer um for somente no strcpy, para copiar TODOS indices de armazenamento_arquivo
        //em alguma variavel que fique linear (todas as informações juntas)
        //assim, apos isso, só faço o processo de strtok uma vez, separando cada ponto em um indice (semelhante ao de sinais)
        //se isso funcionar, é possivel que nao seja necessario a 2° etapa (excluir os sinais do armazenamento_arquivo)
        //ja que é só eu começar o for do strcpy a partir do indice "1"








        // === essa parte determina as colunas da matriz ===
        // int i = 0;
        // while (!feof(ptr)) {

        //     fgets(primeira_linha, 1000, ptr);
        //     char *aux = strtok(primeira_linha, ",");

        //     for ( ; aux != NULL; i++) {

        //         sinais[i] = aux;           //armazena o sinal no indice
        //         aux = strtok(NULL, ",");   //separa a proxima string (sinal) da primeira linha
        //     }
        // }
        // =================================================

        // === essa parte determina as linhas da matriz ===
        // while (!feof(ptr)) {

        //     fgets(resto_arquivo, 1000, ptr);
        //     char *aux2 = strtok(resto_arquivo, ",");

        //     for ( ; aux2 != NULL; k++) {

        //         pontos[k] = aux2;           //armazena os pontos da linha no indice
        //         aux2 = strtok(NULL, ",");
        //     }
        // }
        // =================================================













        fclose(ptr);

    } else {
        printf("Deu errado!");
    }

    return 0;
}
