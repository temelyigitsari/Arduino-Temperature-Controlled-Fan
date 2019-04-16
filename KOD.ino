#include "DHT.h"                                // DHT KÜTÜPHANESİ EKLENİR.

#define DHTPIN 2                                // DHT'NİN BAĞLI OLDUĞU PİN TANIMLANIR.

#define DHTTYPE DHT11                           //DHT SERİSİNİN HANGİ ÜRÜNÜ KULLANILDIĞI BELİRTİLİR.

//#define DHTTYPE DHT22
//#define DHTTYPE DHT21

DHT temelyigitsari(DHTPIN, DHTTYPE);            //DHT11'İN ÖLÇÜM YAPABİLMESİ İÇİN DHT FONKSİYONU YAZILIR.

int kirmiziPin = 9;                             //RGB LED İÇİN GEREKLİ PİN ÇIKIŞLARI BELİRTİLİR.
int yesilPin = 10;
int maviPin = 11;

int kirmizi_motor=3;                            //PWM ÇIKIŞLARI İÇİN HANGİ MOTORLARA GİTTİKLERİ BELİRTİLİR.
int mavi_motor=5;

void setup() {

pinMode(kirmiziPin, OUTPUT);                    //PİNLERİN GİRİŞ Mİ YOKSA ÇIKIŞ OLARAK MI KULLANILACAĞI BELİRTİLİR.
pinMode(yesilPin, OUTPUT); 
pinMode(maviPin, OUTPUT);  
pinMode(kirmizi_motor, OUTPUT);
pinMode(mavi_motor, OUTPUT);

Serial.begin(9600);                             //SERİAL EKRANDAN ONLİNE BİLGİ ALABİLMEK İÇİN YAZILAN SERİAL EKRAN AÇMA İŞLEMİDİR.

Serial.println("DHT11 test!");

temelyigitsari.begin();

}

void loop() {

  delay(2500);

  int h = temelyigitsari.readHumidity();                       //DHT ÖLÇÜM İŞLEMİ YAPAN FONKİSYONLAR VE TANIMLAMALARI.
  int t = temelyigitsari.readTemperature();

  Serial.print("Nem: ");
  Serial.print(h);
  Serial.println(" %");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" ^C ");
  
    if (t>=20 and t<30)    
  {
   analogWrite(kirmiziPin,0);     // KIRMIZI RENK RGB LED AYARI
   analogWrite(yesilPin,255);
   analogWrite(maviPin,255);
   
   analogWrite(kirmizi_motor,165);
   analogWrite(mavi_motor,0);

   Serial.print("Speed: ");
   Serial.println(" 500 RPM || KIRMIZI FAN YARI GÜÇTE");
    
  }
  
   if (t>=30 and t<40)     
  {
   analogWrite(kirmiziPin,255);   // YEŞİL RENK RGB LED AYARI
   analogWrite(yesilPin,0);
   analogWrite(maviPin,255);

   analogWrite(kirmizi_motor,255);
   analogWrite(mavi_motor,0);

   Serial.print("Speed: ");
   Serial.println(" 1000 RPM || KIRMIZI FAN TAM GÜÇTE");
            
  }
  
    if (t>=40 and t<50)   
  {
   analogWrite(kirmiziPin,255);   // MAVİ RENK RGB LED AYARI
   analogWrite(yesilPin,255);
   analogWrite(maviPin,0);

   analogWrite(kirmizi_motor,0);
   analogWrite(mavi_motor,165);

   Serial.print("Speed: ");
   Serial.println(" 500 RPM || MAVİ FAN YARI GÜÇTE");
          
  }
  
    if (t>=50 and t<=60)   
  {
   analogWrite(kirmiziPin,0);     // BEYAZ RENK RGB LED AYARI
   analogWrite(yesilPin,0);
   analogWrite(maviPin,0);

   analogWrite(kirmizi_motor,0);
   analogWrite(mavi_motor,255);

   Serial.print("Speed: ");
   Serial.println(" 1000 RPM || MAVİ FAN TAM GÜÇTE");
        
  }
  
  Serial.println("-------------------");
     

}
