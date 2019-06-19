void api1() {         
String url = "/method/messages.getLongPollServer?use_ssl=0&need_pts=1&v=5.37&access_token=";    
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
    StaticJsonBuffer<999> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(line);     
    int  k1 = root ["response"]["pts"]; 
    int  k2 = root ["response"]["ts"];
    pts=k1;
    ts=k2;
  }
Serial.print("pts");  
Serial.println(pts);    
Serial.print("ts");  
Serial.println(ts);  
}
