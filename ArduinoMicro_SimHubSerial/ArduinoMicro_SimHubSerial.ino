/* -------------------------------------------------------

This is a very basic serial reader/writer to interface a 
Nextion Screen with SimHub's "Custom Serial Device" plugin
specifically for use with an Arduino Pro Micro 5v 16mhz.

------------------------------------------------------- */

//SimHub uses 115200, ensure your Windows Device and Nextion HMI file are all set to the correct baud
static long baud = 115200;

void setup() {
  /*

  The Arduino Micro has two Serial interfaces, one operates 
  over the USB connection (Serial) and is what SimHub can see
  the second (Serial1) operates between the Micro and the Nextion 
  Display over the physical RX/TX connections on the Micro board. 
  We must establish both and transfer messages for the Nextion 
  to see SimHub's output.
  
  
  
  */

  Serial.begin(baud);  //SimHub <-> USB/Micro
  Serial1.begin(baud); //USB/Micro <-> Nextion  //If Running/Testing on an Uno remove this

}

void loop() {
  
  
  //If running/testing on an Uno just use while(Serial.available() >0)
  while ((Serial1.available() > 0) && (Serial.available() > 0))
  {
    //Read the serial buffer coming over USB from SimHub
    //Note: We are not looking for data from the Nextion, if you want to read display 
    //      commands you will need to also read the Serial1 buffer and write it to Serial
    char inByte = (char)Serial.read();
    
    /* 
    The magic to make this work: SimHub outputs ASCII to Serial
    but the Nextion requires a hex end of message 0xFF 0xFF 0xFF.
    It will not respond to this translated to ASCII so instead 
    we establish our own end of message character and when we see
    it in the buffer, we know to send the Nextion message termination

    */

    //If you want to use | in your screen data you can simply change this character 
    //to something else and ensure your messages in SimHub use the new character
    //If running/testing on an Uno change the next 4 Serial1's to just Serial
    if (inByte == '|')
    {
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);
    }
    else
    {
       Serial1.write(inByte);
    }
 }
 
}
