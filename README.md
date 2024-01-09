# ES
## Stack\_CLI
Stack CLI es un programa que sirve para interactuar con pilas mediante un entorno CLI
### Funcionamiento básico
El programa permite crear pilas y interactuar con ellas a nivel básico con los movimientos "push" y "pop" (modo legacy, el unico existente actualmente).
Al iniciar el programa selecciona el modo y usa los comandos que están abajo.
#### Sistema de comandos
Al ejecutar el programa se abrirá una "CLI" en la que podrás poner comandos, los comandos son los movimientos, sin embargo, aparte de estos hay un comando "init": `init ID [enteros_que_forman_la_pila]`
#### Movimientos
##### Mode 1 (legacy)
* `init ID [valor1 valor2...]  : crea una pila con el nombre "ID" y le asigana los valores (si los hay).`
* `push ID VALOR               : envia el valor "VALOR" a la pila ID (si no existe da error).`
* `pop ID                      : muestra en pantalla el valor superior de la pila ID y lo elimina.`
