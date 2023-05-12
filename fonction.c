/**
* @file fonction.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for pesro scrollilng
*
*/
/**

* @file fonction.c
*/
#include <stdio.h>
 #include<stdlib.h>
#include <string.h>
 #include<SDL/SDL.h>
 #include<SDL/SDL_image.h>
#include <math.h>
 #include"fonction.h"
/**
* @brief To initialize perso 
* @param b perso
* @param url the url of the image
* @return Nothing
*/
 ////////////////////////////////////////////////////////////////////////
 void initperso(perso *p,int numperso){
	p->num=numperso;
	if (numperso==1){
	p->img=IMG_Load("char1.png");
	p->posScreen.x=0;
	}
	if (numperso==2)
	{
	p->img=IMG_Load("char.png");
	p->posScreen.x=700;			
	}
    if( p->img == NULL )
        {
        printf( "Can't set video mode: %s\n", SDL_GetError( ) );
        }
	p->direction=1;
	p->posScreen.y=500;
	p->posimg.x=0;
 	p->posimg.y=0;
	p->posimg.h =37 ;
	p->posimg.w =50;
	p->Signal=0;
	p->Signalb=0;
	p->isJump = 0;
	p->col = 1;
	p->speed = 0;
	p->ground = p->posScreen.y;
	p->frame = 0;
	p->frameb = 5;
 }
 /**
* @brief To output the pesro .
* @param b pesro
* @return Nothing
*/
 void afficherperso(perso *p,SDL_Surface *screen){
 SDL_BlitSurface(p->img,&p->posimg,screen,&p->posScreen);
 }
  /**
* @brief To liber the pesro .
* @param b pesro
* @return Nothing
*/
 void liberer2(perso *a){
SDL_FreeSurface(a->img);

}
  /**
* @brief To move the pesro .
* @param b pesro
* @return Nothing
*/
 void deplacerPerso(perso *p){

	if(((p->Signal == 1)||(p->Signalb == 1))&&(p->speed < 10)){
			p->speed+= 0.15;
		}
	if((p->Signal == 0)&&(p->Signalb == 0)&&(p->speed > 0)){
		p->speed-=  0.75;
	}
	
	if(p->speed <= 0){
		p->speed = 0;
	}

	(p->posScreen.x)+= p->speed * p->direction;
	if (p->posScreen.x <= 0)
		p->posScreen.x = 0;
	if (p->posScreen.x >= 1200)
		p->posScreen.x = 1200;

 

}
 /**
* @brief To scroll the pesro .
* @param b pesro
* @return Nothing
*/
 
 void animerperso(perso *p){
	if((p->direction == 1)&&(p->Signal == 1)){
		
		p->posimg.x=(p->frame)*50;
		p->posimg.y=1*37;
		p->posimg.h=37;
		p->posimg.w=50;
		p->frame++;
	}
	if((p->Signalb == 1)&&(p->direction == -1)){
		
		p->posimg.x=(p->frameb)*50;
		p->posimg.y=3*37;
		p->posimg.h=37;
		p->posimg.w=50;
		p->frameb--;

	}	

	if((p->Signal == 0)&&(p->Signalb == 0)&&(p->isJump == 0)){
	  	p->posimg.x=0;
		p->posimg.y=0;
		p->posimg.h=37;
		p->posimg.w=50;
			}
	if((p->isJump == 1)&&(p->direction == 1))
	{
		p->posimg.x=0;
		p->posimg.y=2*37;
		p->posimg.h=37;
		p->posimg.w=50;	
	}
	if((p->isJump == 1)&&(p->direction == -1))
	{
		p->posimg.x=50;
		p->posimg.y=2*37;
		p->posimg.h=37;
		p->posimg.w=50;	
	}

 
 
 }
 
 /**
* @brief To jump the pesro .
* @param b pesro
* @return Nothing
*/
 
 void sautperso(perso *p){
	int y;
	int Amp = -300;
	float delta = -4*Amp;
	float x = (sqrt(delta) / (2));
	if((p->isJump == 1)||(p->col == 0)){
		p->VarX ++;
		printf("Jump\n");
	}
	y = (int)((p->VarX - x)*(p->VarX - x) + Amp);
	if(y < 0){
		p->col = 0;
	}
	if(y >= 0){
		y = 0;
		p->VarX = 0;
		p->isJump = 0;
		p->col = 1;
	}
	p->posScreen.y = (int) y + p->ground;
}












 
 
 
 
 
 
