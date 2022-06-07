/* 
 *  https://moderndevice.com/products/wind-sensor
 */

#define analogPinForRV    A0   // change to pins you the analog pins are using
#define analogPinForTMP   A1

#define KNOB_PIN_1 A2
#define KNOB_PIN_2 A3
#define KNOB_PIN_3 A4
#define SLIDER_PIN A5 //todo: use both slider pins and average them

//#define NUM_BUTTONS 11;

bool started = false;

long countervalue = 0; // counter value

// to calibrate your sensor, put a glass over it, but the sensor should not be
// touching the desktop surface however.
// adjust the zeroWindAdjustment until your sensor reads about zero with the glass over it. 

const float zeroWindAdjustment =  0.2; // negative numbers yield smaller wind speeds and vice versa.

int TMP_Therm_ADunits;  //temp termistor value from wind sensor
float RV_Wind_ADunits;    //RV output from wind sensor 
float RV_Wind_Volts;
unsigned long lastMillis;
int TempCtimes100;
float zeroWind_ADunits;
float zeroWind_volts;
float WindSpeed_MPH;
int windspeed;

void setup() {

  Serial.begin(115200);   // faster printing to get a bit better throughput on extended info

  pinMode( KNOB_PIN_1, INPUT );
  pinMode( KNOB_PIN_2, INPUT );
  pinMode( KNOB_PIN_3, INPUT );
  pinMode( SLIDER_PIN, INPUT );

  /*
  for (int i = 0; i < NUM_BUTTONS; i++) {
       pinMode(i, INPUT);
       buttonPressed[i] = false;
  }
  */
}

void loop() {


  if(Serial.available()) // check to see if there's serial data in the buffer
  {
    int serialvalue = Serial.read(); //hang until read a byte of serial data (Max is ready)
    started = true;
  }

  if (started) {
  
    if (millis() - lastMillis > 200){      // read every 200 ms - printing slows this down further
      
      TMP_Therm_ADunits = analogRead(analogPinForTMP); // Temp_Volts = TMP_Therm_ADunits * 0.0048828125 
      RV_Wind_ADunits = analogRead(analogPinForRV);
      RV_Wind_Volts = (RV_Wind_ADunits *  0.0048828125);
  
      // these are all derived from regressions from raw data as such they depend on a lot of experimental factors
      // such as accuracy of temp sensors, and voltage at the actual wind sensor, (wire losses) which were unaccouted for.
      TempCtimes100 = (0.005 *((float)TMP_Therm_ADunits * (float)TMP_Therm_ADunits)) - (16.862 * (float)TMP_Therm_ADunits) + 9075.4;  
  
      zeroWind_ADunits = -0.0006*((float)TMP_Therm_ADunits * (float)TMP_Therm_ADunits) + 1.0727 * (float)TMP_Therm_ADunits + 47.172;  //  13.0C  553  482.39
  
      zeroWind_volts = (zeroWind_ADunits * 0.0048828125) - zeroWindAdjustment;  
  
      // This from a regression from data in the form of 
      // Vraw = V0 + b * WindSpeed ^ c
      // V0 is zero wind at a particular temperature
      // The constants b and c were determined by some Excel wrangling with the solver.
      WindSpeed_MPH =  pow(((RV_Wind_Volts - zeroWind_volts) /.2300) , 2.7265);   
    
      //SUCK SPEED
      //int windspeed = (int)((RV_Wind_Volts - zeroWind_volts) * 100); 
      Serial.print((int)(WindSpeed_MPH * 1000));
      Serial.print(" "); 

      //KNOB 1
      Serial.print(analogRead(KNOB_PIN_1) / 4); 
      Serial.print(" "); 

      //KNOB 2
      Serial.print(analogRead(KNOB_PIN_2) / 4);
      Serial.print(" "); 

      //KNOB 3
      Serial.print(analogRead(KNOB_PIN_3) / 4);
      Serial.print(" "); 

      //SLIDER
      Serial.print(analogRead(SLIDER_PIN) / 4);

      /*
      for (int i = 0; i < NUM_BUTTONS; i++) {
        Serial.print(" "); // print a space
        Serial.print( digitalRead(i) ); // print the button value
      }
      */
      
      Serial.println(); // print a line-feed
  
      //increment the counter
      countervalue = (countervalue+1);

      lastMillis = millis();    
    } 
    
  }

}
