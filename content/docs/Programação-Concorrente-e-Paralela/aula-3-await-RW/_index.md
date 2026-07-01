---
title: "aula 3 await RW"
weight: 4
---

# await

comando que de fato não faz nada, atua como uma flag de sincronismo. Em sua forma mais simples temos

> <S;> => indica que S é executado de modo exclusivo

temos também a forma que indica sincronismo simples:

> <await(B);>=> indica que o próximo comando será executado quando B for válido

temos finalmente, a combinação, dada por:

> <await(B) S;> - representa uma ação atômica condicional, ou seja, atrasa a execução até que B seja verdadeiro e então executa S.

Await pode ser implementado dentro de uma região crítica, sendo a ação atômica condicional descrita por um while loop, no formato busy waiting (espera ocupada):

```c
CSEnter; \\ demilitador entrada da região critica
while (!B) {
    CSexit; \\ delimitador saida da região crítica
    delay;
    CSEnter; \\ demilitador entrada da região critica
}
S;
CSexit; \\ delimitador saida da região crítica
```

este código evalua B dentro da região critica, tornando a execução atomica. Percebe-se que, ao sair da região critica dentro do while, outra thread pode executá-la também, mantendo a ideia de atomicidade. 

Isso significa que o código vai rodar até B ser atendido enquanto outras threads podem tomar a frente na race condition proporcionada.

Entenda também que a implementação apresentada é apenas teórica, visto que delay usa tempo da CPU a toa.

---

## Aplicando o await - problemas do múltiplos leitores/escritores


Como await é uma abstração de uma ação condicional atômica, podemos implementá-los de diversas formas, desde que consigamos garantir a atomicidade e que a condição seja respeitada.

```c
int nr = 0; // numero de leitores ativos
sem rw = 1; // semaforo de escritores

process Writer[j=1 to N] {
	while (true) {
		...
		P(rw);
		escreve;
		V(rw);
	}
}

process Reader [i=1 to M] {
	while (true) {
		<	nr = nr + 1; if (nr == 1) P(rw); > // quando há um leitor, paramos as escritas
		leitura;
		<   nr = nr - 1;  if (nr == 0) V(rw); > // quando há 0 leitores, voltamos a escrever
	}
}
```

Vamos usar 2 formas, os semáforos e os monitores, vistos anteriormente:

### semáforos 
```c
int nr = 0;    // numero de leitores ativos
sem rw = 1;    // semaforo de escritores
sem mutex = 1; // semaforo de mutual exclusion

process Writer[j=1 to N] {
	while (true) {
		...
		P(rw);
		escreve;
		V(rw);
	}
}

process Reader [i=1 to M] {
	while (true) {
		...
		P(mutex);
		nr = nr + 1;
		if (nr == 1) P(rw);
		V(mutex);
		
		leitura;
		
		P(mutex)
		nr = nr - 1;
		if (nr == 0) V(rw);
		V(mutex);
	}
}
```

não se pode utilizar apenas um semaforo no reader (como foi feito anteriormente pelo professor), pois precisa-se ter um semaforo para entrada de leitores e um semaforo para saída de leitores, pois se usasse o mesmo, caso ficasse um leitor esperando pois houve solicitação de escrita, não seria possível liberar os leitores que já estavam lendo, pois o mutex estaria com o leitor que foi bloqueado na entrada.

Encontramos, no entanto, um problema muito comum na concorrencia, o conceito de fairness. Ou seja, evitar starvation. Uma possível solução é se utilizar do conceito de atraso para ver quem está ativamente trabalhando e quem está parado esperando.

```c
int nr = 0, nw = 0, dr = 0, dw = 0;

// dr = delayed reader || dw = delayed writer

sem e = 1, r = 0, w = 0;

process Writer[j=1 to N] {
	while(true) {
		P(e);
		if (nr > 0 or nw > 0) {
			dw = dw + 1;
			V(e);
			P(e);
		}
		nw = nw + 1;
		V(e);

		escreve;

		P(e);
		nw = nw - 1;
		if (dr > 0) {
			dr = dr - 1;
			V(r);
		}
		else if (dw > 0) {
			dw = dw - 1;
			V(w);
		}
		else
			V(e);
	}
}

process Reader[i=1 to M] {
	while (true) {
		P(e);
		if (nw > 0) {
			dr = dr + 1;
			V(e);
			P(r);
		}
		nr = nr + 1;
		if (dr > 0) {
			dr = dr - 1;
			V(r);
		}
		else {
			V(e);
		}

		leitura;

		P(e);
		nr = nr - 1;
		if (nr == 0 and dw > 0) {
			dw = dw - 1;
			V(w);
		}
		else {
			V(e);
		}
	}
}
```

nr e nw contam numero de readers e writers ativos.
dr e dw são "salas de espera" onde os r e w esperam ser acordados.

sem e = 1; // controla todo processo, leitor ou escritor, para modificar as variaveis de contagem. Garante atomicidade.
sem r = 0; // espera dos readers
sem w = 0; // espera dos writers
### Monitores
```c
monitor RW_Controller{
	int nr = 0, nw = 0;
	cond OK_to_read, OK_to_write;
	
	procedure request_read() {
			while (nw > 0)
				wait(OK_to_read);
			nr = nr + 1;
	}
	
	procedure release_read() {
		nr = nr - 1;
		if (nr == 0) signal(OK_to_write);	
	}
	
	procedure request_write() {
		while (nr > 0 || nw > 0)
			wait(OK_to_write);
		nw = nw + 1;	
	}

	procedure release_write() {
		nw = nw - 1;
		signal(OK to write);
		signal_all(OK to read);
	}
}
```

ainda causa starvation, no entanto, a abstração é consideravelmente mais simples.