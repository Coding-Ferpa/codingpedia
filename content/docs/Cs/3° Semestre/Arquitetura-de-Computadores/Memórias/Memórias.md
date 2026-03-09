---
title: "Memórias"
weight: 4
---

# Definição

| CARACTERISTICAS             |                                 |                               |                               |                |
| --------------------------- | ------------------------------- | ----------------------------- | ----------------------------- | -------------- |
| Localização                 | Na CPU                          | Interna ao circuito integrado | Externa ao circuito integrado |                |
| Capacidade de armazenamento | Tamanho de uma palavra          | Numero de Palavras            |                               |                |
| Unidade de transferência    | Palavra (tamanho do barramento) | Bloco (muitas palavras)       |                               |                |
| Método de acesso            | Sequencial                      | Direto                        | Aleatório                     | Associativo    |
| Desempenho                  | Tempo de acesso                 | Tempo de ciclo                | Taxa de transferência         |                |
| Tipo físico                 | Semicondutor                    | Magnético                     | Óptico                        | Magneto-óptico |
| Detalhes físicos            | Volátil/não volátil             | Volátil/não volátil           |                               |                |

## Métodos de acesso

- Sequencial
    - Começa do inicio físico da memoria e vasculha ate achar (ou não) o que busca
- Direto
    - Dividido em blocos que possuem endereços exclusivos, porem o tempo de acesso do próximo bloco depende do endereço prévio.
- Aleatorio
    - O tempo de acesso de cada espaco de memoria independe de qualquer sequencia previa. A memoria principal e poucos caches funcionam assim
- Associativo
    
    - Esse recurso usa a capacidade de acessar todos os espacos da memoria (igual ao aleatorio) mas o faz simultaneamente, resultando em uma comparacao parcial da palavra procurada com as palavras na memoria. Isso implica em procurar pelo conteudo, nao pelo endereco da memoria.
    
## Desempenho

- Tempo de acesso: Tempo entre apresentar o endereco (ou requisicao) e o respectivo dados valido.
- Tempo de clock de memoria: Tempo de acesso + qualquer atraso entre o proximo acesso
- Taxa de transferencia: velocidade de transferencia

[[Cache]]
[[Memoria Interna]]