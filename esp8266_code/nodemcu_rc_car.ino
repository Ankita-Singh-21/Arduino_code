
  
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.

char auth[] = "2zGwkqaHho4_xB6zxxPPohL_p-6t7mjl";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "OppoA15";
char pass[] = "77777777";
int val_f = 0;
int val_b = 0;
int val_l = 0;
int val_r = 0;

void setup()
{
  // Debug console
  Serial.begin(9600);

  pinMode(16, OUTPUT); // GPIO pin16=D0 of NodeMCU 12E or in place of '16' you can write'D0' directly || -->Connected to motordriver 
  pinMode(5, OUTPUT);  // GPIO pin5=D1 of NodeMCU 12E or in place of '16' you can write 'D0' directly || -->Connected to motordriver
  pinMode(4, OUTPUT);  // GPIO pin4=D2 of NodeMCU 12E or in place of '16' you can write 'D0' directly || -->Connected to motordriver
  pinMode(0, OUTPUT);  // GPIO pin0=D3 of NodeMCU 12E or in place of '16' you can write 'D0' directly || -->Connected to motordriver

  // Input pin connected to blynk app
  
  pinMode(14, INPUT);  // GPIO pin14=D5
  pinMode(12, INPUT);  // GPIO pin12=D6
  pinMode(13, INPUT);  // GPIO pin13=D7
  pinMode(15, INPUT); // GPIO pin15=D8
  

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  
  val_f = digitalRead(14);
  val_b = digitalRead(12);
  val_r = digitalRead(13);
  val_l = digitalRead(15);
  
  

  if (val_f == 1){
    
      digitalWrite(16,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      digitalWrite(0,HIGH);
      
      Serial.println("forward");
    
    }
    else if (val_b == 1){
    
      digitalWrite(16,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(0,LOW);
      
      Serial.println("backward");
    
    }
    if (val_l == 1){
    
      digitalWrite(16,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(0,HIGH);
      
      Serial.println("left");
    
    }
    if (val_r == 1){
    
      digitalWrite(16,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(0,LOW);
      Serial.println("right");
    
    }

    else {
      
      digitalWrite(16,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      digitalWrite(0,LOW);
     
      Serial.println("stop");}
}
