---
title: "analisador-lexico"
weight: 3
---

- A entrada na "fita" do scanner (AFD) é feita por um programa anterior (leitor de arquivo) que usa de separadores da linguagem de programação (e.g $).
	- O scanner (analisador léxico) então verifica se o(s) token(s) enviado(s) é(são) válido(s).
- O analisar léxico analisa somente se os tokens são BEM FORMADOS.
# Exemplo de erros léxicos
- Uso de caracteres fora do alfabeto da linguagem;
- Erros de grafia.

# Token: padrões e lexemas
- Cada LP possui um conjunto de tokens que definem as sequências de caracteres válidos para a linguagem.
- Cada sequência de caractere em um programa fonte tem significado próprio na LP.
- Por exemplo, a sequência "if" pode significar um identificador ou o nome de uma estrutura de controle (dependendo da linguagem).
- Sequências diferentes podem estar associadas ao mesmo token. Ex: 10 e 234
- A sequência de caracteres que forma um token é chamada **lexema**
	- Ex: pi = 3,1416; 
	- pi é um lexema pra o token identificador.
- O padrão de um token é a regra de formação (ex: nome de variável em c).
	- Ex: token CONSTANTE_INTEIRA tem o padrão sequência de um ou mais dígitos

# Maneira de implementar um Analisador Léxico
1) Construir um simulador de um AF.
2) Implementar as transições de estado no código (chumbado).
3) Usar um gerador de analisador léxico.
