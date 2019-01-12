/*----------------------------------------------------------------------------
 * Name:    gallery.c
 * Purpose: Media Center Project//Gallery Mode
 * By: Aaron Cayabyab 
 *----------------------------------------------------------------------------*/
            

#include <LPC17xx.H>                    /* NXP LPC17xx definitions            */
#include "GLCD.h"
#include "LED.h"
#include "KBD.h"

#define __FI        1                      /* Font index 16x24               */

//Gallery Pictures
extern unsigned char saitama_ok[];
extern unsigned char saitama_smile[];
extern unsigned char saitama_scary[];
extern unsigned char saitama_serious[];


/*----------------------------------------------------------------------------
  PHOTO GALLERY - 4 PICTURES - SERIOUS, CRY, SMILE, OK
 *----------------------------------------------------------------------------*/
int pic_gallery(void){
	int active_pic = 0;
	int button_pressed = 0;

	
	GLCD_SetBackColor(Black);
  GLCD_SetTextColor(White);
	
		while(1){
			GLCD_DisplayString(0, 0, __FI, "     - GALLERY -     ");
			GLCD_DisplayString(8, 0, __FI, " RIGHT/LEFT - SCROLL ");
			GLCD_DisplayString(9, 0, __FI, " UP - Return to MENU ");
			
			button_pressed = get_button();
			
			//Navigate through gallery pictures	
			if(button_pressed == KBD_LEFT){
				if(active_pic == 0){
					active_pic = 3;
				}
				else {
					active_pic--;
				}
			}
			else if(button_pressed == KBD_RIGHT) {
				if(active_pic == 4){
					active_pic = 0;
				}
				else {
					active_pic++;
				}
			}
			else if(button_pressed == KBD_UP){ 
					GLCD_Clear(Black);
					return 0;
			
			}
			
			//Display picture based on active_pic which is set by joystick
			if(active_pic == 0)  {
						GLCD_Bitmap (80, 55, 160,  130, saitama_ok);	
			}
			else if (active_pic == 1) {
						GLCD_Bitmap (80, 55, 160,  130, saitama_smile);
			}
			else if (active_pic == 2) {
						GLCD_Bitmap (80, 55, 160,  130, saitama_serious);	
			}
			else if (active_pic == 3)
			{
						GLCD_Bitmap (80, 55, 160,  130, saitama_scary);
			}
		}


}