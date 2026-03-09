---
title: "Árvore R"
weight: 3
---

Tipos de dados espaciais:
- ponto: unidade minima de um objeto espacial.
- linha: sequencia de pontos
...

## MBR - (Minimum Bounding Rectangle)
retangulo delimitador minimo.

# R TREE
Objetivo: guardar dados utilizados com frequencia em muitas areas.
Utilizada para indexacao espacial, ou seja, para armazaenar dados que existem em multiplas dimensions como coords.

## Aplicacoes 
- GIS
- CAD 
- VLSI 
- P2P
- data streams..

## props
- bottom up
- balanceada 

Uma arvore R de order $(m, M)$ e uma estrutura que contem:
- m -> minimo eh o numero minimo de entradas por numero
- M -> maximo 

sendo m < $\frac{M}{2}$

consequentemente, uma arvire R nao precisa estar pelo menos meio cheia.

Altura maxima -> $h_{max} = \lceil \log_m n \rceil -1$

## estrutura
Uma folha em uma arvore R contem entradas na forma:
- (rect, id) ->
    - rect = coordenadas n-dimensionais que delimitam o objeto representado por id.
    - id = ponteiro pro arquivo de dados.

Exemplo:
Vector2D = [(0,0)(1,0)]

Um *no nao folha* tem forma:
- (rect, prt) onde:
    - prt: referencia ao no do nivel imediatamente inferior (filho);
    - rect: menor retangulo que abrande todos os retangulos encontrados em prt;

### colisao:
> detectar se um esta contido no outro (ou ha interseccao):

- se $A_{x_1} \geq B_{x_1} & A_{y_i} \geq B_{y_1}$
- se $A_{x_1} \geq B_{x_2} & A_{y_i} \geq B_{y_2}$

---

## Consulta (busca):
_formas:_
- Point query
- Window query
- Region query

- Topologicos todos os objetos que interceptam um dado objeto.
- Retorno de todas as regioes que interceptam um Vector2D dado.
- Retorno de todas os Vector2D's dentro de um outro Vector2D.

## Insercao:
- Percorrer a arvore a partir da raiz ate o no folha F mais apropriado.
- A cada nivel, escolher a entrada cujo Rect necessita do menor aumento de area. Resolver empates selecionando a folha com menor numero de entradas.
- Se o no folha F contem espaco suficiente, inserir a nova entrada em F e parar o processo de insercao. Caso contrario, dividir a folha F em F1 e F2.
    - Ajustar novas folha em caso de exceder o tamanho da folha.

## Split
