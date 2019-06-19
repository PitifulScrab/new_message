void api32() {
     ee1 = server.arg("ee1").toInt();//ON / OFF    
     ee2 = server.arg("ee2").toInt();//Time update 
     ee3 = server.arg("ee3").toInt();//   

      
     save32();//  запись в память модуля
     server.send(200, "text/plain", "OK");
}
void openfilehtm32() {
  File htm32 = SPIFFS.open("/htm32.json", "r");
  size_t size = htm32.size();
  std::unique_ptr<char[]> buf(new char[size]);
  htm32.readBytes(buf.get(), size);
  StaticJsonBuffer<900> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());
   ee1 = json["d1"];// ON /  
   ee2 = json["d2"];// Time update  
   ee3 = json["d3"];//  
    
} 

bool save32() {
  StaticJsonBuffer<900> jsonBuffer;
  JsonObject& json = jsonBuffer.createObject();
  json["d1"] = ee1;//ON / OFF  
  json["d2"] = ee2;//Time update 
  json["d3"] = ee3;// 
 
  
  
  File htm32 = SPIFFS.open("/htm32.json", "w");
  if (!htm32) {   
    return false;
  }
  json.printTo(htm32);
  return true;
}

void htm32xml(){
String  url1="<?xml version='1.0'?>";
        url1+="<Donnees>"; 
        url1+="<q1>";
        url1+=ee1;// ON / OFF 
        url1+="</q1>";
        url1+="<q2>";
        url1+=ee2;//Time update 
        url1+="</q2>";
        url1+="<q3>";
        url1+=ee3;// 
        url1+="</q3>"; 
        
        url1+="</Donnees>"; 
server.send(200,"text/xml",url1);
} 
void vk_group_test1(){
     vk_group1_1=1;
}
 
