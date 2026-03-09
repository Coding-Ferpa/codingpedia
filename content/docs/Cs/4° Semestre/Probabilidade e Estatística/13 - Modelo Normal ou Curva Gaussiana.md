---
title: "Modelo Normal ou Curva Gaussiana"
weight: 3
---

$$f(x) = \frac{1}{\sigma\sqrt{2\pi}}e^{\frac{-1}{2}(\frac{x-\micro}{\sigma})^{2}};x\in R$$ 
média =  $\micro$
desvio padrão = $\sigma$
Função unimodal em com forma de sino.

## props
- muitos fenômenos são associados a este modelo.
- pode ser usado para aproximar modelo de variáveis aleatórias como binomial, Poisson...
- Proporciona um embasamento para a inferência clássica que possibilita estimar parâmetros e testar hipóteses.


- A área sosb $f(x)$ compreendida entre $\micro - \sigma$ e $\micro + \sigma$ é de 68.27%
- A área sosb $f(x)$ compreendida entre $\micro - 2\sigma$ e $\micro + 2\sigma$ é de 95.45%
- A área sosb $f(x)$ compreendida entre $\micro - 3\sigma$ e $\micro + 3\sigma$ é de 99.73%

---
É preciso fazer a padronização ou normalização dos valores de X, com média $\micro = 0$ e desvio padrão $\sigma = 1$
$$Z = \frac{X-\micro}{\sigma}$$
a ideia é definir cada intervalo antes baseado em $\micro$ agora pode ser contada em números inteiros.

# Exemplo 
$\micro = 5, \ \sigma = 1$
$P(X<3)$ = $\int^{3}_{-\infty}f(x)dx$??
-> $Z = \frac{X-\micro}{\sigma} = \frac{3 - 5}{1} = -2 = (na \ tabela = 0.0228)$  
