---
title: "aula 11 exemplos"
weight: 4
---

# Sistema de arquivos (RPC)

```c
module FileServer 
	op readblk(int fileid, offset; result char blk[1024];
	op writeblk(int fileid, offset; char blk[1024];
body
	cache de blocos do disco
	fila de requisições pendentes
	semáforos para acesso à cache e fila
	
	proc readblk(fileid, offset, blk){
		if(bloco não está em cache){
			armazena requisição na fila
			espera término da leitura
		}
		blk = bloco lido;
	}
	
	proc writeblk(fileid, offset, blk){
		seleciona bloco na cache
		if(necessitar escrita no disco){
			armazena requisição na fila
			espera término da escrita
		}
		bloco na cache = blk;
	}
	
	proc DiskDriver{
		while(true){
			espera requisição
			inicia operação
			espera interrupção do disco
			acorda processo esperando requisição
		}
	}
end FileServer
```

```c
FileCache
	opread(int count; result char buffer[*]);
	opwrite(int count; char buffer[});
body
	cache de blocos de arquivos
	variáveis para descritores de arquivos
	semáforos para acesso à cache
	
	proc read(int count, buffer){
		if(dado não está em cache){
			seleciona bloco de cache a ser usado
			if(bloco precisa ser salvo)
				FileServer.writeblk(...);
			FileServer.readblk(...);
		}
		buffer = count bytes de bloco de cache
	}
	
	proc write(count, buffer){
		if(bloco não está em cache){
			seleciona bloco da cache
			if(bloco precisa ser salvo)
				FileServer.writeblk(...);
		}
		bloco de cache = count bytes do buffer;
	}
end FileCache
```

# Filtro Merge-Sort usando RPC

```c
optype stream = (int);
module Merge[i=1 to n]
	op in1 stream, in2 stream;
	op initialize(cap stream); //link p/ stream de saída
body
	int v1,v2;
	cap stream out;
	sem empty = 1, full1 = 0, empty2 = 1, full 2 = 0;
	proc initialize(output){
		out = output;
	}
	proc in1(value1){
		P(empty1);
		v1 = value1;
		V(full1);
	}
	
	proc in2(value2){
		P(empty2);
		v2=value2;
		V(full2);
	}
	
	process M{
		P(full1);
		P(full2);
		while(v1 != EOS and v2 != EOS){
			if(v1<=v2){
				call out(v1);
				V(empty1);
				P(full1);
			}
			else{
				call out(v2);
				V(empty2);
				P(full2);
			}
		}
		if(v1 == EOS){
			while(v2 != EOS){
				call out(v2);
				V(empty2);
				P(full2);
			}
		}
		else{
			while(v1 != EOS){
				call out(v1);
				V(empty1);
				P(full1);
			}
		}
		call out(EOS);
	}
	end Merge
```

# Filtro Merge-Sort usando Rendezvous

```c
optype stream=(int)
module Merge[i=1 to N]
	op in1 stream, in2 stream;
	op initialize(cap stream); // link stream saída
body
	process Filter{
		int v1,v2;
		cap stream out;
		in initialize(c)->out=c; ni
		in in1(v)->v1=v; ni
		in in2(v)->v2=v; ni
		while(v1 = EOS and v2 = EOS)
			if(v1<=v2){
				call out(v1)
				in in1(v)->v1=v; ni
			}
			else{
				call out(v2)
				in in2(v)->v2=v; ni
			}
		if(v1 == EOS){
			while(v2!=EOS){
				call out(v2); 
				in in2(v)->v2=v; ni
			}
		}
		else{
			while(v1!=EOS){
				call out(v1); 
				in in1(v)->v1=v; ni
			}
		}
		call out(EOS);
		end Merge	
```