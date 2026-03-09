---
title: "aula 5"
weight: 4
---

# Sistemas de coordenadas
Referencia em termos de medidas do tamnaho e posicao dos objetos.
- define a unidade de ref. basica.
- determina limites extremos para descrever o objeto 

SRM - Sistema de Referencia do Modelo: adotado pelo modelo, por exemplo, o cubo padrao, que precisa ser transpilado para o SRU.
SRU - Sistema de Referencia do Universo: adotado pelo usuario, por exemplo, o sistema cartesiano.
SRD - Sistema de Referencia do Dispositivo: adotado pelo dispositivo da saida, por exemplo, a tela do computador.

# Transformacao Janela - Window-to-Viewport
Transformacao que mapeia a janela de visualizacao (window) na area de exibicao (viewport).

As transformacoes e renderizações são distorcidas em caso de a janela e a viewport possuirem proporções diferentes.

# Algoritmos de Clipping
- retas 
## Algoritmo de Cohen-Sutherland (1967) 
-> é necessário ter $x_{min}$, $x_{max}$, $y_{min}$ e $y_{max}$ - limites da janela de visualização.
Plano é dividido em 9 regiões, cada uma com um código de 4 bits. 

Apenas o que vai ser desenhado está em 0000.

Teste de aceitação ou rejeição rápida: 
- 1° bit: semiplano acima da aresta superior $y_{max}$
- 2° bit: semiplano abaixo da aresta inferior $y_{min}
- 3° bit: semiplano à direita da aresta direita $x_{max}$
- 4° bit: semiplano à esquerda da aresta esquerda $x_{min}$

```c

if (codigo(p1) && codigo(p2) == 0) // Aceita
    desenhaReta(x1, y1, x2, y2);
else if (codigo(p1) == 0 && codigo(p2) == 0)
    return;
else {
    // Calcula interseccao - precisamos achar um C' e um D' que intercetem a janela
}

```

Podemos calcular os recortes definidios por os pontos C' e D' usando a equação da reta:
-  $y= \frac{(y_1 - y_0)}{(x_1 - x_0)}*(x_{min} - x_0) + y_0$
-  $x= \frac{(y_1 - y_0)}{(x_1 - x_0)}*(y_{min} - y0) + x_0$S

TODO estudar essas contas aqui

## Algoritmo de Sutherland-Hodgeman (1974)
Algoritmo de recorte de polígonos.

Transição Interior-Interior: Quando ambos os vértices estão contidos no semi-plano, o vértice final é adicionado à lista de saída.
Transição Interior-Exterior: Quando o vértice inicial está contido no semi-plano, mas o vértice final não está, o ponto de interseção do segmento com a aresta do semi-plano é adicionado à lista de saída.
Transição Exterior-Exterior: Quando ambos os vértices não estão contidos no semi-plano, nenhum ponto é adicionado à lista de saída.
Transição Exterior-Interior: Quando o vértice inicial não está contido no semi-plano, mas o vértice final está, o ponto de interseção do segmento com a aresta do semi-plano e o vértice final são adicionados à lista de saída.

## Algoritmo Weiler-Atherton (1977):

