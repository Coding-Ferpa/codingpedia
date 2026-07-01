---
title: "aula 4"
weight: 4
---

# Rasterização: representação matricial
Gráficos são dados por primitivas geométricas, passando algo vetorial (continuo) para matricial (discreto).

Dispositivos gráficos: matrizes de pixels.

- algoritmos para segmentos de retas 
data uma reta qualquer com v1(x1, y2) e v2(x2, y2): 
1. Seleção de pixels imediatamente acima e abaixo (linhas densas)
2. Pixels obtidos pelo arredondamento dos valores de algum ponto do segmento (aproximação)
3. Pixels obtidos por um pixel por coluna mais próximos da intersecção (mais bonito). (0 - 45 graus)
4. mesmo critério para cada linha horizontal (paia) (45 - 90 graus)

Características possíveis:
- Linearidade: parecer uma reta
- Precisão: pontos devem terminar e começar nos vértices terminais.
- Densidade uniforme: pixels devem ser igualmente espacados.
- Intensidade independente da inclinacao: ou seja, se a inclinacao mudar, a reta deve parecer a mesma.
- Continuidade: Nao aprensetar interrupcao
- Rapidez.


# Aliasing
Um fenômeno muito comum em imagens digitais é o *aliasing*, isto é, quando a amostragem de uma dada função contínua é pobre, ao ser desenhada, têm-se resultados inconsistentes com o
esperado. No caso de cg, esse efeito é causado quando o DPI (dots per inch) é insuficiente para representar matricialmente a função contínua descrita, causando infidelidade à representação esperada.

Uma forma de mitigação do problema é a aplicação do Filtro gaussiano (normal), o qual atribui um peso pro pixel central e pesos menores aos vizinhos em uma matriz com quadrada de tamanho 3, e multiplica os vizinhos com esta, causando um efeito de borrar a imagem: 
![[Pasted image 20250831080839.png]]

# Preenchimento de polígono
checando vizinhos ou até a fronteira, dado uma semente (posição inicial)

para pintar pixel usa o ray casting (se esta ou não no polígono).

Problema do vertice: vertices sao compartilhados entre arestas, logo o flip estara errado.
Se o vértice eh minimo para uma aresta e maximo para outra, inverta a paridade.
Se for minimo pras 2  arestas presentes, nao flipa, so pinta o pixel do vertice.
Se for maximo pras 2  arestas presentes, nao flipa e nem pinta.

Causa `sliver`, dentro do mesmo pixel há outra aresta.

# Exercicios:
programa usando opengl para que o usuario informe
num de vertices para construir um poligono convexo, uma coord para cada vertice e sua cor de preenchimento.
