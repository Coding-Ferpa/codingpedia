---
title: "exemplos"
weight: 4
---

# barbeiro dorminhoco com troca de mensagens
problema do barbeiro visto em SO, mas com canais

solucao porca (nossa)
chan bar_in(int), cli_in(int), cli_out(int), bar_out(int);

```python
process Barber {
    int receba = 0;
    while (receba != EOS) {
        receive bar_in(receba);
        send cli_in(receba)
        corta()
        send bar_out(receba)
        receive cli_out(receba)
    }
}

process Clients \[i=1 to N\] {
    while(true) {
        int liberado, acabou;
        send bar_in(i);
        receive cli_in(liberado);
        if (liberado != i)
            send cli_in(liberado);
        receive bar_out(acabou);
        send cli_out(acabou);
    }
}
```

---
solução Aleardo
```python
chan req(int), talk(int), cli[N](int)

process Barber {
    int who, val;
    while (who != EOS) {
        receive req(who);
        send cli[who](1);
        receive talk(val);
        corta();
        send cli[who](2);
        receive talk(val);
    }
}

process Clients [i=1 to N] {
    int val;
    while(true) {
        send req(i);
        receive cli[i](val);
        send talk(val);
        receive cli[i](val);
        send talk(val);
    }
}


```

talk pode ser unico pois o cliente so acessa aquela regiao quando cli[i] for ativado.
receive talk no barbeiro nao pode ser trocado por um send cli\[i\]() pois ele mesmo poderia ouvir a mensagem.
receive é sempre bloqueante, ele espera chegar uma mensagem até chegar algo

---

# produtor consumidor (sincrono)
```python
chan produto(int);

process Consumer {
    int prod;
    while (true) {
        receive produto(prod);
        receive produto(prod);
        consome(prod);
    }
}
process Producer {
    int fez;
    while (true) {
        sync_send produto();
            produz();
        sync_send produto();
    }
}

// pode ser ao contrario (sync_send vira receive).

```
# produtor consumidor (assincrono)
```python
chan vazio(int), cheio(int);

process prod {
    int val;
    while (true) {
        receive vazio(val);
            produz();
        send cheio(val);
    }
}

process cons {
    int val;
    while (true) {
        receive cheio(val);
            consome();
        send vazio(val);
    }
}

```