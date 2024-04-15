// Definición de pines
// Aquí solo cambien el número del pin si lo requieren
const int ledPin1 = 2;
const int ledPin2 = 3;
const int ledPin3 = 4;
const int ledPin4 = 5;
const int ledPin5 = 6; 
const int ledPin6 = 7; 
const int ledPin7 = 8; 
const int ledPin8 = 9; 

// Control de tiempo
// Aquí únicamente dejen descomentada una frecuencia.
unsigned long previousMillis = 0;
const long interval = 10; // 100 Hz
// const long interval = 1; // 1 KHz
// const long interval = 0.01; // 100 KHz
// const long interval = 0.001; // 1 MHz

// Patrones de encendido de los LEDs
byte leds[] = {
  B00000000, 
  B00000001, 
  B00000000, 
  B00000011, 
  B00000000, 
  B00000111, 
  B00000000, 
  B00001111, 
  B00000000, 
  B00011111, 
  B00000000, 
  B00111111, 
  B00000000, 
  B01111111, 
  B00000000, 
  B11111111
};
int currentPattern = 0;

// Configuración inicial
void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT); // Configuración del 5to LED
  pinMode(ledPin6, OUTPUT); // Configuración del 6to LED
  pinMode(ledPin7, OUTPUT); // Configuración del 7mo LED
  pinMode(ledPin8, OUTPUT); // Configuración del 8vo LED
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
    digitalWrite(ledPin5, bitRead(leds[currentPattern], 4)); 
    digitalWrite(ledPin6, bitRead(leds[currentPattern], 5)); 
    digitalWrite(ledPin7, bitRead(leds[currentPattern], 6)); 
    digitalWrite(ledPin8, bitRead(leds[currentPattern], 7)); 

    currentPattern = (currentPattern + 1) % 16; // Ahora hay 16 patrones para recorrer
  }
}
