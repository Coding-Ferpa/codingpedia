---
title: "extra 1"
weight: 4
---

alguns conceitos no livro de pcp

# 1.3 - Applications and programming styles

Existem 3 tipos de aplicações paralelas comuns: sistemas multithreaded's, distribuidos e computações paralelas.

# 1.4 - Iterative Parallelism: Matrix multiplication

é possível computar for loops em paralelo, se usarmos cada iteração (desde que independentes entre si - podem até compartilhar um mesmo endereço de memória, sendo o problema sincronizável, mas o ideal é que cada iteração acesse e altere sua própria parte de memória) usando `co` (concurrent) ao invés de um for em si, para computar as interações concorrentemente.

---
cansei do capitulo 1. Paia

# capitulo 2 - alguns conceitos ai
estado (contexto) do processo: indica as variáveis alocadas no momento pelo processo, assim como o contador de programa e outros detalhes.

