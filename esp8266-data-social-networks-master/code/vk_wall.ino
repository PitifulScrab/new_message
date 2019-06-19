void api30() {
     vv1 = server.arg("vv1").toInt();//ON / OFF    
     vv2 = server.arg("vv2").toInt();//Time update 
     vv3 = server.arg("vv3");//   
     vv4 = server.arg("vv4").toInt();// 
     
     save30();//  запись в память модуля
     server.send(200, "text/plain", "OK");
}
void openfilehtm30() {
  File htm30 = SPIFFS.open("/htm30.json", "r");
  size_t size = htm30.size();
  std::unique_ptr<char[]> buf(new char[size]);
  htm30.readBytes(buf.get(), size);
  StaticJsonBuffer<900> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());
   vv1 = json["d1"];// ON /  
   vv2 = json["d2"];// Time update  
   String evv3 = json["d3"];//  
   vv4 = json["d4"];// 
   vv3=evv3;
} 

bool save30() {
  StaticJsonBuffer<900> jsonBuffer;
  JsonObject& json = jsonBuffer.createObject();
  json["d1"] = vv1;//ON / OFF  
  json["d2"] = vv2;//Time update 
  json["d3"] = vv3;// 
  json["d4"] = vv4;// 
  
  
  File htm30 = SPIFFS.open("/htm30.json", "w");
  if (!htm30) {   
    return false;
  }
  json.printTo(htm30);
  return true;
}

void htm30xml(){
String  url1="<?xml version='1.0'?>";
        url1+="<Donnees>"; 
        url1+="<q1>";
        url1+=vv1;// ON / OFF 
        url1+="</q1>";
        url1+="<q2>";
        url1+=vv2;//Time update 
        url1+="</q2>";
        url1+="<q3>";
        url1+=vv3;// 
        url1+="</q3>";
        url1+="<q4>";
        url1+=vv4;// 
        url1+="</q4>"; 
        
        url1+="</Donnees>"; 
server.send(200,"text/xml",url1);
} 
void vk_wall_test1(){
     vk_wall1_1=1;
}
 
   
