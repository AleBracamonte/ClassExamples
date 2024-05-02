// Definición de pines para los LEDs
#define LeftLed 6
#define RightLed 5

// Definición de pines para los botones de señal
#define LeftSignal 4
#define RightSignal 3
#define EmergencySignal 2

// Definición de estados
enum State {
  OFF,
  LeftEnabled,
  RightEnabled,
  EmergencyEnabled
};

// Variables de estado
State currentState = OFF;
State previousState = OFF;


void setup() {
  // Inicialización de los pines de LED como salida
  pinMode(LeftLed, OUTPUT);
  pinMode(RightLed, OUTPUT);

  // Inicialización de los pines de botón como entrada con pull-up
  pinMode(LeftSignal, INPUT_PULLUP);
  pinMode(RightSignal, INPUT_PULLUP);
  pinMode(EmergencySignal, INPUT_PULLUP);
}

void loop() {
  // Leer los botones y determinar la señal activa
  bool leftSignal = digitalRead(LeftSignal);
  bool rightSignal = digitalRead(RightSignal);
  bool emergencySignal = digitalRead(EmergencySignal);

  // Actualizar el estado según la señal activa
  switch (currentState) {
    case OFF:
      if (leftSignal) {
        currentState = LeftEnabled;
      } else if (rightSignal) {
        currentState = RightEnabled;
      } else if (emergencySignal) {
        currentState = EmergencyEnabled;
      }
      break;

    case LeftEnabled:
      if (emergencySignal) {
        currentState = EmergencyEnabled;
      } else if (!leftSignal) {
        currentState = OFF;
      }
      break;

    case RightEnabled:
      if (emergencySignal) {
        currentState = EmergencyEnabled;
      } else if (!rightSignal) {
        currentState = OFF;
      }
      break;

    case EmergencyEnabled:
      if (!emergencySignal) {
        currentState = OFF;
      }
      break;
  }

  // Si se cambia a EmergencyEnabled, reiniciar el estado de los LEDs
  if (currentState == EmergencyEnabled && previousState != EmergencyEnabled) {
    digitalWrite(LeftLed, LOW);
    digitalWrite(RightLed, LOW);
  }

  // Actualizar los LEDs según el estado actual
  switch (currentState) {
    case OFF:
        digitalWrite(LeftLed, LOW);
        digitalWrite(RightLed, LOW); 
      break;

    case LeftEnabled:
      for (int i = 0; i < 3; i++) {
          digitalWrite(LeftLed, HIGH);
          delay(500); 
          digitalWrite(LeftLed, LOW);
          delay(500); 
        }
      break;

    case RightEnabled:
      for (int i = 0; i < 3; i++) {
          digitalWrite(RightLed, HIGH);
          delay(500); 
          digitalWrite(RightLed, LOW);
          delay(500); 
        }
      break;

    case EmergencyEnabled:
      if (emergencySignal) {
        for (int i = 0; i < 3; i++) {
          digitalWrite(LeftLed, HIGH);
          digitalWrite(RightLed, HIGH);
          delay(500); 
          digitalWrite(LeftLed, LOW);
          digitalWrite(RightLed, LOW);
          delay(500); 
        }
      }
      break;
  }
  previousState = currentState;
}
