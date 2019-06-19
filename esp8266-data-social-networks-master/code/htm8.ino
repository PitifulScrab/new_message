void api8() {
     k1 = server.arg("k1").toInt();//ON / OFF    i2c 16 2
     k2 = server.arg("k2").toInt();//Time update 
     k3 = server.arg("k3").toInt();//LINE 1  
     k4 = server.arg("k4").toInt();//LINE 2
 

     k5 = server.arg("k5").toInt();//ON / OFF  i2c SSD1306
     k6 = server.arg("k6").toInt();//Time update 
     k7 = server.arg("k7").toInt();//LINE 1  
     k8 = server.arg("k8").toInt();//LINE 2



     k9 = server.arg("k9").toInt();//ON / OFF  MAX7219 4-матрицы
     k10 = server.arg("k10").toInt();//Time update 
     k11 = server.arg("k11").toInt();//LINE    
     k12 = server.arg("k12").toInt();// яркость 0 - 15   
     k13 = server.arg("k13").toInt();// поворот  1 3 


     k14 = server.arg("k14").toInt();//ON / OFF  MAX7219  7-сегмент
     k15 = server.arg("k15").toInt();//Time update 
     k16 = server.arg("k16").toInt();//LINE 
 
     save8();//  запись в память модуля
     server.send(200, "text/plain", "OK");
}
void openfilehtm8() {
  File htm8 = SPIFFS.open("/htm8.json", "r");
  size_t size = htm8.size();
  std::unique_ptr<char[]> buf(new char[size]);
  htm8.readBytes(buf.get(), size);
  StaticJsonBuffer<900> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());
   k1 = json["d1"];// ON / OFF i2c 16 2
   k2 = json["d2"];// Time update  
   k3 = json["d3"];// LINE 1
   k4 = json["d4"];// LINE 2

   k5 = json["d5"];// ON / OFF i2c SSD1306
   k6 = json["d6"];// Time update  
   k7 = json["d7"];// LINE 1
   k8 = json["d8"];// LINE 2

   k9 = json["d9"];// ON / OFF MAX7219 4-матрицы
   k10 = json["d10"];// Time update  
   k11 = json["d11"];// LINE 1
   k12 = json["d12"];// яркость 0 - 15 
   k13 = json["d13"];// поворот  1 3 

   k14 = json["d14"];// ON / OFF MAX7219 7-сегмент 
   k15 = json["d15"];// Time update  
   k16 = json["d16"];// LINE  
} 

bool save8() {
  StaticJsonBuffer<900> jsonBuffer;
  JsonObject& json = jsonBuffer.createObject();
  json["d1"] = k1;//ON / OFF i2c 16 2
  json["d2"] = k2;//Time update 
  json["d3"] = k3;//LINE 1
  json["d4"] = k4;//LINE 2
 

  json["d5"] = k5;//ON / OFF i2c SSD1306
  json["d6"] = k6;//Time update 
  json["d7"] = k7;//LINE 1
  json["d8"] = k8;//LINE 2

  json["d9"] = k9;//ON / OFF MAX7219 4-матрицы
  json["d10"] = k10;//Time update 
  json["d11"] = k11;//LINE 1
  json["d12"] = k12;//яркость 0 - 15   
  json["d13"] = k13;// поворот  1 3  

  json["d14"] = k14;//ON / OFF MAX7219 7-сегмент
  json["d15"] = k15;//Time update 
  json["d16"] = k16;//LINE  
  
  File htm8 = SPIFFS.open("/htm8.json", "w");
  if (!htm8) {   
    return false;
  }
  json.printTo(htm8);
  return true;
}

void htm8xml(){
String  url1="<?xml version='1.0'?>";
        url1+="<Donnees>"; 
        url1+="<q1>";
        url1+=k1;// ON / OFF 
        url1+="</q1>";
        url1+="<q2>";
        url1+=k2;//Time update 
        url1+="</q2>";
        url1+="<q3>";
        url1+=k3;//LINE 1
        url1+="</q3>";
        url1+="<q4>";
        url1+=k4;//LINE 2
        url1+="</q4>";
        url1+="<q5>";
        url1+=k5;//ON / OFF  i2c SSD1306
        url1+="</q5>";
        url1+="<q6>";
        url1+=k6;//Time update 
        url1+="</q6>";
        url1+="<q7>";
        url1+=k7;// LINE 1
        url1+="</q7>";
        url1+="<q8>";
        url1+=k8;// LINE 2
        url1+="</q8>";
        url1+="<q9>";
        url1+=k9;//ON / OFF  MAX7219 4-матрицы
        url1+="</q9>";
        url1+="<q10>";
        url1+=k10;//Time update
        url1+="</q10>";
        url1+="<q11>";
        url1+=k11;//LINE 
        url1+="</q11>";
        url1+="<q12>";
        url1+=k12;//яркость 0 - 15   
        url1+="</q12>";
        url1+="<q13>";
        url1+=k13;// поворот  1 3  
        url1+="</q13>";
        url1+="<q14>";
        url1+=k14;//ON / OFF  MAX7219 7-сегмент    
        url1+="</q14>";
        url1+="<q15>";
        url1+=k15;//Time update    
        url1+="</q15>";
        url1+="<q16>";
        url1+=k16;//LINE     
        url1+="</q16>";
 
        url1+="</Donnees>"; 
server.send(200,"text/xml",url1);
} 
   
 
 void ssd1306_time(){ 
         display_oled.clearDisplay(); //Очистка экрана        
         display_oled.setTextSize(2);
         display_oled.setTextColor(WHITE);
         display_oled.setCursor(25,0);  
 
                     
             if (k7 == 1){ //on/off  
                 display_oled.println(api.likes);//информация о лайках к записи
                }  
             if (k7 == 2){ //on/off  
                 display_oled.println(api.comments);//информация о комментариях к записи 
                }  
             if (k7 == 3){ //on/off  
                 display_oled.println(api.reposts);//информация о репостах записи   
                }  
            if (k7 == 4){ //on/off  
                 display_oled.println(api.views);//информация о просмотрах записи    
                }  
            if (k7 == 5){ //on/off  
                 display_oled.println(api.like_photo);//информация о лайках к фото  
                }      
            if (k7 == 6){ //on/off  
                 display_oled.println(api.participants);//информация о количество участников в группе  
                }   
            if (k7 == 7){ //on/off  
                 display_oled.println(api.messages_new);//Количество непрочитанных сообщений Vk
                } 
            if (k7 == 8){ //on/off  
                 display_oled.println(instagram_data.follows);//instagram Подписки
                } 
             if (k7 == 9){ //on/off  
                 display_oled.println(instagram_data.followed_by);//instagram Подписчиков
                }     
             if (k7 == 10){ //on/off  
                 display_oled.println(instagram_data.media);//instagram Kоличество публикаций 
                } 
             if (k7 == 11){ //on/off  
                 display_oled.println(instagram_data.nodes);//instagram Количество лайков под последней записью 
                }   
             if (k7 == 12){ //on/off  
                 display_oled.println(instagram_data.video_views);//instagram Количество просмотров на видео под последней записью 
                }     
             if (k7 == 13){ //on/off  
                 display_oled.println(instagram_data.media_preview_like );//instagram Информация о лайках к записи 
                }  
             if (k7 == 14){ //on/off  
                 display_oled.println(instagram_data.video_view_count);//instagram Количество просмотров на видео под  записью 
                } 
            if (k7 == 15){ //on/off  
                 display_oled.println(youtube_api.subscriberCount);//Подписчики  
                }                                     
             if (k7 == 16){ //on/off  
                 display_oled.println(youtube_api.viewCount);//Количество просмотров на канале  
                }    
            if (k7 == 17){ //on/off  
                 display_oled.println(youtube_api.videoCount);//Количество видео на канале    
                }    
            if (k7 == 18){ //on/off  
                 display_oled.println(youtube_api.view);//Kоличество просмотров на видео
                }  
            if (k7 == 19){ //on/off  
                 display_oled.println(youtube_api.like);//Kоличество лайков на видео  
                } 
           if (k7 == 20){ //on/off  
                 display_oled.println(youtube_api.dislike);//Kоличество дизлайков на видео  
                }  
           if (k7 == 21){ //on/off  
                 display_oled.println(youtube_api.comment);//Kоличество комментариев   
                }                
/////////////////////////////////////////////////       
      display_oled.setCursor(25,17);
/////////////////////////////////////////////////
              if (k8 == 1){ //on/off  
                 display_oled.println(api.likes);//информация о лайках к записи
                }  
              if (k8 == 2){ //on/off  
                 display_oled.println(api.comments);//информация о комментариях к записи 
                }  
             if (k8 == 3){ //on/off  
                 display_oled.println(api.reposts);//информация о репостах записи   
                }  
             if (k8 == 4){ //on/off  
                 display_oled.println(api.views);//информация о просмотрах записи   
                }    
             if (k8 == 5){ //on/off  
                 display_oled.println(api.like_photo);//информация о лайках к фото  
                }
             if (k8 == 6){ //on/off  
                 display_oled.println(api.participants);//информация о количество участников в группе  
                }    
             if (k8 == 7){ //on/off  
                 display_oled.println(api.messages_new);//Количество непрочитанных сообщений Vk
                }
             if (k8 == 8){ //on/off  
                 display_oled.println(instagram_data.follows);//instagram Подписки
                } 
             if (k8 == 9){ //on/off  
                 display_oled.println(instagram_data.followed_by);//instagram Подписчиков
                }     
             if (k8 == 10){ //on/off  
                 display_oled.println(instagram_data.media);//instagram Kоличество публикаций 
                } 
             if (k8 == 11){ //on/off  
                 display_oled.println(instagram_data.nodes);//instagram Количество лайков под последней записью 
                }   
             if (k8 == 12){ //on/off  
                 display_oled.println(instagram_data.video_views);//instagram Количество просмотров на видео под последней записью 
                }     
             if (k8 == 13){ //on/off  
                 display_oled.println(instagram_data.media_preview_like );//instagram Информация о лайках к записи 
                }  
             if (k8 == 14){ //on/off  
                 display_oled.println(instagram_data.video_view_count);//instagram Количество просмотров на видео под  записью 
                }

             if (k8 == 15){ //on/off  
                 display_oled.println(youtube_api.subscriberCount);//Подписчики  
                }                                     
             if (k8 == 16){ //on/off  
                 display_oled.println(youtube_api.viewCount);//Количество просмотров на канале  
                }    
            if (k8 == 17){ //on/off  
                 display_oled.println(youtube_api.videoCount);//Количество видео на канале    
                }    
            if (k8 == 18){ //on/off  
                 display_oled.println(youtube_api.view);//Kоличество просмотров на видео
                }  
            if (k8 == 19){ //on/off  
                 display_oled.println(youtube_api.like);//Kоличество лайков на видео  
                } 
           if (k8 == 20){ //on/off  
                 display_oled.println(youtube_api.dislike);//Kоличество дизлайков на видео  
                }  
           if (k8 == 21){ //on/off  
                 display_oled.println(youtube_api.comment);//Kоличество комментариев   
                }                
         display_oled.display();  
       
 
 } 
void lcdtime(){ 
     lcd.clear(); //Очистка экрана 
              if (k3 == 1){ //on/off   
                 lcd.print(api.likes);//информация о лайках к записи
                 }  
              if (k3 == 2){ //on/off   
                 lcd.print(api.comments);//информация о комментариях к записи 
                 } 
             if (k3 == 3){ //on/off   
                  lcd.print(api.reposts);//информация о репостах записи  
                 }
             if (k3 == 4){ //on/off   
                   lcd.print(api.views);//информация о просмотрах записи  
                 }    
             if (k3 == 5){ //on/off  
                  lcd.print(api.like_photo);//информация о лайках к фото 
                 } 
             if (k3 == 6){ //on/off  
                  lcd.print(api.participants);//информация о количество участников в группе
                 } 
             if (k3 == 7){ //on/off  
                  lcd.print(api.messages_new);//Количество непрочитанных сообщений Vk 
                 }
              if (k3 == 8){ //on/off  
                  lcd.print(instagram_data.follows);//instagram Подписки 
                 }  
              if (k3 == 9){ //on/off  
                  lcd.print(instagram_data.followed_by);//instagram Подписчиков 
                 }  
              if (k3 == 10){ //on/off  
                  lcd.print(instagram_data.media);//instagram Kоличество публикаций 
                 }  
              if (k3 == 11){ //on/off  
                  lcd.print(instagram_data.nodes);//instagram Количество лайков под последней записью
                 }  
              if (k3 == 12){ //on/off  
                  lcd.print(instagram_data.video_views);//instagram Количество просмотров на видео под последней записью
                 } 
              if (k3 == 13){ //on/off  
                  lcd.print(instagram_data.media_preview_like);//instagram Информация о лайках к записи
                 }  
              if (k3 == 14){ //on/off  
                  lcd.print(instagram_data.video_view_count);//instagram Количество просмотров на видео под записью
                 } 

              if (k3 == 15){ //on/off  
                  lcd.print(youtube_api.subscriberCount);//Подписчики 
                 }  
             if (k3 == 16){ //on/off  
                  lcd.print(youtube_api.viewCount);//Количество просмотров на канале 
                 }  
             if (k3 == 17){ //on/off  
                  lcd.print(youtube_api.videoCount);//Количество видео на канале  
                 } 
             if (k3 == 18){ //on/off  
                  lcd.print(youtube_api.view);//Kоличество просмотров на видео 
                 }   
            if (k3 == 19){ //on/off  
                  lcd.print(youtube_api.like);//Kоличество лайков на видео
                 }  
            if (k3 == 20){ //on/off  
                  lcd.print(youtube_api.dislike);//Kоличество дизлайков на видео  
                 }  
            if (k3 == 21){ //on/off  
                  lcd.print(youtube_api.comment);//Kоличество комментариев  
                 }                                  
                 
//////////////////////////////
lcd.setCursor(0,1);
//////////////////////////////
              if (k4 == 1){ //on/off  
                  lcd.print(api.likes);//информация о лайках к записи
                 } 
              if (k4 == 2){ //on/off  
                  lcd.print(api.comments);//информация о комментариях к записи 
                 }  
              if (k4 == 3){ //on/off  
                  lcd.print(api.reposts);//информация о репостах записи  
                 }  
              if (k4 == 4){ //on/off  
                  lcd.print(api.views);//информация о просмотрах записи  
                 }  
              if (k4 == 5){ //on/off  
                  lcd.print(api.like_photo);//информация о лайках к фото 
                 } 
              if (k4 == 6){ //on/off  
                  lcd.print(api.participants);//информация о количество участников в группе
                 }         
              if (k4 == 7){ //on/off  
                  lcd.print(api.messages_new);//Количество непрочитанных сообщений Vk 
                 }
              if (k4 == 8){ //on/off  
                  lcd.print(instagram_data.follows);//instagram Подписки 
                 }  
              if (k4 == 9){ //on/off  
                  lcd.print(instagram_data.followed_by);//instagram Подписчиков 
                 }  
              if (k4 == 10){ //on/off  
                  lcd.print(instagram_data.media);//instagram Kоличество публикаций 
                 }  
              if (k4 == 11){ //on/off  
                  lcd.print(instagram_data.nodes);//instagram Количество лайков под последней записью
                 }  
              if (k4 == 12){ //on/off  
                  lcd.print(instagram_data.video_views);//instagram Количество просмотров на видео под последней записью
                 } 
              if (k4 == 13){ //on/off  
                  lcd.print(instagram_data.media_preview_like);//instagram Информация о лайках к записи
                 }  
              if (k4 == 14){ //on/off  
                  lcd.print(instagram_data.video_view_count);//instagram Количество просмотров на видео под записью
                 }    

             if (k4 == 15){ //on/off  
                  lcd.print(youtube_api.subscriberCount);//Подписчики 
                 }  
             if (k4 == 16){ //on/off  
                  lcd.print(youtube_api.viewCount);//Количество просмотров на канале 
                 }  
             if (k4 == 17){ //on/off  
                  lcd.print(youtube_api.videoCount);//Количество видео на канале  
                 } 
             if (k4 == 18){ //on/off  
                  lcd.print(youtube_api.view);//Kоличество просмотров на видео 
                 }   
            if (k4 == 19){ //on/off  
                  lcd.print(youtube_api.like);//Kоличество лайков на видео
                 }  
            if (k4 == 20){ //on/off  
                  lcd.print(youtube_api.dislike);//Kоличество дизлайков на видео  
                 }  
            if (k4 == 21){ //on/off  
                  lcd.print(youtube_api.comment);//Kоличество комментариев  
                 }                                                               
   
}
void oled_ssd1306_test1(){
     oled_ssd1306_test1_1=1;
} 
void display_lcd_test1(){
     display_lcd_test1_1=1;
}
void display_max7219_matrix_test1(){
     display_max7219_matrix1_1=1;
}
void display_max7219_segment_test1(){
     display_max7219_segment1_1=1;
}
void display_max7219_matrix(){
     String  matrix_url;
         if (k11 == 1){ //on/off   
             matrix7219_running("like ");  
             matrix_url+=api.likes;//информация о лайках к записи  
             matrix7219_text(matrix_url);
            }  
            if (k11 == 2){ //on/off   
             matrix7219_running("comments ");  
             matrix_url+=api.comments;//информация о комментариях к записи   
             matrix7219_text(matrix_url);
            }  
            if (k11 == 3){ //on/off   
             matrix7219_running("reposts ");  
             matrix_url+=api.reposts;//информация о репостах записи   
             matrix7219_text(matrix_url);
            }  
            if (k11 == 4){ //on/off   
             matrix7219_running("views ");  
             matrix_url+=api.views;//информация о просмотрах записи   
             matrix7219_text(matrix_url);
            }  
            if (k11 == 5){ //on/off   
             matrix7219_running("likes ");  
             matrix_url+=api.like_photo;//информация о лайках к фото   
             matrix7219_text(matrix_url);
            }  
            if (k11 == 6){ //on/off   
             matrix7219_running("group ");  
             matrix_url+=api.participants;//информация о количество участников в группе   
             matrix7219_text(matrix_url);
            }  
            if (k11 == 7){ //on/off   
             matrix7219_running("messages new ");  
             matrix_url+=api.messages_new;//Количество непрочитанных сообщений Vk   
             matrix7219_text(matrix_url);
            }  
            if (k11 == 8){ //on/off   
             matrix7219_running("follows ");  
             matrix_url+=instagram_data.follows;//instagram Подписки  
             matrix7219_text(matrix_url);
            }  
            if (k11 == 9){ //on/off   
             matrix7219_running("followed_by ");  
             matrix_url+=instagram_data.followed_by;//instagram Подписчиков  
             matrix7219_text(matrix_url);
            }  
            if (k11 == 10){ //on/off   
             matrix7219_running("media ");  
             matrix_url+=instagram_data.media;//instagram Kоличество публикаций 
             matrix7219_text(matrix_url);
            }  
            if (k11 == 11){ //on/off   
             matrix7219_running("last post like ");  
             matrix_url+=instagram_data.nodes;//instagram Количество лайков под последней записью 
             matrix7219_text(matrix_url);
            }  
            if (k11 == 12){ //on/off   
             matrix7219_running("video views ");  
             matrix_url+=instagram_data.video_views;//instagram Количество просмотров на видео под последней записью 
             matrix7219_text(matrix_url);
            }  
            if (k11 == 13){ //on/off   
             matrix7219_running("post like ");  
             matrix_url+=instagram_data.media_preview_like;//instagram Информация о лайках к записи 
             matrix7219_text(matrix_url);
            }  
            if (k11 == 14){ //on/off   
             matrix7219_running("video view post ");  
             matrix_url+=instagram_data.video_view_count;//instagram Количество просмотров на видео под записью 
             matrix7219_text(matrix_url);
            }  
            if (k11 == 115){ //on/off   instagram Аккаунт (бегущая строка)
             String running_string; 
             running_string += " username  ";
             running_string += instagram_data.username;
             running_string += "  followed_by  ";
             running_string += instagram_data.followed_by; 
             running_string += "  last post like  ";
             matrix7219_running(running_string); 
             matrix_url+=instagram_data.nodes; 
             matrix7219_text(matrix_url);
            } 

                 
            if (k11 == 15){ //on/off   
             matrix7219_running("Subscribers ");  
             matrix_url+=youtube_api.subscriberCount;//youtube Количество подписчиков  
             matrix7219_text(matrix_url);
            }   
           if (k11 == 16){ //on/off   
             matrix7219_running("view channel ");  
             matrix_url+=youtube_api.viewCount;//youtube Количество просмотров на канале  
             matrix7219_text(matrix_url);
            }    
           if (k11 == 17){ //on/off   
             matrix7219_running("video on the channel ");  
             matrix_url+=youtube_api.videoCount;//youtube Количество видео на канале  
             matrix7219_text(matrix_url);
            } 
          if (k11 == 18){ //on/off   
             matrix7219_running("view ");  
             matrix_url+=youtube_api.view;//youtube Kоличество просмотров на видео  
             matrix7219_text(matrix_url);
            }   
          if (k11 == 19){ //on/off   
             matrix7219_running("like ");  
             matrix_url+=youtube_api.like;//youtube Kоличество лайков на видео  
             matrix7219_text(matrix_url);
            }      
         if (k11 == 20){ //on/off   
             matrix7219_running("dislike ");  
             matrix_url+=youtube_api.dislike;//youtube Kоличество дизлайков на видео  
             matrix7219_text(matrix_url);
            } 
         if (k11 == 21){ //on/off   
             matrix7219_running("comment ");  
             matrix_url+= youtube_api.comment;//youtube Kоличество комментариев  
             matrix7219_text(matrix_url);
            }    
        if (k11 == 121){ //on/off  youtube Канал (бегущая строка)
             String running_string; 
             running_string += "video on the channel  ";
             running_string += youtube_api.videoCount;//Количество видео на канале 
             running_string += "view channel  ";
             running_string += youtube_api.viewCount ;//Количество просмотров на канале  
             running_string += "Subscribers   ";
             matrix7219_running(running_string); 
             matrix_url+=youtube_api.subscriberCount;//Подписчики 
             matrix7219_text(matrix_url);
            }    
                      
       if (k11 == 122){ //on/off  youtube Видео (бегущая строка)
             String running_string; 
             running_string += " like  ";
             running_string += youtube_api.like;//Kоличество лайков на видео 
             running_string += " dislike ";
             running_string += youtube_api.dislike;//Kоличество дизлайков на видео
             running_string += " view ";
             matrix7219_running(running_string); 
             matrix_url+=youtube_api.view;//Kоличество просмотров на видео
             matrix7219_text(matrix_url);
            }  
}
void display_max7219_segment(){
     HCMAX7219.Clear(); 
     if (k16 == 1){ //on/off   
         HCMAX7219.print7Seg(api.likes,8);//информация о лайках к записи   
         HCMAX7219.Refresh();
        }
    if (k16 == 2){ //on/off   
         HCMAX7219.print7Seg(api.comments,8);//информация о комментариях к записи    
         HCMAX7219.Refresh();
        }   
    if (k16 == 3){ //on/off   
         HCMAX7219.print7Seg(api.reposts,8);//информация о репостах записи   
         HCMAX7219.Refresh();
        }  
   if (k16 == 4){ //on/off   
         HCMAX7219.print7Seg(api.views,8);//информация о просмотрах записи      
         HCMAX7219.Refresh();
        }  
   if (k16 == 5){ //on/off   
         HCMAX7219.print7Seg(api.like_photo,8);//информация о лайках к фото 
         HCMAX7219.Refresh();
        }   
   if (k16 == 6){ //on/off   
         HCMAX7219.print7Seg(api.participants,8);//информация о количество участников в группе 
         HCMAX7219.Refresh();
        } 
   if (k16 == 7){ //on/off   
         HCMAX7219.print7Seg(api.messages_new,8);//Количество непрочитанных сообщений Vk   
         HCMAX7219.Refresh();
        }    
        
   if (k16 == 8){ //on/off   
         HCMAX7219.print7Seg(instagram_data.follows,8);//instagram Подписки   
         HCMAX7219.Refresh();
        }   
   if (k16 == 9){ //on/off   
         HCMAX7219.print7Seg(instagram_data.followed_by,8);//instagram Подписчиков   
         HCMAX7219.Refresh();
        }      
   if (k16 == 10){ //on/off   
         HCMAX7219.print7Seg(instagram_data.media,8);//instagram Kоличество публикаций   
         HCMAX7219.Refresh();
        }      
   if (k16 == 11){ //on/off   
         HCMAX7219.print7Seg(instagram_data.nodes,8);//instagram Количество лайков под последней записью  
         HCMAX7219.Refresh();
        }          
   if (k16 == 12){ //on/off   
         HCMAX7219.print7Seg(instagram_data.video_views,8);//instagram Количество просмотров на видео под последней записью 
         HCMAX7219.Refresh();
        }      
   if (k16 == 13){ //on/off   
         HCMAX7219.print7Seg(instagram_data.media_preview_like,8);//instagram Информация о лайках к записи
         HCMAX7219.Refresh();
        }     
   if (k16 == 14){ //on/off   
         HCMAX7219.print7Seg(instagram_data.video_view_count,8);//instagram Количество просмотров на видео под записью
         HCMAX7219.Refresh();
        } 

  if (k16 == 15){ //on/off   
         HCMAX7219.print7Seg(youtube_api.subscriberCount,8);//youtube Количество подписчиков 
         HCMAX7219.Refresh();
          
        } 
  if (k16 == 16){ //on/off   
         HCMAX7219.print7Seg(youtube_api.viewCount,8);//youtube Количество просмотров на канале
         HCMAX7219.Refresh();
        }       
  if (k16 == 17){ //on/off   
         HCMAX7219.print7Seg(youtube_api.videoCount,8);//youtube Количество видео на канале
         HCMAX7219.Refresh();
        }     
  if (k16 == 18){ //on/off   
         HCMAX7219.print7Seg(youtube_api.view,8);//youtube Kоличество просмотров на видео
         HCMAX7219.Refresh();
        }   
  if (k16 == 19){ //on/off   
         HCMAX7219.print7Seg(youtube_api.like,8);//youtube Kоличество лайков на видео
         HCMAX7219.Refresh();
        }     
  if (k16 == 20){ //on/off   
         HCMAX7219.print7Seg(youtube_api.dislike,8);//youtube Kоличество дизлайков на видео
         HCMAX7219.Refresh();
        }
  if (k16 == 21){ //on/off   
         HCMAX7219.print7Seg(youtube_api.comment,8);//youtube Kоличество комментариев
         HCMAX7219.Refresh();
        }                                                                                                                       
}

