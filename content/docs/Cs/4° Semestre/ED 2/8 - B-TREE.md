---
title: "B-TREE"
weight: 3
---

## Árvore binária de busca
Da pra criar uma arvore de busca binária em um arquivo, com os **Records** recebendo um ponteiro a direita e a esquerda do próximo registro, assim como uma chave própria. 
(key, rrn-left, rrn-right). O que isso gera é um desbalanceamento.
![[Árvore Binária de Busca - files]]
## AVL
temos a garantia com O(log(n)). Problema:
- se as chaves estão no arquivos, há muitos acessos desnecessários.

# Árvore Binária Paginada (Paged Binary Tree)

Cada 'página' é armazenada em um bloco, podendo conter um numero grande de Records, ou seja, é uma árvore *blocada*.

## Página:
Conjunto de setores logicamente contíguos no disco. Uma pagina é um grupo de $n$ records. 

## Problema da construção top-down
Construir uma arvore paginada é relativamente simples se temos todo o conjunto de chaves antes de iniciar a construção. Sabemos que temos que começar com a chave do meio.
Porém, se for em sequência aleatória.

A solução é uma árvore B (B-TREE).

---
# B-TREE

## Propiedades 
- completamente balanceadas 
- Não são binárias.
- Conteúdo de uma página não é mantido em uma árvore.
- Construção bottom-up
	- folhas -> raiz
- chaves **erradas** não são mais alocadas no no raiz. 
- cada página (ou nó) é formada por uma sequencia ordenada de chaves e um conjunto de ponteiros para outras páginas (ou RRN's). 
- não existe uma árvore explicita dentro de uma página
- ordem = numero de chaves + 1
- Os nós folhas não possuem filhos.

Estrutura de um nó 
Registro de tamanho fixo -> RRN

# Inserção 
- sempre realizada nos nós folhas (a busca binaria por uma chave inexistente termina sempre no no folha)
- ordem previamente definida
- **casos**
	- inserção em B-TREE vazia
		- criação e preenchimento em um nó (raiz)
		- demais chaves são inseridas até a capacidade do nó
		- tem que ser ordenadas na inserção
	- overflow no nó raiz
		- 1. particionamento do no (split)
			- nó original = nó original + novo nó
			- split 1-to-2
			- as chaves são distribuídas uniformemente nos 2 nós
			- chaves do nó original + nova chave
		- 2. criação de uma nova raiz (efeito bottom-up) 
			- raiz = pagina 2 -> left=pagina 0, right=pagina 1
		- 3. pegar a nova chave separadora
			- a primeira chave separadora (ou a chave final da primeira página, ou a primeira chave da segunda página).
			
![[B-TREE example]]

# Inserção em nós folhas
1. passo 1 ->pesquisa binária, inserção sempre nas folhas
	- até encontrar o nó folha certo
2. inserção em nó num lugar disponível
3.  inserção em nó cheio (overflow)
	1. fazer um split (criar um novo nó e inserir a metade dele no novo nó)
	2. promoção -> escolher a primeira chave do novo nó para ser a separadora no nó pai.
	3. ajuste do nó pai para apontar para o novo nó
![[B-TREE ex2]]

O arquivo que contém a árvore-B é um arquivo com registros de tamanho fixo, sendo que cada registro contém uma página da árvore.

```c
struct page {
	int keycount;          // contador
	char key[ORDER-1]      // chaves atuais
	int child[ORDER]       // RRNS dos filhos ou ponteiros
}

// page.child[i] = filho a esquerda
// page.child[i+1] = filho a direita
```
## representação lógica:
page 2

| 2   | D       H       K | 0      3      8       5 |
| --- | ----------------- | ----------------------- |

page 3

| 3   | E       F         G | NULL NULL NULL |
| --- | ------------------- | -------------- |
| 0   | B                   | NULL NULL NULL |

## detalhes impl
__	importante salvar no header o RRN da raiz.
__	se o filho é **null** escreva o ponteiro como um * 


---
# Algoritmos
# busca
```c
#define ROOT 2 // mudar para o header record

typedef struct page {
	int keycount;      // contador
	char key[MAX]      // chaves atuais
	int child[MAX + 1] // RRNS dos filhos
} page;

page search (RRN, KEY, FOUND_RRN, FOUND_POS) {
	if RRN == null 
		return NULL;
	page = load_page(RRN); 
	POS = search_key(page, KEY);
	if(POS == FOUND) { // se b está nessa pagina, POS = FOUND, se tiver na esquerda, ou n existir, POS = NOT_FOUND
		FOUND_RRN == RRN;
		FOUND_POS == POS;
		return page;
	}
	return search(page->child[POS], KEY, FOUND_RRN, FOUND_POS);
};

int search_key(page, KEY) {
	// tem que melhorar isso daqui
	for(int i = 0; i < PAGE_MAX; i++) {
		if(page.key[i] == KEY)
			return i;
	}
	return NULL; // mudar retorno
}

```
# Inserção
busca se a chave atual existe na árvore até chegar no nó folha em que ela deveria estar

## fases
- search step
- recurisve call
	- mover a operação ao niveis inferiores (ultima página possivel)
- inserção
	- split 
	- promotion 
- tipos de retorno
	- PROMOTION (1)-> quando uma inserção é feita e uma chave é promovida
	- NO PROMOTION (0)-> quando não há promoção (nó com espaço livre)
	- ERROR (-1) -> quando a chave em si já existe (retornar o indice da chave primária)
- variáveis locais
	- page: pagina atual
	- newpage: pagina nova criada
	- pos: posição da página na qual a chave já ocorre ou deveria ocorrer
	- P_B_KEY: chave promovida do nível inferior para ser inserida em page;
	- P_B_RRN:
		- RRN promovido do nivel inferior para ser inserido em page
		- filho a direita
```c
int insert (CURRENT_RRN, KEY, PROMO_KEY, PROMO_RIGHT_CHILD) {
	if CURRENT_RRN == null {
		PROMO_KEY = KEY;
		PROMO_R_CHILD=NULL;
		return PROMOTION;
	}
	page = load_page(CURRENT_RRN);
	POS = search_key(page, KEY);

	if(KEY = page.key[POS]) {
		log("ERROR: CHAVE JA EXISTE");
		return ERROR;
	}
	RETURN_VALUE =  insert(page.child[POS], KEY, P_B_RRN, P_B_KEY)
	if (RETURN_VALUE == NO PROMOTION || RETURN_VALUE == ERROR)
		return RETURN_VALUE;
	if (page_key_count(page) < KEY_MAX)
		// inserir P_B_KEY e P_B_RRN em page;
		return NO_PROMOTION;
	split(P_B_KEY, P_B_RRN, page, PROMO_KEY, PROMO_R_CHILD, NEWPAGE);
	// escrever page no RRN atual;
	// escrever new page no arquivo na posição PROMO_R_CHILD
	return PROMOTION;
}
```
## split
representa o tratamento de overflow causado por uma nova página
```c
void split(P_B_kEY, P_B_RRN, PAGE, PROMO_KEY, PROMO_R_CHILD, NEWPAGE) {
	// cria uma nova página (NEWPAGE)
	new_page();
	// distribui as chaves entre page e newpage
	int mid = (int)ORDER/2;
	// determina qual chave e qual RRN serão promovidos
	/*
		PROMO_KEY;
		PROMO_R_CHILD;
	*/ 
}
```
## procedimento driver 
rotina inicializadora e de tratamento da raiz
- abre ou cria o arquivo de índice (arvore-b)
- identifica ou cria a página da raiz
- lê chaves para serem armazenadas na b-tree e chama insert de forma apropriada
- cria uma nova raiz quando insert particiona a raiz atual
```c
void procedure() {
	if arquivo com árvore-b existe {
		abrir arquivo
	}
	else criar arquivo e colocar a primeira chave na raiz
	// recupere RRN da pagina raiz e armazene em root
	// leia uma chave e armazene em key
	while key existe {
		if(insert(ROOT, KEY, PROMO_R_CHILD, PROMO__KEY) == PROMOTION){
			crie uma nova raiz (com a promo key), l_child=root atual, r_child=promo_r_child
			faça root igual ao rrn da novaa pagina raiz
		}
		leia a proxima chave e armazene em key
	}
	escreva no arquivo a ultima raiz
	feche o arquivo
}
```
# Propriedades
- todas as folhas estão no mesmo nível
- toda página, exceto a raiz tem no minimo [m/2] descendentes
- uma página n folha que possui k filhos tem k-1 chaves

complexidade da árvore:
$N+1 \geq 2 x \lceil \frac{m}{2}\rceil^{d-1} \implies d \leq 1 + \log_{\lceil \frac{m}{2}\rceil}(\frac{N+1}{2})$

# remoção
eliminação 
caso 1: eliminar uma chave de uma página folha. 
- Solução, chave é retirada e os registros internos à página são reorganizados.

caso 2: uma chave fora da folha
- trocar com a sua sucessora imediata (menor da direita ou maior da direita) que está numa folha, deleta o que foi pra folha, e deixe o sucessor imediato na pagina de cima

caso 3: eliminação causa underflow e podemos redistribuir
- solução redistribuição
- procura-se uma página irmã que contenha mais chaves do que o minimo (se existir, redistribuiremos)
- juntamos as 2 páginas, escolhemos a chave mediana da junção e distribuimos metade pra cada, promovendo essa chave mediana e colocando a chave do pai trocada com a mediana

caso 4: ocorre underflow e a redistribuição não pode ser aplicada
- não existem chaves suficientes nos irmãos. 
- solução: concatenação
	- combina-se o conteudo das 2 páginas.
	- combinamos as 2 páginas, pegamos o maior deste nova e o promovemos

caso 5: underflow no pai, como consequencia da concatenação
- solução: underflow se propaga pra cima. Temos então, que concatenar recursivamente quando possível

caso 6: quando o underflow ocorre na raíz (raiz < 1 chave)
- concatenar os nós filhos
## passos
1. se a chave não estiver numa folha, troque-a com a sua sucessora imediata
2. elimine a chave da folha
3. se a página continuar com o número mínimo de chaves, fim.
4. se a página tem uma chave a menos q (m/2) -1, verificamos as páginas irmãs a esquerda e depois da direta
	1. se uma delas tiver mais q o numero minimo de chaves, redistribua
	2. se não, concatene com a página e a chave separadora do pai
5. se ocorreu concatenação aplique os passos de 3 a 6
6. se a ultima chave da raiz for removida, alterar a raiz e a altura diminui
![[B_TREE_REMOVAL]]