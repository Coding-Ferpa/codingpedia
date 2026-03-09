---
title: "exercicios"
weight: 3
---

# Monitores
5.3
```c
monitor empty {
	int empty = 0;  
	cond cv; 
	
	proc empty() {
		return empty == 0;
	}
	
	proc em_wait() {
		empty--;
		wait()
	}
	
	proc em_signal() {
		empty++;
		signal()
	}
}
	
```

Problema: Implemente uma solução para o problema dos Leitores-Escritores com prioridade para leitores. As regras são:
- Vários processos leitores podem acessar a base de dados simultaneamente.
- Apenas um processo escritor pode acessar a base de dados por vez.
- Se um escritor estiver acessando a base de dados, nenhum leitor pode acessá-la.
- Se um leitor estiver lendo, um escritor deve esperar.
- Se novos leitores chegarem enquanto outros já estão lendo, eles devem ter permissão para ler imediatamente, sem esperar por escritores que já estejam na fila. Isso pode levar à inanição (starvation) dos escritores.

```c
monitor RW {
	int nr = 0, nw = 0;
	int num_data = 0;
	cond read, writ;
	
	
	procedure Reader [i=0 to N] {
		if (num_data == 0) {
			signal(writ);
			wait(read);
		}
		
		nr++;
		num_data--;
		signal(read);
	}
	procedure Writers [i=0 to M] {
		if (nr > 0 || nw > 0)   
			wait(writ);
		nw++;
		num_data++;
		if (!empty(read))
			signal_all(read);
		else
			signal(writ);
	}
}
```
# Await
# Barreira
3.15 - Barreira Borboleta ou 
```c
void getPartner (int i, int s, int N) {
	if (N == 0)
		return i << s;
	return pow(2, s-1) % N;
}
void barrier (int i, int s, int stages, int N) {
	// sincroniza
	for [s=0 to N] {
		for [i=0 to stages] {
			j = getPartner(i, s, N); // gray code
			sem[j][s];
			sem[i][s];
		}
		s++;
	}
}
#define butterfly_barrier(int i, int s, int stages) barrier(int i, int s, int stages, 0)
#define dissemination_barrier(int i, int s, int stages, int N) barrier(int i, int s, int stages, N)

process Worker {
	int s = 0;
	while (true) {
		if (N % 2 != 0) return NULL;
		
		num_stages =  ceil(log_2N);
		sem[N][num_stages];
			
		// Trabalha
		// ...
		barrier(i, s, num_stages, N); 
		// Trabalha de novo
		// ...
	}
}
```

# Troca de mensagens
Troca de Mensagens (Dificuldade: Alta)

Problema: Resolva o problema dos Fumantes de Cigarros (Cigarette Smokers' Problem) usando troca de mensagens assíncrona.

Existem três processos fumantes e um processo agente. Para fazer um cigarro, são necessários três ingredientes: tabaco, papel e fósforos.
- O agente tem um suprimento infinito de todos os três ingredientes.
- Cada fumante tem um suprimento infinito de apenas um ingrediente.
	- Fumante 1 tem tabaco.
	- Fumante 2 tem papel.
	- Fumante 3 tem fósforos.
- O agente repetidamente coloca dois ingredientes diferentes na mesa.
- O fumante que tiver o terceiro ingrediente (o que falta) deve pegá-los, enrolar e fumar o cigarro. Depois de fumar, ele sinaliza ao agente que terminou.
- O agente então coloca outros dois ingredientes, e o ciclo se repete.
// funciona desse jeito, mas eh paia, seria melhor usar 3 canais distintos e so syncar ao final do fumo
```c
chan fumo, ingredientes(int tabaco, int papel, int fosforos);

process agente {
	if (empty(ingredientes))
		send ingredientes(1, 1, 0);
	int who = 0;
	while (true) {
		receive fumo(who);
		if (who == 1) {
			send ingredientes(1, 1, 0);
		}
		if (who == 2) {
			send ingredientes(1, 0, 1);
		}
		if (who == 3) {
			send ingredientes(0, 1, 1);
		}
	}
}

process fumante [i=1 to 3] {
	while (true) {
		int tabaco = 0, papel = 0, fosforos = 0;
		receive ingredientes(tabaco, papel, fosforos);
		if (i == 1 && tabaco) {
			send ingredientes(tabaco, papel, fosforos);
			continue
		}
		if (i == 2 && papel) {
			send ingredientes(tabaco, papel, fosforos);
			continue
		}
		if (i == 3 && fosforos) {
			send ingredientes(tabaco, papel, fosforos);
			continue
		}
		send fumo(i);
	}
}
```


// 4 canais (evita bottleneck de repetir entries)
```c
chan papel(bool), fosforo(bool), papel(bool), fumo(bool); 

process Agente {
    while(true) {
        int escolha = rand() % 3;
        if (escolha == 0) {
            send papel(true);
        } else if (escolha == 1) { 
            send fosforo(true);
        } else { 
            send tabaco(true);
        }
        
        receive fumo(_);
    }
}

process fumate_1 {
    while(true) {
        receive papel(_); 
        fuma();
        send fumo(true);
    }
}

process fumante_2 {
    while(true) {
        receive fosforo(_); 
        fuma();
        send fumo(true);
    }
}

process fumante_3 {
    while(true) {
        receive tabaco(_); 
        fuma();
        send fumo(true);
    }
}
```
# RPC 

exercicio: faça um TimeServer com RPC
```C
module TimeServer
	sleep(int time_to_sleep, int id);
body 
	int time = 0;
	queue nap_queue;
	sem mutex;
	sem procesos[N];

	proc sleep(int time_to_sleep, int id) {
		if (time_to_sleep > 0) {
			P(mutex);
			nap_queue.insert({
				time: time + time_to_sleep, 
				id: id
			});
			V(mutex);
			P(processos[id]);
		}
		return
	}
	
	process clock {
		while (true) {
			P(mutex);
			time += 1;
			check = nap_queue.top()
			while (time >= check.time)  {
					nap_queue.pop()
					V(processos[check.id]);
					check = nap_queue.top()
			}
			V(mutex);
		}
	}

end TimeServer
```

Problema: Você precisa implementar um Servidor de Travas Distribuídas (Lock Server) usando RPC. Processos clientes em diferentes máquinas precisam adquirir e liberar travas (locks) para acessar recursos compartilhados. O servidor deve gerenciar um conjunto de N travas distintas.

As operações que o servidor deve fornecer são:
- int create_lock(): Cria uma nova trava e retorna seu ID.
- void lock(int lock_id, int client_id): Adquire a trava com o ID lock_id. Se a trava estiver ocupada, a chamada do cliente deve bloquear até que a trava seja liberada.
- void unlock(int lock_id, int client_id): Libera a trava com o ID lock_id. Só pode ser chamada pelo cliente que atualmente possui a trava.

```c
module LockServer
	int create_lock();
	void lock(int lock_id, int client_id);
	void unlock(int lock_id, int client_id);
body 
	lock trava[N] = ([N] 0);
	int nl = 0;
	sem cli[N];
	sem mutex;
	
	int create_lock() {
		if (nl < N - 1) {
			P(mutex);
			int id = nl++ % N;
			return id;
			V(mutex);
		}
		else 
			return -1;
	}
	void lock(int lock_id, int client_id) {
		P(mutex);
		if (trava[lock_id] == 0) 
			trava[lock_id] = client_id;
			P(cli[lock_id]);
		V(mutex);
	}
	void unlock(int lock_id, int client_id) {
		P(mutex);
		if (trava[lock_id] == client_id) 
			trava[lock_id] = 0;
			V(cli[lock_id]);
			// ver se tem alguem na fila e unlockar tbm
		else {
			// adicionar a uma fila relacionada a trava
		}
		V(mutex);
	}
end LockServer
```

# Rendezvouz
Exercício: Rendezvous (Dificuldade: Média)

Problema: Crie um módulo reutilizável chamado Exchanger que permita que dois processos realizem um rendezvous para trocar um valor inteiro.

O módulo deve fornecer um único procedimento:
- int exchange(int my_value)

Regras de funcionamento:
- Quando um processo (vamos chamá-lo de P1) chama exchange(value1), ele deve bloquear e esperar até que um segundo processo (P2) também chame a função.
- Quando P2 chama exchange(value2), a troca acontece.
- Após a troca, a chamada de P1 deve retornar value2, e a chamada de P2 deve retornar value1.
- Ambos os processos devem ser desbloqueados para continuar suas execuções somente após a troca ser concluída.
- O módulo deve estar pronto para ser reutilizado por outro par de processos após a conclusão de uma troca.


```

module Exchanger
    op exchange (int val) [returns int];
body 
    int a = INT_MAX, b = INT_MAX;   
    sem wait = 0;

    while (true) {
        in exchange(int val) -> {
            if (a != INT_MAX){
                b = val;
                V(wait);
                int local_a = a
                a = INT_MAX;
                return local_a;
            } else  {
                a = a_val:
                P(wait);
                return b;
            }
        }
        ni
    }

end Exchanger

```




# Prova 2
1. Escreva uma solução para o problema do barbeiro dorminhoco usando troca de mensagens síncrona (10/3 pontos).
asincrono
```c
chan barber(int), client[N](int), talk(int)

process Barber {
	int val = 0, t;
	while(val != EOS) {
		receive barber(who);   // espera ser acordado
		send client[who](1);   // autoriza o cliente a vir
		receive talk(t);       // recebe que o cliente chegou
		cut(who);
		send client[who](who); // avisa o cliente que acabou
		receive talk(who);     // espera o cliente avisar que saiu
	}
}

process Client [i=1 to N] {
	int cut = 0;
	while(val != EOS) {
		send barber(i);         // faz a requisicao para ser atendido
		receive client[i](cut)  // espera o barbeiro liberar o seu canal (la ele)
		send talk(i);           // avisa o barbeiro que sentou na cadeira
		receive client[i](cut); // espera o barbeiro terminar de cortar
		send talk(i);           // avisa que saiu da cadeira
	}
}
```
síncrono 

muito mais fácil, visto que o cliente simplesmente espera ao fazer todo send
```c
chan barber(int), client[N](int), chair(int)

process Barber {
	int val = 0, t;
	while(val != EOS) {
		receive barber(who);        // espera ser acordado
		receive talk(t);            // recebe que o cliente chegou
		cut(who);
		sync_send client[who]();    // avisa o cliente que acabou
	}
}

process Client [i=1 to N] {
	while(val != EOS) {
		sync_send barber(i);        // faz a requisicao para ser atendido
		sync_send talk(i);          // avisa o barbeiro que sentou na cadeira
		receive client[i]();   // espera o barbeiro terminar de cortar
	}
}
```

2. A solução a seguir supostamente faz a implementação de troca de valores entre N processos parceiros, usando troca de mensagens assíncrona, para determinar o menor e o maior desses valores. Verifique se a solução é correta (10/3 pontos)
![[Pasted image 20250924172612.png]]
notas:
- me parece overkill todos os processos enviarem para todos os outros seus valores, porque vao ter N processos agora que sabem o maior e menor.
- funciona


3. Escreva uma solução para o problema de múltiplos produtores-consumidores, com buffer de N posições usando monitores (10/3 pontos).


```c
// assuma que N exista
monitor mname {
	sem mutex;
	int lastIn, lastOut, products, buffer[N];
	products = first = last = 0;
	cond prod, cons;
	
	procedure consumer [i=0 to N] {
		int dado;
		while(true) {
			if(nprod == 0)
				wait(cons);
			wait(prod);
			dado = buffer[lastIn];
			consome(dado);
			P(mutex);
			lastIn = lastIn++ % N;
			V(mutex);
			if(!empty(prod)) signal(prod);
		}
	}
	
	procedure producer [i=0 to M] {
		int item;
		while(true) {
			if  ( last == N - 1) 
				wait(prod);
			produz(item);
			P(mutex);
			buffer[lastOut] = item;
			nprod++;
			lastOut = lastOut ++ % N;
			V(mutex);
			if(!empty(cons)) signal(cons);
		}
		
	}
}
```


4. Considere que um conjunto de processos coopere através de semáforos distribuídos, ou seja, um tipo de semáforo em que seja permitido o bloqueio de um processo mesmo não usando memória compartilhada. Implemente um servidor de semáforos usando RPC para cumprir essa função (10/3 pontos).
```c
module Semaphore
	sem_P(sem s);
	sem_V(sem s);
	sem_init(int val) return sem;
	
body 
	sem mutex;
	sem sems[N];
	int num_sem = 0;
	
	proc sem_init(int val) {
		P(mutex);
		sems[num_sem++] = val;
		V(mutex);
		return num_sem;
	}
	
	proc sem_P(sem s) {
		if (s <= 0)
			P(sems[s]);
		else  {
			P(mutex);
			num_sem--;
			V(mutex);
		}
	}
	
	proc sem_V(sem s) {
		if (s == 0)
			V(sems[s]);
		else  {
			P(mutex);
			num_sem++;
			V(mutex);
	}

end Semaphore
```
