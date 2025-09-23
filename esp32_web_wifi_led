#include <WiFi.h>
#include <WebServer.h>

const char* ssid     = "Galaxy Note20";     // 핫스팟 이름
const char* password = "00000000";      // 핫스팟 비밀번호

WebServer server(80);   // HTTP 서버, 포트 80 사용
int ledPin = 2;         // 외부 LED 연결 핀 (GPIO2)

void handleOn() {
  digitalWrite(ledPin, HIGH);
  server.send(200, "text/plain", "LED ON");
}

void handleOff() {
  digitalWrite(ledPin, LOW);
  server.send(200, "text/plain", "LED OFF");
}

void handleWhoami() {
  server.send(200, "text/plain", "id: 1900000\nname: MY NAME"); // 본인 학번/이름 - 한글은 깨지는 문제가 발생할 수 있으므로 숫자 및 영문만 권장
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.begin(ssid, password);
  Serial.print("WiFi Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected! IP Address: ");
  Serial.println(WiFi.localIP());  // ESP32 IP 출력

  // URL 경로 등록
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.on("/whoami", handleWhoami);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();  // 클라이언트 요청 처리
}
