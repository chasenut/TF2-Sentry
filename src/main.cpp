#include <Arduino.h>
#include <WiFi.h>
#include <esp_wifi.h>
#include <esp_now.h>

// I was to lazy to make separate projects for the sentry and the wrangler
// so here are the defines
// always comment accordingly
// if not commented - build for sentry
// if commented - build for wrangler
#define DEPLOY_SENTRY

uint8_t sentry_custom_mac[] = {0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA};
uint8_t wrangler_custom_mac[] = {0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB};

typedef struct struct_message {
  double x_cord;
  double y_cord;
  bool btn_pressed;
} struct_message;

// Create a struct_message called myData
struct_message myData;

esp_now_peer_info_t peerInfo;


void initEspNow() {
  // Get MAC Address
  Serial.print("ESP32 Board MAC Address: ");
  Serial.println(WiFi.macAddress());
  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
}


#ifndef DEPLOY_SENTRY
#define DEPLOY_WRANGLER
#endif

#ifdef DEPLOY_SENTRY
#include <ESP32Servo.h>

Servo xServo;
Servo yServo;
const int X_SERVO_PIN = 27;
const int Y_SERVO_PIN = 26;

const double X_SERVO_ANGLE_MAX = 180;
const double X_SERVO_ANGLE_MIN = 0;
const double Y_SERVO_ANGLE_MAX = 115;
const double Y_SERVO_ANGLE_MIN = 80;

int cycle_time = 3000;
int elapsed_time = 0;
int cycle_count = 0;

int curr_angle_x = 90; //set to 90 be default

int approx_def_joystick_offset = 1720;
int joystick_baund = 10; // offset after which things happen (like servo moves)
int joystick_ratio_comp = 1700; // what the offset from joystick is compared to
const double SENSITIVITY = 3;

int prev_t = millis();
int curr_t = millis();


// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  int x = myData.x_cord;
  int y = myData.y_cord;
  bool btn_pressed = myData.btn_pressed;
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("x_cord: ");
  Serial.println(x);
  Serial.print("y_cord: ");
  Serial.println(y);
  Serial.print("btn_press: ");
  Serial.println(btn_pressed);

  int x_offset = approx_def_joystick_offset - x;
  int y_offset = approx_def_joystick_offset - y;

  if (x_offset > joystick_ratio_comp) x_offset = joystick_ratio_comp;
  if (x_offset < -joystick_ratio_comp) x_offset = -joystick_ratio_comp;
  if (y_offset > joystick_ratio_comp) y = joystick_ratio_comp;
  if (y_offset < -joystick_ratio_comp) y_offset = -joystick_ratio_comp;

  if (joystick_baund - abs(x_offset) < 0) {
    double new_angle_x = 90 + ((double)x_offset / (double)joystick_ratio_comp) * 90;
    if (new_angle_x >= X_SERVO_ANGLE_MIN && new_angle_x <= X_SERVO_ANGLE_MAX) {
      xServo.write(new_angle_x);
    }
  }

  if (joystick_baund - abs(y_offset) < 0) {

  }


}

void setup() {

  xServo.setPeriodHertz(50);
  xServo.attach(X_SERVO_PIN, 500, 2500);

  yServo.setPeriodHertz(50);
  yServo.attach(Y_SERVO_PIN, 500, 2500);

  xServo.write(curr_angle_x);
  yServo.write(90);

  Serial.begin(9600);

  // ESPNow STUFF
  WiFi.mode(WIFI_STA);
  esp_wifi_set_mac(WIFI_IF_STA, sentry_custom_mac);
  initEspNow();
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);


  delay(3000);
}


void loop() {
  elapsed_time = millis();
  //Serial.println("millis: " + String(elapsed_time));
  cycle_count = floor(elapsed_time / cycle_time);
  //Serial.println("cycle_count: " + String(cycle_count));
  bool dir = cycle_count % 2 == 0 ? true : false;
  //Serial.println("dir: " + String(dir));
  double ratio = (double)(elapsed_time % cycle_time) / (double)cycle_time;
  double angle = dir ? ratio * 180 : 180 - ratio * 180;
  //Serial.println("angle: " + String(angle));
  //xServo.write(angle);


  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    double angle = input.toDouble();
    if (angle >= 85 && angle <= 105) {
      yServo.write(angle);
    }
    Serial.println("\nEnter Servo value: ");
  }
}
#endif

#ifdef DEPLOY_WRANGLER

const int JOY_X_PIN = 32;
const int JOY_Y_PIN = 35;
const int JOY_BTN_PIN = 34;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  //Serial.print("\r\nLast Packet Send Status:\t");
  //Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}


void setup() {

  Serial.begin(9600);

  // ESPNow STUFF
  WiFi.mode(WIFI_STA);
  esp_wifi_set_mac(WIFI_IF_STA, wrangler_custom_mac);
  initEspNow();
  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Transmitted packet
  esp_now_register_send_cb(OnDataSent);

  // Register peer
  memcpy(peerInfo.peer_addr, sentry_custom_mac, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }

  // Pins
  pinMode(JOY_BTN_PIN, INPUT_PULLUP);

}

void loop() {

  int joy_x_val = analogRead(JOY_X_PIN); //  0–4095
  int joy_y_val = analogRead(JOY_Y_PIN); //  0–4095
  bool joy_btn_pressed = digitalRead(JOY_BTN_PIN) == LOW;

  // Set values to send
  //strcpy(myData.someString, "THIS IS A CHAR");
  myData.x_cord = joy_x_val;
  myData.y_cord = joy_y_val;
  myData.btn_pressed = joy_btn_pressed;
  
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(sentry_custom_mac, (uint8_t *) &myData, sizeof(myData));
   
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
  //delay(20);
}

#endif


