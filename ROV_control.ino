const int IN1 = 5;
const int IN2 = 4;
const int IN3 = 3;
const int IN4 = 2;
const int enpin = 6;
int back_light=8;
int front_light=12;
int pwm=A4;
int motor1Pin1=11;
int motor1Pin2=10;
int enable1=9;
const int pingPin = A1; // Trigger Pin of Ultrasonic Sensor
const int echoPin = A0; // Echo Pin of Ultrasonic Sensor
int state;
int flag=0;
int flag1=0;
int ststeStop=0;
int input_val=0;

void setup()
{
  pinMode(motor1Pin1,OUTPUT);
  pinMode(motor1Pin2,OUTPUT);
  pinMode(enable1,OUTPUT);
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(back_light,OUTPUT);
  pinMode(front_light,OUTPUT);
  
//digitalWrite(enable1,HIGH);
digitalWrite(enpin,HIGH);
  
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);

 

digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
  
  Serial.begin(9600);

}

void loop() {

  if(Serial.available()>0)
  {
    state=Serial.read();
    flag=0;
    flag1=0;
  }
  
  
  long duration, inches, cm;
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  int pwm= '0'||'1' || '2'|| '3' || '4' ||'5' || '6' || '7' || '8' || '9';
  if(state=='F'|| state=='b'||state=='v'|| state=='o'||state=='z' || state=='0'||state=='1'||state=='2'|| state=='3'|| state=='4'|| state=='5'||state=='6'||state=='7'||state=='8'||state=='9')
  {

    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    delay(100);
    
    if (state=='F')
    {
      //input_val=analogRead(pwm);
      //int dc=input_val/4;
    digitalWrite(motor1Pin1,HIGH);
    digitalWrite(motor1Pin2,LOW);
    digitalWrite(front_light,HIGH);
    digitalWrite(back_light,LOW);
    
     if(flag==0)
    {
      Serial.println("Go Forward");
      flag=1;
      
    }
    
    }
    
    if(state=='b')
    {
      step3();
    if(flag==0)
    {
      Serial.println("The ROV is Turnning Right");
   
      flag=1;
    } 
    
    flag1=1;
  }
  
    else if(state=='v')
    {
    step4();
    if(flag==0)
    {
      Serial.println("The ROV is Turnning Left");
      flag=1;
      
    }  
  flag1==1;  
  }
  
  else if(state=='o')
    {
      step1();
    if(flag==0)
    {
      Serial.println("The ROV is Turnning Right Two steps");
   
      flag=1;
    } 
    
    flag1=1;
  }
  
   else if(state=='z')
    {
      step2();
    if(flag==0)
    {
      Serial.println("The ROV is Turnning Left Two steps");
   
      flag=1;
    } 
    
    flag1=1;
  }
  

   
    else if(state=='0')
    {
analogWrite(enable1,0);   
if(flag==0)
    {
      Serial.println("The DC becomes 0%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  
  else if(state=='1')
    {
analogWrite(enable1,26);   
if(flag==0)
    {
      Serial.println("The DC becomes 10%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  
  else if(state=='2')
    {
analogWrite(enable1,52);   
if(flag==0)
    {
      Serial.println("The DC becomes 20%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  
  else if(state=='3')
    {
analogWrite(enable1,78);   
if(flag==0)
    {
      Serial.println("The DC becomes 30%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  
  else if(state=='4')
    {
analogWrite(enable1,104);   
if(flag==0)
    {
      Serial.println("The DC becomes 40%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  
  else if(state=='5')
    {
analogWrite(enable1,130);   
if(flag==0)
    {
      Serial.println("The DC becomes 50%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  
  else if(state=='6')
    {
analogWrite(enable1,156);   
if(flag==0)
    {
      Serial.println("The DC becomes 60%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  
  else if(state=='7')
    {
analogWrite(enable1,182);   
if(flag==0)
    {
      Serial.println("The DC becomes 70%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  else if(state=='8')
    {
analogWrite(enable1,208);   
if(flag==0)
    {
      Serial.println("The DC becomes 80%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  
  else if(state=='9')
    {
analogWrite(enable1,255);   
if(flag==0)
    {
      Serial.println("The DC becomes 100%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  }
  else if(state=='B'|| state=='b'||state=='v'|| state=='o'|| state=='z'|| 
  state=='0'||state=='1'||state=='2'|| state=='3'|| state=='4'||
  state=='5'||state=='6'||state=='7'||state=='8'||state=='9')
  {
    if(state=='B')
    {
    digitalWrite(motor1Pin1,LOW);
    digitalWrite(motor1Pin2,HIGH);
    digitalWrite(back_light,HIGH);
    digitalWrite(front_light,LOW);
    }
    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    delay(100);
    
    
    if(flag==0)
    {
      Serial.println("Go Backward");
      flag=1;
    }
    
    if(state=='b')
    {
      step3();
      flag=1;
    }
    else if(state=='v')
    {
      step4();
      flag1=1;
    }
    
    else if(state=='o')
    {
      step1();
    if(flag==0)
    {
      Serial.println("The ROV is Turnning RIGHT 90 degree");
   
      flag=1;
    } 
      flag1=1;
    }
    
   else if(state=='z')
    {
      step2();
      
   if(flag==0)
    {
      Serial.println("The ROV is Turnning Left 90 degree");
   
      flag=1;
    } 
      flag1=1;
    }
    
    else if(state=='0')
    {
analogWrite(enable1,0);   
if(flag==0)
    {
      Serial.println("The DC becomes 0%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  
  else if(state=='1')
    {
analogWrite(enable1,26);   
if(flag==0)
    {
      Serial.println("The DC becomes 10%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  
  else if(state=='2')
    {
analogWrite(enable1,52);   
if(flag==0)
    {
      Serial.println("The DC becomes 20%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  
  else if(state=='3')
    {
analogWrite(enable1,78);   
if(flag==0)
    {
      Serial.println("The DC becomes 30%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  
  else if(state=='4')
    {
analogWrite(enable1,104);   
if(flag==0)
    {
      Serial.println("The DC becomes 40%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  
  else if(state=='5')
    {
analogWrite(enable1,130);   
if(flag==0)
    {
      Serial.println("The DC becomes 50%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  
  else if(state=='6')
    {
analogWrite(enable1,156);   
if(flag==0)
    {
      Serial.println("The DC becomes 60%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  
  else if(state=='7')
    {
analogWrite(enable1,182);   
if(flag==0)
    {
      Serial.println("The DC becomes 70%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  else if(state=='8')
    {
analogWrite(enable1,208);   
if(flag==0)
    {
      Serial.println("The DC becomes 80%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  
  else if(state=='9')
    {
analogWrite(enable1,255);   
if(flag==0)
    {
      Serial.println("The DC becomes 100%");
   
      flag=1;
    } 
    
    flag1=1;
  }
  }
  
  else if(state=='S')
  {
    digitalWrite(motor1Pin1,LOW);
    digitalWrite(motor1Pin2,LOW);
    stop_stepper();
    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    delay(100);
    
        
    if(flag==0)
    {
      Serial.println("The ROV is Stopped");
      flag=1;
    }
    
  }
}


long microsecondsToInches(long microseconds)
{
return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}

void step1 ()
{

digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);

}

void step2 ()
{
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
}

void step3 ()
{
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);

}

void step4 ()
{
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);
}

void stop_stepper()
{
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);
}
