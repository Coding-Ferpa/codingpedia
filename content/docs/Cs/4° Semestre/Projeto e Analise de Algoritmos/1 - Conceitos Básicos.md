---
title: "Conceitos Básicos"
weight: 3
---

## 1.1 Algoritmos

Definição de algoritmo: informalmente, um algoritmo é qualquer procedimento  
computacional bem definido que toma algum valor ou conjunto de valores como entrada e  
produz algum valor ou conjunto de valores como saída. Portanto, um algoritmo é uma  
sequência de etapas computacionais que transformam a entrada na saída. Também  
podemos considerar um algoritmo como uma ferramenta para resolver um problema  
computacional bem definido. O enunciado do problema específica em termos gerais a  
relação desejada entre entrada e saída. O algoritmo descreve um procedimento  
computacional específico para se conseguir essa relação entre entrada e saída.  

## 1.2 O problema da ordenação

O problema da ordenação pode ser definido da seguinte forma:  
Entrada: uma sequência de n números < a1, a2, . . . , an >  
Saída: uma permutação (ou reordenação) < a1´, a2´, . . . , an´ > da sequência de entrada,  
tal que a1´ ≤ a2´ ≤. . . ≤ an´. (Ordem não-decrescente)  
Por exemplo, dada a sequência de entrada < 31, 41, 69, 26, 41, 58 >, um algoritmo de  
ordenação como saída a sequência < 26, 31, 41, 41, 58, 69 >. Tal sequência de entrada é  
denominada instância do problema de ordenação. Em geral, uma instância de um  
problema de ordenação consiste na entrada (que satisfaz quaisquer restrições impostas  
no enunciado do problema) necessária para calcular uma solução para o problema.  
Diz-se que um algoritmo é correto se, para toda instância de entrada , ele parar com a  
saída correta (esperada).  
Um algoritmo incorreto poderia não parar em algumas instâncias de entrada ou poderia  
parar com uma resposta incorreta. Ao contrário do que se podeira esperar, às vezes os  
algoritmos incorretos podem ser úteis se pudermos controlar sua taxa de erros.

## 1.3 Eficiência

Embora os computadores sejam cada vez mais rápidos e possuam cada vez mais  
memória, esses recursos são limitados. É necessário pensar em algoritmos que sejam  
eficientes em termos de tempo de execução e espaço de memória utilizado.  
Algoritmos diferentes criados para resolver o mesmo problema muitas vezes são muito  
diferentes em termos de eficiência. Essas diferenças podem ser muito mais significativas  
que as diferenças relativas a hardware e software.  
O problema da ordenação também é um bom exemplo do ponto de vista de eficiência:  
Realmente faz diferença usar o quicksort ao invés do bubblesort para qualquer sequência  
numérica? O tamanho da entrada é importante nessa comparação?  
A análise de algoritmos nos fornecem ferramentas para que se possa fazer essa  
comparação de forma satisfatória. Buscamos algoritmos que sejam corretos e eficientes  
ao mesmo tempo em que sejam fáceis de implementar. Essas metas podem não ser  
simultaneamente atingíveis. Em ambientes industriais qualquer programa que pareça dar  
respostas boas o suficiente sem tornar o aplicativo mais lento é frequentemente aceitável,  
independentemente de existir um algoritmo melhor.  
Considere o seguinte exemplo envolvendo dois algoritmos de ordenação: O primeiro,  
conhecido por ordenação por inserção (insertion sort), leva um tempo aproximadamente  
igual a c1n2 para ordenar n itens, em que c1 é uma constante que não depende de n. Isto  
é, ele demora um tempo aproximadamente proporcional a n2.  
O segundo, a ordenação por intercalação (merge sort) leva um tempo aproximadamente  
igual a c2 log n em que c2 é uma constante que também não depende de n e log n  
representa log2 n.  
Considere ainda dois computadores, um mais rápido (computador A) que executa a  
ordenação por inserção e um computador mais lento (computador B) que executa a  
ordenação por intercalação. Cada um deve ordenar um vetor de 10 milhões de números.  
Suponha que o computador A execute 10 bilhões de instruções por segundo e que o  
computador B execute apenas 10 milhões de instruções por segundo; assim, o  
computador A será 1000x mais rápido que o computador B em capacidade bruta de  
computação. Para tornar a diferença ainda mais drástica, suponha que o programador  
mais astucioso do mundo (eu) codifique a ordenação por inserção em linguagem de  
máquina para o computador A e que o código resultante exija 2n2 instruções para ordenar  
n números. Suponha ainda que um programador médio (Mario) implemente a ordenação  
por intercalação utilizando uma linguagem de alto nível com um compilador ineficiente  
(Java), sendo que o código resultante totaliza 50n log n instruções. Para ordenar 10  
milhões de números, o computador A leva:  
$2(107)2$
1010 = 20000  
segundos (+ de 5,5h), o computador B leva  
5 ⋅ 107 log 107  
107 ≈ 1163  
segundos (- de 20 minutos).  
Usando um algoritmo cujo tempo de execução cresce mais lentamente até mesmo com  
um compilador fraco o computador B executa numa rapidez mais de 17x maior que o  
computador A. A vantagem da ordenação por intercalação é ainda mais evidente quando  
ordenamos 100 milhões de números: São 23 dias para a ordenação por inserção e menos  
de 4 horas para ordenação por intercalação.  
Esse exemplo mostra que algoritmos assim como o hardware de computadores, devem  
ser considerados uma tecnologia. O desempenho total do sistema depende da escolha  
dos algoritmos eficiente tanto quanto da escolha do hardware rápido. A velocidade dos  
avanços que ocorrem em outras tecnologias computacionais também é observada em  
algoritmos