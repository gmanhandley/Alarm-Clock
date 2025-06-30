//each digit has a function and each number it can display has a function. The idea is to set each digit individually and swap between them imperceptively fast.

/*
 * The clock countes accurately.
 * The minutes and hours can be manualy incremented by one using buttons.
 */

 /*
  * Things I have learned:
  * reading pinout diagrams
  * creation of basic embedded systems
  * using classes to take in information and make an output
  * using while loops to prevent repeated presses of button
  * electrical wiring of 7 segment display, buttons, and passive buzzers
  * arduino includes some built in functions such as millis()
  * improved logical problem solving with if stateaments in basic clock counter
  */
  
//pins for 4 number 7 segement display
int dig1=A5;
int dig2=A4;
int dig3=A3;
int dig4=A2;
int Apin=6;
int Bpin=7;
int Cpin=8;
int Dpin=9;
int Epin=10;
int Fpin=11;
int Gpin=12;
int dec=13;

//pins for buttons
int hourButton=3;
int minuteButton=2;
int alarmButton=4;

int buzzerPin=5;

//minute incrementer
int addMinute=0;

//initial time values
int minute=0;
int tenMinute=0;
int hour=1;
int tenHour=0;

//alarm integers
int alarmMinute=0;
int alarmTenMinute=0;
int alarmHour=1;
int alarmTenHour=0;

//other variables used as counters and trackers
int counter=0;
int couterMinute;
int counterHour;
int tenMinuteCounter=0;
int minuteinf;
int minuteButtonRead;
int hourButtonRead;
int alarmButtonRead;
bool settingAlarm=false;

//this wait value is the delay betweendisplaying each number. smaller number makes all numbers appear at all digits. larger number causes visual flashing
int wait=3;

class Digit {
  public:
    Digit(int place,int number){
      if (place == A5){
        digitalWrite(dig1,0);
        digitalWrite(dig2,255);
        digitalWrite(dig3,255);
        digitalWrite(dig4,255);
        digitalWrite(dec,0);
      }
      if (place == A4){
        digitalWrite(dig1,255);
        digitalWrite(dig2,0);
        digitalWrite(dig3,255);
        digitalWrite(dig4,255);
        digitalWrite(dec,255);
      }
      if (place == A3){
        digitalWrite(dig1,255);
        digitalWrite(dig2,255);
        digitalWrite(dig3,0);
        digitalWrite(dig4,255);
        digitalWrite(dec,0);
      }
      if (place == A2){
        digitalWrite(dig1,255);
        digitalWrite(dig2,255);
        digitalWrite(dig3,255);
        digitalWrite(dig4,0);
        digitalWrite(dec,0);
      }
      if (number == 0){
        digitalWrite(Apin,HIGH);
        digitalWrite(Bpin,HIGH);
        digitalWrite(Cpin,HIGH);
        digitalWrite(Dpin,HIGH);
        digitalWrite(Epin,HIGH);
        digitalWrite(Fpin,HIGH);
        digitalWrite(Gpin,LOW);
      } 
      if (number == 1){
        digitalWrite(Apin,LOW);
        digitalWrite(Bpin,HIGH);
        digitalWrite(Cpin,HIGH);
        digitalWrite(Dpin,LOW);
        digitalWrite(Epin,LOW);
        digitalWrite(Fpin,LOW);
        digitalWrite(Gpin,LOW);
      }
      if (number == 2){
        digitalWrite(Apin,HIGH);
        digitalWrite(Bpin,HIGH);
        digitalWrite(Cpin,LOW);
        digitalWrite(Dpin,HIGH);
        digitalWrite(Epin,HIGH);
        digitalWrite(Fpin,LOW);
        digitalWrite(Gpin,HIGH);
      }
      if (number == 3){
        digitalWrite(Apin,HIGH);
        digitalWrite(Bpin,HIGH);
        digitalWrite(Cpin,HIGH);
        digitalWrite(Dpin,HIGH);
        digitalWrite(Epin,LOW);
        digitalWrite(Fpin,LOW);
        digitalWrite(Gpin,HIGH);
      }
      if (number == 4){
        digitalWrite(Apin,LOW);
        digitalWrite(Bpin,HIGH);
        digitalWrite(Cpin,HIGH);
        digitalWrite(Dpin,LOW);
        digitalWrite(Epin,LOW);
        digitalWrite(Fpin,HIGH);
        digitalWrite(Gpin,HIGH);
      }
      if (number == 5){
        digitalWrite(Apin,HIGH);
        digitalWrite(Bpin,LOW);
        digitalWrite(Cpin,HIGH);
        digitalWrite(Dpin,HIGH);
        digitalWrite(Epin,LOW);
        digitalWrite(Fpin,HIGH);
        digitalWrite(Gpin,HIGH);
      }
      if (number == 6){
        digitalWrite(Apin,LOW);
        digitalWrite(Bpin,LOW);
        digitalWrite(Cpin,HIGH);
        digitalWrite(Dpin,HIGH);
        digitalWrite(Epin,HIGH);
        digitalWrite(Fpin,HIGH);
        digitalWrite(Gpin,HIGH);
      }
      if (number == 7){
        digitalWrite(Apin,HIGH);
        digitalWrite(Bpin,HIGH);
        digitalWrite(Cpin,HIGH);
        digitalWrite(Dpin,LOW);
        digitalWrite(Epin,LOW);
        digitalWrite(Fpin,LOW);
        digitalWrite(Gpin,LOW);
      }
      if (number == 8){
        digitalWrite(Apin,HIGH);
        digitalWrite(Bpin,HIGH);
        digitalWrite(Cpin,HIGH);
        digitalWrite(Dpin,HIGH);
        digitalWrite(Epin,HIGH);
        digitalWrite(Fpin,HIGH);
        digitalWrite(Gpin,HIGH);
      }
      if (number == 9){
        digitalWrite(Apin,HIGH);
        digitalWrite(Bpin,HIGH);
        digitalWrite(Cpin,HIGH);
        digitalWrite(Dpin,LOW);
        digitalWrite(Epin,LOW);
        digitalWrite(Fpin,HIGH);
        digitalWrite(Gpin,HIGH);
      }
    }
};

void setup() {
  Serial.begin(9600);
  pinMode(dig1,OUTPUT);
  pinMode(dig2,OUTPUT);
  pinMode(dig3,OUTPUT);
  pinMode(dig4,OUTPUT);
  pinMode(Apin,OUTPUT);
  pinMode(Bpin,OUTPUT);
  pinMode(Cpin,OUTPUT);
  pinMode(Dpin,OUTPUT);
  pinMode(Epin,OUTPUT);
  pinMode(Fpin,OUTPUT);
  pinMode(Gpin,OUTPUT);
  pinMode(dec,OUTPUT);
  pinMode(hourButton,INPUT);
  pinMode(minuteButton,INPUT);
  pinMode(buzzerPin,OUTPUT);
}

void loop() {
  minuteButtonRead = digitalRead(minuteButton);
  hourButtonRead = digitalRead(hourButton);
  alarmButtonRead = digitalRead(alarmButton);

//setting alarm
  counter=0;
  while (alarmButtonRead == 0){
    if (counter == 0){
      counter++;
      settingAlarm = true;
    }
    alarmButtonRead = digitalRead(alarmButton);
  }
  counter=0;
  while (settingAlarm == true){
    minuteButtonRead = digitalRead(minuteButton);
    hourButtonRead = digitalRead(hourButton);
    alarmButtonRead = digitalRead(alarmButton);
    counter=0;
    while (alarmButtonRead == 0){
      if (counter == 0){
        counter++;
        settingAlarm = false;
      }
    alarmButtonRead = digitalRead(alarmButton);
    }
    while (minuteButtonRead == 0){
      if (counter == 0){
        counter++;
        alarmMinute++;
        if(alarmMinute >= 10){
          alarmMinute=0;
          alarmTenMinute++;
          if(alarmTenMinute >= 6){
            alarmTenMinute=0;
            alarmHour=1;
          }
        }
      }
      minuteButtonRead = digitalRead(minuteButton);
      hourButtonRead = digitalRead(hourButton);
    }
    counter=0;
    while (hourButtonRead == 0){
      if (counter == 0){
        counter++;
        alarmHour++;
        if(hour >= 10){
          alarmHour=0;
          alarmTenHour++;
        }
        if(alarmTenHour >= 1 && hour >= 3){
          alarmTenHour=0;
          alarmHour=1;
        }
      }
      minuteButtonRead = digitalRead(minuteButton);
      hourButtonRead = digitalRead(hourButton);
    }
    counter=0;
    Digit digitone(dig1,alarmTenHour);
    delay(wait);
    Digit digittwo(dig2,alarmHour);
    delay(wait);
    Digit digitthree(dig3,alarmTenMinute);
    delay(wait);
    Digit digitfour(dig4,alarmMinute);
    delay(wait);
  }
  
//manual minute incrementation
  while (minuteButtonRead == 0){
    if (counter == 0){
      counter++;
      addMinute++;
    }
    minuteButtonRead = digitalRead(minuteButton);
    hourButtonRead = digitalRead(hourButton);
  }
  counter=0;

//manual hour incrementation
  while (hourButtonRead == 0){
    if (counter == 0){
      counter++;
      hour++;
      if(hour >= 10){
        hour=0;
        tenHour++;
      }
      if(tenHour >= 1 && hour >= 3){
        tenHour=0;
        hour=1;
      }
    }
    minuteButtonRead = digitalRead(minuteButton);
    hourButtonRead = digitalRead(hourButton);
  }
  counter=0;

//clock counter
  minuteinf = millis() / 60000;
  minute = minuteinf + addMinute - (tenMinuteCounter*10);
  if(minute >= 10){
    minute=0;
    tenMinute++;
    tenMinuteCounter++;
    if(tenMinute >= 6){
      tenMinute=0;
      hour++;
      if(hour >= 10){
        hour=0;
        tenHour++;
      }
      if(tenHour >= 1 && hour >= 3){
        tenHour=0;
        hour=1;
      }
    }
  }

//sound the alarm
  if (minute == alarmMinute){
    if(tenMinute == alarmTenMinute){
      if(hour == alarmHour){
        if(tenHour == alarmTenHour){
          digitalWrite(buzzerPin,HIGH);
        }
      }
    }
  }
  else{
    digitalWrite(buzzerPin,LOW);
  }
//displays numbers by passing to class Digit
  Digit digitone(dig1,tenHour);
  delay(wait);
  Digit digittwo(dig2,hour);
  delay(wait);
  Digit digitthree(dig3,tenMinute);
  delay(wait);
  Digit digitfour(dig4,minute);
  delay(wait);

//prints time to serial. may be usefull for other implementations
  Serial.print(tenHour);
  Serial.print(hour);
  Serial.print(":");
  Serial.print(tenMinute);
  Serial.println(minute);
}
