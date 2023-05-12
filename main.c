/**
* @file main.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for background scrollilng
*
*/
#include <stdio.h>
 #include<stdlib.h>
#include <string.h>
 #include"fonction.h"
 #include<SDL/SDL.h>
 #include<SDL/SDL_image.h>

 int main(int argc, char** argv)
 {
	if( SDL_Init( SDL_INIT_VIDEO ) == -1 )
    	{
        printf( "Can't init SDL:  %s\n", SDL_GetError( ) );
        return EXIT_FAILURE;
    	}

 	
 	SDL_Event event;
 	SDL_Surface *screen; 
	perso p,p2;
	int numperso;
	int Jump = 0;
	int done=0;
	
 
 
	screen = SDL_SetVideoMode( 1366, 768, 32, SDL_HWSURFACE | SDL_RESIZABLE);
    	if( screen == NULL )
    	{
        printf( "Can't set video mode: %s\n", SDL_GetError( ) );
        return EXIT_FAILURE;
    	}
	initperso(&p,1);
    	initperso(&p2,2);
 
 

 
 while(!done){
		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format,0xAD, 0xD8, 0xE6) );
  		afficherperso(&p,screen);
		afficherperso(&p2,screen); 
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
      		{				
				case SDL_QUIT:
        		{
         				done= 1;
				}
				break;
				case SDL_KEYDOWN:
    		if(event.key.keysym.sym == SDLK_RIGHT){
              p.Signal = 1;
              p.direction = 1;
                
                
    		}
    		if(event.key.keysym.sym == SDLK_LEFT){
                  p.Signalb = 1;
                  p.direction = -1;
                
    		
            }
            if(event.key.keysym.sym == SDLK_UP){
            	p.isJump = 1;
            }
            if(event.key.keysym.sym == SDLK_d){
            p2.Signal = 1;
            p2.direction = 1;
        	}
        	if(event.key.keysym.sym == SDLK_q){
            p2.Signalb = 1;
            p2.direction = -1;
        	}
        	if(event.key.keysym.sym == SDLK_z){
         	p2.isJump = 1;
        	}

    		break;
    		case SDL_KEYUP:
    		if(event.key.keysym.sym == SDLK_q)
                  p2.Signalb = 0;
    		if(event.key.keysym.sym == SDLK_d)
                p2.Signal = 0;
    		if(event.key.keysym.sym == SDLK_RIGHT)
             p.Signal = 0;
            if(event.key.keysym.sym == SDLK_LEFT)
              p.Signalb = 0;
            if(event.key.keysym.sym == SDLK_UP){
              Jump = 0;
            }
    		      
            
    		break;
				default:
				break;
			}}
		
		
        		
		  
	
      sautperso(&p);
      sautperso(&p2);
      printf("posScreen.y: %d\n", p.posScreen.y);
      deplacerPerso(&p);
      deplacerPerso(&p2);
      animerperso(&p);
      animerperso(&p2);
      
      
      if (p.frame == 5)
        p.frame = 0;
      if (p.frameb == 0)
        p.frameb = 5;
    if (p2.frame == 5)
        p2.frame = 0;
      if (p2.frameb == 0)
        p2.frameb = 5;
    	
    	SDL_Flip(screen);
      	SDL_Delay(10);
    	
	}
    
    SDL_FreeSurface(p.img);
    SDL_FreeSurface(p2.img);

    SDL_Quit();
    return EXIT_SUCCESS;
}
 

 
