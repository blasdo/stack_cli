# ES
## Stack\_CLI
Stack CLI es un programa que sirve para interactuar con pilas mediante un entorno CLI
### Funcionamiento básico
El programa genera dos pilas, al ejecutarlo se crean dos pilas vacias pudiendo añadir lo que quieras a cualquiera de las dos con un inicializador, desde ese momento todos los movimientos son entre pilas  
#### Sistema de comandos
Al ejecutar el programa se abrirá una "CLI" en la que podrás poner comandos, los comandos son los movimientos, sin embargo, aparte de estos hay un comando "init" `init <a|b> enteros_que_forman_la_pila`\
Una vez se ha ejecutado init no puede volverse a ejecutar hasta cerrar el programa con `exit`, por favor, no pulses "intro" hasta que hayas decidido como inicializar
#### Movimientos
##### Mode 1 (legacy)
* init ID [valor1 valor2...]: crea una pila con el nombre "ID" y le asigana los valores (si los hay).
* push ID VALOR				: envia el valor "VALOR" a la pila ID (si no existe da error)
* pop ID					: muestra en pantalla el valor superior de la pila ID y lo elimina

##### Mode 2 (orden) (no impementado en 1.0)
###### Push
* pa (push a)				: envia a la pila 'a' el elemento superior de la pila 'b', este movimiento elimina de 'b' este elemento.
* pb (push b)				: envia a la pila 'b' el elemento superior de la pila 'a', este movimiento elimina de 'a' este movimiento.
###### Rotate
* ra (rotate a)				: mueve el elemento superior de la pila 'a' a la posición inferior de la pila 'a', en consecuencia todos los demás miembros suben una posición.
* rb (rotate b)				: mueve el elemento superior de la pila 'b' a la posición inferior de la pila 'b', en consecuencia todos los demás miembros suben una posición.
* rr (rotate ab)			: hace los dos movimientos de arriba combinados.
* rra (reverse rotate a)	: mueve el elemento inferior de la pila 'a' a la posición superior de la pila 'a', en consecuencia todos los demás miembros bajan una posición.
* rrb (reverse rotate b)	: mueve el elemento inferior de la pila 'b' a la posición superior de la pila 'b', en consecuencia todos los demás miembros bajan una posición.
* rrr (reverse rotate ab)	: hace los dos movimientos de arriba combinados.
###### Swap
* sa (swap a)				: Intercambia los dos elementos superiores de la pila 'a'
* sb (swap b)				: Intercambia los dos elementos superiores de la pila 'a'
* ss (swap ab)				: hace los dos movimientos de arriba combinados
