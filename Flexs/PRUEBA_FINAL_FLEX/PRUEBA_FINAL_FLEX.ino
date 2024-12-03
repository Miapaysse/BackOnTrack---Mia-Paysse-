#define FLEX1 39
#define FLEX2 36

float tension = 0;
float flex = 0;
float angulo = 0;

float V_min = 0.5;  
float V_max = 1.25;  


void setup() {
  pinMode(FLEX1, INPUT);
  pinMode(FLEX2, INPUT);

  Serial.begin(9600);
}

void loop() {
  flex = analogRead(FLEX1);
  tension = obtenerTension(flex);
  obtenerAngulo(tension);
}

float obtenerTension(float flex) {
  float tension = 0;
  tension = (flex / 4096) * 3.3;
  //Serial.print("tensión: ");
  //Serial.println(tension);
  return tension;
}

float obtenerAngulo(float tension) {

  // Función sacada de excel: ((tension * (-90)) + 180);
  
  if (tension >= V_min && tension <= V_max) {
    // Cálculo del ángulo usando interpolación lineal
    angulo = (tension - V_min) / (V_max - V_min) * 180;
  } else {
    angulo = 0; // Valor fuera de rango o error
  }

  Serial.print("Angulo: ");
  Serial.println(angulo);

  return angulo;
}
