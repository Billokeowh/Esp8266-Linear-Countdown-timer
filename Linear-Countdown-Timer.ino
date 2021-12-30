#include <FastLED.h>
#define NUM_LEDS 29//Edit to whatever length of LED strip you are using. 
#define DATA_PIN 2  // Pin attached to the Data pin of your Led strip.
//#define CLOCK_PIN 10


// END OF NPT DEFINITIONS
const int buttonPin = 13;     // the number of the pushbutton pin
boolean flasher = true;      //
int delayCounter = 0;
int timeLeft = 0;
int hoursInMS = 0;
int minsInMS = 0;
int secsInMS = 0;
int totalTimeMS = 0;
int buttonState = 0;
int countdownMinutes = 0;
int mins = 0;
int resetCoutner = 0;
boolean counterflag = false;
boolean timermode = false;
boolean animationFlag = false;
boolean buttonReleased = false;




CRGB leds[NUM_LEDS];


void setup() {
  pinMode(buttonPin, INPUT);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
  FastLED.setBrightness(255);
  Serial.begin(9600);
  allBlack();
}



void loop() {

  // Turn the LED on, then pause
  FastLED.setBrightness(255);
  buttonState = digitalRead(buttonPin);


  //COUNTUP - If button is held then count up the timer + set the counterFlag to TRUE
  if ((buttonState == 1) && (timermode == false)) {
    
    while (buttonState == 1) {
      delay(10); // Need a delay for button debounce reasons - if code is error prone you may need to edit delay duration. 
      buttonState = digitalRead(buttonPin);
      leds[mins] = CRGB::Green;
      Serial.println(mins);
      FastLED.show();
      delay(300);//delay in counting up. Smaller for faster. 
      mins++;
      //TODO - The debounce and delay above needs work. Very easy to add additional minutes when you don't mean to. 
    }
    timermode = true;
  }




  // Countdown to 0
  if ((buttonState == 0) && (timermode == true)) {
    Serial.println("in the countdown");
    allBlack();
    countDown(mins);
    endAnimation();
    timermode == false;
  }


}

void allBlack() {
  for (int b = 0; b < NUM_LEDS; b++) {

    leds[b] = CRGB::Black;
    FastLED.show();
  }

}

void allGreen() {
  for (int b = 0; b < NUM_LEDS; b++) {

    leds[b] = CRGB::Green;
    FastLED.show();
  }

}

void countDown(int delayCounter) {
  Serial.println(delayCounter);
  delayCounter = (delayCounter * 60 * 1000);
  FastLED.setBrightness(255);
  Serial.println("This many MS to count down");
  Serial.println(delayCounter);
  Serial.println("Delay for each LED:");
  Serial.println(delayCounter / NUM_LEDS);
  delayCounter = delayCounter / NUM_LEDS;
  allGreen();

  for (int f = NUM_LEDS - 1; f > -1; f--) {
    Serial.println(f);

    if (flasher == true) {
      for (int t = 0; t < 16; t++) {
        leds[f] = CRGB::Red;
        FastLED.show();
        delay(delayCounter / 32);
        leds[f] = CRGB::Black;
        FastLED.show();
        delay(delayCounter / 32);
        buttonState = digitalRead(buttonPin);
        if(buttonState==1){
          delay(10); //debounce
          Serial.println("Button pressed while counting down - Exiting");
          mins=0;
          return; //out of the countdown.
          
        }
        }
      }
    
    if (flasher == false) {
      for (int t = 0; t < 16; t++) {
        leds[f] = CRGB::Red;
        FastLED.show();
        delay(delayCounter);
        leds[f] = CRGB::Black;
        FastLED.show();
      }

    }

}
  animationFlag = true;
}


void endAnimation() {
  while (resetCoutner < 5) { // Set higher number here for longer finishing animation
    for (int reset = 0; reset < NUM_LEDS; reset++) {
      leds[reset] = CRGB::Red;
      FastLED.show();
      delay(5);
    }
    for (int reset = 0; reset < NUM_LEDS; reset++) {
      leds[reset] = CRGB::Blue;
      FastLED.show();
      delay(5);
    }
    for (int reset = 0; reset < NUM_LEDS; reset++) {
      leds[reset] = CRGB::Yellow;
      FastLED.show();
      delay(5);
    }
    for (int reset = 0; reset < NUM_LEDS; reset++) {
      leds[reset] = CRGB::Green;
      FastLED.show();
      delay(5);
    }
    resetCoutner++;
  }
  for (int reset = 0; reset < NUM_LEDS; reset++) {
    leds[reset] = CRGB::Black;
    FastLED.show();
    delay(5);
  }
  counterflag = false;
  timermode = false;
  animationFlag = false;
}



