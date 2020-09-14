// Código de Funcionaemnto Termômetro Arduino

#include <SPI.h>
#include <Wire.h>
#include <SparkFunMLX90614.h>     // Biblioeca do Sensor Infravermelho
#include <Adafruit_GFX.h>         // Biblioteca do Display OLED
#include <Adafruit_SSD1306.h>     // Biblioteca do Display OLED

IRTherm temperatura;

Adafruit_SSD1306 display = Adafruit_SSD1306();

void setup() {
  temperatura.begin(0x5A);         // Inicia o Sensor no endereço 0x5A
  temperatura.setUnit(TEMP_C);     // Define a temperatura em Celsius

  display.begin(0x3C);             // Inicia o Display no endereço 0x3C
  display.setTextColor(WHITE);     // Define a cor dos caracteres
  display.clearDisplay();          // Limpa o Display
  display.setCursor(0, 10);        // Posiciona o cursor
  display.setTextSize(2);          // Define tamanho da fonte
  display.println(" USINAINFO ");  // Imprime ...
  display.display();
  delay(2000);                     // Aguarda 2 segundos
  display.clearDisplay();          // Limpa o Display
}

void loop() {
  if (temperatura.read())  {
    display.setCursor(0, 0);       // Posiciona o cursor
    display.setTextSize(1);        // Define tamanho da fonte

    display.print("Objeto: " + String(temperatura.object(), 2));

    display.println(" Graus");     // Imprime ...
    display.println("");           // Cria uma linha em branco

    display.print("Ambiente: " + String(temperatura.ambient(), 2));

    display.print(" Graus");       // Imprime ...
    display.display();
    delay(2000);                   // Aguarda 2 segundos
    display.clearDisplay();        // Limpa o Display
  }

  delay(1500);
}
