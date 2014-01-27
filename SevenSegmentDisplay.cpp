#include "SevenSegmentDisplay.h"
char SevenSegmentDisplay::digitChars[10]={0b11111100,0b01100000,0b11011010,0b11110010,0b01100110,
                                      0b10110110,0b10111110,0b11100000,0b11111110,0b11100110};

SevenSegmentDisplay::SevenSegmentDisplay(unsigned char digitCount) {
  this->digitCount=digitCount;
  this->displayDigits=new char[digitCount];
  this->displayDigits=new char[digitCount];
  this->nextDigit=0;
}

SevenSegmentDisplay::~SevenSegmentDisplay() {
  delete [] this->displayDigits;
}

void SevenSegmentDisplay::setValue(int v) {
  for (int idx=0; idx<this->digitCount; idx++) {
    this->displayDigits[idx]=this->digitChars[v%10];
    v/=10;
  }
  this->nextDigit=0;
}

void SevenSegmentDisplay::setValue(float v) {
}

void SevenSegmentDisplay::update() {
  digitalWrite(this->digitPins[this->currentDigit],~this->valueForDigitON); //Turn the current digit off
  (++this->currentDigit)%=this->digitCount;
  char digit=this->displayDigits[this->currentDigit];
  for (i=0; i<8; i++) {
    if (this->outputPins[i]<0) 
      continue;
    if (digit & 1<<i) {
      digitalWrite(this->segmentPins[i],this->valueForSegmentON);
    }
    else {
      digitalWrite(this->segmentPins[i],~this->valueForSegmentON);
    }
  }
  digitalWrite(this->digitPins[this->currentDigit],this->valueForDigitON);
}



