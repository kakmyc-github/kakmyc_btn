#include "Arduino.h"
#include "kakmyc_btn.h"
#define _bounce_time 50
#define _long_press 1500
#define _wait_multiclick 300

//функции класса Btn(обработчик кнопок)
byte kakmyc_btn::read(){ 
uint16_t _millis=millis();
!_state?button=digitalRead(_pin):button=!digitalRead(_pin);//в зависимости от того, что в конструкторе настраиваем кнопку
	if(!button){num=0;}//если кнопка отпущена, выдаем результат 0
	if(button&&!pressFlag)//если кнопка нажата и флаг опущен
	{pressTime=_millis-start_press;//считаем время нажатия кнопки
		if(pressTime>=_long_press){//если длительность нажатия больше 1,5 сек
			pressFlag=1;//поднимаем флаг
num=255;//значение кнопки long
pressTime=0;//сбрасываем длительность нажатия
		}		}
	if(!button){//если кнопка отпущена
 start_press=_millis;//сбрасываем время нажатия
pressFlag=0;//опускаем флаг
}

	if(!button&&!pressFlag){//если кнопка и флаг отпущены
		if(pressTime>_bounce_time&&pressTime<_long_press)//а время нажатия больше 50мс, но меньше 1,5сек
		{press_one++;//увеличиваем счетчик количества нажатий
 if(press_one>_val)press_one=_val;//ограничиваем значение счетчика
 pressTime=0;//сбрасываем длительность нажатия
 double_press=_millis;//запускаем таймер ожидания следующего нажатия
    }}
if(press_one){//если было короткое нажатие
if(_millis-double_press>=_wait_multiclick){//ждем 0,3сек
pressTime=0;//сбрасываем длительность нажатия
num=press_one;//значение кнопки приравниваем к количеству нажатий
press_one=0;//сбрасываем количество нажатий
  }}
_num=num;//для одиночного вывода результата, используем временную переменную
num=0;//обнудяем основную переменную значения кнопки
	return _num;//возвращаем значение кнопки
}
//функция конструктора класса
/*в конструкторе указываем:
номер пина
тип сигнала (лог0/лог1)
максимальное количество отслеживаемых кликов*/
kakmyc_btn::kakmyc_btn(byte pin,byte state,byte val)
{_pin = pin;//передаем внутренней переменной номер пина
//!state?_state=2:_state=0;//в зависимости от выбранного типа сигнала меняем значение переменной
_state=state;
_val=val;//передаем внутренней переменной количество кликов
 pinMode(pin,_state);//конфигурируем пин согласно типа сигнала
    }
