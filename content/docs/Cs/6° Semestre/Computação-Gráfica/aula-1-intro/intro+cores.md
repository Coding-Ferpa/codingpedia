---
title: "intro+cores"
weight: 4
---

# Ementa 

- Dispositivos e sistemas graficos (matriciais e vetoriais)
- Transformacoes geometricas no plano e no espaço
- Rasterização de primitivas gráficas
- Coordenadas homogêneas
- Composições de transformações 
- Técnicas para preenchimento de polígonos 
- Técnicas de recorte
- Projeções paralelas e cônicas
- Aplicações

# Definição - "Matemática e arte"

Segundo a ISO/IEC de 1998 é um conjunto de ferramentas e técnicas com normas e procedimentos usados para converter dados de ou para um dispositivo gráfico.

# Historia (Linha do tempo)
O primeiro computador a possuir recursos gráficos foir o Whirlwind I (1950), desenvolvido pelo MIT. Seguido por um sistema de monitoramente e controle de voos voltado para a defesa dos EUA.  No entanto, eles usavam a tecnologia de CRT (Cathode Ray Tube - TV de tubo), que foi descoberta em 1886. Em 1929, no entanto, a industria cinematográfica começara a se estruturar, com o padrão dos 24 FPS para filmes.

A seguir, uma linha do tempo com a evolução da CG:

1927: Primeiro Computador (Eniac)

1929: Fotograma - industria cinematográfica define o padrão de 24 FPS.

1938: Proposta do CRT Colorido

1950: Laposky -> Primeiras obras de arte digital, usando um efeito de osciloscopio.

1955: surge o Sage de monitoramento aereo.

1959: surge o termo computacao grafica, criado por William Fetter da boeing.

1960: primerio computador comercial.

1961: space wars -> primeiro jogo usando comp. grafica.

1963: usando uma caneta grafica para desenhar.

1963: primiero filme do zajac.

1964: Boeing cria o primeiro modelo o corpo humano

1966: primero console -> odyssey | primeira empresa que cria animacoes -> MAGI

1970: tecnicas de CG como sombreamento e z-buffer.

1971: tomografia computadorizada

1972: ATARI

1975: CG se torna uma área acadêmica

1992: lançamento do openGL

--- 

# Computação Gráfica
A computação gráfica é dividida em três vetores principais:
- Síntese de Imagens: objetos criados através do computador a partir de especificações geométricas e visuais de seus componentes.
- Processamento de Imagens: Visa melhorar ou alterar características visuais de imagens já existentes. 
- Analise de Imagens: Obter características de componentes de uma imagem (por exemplo, primitivas geométricas que a compoẽm).

Veremos alguns conceitos dispersos a seguir, importantes para o entendimento de cg.

## Sistemas Gráficos
Sistemas gráficos podem ser representados:
- matricial (dupla x, y -> como o paint): nesta representação, a imagem é descrita por um conjunto de células em um arranjo espacial bidimensional (O PLANO). Cada célula representa os ditos *pixels*, que nada mais são do que pontos lógicos de representação.
- vetoriais:  nesta forma de representação, usam-se primitivas matemáticas para modelar os problemas e elementos a serem dispostos. Tais elementos são chamados de *primitivas vetoriais* e possuem seu conjunto de atributos e geometria.
    - utiliza-se de voxels (pixel com volume) para representação nos octantes.
    - Dispositivos 3d: impressora
    - Podemos modelar uma reta nesta representação da seguinte forma: $(x, y, z) = (P_2 - P_1)+t +P_1, \ 0 \leq t \leq 1$,  onde cada elementos de ponto corresponde as coordenadas no espaço de 0 a X, Y e Z delimitados.

## Dispositivos Graficos
### CRT (Cathode Ray Tube)

Medida em pixel é uma unidade lógica e não física.
tamanho físico depende do dispostivo de projeção, depende da unidade minima de projeção. 

Esse valor em si é medido por `dot pitch` -> distancia entre 2 pontos de projeção é no máximo 0.28mm.

## LCD (liquid crystal display)

Formado por 2 laminas transparentes polarizadas, uma horizontal e uma vertical. 

## Plasma 

Elotros emitem estimulos que passam os gases xeonio e neonio e alteram o estado deles entre gas -> plasma.

A liberacao da luz faz o fosforo brilhar.

