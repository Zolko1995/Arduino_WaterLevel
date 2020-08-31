#include<Wire.h> //Wire könyvtár beillesztése az I2C busz használatához
#include<LiquidCrystal_I2C.h> //Az I2C Folyékony kristályos LCD kijelző kezelő könyvtára
LiquidCrystal_I2C lcd(0x27, 16, 2); //Az általunk használt kijelző karakterkészlete 16 karakter és 2 sor

int ertek = 0;
const int sensor = A0; //konstans globális integer típusú változó mely a folyadékszint méró szenzor pin-jét tárolja

void setup()
{
  lcd.init(); //Az LCD kijelző inicializálása
  lcd.backlight(); //Az LCD kijelző háttérvilágításának bekapcsolása
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("FOLYADEKSZINT:");
  Serial.begin(9600); //A soros porton történő kommunikáció bitrátája
}

void loop() //ciklus
{
  lcd.setCursor(0, 0);
  lcd.print("FOLYADEKSZINT:");
  ertek = analogRead(sensor); //A szenzor értékének beolvasása és változóban tárolása
  Serial.println(ertek); //A beolvasott és változóban tárolt érték kiíratása a soros portra
  if (ertek <= 100) //Feltétel vizsgálat, ha a beolvasott érték kisebb vagy egyenlő, mint 100 akkor:
  {
    Serial.println("EMPTY"); //Megadott karakterlánc kiíratása
    lcd.print(" "); //Üres karakterlánc kiíratása
    lcd.setCursor(0, 1); //Kurzor pozicionálás ez esetben 0. karakter a 1. sorban
    lcd.print("URES"); //Megadott karakterlánc kiíratása
  }
  else if (ertek > 130 & ertek <= 250) //Feltétel vizsgálat:
  {
    Serial.println("LOW"); //Megadott karakterlánc kiíratása
    lcd.print(" "); //Üres karakterlánc kiíratása
    lcd.setCursor(0, 1); //Kurzor pozicionálás ez esetben 0. karakter a 1. sorban
    lcd.print("ALACSONY"); //Megadott karakterlánc kiíratása
  }
  else if (ertek > 260 & ertek <= 310) //Feltétel vizsgálat:
  {
    Serial.println("MEDIUM"); //Megadott karakterlánc kiíratása
    lcd.print(" "); //Üres karakterlánc kiíratása
    lcd.setCursor(0, 1); //Kurzor pozicionálás ez esetben 0. karakter a 1. sorban
    lcd.print("KOZEPES"); //Megadott karakterlánc kiíratása
  }
  else if (ertek > 315) //Feltétel vizsgálat:
  {
    Serial.println("HIGH"); //Megadott karakterlánc kiíratása
    lcd.print(" "); //Üres karakterlánc kiíratása
    lcd.setCursor(0, 1); //Kurzor pozicionálás ez esetben 0. karakter a 1. sorban
    lcd.print("MAGAS"); //Megadott karakterlánc kiíratása
  }
  delay(500); //A szenzor olvasásának intervalluma 0.5 másodperc
  lcd.clear(); //Az LCD kijelző tartalmának a törlése
}
