---
title: "monitores"
weight: 4
---

# Monitores
É um TAD utilizado para sincronismo, exclusão mutua e etc.
Um monitor exporta $n$ funções através de requisições diretamente à um processo, ou seja, somente um processo é capaz de acessar o monitor por vez.

`Sintaxe`: 
```c
monitor mname {
    // Declaração de variáveis permanentes
    // comandos de inicialização
    // procedimentos do monitor
};
```

- Apenas os **nomes** e args dos procedimentos são visíveis externamente.
- Comandos de inicialização dos procedimentos não podem acessar variáveis externas ao monitor.
- Variáveis permanentes são inicializadas antes de executar a primeira chamada ao monitor. 

Os procedimentos do monitor são chamadas assim:

> call mname.opname(args);

Por definição, procedimentos são executados em exclusão mútua, obitda implicitamente na implementação do TAD monitor.

## Funções implícitas
Interações entre processos, providas pelo monitor, são controladas por **variáveis condicionais**, acessadas por funções específicas.

Declaração de variável condicional:

> cond cv;

Funções sobre variáveis condicionais:
```c
 empty(cv); // retorna zero se existe processo esperando por cv.
 wait(cv); // bloqueia processo que fez a chamada, liberando o acesso ao monitor
 wait(cv, rank); // bloqueia o processo, usando o valor de rank para inserir na fila
 signal(cv); // libera processo na frente da fila de cv
 signal_all(cv); // libera todos os processos na fila de cv
 minrank(cv); // retorna o rank do processo na frente da fila
```

## Politicas de liberação (signal)
- Signal and Continue (SC): o procedimento que fez a chamada continua a ser executado (processo não sofre preempção).
- Signal and Wait (SW): o procedimento que fez a chamada cede a execução para o processo que foi liberado.

### Exemplo - Implementação das primitivas de semáforo usando monitores ("depende" de SW)
```c
monitor Semaphore {
    int s = 0;
    cond pos;

    procedure Psem() {
        while (s == 0) {
            wait(pos);
        }
        s--;
    }
    procedure Vsem() {
        s++;
        signal (pos);
    }
}
```

esta solução, apesar de correta, não garante o melhor atendimento numa política SC. Para também se obter isso, podemos modificar o monitor para:

```c
monitor FIFOSemaphore{
	int s = 0;
	cond pos;
	
	procedure Psem(){
		if (s == 0)
			wait(pos);
		else
			s = s - 1;
	}
	
	procedure Vsem(){
		if (empty(pos))
			s = s + 1;
		else
			signal(pos);
	}
}
```

