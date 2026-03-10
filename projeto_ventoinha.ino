// ===== BIBLIOTECA LCD =====
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 7, 4, 3, 2);


// ===== PINOS =====
int pinFan = 5;
int pinSensor = A4;


// ===== VARIÁVEIS =====
float temperatura = 0;
float tensao = 0;
float leitura_sensor = 0;


// ===== SETUP =====
void setup() {

Serial.begin(9600);

lcd.begin(16, 2);
lcd.clear();

pinMode(pinFan, OUTPUT);
pinMode(pinSensor, INPUT);

}


// ===== LOOP PRINCIPAL =====
void loop() {  

leitura_sensor = analogRead(pinSensor);
tensao = 5 * leitura_sensor / 1023;
temperatura = (tensao - 0.5) * 100;

Serial.println(temperatura);


// ===== CONTROLE DA VENTOINHA =====
if (temperatura > 21) {

lcd.setCursor(0,1);
lcd.print("Vent ligado !");
digitalWrite(pinFan, HIGH);

} 

else {

lcd.setCursor(0,1);
lcd.print("Vent desligado !");
digitalWrite(pinFan, LOW);

}

delay(1000);


// ===== EXIBIÇÃO NO LCD =====
lcd.clear();
lcd.print("Temp.: ");
lcd.print(temperatura);
lcd.write(B11011111);
lcd.print("C");

}
