#include <Wire.h> 											// Подключаем библиотеку Wire.h
#include <LiquidCrystal_I2C.h>								// Подключаем библиотеку LiquidCrystal_I2C
#include <iarduino_RTC.h>                                   // Подключаем библиотеку iarduino_RTC для работы с модулями реального времени.
iarduino_RTC time(RTC_DS1302, 10, 13, 12);                  // Объявляем объект time для работы с RTC модулем на базе чипа DS1302, указывая выводы Arduino подключённые к выводам модуля RST, CLK, DAT
LiquidCrystal_I2C lcd(0x3F,16,2);							// Указываем с каким именно дисплеем будем иметь дело
int pwm;


void setup(){                                               
    delay(300);                                             // Ждем готовности модуля отвечать на запросы
    Serial.begin(9600);                                     // Инициируем передачу данных в монитор последовательного порта на скорости 9600 бод.
    time.begin();                                           // Инициируем работу с модулем.
    lcd.init();                                             // Инициируем дисплей 
    lcd.backlight();										// Включаем подсветку
    } 
    

     
void loop(){
   if(millis()%1000==0){                                    // Если прошла 1 секунда.
      lcd.setCursor(3,0);									// Устанавливаем курсор
      lcd.print(time.gettime("H:i:s"));                     // Выводим время.
      lcd.setCursor(0,1);									// Устанавливаем курсор
      lcd.print(time.gettime("d-m-Y, D"));                  // Выводим время.
      delay(1);}                                            // Приостанавливаем скетч на 1 мс, чтоб не выводить время несколько раз за 1мс.
      MyFunction();
}



void MyFunction(){
  pwm = analogRead(0);                                      //Читаем с аналогого А0
  pwm = map(pwm, 390, 1023, 0, 255);                        //Конвертируем диапазоны
  pwm = constrain(pwm, 5, 255);                             //Ограничиваем диапозон
  analogWrite(5, pwm);                                      //Жарим ШИМ на D5
}               
