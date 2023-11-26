# ES
## Stack\_CLI
Stack CLI es un programa que sirve para interactuar con pilas mediante un entorno CLI
### Funcionamiento básico
El programa genera dos pilas, al ejecutarlo se crean dos pilas vacias pudiendo añadir lo que quieras a cualquiera de las dos con un inicializador, desde ese momento todos los movimientos son entre pilas  
#### Sistema de comandos
Al ejecutar el programa se abrirá una "CLI" en la que podrás poner comandos, los comandos son los movimientos, sin embargo, aparte de estos hay un comando "init" `init <a|b> enteros_que_forman_la_pila`\
Una vez se ha ejecutado init no puede volverse a ejecutar hasta cerrar el programa con `exit`, por favor, no pulses "intro" hasta que hayas decidido como inicializar
#### Movimientos
##### Push
* pa (push a)				: envia a la pila 'a' el elemento superior de la pila 'b', este movimiento elimina de 'b' este elemento.
* pb (push b)				: envia a la pila 'b' el elemento superior de la pila 'a', este movimiento elimina de 'a' este movimiento.
##### Rotate
* ra (rotate a)				: mueve el elemento superior de la pila 'a' a la posición inferior de la pila 'a', en consecuencia todos los demás miembros suben una posición.
* rb (rotate b)				: mueve el elemento superior de la pila 'b' a la posición inferior de la pila 'b', en consecuencia todos los demás miembros suben una posición.
* rr (rotate ab)			: hace los dos movimientos de arriba combinados.
* rra (reverse rotate a)	: mueve el elemento inferior de la pila 'a' a la posición superior de la pila 'a', en consecuencia todos los demás miembros bajan una posición.
* rrb (reverse rotate b)	: mueve el elemento inferior de la pila 'b' a la posición superior de la pila 'b', en consecuencia todos los demás miembros bajan una posición.
* rrr (reverse rotate ab)	: hace los dos movimientos de arriba combinados.
##### Swap
* sa (swap a)				: Intercambia los dos elementos superiores de la pila 'a'
* sb (swap b)				: Intercambia los dos elementos superiores de la pila 'a'
* ss (swap ab)				: hace los dos movimientos de arriba combinados

# EN
## Stack\_CLI
Stack CLI is a program that allows you to interact with stacks using a CLI interface.
### Basic operation
The program generates two stacks. When you execute it, two empty stacks are created, and you can add anything you want to either of them with an initializer. From that moment on, all movements are between stacks.
#### Command system
When you run the program, a "CLI" will open where you can enter commands. The commands are the movements. However, besides these, there is an "init" command: `init <a|b> integers_that_form_the_stack`\
Once init has been executed, it cannot be executed again until you close the program with `exit`. Please do not press "enter" until you have decided how to initialize.
#### Movements
##### Push
* pa (push a): Sends the top element of stack 'b' to stack 'a'. This movement removes this element from 'b'.
* pb (push b): Sends the top element of stack 'a' to stack 'b'. This movement removes this element from 'a'.
##### Rotate
* ra (rotate a): Moves the top element of stack 'a' to the bottom position of stack 'a'. Consequently, all other members move up one position.
* rb (rotate b): Moves the top element of stack 'b' to the bottom position of stack 'b'. Consequently, all other members move up one position.
* rr (rotate ab): Performs both of the above movements combined.
* rra (reverse rotate a): Moves the bottom element of stack 'a' to the top position of stack 'a'. Consequently, all other members move down one position.
* rrb (reverse rotate b): Moves the bottom element of stack 'b' to the top position of stack 'b'. Consequently, all other members move down one position.
* rrr (reverse rotate ab): Performs both of the above movements combined.
##### Swap
* sa (swap a): Swaps the top two elements of stack 'a'.
* sb (swap b): Swaps the top two elements of stack 'b'.
* ss (swap ab): Performs both of the above movements combined.
