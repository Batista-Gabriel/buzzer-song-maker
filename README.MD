# BuzzerSongMaker
  
  * play songs using your buzzer and arduino
  * buzzerSongMaker.h: Transforms ToneMelody function https://www.arduino.cc/en/Tutorial/toneMelody into a class
  * This way, you can have your melody ready and separated in a easy way
  * You may find some melodies i got ready here at https://github.com/SrManinka/buzzer-melody 

## Example

```c
#include "buzzerSongMaker.h"

#define buzzerdoor 7 //door that our buzzer will be connected

#define marioNotes 12

// Mario's song melody:
int marioMelody[] = {
  NOTE_F7, NOTE_C7, NOTE_A6, NOTE_D7, NOTE_E7, NOTE_D7, NOTE_CS7, NOTE_DS7, NOTE_CS7, NOTE_C7, NOTE_AS7, NOTE_C7
};

// Mario's  song time marking
int marioTime[] = {
  4, 4, 4, 6, 6, 6, 6, 6, 6, 6, 8, 1
};

void setup() {

buzzer mario(marioMelody, marioTime, marioNotes, buzzerdoor);
mario.play();
}

```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

