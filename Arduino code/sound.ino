int soundSensor = 2;
int red = 3;
int green = 4;
int red2 = 5;
int green2 = 6;

int SAMPLE_TIME = 10;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;

int sampleBufferValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);      
}

void loop() {
  millisCurrent = millis();
  millisElapsed = millisCurrent - millisLast;
  if(digitalRead(soundSensor) == LOW){
    sampleBufferValue++;
  }

  if(millisElapsed > SAMPLE_TIME){
    Serial.println(sampleBufferValue);
    sampleBufferValue = 0;
    millisLast = millisCurrent;
  }

  if(sampleBufferValue > 50) {
      analogWrite(green, 255);
      analogWrite(green2, 255);
      analogWrite(red, 0);
      analogWrite(red2, 0);
      delay(2000);
  } else {
      analogWrite(red, 255);
      analogWrite(red2, 255);
      analogWrite(green, 0);
      analogWrite(green2, 0);
  }
  
}
