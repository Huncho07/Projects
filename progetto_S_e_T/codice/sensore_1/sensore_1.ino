#define ANALOG_PIN 0
#define LED 11
char printBuffer[128];
short input_adc;
short count = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(count <= 10000){
    input_adc = analogRead(ANALOG_PIN);
    sprintf(printBuffer,"level: %d\n", input_adc);
    Serial.print(printBuffer);
    count++;
  }
  digitalWrite(LED, !digitalRead(LED));
  delay(100);
}
