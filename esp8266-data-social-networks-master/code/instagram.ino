void api34() {
     cc1 = server.arg("cc1").toInt();//ON / OFF    
     cc2 = server.arg("cc2").toInt();//Time update 
     cc3 = server.arg("cc3");//   
     
     save34();//  запись в память модуля
     server.send(200, "text/plain", "OK");
}
void openfilehtm34() {
  File htm34 = SPIFFS.open("/htm34.json", "r");
  size_t size = htm34.size();
  std::unique_ptr<char[]> buf(new char[size]);
  htm34.readBytes(buf.get(), size);
  StaticJsonBuffer<900> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());
   cc1 = json["d1"];// ON /  
   cc2 = json["d2"];// Time update  
   String ecc3 = json["d3"];//  
   cc3=ecc3;
} 

bool save34() {
  StaticJsonBuffer<900> jsonBuffer;
  JsonObject& json = jsonBuffer.createObject();
  json["d1"] = cc1;//ON / OFF  
  json["d2"] = cc2;//Time update 
  json["d3"] = cc3;// 
 
  
  
  File htm34 = SPIFFS.open("/htm34.json", "w");
  if (!htm34) {   
    return false;
  }
  json.printTo(htm34);
  return true;
}

void htm34xml(){
String  url1="<?xml version='1.0'?>";
        url1+="<Donnees>"; 
        url1+="<q1>";
        url1+=cc1;// ON / OFF 
        url1+="</q1>";
        url1+="<q2>";
        url1+=cc2;//Time update 
        url1+="</q2>";
        url1+="<q3>";
        url1+=cc3;// 
        url1+="</q3>"; 
        
        url1+="</Donnees>"; 
server.send(200,"text/xml",url1);
} 
void instagram_data_test1(){
     instagram_data1_1=1;
}
 
