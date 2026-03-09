---
title: "flex"
weight: 4
---

aula de flex
# Padrões de expressões regulares
POSIX é o padrão, mas o que mais está sendo utilizado é PCRE.

- Literais -> example 
- Conjuntos [] -> [a-zA-Z] // Na tabela ASCII, existem outros caracteres entre Z e a (como [, \, ], \^,\_, \`\)
- Grupos () -> (abc)
- Ancoras ^ \$ -> \^example\$ 
- União | -> (let|const)
- Fechamento * (0 ou +) + (positivo) {valor arbitrário} -> (ab)*\[c-z\]+\[\[:digit:\]\] {1, 3}
- Expansão {NAME} -> a{NAME}b (sendo NAME um valor definido pelo usuário)
- Curinga . -> .
- Escape \ -> \\.\\+\\(

--- 
# Flex 
- char* yytext
    - string contendo o valor do token atual
- int yylen 
    - tamanho da string do token atual
- FILE* yyin 
    - contem o arquivo de leitura. Por padrao, stdin (console).
- void yyrestart(FILE* new_file)
    - injeta um novo arquivo dentro de yyin.
- FILE* yyout 
    - Contem o arquivo que recebera a saide do programa (padrao stdout).
- int yylineno
    - Numero da linha atual (precisa de %option yylineno) no preambulo.
