// Dos semaforos vehiculares y un semaforo peatonal.
// Arduino UNO: cada salida va a una resistencia de 220 ohmios,
// luego al anodo del LED. El catodo del LED se conecta a GND.
// Ciclo automatico de demostracion, sin pulsador.

const int rojo1 = 13;
const int amarillo1 = 12;
const int verde1 = 11;

const int rojo2 = 10;
const int amarillo2 = 9;
const int verde2 = 8;

const int rojoPeaton = 7;
const int verdePeaton = 6;

// Tiempos en milisegundos: 1000 ms equivalen a 1 segundo.
const unsigned long tiempoVerde = 5000;
const unsigned long tiempoAmarillo = 2000;
const unsigned long tiempoPeaton = 5000;
const unsigned long tiempoTodosRojos = 1000;

void setup() {
  pinMode(rojo1, OUTPUT);
  pinMode(amarillo1, OUTPUT);
  pinMode(verde1, OUTPUT);
  pinMode(rojo2, OUTPUT);
  pinMode(amarillo2, OUTPUT);
  pinMode(verde2, OUTPUT);
  pinMode(rojoPeaton, OUTPUT);
  pinMode(verdePeaton, OUTPUT);

  // Estado inicial: las dos vias y el peaton esperan en rojo.
  digitalWrite(amarillo1, LOW);
  digitalWrite(verde1, LOW);
  digitalWrite(amarillo2, LOW);
  digitalWrite(verde2, LOW);
  digitalWrite(verdePeaton, LOW);
  digitalWrite(rojo1, HIGH);
  digitalWrite(rojo2, HIGH);
  digitalWrite(rojoPeaton, HIGH);
  delay(tiempoTodosRojos);
}

void loop() {
  // 1. Avanzan los vehiculos de la via 1.
  // La via 2 y el peaton permanecen en rojo.
  digitalWrite(rojo1, LOW);
  digitalWrite(verde1, HIGH);
  delay(tiempoVerde);

  // 2. La via 1 cambia a amarillo.
  digitalWrite(verde1, LOW);
  digitalWrite(amarillo1, HIGH);
  delay(tiempoAmarillo);

  // 3. Todos esperan en rojo antes del siguiente turno.
  digitalWrite(amarillo1, LOW);
  digitalWrite(rojo1, HIGH);
  delay(tiempoTodosRojos);

  // 4. Avanzan los vehiculos de la via 2.
  digitalWrite(rojo2, LOW);
  digitalWrite(verde2, HIGH);
  delay(tiempoVerde);

  // 5. La via 2 cambia a amarillo.
  digitalWrite(verde2, LOW);
  digitalWrite(amarillo2, HIGH);
  delay(tiempoAmarillo);

  // 6. Todos esperan en rojo antes del cruce peatonal.
  digitalWrite(amarillo2, LOW);
  digitalWrite(rojo2, HIGH);
  delay(tiempoTodosRojos);

  // 7. Cruza el peaton; las dos vias permanecen en rojo.
  digitalWrite(rojoPeaton, LOW);
  digitalWrite(verdePeaton, HIGH);
  delay(tiempoPeaton);

  // 8. El peaton vuelve a rojo antes de reiniciar el ciclo.
  digitalWrite(verdePeaton, LOW);
  digitalWrite(rojoPeaton, HIGH);
  delay(tiempoTodosRojos);
}
