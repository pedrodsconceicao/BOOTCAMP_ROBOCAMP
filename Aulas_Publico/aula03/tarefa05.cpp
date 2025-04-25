// Código de Semáforo com Funções

// crie constantes para definir os pinos para cada LED do semáforo
// LED vermelho conectado ao pino 8
#define vermelho 8
// LED amarelo conectado ao pino 9
#define amarelo 9
// LED verde conectado ao pino 10
#define verde 10

void trocaLed(int pino, int tempo){
  apagarLeds();
  digitalWrite(pino, HIGH);
  delay(tempo*1000);
}

// Função para apagar todos os LEDs
void apagarLeds() {
  digitalWrite(vermelho, LOW);
  digitalWrite(amarelo, LOW);
  digitalWrite(verde, LOW);
}

void setup() {
  // Configura os pinos como saída
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  
  // Inicializa todos os LEDs apagados
  digitalWrite(vermelho, LOW);
  digitalWrite(amarelo, LOW);
  digitalWrite(verde, LOW);
}

void loop() {
  trocaLed(vermelho, 5);
  trocaLed(verde, 4);
  trocaLed(amarelo, 2);
}
