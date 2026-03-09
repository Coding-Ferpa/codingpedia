---
title: "Organização de arquivos"
weight: 3
---

# Organização de Arquivos 

Stream → não precisa ser ligado a arquivos, necessariamente, são espécies de buffers

Arquivo → conjunto de bytes foda com extensão

# Organização em registros

registro (struct) → conjunto de campos agrupados

- tem como objetivo preservar significado e estados

## Métodos de organização

- pode-se declarar indicadores, seja de tamanho de bytes de um registro ou apenas um separador entre campos
- pode-se usar um indice externo
    - tem um indice da posição do início de cada campo em um arquivo/registro

- fread e fwrite → leem e escrevem uma struct completa em um arquivo.

  

Questões: Portabilidade, Legibilidade. Facilidade de manipulação, desempenho…

## Acesso a registros

- Arquivo organizados por registros
    - cada registro tem um ponteiro próprio e podemos associar também uma chave a um registro que permite a recuperação do ponteiro
- chaves
    - primária → chave unica de identificação
        - deve não ter um significa associada, ser, de preferência, imutável.
    - secundária → não identifica um registro, pode ser utilizada em paralelo vários registros.
- formas canonicas → independente do case, uma chave deve levar ao mesmo registro
- na pesquisa em RAM, usamos o _**número de comparações**_ efetuadas para definir o mair rápido
- no acesso a _discos_ o melhor a se fazer é comparar o _**número de acesso**_

## Acesso direto

bom para velocidade, mas paia para uso de memória, ou seja, toda operação altera um senão todos os índices separados

- pode-se usar o RRN (relative record number ou byte offset) fornece a posição do registro dentro de um arquivo

### RRN

é necessário trabalhar com registros de tamanho fixo se quiser usar o RRN.

serve apenas como um índice posicional, ou seja, logicamente um numero inteiro.

---

# Organização de arquivos (pt2)

modelos abstratos de dados permite uma visão dos dados diferente ai

## Header Record

é importante salvar algumas infos sobre o arquivo previamente

ou seja, um arquivo torna-se um objeto auto-descrito

→ vantagens

- programas que leiam e escrevam grandes numero de arquivos

→ desvantagem

- o programa que le e escreve arquivos tem que ser baludo

### Metadados

- dados que descreve dados primários
- ex: Formato FITS

## Desempenho

- compactação
- compressão
# Compressão de dados

### Técnicas de compressão

- Notação diferenciada
    - tenta escrever uma sequencia grande de bytes ou nomes, reduzindo em algum tipo de tabela de codificação
- Omissão de sequencias repetidas
    - usa um código indicador de repetição e omite o valor repetido
- Código de tamanho variável
    - código morse
    - código de huffman
- código de tamanho fixo
    - ex: ASCII
- compressão de dados “analógicos” costumam ser irreversíveis.
# Compactação

encontrar regiões sem dados e reaproveitá-las, visto que a exclusão de registros geram espaços vazios.

- exemplos
    - marcação especial (tipo um * ou um \0) para declará-los apagados.
        - para copiar pode-se evitar o registro apagado.
        - também pode-se identificar o espaço apagado como passível de ser alterado.
        - acesso direto é importante, da pra formar uma lista com a info de espaços disponíveis, salvando-se apenas a head dela.
    - em registros variáveis
        - salvar a posição exata em que foi liberado espaço

# Estratégias de alocação

- first-fit → onde couber primeiro
    - gera fragmentação interna
    - pra resolver isso ai, basta salvar o espaço que sobrou na lista de espaços disponíveis
- best-fit → escolhe o melhor espaço
    - gera fragmentação externa
- worst-fit → o maior espaço disponível
    - sempre inserir o maior espaço disponível na LD

# Keysorting