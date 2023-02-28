
#include <LCD_I2C.h>
#include <SoftwareSerial.h>
String msj;
char letra=0;
int estado=0;
LCD_I2C lcd(0x3F, 16, 2);
SoftwareSerial BTSerial(11, 10); // RX | TX

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode (13,OUTPUT);
  digitalWrite(13,HIGH);
   lcd.begin();
  lcd.backlight(); 
}

void loop() {
    if (Serial.available()){
    msj="";
    letra=0;
    while (Serial.available()>0){
      letra=Serial.read();
      if(letra =='\n'){
      break;
    }
    else
    {
       msj=msj+letra;
      letra=0;
       delay(1);
  
  }
  }
  Serial.println(msj);
  BTSerial.print(msj);
  lcd.clear();
  lcd.setCursor (3,0);
  lcd.print(msj);
 
 
}

if (BTSerial.available()){
    msj="";
    letra=0;
    while (BTSerial.available()>0){
      letra=BTSerial.read();
      if(letra =='\n'){
      break;
    }
    else
    {
       msj=msj+letra;
      letra=0;
       delay(1);
  
  }
  }
  Serial.println(msj);
  BTSerial.print( "mensaje recibido");
  lcd.clear();
  lcd.setCursor (5,0);
  lcd.print (msj);
 
}
if(msj== "encender foco") {
  digitalWrite (13, LOW);
}
if (msj == "apagar foco"){
  digitalWrite (13, HIGH);
}

if(msj == "a"){
  digitalWrite(13,LOW);
}
if(msj == "b"){
  digitalWrite(13,HIGH);
}

}
