# rracingDash
## SimHub Custom Serial Device Dash – Nextion 5.0" / Arduino Micro

Quickstart Guide
Follow the three steps below to get up and running with the rracingDash.

rracingDash is designed to run on a Nextion 5" TFT display connected to SimHub
via an Arduino Micro. I originally attempted to connect via a USB-TTL adapter
but the SimHub Nextion plugin caused all dynamic variables (e.g. Time, RPM) to
flicker as they updated making the dash unusable. 
 
This led me to learn SimHub no longer supports Nextion Displays and like me, 
you are probably here because you watched a youtube video and ordered the screen 
only to then realize the video is 3 years old and no longer relevant. This project 
is to show there is in fact a way. By being Arduino based the sketch can be modified
to support additional LEDs and other hardware easily. 

Proof of concept running on an Arduino Uno: https://www.youtube.com/shorts/h1ZTXwlqrbo
Note: Review sketch comments on specific changes required for the Micro.

Final product using the hardware outline belowe: https://www.youtube.com/watch?v=PJmJ7qeRTEA

The dash UI design is inspired by Lovely-Dashboard. All graphics in rracingDash 
were created from scratch but follow the same design principles. If you want 
a more feature-rich dash option I highly recommend checking out this project
but it requires different hardware: 

https://github.com/cdemetriadis/lovely-dashboard


## Hardware Requirements

Below is the exact hardware ordered:

**Arduino Micro:**
https://www.amazon.com/dp/B01KJR41J4

**Nextion 5" Intelligent Screen 800x480px**
NX8048P050-011C
https://www.amazon.com/dp/B0B95TRTRD

**MicroSD Card** (For reliably loading .TFT/HMI)
https://www.amazon.com/gp/product/B089DPCJS1

Note: The Intelligent series supports transparency in the HMI builder
if you plan to create your own dashes this opens up more creativity. 
You can save money by opting for a cheaper model.


## 1. Configure Arduino Micro


**Solder connections:**


	MICRO => Nextion
	GND   =>   GND 
	VCC   =>   5V 
	RX1   =>   TX 
	TX0   =>   RX 

**Note:** You must also solder the J1 jumper to ensure a full 5v otherwise
the Micro regulates VCC to 4.9v and the Nextion screen will not power on.

Upload the sketch from /ArduinoMicro_SimHubSerial/


## 2. Configure Nextion Display

**Load .TFT via MicroSD**
Simply place the .TFT file from the /Nextion/ folder on a MicroSD 
card. With the power off, insert the card, power on the Nextion and
it will automatically load the program. Power off and remove the SD,
the rracingDash should now appear on the next power on.

**Note:** This dash is designed for the 800x480 resolution it can be 
adaptedto any size Nextion screen using the .PSD files included in 
the /images/ folder.  All images and fonts are embedded in the HMI so 
the .jpgs in this folder are only for reference in how I build the dash, 
editing them will not update the .TFT/HMI files automatically, they need 
to be re-imported and a new .TFT/HMI file generated. The font used in 
Roboto Bold and available from Google: https://fonts.google.com/specimen/Roboto


## 3. Configure SimHub

Go to Settings -> Plugins and enable "Custom serial devices"

Ensure you Windows Device settings have the Baud rate set to 115200
for the Arduino Mico. The rracingDash .TFT/HMI file is set to expect 
this rate.

Under the Custom Serial Devices configure your Arduino. Select the correct
COM port and baudrate.  

Import the mapping settings using the file in /SimHub/

If you are succesful the session clock on the display should begin 
updating as it is set to display the current time. 

**Interacting:**  Tap the screen to switch between dashes (Title Screen, Detailed, Simple)
The title screen includes a sleep button to turn of the TFT when not in game. To turn it
back on simply touch the screen while it is asleep to wake it.

## Optional: Print the included enclosure

.stl Files are included in the /stl/ folder of a simple enclosure
that matches the Fanatec CSL DD aesthetic. 