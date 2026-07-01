---
title: "aula 1 revisão"
weight: 4
---

# Dados do curso
Media Final: $(\frac{P_1 + P_2 + MProj}{3} \ + \ \text{Artefato})$

# Programa (sem ordem)
- Princıpios basicos de concorrencia.
- Solucoes para problemas classicos em memoria compartilhada
- Solucoes para problemas classicos em memoria distribu ́ıda
- Computação de alto desempenho e paralelismo
- Threads e openMP
- Condicoes e modelos de paralelismo
- Avaliacao e otimizacao de desempenho
- CUDA e openCL
- MPI

# Previsão de Datas

- Revisao sobre regiao crıtica, semaforos e deadlocks
- Concorrencia usando monitores
- Exemplos de problemas concorrentes
- Mais exemplos
- Threads
- openMP, parte 1
- openMP, parte 2
- Concorrencia usando troca de mensagens
- Novos exemplos
- RPCS
- Exemplos
- Rendezvous
- Exemplos
- Primeira Prova
- Computacao de alto desempenho
- GPUs e CUDA
- CUDA, parte 2
- Processadores para alto desempenho
- Memoria para alto desempenho
- Conectividade para alto desemepnho
- Condicoes de paralelismo
- Modelos de paralelizacao
- MPI, parte 1
- MPI, parte 2
- Avaliacao de desempenho
- Otimizacao de codigo
- openCL
- Segunda Prova
- Apresentacoes de artefatos
- EXAME

# Revisão de concorrência (visto em SO)

Causas de um deadlock:
- hold de recursos 
- circular wait

Algoritmos de tratamento:
- Banqueiro: garante que um processo so rode se todos os recursos que ele requer estejam disponiveis (nao importa muito como ele faz isso)
- Padaria (pãozinho): da prioridade para o processo requerente por um numero natural sempre crescente, assim o proximo requerente tera menos prioridade para acessar um recurso.
- Detecção de ciclo (de floyd):  algoritmo da tartaruga e lebre, 2 ponteiros se dispoem na sequencia de eventos, cada um iterando por ela em velocidades distintas (dai o nome). Mais complexo do que o necessario para o momento.
- Timeout (batizado de agiota pelos conterraneos): empresta o recurso por x unidades de tempo e o remove em caso de atraso.
