---
title: "B+ Tree"
weight: 3
---

**Objetivo:** permitir busca sequencial e direta.

Pensada em ranges. Utilizada em muitos sistemas de arquivos.
- Conjunto de indices, organizado igualmente como a _B_TREE_
- Sequence Set: lista encadeada que liga as folhas da b-tree (blocos de tamanho fixo ordenados pelas chaves). 

### props
1. Os nós internos não contém dados secundários dos registros, apenas cópias das chaves e servem só como referência para o percurso. Em outras palavras, abrigam apenas separadores de chave.
2. são utilizados blocos para armazenar os dados de fato, assim, o tamanho do bloco se difere da ordem da árvore.

podemos fazer a maior parte das exclusões e inclusões sem alterar os índices, apenas no conjunto sequencial.

# Operações
Busca por range: 
- encontra o primeiro bound do range seguida por uma busca linear até o limite $[4, 7]$.
- só se pode ter certeza que um registro foi encontrado quando se chega na folha.
- se chave_atual > chave_buscada, descemos pelo ponteiro da esquerda
- se chave_atual <=  buscada, descemos no ponteiro à direita.

![[Pasted image 20241015104611.png]]

## Inserção:
- no overflow do índice interno = igual a b-tree normal
- no overflow do bloco, subimos só uma cópia da chave mediana do novo nó pai.
```c 
struct node {
    bool isLeaf; // Verifica se o nó/página é folha
    int RNN; // RNN do próprio nó no arquivo de indice (arvore B+)
    int keys[order]; // vetor com valores das chaves (order-1)==bucketSize*
    int dataRRN[order]; // RRNs de dados associados a cada chave (somente em folha)
    int filhos[order+1]; // Ponteiros** (RNNs dos nós no arquivo) para os filhos
    int numKeys; // número de chaves inseridas na página
    int parent; // referência para o pai
    int next_node; // referência para o próximo nó/página da lista (se o nó é folha)
    int n; // quantas chaves tem
};

```
``` c
// Função para inserir no nó folha
// leaf: nó folha; key: chave a ser inserida; RNN_data: RNN da chave no arq. dados
void insert_at_leaf(leaf, key, RNN_data) {
    if (leaf) a folha nao esta vazia
    // Loop para encontrar a posição de inserção correta da chave
    node *temp1 = leaf->keys
    for (int i=0; i < temp1->n -1{
        // Inserção, quando o valor já existe no nó
        if (key == temp1->keys[i])
            //chave ja existe
            break;
            // Inserção, quando o valor é menor que os valores existentes
        else if (key < temp1->keys[i])
            //insere key na posição i e dá um shift nas demais chaves
            break;
            // Inserção, quando o valor é maior que todos os valores presentes
        else if (i + 1 == temp1->n) {
            //insere key depois da posição i
            break;
        }
        else {
            // Se o nó estiver vazio, adicione o valor e a chave diretamente na primeira posição:w
        }
    }
}

// Função de inserção principal
//key: chave inserida; RNN_data: RNN da chave no arq. dados
void insert(key key, data RNN_data) {
    node *old_node = search(key);// Encontre o nó folha adequado para inserção
    insert_at_leaf(old_node, key, RNN_data); // Insere a chave e RNN_data no nó folha
    // Se o nó folha estiver cheio após a inserção, é necessário dividi-lo (split)
    if (old_node->numKeys == order) {
        node *node1 = alloc_node();// cria um novo nó
        node1->isLeaf = true; //seta como folha
        node1->parent = old_node->parent; //seta o nó pai
        int mid = (int)ceil(old_node->numKeys / 2) - 1 // Determinando a posição média
        for (int i = mid + 1; i < old_node->numKeys; i++) {
            node1->keys = ;//recebe as chaves de mid+1 ate old_node->numKeys
            node1->dataRRN = ;//recebe os RNNs de mid+1 ate old_node->numKeys
        }
    }

    // Novo nó aponta para quem old_node apontava na lista
    node1->nextKey = old_node->nextKey
    for (int i = 0; i < mid; i++) {
        old_node->keys[i] = node->keys[i];//recebe as chaves de 0 a mid
        old_node->dataRRN[i] = node->dataRRN[i];//recebe os RNNs de 0 a mid
    }
    old_node->nextKey = node1->RNN; // Agora aponta para o RNN do novo nó na lista
    // Insira o valor médio no nó pai (que é interno)
    insert_in_parent(old_node, node1->keys[0], node1);
}
// Função para encontrar o nó folha adequado para inserção de uma chave
node search(node *root, key key) { //root: raiz; key: chave a ser buscada
    // Inicializa o nó atual como a raiz da árvore
    node *current_node = root;
    // Continua o loop até que o nó folha seja encontrado
    while(!current_node->isLeaf) {
        key temp2 = current_node->keys; // Armazena as chaves do nó atual em temp2
        for (i =0 ; i < temp2->n-1; i++) { // Percorre todas as chaves do nó atual
            if (key == temp2->keys[i]){ // Se a chave é igual à chave atual no nó
                // Muda para o filho à direita da chave e sai do loop
                current_node = current_node->filhos[i + 1]
                break
            }
                if (key < temp2->keys[i]) {
                    // Se a chave é menor que a chave atual no nó
                    // Muda para o filho à esquerda da chave e sai do loop
                    current_node = current_node->filhos[i];
                    break;
                } 
                // Se o loop chegou ao final e nenhuma das condições acima foi satisfeita
                if (i == current_node->n)) {
                    // Muda para o último filho do nó atual e sai do loop
                    current_node = current_node->filhos[i + 1];
                    break;
                }
            }
        }
        return current_node;
    }
}

// Função para lidar com a inserção em nós internos (não-folha) após uma divisão
// old_node: nó que foi dividido e vira filho esquerdo; key_promovida: chave promovida;
// new_node: nó criado devido a lotação de old_node e vira filho direito
void insert_in_parent(node *old_node,key key_promovida,node *new_node){
    // Verifica se o nó atual (old_node) é a raiz da árvore
    if (root == old_node->RNN) {
        node *rootNode = alloc_node(); // Cria um novo nó para se tornar a nova raiz
        rootNode->keys[0] = key_promovida; // A nova raiz terá a chave promovida como seu único valor
        // As chaves da nova raiz apontarão para o nó antigo (filho esquerdo) e o novo nó (direto)
        rootNode->filhos = [old_node->RNN, new_node->RNN];
        root = rootNode->RNN; // Define o novo nó como a raiz da árvore

        // Define o nó pai do nó antigo e do novo nó como a nova raiz
        old_node->parent = rootNode->RNN;
        new_node->parent = rootNode->RNN;
        return; // Como tratamos a raiz, não precisamos fazer mais nada nesta chamada
    }

    // Se chegamos aqui, significa que o nó não é a raiz-> Então, pegamos o nó pai do nó atual
    node *parentNode = old_node->parent;
    // Armazenamos os filhos do nó pai em temp3 para facilitar a manipulação
    int *temp3 = parentNode->filhos;

    // Percorre cada filho no nó pai. Continua no proximo slide
    for(i=1; i< temp3->n; i++) { // Percorre cada filho no nó pai
        if (temp3[i] == old_node->RNN) //Encontra a posição do nó antigo entre as chaves do nó pai
            // Insere a chave promovida na posição correta dos valores do nó pai
            parentNode->values = parentNode->keys[ate i] + [key_promovida] + parentNode->keys[i+1 ate fim]
            // Insere o RNN do novo nó na posição correta nos filhos do nó pai
        parentNode->filhos = parentNode->filhos[ate i] + [new_node->RNN] + parentNode->filhos[i+1 ate fim]

        // Verifica se o nó pai excede a capacidade máxima após a inserção
        if (parentNode->numKeys == order) {
            node *parentdash = alloc_node(); // Se exceder, cria um novo nó interno
            parentdash->parent = parentNode->parent; // Define o pai do novo nó interno

            // Move os valores e chaves à direita da posição média (mid = int(ceil(order / 2)) - 1) para o novo nó interno
            parentdash->keys = parentNode->keys[mid + 1 ate fim];
            parentdash->filhos = parentNode->filhos[mid + 1 ate fim];
            // Pega o valor da posição média para ser promovido na próxima chamada
            key_promovida = parentNode->keys[mid];

            // Atualiza os valores e chaves do nó pai para refletir a divisão
            if (mid == 0)
                parentNode->keys = parentNode->keys[mid];
            else {
                parentNode->keys = parentNode->keys[0 ate mid];
                parentNode->filhos = parentNode->filhos[0 ate (mid + 1)];
            }
            // Atualiza os pont de pai dos nós filhos de parentNode e parentdash após a divisão
            for(filho in parentNode->filhos) // foreach q n existe
                filho->parent = parentNode->RNN;
            for(filho in parentdash->filhos) // foreach q n existe
                filho->parent = parentdash->RNN;

            insert_in_parent(parentNode, key_promovida, parentdash);// Recursivamente insere no avô;
        }
    } 
}


// Inicializando e testando
#define order 3

int main() {
    insert(6, 33);  // 6 = chave, 33 = rrn no arquivo de dados
    insert(15, 21); 
    insert(25, 31);
    insert(35, 41);
    insert(45, 10);
    return 0;
}
```

# Exclusão
- apenas no nó folha;
- chaves excluidas continuam nos nós intermediários;
- remoção pode provocar underflow em um bloco
-> concatenar os blocos com seu antecessor ou sucessor na sequência lógica.
-> redistribuir registros, movendo-os entre os blocos logicamente adjacentes.

quando há concatenação, isso pode propagar-se para os nós internos.


# Arvore B+ com prefixo simples
Utilizar chaves com o prefixo das strings chave
Utilizamos o conceito de separador do tipo prefixo simples. Exemplo, se "Folks" e "Folk" existirem o separador pode ser "Folks", que difere as 2 palavras.

São mantidos no index os prefixos simples, ao invés das chaves em si.

### Tabela de decisão
chave < separador -> vai pra esquerda
chave = separador -> vai pra direita
chave > separador -> vai pra  direita

```c
void find_sep(char *key1, char *key2, char *sep) {
	while((*sep++ = *key2++) == *key1++);
	*sep ='\0';
}
// key1 -> ultima chave do bloco Xi
// key2 -> primeira chave do bloco Xi+1
// lembrar do tamanho da string ser MAX+1
```

Efeito de **sequence set.** (não altera a chave separadora).
Quando há overflow, há redistribuição e precisa-se recalcular a chave separadora;