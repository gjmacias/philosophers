
-fsanitize=thread
-fsanitize=thread
-fsanitize=thread


# philosophers - gmacias-
En este proyecto, aprenderás los principios básico de hilar un proceso.Vas a aprender a como crear hilos y descubrirás los mutex.

### Indice
* [Que es philosophers?](#que-es-philosophers)
* [Que utilizamos?](#que-utilizamos)
* [Como funciona?](#como-funciona)

### Que es philosophers?
Philosophers es un proyecto sobre programación, sincronización y rendimiento de subprocesos múltiples.


### Que utilizamos?
En nuestro **philosophers** tenemos solo las siguentes funciones de librerias externas autorizadas:

| Función  | Descripción														 			|
|-------|-----------------------------------------------------------------------------------|
| malloc | Solicitar un bloque de memoria del tamaño suministrado como parámetro.     													|
| free | Desasigna un bloque de memoria que se había asignado previamente mediante una llamada. 											|
| write | Hace que los bytes que indiques del buffer sean escritos en el file descriptor seleccionado.								|
| open |  Abre el archivo del sistema seleccionado.													|
| close |  Cierra el archivo del sistema seleccionado.               											|
| read |  Lee el contenido del archivo del sistema seleccionado.               									|
| exit | Finaliza inmediatamente el programa liberando la memoria dinamica asignada        |

Tambien necesitaremos **OBLIGATORIAMENTE** la libreria *minilibx* para este proyecto.

### Como funciona?

Para compilar el programa seguimos los siguientes pasos:

	git clone https://github.com/gjmacias/so_long
	cd so_long
	make
Luego ejecutamos el programa pasandole de parametro la ubicacion del archivo del mapa:

	./so_long maps/map.ber

¡Y eso seria todo!¡Estas liso para jugar!

# Quizás pueda interesarte!

### - Para ver mi progresion en 42 🌠
[AQUÍ](https://github.com/gjmacias/42BCN)

### - Mi perfil de 42 👾
[AQUÍ](https://profile.intra.42.fr/users/gmacias-)

### - Mis proyectos personales 🧐
[AQUÍ🗒️](https://github.com/gjmacias/autoproyectos)

# Contacto 📥

◦ Email: gmacias-@student.42barcelona.com

[1]: https://www.42barcelona.com/ "42 BCN"
