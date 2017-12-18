/*
** EPITECH PROJECT, 2017
** bootstrap_initiation
** File description:
** bootstrap_initiation
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "include/my.h"
#include "include/struct.h"
#include <stdio.h>
#include <time.h>

int	main()
{
	duck_ent duck;
	bg_ent bg;
	window_ent window;
	event_ent event;
	scope_ent scope;
	go_ent go;
	gp_ent gp;
	gr_ent gr;
	opa_ent opa;
	gm_ent gm;

	float		seconds;
	int		rebound = 0;
	int		score = 0;
	int		fail = 10;
	int		ascore = 0;
	event.resume = sfKeyEscape;
	event.retry = sfKeyR;
	event.rect.top = 0;
	event.rect.left = 0;
	event.rect.width = 110;
	event.rect.height = 110;
	window.video_mode.width = 800;
	window.video_mode.height = 600;
	window.video_mode.bitsPerPixel = 32;
	duck.dk_position.x = 0;
	duck.dk_position.y = 0;
	duck.dk_rev.x = 100;
	duck.dk_rev.y = 100;
	window.bool = 0;
	opa.color_opa.a = 170;
	opa.color_opa.r = 255;
	opa.color_opa.g = 255;
	opa.color_opa.b = 255;

	const char* mj = "assets/sounds/Mj.ogg";
	const char* awp = "assets/sounds/awp.ogg";
	const char* hitmarker = "assets/sounds/hitmarker.ogg";
	const char* pause = "assets/sounds/pause.ogg";
	const char* go_music = "assets/sounds/go.ogg";
	event.music_mj = sfMusic_createFromFile (mj);
	event.music_awp = sfMusic_createFromFile (awp);
	event.music_hitmarker = sfMusic_createFromFile (hitmarker);
	event.music_pause = sfMusic_createFromFile (pause);
	event.music_go = sfMusic_createFromFile (go_music);
	sfMusic_setVolume(event.music_mj, 35.0);
	sfMusic_setVolume(event.music_awp, 25.0);
	sfMusic_setVolume(event.music_hitmarker, 25.0);
	sfMusic_setVolume(event.music_pause, 100.0);
	sfMusic_setVolume(event.music_go, 25.0);
	window.window = sfRenderWindow_create(window.video_mode,"MyWindow", sfResize | sfClose, NULL);
	bg.texture_bg = sfTexture_createFromFile("assets/sprite/background.png",NULL);
	bg.sprite_bg = sfSprite_create();
	opa.texture_opa = sfTexture_createFromFile("assets/sprite/opa.png",NULL);
	opa.sprite_opa = sfSprite_create();
	sfSprite_setColor(opa.sprite_opa, opa.color_opa);
	duck.texture_dk = sfTexture_createFromFile("assets/sprite/spritesheet.png",NULL);
	duck.sprite_dk = sfSprite_create();
	go.texture_go = sfTexture_createFromFile("assets/sprite/game_over.png",NULL);
	go.sprite_go = sfSprite_create();
	gm.texture_gm = sfTexture_createFromFile("assets/sprite/game_menu.png",NULL);
	gm.sprite_gm = sfSprite_create();
	gm.texture_play = sfTexture_createFromFile("assets/sprite/play.png",NULL);
	gm.sprite_play = sfSprite_create();
	gm.texture_quit = sfTexture_createFromFile("assets/sprite/quit.png",NULL);
	gm.sprite_home = sfSprite_create();
	gm.texture_home = sfTexture_createFromFile("assets/sprite/game_home.png",NULL);
	gm.sprite_quit = sfSprite_create();
	gp.texture_gp = sfTexture_createFromFile("assets/sprite/game_pause.png",NULL);
	gp.sprite_gp = sfSprite_create();
	gr.sprite_gr = sfSprite_create();
	gr.texture_gr = sfTexture_createFromFile("assets/sprite/game_retry.png",NULL);
	gr.sprite_gr = sfSprite_create();
	scope.texture_scope = sfTexture_createFromFile("assets/sprite/scope2.png",NULL);
	scope.sprite_scope = sfSprite_create();
	event.clock = sfClock_create();
	sfMusic_setLoop(event.music_pause, sfTrue);
	sfRenderWindow_setTitle(window.window, "Pout_Hunter");
	while(sfRenderWindow_isOpen(window.window))
	{
		event.vector_mouse = sfMouse_getPositionRenderWindow(window.window);
		sfRenderWindow_setMouseCursorVisible(window.window,window.bool);
		while (sfRenderWindow_pollEvent(window.window, &event.event))
        {
		if (event.event.type == sfEvtKeyPressed)
		{
		if (sfKeyboard_isKeyPressed(event.retry))
		{
			fail = 0;
			score = 0;
			duck.dk_position.x = 0;
			duck.dk_position.y = rand()%500;
			my_printf("Restart\n");
			sfMusic_stop(event.music_pause);
		}
		if (sfKeyboard_isKeyPressed(event.resume))
		{
			ascore = fail;
			fail = 4;
			my_printf("Menu Pause\n");
			sfMusic_play(event.music_pause);
		}
		}
		if (event.event.type == sfEvtMouseButtonPressed && fail == 10) {
			if (event.vector_mouse.x < gm.play_position.x + 300 && event.vector_mouse.x > gm.play_position.x)
			{
				if(event.vector_mouse.y < gm.play_position.y + 75 && event.vector_mouse.y > gm.play_position.y){
				my_printf("Play");
				duck.dk_position.x = 0;
				duck.dk_position.y = rand()%500;
				fail = -1;
						}
		}
		if (event.vector_mouse.x < gm.quit_position.x + 300 && event.vector_mouse.x > gm.quit_position.x) {
			if(event.vector_mouse.y < gm.quit_position.y + 80 && event.vector_mouse.y > gm.quit_position.y) {
			my_printf("Quit");
			sfRenderWindow_close(window.window);
		}
		}
	}
                if (event.event.type == sfEvtMouseButtonPressed)
                {

			if (event.vector_mouse.x < duck.dk_position.x + 110 && event.vector_mouse.x > duck.dk_position.x)
			{
				if(event.vector_mouse.y < duck.dk_position.y + 110 && event.vector_mouse.y > duck.dk_position.y && fail < 3){
				score++;
				my_printf("Score is : %i\nPANNN !!! \n",score);
				sfMusic_play(event.music_awp);
				sfMusic_play(event.music_hitmarker);
				duck.dk_position.x = 0;
				duck.dk_position.y = rand()%500;
			} else {
				sfMusic_play(event.music_awp);
				if (fail < 3) {
			my_printf("Fail %d\n", fail + 1);
			fail++;
		}
		}
		}
		else if(event.vector_mouse.x < gp.gp_position.x + 200 && event.vector_mouse.x > gp.gp_position.x &&fail == 4 )
		{
			if(event.vector_mouse.y < gp.gp_position.y + 200 && event.vector_mouse.y > gp.gp_position.y && fail == 4)
			{
				fail = ascore;
				my_printf("Resume\n");
				sfMusic_pause(event.music_pause);
			}
		}
		else if(event.vector_mouse.x < gr.gr_position.x + 200 && event.vector_mouse.x > gr.gr_position.x &&fail == 4 )
		{
			if(event.vector_mouse.y < gr.gr_position.y + 200 && event.vector_mouse.y > gr.gr_position.y && fail == 4)
			{
				fail = 0;
				score = 0;
				duck.dk_position.x = 0;
				duck.dk_position.y = rand()%500;
				my_printf("Restart\n");
				sfMusic_pause(event.music_pause);
			}
		}else if (event.vector_mouse.x < gm.home_position.x + 200 && event.vector_mouse.x > gm.home_position.x &&fail == 4 ) {

			if(event.vector_mouse.y < gm.home_position.y + 200 && event.vector_mouse.y > gm.home_position.y && fail == 4) {
				fail = 10;
				sfMusic_stop(event.music_pause);
			}
		}
		 else{
			if (fail < 3) {
			sfMusic_play(event.music_awp);
			my_printf("Fail %d\n", fail + 1);
			fail++;
		}
		}
		} else if (event.event.type == sfEvtClosed)
		sfRenderWindow_close(window.window);
	}
		if (fail == 2)
		{
			sfMusic_play(event.music_go);
		}else if (fail != 2 && fail != 3)
		sfMusic_stop(event.music_go);

		sfRenderWindow_setFramerateLimit(window.window, 60);
		event.time = sfClock_getElapsedTime(event.clock);
		seconds = event.time.microseconds / 1000000.0;
		sfSprite_setTexture(bg.sprite_bg, bg.texture_bg, sfTrue);
		sfSprite_setTexture(duck.sprite_dk, duck.texture_dk, sfTrue);
		sfSprite_setTexture(scope.sprite_scope, scope.texture_scope, sfTrue);
		sfSprite_setTexture(go.sprite_go, go.texture_go, sfTrue);
		sfSprite_setTexture(opa.sprite_opa, opa.texture_opa, sfTrue);
		sfSprite_setTexture(gp.sprite_gp, gp.texture_gp, sfTrue);
		sfSprite_setTexture(gm.sprite_home, gm.texture_home, sfTrue);
		sfSprite_setTexture(gr.sprite_gr, gr.texture_gr, sfTrue);
		sfSprite_setTextureRect(duck.sprite_dk, event.rect);
			if (seconds > 0.25 && fail < 3)
	    {
      event.rect.left = 110;
			}
sfSprite_setTextureRect(duck.sprite_dk, event.rect);
sfRenderWindow_drawSprite(window.window, duck.sprite_dk, NULL);
			if (seconds > 0.50 && fail < 3)
			{
				event.rect.left = 220;
			}
			sfSprite_setTextureRect(duck.sprite_dk, event.rect);
			sfRenderWindow_drawSprite(window.window, duck.sprite_dk, NULL);
			if (seconds > 0.75 && fail < 3)
			{
				event.rect.left = 0;
				sfClock_restart(event.clock);
			}
		sfRenderWindow_clear(window.window, sfBlack);
	  	sfRenderWindow_drawSprite(window.window, bg.sprite_bg, NULL);
		sfRenderWindow_drawSprite(window.window, duck.sprite_dk, NULL);
		sfSprite_setPosition(duck.sprite_dk, duck.dk_position);
		if (duck.dk_position.x < window.video_mode.width && rebound == 0 && fail < 3) {
			duck.dk_position.x+=score/2 + 1;
		}
if (duck.dk_position.x >= window.video_mode.width && fail < 3) {
rebound = 1;
sfMusic_play(event.music_mj);
}
if (rebound == 1 && fail < 3) {
	duck.dk_position.x-=score/2 + 1;
	if (duck.dk_position.x <= 0 && fail < 3) {
		sfMusic_pause(event.music_mj);
		rebound = 0;
	}
}
if (fail == 3) {
	go.go_position.x = 150;
	sfRenderWindow_drawSprite(window.window, go.sprite_go, NULL);
	sfSprite_setPosition(go.sprite_go, go.go_position);
	sfMusic_stop(event.music_mj);
}
if (fail == 4) {
	gp.gp_position.x = window.video_mode.height/2 - 250;
	gp.gp_position.y = 200;
	gr.gr_position.x = window.video_mode.height/2 + 250 ;
	gr.gr_position.y = 200;
	gm.home_position.x = 300;
	gm.home_position.y = 200;
	sfRenderWindow_drawSprite(window.window, gp.sprite_gp, NULL);
	sfSprite_setPosition(gp.sprite_gp, gp.gp_position);
	sfRenderWindow_drawSprite(window.window, gr.sprite_gr, NULL);
	sfSprite_setPosition(gr.sprite_gr, gr.gr_position);
	sfRenderWindow_drawSprite(window.window, gm.sprite_home, NULL);
	sfSprite_setPosition(gm.sprite_home, gm.home_position);
	sfRenderWindow_drawSprite(window.window, opa.sprite_opa, NULL);
}
if (fail == 10) {
	gm.gm_position.x = 0;
	gm.gm_position.y = 0;
	gm.play_position.x = 240;
	gm.play_position.y = 100;
	gm.quit_position.x = 240;
	gm.quit_position.y = 328;
	sfSprite_setTexture(gm.sprite_gm, gm.texture_gm, sfTrue);
	sfSprite_setTexture(gm.sprite_play, gm.texture_play, sfTrue);
	sfSprite_setTexture(gm.sprite_quit, gm.texture_quit, sfTrue);
	sfSprite_setPosition(gm.sprite_gm, gm.gm_position);
	sfSprite_setPosition(gm.sprite_play, gm.play_position);
	sfSprite_setPosition(gm.sprite_quit, gm.quit_position);
	sfRenderWindow_drawSprite(window.window, gm.sprite_gm, NULL);
	sfRenderWindow_drawSprite(window.window, gm.sprite_play, NULL);
	sfRenderWindow_drawSprite(window.window, gm.sprite_quit, NULL);

}

sfSprite_setPosition(duck.sprite_dk, duck.dk_position);
scope.scope_position.x = event.vector_mouse.x -44;
scope.scope_position.y = event.vector_mouse.y -44;
sfSprite_setPosition(scope.sprite_scope, scope.scope_position);
sfRenderWindow_drawSprite(window.window, scope.sprite_scope, NULL);
sfRenderWindow_display(window.window);
}
	sfSprite_destroy(bg.sprite_bg);
	sfTexture_destroy(bg.texture_bg);
	sfMusic_destroy(event.music_mj);
	sfMusic_destroy(event.music_awp);
	sfMusic_destroy(event.music_hitmarker);
	sfMusic_destroy(event.music_pause);
	sfMusic_destroy(event.music_go);
	return(0);
}
