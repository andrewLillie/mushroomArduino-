    /*
    Jacob & Andrew
    Lit mushroom forest
    512 mhcid
    */


    /*Links
     * https://www.arduino.cc/en/tutorial/button
     * https://create.arduino.cc/projecthub/muhammad-aqib/arduino-rgb-led-tutorial-fc003e
     * https://learn.adafruit.com/photocells/arduino-code
     */

    //constants and variable setup
    const int buttonPin = 2;
    int buttonState = 0;   
    
    int photocellPin = 0; 
    int photocellReading;
    int LEDbrightness;
     
    int redPin = 11;
    int greenPin = 10;
    int bluePin = 9;
     
    //uncomment this line if using a Common Anode LED
    //#define COMMON_ANODE
     
    void setup()
    {
      //serial connection for light sensor 
      Serial.begin(9600); 

      //set up pins
      pinMode(redPin, OUTPUT);
      pinMode(greenPin, OUTPUT);
      pinMode(bluePin, OUTPUT);

      pinMode(buttonPin, INPUT);
    }
     
    void loop()
    {
      
      photocellReading = analogRead(photocellPin); //read in light sensor 
      
      
      buttonState = digitalRead(buttonPin); //get the cur state of the button
      //Serial.print(photocellReading);
      //Serial.println(buttonState);
      //Serial.println("-------------------");
      //Serial.print(buttonState);
      
      if (buttonState == 0) { //if the button is not pressed, set the leds to 0,0,0 (white)
        setColor(0, 0, 0);  // red
      
      //Serial.print("high");
      } else { //otherwise convert the light sensor data to led values
        LEDbrightness = map(photocellReading, 0, 1023, 0, 255);
        //Serial.println(LEDbrightness);
        //Serial.println(photocellReading);
      //if the light levels are valid
      if(LEDbrightness < 230){
        setColor(255, 0, 0);  // red
        delay(1000);
        setColor(0, 255, 0);  // green
        delay(1000);
        setColor(0, 0, 255);  // blue
        delay(1000);
        setColor(255, 255, 0);  // yellow
        delay(1000);  
        setColor(80, 0, 80);  // purple
        delay(1000);
        setColor(0, 255, 255);  // aqua
        delay(1000);
      }

      }
      
      
      
   
    }
    //set color function, makes writing the leds easier since we have 3 seperate values for each
    void setColor(int red, int green, int blue)
    {
      #ifdef COMMON_ANODE
        red = 255 - red;
        green = 255 - green;
        blue = 255 - blue;
      #endif
      analogWrite(redPin, red);
      analogWrite(greenPin, green);
      analogWrite(bluePin, blue);  
    }
