// Definicion de pines
// Aqui solo cambien el numero del pin si lo requieren
const int ledPin1 = 2;
const int ledPin2 = 3;
const int ledPin3 = 4;
const int ledPin4 = 5;

// Control de tiempo
// Aqui unicamente dejen descomentada una frecuencia.
unsigned long previousMillis = 0;
const long interval = 10; // 100 Hz
// const long interval = 1; // 1 KHz
// const long interval = 0.01; // 100 KHz
// const long interval = 0.001; // 1 MHz

byte leds[] = {B0000, B0001, B0000, B0011, B0000, B0111, B0000, B1111}; // Patrones de encendido de los LEDs
int currentPattern = 0;

// Configuracion inicial
void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

// Loop de trabajo
void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    digitalWrite(ledPin1, bitRead(leds[currentPattern], 0));
    digitalWrite(ledPin2, bitRead(leds[currentPattern], 1));
    digitalWrite(ledPin3, bitRead(leds[currentPattern], 2));
    digitalWrite(ledPin4, bitRead(leds[currentPattern], 3));

    currentPattern = (currentPattern + 1) % 8;
  }
}
