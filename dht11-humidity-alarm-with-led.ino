#include "DHT.h" //온습도센서 라이브러리!
#define DHTPIN 4 //온습도센서가 연결된 핀번호!
#define DHTTYPE DHT11 //DHT센서의 종류
DHT dht(DHTPIN, DHTTYPE); 

void setup() {
  Serial.begin(115200); //ESP32가 PC하고 통신할것이다!
  Serial.println("DHTxx test!");

  dht.begin(); //온습도센서 시작하기!
  pinMode(21, OUTPUT);
  digitalWrite(21, 0); //turn off 상태에서 시작(0)
}

void loop() {
  delay(2000);
  float h = dht.readHumidity(); //습도를 측정하는 함수!
  float t = dht.readTemperature(); //온도를 측정하는 함수!(도씨)

  //센서가 잘못연결되거나 고장이 난경우 발생하게될 에러메시지!
  if (isnan(h) || isnan(t)) {
    Serial.println("센서값이 측정되지 않았습니다!");
    return; //더이상 아래부분을 실행하지 않겠다!
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.print("°C ");
  Serial.println();  

  if (h>70) digitalWrite(21,1); //습도가 70% 이상일 때 LED turn on(1)
  else digitalWrite(21,0);
}
