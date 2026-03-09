---
title: "aula 21 modelos de paralelismo"
weight: 4
---

# Identificando pontos passiveis de paralelização

Um programa pode ser paralelizado por, em suma, 2 agentes:
- (1) pelo compilador
- (2) pelo programador

## 1) Pelo compilador
> Envolve  ILP - Instruction level paralelism - usualmente

Deve-se paralelizar instruções se, e somente se, forem identificados trechos de código independentes. 

Essa estratégia é mais factível para máquinas de memória compartilhada, pela ausência de troca de mensagens.

## 2) Pelo programador 
É realizado normalmente para ambientes de memória distribuida, onde o usuário deve identificar e implementar o paralelismo;

Depende, em geral, do tipo de conexão do processador, limitando:
- o tamanho do grão de processamento
- grau de paralismo da máquina 

> HOT TAKE: Se entre cada grão for necessário trocar valores, então os grãos devem ser suficientemente grandes para compensar o tempo gasto ao comunicar-se

> HOT TAKE 2: Se a velocidade em que se recebe novos dados for menor do que a capacidade de processamento, então não se deve aumentar o grau de paralelismo

A identificação do paralelismo possível se torna, portanto, uma tarefa de encontrar o ponto ótimo de particionamento do problema.

## Contra-exemplos

Sistemas com dominação de E/S: temos uma restrição quanto ao tamanho do grão, pois torna-se IMPOSSÍVEL paralelizar o sistema, a não ser em que o E/S seja sincronizado com o processamento em escala.

Sistemas iterativos de corpo curto: tem-se uma restrição quanto ao grau do paralelismo. Quando há poucas operações, paralelizar (em cpu) torna-se também ineficiente, visto que a criação dos mecanismos de controle são, ora, mais lentas do que o próprio processamento.

# Modelos de particionamento

Modelos de particionamento são modelos que definem como o processamento paralelo ocorrerá e de que forma os programas paralelos irão interagir, sendo limitado pelo casamento entre caracteristicas do problema e da máquina em questão.

## Exemplo
Multiplicação de matrizes: o particionamento do problema deve minimizar a necessidade de se percorrer muitas linhas ou colunas numa ordem não-ótima, ou ainda, as trocas de cache. 

Podemos, por exemplo, blocar essa ordem de execução, seja ou copiando cada linha e coluna numa GPU, por exemplo, para aceleração, ou outras formas.

Quando as matrizes são grandes demais, deve-se considerar outras formas de blocar. Essas formas devem considerar o tamanho do cache ou memória presente.

### Algoritmo de Strassen
> $O(n^{log_7})

rapidinho

### Algoritmo de Coppersmith-Winograd (o mais rapido existente) 
nao serve de nada, pois so fica pratico para matrizes grande demais quando se comparada com as existentes hoje


## Como efetivar a paralelização
Tipos:
- Paralelização pelo resultado: define-se o que deve ser produzido pela aplicação. Constroe-se, portanto, o produto por componentes distintos paralelizados.
- Paralelização por especialista: funções em tarefas distinas, as quais são independentes entre si.
- Paralelização por agenda: assume um conjunto de tasks. Os processos paralelos executam uma tarefa e consultam a agenda para  receber uma nova tarefa.


## Paradigmas para interação
- Saco de Tarefas (Bag-of-Tasks): trabalhadores buscam tarefas com o coordenador. Quem requisita dados são os trabalhadores.
- Batimento (Heartbeat):  descentralizado, exige comunicação entre os programas paralelos. Há 3 fases:
1) expansão: envio de dados por todos os processos;
2) contração: cada processo recebe os dados enviados pelos demais processos;
3) processamento: processamento

- Pipeline: pode ser:
1) Aberto: só vai pai
2) Fechado: se auto injeta caso necessário
3) Fechado com coordenador: se injeta com decisão do coordenador

## Tarefas 
- independentes: bag of tasks é ótimo, resultando em um nome: “embarrassingly parallel system”.
- workflow: trabalho é identificar quando agendar uma tarefa para ser executada

## Estratégias
- Paralelismo por eventos/tarefas: aparece em sistemas MIMD. Tem natureza distribuda.
- Paralelismo por dados: SIMD (mesmo código sobre dados distintos).

### Hadoop MapReduce
Projetado para tarefas independentes, executadas em blocos, para grandes quantidades de dados contidos num sistema de arquivos distribuido. Um framework distribui e agrupa as respostas (mapeia e reduz).

Sua ideia básica é dividir o problema em duas fases:

Uma, embaraçosamente paralela:  **map**
Outra, de composição, dada pela função **reduce**

Ou seja, divide o problema inicial em sub-problemas, os mapeia em um par (key-value) qualquer, embaralha e ordena os pares e, então, os reagrupa com uma função de agregação qualquer para o problema.

## Transactional Memory

Busca aplicar a ideia de transações (de BD), no qual tarefas em paralelo são executadas como se fossem independentes e sua validade é verificado no final (com commit).

A principal vantagem é a abordagem otimista em relação aos conflitos em regiões críticas. Desvantagens aparecem quando esse otimismo não se confirma.

Lock ellision: técnica onde uma região crítica é executada numa transaç
ão e, caso o commit não ocorra, a thread é bloqueada.
