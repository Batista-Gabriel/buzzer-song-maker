/*
 * buzzerSong.h: Transforms ToneMelody function https://www.arduino.cc/en/Tutorial/toneMelody into a class
 * This way, you can have your melody ready and separated in a easy way
 * You may find some melodies i got ready here at https://github.com/SrManinka/buzzer-song-maker
 * If you find any bug or want to contribute, please coment at
 * 
 * Thank You :D
 */
#ifndef buzzer_h
#define buzzer_h



class buzzer {
  private:
    int *melody;
    int *noteDuration;
    int  numberOfNotes;
    int door;

  public:
    buzzer();
    buzzer(int *m, int * nd, int nn,int d) {
      melody = ( int*) malloc (nn*sizeof(int));
      noteDuration = (int *)malloc(nn*sizeof(int));
      setDoor(d);
     
      for(int i=0;i<nn;i++){
        melody[i] = m[i];

        noteDuration[i] = nd[i];
      }
      numberOfNotes=nn;
    }

    void setDoor(int n) {
      door = n;
    }

    
    int getDoor() {
      return door;
    }
    
    //I didn't make this function. just some alterations
    //you may find the original one at https://www.arduino.cc/en/Tutorial/toneMelody
    void play() {
      // iterate over the notes of the melody:
      for (int thisNote = 0; thisNote < numberOfNotes; thisNote++) {

        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / noteDuration[thisNote];
        tone(door, melody[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
      }
    }
};
#endif
