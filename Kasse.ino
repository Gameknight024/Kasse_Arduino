#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// Deklaration des LCD-Objekts mit der richtigen Adresse (0x27) und den Dimensionen (16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4; // Anzahl der Reihen des Keypads
const byte COLS = 4; // Anzahl der Spalten des Keypads

// Definition der Keymap
char hexaKeys[ROWS][COLS] = {
  {'D', '#', '0', '*'},
  {'C', '9', '8', '7'},
  {'B', '6', '5', '4'},
  {'A', '3', '2', '1'}

};

// Definition der Pinbelegung
byte rowPins[ROWS] = {6, 7, 8, 9};
byte colPins[COLS] = {2, 3, 4, 5};

// Initialisierung des Keypads
Keypad Tastenfeld = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

char Taste;
int Preis = 0; // Richtig deklarierter Preis

// Anzahl der einzelnen Fruchtdrücke
int anzahlApfel = 0;
int anzahlBanane = 0;
int anzahlMaracuja = 0;
int anzahlBirne = 0;
int anzahlKiwi = 0;
int anzahlMango = 0;
int anzahlJoannisbeere = 0;
int anzahlOrange = 0;
int anzahlBK = 0;
int anzahlGP = 0;


void setup() {
  Serial.begin(9600);
  lcd.init();        // Initialisierung des LCD
  lcd.backlight();   // Hintergrundbeleuchtung einschalten
  lcd.clear();       // Bildschirm löschen
}

void loop() {
  Taste = Tastenfeld.getKey();

  if (Taste) {
    Serial.print(Taste);
    Serial.print(" wurde gedrückt");
    Serial.println();

    if (Taste == '1') {
      anzahlApfel++;
      Preis = Preis + 1;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Apfel ");
      lcd.print(anzahlApfel);
    } 
    else if (Taste == '2') {
      anzahlBanane++;
      Preis = Preis + 1;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Banane ");
      lcd.print(anzahlBanane);
    }
    else if (Taste == '3') {
      anzahlMaracuja++;
      Preis = Preis + 3;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Maracuja ");
      lcd.print(anzahlMaracuja);
    }
    else if (Taste == '4') {
      anzahlBirne++;
      Preis = Preis + 2;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Birne ");
      lcd.print(anzahlBirne);
    }
    else if (Taste == '5') {
      anzahlKiwi++;
      Preis = Preis + 2;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Kiwi ");
      lcd.print(anzahlKiwi);
    }
    else if (Taste == '6') {
      anzahlMango++;
      Preis = Preis + 5;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Mango ");
      lcd.print(anzahlMango);
    }
    else if (Taste == '7') {
      anzahlJoannisbeere++;
      Preis = Preis + 2;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Johannisbeere ");
      lcd.print(anzahlJoannisbeere);
    }
    else if (Taste == '8') {
      anzahlOrange++;
      Preis = Preis + 2;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Orange ");
      lcd.print(anzahlOrange);
    }
    else if (Taste == '9') {
      anzahlBK++;
      Preis = Preis + 10;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Bunter Korb ");
      lcd.print(anzahlBK);
    }
    else if (Taste == '0'){
      anzahlGP++;
      Preis = Preis + 16;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Guenthers Pack ");
      lcd.print(anzahlGP);
    }
    else if (Taste == 'A') {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Zu Zahlen: ");
      lcd.setCursor(0,1);
      lcd.print(Preis);
      lcd.print(" Euro");
      return;  // Exit the loop early to only show the price
    }
    else if (Taste == 'B') {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Auf Wiedersehen");
      return;  // Exit the loop early to only show the message
    }
    else if (Taste == 'D'){
      lcd.clear();
      Preis = 0;
      anzahlApfel = 0;
      anzahlBirne = 0;
      anzahlMaracuja = 0;
      anzahlBanane = 0;
      anzahlKiwi = 0;
      anzahlMango = 0;
      anzahlJoannisbeere = 0;
      anzahlOrange = 0;
      anzahlGP = 0;
      return;
    }

    else if (Taste == 'C'){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Kasse");
      lcd.setCursor(0,1);
      lcd.print("geschlossen");
      return;
    }

    // Preis auf dem LCD anzeigen
    lcd.setCursor(0, 1);  // Cursor auf die zweite Zeile setzen
    lcd.print("Preis: "); // "Preis: " auf dem LCD anzeigen
    lcd.print(Preis);     // Den aktuellen Preis auf dem LCD anzeigen
  }
}
