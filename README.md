# Inicio
Proyecto para IPOO (Introduccion a la Programación Orientada a Objetos)
- Desarrollado por:
  - Kevin Del Castillo Ramirez
  - Jesus Lazo Quevedo

Actualmente, el juego se puede decir que tiene lo que debe de tener todo juego, es funcional,
el juego fue desarrollado con la libreria de Allegro para facilitar la carga de imagenes.

# Compilar el codigo fuente (CMAKE)
- Para poder compilar con CMake, lo primero que necesitamos instalar CMake

    - Arch Linux:

            # pacman -S cmake

    - Ubuntu y distros basadas en él:

            $ sudo add-apt-repository ppa:george-edison55/cmake-3.x
            $ sudo apt-get update
            $ sudo apt-get install cmake

- Si todo salio bien, ya tenemos CMake instalado, en este caso no necesitamos instalar allegro, ya que dentro del source incluimos una carpeta que contiene todas las librerias de allegro.

    - Hagamos clone al repositorio

            $ git clone https://github.com/lans98/SpaceShip.git
            $ cd SpaceShip
            $ mkdir build
            $ cd build

    - Generaremos los archivos para el cmake:

            $ ccmake ..

        Apretamos dos veces la tecla [c] y luego una vez la tecla [g]

    - Compilemos el juego:

            $ make

    - ¿Donde esta el juego?

            $ cd ../resources
            $ ./SpaceShip

    - **Nota:** La carpeta `./resources` es fundamental para que el juego funcione correctamente, como se observa en el anterior nos movimos a `resources` ya que ahí se genera el binario, por lo tanto, se puede borrar cualquier otra carpeta, excepto `resources`.
    - **Nota:** La capera `./libs` tambien es fundamental para que el juego funcione ya que ahi se encuentran los `.so` de allegro, que nos obviamos de instalar por esa razón.

    - **Nota:** En caso existan errores con dependencias incumplidas, verificar el contenido de esta pagina:
    https://wiki.allegro.cc/index.php?title=Install_Allegro5_From_Git/Linux/Debian#Direct_Dependencies


# Compilar el código fuente (GCC)
- Lo primero de todo, se necesita Allegro 5.x, lo ideal es compilarlo desde el codigo fuente pero tambien hay alternativas más sencillas.

    - Arch Linux:

            # pacman -S allegro

        Este comando instala la ultima versión de Allegro disponible.

    - Ubuntu y distros basadas en él:

            $ sudo add-apt-repository ppa:allegro/5.2
            $ sudo apt-get update
            $ sudo apt-get install liballegro5-dev

    - Más información y otros SO (Windows, Mac):

        https://wiki.allegro.cc/index.php?title=Getting_Started#Installing_Allegro


- Si todo salió bien y tenemos Allegro 5.x  instalado en nuestra computadora, ya podemos compilar el codigo fuente del juego.

    - Hagamos clone al repositorio:

            $ git clone https://github.com/lans98/SpaceShip.git
            $ cd SpaceShip

    - Una vez hicimos esto, podemos compilarlo:

            $ g++ -std=c++1y -o ./resources/SpaceShip main.cpp bitmap_interfaces/* bitmap_objects/* game_interfaces/* tools_and_headers/* $(pkg-config --cflags --libs allegro-5 allegro_acodec-5 allegro_audio-5 allegro_color-5 allegro_dialog-5 allegro_font-5 allegro_image-5 allegro_main-5 allegro_memfile-5 allegro_physfs-5 allegro_primitives-5 allegro_ttf-5 allegro_video-5)

    - La carpeta "resources" es elemental para que el juego funcione correctamente, y ademas el binario del juego tiene que encontrarse dentro de esa carpeta, todo lo demás puede ser borrado, despues de la compilación.
    - Notese que la salida del binario sera en `./resources` en la parte `-o ./resources/SpaceShip` y el binario se llamara SpaceShip.



# Juego
- ¿Como jugar?
    - En el momento en el que se entra por  primera vez al juego, se puede observar el menu
    principal con 2 opciones.

            Iniciar (Presiona Enter)
            Salir (Presiona Escape)

    - ***Controles:***

            FLECHA ARRIBA: La nave se mueve hacia adelante
            FLECHA ABAJO: La nave se mueve hacia atras (mirando hacia adelante)
            FLECHA IZQUIERDA: La nave se mueve hacia la izquierda (mirando hacia la izquierda, pero no dispara hacia la izquierda)
            FLECHA DERECHA: La nave se mueve hacia la derecha (mirando hacia la derecha, pero no dispara hacia la derecha)
            TECLA A: La nave dispara (siempre hacia alfrente, independiente de hacia donde mira o mueve)

    - ***Game Over / Pause:***
    Se pierde el juego una vez pierdes tus tres vidas, ya sea por chocar con asteroides, o algun *Power Up* malicioso.
    Para pausar el juego basta con apretar la tecla ESC.

            ESC: Pausa el juego
