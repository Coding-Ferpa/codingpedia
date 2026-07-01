---
title: "aula 10 Rendezvous"
weight: 4
---

# Rendezvous
O cliente chama uma operação e o servidor explicitamente aceita essa chamada em um ponto específico de seu código usando a instrução in. É um encontro (sincronização) direto entre dois processos ativos. O servidor tem controle total sobre qual chamada aceitar e quando, usando guardas e escalonamento.

## Sintaxe
```c
// lado do cliente
call mname.opname(params);

// Lado do servidor
// - Definição das operações exportadas 
op opname(tipos_dos_parametros);

// No ponto de Rendezvouz
in opname(id param) -> S; ni 

// em que S é uma sequência de comandos;
```

S: sequência de comandos

O ponto de Rendezvouz pode envolver várias operações e também condições de escalonamento, como em:

```c
in op1(formals_1) and B1 by e1 -> S1;
	[] ...;
	[] opn(formals_n) and Bn by en -> Sn;
ni
```

# Filósofos com fome (tadinhos)

Vamos alterar a lógica para verificar se os $i - 1$ e $i + 1$ vizinhos de $i$ estão comendo ou não.

```c
process Filosofos [i=0 to 4] {
	while (true) {
		call getForks(i);
			eat();
		call relForks(i);
			think();
	}
}

module Table
	op getForks(int), retForks(int);
body 
	process Waiter {
		bool eating[5] = ([5] false);
		while (true) {
			in getForks(i) and eating[right(i)] == false and eating[left(i)] == false -> eating[i] = true
			[] relForks(i) -> eating[i] = false;
			ni
		}
	}
end Table
```

se getForks não retornar S, ele enfileira a requisição de i.

## Servidor de relógio
- não precisa de fila alguma (o Rendezvouz já tem uma fila)

```c
module TimeServer
	op getTime() returns int;
	op delay(int);
	op tick(): // chamada para relogio "real"
body
	process Timer {
		int tod = 0;
		while (true) {
			in get_time() returns time -> time = tod;
			[ ] delay(waketime) and waketime <= tod -> skip;
			[ ] tick() -> {
				tod = tod + 1;
				restart timer'
			}
			ni
		}
	}
end TimeServer
```

## SJFT - Shortest Job First Time

```c
module SJFT_Allocator 
	op request(int time), release();
body 
	process SJFT {
		bool free=true;
		while (true) {
			in request(time) and free by time -> free=false;
			[] release() -> free =true;
			ni
		}
	}
end SJTF_Allocator
```

ai que entra *by time*, para comparar o tamanho do tempo (por tempo);