---
title: "Rodando o Projeto Localmente"
description: "Guia rápido para visualizar o projeto em ambiente local com Hugo"
icon: "terminal"
toc: true
weight: 3
---

## Rodando o Projeto Localmente

Se você quer visualizar suas alterações antes de enviar uma contribuição, pode rodar o projeto localmente com apenas um comando.

### Pré-requisitos

Antes de começar, certifique-se de que você tem o [Hugo](https://gohugo.io/getting-started/installing/) instalado em sua máquina.
Você pode verificar com:

```sh
hugo version
```

Se ainda não tiver o Hugo instalado, siga as instruções no site oficial ou use um gerenciador de pacotes, como:

```sh
# Para MacOS (Homebrew)
brew install hugo

# Para Linux (Snap)
sudo snap install hugo --channel=extended

# Para Arch (pacman)
sudo pacman -S hugo
```

## Passos para Rodar Localmente
1. No terminal, navegue até a raiz do projeto:
  ```sh
  cd /caminho/para/o/projeto
  ```
2. Inicie o servidor de desenvolvimento:
  ```sh
  hugo server -D
  ```
3. Acesse o projeto em seu navegador:
  ```sh
    http://localhost:1313
  ```
