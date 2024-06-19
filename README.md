
# Video Game Business Card

This business card uses an ATTiny85 programmed by an Arduino AVR via the pin header. It uses the Open Source repository from Tiny Joypad for the software. The screen can be just about any 128x64 SSD1306 device. I use the .94" one to keep costs per unit down, but I designed the card with space to fit a larger size screen too. The pad on top of the joystick is designed in OpenScad and 3D printed. 

This is very much designed to a price.  That's why there is no USB port, no rechargeable battery, and it requires an external programmer via an unpopulated AVR pin header. 

My original goal was to keep the BOM below $6.00, but it's crept up a little over time.  I also had to re-design it because I could not order the attiny85's in a SOIC package for a while.  QFN's are more difficult to solder, but I think the card actually looks better for the work!

Some of my component choices were also simply "because I had a lot of them."  When looking at the card, see if you can find any components that only slightly make sense.   There are a few of those.  Balance those with the cost of ordering different ones and waiting for them to arrive and the method to my madness becomes apparent. Oh, and for the love of all that is pizza: Use a more thumb friendly button.  I had way too many of the ones you see here and had to get rid of them. They make a terrible button for game play.  Don't be as cheap as I am.  Be better!

The software is from the amazing set of games/tools/api from danielc at tinyjoypad.com.  All it took to make it work as a little code integrating a graphics library and some to flip the screen to work with this design.  That code is on my github page.  I like the idea of being able to switch games, so I included the least expensive option I could.  An unpopulated pin header is on the card that I use to program it. 

The programmer I use is an Arduino nano with a 10uf cap between GND and RST, and 5v, GND and D10 -> D13 to the appropriate pins soldered to a 2 row 6p pin header that I wedge into the holes on the card to load software.  The total cost of the programmer is around $6.00 and lets me be flexible with the software I load on the cards.

Finally, I used ATTinyCore from Spencer Konde to add support for the microcontroller to Arduino IDE.  

Things to note:  The version of Arduino IDE and the libraries you have often affect how the software compiles... or doesn't.  Several of the games should be simple to get running.  A few will require some debugging to work with your setup.   Changes are almost always minor.


**Files:**

**https://github.com/dschnur/Business-Card-4.0**
- BCD Joystick Cap.scad - OpenSCAD file for the pad on the top of the joystick. 
- BCD Joystick Cap.stl - STL file - import in your 3D slicer.
- BOM_Game-Buisness-Card_2024-05-24.csv - Current Bill of Materials updated with in-stock items @ DigiKey
- BOM_Game BCD 4.0_2023-04-13.csv - Old bill of materials for the card.
- PCB_Game BCD Board 4.0_2023-04-13.json - EasyEDA PC Board. 
- SCH_Game BCD 4.0_2023-04-13.json - EasyEDA Schematic. 

**From tinysaur:**
- ssd1306xled-master.zip - Arduino Library for the OLED screen.
(He liked it too:  https://tinusaur.com/2022/04/17/business-card-with-display-uses-our-attiny85-oled-library-ssd1306xled/)

**From tinyjoypad.com:**
- Tinyjoypad Games/TinyDriver.h - Modified OLED library driver include for use with ssd1306xled.  Use this with all programs below.
- Tinyjoypad Games/SOFTWARES/ - Contains test software
- Tinyjoypad Games/Games/ - All games included here.  Use TinyDriver.h and the ssd1306xled library.

**ATTiny85 Support for Arduino IDE:**
- https://github.com/SpenceKonde/ATTinyCore


## Instructions

### 1: Modify the Card Design

Make sure you replace the text and graphics on the silk screen on both the front and back of the card with your own!


### 2: Get your PCB Made:

If you are using my files, then the board is panelized with 4 cards each.  Make sure you order enough cards to hand out.  Unstuffed cards are really cool to hand out too...  I may have a batch that I got wrong...  Just saying.

If you are using EasyEDA, export the gerber files and choose a PCB fab of your choice. 

The settings I have my cards manufactured with are:

**via PCBWay**

- Dimensions:  180 x 114 mm
- Layers: 2 layers
- Thickness: 1.0mm
- Layers: 2
- Material: FR-4
- FR4-TG: TG 150-160
- Thickness: 1.0
- Solder Mask:  Matte Black (Your choice though, matte black is a fingerprint magnet.)
- Silk Screen:  White - That's my choice,  be artistic!  I'm not artistic.  Don't be like me.
- Surface Finish: HASL with genuine lead!
- Request the product number on the tooling strips/rails of each panelized set.
- Order a stencil for the top too.
- Existing fiducials I get lasered through.


**via jlcpcb**

- Material:  FR4
- Layers: 2
- Panel by Customer
- Delivery Format: Panel by Customer
- PCB Color: (I use black, but it's your choice. )
- PCB Thickness: 1
- Surface Finish: HASL (with lead!)
- Stencil:  Order one for the top only.
- Fiducials: Etched Through (This can change depending on your equipment)
- Engrave Text: Yes (That way I can keep track of what is what.  Optional depending on your equipment)


### 3: Order components.

See enclosed BOM for the the best places to order from.  I updated the most recent with current parts in stock from DigiKey.


### 4: Solder components to the top (front).

This can be tricky. The components are small. When I order cards, I have a SMD solder stencil made for the top of the card only. The card has been designed for a pick and place machine, but I use tweezers, a magnifying glass + lots of patience. I do have a small reflow oven that makes the final bit somewhat simpler. I often do some hand touch up after reflowing too.

First, I place the panelized board and SMD stencil in a jig and add solder paste.  Manufacturers have machines for this.  I don't.  I use a plastic squeegee (an old credit card will do) and a home made jig.  Get the alignment dead on before applying the solder paste.  There are videos on YouTube that do a good job showing this step.

Once I have the solder paste on my board, I use a tweezers, a magnifying table lamp, and a 3d printed bin to place the parts on the board.  Take your time.  Remember, this is the top of the board only that you are working on now.

I use an incredibly cheap but modified reflow oven to melt the solder paste, then I inspect the cards.  You can also do this with a hot air rework station, but be careful of the joystick.  It does not take heat to well.

I commonly have to add (way too much) flux to some components and touch up things with an iron.   I swear I'll get this right one day, but for now the package I am using for the ATTiny85 is a pain.  It looks cool, so for me its worth it.  I mentioned this earlier, but if you have to touch up the joystick, be careful.  It's not forgiving if you get it too hot or use the wrong flux.


### 5: Compile and Upload to your card

Do this **before** you attach the OLED.

Install and set up Arduino IDE.

Install ATTinyCore for board support @ https://github.com/SpenceKonde/ATTinyCore

Add the ssd1306xled library to your Arduino IDE.

Use the included TinyDriver.h file.  Overwrite the one in the games zip file.

Compile the program.  I use Tiny Missile as a starting point.  It's the easiest to compile.  Depending on your version or Arduino IDE and library files, mileage may vary.


**Note:** The TinyDriver.h I provide should also work for the rest of the family of programs from tinyjoypad.com

Use an Ardiuno as an ISP connected to the header on the card to upload the program. Use the example sketch in Arduino IDE to set it up.  I use a nano wired to a 6 pin header.  It's pretty simple to set up.  I do this before I attach the screen to make sure the cards can at least function enough to warrant me attaching the screen, battery, and speaker.

Before you program the card, set up Arduino IDE:

Install ATTinyCore and SSD1306Xled.

- Use the following settings to program your board:
- Board: "ATTiny25/45/85 (no bootloader)"
- Clock Source (only set on bootload): "16 MHz (PLL)"
- mills()/micros(): disabled (saves flash)

**Errata:**
You should actually burn a bootloader first to set the clock speed of the ATTiny85.   It'll get overwritten when you program it with the game.  If you forget and the cards runs *really* slow when it's finished, go back and burn a bootloader.  Then send the game to the card again.


### 6: Solder Components to the Back, Test & Finish

The back is simple enough to hand solder.

Add a lot of flux, and pre-tin the pads on the back of the card. 

Use a little solder for the speaker and the screen header.  Use lots of solder for the battery holder.  Clean the board, then add fresh flux.  The more the merrier.

Again, add way too much paste flux to the screen header and align the pins on the screen to the card.  You can use the holes on both to get close, but do this carefully.  Place the screen, add still more flux on top, check alignment again and drag solder the pads on the screen with your iron.  I don't add additional solder when I do this.

Attach the speaker and battery holder too.   

Once all parts are installed, test it. Fix any issues, clean it up and use a good double sided tape to attach the screen to the front of the card. I use a small piece of thin 3M VHB.  I bought a few sheets on Amazon and cut small pieces to fit from them.

The button for the top of the joystick is included, 3d print some and use them to save you finger. Depending on your printer you may need a *tiny* amount of ca glue to hold it to the joystick. Too much and the joystick gets glued in place.  I add glue with a pin.

I test it with a bench battery, then put it in an anti-static bag with a new one.  I install the battery when I hand out the card.

Clean it again, add a fresh cr2032 battery, put a little kapton tape over the exposed solder on the screen connector and you are done!

**Most common bugs that show in testing:**

- The pins on the ATTiny85 are not connected. - Causes various issues, put a *lot* of flux around the IC and run an iron around it.
- The Joystick doesn't work / only works in a few directions. - Check that the pins on the joystick are soldered correctly.  Same repair as the IC.
- The screen is not aligned to the pins. - This will cause issues from a blank screen to the card simply not responding. Rework the screen.
- Intermittent or no operation, but works when programming: Low battery.  Replace it.

**Note:**  With all batteries, you get what you pay for.  In this case you don't need to pay much.  Amazon has some decent ones in bulk that last a while with these cards.

### 7: 

### 8: Profit!
