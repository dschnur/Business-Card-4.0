
# Business-Card-4.0
Video Game Business Card

This business card uses an ATTiny85 programmed by an Arduino AVR via the pin header.
It uses the Open Source repository from Tiny Joypad for the software.
The screen can be just about any 128x64 SSD1306 device.  I use the .94" one to keep costs per unit down, but I've used larger.
The button top is designed in OpenScad and 3D printed.

Files:

BCD Joystick Cap.scad - OpenSCAD file for the pad on the top of the joystick.
BCD Joystick Cap.stl - STL file - import in your 3D slicer.
BOM_Game BCD 4.0_2023-04-13.csv - Bill of materials for the card.
PCB_Game BCD Board 4.0_2023-04-13.json - EasyEDA PC Board.
SCH_Game BCD 4.0_2023-04-13.json - EasyEDA Schematic.
Tiny-Missile-fixed.zip - Tiny Missle.  Slightly modified to flip screen so it works with this card. Includes library driver interface code.
ssd1306xled-master.zip - Arduino Library for the OLED screen.

Download ATTinyCore for board support @ https://github.com/SpenceKonde/ATTinyCore

To use:

Modify the card design: 

Make sure you replace the text and graphcs on the silk screen on both the front and back of the card with your own informaiton.

2: Make the card.

This can be tricky. The components are small.   When I order cards, I have a SMD solder stencil made for the top of the card too.  The card has been designed for a pick and place machine, but I use tweezers, a magnifying glass + lots of paitence.   I do have a small reflow oven that makes the final bit somewhat simpler.  I often do some hand touchup after reflowing too.  I use the stencil on the front of the card.

2a: (Do this before you attach the OLED) Program the card:

Add the ssd1306xled library to your Arduino IDE.

Compile the included Tiny Missle program.

Note:  The minor modification in that program also apply to the rest of the family of programs from tinyjoypad.com

Use an Ardiuno ISP connected to the header to upload the program to the cards.   I do this before I attach the screen to make sure the cards can at least function enough to warrant me attaching the screen, battery, and speaker.

2c: Attach components to the back. The back is simple enough to hand solder, plus the screen is best hand soldered.  Pre-tin the pads on the back of the card, then allign the pin holes in the screen to the card, and use *lots* of paste flux.  Attach the speaker and battery holder too.  Use a little solder for the speaker and *lots* for the battery holder.  The button for the top of the joystick is included, 3d print some and use them to save you finger.  Once all parts are installed, test it.  If it works, clean it up and use a good double sided tape adhesive (I use 3m VHB) to attach the screen to the front of the card.

4:  Profit!

![IMG_1908 2](https://user-images.githubusercontent.com/19963279/231891402-4f48f17f-9091-4113-976d-780c74542a1d.jpeg)
![IMG_1925](https://user-images.githubusercontent.com/19963279/231891413-1c71943b-8d50-41b9-b3df-e85dd74759c4.jpeg)


