---
title: "aula 9 RPC"
weight: 4
---

# Remote Procedure Call (RPC)
É um mecanismo de comunicação entre processos em ambientes distribuídos, no qual processos requisitam a execução de serviços por parte de um módulo remoto. Na prática, esse mecanismo implementa fielmente o conceito de cliente-servidor.

O módulo remoto, responsável por atender as requisições, é composto por procedimentos e processos tanto internos quanto exportados (visíveis remotamente). 
## Sintaxe
```
module mname
    headers de operações exportadas 

body
- declaracoes de variaveis
- codigo de inicialização 
- procedimentos das ops exportadas
- procedimentos e processos locais

end mname 
```

Os headers são da forma 
> op opname (formals) \[return result\]

Os procedimentos são da forma:
> proc opname (formal identifiers) returns res. identifier 
>   declaracao variaveis locais 
>   comandos

Esses procedimentos são chamados remotamente por:
> call mname.opname(arguments)

## Lógica de execução

| processo que chama | servidor |
|--------------------|----------|
| call mname.op | executa op |
| `estado de espera` | termina de executar op |
| volta a executar | |


## Exemplo - Servidor de relógio 
```c
module TimeServer
    op get_time() returns int;
    op delay(int interval);
body 
    int tod = 0;
    sem m=1, d[n] = ([n] 0), mutex;
    <queue min_heap> (int waketime, int process_id) napQueue;
    proc get_time() return time 
       { time = tod };

    proc delay(int interval) 
    {
        int waketime = tod + interval;
        P(m);
        insert (waketime, my_id) in napQueue;
        V(m);
        P(d[myid]);
    }

    process clock {
        // inicia relogio de hardware
        while (true) {
            // atualiza o relogio 
            tod = tod + 1
            P(m);
            while (tod <= napQueue.top().waketime) {
                napQueue.pop()
                V(d[id]);
            }
            V(m);
        }
    }
    
end TimeServer
```