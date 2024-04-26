#include <stdio.h>

using namespace std;

void plotarGrafico(FILE* pipe) {
 // Abrindo o pipe para o gnuplot
 // É NECESSARIO TER O GNUPLOT INSTALADO E ADICIONADO COMO VARIÁVEIS DE AMBIENTE

  /// Plotar usando o gnuplot através do pipe aberto
  fprintf(pipe, "plot 'relatorios-de-testes/relatorio-bubble.txt' title 'BUBBLE' with linespoints lw 3, 'relatorios-de-testes/relatorio-insertion.txt' title 'INSERTION' with linespoints lw 3, 'relatorios-de-testes/relatorio-selection.txt' title 'SELECTION' with linespoints lw 3, 'relatorios-de-testes/relatorio-merge.txt' title 'MERGE' with linespoints lw 3, 'relatorios-de-testes/relatorio-quick.txt' title 'QUICK' with linespoints lw 3 linecolor 8; \n"); // Plot data

  fprintf(pipe, "i = 1 \n");

  fprintf(pipe, "set ylabel ' Average for 30x in seconds' \n"); 

  fprintf(pipe, "set xlabel 'Amount of Entries V[x]' \n");

  fprintf(pipe, "set size 0.9, 0.9 \n");

  fprintf(pipe, "set key left top \n");

  fprintf(pipe, "set border 3 \n");

  fprintf(pipe, "set title 'Perfomance Analysis for Sorting Algorithms' \n");

  fflush(pipe);

}