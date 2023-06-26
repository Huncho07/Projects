#define DIGITAL_PIN 3
#define ANALOG_PIN 5
#define SENSOR_POWER 2
#define LED 11
char printBuffer[128];
short input_adc;
boolean isRaining = false;
String raining;
short count = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(DIGITAL_PIN, INPUT);
  pinMode(SENSOR_POWER, OUTPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(SENSOR_POWER, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(count <= 10000){
    digitalWrite(SENSOR_POWER, HIGH);
    delay(10);
    input_adc = analogRead(ANALOG_PIN);
    sprintf(printBuffer,"level: %d\n", input_adc);
    Serial.print(printBuffer);
    isRaining = digitalRead(DIGITAL_PIN);
    if(isRaining){
      raining = "Sì";
    }
    else{
      raining = "No";
  }
  digitalWrite(SENSOR_POWER, LOW);
  count++;
  }
  digitalWrite(LED, !digitalRead(LED));
  delay(100);
}