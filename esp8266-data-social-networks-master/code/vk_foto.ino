void api31() {
     qq1 = server.arg("qq1").toInt();//ON / OFF    
     qq2 = server.arg("qq2").toInt();//Time update 
     qq3 = server.arg("qq3");//photo 
     qq4 = server.arg("qq4").toInt();// идентификатор пользователя сообщества
     qq5 = server.arg("qq5").toInt();// идентификатор объекта
     
     save31();//  запись в память модуля
     server.send(200, "text/plain", "OK");
}
void openfilehtm31() {
  File htm31 = SPIFFS.open("/htm31.json", "r");
  size_t size = htm31.size();
  std::unique_ptr<char[]> buf(new char[size]);
  htm31.readBytes(buf.get(), size);
  StaticJsonBuffer<900> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());
   qq1 = json["d1"];// ON /  
   qq2 = json["d2"];// Time update  
   String evv3 = json["d3"];//  
   qq4 = json["d4"];// 
   qq5 = json["d5"];// 
   qq3=evv3;
} 

bool save31() {
  StaticJsonBuffer<900> jsonBuffer;
  JsonObject& json = jsonBuffer.createObject();
  json["d1"] = qq1;//ON / OFF  
  json["d2"] = qq2;//Time update 
  json["d3"] = qq3;// 
  json["d4"] = qq4;// 
  json["d5"] = qq5;// 
  
  
  File htm31 = SPIFFS.open("/htm31.json", "w");
  if (!htm31) {   
    return false;
  }
  json.printTo(htm31);
  return true;
}

void htm31xml(){
String  url1="<?xml version='1.0'?>";
        url1+="<Donnees>"; 
        url1+="<q1>";
        url1+=qq1;// ON / OFF 
        url1+="</q1>";
        url1+="<q2>";
        url1+=qq2;//Time update 
        url1+="</q2>";
        url1+="<q3>";
        url1+=qq3;// 
        url1+="</q3>";
        url1+="<q4>";
        url1+=qq4;// 
        url1+="</q4>"; 
        url1+="<q5>";
        url1+=qq5;// 
        url1+="</q5>"; 
        
        url1+="</Donnees>"; 
server.send(200,"text/xml",url1);
} 
void vk_foto_test1(){
     vk_foto1_1=1;
}
 
  
