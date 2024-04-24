**AVALIAÇAO DE PERFORMANCE DE ALGORÍTMOS DE ORDENAÇÃO​ - C++** :computer: 

Mestrado em Modelagem Computacional - UFF/ EEIMVR - 20/04/2024

Objetivo deste projeto é executar e cronometrar algoritmos para ordenação de vetores nas linguagens C/C++, obter os tempos de ordenação para as amostragem e comparar as complexidades de cada algoritmo. :timer_clock:

![01](imagens\01.PNG)



Motivação do Estudo: 
--> Muitos problemas computacionais do mundo atual consistem em avaliar, ordenar e/ou classificar grandes massas de informações.
 Problemas como pré-processar, segmentar, classificar, comuns do segmento de **Visão Computacional**, são exemplos de aplicações que necessitam essencialmente de algoritmos poderosos e que consigam produzir respostas em espaço de tempo relativamente pequenos. Naturalmente, para problemas de **Visão Computacional** utiliza-se matrizes M[m][n].
 Neste estudo, trataremo de objetos de dimensão menor, os Vetores V[x], mas cujo o propósito é similar ao de matrizes: guardar informações.

 A análise Teórica de complexidade O(n), juntamente com a análise de tempos de execução de algoritmos.

 palavras-chave:
 EFICIÊNCIA / COMPLEXIDADE / PERFORMANCE / C / C++


Parâmetros:

---> Vetores com V[5000] ~ V[20000];

---> Cada vetor é criado com entradas aleatórias, utilizando como apoio a biblioteca <random> padrão da biblioteca C/C++.

---> x30 vezes a execução de cada ordenação para obter medias de tempo

---> Execução de algoritmos de ordenação: 
• Bubble Sort
• Insertion Sort
• Selection Sort
• Merge Sort
• Quick Sort

---> Cada método de ordenação é validado pelo programa adicional de testes **TesteUnitarioDosMetodos.cpp** criado para este fim.

---> Utilizado software gratuito para plotar gráficos [GNUPLOT](http://www.gnuplot.info/)

---> Os gráficos são gerados e atualizados em tempo real de forma automática pelo programa, através de um Pipe criado para utilizar os recursos disponibilizados pelo [GNUPLOT](http://www.gnuplot.info/).

---> É necessário possuir o [GNUPLOT](http://www.gnuplot.info/) instalado e adicionado como "variável de ambiente" para permitir acesso aos recursos do software via Pipe dentro do programa principal.

---> Os resultados das médias para cada método em cada configuração de teste é armazenado e identificado pelos arquivos no diretório "relatórios-de-testes".

---> Ao finalizar uma bateria de testes, crie uma cópia dos relatórios gerados para garantir que os mesmos não sejam perdidos ao se executar uma nova análise.

---> O programa principal a ser compilado se encontra no arquivo **CronometroPerformance.cpp**

---> Os parâmetros iniciais como devem ser configurados diretamente no código fonte principal **CronometroPerformance.cpp** através das seguintes variáveis declaradas:

![02](imagens\02.PNG)
