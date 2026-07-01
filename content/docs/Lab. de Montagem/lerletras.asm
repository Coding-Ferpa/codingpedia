;; Descrição do Programa:

;; Desenvolva um programa que fique em loop aguardando a digitação de teclas.
;; Quando a tecla 'A' for pressionada, exiba a mensagem "Tecla A
;; pressionada!" na tela. Quando a tecla 'B' for pressionada, exiba "Tecla B
;; pressionada!“, até formar uma palavra de cinco letras. Se a tecla 'Esc' for
;; pressionada, o programa deve finalizar.

;; Requisitos:

;; • O programa deve usar a interrupção 0x21 para leitura do teclado.
;; • Você deve implementar uma rotina de interrupção que capture a pressionada e verifique se é 'A', 'B' ou 'Esc'.
;; • Utilize a interrupção 0x10 para exibir as mensagens na tela.
;; • As mensagens devem ser exibidas sem que haja a necessidade de Enter.    

.model small
.stack 100h
.data 
    msg db 'Pressione uma tecla: $'
    tecla db ? ; variável para armazenar a tecla pressionada
.code
    MAIN:
    ; Inicialização
        mov ax, @data
        mov ds, ax
    ; Exibir mensagem
        mov ah, 09h
        lea dx, msg
        int 21h
                 
        ; Chamar a rotina de leitura de tecla
                 
        ; Exibir a tecla pressionada
        mov ah, 0Eh ; Função para escrever caractere no modo teletipo
        mov al, tecla ; Caractere a ser exibido
        int 10h 
        
        
        mov SI , 1
    le_tecla:
        ; Interrupção para ler a tecla pressionada
        mov ah, 01h ; Função para ler tecla sem eco
        int 21h ; Chama a interrupção do DOS
        mov tecla, al ; Armazena a tecla pressionada
        
        add si,1
     loop le_tecla 
     
     ; Encerrar o programa
        mov ax, 4C00h
        int 21h
    END MAIN
