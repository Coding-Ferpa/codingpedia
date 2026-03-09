---
title: "Ciclo de instrução – O retorno"
weight: 3
---

# Indireção

- Endereçamento indireto requer mais acessos à memória;
- Pode ser imaginado como subciclo de instrução adicional.

![[/Untitled 7.png|Untitled 7.png]]

  

---

## Ciclo de dados

## Busca:

— PC → próxima instrução;

— Endereço da Instrução → MAR

— Endereço → barramento de endereço

— Unidade de controle solicita leitura de memória

— Resultado colocado no barramento de dados →MBR , depois para IR;

— Enquanto isso, PC incrementado em 1.

— IR é examinado;

— Se endereçamento indireto, ciclo indireto é realizado.

— bits do MBR transferidos para MAR.

— Unidade de controle solicita leitura de memória.

— Resultado movido para MBR.

  

### Execução

— Leitura/escrita da memória.

— Entrada/saída.

— Transferências de registradores.

— Operações da ULA.

  

### Interrupção

—Conteúdo do PC copiado para MBR;

—Local especial da memória (p.e., ponteiro de pilha) carregado no MAR;

—MBR gravado na memória;

—PC carregado com endereço da rotina de tratamento de interrupção;

—Próxima instrução (primeira do tratador de interrupção) pode ser obtida.

  

### Prefetch

- Busca acessando memória principal;
- Execução normalmente não acessa memória  
    principal;  
    
- Pode buscar próxima instrução durante execução  
    da instrução atua;  
    
- Chamada busca antecipada da instrução.