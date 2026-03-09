---
title: "Exercicios PAA"
weight: 3
---

[[Exercícios PAA - draw]]
# Exercício 1
descreva um algoritmo que, dado um conjunto S de n inteiros
e um outro inteiro x, determine se existem ou não dois elementos em S
cuja soma seja exatamente x. Seu algoritmo deverá levar um tempo Θ(n
lg n) no pior caso.

---
# Solução:
Temos inicialmente, que ordenar o vetor para poder saber que numeros operar.
Portanto, usaremos o merge Θ(n log(n)).
Agora, usaremos 2 ponteiros para passar pelo vetor ordenado. Assim, podemos usar o seguinte critério:
``` c
func (int A[], u16 min, u16 max){
    if (min = max)
        return false;
    if (A[min]  + A[max] > x)
        return func(A, min, max - 1)
    if (A[min] + A[max] < x)
        return func(A, min + 1, max)
    return true;
}
```
