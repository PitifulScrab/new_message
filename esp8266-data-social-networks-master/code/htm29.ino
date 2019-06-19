void api29() {
     zz1 = server.arg("zz1");//     
     zz2 = server.arg("zz2");// 
     zz3 = server.arg("zz3");// 
     zz4 = server.arg("zz4");//  
     zz5 = server.arg("zz5");// 
     zz6 = server.arg("zz6");//  
     
     save29();//  запись в память модуля
     server.send(200, "text/plain", "OK");
}
void openfilehtm29() {
  File htm29 = SPIFFS.open("/htm29.json", "r");
  size_t size = htm29.size();
  std::unique_ptr<char[]> buf(new char[size]);
  htm29.readBytes(buf.get(), size);
  StaticJsonBuffer<900> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());
   String ezz1 = json["d1"];//    
   String ezz2 = json["d2"];//   
   String ezz3 = json["d3"];//  
   String ezz4 = json["d4"];// 
   String ezz5 = json["d5"];// 
   String ezz6 = json["d6"];//
   zz1=ezz1;
   zz2=ezz2;
   zz3=ezz3;
   zz4=ezz4;
   zz5=ezz5;
   zz6=ezz6;
} 

bool save29() {
  StaticJsonBuffer<900> jsonBuffer;
  JsonObject& json = jsonBuffer.createObject();
  json["d1"] = zz1;//   
  json["d2"] = zz2;// 
  json["d3"] = zz3;// 
  json["d4"] = zz4;// 
  json["d5"] = zz5;//
  json["d6"] = zz6;// 
  
  
  File htm29 = SPIFFS.open("/htm29.json", "w");
  if (!htm29) {   
    return false;
  }
  json.printTo(htm29);
  return true;
}

void htm29xml(){
String  url1="<?xml version='1.0'?>";
        url1+="<Donnees>"; 
        url1+="<q1>";
        url1+=zz1;//  
        url1+="</q1>";
        url1+="<q2>";
        url1+=zz2;// 
        url1+="</q2>";
        url1+="<q3>";
        url1+=zz3;// 
        url1+="</q3>";
        url1+="<q4>";
        url1+=zz4;// 
        url1+="</q4>"; 
        url1+="<q5>";
        url1+=zz5;// 
        url1+="</q5>"; 
        url1+="<q6>";
        url1+=zz6;// 
        url1+="</q6>"; 
        
        url1+="</Donnees>"; 
server.send(200,"text/xml",url1);
} 
