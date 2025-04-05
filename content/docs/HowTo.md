---
title: "Como Contribuir"
description: "Guia passo a passo para contribuir com o projeto"
icon: article
weight: 1
---

Contribuir com este projeto é simples e muito bem-vindo! Siga o passo a passo abaixo para começar.

## 1. Faça um Fork do Repositório

Acesse o repositório principal no GitHub e clique em **Fork** no canto superior direito para criar uma cópia em sua conta.
Se precisar de ajuda com esse processo, confira o [guia oficial do GitHub sobre forks](https://docs.github.com/pt/pull-requests/collaborating-with-pull-requests/working-with-forks/fork-a-repo).

## 2. Clone o Repositório para Sua Máquina

No terminal, use o comando:

```sh
git clone https://github.com/seu-usuario/seu-fork.git
```

Substitua seu-usuario e seu-fork pelas informações do seu repositório forkado.

## Criando Conteudo
Se você quiser contribuir criando um novo conteúdo (por exemplo, "Como Contribuir"), siga os passos abaixo:

#### Estrutura de Pastas

1. Crie uma nova pasta com o nome do conteúdo dentro da pasta content/docs. Exemplo: `content/docs/ComoContribuir`
2. Dentro dessa nova pasta, crie dois arquivos:
- _index.md
- ComoContribuir.md

A Estrutura ficará assim:

```sh
└── content
    └── docs
        └── ComoContribuir
            ├── _index.md
            └── ComoContribuir.md
```

## Exemplo de Conteudo

```md
---
title: "Como Contribuir"
description: ""
icon: "article"
toc: true
weight: 2
---

# Como Contribuir

Para contribuir com o projeto, siga os passos abaixo:

1. Faça fork do repositório.
2. Clone o fork para sua máquina local.
3. Crie uma nova branch com um nome descritivo.
4. Realize as alterações desejadas.
5. Adicione e faça commit das mudanças.
6. Envie (push) as alterações para o seu fork no GitHub.
7. Crie uma pull request para o repositório original.
```

## Dicas
- Tente manter uma linguagem clara e objetiva.
- Use títulos, listas e exemplos para facilitar a leitura.
- Verifique se o peso (weight) no frontmatter é 2 ou maior, para garantir consistência na ordenação com outros conteúdos.
