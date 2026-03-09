---
title: "Heap Sort"
weight: 3
---

### conteudo pra Eng. software bom
Sort -> saiba o merge sort.
Tabela Hash -> esteja preparado pra explicar uma tabela hash e saiba como implementá-la.
Usar API, uma lang, conhecimento de design e POO, dijkstra, A*
ED-> dinâmicas, tabela hash, dicionário, heap e grafos.
Matemática discreta 
AVL, DFS, BFS, Dijkstra e A* 

---
# heap
- árvore binária quase-completa
- vetorizada.
- filho a esquerda de i (2i) 
- filho a direita de i(2i +1)
- pai de i = i/2 
- A[0] = raiz da árvore
## heap máximo e minimo
_máximo_ $A[PAI(i)] \geq A[i]$  maior elemento está na raiz, menor na ultima folha a direita 16 -> 1
_minimo_ $A[PAI(i)] \leq A[i]$ o contrário
# Heap Sort

Heap Sort -> ordenação in-place: um numero constante de elementos do vetor é armazenado 
- construido com heap

Complexidade = $O(\lg{n})$

_MAX_HEAPIFY_. 
> Se algum filho for maior que o pai atual, trocaremos ele com o maior filho e faremos a mesma verificação com o filho escolhido.

``` c
void max_heap(heap *A, int i) {
	int l = 2i;
	int r = 2i+1;
	int maior = 0;

	if (l <= A->size && A[l] > A[r]) {
		maior = l; 
	}
	else
		maior = i;
	if (r <= A->size && A[r] > A[maior])
		maior = r;
	if (maior != i){
		swap(A[i], A[maior]);
		max_heapify(A, maior);
	}
}
```

_BUILD_MAX_HEAPIFY_
o sub-vetor de $A(\lfloor \frac{n}{2}\rfloor +1 : n)$ não precisa ser alterado. 
Essa função começa de $i = \frac{n}{2}$ a cada iteração executando _MAX_HEAPIFY_ 
``` c
void max_heapify(heap *A) {
	A->size = A->length;
	for(int i = n/2; i > 0; i--)
		max_heap(A, i);
}
```
invariante de laço: No começo de cada iteração do laço for das linhas 2-3, cada nó i+1, ..., n é a raiz de um heap máximo.

_HEAPSORT_ 
``` c
void HEAP_SORT(heap *A) {
	BUILD_MAX_HEAP(A);
	for(int i = A.length; i > 1; i--){
		swap(A[i], A[0]);
		A.size--;
		max_heapify(A, 1);
	}
}
```


# Fila de Prioridade

Uma fila de prioridade é uma estrutura de dados para manter um conjunto S de elementos, cada qual com um valor associado denominado chave. Como ocorre com os heaps, existem dois tipos de filas de prioridades: filas de prioridade máxima e filas de prioridade mínima.

Quando usamos um heap para implementar uma fila de prioridades dentro de determinada aplicação, os elementos na fila de prioridades correspondem a objetos na aplicação. Cada objeto contém uma chave. Se a fila de prioridades for implementada por um heap, você precisa determinar qual objeto da aplicação corresponde a determinado  elemento do heap, e vice-versa e, como os elementos do heap são armazenados em um vetor, é preciso encontrar uma maneira de mapear os objetos de aplicação de e para índices do vetor.

Uma forma de mapear os objetos de aplicação e os elementos do heap é por meio de descritores, que são informações adicionais armazenadas nos objetos e elementos do heap que dão informações suficientes para realizar o mapeamento. Os descritores são frequentemente implementados para serem opacos ao código em redor, mantendo, assim, uma barreira de abstração entre a aplicação e a fila de prioridades.  Normalmente, o custo adicional (overhead) no pior caso para a manutenção de descritores é O(1) por acesso, á que eles normalmente são utilizado por meio de ponteiros nos elementos do heap. Como alternativa para incorporar descritores em objetos de aplicação, pode-se armazenar na fila de prioridades um mapeamento entre objetos de aplicação e índices de vetor no heap.

## Fila de Prioridade Maxima
Entre outras aplicações, podemos usar filas de prioridade máxima para programar trabalhos em um computador compartilhado por diversos usuários. A fila de prioridade máxima mantém o controle dos trabalhos a executar e suas prioridades relativas e quando um trabalho termina ou é interrompido, o escalonador seleciona o trabalho de prioridade mais alta entre os trabalhos pendentes por meio do getMax. O escalonador pode acrescentar um novo trabalho à fila em qualquer instante chamando insert.

Uma fila de prioridade máxima suporta as seguintes operações:

- insert(S, x, k) insere o elemento x com chave k no conjunto S, que é equivalente à operação S = S ∪ {x}.

- max(S) retorna o elemento de S que tenha a maior chave.

- getMax(S) remove e retorna o elemento de S que tenha a maior chave.

- incKeys(S, x, k) aumenta o valor da chave do elemento x até o novo valor k, que se admite ser, pelo menos, tão grande quanto o valor da chave atual de x.

## Fila de Prioridade Minima
Alternativamente, uma fila de prioridade mínima suporta as operações insert, min, getMin e decKey. Uma fila de prioridade mínima pode ser usada em um simulador orientado a eventos. Os itens na fila são eventos a simular, cada qual com um instante de ocorrência associado que serve como sua chave. Os eventos devem ser simulados na ordem de seu instante de ocorrência, porque a simulação de um evento pode provocar outros eventos a simular no futuro.


MAXIMUM(S) devolve o elemento de S que tenha a maior chave.
![[Pasted image 20241007092630.png]]

INSERT(S, x) insere o elemento x no conjunto S. 
![[Pasted image 20241007092610.png]]

EXTRACT-MAX(S) remove e devolve o elemento de S que tenha a maior chave.
![[Pasted image 20241007092524.png]]

INCREASE-KEY(S, x, k) aumenta o valor da chave do elemento x até o novo valor k, que admite-se ser, pelo menos, tão grande quanto o valor da chave atual de x.
![[Pasted image 20241007092550.png]]
