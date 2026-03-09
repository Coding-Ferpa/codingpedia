---
title: "Hashing"
weight: 3
---

#hash #keys #index
# Tabela hash
- é uma estrutura de dados que permite acesso rápido e eficiente com base em uma chave.
- é composta por um array de "baldes" onde os dados são armazenados
- a ideia e usar uma **função de hash** que transforma a chave no indice do array.

## Função hashing/espalhamento
- $h(k)$ transforma uma chave **k** em um endereço associado.
- similiar a indexação.

### Hashing interno
hashing em memória principal, cada slot da hash representa um registro

### Hashing externo
Hashing em memória secundária. Cada slot de tabela de hash é um bucket (um bloco ou cluster do disco)
- As colisões preenchem o bucket, apenas. 
- Tablea de hash fica no cabeçalho no arquivo.

#### Exemplo:
pegar os 2 primeiros bytes de uma chave, pegar sua representação em ascci, multiplicá-los e salvar apenas o valor da mantissa com os 3 números mais significativos dela.
- $k$ = *BA*LL -> B = 66, A = 65, a.b = 4290 -> $h(k)$ = 290.  

- colisões:
	- linked list ->(endereçamento fechado = hashing aberto): quando uma colisão ocorre os elementos colididos são simplesmente adicionados à lista ligada no respectivo slot.
	- outro slot (endereçamento aberto = hashing fechado):  procura outro slot aberto. Pode ser:
		- sondagem linear;
		- sondagem quadrática; e
		- duplo hash.
### Hashing x index
- ambos tem uma chave de busca associada a um endereço.
- teoricamente aleatório no hashing, direto no index.
> $id(x)$ -> hashing uniforme

aleatório - todo endereço tem perfeitamente a mesma chance de ser escolhido
### Métodos possíveis
- Pegar o resto da divisão da chave pelo tamanho de espaço disponível;
- padrões específicos nas chaves;
	- i.e. 4 últimos dígitos do telefone 3442-2866-> 2866.
- segmentar a chave em diversos pedaços e depois fundir os pedaços;
- dividir por um número inteiro (e juntar com o primeiro, se quiser);
- Elevar a chave ao quadrado e pegar o meio;
- Transformar a base.
