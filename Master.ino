#include <esp_now.h>
#include <WiFi.h>

typedef struct struct_message {
  float x;
  float y;
  float z;
} struct_message;

struct_message myData;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));

    Serial.print("Received Orientation Data - X: ");
    Serial.print(myData.x);
    Serial.print(", Y: ");
    Serial.print(myData.y);
    Serial.print(", Z: ");
    Serial.println(myData.z);
}
 
void setup() {
 
   Serial.begin(115200);
  
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {

}