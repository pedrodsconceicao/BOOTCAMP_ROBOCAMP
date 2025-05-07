# Aula 05 – Programação Orientada a Objetos no Arduino

## Introdução à Programação Orientada a Objetos (POO)
A **Programação Orientada a Objetos** é um paradigma de programação que organiza o código em torno de objetos, permitindo:
- **Estruturar** código de forma mais coesa
- **Modelar** problemas de forma mais próxima ao mundo real
- **Reutilizar** código de forma mais eficiente
- **Simplificar** a manutenção de projetos

### Objetivo da Aula
- Apresentar conceitos básicos de POO
- Entender a diferença entre paradigma estruturado e orientado a objetos
- Compreender os conceitos de classes e objetos
- Conhecer os pilares da orientação a objetos, com foco em herança

---

## O que é um Paradigma de Programação?

### Definição
- **Forma menos abstrata**: Um jeito de organizar e escrever código para resolver problemas com um computador
- **Forma mais abstrata**: Imposição de disciplina sobre o estilo de escrita de código, restringindo certas ações para promover organização, clareza e manutenção

### Principais Paradigmas
- **Paradigma Estruturado**
- **Paradigma Funcional**
- **Paradigma Orientado a Objetos**

---

## Paradigma Estruturado vs Orientado a Objetos

### Paradigma Estruturado
- Baseado em **funções** que manipulam **estruturas de dados**
- Elementos separados que cooperam por convenção
- Exemplo em C:
```c
struct Carro {
    char modelo[50];
    int ano;
    float kilometragem;
};

// Função construtora
Carro* newCarro(char* modelo, int ano) {
    Carro* carro = malloc(sizeof(Carro));
    strcpy(carro->modelo, modelo);
    carro->ano = ano;
    carro->kilometragem = 0;
    return carro;
}

// Função que atua sobre a estrutura
void carro_andarKm(Carro* carro, int km) {
    carro->kilometragem += km;
}

// Uso
int main() {
    Carro* meuCarro = newCarro("Fusca", 1980);
    carro_andarKm(meuCarro, 100);
    printf("Km: %.2f\n", meuCarro->kilometragem);
    free(meuCarro);
    return 0;
}
```

### Paradigma Orientado a Objetos
- Baseado em **classes** que contêm **atributos** e **métodos**
- Elementos agrupados de forma mais coesa
- Exemplo em C++:
```cpp
class Carro {
public:
    char modelo[50];
    int ano;
    float kilometragem;
    
    // Construtor
    Carro(char* _modelo, int _ano) {
        strcpy(modelo, _modelo);
        ano = _ano;
        kilometragem = 0;
    }
    
    // Método
    void andarKm(int km) {
        kilometragem += km;
    }
};

// Uso
int main() {
    Carro* carro = new Carro("Fusca", 1980);
    carro->andarKm(100);
    cout << "Km: " << carro->kilometragem << endl;
    delete carro;
    return 0;
}
```

---

## Classes vs Objetos

### Classe
- **Definição**: Um contrato de comportamentos e atributos
- **Analogia**: Uma classe está para um objeto como uma **receita** está para um **produto**
- É um modelo ou plano para criar objetos

### Objeto
- **Definição**: Uma instância concreta de uma classe
- Possui valores específicos para os atributos definidos na classe
- Pode executar os comportamentos (métodos) definidos na classe

---

## Código Orientado a Objetos em C++

### Declaração de Classe
```cpp
class Carro {
public:  // Bloco de declaração de nível de acesso
    char modelo[50];
    int ano;
    float kilometragem;
    
    // Construtor
    Carro(char* _modelo, int _ano) {
        strcpy(modelo, _modelo);
        ano = _ano;
        kilometragem = 0;
    }
    
    // Método
    void andarKm(int km) {
        kilometragem += km;
    }
};
```

### Criação de Objetos
```cpp
// Criando um objeto da classe Carro
Carro* carro = new Carro("Fusca", 1980);

// Chamando método do objeto
carro->andarKm(100);
```

### Níveis de Acesso
- **public**: Atributos e métodos acessíveis de qualquer lugar
- **private**: Atributos e métodos acessíveis apenas dentro da classe
- **protected**: Atributos e métodos acessíveis dentro da classe e suas subclasses

---

## Composição

### Definição
- Uma classe pode **conter** objetos de outras classes como atributos
- Estabelece uma relação "tem um" ou "possui um"

### Exemplo
```cpp
class Pessoa {
public:
    char nome[50];
    int idade;
    Carro* carro;  // Composição: Pessoa tem um Carro
    
    Pessoa(char* _nome, int _idade, Carro* _carro) {
        strcpy(nome, _nome);
        idade = _idade;
        carro = _carro;
    }
    
    void dirigir(int km) {
        carro->andarKm(km);
    }
};

// Uso
int main() {
    Carro* meuCarro = new Carro("Fusca", 1980);
    Pessoa* eu = new Pessoa("João", 30, meuCarro);
    
    eu->dirigir(100);  // Pessoa dirige o carro
    
    delete meuCarro;
    delete eu;
    return 0;
}
```

---

## Herança

### Definição
- Permite que uma classe **herde** atributos e métodos de outra classe
- Estabelece uma relação "é um" ou "é um tipo de"
- Classes derivadas podem especializar ou estender funcionalidades da classe base

### Exemplo
```cpp
// Classe base/pai
class Automovel {
public:
    char modelo[50];
    int ano;
    float kilometragem;
    
    Automovel(char* _modelo, int _ano) {
        strcpy(modelo, _modelo);
        ano = _ano;
        kilometragem = 0;
    }
    
    void andarKm(int km) {
        kilometragem += km;
    }
};

// Classe derivada/filha
class Carro : public Automovel {
public:
    int numPortas;
    
    Carro(char* _modelo, int _ano, int _numPortas) 
        : Automovel(_modelo, _ano) {  // Chamada ao construtor da classe pai
        numPortas = _numPortas;
    }
};

// Outra classe derivada
class Moto : public Automovel {
public:
    int cilindradas;
    
    Moto(char* _modelo, int _ano, int _cilindradas)
        : Automovel(_modelo, _ano) {
        cilindradas = _cilindradas;
    }
};
```

---

## Exercício: Semáforo com Pedestre Orientado a Objetos

### Objetivo
Criar um sistema de semáforo com pedestres usando programação orientada a objetos no Arduino.


🔗 [Acessar Tarefa no Tinkercad](https://www.tinkercad.com/joinclass/8EREQRMRQ)

---

## Recapitulação

### Conceitos Apresentados
- **Paradigma de Programação**: Forma de estruturar e organizar código
- **Programação Orientada a Objetos**: Código organizado em torno de objetos
- **Classes**: Modelos ou contratos para criar objetos
- **Objetos**: Instâncias concretas de classes
- **Composição**: Relação "tem um" entre classes
- **Herança**: Relação "é um" entre classes
- **Encapsulamento**: Controle de acesso aos atributos e métodos

### Benefícios da POO
- Reutilização de código
- Organização mais coesa
- Manutenção simplificada
- Modelagem mais próxima do mundo real
