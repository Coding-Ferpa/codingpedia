---
title: "GPU"
weight: 3
---

É um processador vetorial pica pra caramba
# Programação em GPU

permitir uso da gpu simultaneamente a cpu e otimziar ao máximo os seus processamentos

→ CUDA (nvidia)

→ OpenCL

---
# CUDA

o compilador utiliza-se de threads CUDA, reunidos em blocos de 32 unidades, ou seja, é uma execução SIMD multithreaded

- execução assíncrona
- Scatter-Gather
- Mask Registers
- muitos arquivos de registradores

## Isa da GPU NVIDIA

PTX (Parallel Threads Execution) → utiliza registrador virtual (alocado conforme necessário) e há uma análise de convergência ou divergência de código.

## Memória privada

é uma seção de memória usada no processador SIMD multithreaded em cada lane

## Memória local

tem uma memórias geral para todas as lanes de um bloco acessarem

## Memória de GPU

memória geral para literalmente todos os blocos acessarem