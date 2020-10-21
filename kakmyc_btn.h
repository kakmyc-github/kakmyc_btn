/* myBtn_constructor.h by kakmyc 2019©
Library for processing signal from button 
Types of signal: once/double/multiple/long */


#ifndef kakmyc_btn_h
#define kakmyc_btn_h
#include <Arduino.h>

class kakmyc_btn//создадим класс кнопок
{public://общие функции и переменные
    //конструктор класса
    kakmyc_btn(byte pin,byte state,byte val);   
    byte read();//функция обработчика нажатий
private://личные переменные и функции класса
    //локальные переменные обьекта номер пина/тип сигнала/количество кликов
 byte _pin,_state,_val;
 uint16_t start_press;//переменная времени нажатия кнопки
 uint16_t pressTime;//переменная длительности нажатия кнопки
 uint16_t double_press;//переменная времени между нажатиями
 boolean pressFlag;//переменная флага нажатия
 byte press_one;//переменная количества нажатий
//переменные состояния/временного состояния/нажатия кнопки
 byte num,_num,button; 
};

#endif
