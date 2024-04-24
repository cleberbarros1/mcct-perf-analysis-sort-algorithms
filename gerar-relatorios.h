#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

///Funcao para criar os relatórios em txt de uma bateria de testes, incluindo médias de tempo, conforme o metodo de ordenacao

void iterarRelatorios (double media, int i, string nomeRel) {

        string tituloRelatorio = "relatorios-de-testes/relatorio-" + nomeRel + ".txt";
        fstream relatorio;

        relatorio.open(tituloRelatorio, std::ios::out | std::ios::app);

        relatorio << i;
        relatorio << " ";
        relatorio << media << std::endl;

        relatorio.close();

    }

void relatoriosIniciais(vector<string> files) {

    fstream relatorio;

      ofstream file(files[0]);
      relatorio.open(files[0], std::ios::out | std::ios::app);
      relatorio << 0;
      relatorio << " ";
      relatorio << 0 << std::endl;
      relatorio.close();

      ofstream file1(files[1]);
      relatorio.open(files[1], std::ios::out | std::ios::app);
      relatorio << 0;
      relatorio << " ";
      relatorio << 0 << std::endl;
      relatorio.close();

      ofstream file2(files[2]);
      relatorio.open(files[2], std::ios::out | std::ios::app);
      relatorio << 0;
      relatorio << " ";
      relatorio << 0 << std::endl;
      relatorio.close();

      ofstream file3(files[3]);
      relatorio.open(files[3], std::ios::out | std::ios::app);
      relatorio << 0;
      relatorio << " ";
      relatorio << 0 << std::endl;
      relatorio.close();

      ofstream file4(files[4]);
      relatorio.open(files[4], std::ios::out | std::ios::app);
      relatorio << 0;
      relatorio << " ";
      relatorio << 0 << std::endl;
      relatorio.close();
}