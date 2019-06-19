void matrix7219_running(String tape_text) {
     int wait = 55; //задержка в миллисекундах 
     int spacer = 1;
     int width = 5 + spacer; //Ширина шрифта-5 пикселей
     for ( int i = 0 ; i < width * tape_text.length() + matrix.width() - 1 - spacer; i++ ) {
            matrix.fillScreen(LOW);
           
            int letter = i / width;
            int x = (matrix.width() - 1) - i % width;
            int y = (matrix.height() - 8) / 2; // center the text vertically
            while ( x + width - spacer >= 0 && letter >= 0 ) {
                   if ( letter < tape_text.length() ) {
                        matrix.drawChar(x, y, tape_text[letter], HIGH, LOW, 1);
                      }
                   letter--;
                   x -= width;
                  }
 
            matrix.write();//Отправить  для отображения
            delay(wait);
          }
}
void matrix7219_text (String tape) {
    int spacer = 1;
    int width = 5 + spacer; // The font width is 5 pixels
    int x = (matrix.width() - (tape.length() * width)) / 2; //выравнивание по центру X
    int y = (matrix.height() - 8) / 2; //выравнивание по центру Y
    matrix.fillScreen(LOW);
    for ( int i = 0 ; i < tape.length(); i++ ) {  
          int letter = i;
          matrix.drawChar(x, y, tape[letter], HIGH, LOW, 1);  
          x += width; 
        }
    matrix.write(); // отправка данных на дисплей
}
 
