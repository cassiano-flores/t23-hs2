Trabalho 3 e 2  2 

**TRABALHO 3** 

O  objetivo  deste  trabalho  é  aplicar  os  conhecimentos  estudados  durante  as  últimas  aulas, especificamente na manipulação de arquivos. Um programa foi utilizado para gerar formas de onda para uso em uma aplicação embarcada. O programa gerou os três padrões apresentados na figura abaixo: 

![](Aspose.Words.8c6de8f1-28bd-4166-b361-9150de46047b.001.jpeg)

Os dados numéricos dos padrões gerados foram salvos em um arquivo .csv (em anexo) cuja 

formatação é: 

NomeA, NomeB, NomeC dataA, dataB, dataC 

1 1 1 dataA, dataB, dataC 

2 2 2 (...) 

Os pontos que formam os sinais estão nas colunas, formando uma matriz com 1000 linhas e três colunas. O nome de cada sinal é apresentado na primeira linha.   e trata-se de uma sequência numérica simples de valores inteiros. 

Faça um programa que leia os dados do arquivo .csv e gere um arquivo de texto com tabelas para uso em um firmware embarcado. As tabelas devem ser salvas segundo o padrão exemplificado abaixo: 

const unsigned char NomeA[N] = { 

dataA, dataA, dataA, (...) 

1 2 3

(...) 

(...), data A, data A, dataA }; 

N-2 N-1 N

` `Obviamente, o nome dos vetores deve coincidir com os nomes do arquivo csv, e, para o arquivo fornecido, três tabelas, um para cada sinal, devem ser geradas. As tabelas devem ser salvas com no máximo 10 elementos por linha de texto, assim, uma quebra de linha deve ser inserida bem como tabulações e/ou espaços para tornar a tabela mais aprazível devem ser empregados.  

Ressalta-se que o arquivo fornecido tem 1000 pontos por sinal e três sinais, porém o programa desenvolvido deve ser capaz de processar dados com qualquer tamanho e quantidade de sinais (ou seja, o programa deve ser capaz de processar arquivos que tenham 8 sinais com 100 pontos cada, por exemplo, sem a necessidade de o usuário informar isso quando da execução do programa). 

Quaisquer bibliotecas-padrão podem ser utilizadas, e aconselha-se fortemente o emprego da biblioteca string.h. O nome do arquivo csv processado deve ser lido do teclado e o arquivo txt gerado como saída da execução do programa deve ter o mesmo nome desse arquivo. 

![](Aspose.Words.8c6de8f1-28bd-4166-b361-9150de46047b.002.png)
Trabalho 3 e 4  3 

**TRABALHO 4** 

Utilizando o mesmo hardware do trabalho 1 e as tabelas geradas pelo trabalho 2, faça com que os leds do display brilhem conforme as curvas apresentadas nos padrões contidos no arquivo .csv.  

O intervalo de oscilação do brilho pode ser alterado conforme posição do potenciômetro, indo de aproximadamente 1 segundo até 10 segundos. 

O padrão deve ser alterado sequencialmente sempre que o botão for pressionado.  

Aconselha-se  o [ estudo ](https://www.arduino.cc/reference/en/) sobre  interrupções  tanto  de  timer  quanto  externas,  porém  pode-se resolver o problema com uso de delays e operando por[ polling.](https://en.wikipedia.org/wiki/Polling_\(computer_science\)#:%7E:text=Polling%2C%20or%20polled%20operation%2C%20in,software%2Ddriven%20I%2FO.)  

O  trabalho  deverá  ser  apresentado  em  qualquer  encontro  até  a  data  limite  disposta  no cronograma da disciplina. 
![](Aspose.Words.8c6de8f1-28bd-4166-b361-9150de46047b.002.png)
