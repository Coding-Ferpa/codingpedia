---
title: "aula 19 conectividade"
weight: 4
---

# Elementos de conectividade

Conectividade: Descreve como elementos de processamento (CPU e memória) de um sistema são interligados, podendo ser internamente ou com outros processadores/computadores em si.

Grau: O numero de conexoes que cada nó (entenda nó como uma abstração para a unidade de processamento referida) exige para seu funcionamento é o seu GRAU .

Diâmetro: O maior dos caminho minimo percorrido entre 2 elementos de processamento é chamado de DIÂMETRO da rede.

Largura de Bissecção: a quantidade de canais necessários para se conectar os elementos entre 2 metades da rede.

Função de Rotamento: como dados trafegam entre conexões intermediárias entre fonte e destino.


## Tipos de redes de conexão
Outra forma de classificar-se redes envolve sua flexibilidade, podendo existir redes (1) estáticas e (2) dinâmicas. 

(1) Nessas redes, as conexões entre os nós são fixas.
(2) AS conexões variam com o tempo e depende de uma rede de mapeamento.


## Conexões de Alta Velocidade

Para obter-se HPC é necessário que as transferências ocorram rapidamente. Isso implica em atender 2 aspectos: (1) baixa latência e (2) alto volume.

1) Podemos diminuir latência diminuindo etapas intermediárias, com o RDMA (Remote Direct Memory Access com bypass da CPU) ou diminuindo o diâmetro da rede.
2) Devemos ampliar os canais de transmissão

### RDMA
É um mecanismo adota em redes para facilitar o acesso a dados remotos. Ele evita cópias intermediárias (zero-copy networking) dos dados transferidos para o SO ou outros programas.

O problema dele, apesar de ser infinitamente mais veloz que o TCP, é a sua dependência acerca dos protocolos utilizados. Cada tecnologia como infiniband, (1) ethernet com RoCE e (2) internet com iWarp são obrigatórias.

1) RoCE (RDMA over Converged Ethernet): apresenta versões diferentes para diferentes camadas (de link e network).

2) iWARP: feito para redes TCP/IP, implementando um Kernel bypass e Direct Data Placement.

### Redução do Diamaetro da Rede
Pode ser obtida de duas formas:
- Aumentando o grau dos nós (1)
- Reduzindo a complexidade de roteamento (2)

1 e 2) Usar CLOS, que é uma arquitetura de rede de comutação multiestágios, escalável e de alta performance. Composta por camadas de switches, em 3 estágios:
- Estágio de entrada (leaf/folha): Conecta-se aos dispositivos finais com redes crossbars.
- Estágio de saída (leaf/folha): Conecta-se à rede externa ou a outros data centers.
- Estágio de agregação (spine/espinha): Conecta as duas camadas anteriores.

### Ethernet
Muito bom

### Infiniband
É uma arquitetura baseada em switched fabric, que é uma rede dinâmica de switches (como as redes convencionais que temos entre os AS's).
