#define LED1_PIN 13  // Define o pino do LED1 (vermelho)
#define LED2_PIN 12  // Define o pino do LED2 (azul)
int ciclo = 0;
  
void setup() {
  pinMode(LED1_PIN, OUTPUT);  // Define o pino do LED1 como saída
  pinMode(LED2_PIN, OUTPUT);  // Define o pino do LED2 como saída

}

void loop() {
  
  if(ciclo < 10){
  // Parte 1: Sirene "Ligada"
  digitalWrite(LED1_PIN, HIGH);  // Acende o LED1 (vermelho)
  digitalWrite(LED2_PIN, LOW);   // Apaga o LED2 (azul)
  delay(150);  // Tempo curto para simular o "flash" do LED1

  digitalWrite(LED1_PIN, LOW);   // Apaga o LED1 (vermelho)
  digitalWrite(LED2_PIN, HIGH);  // Acende o LED2 (azul)
  delay(150);  // Tempo curto para simular o "flash" do LED2

  // Parte 2: Sirene "Desligada" por um curto tempo
  digitalWrite(LED1_PIN, LOW);   // Apaga o LED1 (vermelho)
  digitalWrite(LED2_PIN, LOW);   // Apaga o LED2 (azul)
  delay(75);  // Tempo de pausa entre os flashes
  }
  
  else {
      // Parte 1: Sirene "Ligada"
  digitalWrite(LED1_PIN, HIGH);  // Acende o LED1 (vermelho)
  digitalWrite(LED2_PIN, LOW);   // Apaga o LED2 (azul)
  delay(400);  // Tempo curto para simular o "flash" do LED1

  digitalWrite(LED1_PIN, LOW);   // Apaga o LED1 (vermelho)
  digitalWrite(LED2_PIN, HIGH);  // Acende o LED2 (azul)
  delay(400);  // Tempo curto para simular o "flash" do LED2

  // Parte 2: Sirene "Desligada" por um curto tempo
  digitalWrite(LED1_PIN, LOW);   // Apaga o LED1 (vermelho)
  digitalWrite(LED2_PIN, LOW);   // Apaga o LED2 (azul)
  delay(200);  // Tempo de pausa entre os flashes
  }
  
  if(ciclo > 15){
    ciclo = 0;
  }
  
  ciclo = ciclo + 1;	
}

