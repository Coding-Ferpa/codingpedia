---
title: "aula 7 dist mem"
weight: 4
---

# Concorrência em Memória Distribuída

É necessário se escrever mecanismos construídos em cima da comunicação disponível pela rede. Diferentemente do approach padrão em memória compartilhada, usar trocas entre computadores para se saber valores de semáforos, por exemplo, é altamente custo e causa _busy waiting_. Precisa-se criar, portanto, um IPC (_Interprocess Communication_).

## Async and Sync Message Passing Primitives

Este é o IPC mais simples, que precisa de canais dedicados. Canais são filas FIFO de mensagens pendentes. Esses canais podem ser acessadas pelas primitivas **send** and **receive**, sendo elas implementadas em forma sincrona ou assincrona (como o Redis).

### Sintaxe (baseada no andrews)

Declaracao de canal: 
```c
chan ch_nome (Tipo[] lista_de_conteudo);
```
- lista de conteudo: um dos seguintes formatos:
    - ($tipo_1 id_1, ..., type_n id_n$)
    - ($tipo_1, ..., type_n$)

exemplos:
```c
chan input(char c);
chan result[n](int c);
chan disk_access(int cylinder, int block, int count, char *buffer);
```


Usando o canal:
```c
bool empty(chan ch); // retorna se o canal ta vazio ou nao
receive ch(tipo lista_de_variaveis); // retorna a primeira mensagem no canal na ordem dada pelo channel, mas bloqueia a continuacao do codigo.

send ch(tipo lista_de_parametros); // assincrona
sync_send ch(tipo lista_de_parametros) // sincrona
```

#### MergeSort com troca de mensagens assincrona

```c
chan in1(int), in2(int), out(int);

process merge_sort() {
    int first, second;
    receive in1(first);
    receive in2(second);

    while(!empty(in1) && !empty(in2)) {
        if (first < second) {
            send out(first); receive in1(first);
        }
        else {
            send out(second); receive in2(second);
        }
    }

    if (empty(in1)) {
        while(!empty(in2)) {
            send out(second); receive in2(second);
        }
    }
    else if (empty(in2)) {
        while(!empty(in1)) {
            send out(first); receive in1(first);
        }
    }
}
    ```

O canal pode ser vazio sem que de fato o processo filho tenha acabado a execução, ou seja, empty() não pode ser a condição de término.
Portanto, definimos EOS como um valor de final de stream, por exemplo, INT_MAX:


```c
chan in1(int), in2(int), out(int);

process merge_sort() {
    int first, second;
    receive in1(first);
    receive in2(second);

    while(v1 != EOS && v2 != EOS) {
        if (first < second) {
            send out(first); receive in1(first);
        }
        else {
            send out(second); receive in2(second);
        }
    }

    if (v1 == EOS) {
        while(v2 != EOS) {
            send out(second); receive in2(second);
        }
    }
    else if (v2 == EOS) {
        while(v1 != EOS) {
            send out(first); receive in1(first);
        }
    }
}
```