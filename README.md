# philosophers - gmacias-
En este proyecto, aprenderás los principios básico de hilar un proceso.Vas a aprender a como crear hilos y descubrirás los mutex.

### Indice
* [Que es philosophers?](#que-es-philosophers)
* [Las reglas del juego:](#las-reglas-del-juego)
* [Que utilizamos?](#que-utilizamos)
* [Como funciona?](#como-funciona)

### Que es philosophers?
Philosophers es un proyecto sobre programación, sincronización y rendimiento de subprocesos múltiples.

Para mejor entendimiento de su funcionamiento, haremos una analogia donde:

	• Cada filósofo debe ser un hilo.
	• Hay un tenedor entre cada filósofo. por lo tanto, si hay varios filósofos, cada filósofo debe tener un tenedor su izquierda y otro a su derecha.
	• Si solo hay un filósofo, solo habrá un  enedor en la mesa.
	• Para prevenir que los filósofos dupliquen los tenedores, deberás proteger los estados de los tenedores con un mutex por cada uno de ellos.

### Las reglas del juego:
Aqui muestro cuales son las reglas del juego:

1. El programa debe tomar los siguientes argumentos:

	• number_of_philosophers  
	• time_to_die  
	• time_to_eat  
	• time_to_sleep  
	◦ number_of_times_each_philosopher_must_eat (opcional)  

• **number_of_philosophers:** es el número de filósofos, pero también el número de tenedores.  
• **time_to_die (en ms):** si un filósofo no empieza a comer, si la diferencia entre una comida y eotra es mayor a `time_to_die`, este morirá.  
• **time_to_eat (en ms):** es el tiempo que tarda un filósofo para comer. Durante ese tiempo, tendrá los tenedores **ocupados**.  
• **time_to_sleep (en ms):** es el tiempo que esta durmiendo un filósofo. Durante ese tiempo, **no** podra hacer nada.  
◦ **(opcional):** limita cuantas veces todos los filosofos deben de comer, si lo cumplen, la simulación se detendrá. Si no se especifica, la simulación se detendrá con la muerte de un filósofo.

2. Cada filósofo tendrá asignado un número: **del 1 al number_of_philosophers**.
3. La mesa es **redonda**. El filósofo número 1 se sentará al lado del filósofo número number_of_philosophers. Los demas se sentarán entre el filósofo número **N - 1** y el filósofo número **N + 1**.

### Que utilizamos?
En nuestro **philosophers** tenemos solo las siguentes funciones de librerias externas autorizadas:

| Función  | Descripción					 			|
|-------|-----------------------------------------------------------------------------------|
| malloc | Solicitar un bloque de memoria del tamaño suministrado como parámetro.     						|
| free | Desasigna un bloque de memoria que se había asignado previamente mediante una llamada. 				|
| write | Hace que los bytes que indiques del buffer sean escritos en el file descriptor seleccionado.				|
| printf | Escribe por pantalla una “cadena de formato” donde puedes incluir variables en la salida.				|
| usleep | Suspende la ejecución del proceso llamante durante usec microsegundos.        					|
| gettimeofday | Permite obtener la hora usado en los sistemas operativos UNIX.            					|
| pthread_create | Crea un nuevo hilo donde le puedes pasar la funcion a realizar junto los atributos necesarios		|
| pthread_mutex_init | Crea e inicializa un nuevo bloqueador			|
| pthread_mutex_lock | Bloquea el bloqueador					|
| pthread_mutex_unlock | Desloquea el bloqueador				|
| pthread_mutex_destroy | Elimina el bloqueador seleccionado			|
| pthread_join | Une cada hilo que pase por esta funcion con el hilo principal	|

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
