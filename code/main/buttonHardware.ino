const int NROFBUTTONS = 4;

const int BUTTONPINS[] = {A1, A2, A3, A4};

void buttonHardwareSetup() {
  for (int i = 0; i < NROFBUTTONS; i++) {
    pinMode(BUTTONPINS[i], INPUT);
  }
}

boolean buttonHardwareDown(int button) {
  // Pull down resistor used.
  return (digitalRead(BUTTONPINS[button]) == HIGH);
  // if pull down resistor is used, compare to HIGH
}

boolean buttonHardwareUp(int button) {
  return !buttonHardwareDown(button);
}
