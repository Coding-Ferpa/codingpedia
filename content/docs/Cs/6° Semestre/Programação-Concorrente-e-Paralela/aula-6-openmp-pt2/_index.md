---
title: "aula 6 openmp pt2"
weight: 4
---

> [!tip] Não cai na prova

# OpenMP parte 2
`SECTION`
Atribui tarefas distintas aos threads, ou seja, cada section representa uma thread distinta, ou seja, nao rodam o mesmo codigo.

```c

#pragma omp section 
```

`MASTER`

Trecho executado apenas pelo thread principal

```c
#pragma omp parallel {
...
#pragma omp master {
    printf("Hello World\n");
}
}
```

`SINGLE`

Trecho executado por um dos threads (o que chegar primeiro).

```c
#pragma omp parallel {
...
#pragma omp single {
    printf("Hello World\n");
}
}
```

`TASK`

Uma task é uma forma de criar seções sem ter que conhecer de antemão quantas seções são necessárias, nem quais threads executarão.
```c
#pragma omp parallel {
...
#pragma omp task
    printf("Hello World\n");
#pragma omp task
    printf("Hello Country\n");
}
```
---
Um exemplo que sera explorado outras vezes é o problema de transferencia de calor, enunciado da seguinte forma: 

> [!question] Exemplo
> Suponha uma chapa em que as bordas são mantidas em temperatura constante, assim como pontos isolados da chapa. Como determinar a temperatura de um ponto qualquer da chapa?

Podemos usar um algoritmo de aproximacao sucessiva, como o chamado algoritmo de `red & black`. Nesse caso, cada ponto da chapa tem sua temperatura, numa iteracao, como sendo a media das temperaturas do seu vizinhos e de sua propria na iteracao anterior. $P<i,j>' = \frac{P<i-1, j> + P<i, j - 1> + P<i + 1, j> + P<i, j + 1> + P<i, j>}{5}$
