# Practica 4
Algoritmo de Huffman mediante Arboles y Listas 

Build 0.5.2
**Agregadas las funciones mediante las cuales se creara la lista, y el arbol.
--Imprime en un archivo de salida

Build 0.6.0
**Arbol listo
--Codificacion en binario, casi lista, solo falta mostrar el numero binario

Build 0.6.2
**Codificacion en binario lista
--Alta agregar la funcion que guardara en un char *array para sacar la codificacion en ASCII extendido

Build 0.6.3
**Numeros binarios impresos correctamente, dependiendo de sun posicion en el arbol
--La funcion que imprime correctamente, al entrar recorre las referencias y las pierde

Build 0.6.5
**Numeros binarios impresos de manera correcta segun la palabra en un archivo
--Falta agregar un paso para obtener toda esa cadena del archivo donde se guardo

Build 1.0.0
**Codificacion Terminada

Build 1.0.1
**Comenzando con la decodificacion
++Se realizo el conteo de filas
++Se realizaron modificaciones a las funciones de codificacion
++Guarda la informacion del arbol codificado en dos arreglos diferentes, para despues dar de alta el arbol e imprimirlo
--Falta verificar si el arbol debe de darse de alta a partir de el orden en que se nos da el archivo

Build 1.0.1.1
**Cambiar la manera en la que interactua el programa, de manera en que trate como un proceso diferente la codificacion y la decodificacion, en el caso de la decodificacion a partir del arbol, al momento de leer del archivo guardar una lista pero excluyendo a los que son raices, con la lista hacer el mismo proceso que en la codificacion, crear el arbol,tabla binaria.
**Una vez teniendo la tabla binaria. Abrir el archivo de frase codificada, sacando los numeros y guardarlos en un arreglo, mediante una funcion convertirlos a binarios e ir completando ceros a la izquierda si la strlen es < a 8, despues de completarlos, guardarlos en un nuevo arreglo,donde se realizara la comparacion por medio de la tabla de binarios para ir poniendo letra por letra. hasta terminar el codigo binario, y si sobran 0000 excluirlos

Build 1.0.2
**Crea la lista a partir de la cual realizara la reconstruccion del arbol
**Realiza la reconstruccion del arbol a partir de la lectura del archivo
**Guarda en un arreglo dinamico todos los caracteres que estan en binario
**Implementada la funcion con la cual recorrera el arbol y mostrara los codigos binarios

Build 1.0.3
**Implementada la funcion que decodificara el arbol
--La funcion pierde referencias

Final 1.0
**Algoritmo terminado de manera correcta, por el momento no existen fallos en él.
