#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

// === LCD ===
LiquidCrystal_I2C lcd(0x27, 16, 2);

// === KEY PAD ===
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// === LED, Servo, dan Buzzer ===
const int ledHijau = 10;
const int ledMerah = 11;
const int buzzer = 13;
Servo kunciServo;

// === Password ===
String passwordBenar = "1234";
String input = "";
int percobaan = 0;  // jumlah percobaan salah

void setup() {
  pinMode(ledHijau, OUTPUT);
  pinMode(ledMerah, OUTPUT);
  pinMode(buzzer, OUTPUT);
  kunciServo.attach(12);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Masukkan Sandi:");
  kunciServo.write(0); // posisi kunci tertutup
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '#') { // '#' untuk cek sandi
      lcd.clear();
      if (input == passwordBenar) {
        // === Jika sandi benar ===
        digitalWrite(ledHijau, HIGH);
        digitalWrite(ledMerah, LOW);
        lcd.print("Akses Diterima");
        kunciServo.write(90); // buka kunci
        delay(3000);
        kunciServo.write(0); // tutup lagi
        percobaan = 0; // reset percobaan
      } else {
        // === Jika sandi salah ===
        percobaan++;
        digitalWrite(ledMerah, HIGH);
        digitalWrite(ledHijau, LOW);
        lcd.print("Sandi Salah!");
        
        if (percobaan >= 3) {
          // === Jika salah 3x ===
          lcd.clear();
          lcd.print("!!! TERKUNCI !!!");
          tone(buzzer, 1000); // bunyi 1kHz
          delay(3000);        // bunyi 3 detik
          noTone(buzzer);
          percobaan = 0;      // reset percobaan
        }
      }

      delay(2000);
      lcd.clear();
      lcd.print("Masukkan Sandi:");
      input = "";
      digitalWrite(ledHijau, LOW);
      digitalWrite(ledMerah, LOW);
    }

    else if (key == '*') { // hapus 1 karakter
      if (input.length() > 0) {
        input.remove(input.length() - 1);
        lcd.clear();
        lcd.print("Sandi: ");
        for (int i = 0; i < input.length(); i++) lcd.print('*');
      }
    }

    else { // tambah karakter baru
      input += key;
      lcd.clear();
      lcd.print("Sandi: ");
      for (int i = 0; i < input.length(); i++) lcd.print('*');
    }
  }
}
