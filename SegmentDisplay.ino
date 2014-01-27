#include "SevenSegmentDisplay.h"

SevenSegmentDisplay displ(4);

void setup() {
}

void loop() {
  displ.setValue(1);
  displ.update();
}
