void api33() {
     rr1 = server.arg("rr1").toInt();//ON / OFF    
     rr2 = server.arg("rr2").toInt();//Time update 
     rr3 = server.arg("rr3");//   

      
     save33();//  запись в память модуля
     server.send(200, "text/plain", "OK");
}
void openfilehtm33() {
  File htm33 = SPIFFS.open("/htm33.json", "r");
  size_t size = htm33.size();
  std::unique_ptr<char[]> buf(new char[size]);
  htm33.readBytes(buf.get(), size);
  StaticJsonBuffer<900> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());
   rr1 = json["d1"];// ON /  
   rr2 = json["d2"];// Time update  
   String err3 = json["d3"];//  
   rr3=err3;
    
} 

bool save33() {
  StaticJsonBuffer<900> jsonBuffer;
  JsonObject& json = jsonBuffer.createObject();
  json["d1"] = rr1;//ON / OFF  
  json["d2"] = rr2;//Time update 
  json["d3"] = rr3;// 
 
  
  
  File htm33 = SPIFFS.open("/htm33.json", "w");
  if (!htm33) {   
    return false;
  }
  json.printTo(htm33);
  return true;
}

void htm33xml(){
String  url1="<?xml version='1.0'?>";
        url1+="<Donnees>"; 
        url1+="<q1>";
        url1+=rr1;// ON / OFF 
        url1+="</q1>";
        url1+="<q2>";
        url1+=rr2;//Time update 
        url1+="</q2>";
        url1+="<q3>";
        url1+=rr3;// 
        url1+="</q3>"; 
        
        url1+="</Donnees>"; 
server.send(200,"text/xml",url1);
} 
void vk_messages_new_test1(){
     vk_messages_new1_1=1;
}
 
