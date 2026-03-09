---
title: "Paralelismo em nível de instrução"
weight: 3
---

# Visão geral

pipeline busca sobrepor operações da instrução de forma paralela, tornando cada parte do processador utilizável enquanto outra está em uso, montando assim um “dado duto”

![[/Untitled 9.png|Untitled 9.png]]

---

Os processadores usam uma pipeline pra sobrepor instruções. → ILP – Instruction Level Parallelism;

Existem 2 tipos de ILP, assistido por hardware e por software.

Em geral, tende-se a utilizar mais ILPs em pontos com loops, visto que a execução do próximo loop pode ser prevista de acordo com o atual, admitindo poucos erros.

## Dependência

de dados, de controle e de nome. Assim sendo, a ordem que os dados podem ser calculados precisa ser adequada, limitando o paralelismo a fim de evitar hazards
  

Dep. de nome/recurso → mesmo registrador ou local de memória sendo “usado ao mesmo tempo”

Dep. de controle → coerência em fluxos de controle (if antes do else, por exemplo)

Dep. de dados → mesmo dado sendo compartilhado

# Hazard

É absurdamente maléfico que uma pipeline pare, visto que a sua intenção de existência é permitir um fluxo contínuo de instruções, portanto deve-se evitar os hazards

## Tipos de hazards:

- Recursos.
    - também chamado de hazard estrutural, representa qnd 2 instruções precisam do mesmo recurso
    - o que significa que: Leitura ou escrita de operando não podem ser realizadas em  
        paralelo com busca de instrução;  
        
    - Uma solução: aumentar recursos disponíveis.  
        — Múltiplas portas da memória principal.  
        — Múltiplas ALUs.  
        
- Dados.
    
    - 2 operações acessam a mesma unidade de memória “ao mesmo tempo”, uma está executando operação lá e a outra precisa do mesmo pedaço de info.
    
    — TIPOS DE HAZARD DE DADOS —
    
    - RAW ( READ AFTER WRITE )
        - da um Hazard se a leitura ocorre antes do término da escrita.
    - WAR ( WRITE AFTER READ )
        - da um Hazard se escrita termina antes que ocorra a leitura.
    - WAW ( WRITE AFTER WRITE )
        - Hazard se a escrita ocorre na ordem contrária à sequência intencionada.
- Controle.
    - uma pipeline tende a escolher quais instruções devem ser priorizadas, colocando em conta, também, a previsão de desvio de cada uma delas. Por exemplo, se X vai usar endereço E e Y também, deve-se evitar que elas acessem o dado ao mesmo tempo
    - quando a pipeline não prevê corretamente, há um hazard
    - Lidando com desvios:
        - Múltiplos fluxos (mais de uma pipeline, gerando disputas no barramento e registradores)
        - Buffer de laço de repetição.
        - Previsão de desvio.

---
# Compilação na ILP

instruções dependentes entre si podem ser espalhadas entre os ciclos de clock, ou seja, inserções de latencia (ou delay slot), promovendo a _previsão de desvio_.

### Previsor de correlação

uma marcação de 2 bits na instrução, como forma de acrescer informações sobre a natureza do desvio, sendo

- Globais; ou
- Locais

---

# Escalonamento dinâmico

há os casos de hazards que não são identificados na compilação e precisam de tratamento especial. Torna-se necessário, portanto, utilizar-se de um equipamento de hardware para tolerar atrasos e hazards.

## Técnica de Tomasulo

Verifica quando os operandos para uma instrução estão disponíveis. Minimizando RAW;

## Especulação baseada em hardware

Previsão dinâmica de desvio para escolher qual instrução executar, execução na ordem pré-definida, esperando apenas a liberação dos operandos. Essa ordem não precisa ser exata, porém, são confirmadas em ordem pelo buffer de reordenação

## ILP com Múltiplo Despacho e Escalonamento Estático

técnicas que buscam o numero de ciclos por instrução próximos a 1. Um processador com múltiplo despacho permitem múltiplas instruções enviadas a partir de um mesmo clock.

- processadores superescalares escalados estática e dinamicamente

  

SUPERESCALAR → hazard on hardware, dynamic issue structure

VLIW/LIW → hazard detection on software (compile time)

EPIC → hazard on compiler

  

## Técnicas de Despacho e Especulação

atualmente, há cerca de 4 ou mais instruções por ciclo de clock, assim sendo, precisa-se de técnicas como renomeação de buffer, buffer de ordenação, eficiência de especulação e previsão de valor;

  

- há a técnica de armazenar qual o desvio antes mesmo de decodificar a instrução no BTB (Branch-Target Buffer).
- há também a técnica de prever endereços de retorno, colocando em uma pilha num cache essa info.
- existem também as unidades de prefetch especializadas para possíveis desvios, conectadas por meio de buffers ao pipeline.
- renomeação de registradores
- previsão de valor produzido por uma instrução