//LED'lerin bağlı olduğu pinler tanımlanır. 
#define LED1 7
#define LED2 6
#define LED3 5 

//değişken tanımlamaları yapılır.
float value1;
float value2;
float temperature;
int motor=11;


void setup()
{
  Serial.begin(9600);
  // pinMode(motor,OUTPUT);   // Fan pini çıkış olarak tanımlanır.
  
  // pinMode(7,OUTPUT);  // 7,6 ve 5'de LED'ler bağlıdır. Çıkış olarak tanımlanırlar.
  // pinMode(6,OUTPUT);
  // pinMode(5,OUTPUT);
}
void loop()
{
  value1=analogRead(4);   // Sıcaklık sensörü okunur.
  value2= (value1/1023)*500;
  temperature=value2;       // Okunan sıcaklık bilgisine göre sıcaklık santigrat cinsinden hesaplanır.
  

  Serial.print("Sicaklik : ");
  Serial.print(temperature);
  Serial.println(" ^C");
  Serial.print("lm35pin : ");
  Serial.print(value1);
  Serial.println(" ^C");

   // if (isi>15)    
  {
    digitalWrite(LED1,HIGH);
    analogWrite(motor,75);
  }
  // else if (isi>25)     
  {
    digitalWrite(LED2,HIGH);
    analogWrite(motor,150);
  }
    // else if (isi>35)   
  {
    digitalWrite(LED3,HIGH);
    analogWrite(motor,255);
  }
    // else {
      analogWrite(motor,0); 
  
    delay(500);
}
