void serveron() {
   server.on("/esp_update", [](){//Обнавление   
   if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       String fs_bin_test = server.arg("fs_bin");//fs 
       String code_bin_test = server.arg("code_bin");//code
       esp_update(fs_bin_test,code_bin_test);
     }); 
     server.on("/test", [](){    
   if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       xmltest();
     }); 
    server.on("/xml1", [](){    
   if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       testxml();
     });  
        server.on("/xml8", [](){    
   if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       htm8xml();
     });   
         server.on("/xml9", [](){    
   if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       htm9xml();
     });   
   
   server.on("/xml19", [](){    
   if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       htm19xml();
     }); 
      server.on("/xml29", [](){    
   if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       htm29xml();
     });  
  server.on("/xml30", [](){    
   if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       htm30xml();
     });  
      server.on("/xml31", [](){    
   if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       htm31xml();
     });   
   server.on("/xml32", [](){    
   if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       htm32xml();
     });   
   server.on("/xml33", [](){    
   if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       htm33xml();
     });   
   server.on("/xml34", [](){    
   if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       htm34xml();
     });  
   server.on("/xml35", [](){    
   if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       htm35xml();
     });    

     
   server.on("/api", [](){    
     if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       api_1();
     });  
     server.on("/api8", [](){    
     if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       api8();
     }); 
       server.on("/api29", [](){    
     if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       api29();
     }); 
    server.on("/api30", [](){    
     if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       api30();
     }); 
      server.on("/api31", [](){    
     if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       api31();
     }); 
      server.on("/api32", [](){    
     if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       api32();
     }); 
       server.on("/api33", [](){    
     if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       api33();
     }); 
      server.on("/api34", [](){    
     if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       api34();
     }); 
      server.on("/api35", [](){    
     if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       api35();
     }); 
  server.on("/i2c/lcd/off", [](){
       if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       lcd.noBacklight();
       server.send(200, "text/plain", "ok");        
   }); 
    server.on("/i2c/lcd/on", [](){
       if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       lcd.backlight(); 
       server.send(200, "text/plain", "ok");        
   }); 
    server.on("/reset", [](){
     if(!server.authenticate(w5.c_str(),w6.c_str()))
        return server.requestAuthentication();  
        server.send(200, "text/plain", "ok");
        ESP.restart();    
     }); 
     
      
      server.on("/api19", [](){    
     if(!server.authenticate(w5.c_str(),w6.c_str()))
       return server.requestAuthentication();  
       api19();
     });   
     
      
     
    
    server.on("/config.json", [](){      
    server.send(403, "text/plain", "Forbidden");       
    });  
    server.on("/htm19.json", [](){      
    server.send(403, "text/plain", "Forbidden");       
     }); 
    server.on("/htm33.json", [](){      
    server.send(403, "text/plain", "Forbidden");       
     }); 
     
     server.onNotFound([](){
     if(!handleFileRead(server.uri()))
         server.send(404, "text/plain", "FileNotFound");
        }); 
        server.on("/list", HTTP_GET, handleFileList);  
        server.on("/edit", HTTP_GET, [](){
         if(!handleFileRead("/edit.htm")) server.send(404, "text/plain", "FileNotFound");
            });         
         server.on("/edit", HTTP_PUT, handleFileCreate); 
         server.on("/edit", HTTP_DELETE, handleFileDelete);
         server.on("/edit", HTTP_POST, [](){ server.send(200, "text/plain", ""); }, handleFileUpload);
         server.begin();
    
}
