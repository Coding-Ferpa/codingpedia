---
title: "AL"
weight: 3
---

AB = BA = Id.

Esse método de escalonar a matriz ampliada do sistema para encontrar sua solução é conhecido como método de Gauss-Jordan.
  

### SISTEMA DE CRAMER

AX = B ⇔

A⁻¹(AX) = A⁻¹B ⇔

(A⁻¹A)X = A⁻¹B ⇔

X = A⁻¹B.

  

## Espaço vet

1. u + v = v + u (comutativa).
2. u + (v + w) = (u + v) + w (associativa).
3. Existe em V um elemento neutro, denotado por 0, tal que u + 0 = u.
4. Para todo elemento u ∈ V , existe o elemento oposto, denotado por −u tal que u + (−u) =  
    (−u) + u = 0.  
    (M) Em relação a multiplicação, para todo u, v ∈ V e α, β ∈ R, tem-se:  
    
5. α(βu) = (αβ)u.
6. (α + β)u = αu + βu.
7. α(u + v) = αu + αv.
8. 1 · u = u.

  

## SubEspaço vet de W

(a) 0 ∈ W (elemento neutro da soma est ́a em W);

(b) ∀u, v ∈ W, u + v ∈ W;

(c) ∀α ∈ R e ∀u ∈ W, tem αu ∈ W.

  

## Soma direta

1. W = U + V ;
2. U ∩ V = {0}.

  

# Combinação linear

O subespaço vetorial <S> é chamado de subespaço gerado por S. Assim, cada elemento de < S > é uma combinação linear de S.

Para subespa ̧cos gerados temos as seguintes propriedades:  
(a) S ⊆< S >.  
(b) Se S1 ⊆ S2 ⊆ V , ent ̃ao < S1 >⊆< S2 >.  
(c) << S >>=< S >.  
(d) Se S1 e S2 s ̃ao subconjuntos de V , ent ̃ao < S1 ∪ S2 >=< S1 > + < S2 >.  

  

# Base

Uma base de V ́e um subconjunto finito β ⊂ V no qual as seguintes condições se verificam.

1. β é linearmente independente;
2. V =<β>.

  

# Dimensão

Chamamos de dimens ̃ao de V e  
denotamos por dim(V ), o n ́umero de vetores de uma base qualquer de V . Se esse n ́umero de vetores  
for finito, dizemos que V ́e um espa ̧co vetorial de dimens ̃ao finita.  

  

## Teorema da Invariância

- Seja V um espaço vetorial finitamente gerado. Então duas bases quaisquer de V tem o mesmo número de vetores.

  

PROPS

1. Todo subespa ̧co vetorial de um espa ̧co vetorial finitamente gerado ́e tamb ́em finitamente gerado.
2. Se W ́e um subespa ̧co vetorial de V e dim(W) = dim(V ), ent ̃ao W = V .

  

## Dim da soma

dim(U ∩ V ) = dim(U) + dim(V ) - dim(U + V )

  

  

# Coordenadas

Uma base ordenada de um espaço vetorial V é uma base na qual fixamos quem é o primeiro vetor, quem é o segundo vetor, e assim por diante.

  

![[Untitled.png]]

  

# Mudança de base

![[Untitled 1.png]]

  

  

# TRANSFORMAÇÕES LINEARES

### Propiedades

$a) T(u1 + u2) = T(u1) + T(u2), ∀u1, u2 ∈ U;$

$b) T(λu) = λT(u), ∀u ∈ U e ∀λ ∈ R.$

$T(0) = T(u + (−u)) = T(u) + T(−u) = T(u) − T(u) = 0.$

ou seja, se T(0) ≠ 0 então T não é linear

  

# Núcleo e imagem

$Ker(T) = {u ∈ U : T(u) = 0}.$

## Teorema nucleo/imagem

$dim(U) = dim(Ker(T)) + dim(Im(T)).$

### Imagem

$Im(T) = {v ∈ V : ∃u ∈ U / T(u) = v}.$

### Injetora

$T \ é \ injetora ⇔ Ker(T) = {0}.$

### Sobrejetora

$T \ é \ sobrejetora ⇔ dim(U) = dim(V) : U,V ∈ L(U,V);$

  

### Isomorfismo

Se T é bijetora (sobrejetora e injetora)

  

### Obs:

$dim(U) > dim(V) \ -> não \ é \ injetora$

$dim(U) < dim(V) \ -> não \ é \ sobrejetora$

em espaços de mesma dimensão, ser injetora = ser sobrejetora

# Operações em transformações lineares

### Soma

$(F + G)(u) = F(u) + G(u).$

### Multiplicaçaõ por real

$(αF)(u) =αF(u).$

### Composição

$(G ◦ F)(u) = G(F(u)).$

## Matriz composta de ToF

$(T ◦ F)α,γ = (T)β,γ · (F)α,β.$

---

# Autovalores e autovetores

def: todos os vetores que são multiplos de v.

$T(v) = λv ∈ V,λ ∈ R.$

  

precisa satisfazer essa equação

$T(v) = λv ⇔ T(v) − λv = 0 ⇔ (T − λId)v = 0 ⇔ v ∈ Ker(T − λId).$

---

# Produto Interno

propriedades:

$(i) <u, u> \ \geq 0\newline (ii) <au, v> \ = a<u,v> \newline (iii) <u+v, w> = <u,w> + <v,w> \newline (iv) <u,v> = <v,u> \newline extra:\newline (0) <0, u> = 0$

# Norma

## Norma induzida do produto interno

$|| u|| = \sqrt{<u,u>}$

### Propriedades norma

$(i) \ ||a.u|| = a||u||, a \in \real,\forall u\in U \newline (ii)\ ||u|| \geq 0, ||u||=0 \iff u = 0\newline (iii) \ ||u+v|| = ||u||+||v||$

## Distância

$d(u,v) = ||u-v||$

## ângulo

$\cosθ = \frac{<u,v>}{||u||.||v||} \ \le \ |1|$

  

## Ortogonalidade

2 vetores são ortogonais se e somente se θ = 90°

$cosθ = 0 \iff <u,v> \ = 0 \implies u\perp v$
