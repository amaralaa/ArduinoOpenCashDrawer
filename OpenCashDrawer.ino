#define KEY_LEFT_CTRL  0x01
#define KEY_RIGHT_CTRL  0x10

uint8_t buf[8] = { 0 };

#define PIN_COPY 5
#define DrawerKey 6

int state = 1;
int start = 0;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(PIN_COPY, INPUT);
  pinMode(DrawerKey,OUTPUT);
  digitalWrite(PIN_COPY, 1);
  digitalWrite(DrawerKey,0);
  delay(10);
}

void loop() 
{
  state = digitalRead(PIN_COPY);
  if (state != 1 && start == 0) {
    start = 1;
    buf[0] = KEY_LEFT_CTRL;
    buf[2] = 0;
    Serial.write(buf, 8);
    OpenDrawer();
    releaseKey();
  }
  if(state == 1 and start == 1){
    start = 0;
  }
 }

void releaseKey() 
{
  delay(50);
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key  
  digitalWrite(DrawerKey,0);
  delay(200);
}

void OpenDrawer(){
digitalWrite(DrawerKey,1);
delay(50);
digitalWrite(DrawerKey,0);
delay(200);
}
