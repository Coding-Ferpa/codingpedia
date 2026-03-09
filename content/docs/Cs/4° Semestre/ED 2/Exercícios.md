---
title: "Exercícios"
weight: 3
---

![[lista1.pdf]]


# Solução
1 - Um arquivo lógico representa a forma como a linguagem de alto nível representa e enxerga os dados, não necessariamente representa como um arquivo físico está localizado no sistema. Ele é o IO buffer que utilizamos em memória principal. Ambos representam conjuntos de bytes, evidentemente, porém, um arquivo físico não tem distinção de suas qualidades internas, ou seja, não difere uma struct de um inteiro ou etc. 

2 - um seeking representa o movimento que a agulha de um disco tem que fazer para achar o cluster onde estão os dados de um arquivo em específico e representa um custo absurdo para o sistema computacional, visto que um movimento cinético é muito mais lento que um elétron em movimento.

3 - conjunto de trilhas verticalmente paralelas. são organizados assim para reduzir o numero de seekings, visto que em um cilindro podem ser feitas várias buscas paralelamente.

4 - são lentos, são mecânicos. Devemos minimizar os acessos aos discos, da forma que for possível. 

5 - Discos são divididos em:
 - superfícies
 - trilhas
 - cilindros 
 - setores;
os discos devem tentar ao máximo evitar fragmentação, mas a parte de armazenamento dentro deles cabe ao file system, vide ReFS, NTFS, ext4, ext3 ....

6 - São espaços de memória dedicados a transmissão de dados entre dispositivos de entrada e saida e o sistema computacional. A exemplo, podemos usar uma struct IO_BUF para identificar a representação lógica do arquivo. Podemos coletar os dados do arquivo inicialmente abrindo via `fopen` , depois lendo o conteudo via `fgets`, `fgetc` ou caso tenhamos que representar logicamente, podemos usar o fscanf. Para escrever temos o `fprintf` e o `fwrite`.

7 - Um cluster representa uma sequência lógica de arquivos, como o arquivo de index que podemos criar. Um extent é uma sequência de clusters consecutivos em um arquivo

8 - Fragmentação representa um espaço que está ou reservado e inutilizado ou não está reservado mas não pode ser reaproveitado. Existem 2 tipos de fragmentação, a interna e a externa. 
- Fragmentação interna -> Perda de espaço útil decorrente da organização em setores de tamanho fixo.
	- Ex: setor de 512 bytes, arquivos c/ registro de 300 bytes. 
- Fragmentação externa -> 

9 - Pode-se utilizar um bloco de tamanho definido pelo usuário. Este processo normalmente cria um overhead maior do que o overhead padrão (espaço ocupado para gerenciamento/controle de informações, não com os dados em si).

10 - podemos escrever sintaticamente no arquivo, podendo recuperar de forma logica o que tem no arquivo mesmo que não escrito pelo nosso programa. Ou seja, podemos fazer o fprintf ou simplesmente escreve em bytes e só permitir que nosso programa releia.

11- Podemos escrever campos de algumas maneiras diferentes, entre elas:
๏ Comprimento fixo
๏ Indicador de comprimento
๏ Delimitadores - podemos utilizar separadores como tags (; / ou qq outra coisa)
๏ Uso de tags (etiquetas)

12 -  é a fragmentação quando temos cada campo com tamanho fixo e limitado. A escrita do campo independe da porção lógica o qual o é inserido. Desta forma, se tivermos um campo ou registro de tamanho fixo, naturalmente a maior parte dos valores deles não serão sempre 100% preenchidos.

13 - As limitações são que o caractere utilizado para ser o delimitador deve estar fora do utilizado no campo. O delimitador pode ser uma /, mas / tem o tempo todo em campos. Portanto, podemos usar tags como $\times /$

14 - Depende do tamanho. Relative record number guarda o indice relativo de um registro 
> Byte offset = RRN * Tamanho do registro.

15 - É importante criar blocos com uma determinada quantidade de registros predefinidas, dessa forma, você diminuirá a quantidade de seekings para buscar um dado, ja que devido ao **principio da localidade**, mais dados podem estar próximos... Vale ressaltar que podemos utilizar chaves para identificar campos especificos, desta forma 

16 - (64 * 3) + 10 -> tamanho fixo do registro * RRN + tamanho do header record 

17 - Fixar o tamanho de um registro/campo permite o acesso rápido, devido a possibilidade de usarmos o RRN para acessar cada parte de um arquivo de dados. No entanto, isso acaba criando ainda mais fragmentação, visto que normalmente os dados não serão totalmente preenchidos.

18 - Relative Record Number, basta multiplicar 

19 - 
First Fit is fast and simple to implement, making it the most commonly used algorithm. However, it can suffer from external fragmentation, where small free partitions are left between allocated partitions.

Best Fit reduces external fragmentation by allocating processes to the smallest free partition, but it requires more time to search for the appropriate partition.

Worst Fit reduces external fragmentation by leaving the largest free partition, but it can lead to inefficient use of memory.

20 -  Sim, é vantajoso. A inserção pode ser feita de forma não criteriosa, podendo apenas ser ordenada no arquivo de index.

21 - você pode marcar para reuso com um bit especial e/ou criar um arquivo com uma Lista de Espaços Disponíveis (LD).

22 - a diferença é que a fragmentação interna ocorre dentro de um registro, ou seja, campos estáticos com espaço inutilizado. A externa acontece fora, entre os registros.

23 -   Para salvar informações uteis para o acesso das informações contidas nele. Tipo o LD ou sla

24 -  
Carla|Guimarães|Rua Riachuelo 123|Jardim America|033|720|.......... Djavan Carlos| Moura|Av D. Pedro I 1234|Vila independência|033|730|

25 -  

26 - a busca binária torna-se possível visto que nosso arquivo de índices agora possui uma ordenação, seja ela crescente ou decrescente, que representam os 2 limites (superior e inferior) para uma busca binária. Haja visto que o valor que o indice carrega pode estar relacionado seja à um valor unico (como o rrn) ou diversos como o campo Nome.

27 - a ideia do out-of-date é permitir a reconstrução do arquivo de índices baseado no arquivo de dados alterado. Ele pode ter sido modificado ou estar sendo modificado, portanto em um ambiente com multiprogramação, vários programas podem querer usar aquele arquivo e isso evitará desgaste. 

28 -

29 - Lista invertida -> mantém em 2 arquivos separados os índices secundários e primários. Porém, com enfase nos secundários, adiciona-se uma contagem de qnts índices primários estão associados a algum índice secundário. 


31 - a partir do índice primário?




![[lista2.pdf]]
1 - Uma árvore-B possui métodos que permitem sua reestruturação durante a runtime. Nesse caso, o método principal que é capaz de "construir de baixo pra cima" é o promotion. Ele é causado quando se há um split ocasionado pelo overflow de chaves ou quando á uma concatenação quando há o underflow de chaves dentro de uma ou mais páginas.

2 - A b-tree é mais eficiente que uma ABB quando olhamos para o trabalho em armazenamento secundário, visto que garante uma quantidade muito menor de acessos. Uma b-tree, em cerca de 1000 casos, precisa de aproximadamente 11. A depender da ordem da árvore-B, esse numero poderia ser reduzido, por exemplo, a 3 acessos.

3 - 
- o numero máximo de filhos ($m$) = 256 filhos
- o numero minimo de filhos ($\frac{m}{2}$) = 256/2  = 128
- numero minimo de descendentes da raíz -> 2
- numero minimo de descententes de uma folha -> 0
- nro de chaves: 199
- considerando o numero minimo de filhos como 128 -> $log_{127}(\frac{100000+1}{2})$ $\leq$ 3 
> $d \leq 1 + \log_{\lceil \frac{m}{2}\rceil}(\frac{N}{2}+1)$  

4- ?

5 -  um nó folha tem que ter no minimo $[\frac{m}{2}-1]$ filhos, caso contrário (somente em remoções), será concatenado.

6 - 
``` c
typedef struct Page page;
struct page {
    u8 RRN;
    struct page *children; 
    key *keys;            
};
```

7 - a menor chave armazenada em uma árvore B está, com certeza, na parte mais à esquerda de todas as páginas, ou seja, estará no indice = 0 do ultimo nó folha a esquerda da raiz.

8 -  [[]]