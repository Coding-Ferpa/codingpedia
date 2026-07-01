---
title: "aula 15 cuda basics pt2"
weight: 4
---

# CUDA Threads

Terminologia: um bloco pode ser separado em threads distintas. 

Cada thread tem seu próprio ID, que pode ser acessado através de variáveis pré-definidas:
- threadIdx.x
- threadIdx.y
- threadIdx.z

Podemos usar 1 bloco e M threads.

Exemplo:

```c
__global__ void add(int *a, int *b, int *c) {
    a[threadIdx.x] = b[threadIdx.x] + c[threadIdx.x];
}

add<<<1, N>>> (d_a, d_b, d_c);
```
Podemos combinar threads e blocos agora, usando N blocos e M threads. Essa estrutura eh chamada de *grid*.

Podemos calcular o indice de cada threads dos N blocos atraves de:

```c
__global__ void add(int *a, int *b, int *c) {
    int index = threadIdx.x + blockIdx.x * blockDim.x;
    c[index] = a[index] + b[index];
}

...
add<<<N/THREADS_PER_BLOCK, THREADS_PER_BLOCK>>> (d_a, d_b, d_c);
...
```

PROBLEMA: devemos limitar o acesso a threads de acordo com o tamanho do vetor dado, por exemplo.

```c
__global__ void add(int *a, int *b, int *c, int n) {
    int index = threadIdx.x + (blockIdx.x * blockDim.x);
    if (index < n)
        c[index] = a[index] + b[index];
}


add<<<(N + M - 1) / M, M>>> (d_a, d_b, d_c, N);
// temos que copiar N tambem pro device
```

Diferentemente dos blocos paralelos, threads tem mecanismos tem mecanismos para:
- se comunicar;
- se sincronizar;

Cada thread tem acesso a uma memoria compartilhada estando no mesmo bloco, que torna mais rapido do que precisar dar hit na DRAM do dispositivo toda vez que se precisa de algum dado. Usam a tag \_\_shared\_\_, alocada por bloco.

Podemos cachear dados na memoria compartilhada:
- Read(blockDim + 2 * radius): copia os elementos de entrada da memoria global para a memoria compartilhada.
- Computa blockDim.x elementos de saida
- Escreve blockDim.x elementos para a memoria principal.

```c
__global__ void stencil_id(int *in, int *out) {
    __shared__ int temp[BLOCK_SIZE + 2 * RADIUS];
    int gindex = threadIdx.x + blockIdx.x * blockDim.x;
    int lindex =  // TODO nao consegui copiar do slide

    .
    .
    .

    out[gindex] = result;
}
```

pode ocorrer RAW, WAR, WAW hazards desse jeito, ja que as threads vao ler antes da atualizacao ocorrer corretamente.

para evitar data races, podemos sincronizar as threads dentro de um bloco com a primitiva 
```c
void __syncthreads(); // barreira de sincronismo
```

---

# Dispositivos

Os lancamentos pro kernel da gpu são *async*, ou seja, o controle retorna diretamente pra cpu. CPU precisa sincronizar antes de consumir os resultados.

```c
cudaMemcpy() // bloqueia a CPU ate que a copia esteja completa
cudaMemcpyAsync() // nao bloqueia
cudaDeviceSyncronize() // bloqueia a CPU ate que todas as chamadas para a gpu tenham sido completas.
```

Aplicação pode escavar e selecionar GPUs:
```c
cudaGetDeviceCount(int *count);
cudaSetDevice(int device);
cudaGetDevice(int device);
cudaGetDeviceProperties(cudaDeviceProp *prop, int device);
```

Uma unica thread pode gerenciar diversos dispositivos:
```c
cudaSetDevice(int device);
```

