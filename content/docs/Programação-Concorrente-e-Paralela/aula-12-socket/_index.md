---
title: "aula 12 socket"
weight: 4
---

material segundo projeto

# Programação Paralela com Bibliotecas Básicas
Troca de mensagens: o uso de threads não é viável entre processos quando o paralelismo ocorrer usando sistemas distribuidos. Assim, usamos o modelo cliente-servidor para isso.

Para tal comunicação, usaremos **SOCKETS** e **NSL**, via TCP/UDP na camada de transporte e uma aplicação de servidor.

```c
sd = socket(format, type, protocol)
```
em que: - format: system/internet
- type: circutio virtual/diagrama
- protocol: TCP/UDP

```c
host = gethostbyname(host_id)
```
associa endereco a um host.

a estrutura de dados de um socket inclui:
```c
struct sockaddr_in {
    sa_family_t sin_family;  // address family AF_INET
    in_port_t sin_port;      // port in network byte order
    struct in_addr sin_addr; // internet address
};

// Internet address 
struct in_addr {
    uint32_t s_addr,         // address in network byte order
};
```

# Server Side
```c
bind(sd, address, length);          // associa addr do server à porta (socket descriptor)
listen(sd, queue_length);           // aguarda requisições em sd (max de queue_length)
nsd = accept(sd, address, addrlen); // aceita uma conn que será tratada no socket nsd
```

# Client Side
```c
getaddrinfo(node, service, hint, res); // coleta endereços do dominio node a partir de um service, armazenando em res.
// node -> dominio
// servico -> http por exemplo
// hint -> dica
// res -> lista de endereços
connect(sd, addr, length); // requisita a conexao com o servidor addr
```

# trocando msgs
```c
count = send(sd, msg, length, flags);
count = recv(sd, buf, length, flags);
// outras alterantivas envolvem:
// uso de datagramas: sendto() e recvfrom()
// uso de read() e write() depois que uma conexão for estabelecida
```

## extra
```c 
shutdown(sd, node); // fecha a conexão - mas n destrói socket
close();            // destroi um socket

getsockname(sd, name, length); // recupera o nome do socket que tenha sido ligado pelo bind
getsockopt(sd, level, opt, opval, len); // recuppera os vals de opcoes 
setsockopt(sd, level, opt, opval, len); // 
```
