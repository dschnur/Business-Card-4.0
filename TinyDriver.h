//                >>>>>  TINY JOYPAD TESTER  GPL v3 <<<<
//                   >>>>>  FOR TINYJOYPAD rev2  <<<<
//                      Programmer: Daniel C 2021
//            Contact EMAIL: electro_l.i.b@tinyjoypad.com
//              official website: www.tinyjoypad.com
//       or  https://sites.google.com/view/arduino-collection

//  TINY JOYPAD TESTER is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

//for TINY JOYPAD rev2 (attiny85)
//the code work at 16MHZ internal
//Program the chip with an arduino uno in "Arduino as ISP" mode.

#include <ssd1306xled.h>

//prototype
void TinyOLED_init(void);
void TinyOLED_Begin(void);
void TinyOLED_End(void);
void TinyOLED_Send(uint8_t byte_);
void TinyOLED_send_command(uint8_t command_);
void TinyOLED_Data_Start(uint8_t Y_);
                   
#define OledSDA_LOW  0b11111110
#define OledSDA_HIGH 0b00000001
#define OledSCL_LOW 0b11111011
#define OledSCL_HIGH 0b00000100
#define OledADRESS 0x78

void TinyOLED_init(void){
//DDRB = DDRB | OledSDA_HIGH;
//DDRB = DDRB | OledSCL_HIGH;
SSD1306.ssd1306_init();
pinMode(1,INPUT);
DDRB =DDRB|0b00010000;
pinMode(A0,INPUT);
SSD1306.ssd1306_send_command(0xC0); //Flip Screen
SSD1306.ssd1306_send_command(0xA0); //Remap address so we dont get a mirrored screen
}

void TinyOLED_Begin(void){
SSD1306.ssd1306_xfer_start();
}

void TinyOLED_End(void){
SSD1306.ssd1306_xfer_stop();
}

void TinyOLED_Send(uint8_t byte_){
SSD1306.ssd1306_send_data_start();
SSD1306.ssd1306_send_byte(byte_);
}

void TinyOLED_send_command(uint8_t command_){
SSD1306.ssd1306_send_command(command_);
}

void TinyOLED_Data_Start(uint8_t Y_){
SSD1306.ssd1306_send_data_start();
SSD1306.ssd1306_setpos(0,Y_);
}
