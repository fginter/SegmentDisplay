#ifndef __SevenSegmentDisplay_h__
#define __SevenSegmentDisplay_h__

/*
   ---A---
   |     |
   F     B
   |     |
   +--G--+
   |     |
   E     C
   |     |
   +--D--+  (P)
*/

class SevenSegmentDisplay {
  private:
    static char digitChars[]; //Stores all ten digits, as bytes of the form ABCDEFG0  
    char *displayDigits; //Stores as many chars as there are digits to display, from least to most significant. Allocated in constructor.
    int outputSegmentPins[8]; //Stores the output pins for ABCDEFGP. Filled by constructor. Set P to -1 if unusued. 
    int *outputDigitPins; //Stores the pins which enable whole digits. Allocated in constructor
    char digitCount; //Length of displayDigits, i.e. how many digits there are on this display?
    char nextDigit; //Which of the digitCount digits should be turned on next?
  public:
  SevenSegmentDisplay(unsigned char digitCount);
  ~SevenSegmentDisplay();
  
  void setValue(int v); //Set an integer to display
  void setValue(float v); //Set a real number to display
  
  void update(); //Call as often as practical
};

#endif

