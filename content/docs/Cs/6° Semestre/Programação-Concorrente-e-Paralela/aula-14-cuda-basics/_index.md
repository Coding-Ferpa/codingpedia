---
title: "aula 14 cuda basics"
weight: 4
---

antes de falarmos de CUDA, vamos falar de GPU de maneira geral primeiro

### introdução

começou com o desenvolvimento de APIs que permitissem a programação das placas gráficas em alto nível

a dificuldade era desenvolver os programas em DirectX (já utilizado em GPU) para fazer o processamento de calculos númericos pesados

### bibliotecas
desenvolvidas para trabalhar com GPU
- CUDA
- OpenCL
- OpenACC

### arquitetura de GPUs

arquitetura massivamente paralela

os núcleos de processamento são direcionados a operações aritméticas

um alto grau de paralelismo aumenta desempenho

### Graphical Processing Units

iniciaram a lançar familias de GPUs com enfoque para processamento aritmético SEM saída para tela (processamento gráfico nõa era o principal objetivo)

séries da NVIDIA:
- Tesla (2008)
- Fermi (2011)
- Kepler (2012)
- Ampere (2020)
- Hopper (2022)

### programação

as diferenças de arquitetura tornam a programação sensível ao contexto, um programa otimizado para uma GPU pode não funcionar bem em outra

CPU acessa a memória principal, por meio de transferencia para a cache

a GPU também possui cache, mas ela não faz acesso a memória principal, pois o acesso é muito mais lento do que a CPU, então deve-se evitar ao máximo a transferência de dados entre memória principal e GPU. para isso, deve-se transferir o máximo de volume de dados por vez.

---

# CUDA is life

criada para programação em GPU da Nvidia

já é ótimizada para tais placas de vídeo, tanto que um código mediano em CUDA tem desempenho semalhante a um código excelente em OpenCL (estando em uma paca da nvidia)

**arquitetura**
- expoe paralelismo da GPU para computação de propósito geral

**CUDA C/C++**
- baseado no padrão C/C++
- pequeno conjunto de extensões para habilitar programação heterogênea (código parcialmente executado na CPU e parcialmente na GPU)
- APIs direcionadas para gerenciar dispositivos, memória

### hello world
**hello world - versão C (mitinho)**
```c
int main (void) {
	printf("Hello World!\n");
	return 0;
}
```

```bash
$ nvcc
hello_world.cu
$ a.out
hello world!
```

**hello world - versão CUDA IS LIFE**
```
__global__void mykernel (void) {

}

int main (void) {
	mykernel<<<1,1>>>();
	printf("hello world!\n");
	return 0;	
}
```

keywords
- `__global__` : indica uma função que executara na GPU
- `nvcc`: separa o src entre host e dispositivo (host é GPU e dispositivo é GPU)
- `mykernel<<<1,1>>>()`: não consegui pegar no slide (é o slide da nvidia)

### soma de matrizes

**cuidados com a memória**
- ponteiros de dispositivos
	- apontas para memória de GPU
	- nao podem ser referenciados no código do *host*
	- pode-se passar o conteúdo dele (por meio de chamada de funções)

- ponteiros de host
	- apontam para memória de CPU
	- nao podem ser referenciados no código do *device*
	- pode-se passar o conteúdo dele (por meio de chamada de funções)


```c
// add() roda na GPU, então estes ponteiros precisam ser de la
__global__ void add (int *A, int *B, int *C) {
	*C = *A + *B;
}

int main (void) {
	int a, b, c;
	int *d_a, *d_b, *d_c;
	
	cudaMalloc((void **) &d_a, size);
	cudaMalloc((void **) &d_b, size);
	cudaMalloc((void **) &d_c, size);
	
	a = 2;
	b = 7;
	
	cudaMemcpy(d_a, &a, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, &b, size, cudaMemcpyHostToDevice);
	
	add<<<1,1>>>(d_a, d_b, d_c);
	
	cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);
	
	cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);
	return 0; 
}
```

mesmo assim, ta uma merda, não ta executando em paralelo

### a porra da paralelização surge (e urge)

`add<<<1,1>>>` -> `add<<<N,1>>>`

cada chamada de add() é referenciada como um *block*, um conjunto de *blocks* é um *set*, cada chamada pode ser referenciada pelo índice do bloco usando *blockIdx.x*

```c
__global__ void add(int *a, int *b, int *c) {
	c[blockIdx.x] = a[blockIdx.x] + b[blockIdx.x]
}

int main (void) {
	int a, b, c;
	int *d_a, *d_b, *d_c;
	int size = N * sizeof(int);
	
	cudaMalloc((void **) &d_a, size);
	cudaMalloc((void **) &d_b, size);
	cudaMalloc((void **) &d_c, size);
	
	a = (int *) malloc(size); random_ints(a, N);
	b = (int *) malloc(size); random_ints(b, N);
	c = (int *) malloc(size); 
	
	cudaMemcpy(d_a, &a, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, &b, size, cudaMemcpyHostToDevice);
	
	add<<<N,1>>>(d_a, d_b, d_c);
	
	cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);
	
	free(a); free(b); free(c);
	cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);
	return 0; 
}
```
