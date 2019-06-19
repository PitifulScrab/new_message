# Получаем данные из социальных сетей VK Instagram Youtub и выводим на экран
![Главная страница](https://raw.githubusercontent.com/yuri-afanasiev/esp8266-data-social-networks/master/doc/1.png)
## Получает такие параметры:
- vk wall Kоличество лайков
- vk wall Kоличество комментариев
- vk wall Kоличество репостов
- vk wall Kоличество просмотров
- vk Kоличество лайков
- vk Количество участников group
- vk Количество новых сообщений 
- instagram Подписки
- instagram Подписчиков
- instagram Kоличество публикаций
- instagram Количество лайков под последней записью
- instagram Количество просмотров на видео под последней записью 
- instagram Информация о лайках к записи
- instagram Количество просмотров на видео под записью
- youtube Количество подписчиков 
- youtube Количество просмотров на канале
- youtube Количество видео на канале
- youtube Kоличество просмотров на видео 
- youtube Kоличество лайков на видео
- youtube Kоличество дизлайков на видео
- youtube Kоличество комментариев

## Поддерживаемые экраны
- MAX7219 4-матрицы (Din 13 CS 12 CLK 14) 
- MAX7219 7-сегментный (Din 13 CS 12 CLK 14)
- SSD1306 (SDA 4 SCL 5)  
- LCD I2C (SDA 4 SCL 5) 
 
## Установка
Загрузка прошивки с помощью NodeMCU Flasher  https://github.com/nodemcu/nodemcu-flasher
Скачать можно [тут](https://github.com/nodemcu/nodemcu-flasher/blob/master/Win32/Release/ESP8266Flasher.exe)

Последнюю версию прошивки можно скачать из папки [build](https://github.com/yuri-afanasiev/esp8266-data-social-networks/tree/master/build)

Также необходимо скачать файлы, которые нужно установить на сервер и на вкладке Дополнительные настройки прописать к ним путь.
Файлы можно скачать  [тут](https://github.com/yuri-afanasiev/esp8266-vk-api/tree/master/server),[тут](https://github.com/yuri-afanasiev/esp8266-youtube-api/tree/master/server) и [тут](https://github.com/yuri-afanasiev/esp8266-instagram-data/tree/master/server)
 
 ![11](https://raw.githubusercontent.com/yuri-afanasiev/esp8266-data-social-networks/master/doc/11.png)
 ![12](https://raw.githubusercontent.com/yuri-afanasiev/esp8266-data-social-networks/master/doc/12.png)
 
После загрузки создастся точка доступа ESP8266 пароль 12345678 
На вкладке Настройки WIFI прописуем параметры доступа к wifi сети.Сохраняем и перезагружаем.

Доступ к web интерфейсу 
Username admin 
Password admin
![Настройки WIFI](https://raw.githubusercontent.com/yuri-afanasiev/esp8266-data-social-networks/master/doc/13.png)

После каждого сохранения параметров нужно перезагружать систему.
 
