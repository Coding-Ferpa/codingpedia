---
title: "B-star and Virtual Trees"
weight: 3
---

# B* tree
Tentativa de redistribuir chaves durante a inserção antes de particionar o nó.
- Variação da árvore-b no qual cada no tem, no mínimo, 2/3 do número máximo de chaves.
A geração destas árvores utiliza uma variação do processo de particionamento -> adiado até 2 paǵinas irmãs estejam cheias (2 pra 3).

## propriedades
- cada páginas tem no máximo m descendentes
- toda página tem no mínimo $\frac{2m-1}{3}$ descendentes
- a raiz tem pelo menos 2 descendentes
- todas as folhas estão no mesmo nível
- uma fola contém no mínimo $\lfloor \frac{2m-1}{3}\rfloor$ chaves

com 2/3 de ocupação toda página irmã tem condições de redistribuir após um underflow em página vizinha

deve-se tratar a raiz diferentemente -> ou dividimos a raiz one-to-two ou permitir mais capacidade na raiz.

# Virtual B-Tree
O fato de uma árvore ter profundidade 3 não implica necessariamente fazer 3 acessos, se a página acessada estiver em RAM.
Podemos deixar parcialmente algumas páginas em RAM.
- primeiro, deixar sempre carregada a árvore B. (sempre diminuindo 1 acesso);
- podemos criar um RAM Buffer que é chamado de árvore-B virtual. 
- usaremos LRU (last recently used) para trocar a página
- o processo de acessar disco para trazer uma página que não está no buffer é chamado de **page fault**

Podemos optar por colocar todos os níveis mais altos da árvore em RAM.
Isso comporta a raiz e mais algumas poucas páginas que estão no segundo nível.


# Alocação da informação associada à chave
Pode ser guardado diretamente com a chave, temos um acesso a menos.
- reduz a ordem da árvore, mas diminui o máximo guardado em buffer.
Ou no arquivo de dados:
- da a posição em outro arquivo.

- podemos usar chaves de tamanho variável + listas invertidas associadas.

