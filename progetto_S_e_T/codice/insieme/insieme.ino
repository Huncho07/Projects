#define DIGITAL_PIN 3
#define ANALOG_PIN_1 0
#define ANALOG_PIN_2 5
#define SENSOR_POWER 2
#define LED 11

char printBuffer[128];
boolean isRaining = false;
String raining;
short input_adc_1;
short input_adc_2;
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
    input_adc_1 = analogRead(ANALOG_PIN_1);
    digitalWrite(SENSOR_POWER, HIGH);
    input_adc_2 = analogRead(ANALOG_PIN_2);
    sprintf(printBuffer,"1: %d 2: %d", input_adc_1, input_adc_2);
    Serial.println(printBuffer);
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









