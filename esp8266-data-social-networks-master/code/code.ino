#include <ESP8266WiFi.h>            // LGPL  2.1         //https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <ESP8266WebServer.h>       //LGPL 2.1           //https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WebServer
#include <ESP8266mDNS.h>            //MIT                //https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266mDNS
#include <FS.h>                     //LGPL-2.1           //http://esp8266.github.io/Arduino/versions/2.1.0/doc/filesystem.html  //https://github.com/esp8266/Arduino/blob/master/LICENSE  
#include <ArduinoJson.h>            //MIT                //https://bblanchon.github.io/ArduinoJson/                             //https://github.com/bblanchon/ArduinoJson/blob/master/LICENSE.md
#include <PubSubClient.h>           //MIT                //https://github.com/Imroy/pubsubclient                                //https://github.com/Imroy/pubsubclient/blob/master/LICENSE.txt
#include <ESP8266httpUpdate.h>                           //https://github.com/Links2004/Arduino/tree/esp8266/hardware/esp8266com/esp8266/libraries/ESP8266httpUpdate        
#include <ESP8266HTTPClient.h>                           //https://github.com/Links2004/Arduino/tree/libraries/ESP8266HTTPClient 
#include <ESP8266HTTPUpdateServer.h>                     //https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266HTTPUpdateServer 
#include <Wire.h>                   //LGPL               //https://github.com/esp8266/Arduino/tree/master/libraries/Wire 
#include <Ticker.h>                 //LGPL               //https://github.com/esp8266/Arduino/tree/master/libraries/Ticker 
#include <SPI.h>                    //Creative Commons Attribution-ShareAlike 3.0  //http://www.arduino.cc/en/Reference/SPI    //https://creativecommons.org/licenses/by-sa/3.0/
#include <Adafruit_GFX.h>           //BSD-2-Clause       //https://github.com/adafruit/Adafruit-GFX-Library                    //https://github.com/adafruit/Adafruit-GFX-Library/blob/master/license.txt
#include <Adafruit_SSD1306.h>       //BSD-3-Clause       //https://github.com/adafruit/Adafruit_SSD1306                        //https://github.com/adafruit/Adafruit_SSD1306/blob/master/license.txt
#include <LiquidCrystal_I2C.h>      //DFRobot.com        //https://www.dfrobot.com/wiki/index.php/I2C/TWI_LCD1602_Module_(SKU:_DFR0063)   
#include <Max72xxPanel.h>           //BSD-3-Clause       //https://github.com/markruys/arduino-Max72xxPanel                    //https://github.com/markruys/arduino-Max72xxPanel/blob/master/license.txt
#include <HCMAX7219.h>                                   //https://github.com/HobbyComponents/HCMAX7219
#include <VkApiEsp8266.h>                                //https://github.com/yuri-afanasiev/esp8266-vk-api
#include <InstagramEsp8266.h>                            //https://github.com/yuri-afanasiev/esp8266-instagram-data
#include <YoutubeEsp8266.h>                              //https://github.com/yuri-afanasiev/esp8266-youtube-api
 
String esp8266_name;
String w1,w2,w3,w4,w5,w6; //настройки wifi
int w7,w8;//настройки wifi

int var=1;//wifi 
int wifire;
int reconnect;
 
int k1,k2,k3,k4,k5,k6,k7,k8,k9,k10,k11,k12,k13,k14,k15,k16;//htm8 Экраны 

int mqw1,mqw3,mqw8,mqw10;//htm19
String mqw2,mqw4,mqw5,mqw6,mqw7,mqw9;//htm19
String top1,top2,top3,top4; //адресное пространство MQTT 


float rev_code=0.01;//текущая версия кода
WiFiClient mqtttestclient; 
PubSubClient mqttclient(mqtttestclient);
ESP8266HTTPUpdateServer httpUpdater;
ESP8266WebServer server(80); 
WiFiClient client;
File fsUploadFile;

Adafruit_SSD1306 display_oled(14);
Ticker oled_ssd1306;
int oled_ssd1306_test1_1;

LiquidCrystal_I2C lcd(0x27,16,2);
Ticker display_lcd;
int display_lcd_test1_1;  

 
Max72xxPanel matrix = Max72xxPanel(12,1,4);
Ticker display_max7219_matrix_ticker; 
int display_max7219_matrix1_1;


HCMAX7219 HCMAX7219(12);// pin 2 HCMAX7219   
Ticker display_max7219_segment_ticker; 
int display_max7219_segment1_1;


String zz1,zz2,zz3,zz4,zz5,zz6;//htm29


vk_api_host api;
int vv1,vv2,vv4;//htm30
String vv3;

Ticker vk_wall_ticker; 
int vk_wall1_1;

int qq1,qq2,qq4,qq5;//htm31
String qq3;
Ticker vk_foto_ticker; 
int vk_foto1_1;


int ee1,ee2,ee3;//htm32 
Ticker vk_group_ticker; 
int vk_group1_1;

int rr1,rr2;//htm33
String rr3;
Ticker vk_messages_new_ticker; 
int vk_messages_new1_1;
 
instagram instagram_data;
int cc1,cc2;
String cc3;
Ticker instagram_data_ticker; 
int instagram_data1_1;

 
youtube youtube_api;
int wvv1,wvv2,wvv4;//htm35
String wvv3,wvv5;
Ticker youtube_api_ticker; 
int youtube_api1_1;

void callback(const MQTT::Publish& pub){
     String payload = pub.payload_string();
     Serial.println(pub.topic());
            
}

void setup(void){
     Serial.begin(9600);
     SPIFFS.begin();          
     openfile();//файл настроек 
     openfilehtm8();// файл настроек
     openfilehtm19();// файл настроек  htm19 MQTT
     openfilehtm29();// файл настроек  htm29
     openfilehtm30();// файл настроек  htm30 VK wall
     openfilehtm31();// файл настроек  htm31 VK foto
     openfilehtm32();// файл настроек  htm32 VK group
     openfilehtm33();// файл настроек  htm33 VK messages new
     openfilehtm34();// файл настроек  htm34 Instagram
     openfilehtm35();// файл настроек  htm35 Youtube

     //Wire.pins(4,5);// 4(SDA) 5(SCL) 
     
      top3 += "/home/"+mqw7+ "/"+mqw6+"/";  
      top2 += "/home/"+mqw7+"/";     
      top1 += "/home/";
        
      Serial.println(top3);
      Serial.println(top2);
      Serial.println(top1);
      
     wifi();  
     Serial.println(WiFi.localIP());
     serveron();
     
       
        if (k1 == 1){   //lcd  
            lcd.init();                     
            lcd.backlight(); 
            display_lcd.attach(k2, display_lcd_test1); 
           }
        if (k9 == 1){   //MAX7219 4-матрицы
            matrix.setIntensity(k12);// яркость 0 - 15 
            matrix.setRotation(k13);// 1 3 поворот
            matrix.setTextWrap(false); // Don't wrap at end of line - will do ourselves
            matrix7219_running("yuriy_afanasiev_ ");
            display_max7219_matrix();
            display_max7219_matrix_ticker.attach(k10, display_max7219_matrix_test1); 
           }
       if (k5 == 1){   //SSD1306
             display_oled.begin(SSD1306_SWITCHCAPVCC, 0x3c);    
             display_oled.clearDisplay();
             display_oled.setCursor(0,0);
             display_oled.println("");
             display_oled.display();
             oled_ssd1306.attach(k6, oled_ssd1306_test1);// 
           }  
       if (k14 == 1){ //MAX7219 7-сегмент 
           display_max7219_segment_ticker.attach(k15,display_max7219_segment_test1);// 
           }  

          
////////////////////////////////////////////////////////////////////
        if (vv1 == 1){ 
            api.server(zz1);
            api.url(zz6); 
            vk_wall_ticker.attach(vv2, vk_wall_test1);
            vk_wall1_1=1;
           }
        if (qq1 == 1){ 
            api.server(zz1);
            api.url(zz6); 
            vk_foto_ticker.attach(qq2, vk_foto_test1);
            vk_foto1_1=1;
           }
        if (ee1 == 1){ 
            api.server(zz1);
            api.url(zz6); 
            vk_group_ticker.attach(ee2, vk_group_test1);
            vk_group1_1=1; 
           }    
        if (rr1 == 1){ 
            api.server(zz1);
            api.url(zz6); 
            vk_messages_new_ticker.attach(rr2,vk_messages_new_test1);
            vk_messages_new1_1=1;
           }  
        if (cc1 == 1){ 
            instagram_data.server(zz1,zz2);
            instagram_data_ticker.attach(cc2,instagram_data_test1);
            instagram_data1_1=1;
           } 
       if (wvv1 == 1){ 
            youtube_api.server(zz1,zz3,zz4,zz5,wvv3);
            youtube_api_ticker.attach(wvv2,youtube_api_test1);
            youtube_api1_1=1;
            
           }       
                   
    
}
void loop(void){   
     server.handleClient(); 
     wifitest(); 
     if (mqw1 == 1){//
         if (mqttclient.connected()){
             mqttclient.loop();
             }else {
              mqtt_connect();
             }
       }

         if (oled_ssd1306_test1_1 == 1){     
              ssd1306_time();
              oled_ssd1306_test1_1=0;
            }
         if (display_lcd_test1_1 == 1){          
             lcdtime();   
             display_lcd_test1_1=0;   
            }
         if (display_max7219_matrix1_1 == 1){          
             display_max7219_matrix();   
             //matrix7219_running("error ");
             display_max7219_matrix1_1=0;   
            }
         if (display_max7219_segment1_1 == 1){          
             display_max7219_segment();
             display_max7219_segment1_1=0;   
            }
           ///////////////////////////////////////////
         if (vk_wall1_1 == 1){          
             api.wall(vv3);  
             vk_wall1_1=0;   
            } 
         if (vk_foto1_1 == 1){          
             api.like(qq3,qq4,qq5); 
             vk_foto1_1=0;   
            } 
         if (vk_group1_1 == 1){          
             api.group(ee3);
             vk_group1_1=0;   
            }    
         if (vk_messages_new1_1 == 1){          
              api.new_messages(rr3);
             vk_messages_new1_1=0;   
            }       
         if (instagram_data1_1 == 1){          
             instagram_data.account(cc3); 
             instagram_data1_1=0;   
            } 
         if (youtube_api1_1 == 1){  
             if (wvv4 == 1){   
                 youtube_api.account(wvv5);
                  
                }
            if (wvv4 == 2){   
                youtube_api.account_id(wvv5);
               }
            if (wvv4 == 3){   
               youtube_api.statistics(wvv5); 
               } 
             youtube_api1_1=0;   
            }                       
}


