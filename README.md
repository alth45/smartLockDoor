# 🔐 SmartLockDoor

**SmartLockDoor** adalah sistem keamanan pintu sederhana berbasis **mikrokontroler** yang menggunakan **keypad** dan **LCD** untuk memasukkan serta menampilkan sandi.  
Jika pengguna salah memasukkan sandi sebanyak **3 kali**, sistem akan **mengaktifkan alarm** dan **mematikan fungsi keypad** untuk sementara.

---

## 🚀 Fitur Utama

- 🔢 **Input Sandi via Keypad**  
  Pengguna memasukkan kode rahasia melalui keypad 4x4.

- 💬 **Tampilan LCD**  
  LCD menampilkan status input (misalnya: `Enter Password`, `Access Granted`, `Access Denied`, dll).

- 🚨 **Alarm Keamanan**  
  Jika sandi salah sebanyak **3 kali**, buzzer akan aktif menandakan pelanggaran.

- 🔒 **Lock System / Freeze**  
  Setelah alarm aktif, keypad dinonaktifkan hingga sistem direset secara manual.

---

## ⚙️ Komponen yang Digunakan

| Komponen | Fungsi |
|-----------|--------|
| Arduino UNO / Nano | Mikrokontroler utama |
| Keypad 4x4 | Input sandi |
| LCD 16x2 (I2C) | Menampilkan status sistem |
| Buzzer | Alarm keamanan |
| Resistor / Kabel jumper | Pendukung rangkaian |
| Breadboard / PCB | Tempat perakitan |

---

## 🧠 Cara Kerja Sistem

1. Sistem menunggu input sandi dari pengguna.  
2. LCD menampilkan prompt:  Masukan kata sandi
3. Jika sandi **benar**, LCD menampilkan: Access Granted
Door Unlocked
4. Jika sandi **salah**, LCD menampilkan:  Wrong Password
Try Again
5. Setelah **3 kali salah berturut-turut**, sistem:  
- Mengaktifkan **alarm (buzzer)**  
- **Menonaktifkan keypad** hingga dilakukan **reset**

---
