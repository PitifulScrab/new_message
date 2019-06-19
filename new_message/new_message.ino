#include <ArduinoJson.h> 
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h> 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);  
String k,kk,kkk,line; 
int pts,newpts,ts,i;   
const char* ssid = "Platotl23";// ssid wifi
const char* password = "2810002184"; //  Пароль wifi              
const char* host = "api.vk.com";
const int httpsPort = 443; 
const char* access_token = "b7f86ef75b923b18c1e4691431f8425a3cd6727d180ab60c3377d693100c0ad60ef7ca0c380340dd5407a";  // 1.Чтобы получить токен нужно перейти по ссылке https://oauth.vk.com/authorize?client_id=5586765&display=page&redirect_uri=https://oauth.vk.com/blank.html&scope=offline,messages&response_type=token&v=5.37
                                   // 2. Нажимаем разрешить 
                                  // 3.  После чего перенаправляет на страницу   https://oauth.vk.com/blank.html#access_token=c743de878b930a2077651972e6546a0ea623c509c30cb551a1608acdee89841e4ef39dd2469c7e5844c67&expires_in=0&user_id=91548782 - моя ссылка
                                 // 4. oauth.vk.com/blank.html#access_token=код который тут будет надо вставить в поле access_token &expires_in=0&user_id=***         
const char* fingerprint = "fb 9b af 57 f4 46 7c bf 90 80 e5 7a 18 6e 15 a3 0f 11 dd 9f"; //vk.com
WiFiClientSecure client; 
void setup(void){ 
  Wire.pins(4, 5); // 4 sda 5 scl
 
  lcd.init();  
  lcd.backlight();
    Serial.begin(115200);  
    WiFi.mode(WIFI_STA); //режим клиент
    WiFi.begin(ssid, password);  
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
      }   
api1();
api2(); 
  }
void loop(void){   
 delay(8000);   
 test();  
 if (pts < newpts)
{
 i++;
 pts=newpts;
}
}
  
 
