void api2() {       
String url = "/method/messages.getLongPollHistory?ts="; 
url += ts;
url += "&pts=";  
url += pts;   
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
 int  k33 = root ["response"]["new_pts"]; 
 String  first = root ["response"]["profiles"][0] ["first_name"]; 
 String  last = root ["response"]["profiles"][0] ["last_name"]; 
     newpts=k33; 
     kk=first;  
     kkk=last;   
  }
   Serial.print("new_pts");  
 Serial.println(newpts);  
 ;
}
