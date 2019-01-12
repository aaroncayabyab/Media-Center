/*--------------------------------------------------------------------------
* Name: Blinky.c
* Purpose: Media Center PRoject
* By: Aaron Cayabyab
*---------------------------------------------------------------------------*/

#include <LPC17xx.H>
#include "GLCD.h"
#include "LED.h"
#include "KBD.h"

#define __FI 1

//Menu icons
extern unsigned char music_icon[];
extern unsigned char gallery_icon[];
extern unsigned char game_icon[];

//Initailize functions
extern int mp3_player(void);
extern int start_game(void);
extern int pic_gallery(void);

void main_menu();

//Store btn input
int button_pressed;

//---------------------------------------
// MAIN MENU
//---------------------------------------
void main_menu() {
	int active_sel = 0;
	
	GLCD_Clear(Black);
	while(1) {
		GLCD_SetBackColor(Black);
		GLCD_SetTextColor(Red);
		GLCD_DisplayString(0,0,__FI,"      MAIN MENU     ");
		GLCD_SetTextColor(White);
		GLCD_DisplayString(8,0,__FI,"  UP/DOWN - Scroll  ");
		GLCD_DisplayString(9,0,__FI,"   SELECT - Go To   ");
		
		button_pressed = get_button();
		if(button_pressed == KBD_DOWN) {
			if(active_sel == 3) {
				active_sel = 0;
			}
			else {
				active_sel++;
			}
		}
		else if(button_pressed == KBD_UP){
			if(active_sel ==0) {
					active_sel = 3;
			}
			else {
				active_sel--;
			}
		}
		
		//Gallery selected
		if(active_sel==0) {
				GLCD_SetBackColor(Yellow);
				GLCD_SetTextColor(Black);
				GLCD_DisplayString(2,0,__FI,"1) GALLERY          ");
				GLCD_SetBackColor(Black);
				GLCD_SetTextColor(White);
				GLCD_DisplayString(3,0,__FI,"2) MP3              ");			
				GLCD_DisplayString(4,0,__FI,"3) GAME             ");
			
				GLCD_Bitmap(130,132,60,60,gallery_icon);
			
				if(button_pressed == KBD_SELECT) {
					GLCD_Clear(White);
					pic_gallery();
				}
			}

		//MP3 selected
		if(active_sel==1) {
				GLCD_SetBackColor(Black);
				GLCD_SetTextColor(White);
				GLCD_DisplayString(2,0,__FI,"1) GALLERY          ");
				GLCD_SetBackColor(Yellow);
				GLCD_SetTextColor(Black);
				GLCD_DisplayString(3,0,__FI,"2) MP3              ");
				GLCD_SetBackColor(Black);
				GLCD_SetTextColor(White);			
				GLCD_DisplayString(4,0,__FI,"3) GAME             ");
			
				GLCD_Bitmap(130,132,60,60,music_icon);
			
				if(button_pressed == KBD_SELECT) {
					GLCD_Clear(Black);
					mp3_player();
					GLCD_Clear(Black);
				}
			}
		
			//Game selected
		if(active_sel==2) {
				GLCD_SetBackColor(Black);
				GLCD_SetTextColor(White);
				GLCD_DisplayString(2,0,__FI,"1) GALLERY          ");
				GLCD_DisplayString(3,0,__FI,"2) MP3              ");
				GLCD_SetBackColor(Yellow);
				GLCD_SetTextColor(Black);		
				GLCD_DisplayString(4,0,__FI,"3) GAME             ");
			
				GLCD_Bitmap(130,132,60,60,game_icon);
			
				if(button_pressed == KBD_SELECT) {
					GLCD_Clear(Black);
					start_game();
				}
			}
		}
	}
//------------------------------------
// MAIN PRORAM
//---------------------------------------------
int main(void) {
		LED_Init();
		GLCD_Init();
		KBD_Init();
	
		GLCD_Clear(Black);
		GLCD_SetBackColor(Black);
		GLCD_SetTextColor(White);
		GLCD_DisplayString(5,0,__FI,"    MEDIA CENTER    ");
		GLCD_SetTextColor(Blue);		
		GLCD_DisplayString(6,0,__FI,"   Aaron Cayabyab   ");
		GLCD_SetTextColor(Yellow);		
		GLCD_DisplayString(9,0,__FI,"   Click to Start   ");
	
		while(1) {
			if(get_button() == KBD_SELECT) {
					main_menu();
			}
		}
	}