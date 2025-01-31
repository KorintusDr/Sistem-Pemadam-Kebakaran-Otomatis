#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// Konfigurasi WiFi
char ssid[] = "samping"; // Nama WiFi
char password[] = "22223333"; // Password WiFi

// Konfigurasi Telegram Bot
#define BOTtoken "12345" // Token bot
String chatid = "6789"; // ID Telegram

// Deklarasi objek
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Pin yang digunakan
#define pump 16 // Anoda water pump dihubungkan ke pin D0
int NilaiSensor; // Menyimpan nilai sensor

void setup() {
    Serial.begin(9600);
    
    // Inisialisasi WiFi
    WifiStatus();
    
    // Kirim pesan ke Telegram
    bot.sendMessage(chatid, "Sensor MQ-2 Terhubung");
    Serial.println("Sensor MQ-2 Terhubung");
    
    // Konfigurasi pin
    pinMode(A0, INPUT);
    pinMode(pump, OUTPUT);
}

void loop() {
    NilaiSensor = analogRead(A0); // Membaca nilai dari sensor
    Serial.println(NilaiSensor); // Menampilkan nilai sensor di Serial Monitor

    if (NilaiSensor > 300) {
        digitalWrite(pump, HIGH); // Menyalakan pompa
        bot.sendMessage(chatid, "Terjadi Kebakaran...!!!"); // Kirim notifikasi ke Telegram
    } else {
        digitalWrite(pump, LOW); // Mematikan pompa
    }
    
    delay(500); // Jeda waktu 500ms
}

void WifiStatus() {
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    
    Serial.print("Connecting to WiFi: ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }
    
    Serial.println("\nWiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}