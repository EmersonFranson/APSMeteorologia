#include "DHT.h"        // Biblioteca para DHT
#include <SFE_BMP180.h> // Biblioteca para BMP
#define DHTPIN 4        // Pino de dados utilizado no DHT

#define DHTTYPE DHT22   // Tipo de sendor DHT
SFE_BMP180 pressure;


DHT dht(DHTPIN, DHTTYPE); // instnaciando metodo DHT, passando com prarametro o tipo de sensor e o pino utilizado

void setup() {
  Serial.begin(9600); //iniciando comunicaçao serial
  pressure.begin();   //inicianco sensor de pressão
 
  dht.begin();        //iniciando sensor DHT
 }

void loop() {

  float h = dht.readHumidity(); //criando variavel para humidade e atribuindo o valor do DHR
  double t = dht.readTemperature(); //criando variavel para temperatura e atribuino o valor do DHT
  double P; //crinadi variavel para pressão atmosferica
pressure.getPressure(P,t); // atribuindo valor para a variavel de sensor atmosferica, passando como parametro a temperatura


  
  if (isnan(t) || isnan(h)) { // verificando se o DHT tem leitura valida
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print("\n");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.print("\n");
    Serial.print("Pressure BMP");
    Serial.println(P);
    Serial.print("\n\n\n\n");
    delay(10000);
    
  }
}
