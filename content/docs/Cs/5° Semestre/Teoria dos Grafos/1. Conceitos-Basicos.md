# 1. Definicoes
Um grafo G eh constituído por um conjunto V não vazia de vértices (ou nos), e uma família A de pares nao ordenados dos elementos de V, chamados de arestas. Denotamos um grafo por G(V, A) ou G.

ex: a) V = ${v_1, v_2, v_3, v_4, v_5}$ e $A = {(v_{1}v_{2}), (v_{1}v_{2})}$.

Podem ser representados por pontos e linhas (pares ordenados) entre eles.

--- 
# 2. Conceitos Iniciais

Propriedades em G(V, A), a = $(v_{i}, v_{j})$.
- a) $v_i$ e $v_j$ são extremos de $a$.
- b) a aresta $a$ eh dita incidente em $v_i$ e $v_j$
- c) $v_{i}$ e $v_{j}$ são chamados de adjacentes.
- d) se $v_{i}= v_{j}$ , temos a como um laco
- e) se ha uma aresta $f = (v_{k}, v_{l})$ tal que $v_{k} = v_{i}$ e $v_{l} = v_{j}$, $a$ e $f$ são ditas _paralelas_.

- Um grafo é __simples__ se não possui loops e/ou arestas paralelas.
- *Duas arestas são adjacentes* se elas incidem no mesmo vértice.
- O grau de um vértice v, d(v), em um grafo sem loops é determinado pelo número de arestas incidentes em v. Caso haja loops, estas arestas contribuem com grau 2.

- a) Um vértice v é isolado se d(v) = 0.
- b) Um vértice v é pendente se d(v) = 1.
- c) Um grafo G(V, A) é dito nulo se o conjunto de arestas é vazio.
- d) Um grafo G(V, A) é dito regular se todos os seus vértices tem o mesmo grau.
- e) Um grafo G(V, A) é dito completo se existe uma aresta entre cada par vértices. É representado por Kn, onde n é o número de vértices do grafo.
- f) Um grafo G(V, A) é dito valorado (ou rede) se são atribuídos valores para os vértices e/ou arestas. 

### Prop.
> Todo grafo tem essa igualdade. A soma dos graus de todos os vértices = $2 \times num \ de \ arestas$
>   $\sum\limits^{n}_{i=1} d(v_i) = 2m$

O número de vértices de grau ímpar em um grafo é sempre par.

---
# 3. Isomorfismo


