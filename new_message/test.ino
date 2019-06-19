void test() {     
String url = "/method/messages.getLongPollHistory?ts="; 
url += ts;
url += "&pts=";  
url += newpts;   
url += "&v=5.37&access_token=";   
url += access_token; 
 if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
  }
  else
  {
    Serial.println("OK");
    if (client.verify(fingerprint, host)) {
 
       client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
    } else {
      Serial.println("certificate doesn't match");
    }
  } 
  delay(1500);  
  while(client.available()){
    line = client.readStringUntil('\r'); 
    StaticJsonBuffer<1500> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(line);   
 int  k1 = root ["response"]["new_pts"]; 
 String  k2 = root ["response"]["profiles"][0] ["first_name"]; 
 String  k3 = root ["response"]["profiles"][0] ["last_name"]; 
newpts=k1; 
kk=k2;  
kkk=k3;
  }
  lcd.clear(); 
  lcd.print(kk);
  lcd.setCursor(6,0);
  lcd.print(kkk); 
  lcd.setCursor(0, 1);                 
  lcd.print("new");  
  lcd.setCursor(5, 1);                 
  lcd.print(i);  
 ;
}
