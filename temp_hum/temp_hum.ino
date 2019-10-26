#include <DHT.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(6, 7, 2, 3, 4, 5);
#define DHTPIN 11
#define DHTTYPE DHT11
byte degree_symbol[8] =
{
  0b00111,
  0b00101,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {

  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
  lcd.setCursor(0, 0);
    lcd.write("Failed to read ");
    lcd.setCursor(0, 1);
    lcd.write("from DHT sensor!");
    return;
  }
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.print("Temperature:");
  Serial.print(t);
  Serial.print(" *C ");
  lcd.setCursor(0, 0);
  lcd.write("Temperat:");
  lcd.print(t);
  lcd.createChar(1,degree_symbol);
  lcd.setCursor(14,0);
  lcd.write(1);
  lcd.write("C");

  
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  lcd.setCursor(0, 1);
  lcd.write("Humidity:");
  lcd.print(h);
  lcd.write("%");
  delay(4000);
  lcd.clear();
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
  lcd.setCursor(0, 0);
  lcd.write("HeatInde:");
  lcd.print(hic);
  lcd.setCursor(14,0);
  lcd.write(1);
  lcd.write("C");
  lcd.setCursor(0, 1);
  lcd.write("HeatInde:");
  lcd.print(hif);
  lcd.setCursor(14,1);
  lcd.write(1);
  lcd.write("F");
  delay(4000);
  lcd.clear();
}

