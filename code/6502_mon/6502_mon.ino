const char ADDR[] = { 46, 48, 50, 52, 44, 42, 40, 38, 36, 34, 32, 30, 28, 26, 24, 22 };
const char DATA[] = { 49, 47, 45, 43, 41, 39, 37, 35 };

#define RW 23
#define CLOCK 2

void setup() {
  for (int n = 0; n < 16; n += 1) {
    pinMode(ADDR[n], INPUT);
  }

  for (int n = 0; n < 8; n += 1) {
    pinMode(DATA[n], INPUT);
  }

  pinMode(RW, INPUT);

  pinMode(CLOCK, INPUT);
  attachInterrupt(digitalPinToInterrupt(CLOCK), onClock, RISING);

  Serial.begin(57600);
}

void loop() {
   
}

void onClock() {
 char output[20];
  unsigned int address = 0;
  unsigned int data = 0;

  for (int n = 0; n < 16; n += 1) {
    int bit = digitalRead(ADDR[n]) ? 1 : 0;
    Serial.print(bit);
    address = (address << 1) + bit;
  }

  Serial.print("  ");

  for (int n = 0; n < 8; n += 1) {
    int bit = digitalRead(DATA[n]) ? 1 : 0;
    Serial.print(bit);
    data = (data << 1) + bit;
  }

  sprintf(output, "  %04x  %c %02x", address, digitalRead(RW) ? 'r' : 'W', data);

  Serial.println(output);
}
