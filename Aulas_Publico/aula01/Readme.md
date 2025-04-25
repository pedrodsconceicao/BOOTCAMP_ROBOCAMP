# Bootcamp de Eletrônica e Arduino Básico - Aula 01

## 👋 Apresentação

Fala galera! Sejam muito bem-vindos ao nosso primeiro **Bootcamp da Liga de Robótica da Unicamp**. 🎉

É um enorme prazer receber vocês nesse treinamento de **Eletrônica e Arduino Básico**, desenvolvido como parte do processo de formação dos novos membros da **ROBOCAMP**, e agora aberto ao público! Nosso objetivo é introduzir vocês ao universo da **eletrônica**, **robótica** e **programação** de forma leve, prática e acessível.

Este projeto também está vinculado à disciplina **TT060 - Gestão de Projetos**, ministrada pelo Professor **Marcos Borges** na FT, o que nos permite emitir **certificados de horas complementares** para quem participar ativamente!

## 🧑‍🏫 Como vai funcionar?

O bootcamp será composto por **7 aulas online** via Google Meet. Cada encontro será expositivo, com apresentação de conteúdo através de **slides**, realização de **exercícios práticos** na plataforma de simulação **Tinkercad**, e **quizzes** ao final.

📌 Para receber o certificado, você precisa:
- Entregar **75% dos exercícios**
- Responder **75% dos quizzes**

**Prazos:**
- Quizzes: abertos por 1 hora após a aula
- Exercícios: prazo de algumas horas após o encontro

Correções serão feitas com foco no aprendizado — se sua entrega estiver próxima da proposta, ela será considerada válida ✅

---

## 🧠 Conteúdo da Aula 01

### 🤖 O que é Robótica?

A **robótica** combina conhecimentos de **eletrônica, mecânica e computação** para construir sistemas que **interagem com o mundo físico**.

Um robô pode ser definido por:
- **Sensores**: captam informações do ambiente
- **Atuadores**: realizam ações
- **Processador/Microcontrolador**: toma decisões com base nos dados

**Robôs** não precisam ter forma humana! Braços mecânicos industriais, aspiradores automáticos e até assistentes virtuais são exemplos.

---

### 🧬 Microcontroladores: O cérebro dos sistemas

Microcontroladores são **pequenos computadores** que recebem dados dos sensores, processam essas informações e controlam os atuadores. Exemplos:
- **PIC**
- **ESP32**
- **Arduino**

---

### 🔌 O que é o Arduino?

O **Arduino** é uma plataforma de **prototipagem eletrônica** open-source com foco em **educação, acessibilidade e baixo custo**. Ideal para iniciantes e entusiastas!

**Componentes da plataforma:**
- **Hardware**: Placa Arduino (UNO, Nano, Mega)
- **Software (IDE)**: Gratuito, usado para programar a placa
- **Linguagem**: Baseada em C/C++

**Principais vantagens:**
- Baixo custo 💸
- Fácil de aprender 👶
- Comunidade ativa 🌎
- Muitos tutoriais disponíveis 📚

---

### 🧩 Conhecendo a Placa Arduino UNO

| Componente            | Função                                                                 |
|-----------------------|------------------------------------------------------------------------|
| Botão Reset           | Reinicia o código da placa                                             |
| Conector USB          | Comunicação com o PC + alimentação                                     |
| Cristal Oscilador     | "Relógio" que define o tempo de execução                               |
| Chip ATmega328P       | O cérebro do Arduino                                                   |
| LED de Alimentação    | Indica que a placa está ligada                                         |
| Pinos Digitais        | Entrada/Saída de sinais digitais                                       |
| Pinos Analógicos      | Entrada de sinais analógicos                                           |
| Pinos de Alimentação  | 3.3V, 5V, GND e VIN                                                    |
| ICSP                  | Comunicação serial para gravação de código                            |

---

### 💻 Lógica de Programação no Arduino

Todo programa no Arduino possui duas funções principais:

```cpp
void setup() {
  // Executado uma vez ao ligar
}

void loop() {
  // Executado em repetição enquanto o Arduino estiver ligado
}


## Alguns métodos importantes:

```cpp
pinMode(pino, modo)      // define se o pino será entrada ou saída
digitalWrite(pino, valor) // define nível lógico (HIGH ou LOW)
delay(tempo)              // pausa o código por tempo em milissegundos
```

---

## 🧪 Primeiros Passos com o TinkerCAD

O TinkerCAD é uma plataforma online gratuita da Autodesk para modelagem 3D e simulação de circuitos.

### 🔗 Link da sala:
[https://www.tinkercad.com/joinclass/8EREQRMRQ](https://www.tinkercad.com/joinclass/8EREQRMRQ)

---

### 📋 O que fazer:

1. Criar uma conta (pessoal ou estudante)  
2. Acessar a aba **"Classes" > "Bootcamp Robocamp"**  
3. Ir para a **Tarefa 1**  
4. Montar o circuito com:
   - Arduino Uno R3  
   - LED  
   - Resistor de 220Ω  

⚠️ **Lembre-se**: o LED tem polaridade. O **ânodo (positivo)** é a perninha **maior**, e o **cátodo (negativo)** é a **menor**.

---

## 🧑‍💻 Escrevendo o Código no TinkerCAD

Clique em **"Código" > "Texto"** e escreva seu programa:

```cpp
void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
```

Clique em **"Iniciar Simulação"** para ver o LED piscando!

---

## ❓ Dúvidas?

Se ficou alguma dúvida sobre o conteúdo, plataforma ou estrutura do curso, levante a mão durante a aula ou entre em contato com a gente.

Estamos aqui para ajudar e aprender juntos 🤝

---

**Bora codar e criar?** 💡🤖  
Nos vemos na próxima aula!