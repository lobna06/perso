#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <stdio.h>
 #include<stdlib.h>
 #include<SDL/SDL.h>
 #include<SDL/SDL_image.h>
 
/**
* @struct fonction
* @brief struct for fonction
*/
typedef struct {
	SDL_Surface *img;
	SDL_Rect posScreen;
	SDL_Rect posimg;
	int  direction; 
	int sens;
	int num;
	int Signal;/*!< Signal. */
	int Signalb;
	float VarX;
	int ground;
	float speed;/*!< speed. */
	int frame;/*!< Rectangle*/
	int frameb;/*!< Surface. */
	int isJump;
   	int col;
   	int jumpStartY;
}perso ;

void initperso(perso *p,int numperso);
void afficherperso(perso *p,SDL_Surface *screen);
void liberer2(perso *a);
void deplacerPerso(perso *p);
void animerperso(perso *p);
void sautperso(perso *p);
 
#endif 
