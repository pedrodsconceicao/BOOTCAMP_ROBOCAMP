# Aula 04 – Bootcamp de Robótica / Arduino Básico

## Introdução aos Sensores
Os **sensores** são componentes fundamentais em projetos de robótica e automação com Arduino. Eles funcionam como os "sentidos" do sistema, permitindo:
- **Detectar** mudanças no ambiente
- **Converter** fenômenos físicos em sinais elétricos
- **Transmitir** informações para o microcontrolador

### Para que servem sensores em robótica?
- Permitem **interação com o ambiente**
- Possibilitam **tomada de decisões** baseadas em condições externas
- Exemplos de aplicações:
  - Robôs seguidores de linha com sensores infravermelhos
  - Braços robóticos com sensores de força/posição
  - Robôs autônomos com sensores ultrassônicos/proximidade

---

## Tipos de Sensores

### Sensores Analógicos
- Geram **sinal contínuo** com valores intermediários
- Leitura com `analogRead()`, retornando valores entre **0 e 1023**
- Conectados aos pinos: **A0 a A5**
- Exemplos:
  - **LDR** (sensor de luz)
  - **LM35** (sensor de temperatura)
  - **Potenciômetro** (resistência variável)

### Sensores Digitais
- Geram **sinal binário** (apenas 0 ou 1)
- Leitura com `digitalRead()`
- Conectados aos pinos: **D2 a D13**
- Exemplos:
  - **Botão** (pushbutton)
  - **Sensor PIR** (movimento)
  - **Sensor de fim de curso**

---

## Lendo Sensores com Arduino

### Leitura Analógica
```cpp
int valorSensor = analogRead(pinoAnalogico); // Retorna valor entre 0-1023
```

### Leitura Digital
```cpp
int estadoSensor = digitalRead(pinoDigital); // Retorna HIGH ou LOW
```

### Exibindo Valores no Monitor Serial
```cpp
void setup() {
  Serial.begin(9600); // Inicia comunicação serial
}

void loop() {
  int valor = analogRead(A0);
  Serial.print("Valor do sensor: ");
  Serial.println(valor);
  delay(500); // Aguarda meio segundo entre leituras
}
```

---

## Exemplo: Sensor de Luz (LDR) com LED

### Componentes Necessários
- 1 LDR (Light Dependent Resistor)
- 1 Resistor de 10kΩ (para o divisor de tensão)
- 1 LED
- 1 Resistor de 220Ω (para o LED)
- 1 Arduino UNO
- Jumpers e protoboard

### Circuito
- LDR e resistor de 10kΩ formando um **divisor de tensão**
- Saída do divisor conectada a uma entrada analógica (A0)
- LED conectado a um pino digital (D13) através do resistor de 220Ω

### Código
```cpp
// Definição dos pinos
int ldrPin = A0;   // Pino analógico do sensor de luz
int ledPin = 13;   // Pino digital do LED

// Variáveis
int ldrValor = 0;  // Valor lido do LDR
int limiar = 500;  // Valor limiar para acender/apagar o LED

void setup() {
  pinMode(ledPin, OUTPUT);  // Define LED como saída
  Serial.begin(9600);       // Inicia comunicação serial
}

void loop() {
  // Lê o valor do sensor de luz
  ldrValor = analogRead(ldrPin);
  
  // Exibe o valor no monitor serial
  Serial.print("Intensidade de luz: ");
  Serial.println(ldrValor);
  
  // Controla o LED com base na leitura do sensor
  if (ldrValor < limiar) {
    digitalWrite(ledPin, HIGH);  // Acende o LED quando está escuro
  } else {
    digitalWrite(ledPin, LOW);   // Apaga o LED quando há luz
  }
  
  delay(100);  // Pequena pausa para estabilidade
}
```

---

## Exemplo: Potenciômetro para Controle de Brilho do LED

### Componentes Necessários
- 1 Potenciômetro (10kΩ)
- 1 LED
- 1 Resistor de 220Ω
- 1 Arduino UNO
- Jumpers e protoboard

### Circuito
- Potenciômetro conectado a uma entrada analógica (A0)
- LED conectado a um pino PWM (D9) através do resistor de 220Ω

### Código
```cpp
// Definição dos pinos
int potPin = A0;    // Pino do potenciômetro
int ledPin = 9;     // Pino PWM para o LED

// Variáveis
int potValor = 0;   // Valor lido do potenciômetro
int brilho = 0;     // Valor do brilho do LED

void setup() {
  pinMode(ledPin, OUTPUT);  // Define LED como saída
  Serial.begin(9600);       // Inicia comunicação serial
}

void loop() {
  // Lê o valor do potenciômetro
  potValor = analogRead(potPin);
  
  // Converte o valor (0-1023) para faixa PWM (0-255)
  brilho = map(potValor, 0, 1023, 0, 255);
  
  // Controla o brilho do LED
  analogWrite(ledPin, brilho);
  
  // Exibe valores no monitor serial
  Serial.print("Potenciômetro: ");
  Serial.print(potValor);
  Serial.print(" | Brilho LED: ");
  Serial.println(brilho);
  
  delay(100);  // Pequena pausa para estabilidade
}
```

---

## Introdução ao Sensor de Temperatura

### Sensor LM35
- Sensor de temperatura de precisão com saída analógica
- Escala calibrada em graus Celsius
- Faixa de operação: -55°C a 150°C
- Precisão: ±0.5°C (em temperatura ambiente)

### Fórmula de Conversão
```
Temperatura (°C) = (leitura analógica * 5.0 / 1023) * 100
```

### Exemplo Básico
```cpp
int sensorTemp = A0;  // Pino do sensor
float temperatura;    // Variável para armazenar a temperatura

void setup() {
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(sensorTemp);
  
  // Conversão para temperatura em °C
  temperatura = (leitura * 5.0 / 1023) * 100;
  
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  
  delay(1000);  // Aguarda 1 segundo
}
```

---

## Exercício: Sistema de Monitoramento com Múltiplos Sensores

**Componentes:**
- 1 LDR (sensor de luz)
- 1 Potenciômetro (como simulador de sensor)
- 2 LEDs (vermelho e verde)
- Resistores necessários
- 1 Arduino UNO

### Objetivos:
- Criar um sistema que monitora luz ambiente e uma variável ajustável
- O LED verde deve acender quando houver luz suficiente
- O LED vermelho deve acender quando o valor do potenciômetro ultrapassar um limiar
- Exibir todas as leituras no monitor serial

🔗 [Acessar Tarefa 6 no Tinkercad](https://www.tinkercad.com/joinclass/8EREQRMRQ)

---

## Recapitulação da Aula Anterior

### Pushbutton e Funções no Arduino
- **Pushbutton**: componente interativo
  - Tipos: Normalmente Aberto (NA) e Normalmente Fechado (NF)
  - Funcionamento com resistores Pull-up e Pull-down
  - Leitura de estado com `digitalRead()`

### Funções em Arduino
- Organização e reutilização de código
- Estrutura: `tipo_retorno nome_funcao(parametros)`
- Exemplo: `void piscaLed(int pino, int tempo)`

### Exercício Anterior
- LED 1 acendendo enquanto botão estiver pressionado
- LED 2 alternando estado a cada novo clique

---

## Dicas para Projetos com Sensores

1. **Calibração**: Ajuste os limiares com base nas condições reais
2. **Filtragem**: Use médias de leituras para reduzir ruídos
3. **Debounce**: Implemente para sensores digitais quando necessário
4. **Divisores de tensão**: Calcule resistores adequados para cada sensor
5. **Documentação**: Anote os valores típicos para referência futura
