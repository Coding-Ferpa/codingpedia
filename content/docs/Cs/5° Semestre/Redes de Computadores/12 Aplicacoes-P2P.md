Este documento representa meus estudos acerca do livro Redes de Computadores e a Internet - uma abordagem top down

---

# Comparilhamento de arquivos - Aplicacao P2P

O mais usado na Internet.
Ele nao utiliza do potencial de computacao distribuida proveniente na Rede.

Eh uma classe de aplicacoes que aproveita dos recursos na borda da rede, diretamente entre os sistemas.

- Armazenamento
- Processamento
- Largura de Banda

Quando um client procura por um arquivo em um seeder na rede e comeca a fazer o download, ele mesmo passa a ser um seeder, como um servidor, e disponibiliza o arquivo.

## Definicao
Sistema distribuido, sem controle centralizado ou organizacao hierarquica.
- o software peer to peer tem funcionalidades equivalentes entre as maquinas.
- pontos sao autonomos.
- pontos e conexoes n precisam ser constantes.

- rede de overlay: os pares foram uma rede sobreposta a rede IP

## Escalabilidade

### Modelo Classico
- Transmitir uma cópia do arquivo para cada um dos N pares.
    - Transmitir um total de (N x F ) bits.
    - Tempo para distribuição do arquivo deve ser pelo menos NF/us.
- $d_{min}$: menor capacidade de download de um par.
    - Par com menor taxa não pode obter todos os F bits do arquivo em menos tempo do
que F/dmin.

$$D_{cs} = max \lbrace \frac{NF}{\micro_{s}} \, \frac{F}{d_{min}} \rbrace$$



### E se tivessemos mais seeders?
No início da distribuição, apenas o “servidor” tem o arquivo F.
- Para levar este arquivo à rede de pares, o servidor deve enviar cada bit do arquivo pelo menos uma vez através seu link de dados (usando sua banda máxima us ).

Assim, o tempo de mínimo distribuição, é pelo menos:

tempo minimo = $\frac{f}{\micro_s}$


Assim como no modelo CS, o par com menor banda não pode obter todos os F bits do arquivo em menos do que $\frac{F}{d_{min}}$.

Tempo mínimo = NF / (us + u1 + u2 + u3 + ... + uN) -> $\micro_s + \sum\limits_{i=1}^{N}\micro_{i} \micro_i$

### Resumo

- Servidor - Melhor caso:  $\frac{F}{\micro_s}$

- No - Melhor caso: cada cliente faz o download de uma cópia.
    - Tempo de download do cliente mais lento: $\frac{F}{d_{min}}$
    - Todos os nós: download agregado de NF bits

- Taxa maxima de upload do sistema: $\micro_s + \sum\limits_{i=1}^{N}\micro_{i}$

Assim o tempo mínimo real de distribuição P2P é:

$$D_{p2p} = max \lbrace \frac{F}{\micro_s}, \frac{F}{d_{min}}, \frac{NF}{\micro_s + \sum\limits_{i=1}^{N}\micro_{i}}  \rbrace$$


# BitTorrent
A rede em si eh chamada de `BitTorrent`. Torrent eh o conteudo que vai ser compartilhado, representado por um arquivo simples .torrent, que contem os seus metadados. Os arquivos .torrent sao enviados (usualmente) para algum tipo de indexador / buscador de torrent, e.g: PirateBay, Torrentz2, Toorgle...

O arquivo .torrent tem:
- announce: informa qual __tracker__ trata a distribuicao.
- announce-list: informa eventuais trackers auxiliares.
- comment: comentario inserido pelo criador do torrent.
- created by: qual software o torrent foi criado.
- info: 
    - files 
    - lenght 
    - path 
    - pieces: uma lista de hash dos pedacos.
    - pieces lenght: tamanho de cada pedaco.

## Trackers: 
representa um no na infra do torrent. 

quando um par chega numa rede torrent, ele se registra junto ao tracker. 
- tracker eh indicado pelo arquivo .torrent.
- periodicamente informa que ainda esta vivo na rede.
- o par que possui o arquivo de dados completo eh um seed.
- __leech__: contem parcialmente o arquivo.

Tracker mantem um registro de todos os pares que participam do torrent.

- Quando um novo par chega, o tracker seleciona um subconjunto de pares participantes e envia seus enderecos IP.
- o Novo Par tenta estabelecer conexoes simultaneas com todos.
- Forma-se o _swarm_ - `enxame`

### Swarm
Todos os pares que participam da distribuicao de um arquivo. (rede de overlay)

Pares de um swarm fazem o download de blocos de tamanho igual do arquivo entre si (e.g 256kb), enquanto tambem fazem o upload.

### Tracker e pares vizinhos
__Pares Vizinhos__: Nos com quem se consegue estabelecer uma conexao.
- De tempos em tempos, um computador pergunta ao(s) tracker(s) uma lista de pares vizinhos. 
- pergunta, tambem, uma lista de blocos para os pares vizinhos e depois pedira para eles os que ele nao possui.

#### Tecnicas de escolha
blocos:
- `rarest first`: determinar quais sao os blocos mais raros entre os vizinhos e tenta-se distribuir eles mais rapidos.

a quais vizinhos enviar:
- priorizar vizinhos que enviam com maior taxa
    - a cada 10s, recalcula as taxas e define os pares `unchoked` (4 pares que fornecem taxa mais alta de download)


- `optimistic unchoked`: escolhe um aleatorio da lista de pares e envia blocos para ele, se ele corresponder, eu troco o vizinho unchoked mais lento por este novo par.
    - Mecanismos de incentivo para troca: __Tit-for-tat__ (olho por olho).
    - Por esse motivo não se deve limitar a taxa de upload numa rede de torrent.

__Pares vizinhos chocked__:  Todos os demais pares além dos 4 pares “top”


## DHT (Distributed Hash Table)

