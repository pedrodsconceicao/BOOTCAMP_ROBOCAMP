/*
 * Sistema de Semáforo Orientado a Objetos
 * Implementando semáforos de veículos e pedestres utilizando herança
 */

// Classe base para representar um semáforo genérico
class Semaforo {
protected:
  int pinoVermelho;
  int pinoAmarelo;
  int pinoVerde;
  
public:
  Semaforo(int vermelho, int amarelo, int verde) {
    pinoVermelho = vermelho;
    pinoAmarelo = amarelo;
    pinoVerde = verde;
    
    pinMode(pinoVermelho, OUTPUT);
    pinMode(pinoAmarelo, OUTPUT);
    pinMode(pinoVerde, OUTPUT);
  }
  
  // Método para desligar todos os LEDs do semáforo
  void apagarLeds() {
    digitalWrite(pinoVermelho, LOW);
    digitalWrite(pinoAmarelo, LOW);
    digitalWrite(pinoVerde, LOW);
  }
  
  // Acende o LED vermelho
  void acenderVermelho() {
    apagarLeds();
    digitalWrite(pinoVermelho, HIGH);
  }
  
  // Acende o LED amarelo
  void acenderAmarelo() {
    apagarLeds();
    digitalWrite(pinoAmarelo, HIGH);
  }
  
  // Acende o LED verde
  void acenderVerde() {
    apagarLeds();
    digitalWrite(pinoVerde, HIGH);
  }
};

// Classe específica para semáforos de veículos, herda de Semaforo
class SemaforoVeiculos : public Semaforo {
public:
  SemaforoVeiculos(int vermelho, int amarelo, int verde) : 
    Semaforo(vermelho, amarelo, verde) {}
};

// Classe específica para semáforos de pedestres, herda de Semaforo
class SemaforoPedestres : public Semaforo {
public:
  SemaforoPedestres(int vermelho, int verde) : 
    Semaforo(vermelho, -1, verde) {}
    
  // Sobrescreve o método acenderAmarelo pois semáforo de pedestre não tem amarelo
  void acenderAmarelo() {
    // Não faz nada, pois não há LED amarelo no semáforo de pedestres
  }
  
  // Método específico para fazer o LED verde piscar (durante a transição)
  void piscarVerde(int tempoTotal) {
    apagarLeds();
    digitalWrite(pinoVermelho, HIGH);
    
    int numPiscadas = tempoTotal * 1;  
    for (int i = 0; i < numPiscadas; i++) {
      digitalWrite(pinoVerde, HIGH);
      delay(500);
      digitalWrite(pinoVerde, LOW);
      delay(500);
    }
  }
};

// Classe controladora que coordena os dois semáforos
class ControladorSemaforo {
private:
  SemaforoVeiculos *semaforoVeiculos;
  SemaforoPedestres *semaforoPedestres;
  
public:
  ControladorSemaforo(int pinoVermelhoVeiculos, int pinoAmareloVeiculos, int pinoVerdeVeiculos,
                      int pinoVermelhoPedestres, int pinoVerdePedestres) {
    semaforoVeiculos = new SemaforoVeiculos(pinoVermelhoVeiculos, pinoAmareloVeiculos, pinoVerdeVeiculos);
    semaforoPedestres = new SemaforoPedestres(pinoVermelhoPedestres, pinoVerdePedestres);
  }
  
  ~ControladorSemaforo() {
    delete semaforoVeiculos;
    delete semaforoPedestres;
  }
  
  // Inicializa os semáforos desligando todos os LEDs
  void inicializar() {
    semaforoVeiculos->apagarLeds();
    semaforoPedestres->apagarLeds();
  }
  
  // Configura um estado do semáforo e aguarda o tempo especificado
  void configurarEstado(bool veiculosVermelho, bool veiculosAmarelo, bool veiculosVerde,
                       bool pedestresVermelho, bool pedestresVerde, int tempoSegundos) {
    semaforoVeiculos->apagarLeds();
    semaforoPedestres->apagarLeds();
    
    if (veiculosVermelho) semaforoVeiculos->acenderVermelho();
    if (veiculosAmarelo) semaforoVeiculos->acenderAmarelo();
    if (veiculosVerde) semaforoVeiculos->acenderVerde();
    
    if (pedestresVermelho) semaforoPedestres->acenderVermelho();
    if (pedestresVerde) semaforoPedestres->acenderVerde();
    
    delay(tempoSegundos * 1000);
  }
  
  // Executa o ciclo completo do semáforo
  void executarCiclo() {
    // 1. Veículos vermelho, Pedestres verde
    configurarEstado(true, false, false, false, true, 4);
    
    // 2. Veículos vermelho, Pedestres piscando verde (transição)
    semaforoPedestres->piscarVerde(5);
    
    // 3. Veículos verde, Pedestres vermelho
    configurarEstado(false, false, true, true, false, 7);
    
    // 4. Veículos amarelo, Pedestres vermelho
    configurarEstado(false, true, false, true, false, 2);
  }
};

// Variáveis globais para os pinos
const int pinoVermelhoVeiculos = 8;
const int pinoAmareloVeiculos = 9;
const int pinoVerdeVeiculos = 10;
const int pinoVermelhoPedestres = 11;
const int pinoVerdePedestres = 12;

// Instância do controlador
ControladorSemaforo *controlador;

void setup() {
  controlador = new ControladorSemaforo(
    pinoVermelhoVeiculos, pinoAmareloVeiculos, pinoVerdeVeiculos,
    pinoVermelhoPedestres, pinoVerdePedestres
  );
  
  controlador->inicializar();
}

void loop() {
  controlador->executarCiclo();
}
