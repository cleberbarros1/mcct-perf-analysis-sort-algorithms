#include <stdio.h>
#include <vector>
#include <direct.h>
#include <iostream>
#include <fstream>
#include "bateria-testes.h"
#include "gnuplot-function.h"

using namespace std;

int main() {
   printf("\n ------------------- MESTRADO EM MODELAGEM COMPUTACIONAL - 2024.1 --------------------\n");
   printf("\n --> Mestrandos: CLEBER BARROS / ITALO GALLON --- \n");
   printf("\n --> Software para avaliacao de performance de algoritmos de ordenacao --- \n");
   printf("\n --> Professor: Tiago Araujo Neves \n");
   printf("\n --> DESAFIO: Avaliar complexidade e desempenho de Algoritmos de Ordenacao\n\n");
   printf("\n ------------------- INICIANDO AVALIACAO DE TEMPOS --------------------\n\n");

   mkdir("relatorios-de-testes");

   vector<string> files = {
   "relatorios-de-testes/relatorio-bubble.txt",
   "relatorios-de-testes/relatorio-insertion.txt",
   "relatorios-de-testes/relatorio-selection.txt",
   "relatorios-de-testes/relatorio-merge.txt",
   "relatorios-de-testes/relatorio-quick.txt"
   };

   FILE* pipe = popen("gnuplot -persist", "w");
   if (!pipe) {
      printf("Error ao carregar o gráfico!\n");
   }

   relatoriosIniciais(files);
   plotarGrafico(pipe);

   ///AQUI É A INVOCACAO DOs METODOs PRINCIPAIS. ALTERE NA ORDEM ABAIXO
   /// -> valor inicial (1000)
   /// -> Valor Final (2000)
   /// -> Passo (100) 
   /// -> Repeticoes (30)
   /// -> Qual Metodo deseja executar - "bubble" / "Insertion"

   int inicio = 5000;
   int final = 20000;
   int passo = 1000;
   int qtdTestes = 30;

   printf("\n ------------------- BUBBLE SORT --------------------\n\n[");
   vector<double> bubble = bateriaTestes(inicio, final, passo, qtdTestes, "bubble", pipe);

   printf("\n ------------------- INERTION SORT --------------------\n\n[");
   vector<double> insertion = bateriaTestes(inicio, final, passo, qtdTestes, "insertion", pipe);
   
   printf("\n ------------------- SELECTION SORT --------------------\n\n[");
   vector<double> selection = bateriaTestes(inicio, final, passo, qtdTestes, "selection", pipe);

   printf("\n ------------------- MERGE SORT --------------------\n\n[");
   vector<double> merge = bateriaTestes(inicio, final, passo, qtdTestes, "merge", pipe);

   printf("\n ------------------- QUICK SORT --------------------\n\n[");
   vector<double> quick = bateriaTestes(inicio, final, passo, qtdTestes, "quick", pipe);


   printf("\n ------------------- RESULTADO DE MEDIAS - BUBBLE --------------------\n\n[");
   for(int i = 0 ; i < bubble.size(); i++) {
    printf("%f s ", bubble[i]);
   }
   printf("]\n\n");

   printf("\n ------------------- RESULTADO DE MEDIAS - INSERTION --------------------\n\n[");
   for(int i = 0 ; i < insertion.size(); i++) {
    printf("%f s ", insertion[i]);
   }
   printf("]\n\n");

   printf("\n ------------------- RESULTADO DE MEDIAS - SELECTION --------------------\n\n[");
   for(int i = 0 ; i < selection.size(); i++) {
    printf("%f s ", selection[i]);
   }
   printf("]\n\n");

   printf("\n ------------------- RESULTADO DE MEDIAS - MERGE --------------------\n\n[");
   for(int i = 0 ; i < merge.size(); i++) {
    printf("%f s ", merge[i]);
   }
   printf("]\n\n");

   printf("\n ------------------- RESULTADO DE MEDIAS - QUICK --------------------\n\n[");
   for(int i = 0 ; i < quick.size(); i++) {
    printf("%f s ", quick[i]);
   }
   printf("]\n\n");


   printf("PRESSIONE QUALQUER TECLA E ENTER PARA ENCERRAR\n");
   char a[1];
   scanf("%s", a);
      

}