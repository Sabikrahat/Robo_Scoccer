char t;
 
void setup() {
    pinMode(11,OUTPUT);   //right motors forward    //IN1
    pinMode(10,OUTPUT);   //right motors reverse    //IN2
    pinMode(9,OUTPUT);   //left motors forward      //IN3
    pinMode(6,OUTPUT);   //left motors reverse      //IN4
    pinMode(4,OUTPUT);    //front led
    pinMode(8,OUTPUT);    //back led
    pinMode(7,OUTPUT);    //buzzer
    
    Serial.begin(9600);
}
 
void loop() {
    if(Serial.available()){
      t = Serial.read();
      
      Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  analogWrite(11,255);
  analogWrite(9,255);
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  analogWrite(6,255);
  analogWrite(10,255);
}
 
else if(t == 'R'){      //turn right (left side motors rotate in forward full speed direction, right side motors rotate in forward half speed direction)
  analogWrite(9,255);
  analogWrite(11,128);
}
 
else if(t == 'L'){      //turn left (left side motors rotate in forward full speed direction, right side motors rotate in forward half speed direction)
  analogWrite(11,255);
  analogWrite(9,128);
}

else if(t == 'G'){      //turning circle left (right side motors rotate in forward direction, left side motors rotate in reverse direction)
  analogWrite(11,255);
  analogWrite(6,255);
}

else if(t == 'I'){      //turning circle right (left side motors rotate in forward direction, right side motors rotate in reverse direction)
  digitalWrite(9,255);
  digitalWrite(10,255);
}

else if(t == 'H'){      //back turning  left (left side motors rotate in reverse half speed direction, right side motors rotate in reverse full speed direction)
  analogWrite(6,128);
  analogWrite(10,255);
}

else if(t == 'J'){      //back turning right (right side motors rotate in reverse half speed direction, left side motors rotate in reverse full speed direction)
  analogWrite(6,255);
  analogWrite(10,128);
}

else if(t == 'W'){    //turn front led on or off)
  digitalWrite(4,HIGH);
}

else if(t == 'w'){
  digitalWrite(4,LOW);
}

else if(t == 'U'){    //turn back led on or off
  digitalWrite(8,HIGH);
}
else if(t == 'u'){
  digitalWrite(8,LOW);
}

else if(t == 'V'){    //turn buzzer on or off
  digitalWrite(7,HIGH);
}
else if(t == 'v'){
  digitalWrite(7,LOW);
}

else if(t == 'S'){      //STOP (all motors stop)
  analogWrite(6,0);
  analogWrite(9,0);
  analogWrite(10,0);
  analogWrite(11,0);
}
}
