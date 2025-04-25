# Aula 02 - Introdução à Protoboard, Lei de Ohm e Programação com Arduino

## Objetivo da Aula

Nesta aula, damos continuidade aos estudos da plataforma Arduino com os seguintes objetivos:

- Apresentar a **protoboard**, ferramenta fundamental para montagem e testes de circuitos.
- Introduzir conceitos **básicos de eletrônica**: tensão, corrente e resistência.
- Compreender a **Lei de Ohm** e como aplicá-la no dimensionamento de resistores.
- Iniciar os estudos de **constantes, variáveis** e **estruturas condicionais** na programação Arduino.
- Realizar **exercícios práticos** na plataforma Tinkercad.

---

## Protoboard: O Que É e Como Funciona

A **protoboard** é uma placa de ensaio utilizada para montar circuitos sem necessidade de solda.

### Conexões na Protoboard

- **Linhas horizontais (extremidades)**: conectadas internamente, indicadas pelas cores:
  - **Vermelho (positivo)**
  - **Preto (negativo/terra)**

- **Colunas centrais (malha de furos A-J)**:
  - Conectadas **verticalmente**, de A a E e de F a J, separadas pelo canal central.
  - Ex: Todos os furos da coluna "1" (de A a E) estão conectados entre si.

> Isso permite montar circuitos organizados e reutilizáveis com facilidade.

---

## Conceitos Fundamentais de Eletrônica

### Tensão (V)
Diferença de potencial entre dois pontos. É o que "empurra" os elétrons no circuito.

### Corrente (I)
Fluxo de elétrons que percorre o circuito. Medido em **Ampères (A)**.

### Resistência (R)
Dificuldade que um material oferece à passagem da corrente. Medido em **Ohms (Ω)**.

---

## A Primeira Lei de Ohm

A **Lei de Ohm** relaciona as três grandezas acima:

```
V = R × I
```

Ou seja:
```
R = V / I
```

### Exemplo Prático

Se um LED funciona com 2V e 20mA (0.02A), e o alimentamos com uma fonte de 5V:

```
R = (5V - 2V) / 0.02A = 150Ω
```

> Esse é o valor **mínimo** para evitar queimar o LED. Valores maiores diminuem o brilho, valores menores podem danificá-lo.

---

## Exercício 1 - Protoboard + Resistores

**Objetivo:** Montar um circuito com 3 LEDs e resistores, dimensionados para uma fonte de **9V**.

- Plataforma: [Tinkercad](https://www.tinkercad.com/joinclass/8EREQRMRQ)
- Prazo: **Hoje até as 23h59**

---

## Constantes e Variáveis na Programação

### Constantes

São valores que **não mudam** durante a execução do programa.

#### Maneiras de definir:
```cpp
const int pinoLed = 10;
#define TEMPO_CICLO 1000
```

> Usadas para representar pinos, limites e configurações fixas.

#### Constantes do Arduino:
- `true`, `false`
- `HIGH`, `LOW`
- `INPUT`, `OUTPUT`

---

### Variáveis

São espaços de memória para armazenar **valores que podem mudar**.

#### Exemplo:
```cpp
int temperatura;
```

> Existem vários tipos: `int`, `float`, `char`, `double`, etc.

---

## Estruturas Condicionais

### if / else
Permite executar blocos de código **dependendo de uma condição**:

```cpp
if (temperatura < tempSeguranca) {
  digitalWrite(led, HIGH);
} else {
  digitalWrite(led, LOW);
}
```

---

## Comparando Dois Códigos

### Código 1 (Sem constantes)

```cpp
pinMode(10, OUTPUT);
int L = analogRead(A2);
if (L < 50) {
  digitalWrite(10, HIGH);
}
```

Difícil de entender o propósito e fácil de errar.

---

### Código 2 (Com constantes)

```cpp
#define motor 10
#define sensorTemp A2
const int tempSeguranca = 50;

pinMode(motor, OUTPUT);
int temperatura = analogRead(sensorTemp);

if (temperatura < tempSeguranca) {
  digitalWrite(motor, HIGH);
}
```

> Muito mais **legível** e **fácil de manter**.

---

## Exercício 2 - Sirene Policial

**Objetivo:** Criar uma sirene que simula uma viatura com dois LEDs piscando alternadamente.

- Plataforma: Tinkercad
- Link e imagem do circuito serão enviados no momento da atividade.

---

## Dúvidas?

Durante toda a aula, fique à vontade para levantar a mão ou enviar perguntas no chat!

---

## Recursos

- Plataforma Tinkercad: [https://www.tinkercad.com/joinclass/8EREQRMRQ](https://www.tinkercad.com/joinclass/8EREQRMRQ)
- Material de apoio e soluções serão enviados no **Drive** após o prazo das atividades.

---

**Bons estudos!**

## Equipe Training 
Pedro Dos Santos Conceição - **Diretor de Treinamento**
