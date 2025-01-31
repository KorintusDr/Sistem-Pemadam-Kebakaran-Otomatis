# 🔥 Sistem Pemadam Kebakaran dengan ESP8266

## 📌 Deskripsi
Proyek ini adalah **sistem pemadam kebakaran** menggunakan **ESP8266 NodeMCU**, **sensor gas MQ-2**, dan **pompa air yang dikendalikan relay**. Ketika MQ-2 mendeteksi asap atau gas melebihi ambang batas yang telah ditentukan, sistem secara otomatis menyalakan pompa air dan mengirimkan **notifikasi Telegram**.

## 🛠 Fitur
- 🔍 **Deteksi Asap & Gas** menggunakan sensor MQ-2.
- 🚰 **Aktivasi Pompa Air Otomatis** ketika asap atau gas terdeteksi.
- 📩 **Notifikasi Telegram** untuk memberi peringatan secara real-time.
- 📡 **Koneksi Wi-Fi** untuk pemantauan jarak jauh.

## 🏗 Kebutuhan Perangkat Keras
- **ESP8266 NodeMCU**
- **Sensor Gas MQ-2**
- **Modul Relay**
- **Pompa Air (5V atau 12V)**
- **Adaptor Daya (5V/12V) atau Baterai**
- **Kabel Jumper & Breadboard**

## 📝 Diagram Rangkaian
![Diagram Rangkaian](A_detailed_schematic_diagram_of_a_fire_suppression.png)

## 📜 Instalasi & Pengaturan
### 1️⃣ Prasyarat
Pastikan Anda telah menginstal:
- **Arduino IDE**
- **Library ESP8266 Board**
- **Library UniversalTelegramBot**

### 2️⃣ Panduan Koneksi
- **Sensor MQ-2**
  - VCC → 3.3V (NodeMCU)
  - GND → GND (NodeMCU)
  - A0 → A0 (NodeMCU)
- **Modul Relay**
  - VCC → 5V (NodeMCU)
  - GND → GND (NodeMCU)
  - IN → D0 (NodeMCU)
- **Pompa Air**
  - + → NO (Relay Normally Open)
  - - → GND (Sumber Daya)
  - COM (Relay) → + (Sumber Daya)

### 3️⃣ Mengunggah Kode
1. Buka **Arduino IDE**
2. Instal library yang diperlukan (`ESP8266WiFi`, `WiFiClientSecure`, `UniversalTelegramBot`)
3. Ganti placeholder berikut dalam kode:
   ```cpp
   char ssid[] = "NAMA_WIFI_ANDA";
   char password[] = "PASSWORD_WIFI_ANDA";
   #define BOTtoken "TOKEN_BOT_TELEGRAM_ANDA"
   String chatid = "ID_CHAT_TELEGRAM_ANDA";
   ```
4. Unggah kode ke **ESP8266**.
5. Buka **Serial Monitor** (baud rate 9600) untuk memeriksa koneksi.

## 🚀 Cara Penggunaan
1. **Nyalakan** sistem ESP8266.
2. **Sensor akan terus memantau kualitas udara**.
3. Jika terdeteksi asap (`nilai sensor > 300`):
   - 🚰 **Pompa air akan menyala**.
   - 📩 **Notifikasi Telegram akan dikirim**.
4. Sistem akan kembali memantau setelah kondisi normal.

## 📧 Kontak & Dukungan
Jika ada masalah atau ingin berkontribusi, silakan ajukan **Issue** di repositori ini! 🚀
