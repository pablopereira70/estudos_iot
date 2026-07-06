#include <Arduino.h>
#include <DHT.h>

// Projeto: Monitor de Temperatura e Umidade com Alerta Visual (LEDs)
// Descrição: Lê dados do sensor DHT11 e aciona LEDs baseados em faixas de temperatura.

#define DHTPIN 27 
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

// Configuração dos pinos dos LEDs por cor/faixa
const int pinoLedAzul = 25;   // Frio (<= 20°C)
const int pinoLedVermelho = 33;    // Confortável (21-30°C)
const int pinoLedBranco = 12;  // Quente (31-40°C)
const int pinoLedAmarelo = 13; // Muito Quente (> 40°C)

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Inicializa todos os pinos de LED como saída
  pinMode(pinoLedAzul, OUTPUT);
  pinMode(pinoLedVermelho, OUTPUT);
  pinMode(pinoLedBranco, OUTPUT);
  pinMode(pinoLedAmarelo, OUTPUT);
  
  Serial.println("Sistema iniciado com sucesso!");
}

void loop() {
  delay(2000); // O DHT11 precisa de intervalo entre as leituras

  // Reseta o estado dos LEDs antes da nova leitura
  digitalWrite(pinoLedAzul, LOW);
  digitalWrite(pinoLedVermelho, LOW);
  digitalWrite(pinoLedBranco, LOW);
  digitalWrite(pinoLedAmarelo, LOW);

  float h = dht.readHumidity(); // Umidade
  float t = dht.readTemperature(); // Celsius
  float f = dht.readTemperature(true); // Fahrenheit

  // Validação: Se a leitura falhar, interrompe o loop e tenta novamente
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Falha na leitura do sensor!"));
    return;
  }

  // Cálculos de Sensação Térmica (Heat Index)
  float hic = dht.computeHeatIndex(t, h, false);
  float hif = dht.computeHeatIndex(f, h);

  // Exibição dos dados no Serial
  Serial.print(F("Umidade: "));
  Serial.print(h);
  Serial.print(F("% Temperatura: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F Sensação térmica: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  // Lógica de acionamento dos LEDs por faixa de temperatura
  if (t <= 20) {
    digitalWrite(pinoLedAzul, HIGH);
  } else if (t <= 30) {
    digitalWrite(pinoLedVermelho, HIGH);
  } else if (t <= 40) {
    digitalWrite(pinoLedBranco, HIGH);
  } else {
    digitalWrite(pinoLedAmarelo, HIGH);
  } 
}