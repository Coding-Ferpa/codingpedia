---
title: "Árvore Trie"
weight: 3
---

๏ Tempo de busca proporcional ao tamanho das chaves
๏ Chaves com sufixos comuns compartilham caminho até a raiz
๏ Propícias para compactação no caso de letras do alfabeto
๏ boa opção para manter chaves grandes e de tamanho variável

---

Árvores de busca digitais (tries)
- posição de um nó depende da comparação entre os bits da chave.
- vantagem:
	- impl mais simples pois não tem rotação
- desvantagem: 
	- se o conjunto é grande demais, precisamos de muitos bits para representá-la

> uma arvore de busca de na qual o fator de sub-divisão, ou número máximo de filhos por nó, é igual ao número de símbolos do alfabeto 

- tries são utilizados para acesso rápido aos buckets do hashing
- tempo de busca = tamanho das chaves
- ex: arvore com 26 subdivisões, por exemplo, sendo o numero de letras do alfabeto. Neste caso, só poderíamos inserir palavras que comecem com ASCII. As inserções, buscas e remoções se baseiam nos valores da chave inserida. A comparação é feita bit a bit da chave.

``` c
struct trie_node {
    char key; 
    trie_node* child[2];
    trie_node* father;
};
```

## Algoritmo de busca
Toda chave de uma árvore trie está em algum ponto do caminho dos bits

``` c
bool search(node *T, node *x) {
	u = T.pai;
	for (i=0; i < w - 1; i++){
			c = (x.key >> (w - 1) - i) & 1; // compara o bit >> posição com 1 	
		if (x.filho2 == NULL)
			return false;
		if (x.filho1 != x.key) {
			x = x.child[c];
			continue;
		}
		return true;
	}
	return false;
}
```

## Inserção
o nó deve ser inserido na primeira posição livre do caminho, na primeira folha onde c vale
``` c
bool insert(trie_node T, trie_node x) {
	trie_node *u = T.pai;
	for (i=0; i < w - 1; i++){
			c = (x.key >> (w - 1) - i) & 1; // compara o bit >> posição com 1 	
		if (x.filho2 == NULL)
			break;
		if (x.filho1 == x.key) {
			return false;
		}
		u = x.child[c];
	}
	u.child[c] = x
	x.p = u;
	return true;
}
```
## Remoção
- quando removido em uma folha -> show de bola.
- se é removido com 1+ filhos.
	- devemos trocar o nó em questão por uma folha.
	- menor a esquerda ou maior a direita.
![[Drawing 2024-08-20 11.29.11.excalidraw]]

