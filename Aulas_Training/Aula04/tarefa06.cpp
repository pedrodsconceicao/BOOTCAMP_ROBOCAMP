/*
 * Controle de LEDs baseado em temperatura
 * 
 * Este código monitora a temperatura usando um sensor LM35 e:
 * - Acende o LED azul quando a temperatura está abaixo de 30°C
 * - Acende o LED vermelho quando a temperatura está acima de 30°C
 * 
 * Componentes:
 * - Arduino UNO
 * - 1 Sensor de temperatura LM35
 * - 1 LED azul com resistor
 * - 1 LED vermelho com resistor
 * - Placa de ensaio e cabos de conexão
 */

// Definição dos pinos
const int PINO_SENSOR_TEMP = A0;  // Sensor de temperatura conectado ao pino analógico A0
const int PINO_LED_AZUL = 7;      // LED azul conectado ao pino digital 7
const int PINO_LED_VERMELHO = 8;  // LED vermelho conectado ao pino digital 8

// Valor limite de temperatura em Celsius
const float TEMPERATURA_LIMITE = 30.0;

void setup() {
  // Inicializa comunicação serial para debugging
  Serial.begin(9600);
  
  // Configura os pinos dos LEDs como saída
  pinMode(PINO_LED_AZUL, OUTPUT);
  pinMode(PINO_LED_VERMELHO, OUTPUT);
  
  // Inicialmente desliga ambos os LEDs
  digitalWrite(PINO_LED_AZUL, LOW);
  digitalWrite(PINO_LED_VERMELHO, LOW);
  
  Serial.println("Sistema de monitoramento de temperatura iniciado!");
}

void loop() {
  // Lê o valor analógico do sensor de temperatura
  int valorSensor = analogRead(PINO_SENSOR_TEMP);
  
  // Converte o valor analógico para tensão (em volts)
  float tensao = valorSensor * (5.0 / 1023.0); // Converte para escala de 0 a 5V
  
  // Converte a tensão para temperatura em graus Celsius
  // Usa a fórmula (tensao - 0.5) * 100, específica para sensores como TMP36
  float temperatura = (tensao - 0.5) * 100.0;
  
  // Exibe a temperatura no monitor serial
  Serial.print("temperatura: ");
  Serial.print(temperatura);
  Serial.print("°C\n");
  
  // Verifica a temperatura e controla os LEDs
  if (temperatura < TEMPERATURA_LIMITE) {
    // Temperatura abaixo do limite: acende o LED azul e apaga o vermelho
    digitalWrite(PINO_LED_AZUL, HIGH);
    digitalWrite(PINO_LED_VERMELHO, LOW);
    Serial.println("LED Azul LIGADO (temperatura abaixo de 30°C)");
  } else {
    // Temperatura acima do limite: acende o LED vermelho e apaga o azul
    digitalWrite(PINO_LED_AZUL, LOW);
    
    if (temperatura > TEMPERATURA_LIMITE) {
      digitalWrite(PINO_LED_VERMELHO, HIGH);
      Serial.println("LED Vermelho LIGADO (temperatura acima de 30°C)");
    }
  }
  
  // Aguarda 100 milissegundos antes da próxima leitura
  delay(100);
}
