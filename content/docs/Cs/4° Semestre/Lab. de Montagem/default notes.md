---
title: "default notes"
weight: 3
---

### Common DOS Interrupts and Functions

1. **INT 21h** (DOS Interrupt):
   - **INT 21h** is the most commonly used interrupt in DOS. It provides access to a wide range of DOS services such as file handling, input/output operations, memory management, and program termination.
   - The specific service is determined by the value in the `AH` register.
#### **Common INT 21h Functions (AH Values):**

- **AH = 01h**: **Read a single character from standard input (usually the keyboard)**
  - **Example**:
    ```assembly
    mov ah, 01h
    int 21h
    ```
  - **Output**: The character is stored in the `AL` register.

- **AH = 02h**: **Display a single character to standard output (usually the screen)**
  - **Example**:
    ```assembly
    mov ah, 02h
    mov dl, 'A'  ; Load character 'A' into DL
    int 21h      ; Display character 'A'
    ```
  - **Output**: The character in `DL` is displayed on the screen.

- **AH = 09h**: **Display a string of characters terminated by a `$`**
  - **Example**:
    ```assembly
    mov ah, 09h
    lea dx, msg  ; Load the address of the string into DX
    int 21h      ; Display the string
    ```
  - **Output**: Displays the string until it encounters the `$` character.

- **AH = 0Ah**: **Buffered input (reads a line of characters)**
  - **Example**:
    ```assembly
    mov ah, 0Ah
    lea dx, buffer  ; Load the address of the buffer into DX
    int 21h         ; Read the input into the buffer
    ```
  - **Output**: The input string is stored in the buffer, with the first byte containing the maximum input length, the second byte containing the actual number of characters entered, and the characters themselves follow.

- **AH = 4Ch**: **Terminate the program and return control to DOS**
  - **Example**:
    ```assembly
    mov ah, 4Ch
    int 21h
    ```
  - **Output**: The program terminates.

2. **INT 10h** (BIOS Video Services):
   - **INT 10h** provides low-level video services like setting the video mode, moving the cursor, and displaying characters on the screen.
   - Commonly used for direct manipulation of screen display in text and graphics modes.

#### **Common INT 10h Functions (AH Values):**

- **AH = 00h**: **Set video mode**
  - **Example**:
    ```assembly
    mov ah, 00h
    mov al, 03h  ; Set mode to 80x25 text mode
    int 10h
    ```
  - **Output**: Switches to the specified video mode.

- **AH = 02h**: **Set cursor position**
  - **Example**:
    ```assembly
    mov ah, 02h
    mov bh, 00h  ; Page number (usually 0)
    mov dh, 10   ; Row position
    mov dl, 20   ; Column position
    int 10h
    ```
  - **Output**: Moves the cursor to the specified position.

- **AH = 09h**: **Write a character at the current cursor position with attribute**
  - **Example**:
    ```assembly
    mov ah, 09h
    mov al, 'A'    ; Character to display
    mov bh, 00h    ; Page number
    mov bl, 07h    ; Attribute (white on black)
    mov cx, 1      ; Number of times to display the character
    int 10h
    ```
  - **Output**: Displays the character `A` at the current cursor position with the specified attribute.

3. **INT 16h** (BIOS Keyboard Services):
   - **INT 16h** provides services related to keyboard input.

#### **Common INT 16h Functions (AH Values):**

- **AH = 00h**: **Read a character from the keyboard (with wait)**
  - **Example**:
    ```assembly
    mov ah, 00h
    int 16h
    ```
  - **Output**: The ASCII value of the key pressed is returned in `AL`.

- **AH = 01h**: **Check for a keystroke (non-blocking)**
  - **Example**:
    ```assembly
    mov ah, 01h
    int 16h
    ```
  - **Output**: If a key is pressed, the Zero Flag is cleared, and the ASCII value is returned in `AL`.

4. **INT 13h** (BIOS Disk Services):
   - **INT 13h** provides low-level disk services like reading and writing sectors directly to disk.

#### **Common INT 13h Functions (AH Values):**

- **AH = 02h**: **Read sectors from disk**
  - **Example**:
    ```assembly
    mov ah, 02h
    mov al, 1      ; Number of sectors to read
    mov ch, 0      ; Cylinder number
    mov cl, 1      ; Sector number
    mov dh, 0      ; Head number
    mov dl, 80h    ; Drive number (0 = A:, 1 = B:, 80h = C:)
    int 13h
    ```
  - **Output**: Reads the specified sector(s) from disk.

5. **INT 12h** (BIOS Memory Size):
   - **INT 12h** is used to determine the size of conventional memory.

#### **Common INT 12h Functions (AH Values):**

- **AH = 00h**: **Get memory size**
  - **Example**:
    ```assembly
    int 12h
    ```
  - **Output**: Returns the size of conventional memory (in kilobytes) in the `AX` register.

### **Hexadecimal Values (e.g., 30h, 21h, etc.)**

- **30h (0x30):** This is just a hexadecimal representation of the decimal number 48. It's often used to convert a number into its ASCII character equivalent (e.g., adding `30h` to the number 0 gives you the ASCII character '0').

- **21h (0x21):** This value represents the decimal number 33. However, in the context of DOS interrupts, `21h` is commonly used as the interrupt number for DOS function calls (INT 21h).