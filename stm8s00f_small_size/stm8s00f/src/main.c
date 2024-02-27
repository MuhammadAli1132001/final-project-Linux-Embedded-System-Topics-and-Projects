#include "Arduino.h"
//#include "jk_bms.h"
#include "lcd.h"
#include "menu.h"


// static uint8_t receivedBuffer[RECEVIED_BUFFER_LENGTH];

// static unsigned long previousMillis = 0;
// static unsigned long beePpreviousMillis = 0;

extern byte menuLevel;
extern char buttonPressed;


uint8_t ledState = LOW;

//extern LiquidCrystal(lcd, PD3, PD1, PC7, PC6, PC5, PC4);

void setup()  {
  Serial_begin(115200);
  configure_menu_button();
  configureLcdPins();
  lcdInitialization();
  //lcd_clear();
  create_char();
  //lcd_begin(16,2);
  pinMode(PB5,OUTPUT);

} 

void loop()  {
  
 
  checkButton();

  //lcd_string("salam",5);
  // if (menuLevel ==0){
  //lcd_print_s("2salam");
  // lcd_setCursor(0,0);
  // lcd_print_c(buttonPressed);
 // processButton(buttonPressed);


  // pinMode(PB5,HIGH);
  // delay(10);
  // pinMode(PB5,LOW);
  // delay(10);    
  
}

// void processBMSdata(uint8_t *data)
// {
//   uint8_t    lcdWorkingBuffer[16];
//   // uint8_t    RemainingCapacity = 0;
//   uint16_t   current = 0;
//   uint16_t   voltage = 0;
//   uint16_t   Power = 0;
//   uint8_t    DistanceRemaining;

//   lcd_cmd(0x02);
//   voltage = (uint16_t)data[0] << 8 | data[1];         //volatge two combine byte 
//   current = (uint16_t)data[2] << 8 | data[3];         //current two combine byte 
//   RemainingCapacity = data[4];                        //Capacity one byte


//   Power = (uint16_t)voltage /100 * current /100;      //calculation for power
//   DistanceRemaining = RemainingCapacity * 0.6;        //calculation for remaining distance

//   lcd_set_cursor(0,0);
//   intToString(RemainingCapacity, lcdWorkingBuffer, sizeof(lcdWorkingBuffer));            //print Capacity
//   lcd_string(lcdWorkingBuffer, strlen(lcdWorkingBuffer));
//   lcd_string("%",1);

//   lcd_set_cursor(0,5);
//   intToString(DistanceRemaining, lcdWorkingBuffer, sizeof(lcdWorkingBuffer));         //print DistanceRemaining
//   lcd_string(lcdWorkingBuffer, strlen(lcdWorkingBuffer));
//   lcd_string("KM ",3);

//   lcd_set_cursor(0,10);
//   intToString(current/100, lcdWorkingBuffer, sizeof(lcdWorkingBuffer));               //print Current
//   lcd_string(lcdWorkingBuffer, strlen(lcdWorkingBuffer));
//   lcd_string(".",1);
//   intToString(current%100, lcdWorkingBuffer, sizeof(lcdWorkingBuffer));     
//   lcd_string(lcdWorkingBuffer, strlen(lcdWorkingBuffer));
//   lcd_string("A ",2);

//   lcd_set_cursor(1,0);
//   intToString(voltage/100, lcdWorkingBuffer, sizeof(lcdWorkingBuffer));              //print Voltage
//   lcd_string(lcdWorkingBuffer, strlen(lcdWorkingBuffer));
//   lcd_string(".",1);
//   intToString(voltage%100, lcdWorkingBuffer, sizeof(lcdWorkingBuffer));
//   lcd_string(lcdWorkingBuffer, strlen(lcdWorkingBuffer));
//   lcd_string("V",1);

//   lcd_set_cursor(1,10);
//   if(Power !=0 ){
//   intToString(Power/100, lcdWorkingBuffer, sizeof(lcdWorkingBuffer));            //print power upto 2 dec place
//   lcd_string(lcdWorkingBuffer, strlen(lcdWorkingBuffer));
//   //lcd_string(".",1);
//   intToString(Power%100, lcdWorkingBuffer, sizeof(lcdWorkingBuffer));
//   lcd_string(lcdWorkingBuffer, strlen(lcdWorkingBuffer));
//   lcd_string(".",1);
//   intToString(Power%10, lcdWorkingBuffer, sizeof(lcdWorkingBuffer));
//   lcd_string(lcdWorkingBuffer, strlen(lcdWorkingBuffer));
//   lcd_string("W ",2);
//   }
//   else {
//   intToString(Power%100, lcdWorkingBuffer, sizeof(lcdWorkingBuffer));          //print power upto 1 dec place
//   lcd_string(lcdWorkingBuffer, strlen(lcdWorkingBuffer));
//   lcd_string(".",1);
//   intToString(Power%10, lcdWorkingBuffer, sizeof(lcdWorkingBuffer));
//   lcd_string(lcdWorkingBuffer, strlen(lcdWorkingBuffer));
//   lcd_string("W  ",3);
//   }
//  }