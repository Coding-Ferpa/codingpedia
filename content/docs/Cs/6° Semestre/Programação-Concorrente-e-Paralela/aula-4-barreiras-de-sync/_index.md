---
title: "aula 4 barreiras de sync"
weight: 4
---

> [!tip] mini glossario
> *hotspot*: variável acessada por vários processos.

# Barreiras do Sincronismo

Uma barreira é um ponto no programa no qual todos os processos (ou threads) de um grupo devem parar e esperar. Nenhum processo pode prosseguir além da barreira até que todos os processos do grupo tenham chegado a ela.

Essa ideia garante sincronismo entre os processos (vide o nome), visto que a cada etapa de um determinado algoritmo distribuído, todos os processos atuantes teriam que chegar em algum limitante para poder prosseguir.

## Solução de contador compartilhado
Supondo que temos um hotspot arrive, podemos perceber que todos os N processos teriam uma condição de corrida para acessar arrive, tornando a espera ocupada um problema grande.

```c
// Variável compartilhada
integer arrive = 0;

process Worker [i = 1 to N] {
    while (true) {
        <arrive = arrive + 1;>      // Ação atômica
        <await (arrive == N);>      // Espera ocupada (busy-waiting)
    }
}
```

Esse método (ingênuo, de certo modo) gera problema de contenção de memória, onde arrive é acessado por vez dado cada processo.

## Solução do coordenador e flags de sinalização

Para evitar o hotspot de um único contador, podemos usar flags individuais.

```c
process Worker [i = 1 to N] {
    while (true) {
        <arrive[i] = 1;>
        <await (continue[i] == 1);>
        continue[i] = 0;
    }
}
```

```c

process Coordinator {
    while (true) {
        for (j = 1; j <= N; j++) {
            <await (arrive[j] == 1);>
                arrive[j] = 0;
        }

        for (j = 1; j <= N; j++) {
            continue[j] = 1;
        }
    }
}

```

Essa solução, conquanto significativamente melhor que a anterior, sofre de um problema cronico (além de utilizar memória a mais): causa centralização dos N processos em 1 processo coordenador. Esse problema, a priori simples, causa a temida *latência*, já que todo processo precisa esperar que o coordenador o autorize a continuar, criando uma barreira um tanto quanto lenta.

# Princípios de Sincronização por Flags
(i) o processo que espera por uma flag de sincronização ser setada é aquele que deve limpar a flag.
(ii) a flag não deve ser sinalizada até que se saiba que está limpa.

# Solução para evitar uma criação de outro processo Coordenador
Para eliminar o gargalo do coordenador, usamos algoritmos onde os processos se comunicam diretamente entre si.
## Solução com barreira de árvore (Combining Tree Barrier - CTB)

Cria-se uma estrutura de árvore binária para rastrear se todos os trabalhadores chegaram na barreira (ou seja, se arrive == 1).
Verifica-se o filho a direita e o filho a esquerda do processo. Se arrive[left(i)] == 1 e arrive[right(i)] == 1;

Precisamos então, de 3 sub-processos, que sinalizam em 2 flags:
- arrive\[N\]: flag para sinalizar a chegada ao pai 
- continue\[N\]: flag para receber a liberação do pai 

no folha:
```c
arrive[i] = 1;
<await (continue[i] == 1);>
continue[i] = 0;
```

no raiz:
```c
<await (arrive[left(i)] == 1); >
    arrive[left(i)] = 0;
<await (arrive[right(i)] == 1); >
    arrive[right(i)] = 0;
continue[left(i)] = 1; continue[right(i)] = 1;
```

no interior:

```c
// faz o que o raiz faz
// espera os filhos chegarem e limpa-os
<await (arrive[left(i)] == 1); >
<await (arrive[right(i)] == 1); >
arrive[left(i)] = 0;
arrive[right(i)] = 0;

// faz o que o folha faz
arrive[i] = 1; // sinaliza o pai que chegou
<await (continue[i] == 1);> // espera o pai liberar

// faz o que o raiz faz
continue[i] = 0; // limpa seu continue
// permite que os filhos prossigam
continue[left(i)] = 1;
continue[right(i)] = 1; 
```

Neste caso, a latência é proporcional ao tamanho da árvore $(O(log_N))$, não mais a quantidade de processos ($O(N)$).
## Barreiras Simétricas (*Symmetric Barriers*)

Nestas barreiras, todos os processos executam o mesmo código e são equivalentes (não há distinção entre raiz, folha, etc.). A sincronização ocorre em múltiplos estágios.

A ideia central é que, em cada estágio, um processo sincroniza com outro e, ao fazer isso, "aprende" que o grupo de processos do seu parceiro também chegou à barreira. Como o tamanho do grupo que cada processo representa dobra a cada estágio, são necessários apenas $log_{2N}$ estágios para que todos saibam que todos chegaram.

Existem 2 variações desta barreira:
- barreira borboleta; e 
- barreira por disseminação

cada processo avisa outro processo de que chegou na barreira de sincronismo.

Ambas as barreiras implementam um conceito chamado de *sense-reversing* ou barreiras baseadas em rodadas. 

Se usarmos apenas uma flag booleana (chegou/não chegou), podemos ter uma condição de corrida: um processo rápido pode passar pela barreira, executar seu próximo trabalho e chegar na barreira pela segunda vez antes que um processo lento tenha saído da barreira pela primeira vez. O processo rápido veria a flag antiga e passaria direto, quebrando a sincronização.

Para verificar isso, todo processo verifica a iteração $k$ na qual o processo vizinho se encontra, e só avança se o seu vizinho puder avançar também.

#### Barreira por disseminação
Lógica: No estágio $s$, o processo $i$ sincroniza com o processo $(i + 2^s)\ \% \ N$.

No estagio 1, pares adjacentes conversam entre si. Ou seja, a tupla (i, i+1) se fala:

- (0, 1) (2, 3) (4, 5) (6, 7)

No estagio 2: 
- (0, 2) (1, 3) (4, 6) (5, 7)

No estagio 3:
- (0, 4) (1, 5) (2, 6) (3, 7)

#### Na barreira de borboleta

O trabalho $i$ no estagio $s$ conversa com o trabalhador j dado por $j = i \ \ XOR \ \ 2^s$, utilizando flip de gray para o i-ésimo bit

#### Pseudocódigo
solução usando flags e espera ocupada:
```c
// flags[processo][rodada][estágio] - flags para sincronização
// sentido - variável local de cada processo, alterna entre 0 e 1

process Worker[i = 0 to N-1] {
    // Inicializa o sentido local
    sentido = 1; 

    while(true) {
        // ... trabalho ...

        // Inicia a barreira
        for (s = 0 to log2(N)-1) {
			j = para_quem_envia(i, s); // borboleta ou disseminação

            // 1. Sinaliza para o parceiro nesta rodada e estágio
            flags[j][sentido][s] = 1;

            // 2. Espera pelo sinal do parceiro
            < await (flags[i][sentido][s] == 1) >;
        }

        // Inverte o sentido para a próxima vez que usar a barreira
        sentido = 1 - sentido;

        // ... pode prosseguir ...
    }
}
```

solução com semáforos
```c
// i representa o processo atual
// j representa o vizinho/parceiro
// s representa o estagio
for (s=1 to num_estagios) {
	// trabalho
	
	// inicia a barreira
    j = para_quem_envia(i, s); // borboleta ou disseminação
    V(sem[j][s]);
    P(sem[i][s]);
    
    // ... pode prosseguir ...
}
```
