## SGBD
- Sistema gerenciador de banco de dados eh uma coleção de programas com proposito sistemático e eficiente nas tarefas de armazenamento e recuperação de dados.
- Banco de Dados -> seção logica (arquivos) onde os dados são armazenados, normalmente, associado a um SGBD com repositórios dos respectivos dados e estruturas de controle.


# Niveis de Abstracao
**Físico**: o nivel mais baixo de abstracao, descreve como o dado eh de fato armazenado, ou seja, as estruturas de dados que armazenam os dados.

**Conceitual/Logico**: Descreve quais dados sao armazenados e quais relacionamentos possuem. O uso desta camada eh basico, entretanto, sua producao pela camada fisica nao.

**Nivel de visao** permite que grupos podam acessar as partes inferiores do banco de dados. A camada mais alta de abstracao.

# Esquema x Instancia

**esquema**: a especificacao das caracteristicas de como sao os dados suportados pelo SGBD. Eh o design logico do banco de dados.

**instancia**: eh uma tupla/ocorrencia dentro da tabela em determinado instante, para ou definidas pelo esquema. Estas ocorrencias sao tambem denominadas de valores.


# Modelo de dados
Uma colecao de ferramentas concentuais que servem para descrever dados, relacoes, semanticas e constraints. Descreve uma forma de descrever o _design_ de um banco de dados em qualquer nivel, partindo do mundo real.
> _ex_: hierarquico, relacional, orientado a objeto, a grafos... cada geracao ou amplia o restringe o objeto de estudo dos modelos, grafos eh restrito, objeto eh amplo (em representacao semantica).


# Linguagens

**Linguagem de definicao de dados (LDD)**: eh a linguagem do sgbd que permite a especificacao dos esquemas. (altera o Nivel conceitual) Altera propriedades dos dados.

**Linguagem de manipulacao de dados (LMD)**: permite a manipulacao das instancias de dados. Ela permite:
- Consultas para resgatar informacao no DB.
- Permite a insercao de nova informacao no DB.
- Permite deletar informacao do DB.
- Permite modificacao de informacao.