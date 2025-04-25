# Aula 03 – Pushbuttons e Funções no Arduino

## Introdução ao Pushbutton

O **pushbutton** é um componente essencial em projetos interativos com Arduino. Ele funciona como uma chave que:

- **Fecha** o circuito quando pressionado.
- **Abre** o circuito quando solto.

### Tipos de Botões

- **Normalmente Aberto (NA)**: conduz corrente **somente quando pressionado**.
- **Normalmente Fechado (NF)**: conduz corrente **quando solto** e **interrompe ao pressionar**.

### Funcionamento do Pushbutton com Arduino

#### Exemplo de Diagrama (NA)

- 4 conexões:
  - Arduino (pino digital)
  - GND
  - VCC
  - Saída

- **Não pressionado**: o sinal do Arduino vai para o GND.
- **Pressionado**: o circuito se fecha e o Arduino lê sinal de VCC.

### Pull-up e Pull-down

#### Pull-up:

- Botão entre pino digital e GND.
- Resistor de 4kΩ a 10kΩ entre pino digital e 5V.
- **Não pressionado** → lê 5V.
- **Pressionado** → lê 0V.

#### Pull-down:

- Botão entre pino digital e 5V.
- Resistor entre pino digital e GND.
- **Pressionado** → lê 5V.

---

## Programando com `digitalRead()`

- `pinMode(pino, INPUT)` → configura como entrada.
- `digitalRead(pino)` → lê o estado (HIGH ou LOW).

### Exemplo de uso

```cpp
int botao = 2;
int led = 13;

void setup() {
  pinMode(botao, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int estadoBotao = digitalRead(botao);
  if (estadoBotao == HIGH) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
```

Aplicações comuns: controle de interfaces, acionamento de dispositivos, jogos, alarmes e sistemas de segurança.

---

## Exercício Uso de botões

**Componentes:**

- 1 botão pushbutton  
- 2 LEDs  
- 1 Arduino

### Objetivos:

- Enquanto o botão estiver **pressionado**, o **LED 1** deve acender.
- Ao **soltar o botão**, o **LED 1** apaga.
- A **cada novo clique**, o **LED 2** alterna entre ligado e desligado.

🔗 [Acessar Tarefa 4 no Tinkercad](https://www.tinkercad.com/joinclass/8EREQRMRQ)

---

## Funções no Arduino

Funções são blocos de código organizados que executam tarefas específicas.

### Vantagens:

- **Reutilização** de código
- **Organização** e modularização
- **Facilidade de manutenção**
- **Legibilidade**

### Estrutura de uma Função

```cpp
tipo_de_retorno nome_da_funcao(parâmetros) {
  // código
  return valor; // se aplicável
}
```

- `void` é usado para funções sem retorno.

### Exemplos:

- Função sem parâmetros e sem retorno → piscar LED
- Função com parâmetros → recebe pino e tempos
- Função com retorno → soma dois valores e retorna resultado

---

## Escopo de Variáveis

- **Variáveis locais**: declaradas dentro de funções, só existem ali.
- **Variáveis globais**: declaradas fora de funções, acessíveis de qualquer lugar.

```cpp
int valorGlobal = 10;

void loop() {
  Serial.println(valorGlobal); // 10
  mostraValor();
  valorGlobal += 5;
}

void mostraValor() {
  valorGlobal += 5;
  Serial.println(valorGlobal); // 15
}
```

---

## Comparação de Código com e sem Funções

- **Sem funções**: repetição de código para cada LED.
- **Com funções**: apenas uma função `acenderLed(pino)` reutilizada.

---

## Exercício: Semáforo no Tinkercad

**Componentes:**

- 1 led vermelho 
- 1 led amarelo
- 1 led verde
- 3 resistores
- 1 placa de ensaio
- 1 arduino uno 

### Objetivos:

- Simule um semáforo simples.

🔗 [Acessar Tarefa 5 no Tinkercad](https://www.tinkercad.com/joinclass/8EREQRMRQ)
