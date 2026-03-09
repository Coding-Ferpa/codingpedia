---
title: "Erros de arredondamento e truncamento"
weight: 3
---

# Truncamento
seja S$[10, t, M_{min}, M_{max}﻿]$ um sistema de aritmética de ponto flutuante de $t$ dígitos. Então todo número em $S$ é forma:

$\pm0. d_1.d_2 ...d_t.10^M$﻿

com $M\in [M_{min}, M_{max}]$﻿ inteiro $d_x1$﻿ ≠ 0

$x = f_x .10^q+g_x .10^{q-t}$﻿

$0.1 \leq |f_x| \lt 1 , 0.1 \leq |g_x| <1$﻿
  
Para calcular o erro na aproximação por truncamento, calculamos primeiro o erro absoluto:

$|EAx| = |f_x .10^q+g_x .10^{q-t}-f_x.10^q|$﻿

portanto,

==$|EAx| < 10^{q-t}$==﻿

No caso do erro relativo, temos:

$|ERx| = |\frac{EAx}{x}| = \frac{|EAx|}{|x|}$﻿

$|ERx| = \frac{|EAx|}{|f_x.10^q|} = \frac{10^{q-t}}{|f_x.10^q|}$﻿

$|ER_x| < {10^{1-t}}$
# Arredondamento
No arredondamento, temos:

$x = [\binom{f_x.10^q, se |g_x| <0.5}{f_x.10^q+10^{q-t}, se |g_x| \geq0.5}]$﻿

$|EAx| = |f_x *10^q+g_x *10^{q-t}-f_x*10^q|$﻿

$|EAx| < \frac12*10^{q-t}$﻿

percebe-se que o arredondamento tem a metade da estimativa quando comparado ao erro do truncamento

1° caso)

$|ERx| = |\frac{EAx}{x}| = \frac{|EAx|}{|x|}$﻿

$|ERx| < \frac{0.5*10^{q-t}}{|f_x*10^q|} = \frac{0.5*10^{-t}}{f_x} \lt 0.5*10^{1-t}$﻿


2° caso) $|g_x| \geq 0,5$﻿

Nesse caso, a aproximação = $f_x*10^q+10^{q-t}$﻿

$|EAx| = |f_x .10^q+g_x .10^{q-t}-(f_x.10^q +10^{q-t})|$﻿

$|EAx| = |g_x-1|*10^{q-t}$﻿

como $|g_x| \geq 0,5 =>|g_x-1|\geq 0.5$﻿

  
então, podemos dizer que o erro absoluto é:

==$|EAx| \leq 0.5* 10^{q-t}$==﻿


Olhando então, o erro relativo,

$|ERx| = \frac{|EAx|}{|x|}<\frac{0.5*10^{q-t}}{f_x*10^q+10^{q-t}}$﻿

portanto, o erro é estimado como:

==$|ERx| < 0.5*10^{1-t}$==﻿

---
## Operações com Aritméticos que pertencem a S$[10,t,M_{min}, M_{max}]$

Dados x e y quaisquer, para realizar operações em S$[10,t,M_{min}, M_{max}x]$, supondo que x e y pertençam a S, devemos:

- 1) Escrever x e y como elementos desse sistema
- 2) Efetuar a operação aritmética normalmente, (x+y, x-y, x.y ou x/y)
- 3) Reoperar os elementos para dentro do sistema, se necessário

_Exemplo_:

x = 3.7945 e

y = 75.7099,

calcular $x+y, x-y, x.y, x/y$, no sistema $S[10, 3, -10, 10]$﻿

Solução:

x = 0.379_945_ _$*10¹$_﻿

⇒ $x = 0.379*10¹$﻿
  

$0.757099*10¹$﻿⇒

y = $0.757*10²$﻿


⇒ $x + y = 0.379*10¹ +0.757*10^{2}$﻿

= $0.7949*10² = 0.794*10²$﻿


faça as outras ai…

---

## Estimando erros nas operações dentro do sistema

## Adição

### Erro Absoluto

Observe que :

$EA_x = x -x_a=>x=x_a+EA_x$﻿

da mesma forma, vale para y

$y = y_a +EA_y$﻿

Somando as duas relações, temos

$x+y= x_a+y_a + EA_x+EA_y$﻿

portanto, o erro absoluto na aproximação da soma x + y por $x_a+y_a$﻿ →

==$EA_{x+y} = EA _x +EA_y$==﻿

### Erro Relativo

No caso do erro relativo, temos:

$ER_x = \frac{EA_x}{x_a}$﻿

Logo,

$ER_{x+y} = \frac{EA_{x+y}}{x_a+y_a}$﻿

$\frac{EA_x}{x_a}*\frac{x_a}{x_a+y_a}+\frac{EA_y}{y_a}*\frac{y_a}{x_a+y_a}$﻿

  

==$ER_{x+y}= ER_x(\frac{x_a}{x_a+y_a})+ER_y(\frac{y_a}{x_a+y_a})$==﻿

---

## Subtração

  

---

## Multiplicação

### Erro Absoluto

Lembrando que

$x = x_a +EA_x$﻿

$y = y_a +EA_y$﻿

$x * y= x_a +EA_x*y = y_a +EA_y$﻿ ⇒

$x_a*y_a+xEA_x+y*EA_y+(EA_x)(EA_y)$﻿

podemos supor, portanto que

$(EA_{x})(EA_y)= 0$﻿ ⇒


$EA_{x-y}{=} \bar xEA_{\bar x}+\bar yEA_x$﻿

### Erro Relativo

[…]
