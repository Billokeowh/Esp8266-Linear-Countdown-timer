# Esp8266-Linear-Countdown-timer
Very simple visual countdown timer for use with the ESP 8266 and some WS2811 Leds. Simply hold button to count up minutes and release to begin countdown.

//TODO - PIC

This linear countdown timer is designed to be a simple and easy to use tool to give a visual represnetation of time left. I use this tool daily in the classroom to allow children of all ages to understand the time they have to complete a task. It is operated by holding the button to count up the number of minutes required. The amount of time is then divided out evenly over the given number of Leds. This means that whether you are counting down from 1 hour or 1 minute, the entire strip of Leds will be used. If you wanted one Led to be one minute you could easily change the code. Although I am using this in a education setting, it would be just as effective anywhere where understanding clocks/the passage of time is difficult - retirement home, SEN setting etc...

The active Led blinks at a rate of the timedelay per Led/256. This may be distracting in some settings so I've added a way to disable it at the start of the code. Also there are hundreds of different Led types out there so my advice would be to get your Led strip working fully with the FastLED library and then cold your settings to this code. 

If there are any imporvements or features you think could be added please let me know. Happy timing!
