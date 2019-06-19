void api35() {
     wvv1 = server.arg("vv1").toInt();//ON / OFF    
     wvv2 = server.arg("vv2").toInt();//Time update 
     wvv3 = server.arg("vv3");//key   
     wvv4 = server.arg("vv4").toInt();// 1 Аккаунт,2 Аккаунт id,3 Видео 
     wvv5 = server.arg("vv5");//
     
     save35();//  запись в память модуля
     server.send(200, "text/plain", "OK");
}
void openfilehtm35() {
  File htm35 = SPIFFS.open("/htm35.json", "r");
  size_t size = htm35.size();
  std::unique_ptr<char[]> buf(new char[size]);
  htm35.readBytes(buf.get(), size);
  StaticJsonBuffer<900> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());
   wvv1 = json["d1"];// ON /  
   wvv2 = json["d2"];// Time update  
   String evv3 = json["d3"];//key 
   wvv4 = json["d4"];// 1 Аккаунт,2 Аккаунт id,3 Видео  
   String evv5 = json["d5"];//
   wvv3=evv3;
   wvv5=evv5;
} 

bool save35() {
  StaticJsonBuffer<900> jsonBuffer;
  JsonObject& json = jsonBuffer.createObject();
  json["d1"] = wvv1;//ON / OFF  
  json["d2"] = wvv2;//Time update 
  json["d3"] = wvv3;//key 
  json["d4"] = wvv4;//
  json["d5"] = wvv5;//
  
  
  File htm35 = SPIFFS.open("/htm35.json", "w");
  if (!htm35) {   
    return false;
  }
  json.printTo(htm35);
  return true;
}

void htm35xml(){
String  url1="<?xml version='1.0'?>";
        url1+="<Donnees>"; 
        url1+="<q1>";
        url1+=wvv1;// ON / OFF 
        url1+="</q1>";
        url1+="<q2>";
        url1+=wvv2;//Time update 
        url1+="</q2>";
        url1+="<q3>";
        url1+=wvv3;// 
        url1+="</q3>"; 
        url1+="<q4>";
        url1+=wvv4;// 
        url1+="</q4>"; 
        url1+="<q5>";
        url1+=wvv5;// 
        url1+="</q5>"; 
        
        url1+="</Donnees>"; 
server.send(200,"text/xml",url1);
} 
void youtube_api_test1(){
     youtube_api1_1=1;
}
 
