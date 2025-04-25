// Pino do botão pushbutton
#define buttonPin 2      
// Pino do primeiro LED (acende enquanto pressionado)
#define ledPin1 8        
// Pino do segundo LED (alterna estado)
#define ledPin2 9        

int buttonState = LOW;        // Estado atual do botão
int lastButtonState = LOW;    // Estado anterior do botão
int ledState2 = LOW;          // Estado do segundo LED

void setup() {
  // Configuração dos pinos
  pinMode(buttonPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // Lê o estado atual do botão
  buttonState = digitalRead(buttonPin);

  // Controla o primeiro LED (acende apenas quando o botão está pressionado)
  digitalWrite(ledPin1, buttonState);

  // Verifica se houve transição de estado do botão (de solto para pressionado)
  if (buttonState == HIGH && lastButtonState == LOW) {
    // Alterna o estado do segundo LED
    ledState2 = !ledState2;
    digitalWrite(ledPin2, ledState2);
    
    // Pequeno atraso para evitar detecções múltiplas por causa do debounce
    delay(50);
  }

  // Salva o estado atual do botão para a próxima iteração
  lastButtonState = buttonState;
}
