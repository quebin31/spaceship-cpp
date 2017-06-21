//
// Created by kevin on 1/06/17.
//

#include "inc/MainGame.h"

MainGame::MainGame() {
	std::cout << "GameEngine: Iniciando Allegro\n";
	if (!al_init()) {
		al_show_native_message_box(display, "Ups!", "Esto es vergonzoso", "Algo salió mal mientras iniciabamos Allegro, nuestros monos no pudieron hacer nada", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		std::cout << "GameEngine: error(Posiblemente tu sistema no tiene las librerias de Allegro)\n";
		exit(EXIT_FAILURE);
	}
	
	std::cout << "GameEngine: Iniciando Allegro Image\n";
	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Ups!", "Esto es vergonzoso", "No se pudo cargar el addon de imagenes", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		std::cout << "GameEngine: error(Verifica que liballegro_audio.so se encuentra en /usr/lib\n";
		exit(EXIT_FAILURE);
	}
	
	std::cout << "GameEngine: Iniciando Allegro Font\n";
	if (!al_init_font_addon()) {
		al_show_native_message_box(display, "Ups!", "Esto es vergonzoso", "No se pudo cargar el addon de fuentes", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		std::cout << "GameEngine: error(Verifica que liballegro_font.so se encuentra en /usr/lib\n";
		exit(EXIT_FAILURE);
	}
	
	std::cout << "GameEngine: Iniciando Allegro TTF\n";
	if (!al_init_ttf_addon()) {
		al_show_native_message_box(display, "Ups!", "Esto es vergonzoso", "No se pudo cargar el addon de ttf", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		std::cout << "GameEngine: error(Verifica que liballegro_ttf.so se encuentra en /usr/lib\n";
		exit(EXIT_FAILURE);
	}
	
	std::cout << "GameEngine: Iniciando Allegro Acodec\n";
	if (!al_init_acodec_addon()) {
		al_show_native_message_box(display, "Ups!", "Esto es vergonzoso", "No se pudo cargar el addon de acodec", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		std::cout << "GameEngine: error(Verifica que liballegro_acodec.so se encuentra en /usr/lib\n";
		exit(EXIT_FAILURE);
	}
	
	std::cout << "GameEngine: Iniciando Allegro Audio\n";
	if (!al_install_audio()) {
		al_show_native_message_box(display, "Ups!", "Esto es vergonzoso", "No se pudo cargar el addon de audio", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		std::cout << "GameEngine: error(Verifica que allegro este correctamente instalado en tu sistema\n";
		exit(EXIT_FAILURE);
	}
	
	std::cout << "GameEngine: Iniciando el teclado\n";
	if (!al_install_keyboard()) {
		al_show_native_message_box(display, "Ups!", "Esto es vergonzoso", "No se puedo obtener acceso al teclado", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		std::cout << "GameEngine: error(Verifica que allegro este correctamente instalado en tu sistema\n";
		exit(EXIT_FAILURE);
	}
	
	std::cout << "GameEngine: Allegro esta listo :D!\n";
	std::cout << "GameEngine: Creando el display\n";
	if (!(display = al_create_display(640, 480))) {
		al_show_native_message_box(display, "Ups!", "Esto es vergonzoso", "Nuestros monos no pudieron configurar el display", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		std::cout << "GameEngine: error(el display no se pudo crear)\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "GameEngine: Display creado :D! @(" << display << ")\n";
	
	std::cout << "GameEngine: Preparandose para saber que pasa in-game ^·^\n";
	if (!(eventQueue = al_create_event_queue())) {
		al_show_native_message_box(display, "Ups!", "Esto es vergonzoso", "Nuestros monos fallaron :(", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		std::cout << "GameEngine: error(la cola de eventos no se pudo crear\n";
		al_destroy_display(display);
		exit(EXIT_FAILURE);
	}
	
	std::cout << "GameEngine: Cola de eventos creada :D! @(" << eventQueue << ")\n";
	if (!(timer = al_create_timer(1.0/60))) {
		al_show_native_message_box(display, "Ups!", "Esto es vergonzoso", "Nuestros monos malograron el reloj", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		std::cout << "GameEngine: error(el timer no se puedo crear\n";
		al_destroy_display(display);
		al_destroy_event_queue(eventQueue);
		exit(EXIT_FAILURE);
	}
	std::cout << "GameEngine: Timer creado creado :D! @(" << timer << ")\n";
	
}
