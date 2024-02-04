# rracingDash
## SimHub Custom Serial Device Dash – Nextion 5.0" / Arduino Micro
----

Quickstart Guide
Follow the three steps below to get up and running with the rracingDash

Design inspired by Lovely-Dashboard. All graphics in rracingDash were 
created from scratch but follow the same design principles. If you want 
a more feature-rich dash option I highly recommend checking out this project
but it requires different hardware: 

https://github.com/cdemetriadis/lovely-dashboard


## Hardware Requirements
----

**Arduino Micro used:**
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
----


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
----

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
----

Go to Settings -> Plugins and enable "Custom serial devices"

Ensure you Windows Device settings have the Baud rate set to 115200
for the Arduino Mico. The rracingDash .TFT/HMI file is set to expect 
this rate.

Under the Custom Serial Devices configure your Arduino. Select the correct
COM port and baudrate.  

Import the mapping settings using the file in /SimHub/

If you are succesful the session clock on the display should begin 
updating as it is set to display the current time. 

## 4. Optional: Print the included enclosure
----

.stl Files are included in the /stl/ folder of a simple enclosure
that matches the Fanatec CSL DD aesthetic. 