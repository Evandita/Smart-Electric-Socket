#include <Adafruit_Sensor.h>
#include <DHT_U.h>
#include <WiFi.h>
#include <PubSubClient.h>

// Defining Pins
#define DHTPIN 12
#define SocketPIN1 23
#define SocketPIN2 22
#define SocketPIN3 21

// DHT parameters

#define DHTTYPE DHT22
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqttServer = "test.mosquitto.org";
const char* topic = "Tempdata";
const char* clientID = "ESP32-wokwi";

// Parameters for using non-blocking delay
unsigned long previousMillis = 0;
const long interval = 1000;

String msgStr = "";
float temp, hum;

// Setting up WiFi and MQTT client
WiFiClient espClient;
PubSubClient client(espClient);


void setup_wifi() {
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while(!client.connected()) {
    if (client.connect(clientID)) {
      Serial.println("MQTT connected");
      client.subscribe("relay1");
      client.subscribe("relay2");
      client.subscribe("relay3");
      Serial.println("Topic Subscribed");
    }
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void callback(char *topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message: ");
  String data = "";
  for (int i = 0;i < length;i++) {
    Serial.print((char)payload[i]);
    data += (char)payload[i];
  }
  Serial.println();
  Serial.print("Message size: ");
  Serial.println(length);
  Serial.println();
  Serial.println("---------------------");
  Serial.println(data);

  if (String(topic) == "relay1") {
    if (data == "ON") {
      Serial.println("Relay1 ON");
      digitalWrite(SocketPIN1, HIGH);
    }
    else {
      Serial.println("Relay1 OFF");
      digitalWrite(SocketPIN1, LOW);
    }
  }
  if (String(topic) == "relay2") {
    if (data == "ON") {
      Serial.println("Relay2 ON");
      digitalWrite(SocketPIN2, HIGH);
    }
    else {
      Serial.println("Relay2 OFF");
      digitalWrite(SocketPIN2, LOW);
    }
  }
  if (String(topic) == "relay3") {
    if (data == "ON") {
      Serial.println("Relay3 ON");
      digitalWrite(SocketPIN3, HIGH);
    }
    else {
      Serial.println("Relay3 OFF");
      digitalWrite(SocketPIN3, LOW);
    }
  }



}

void setup() {
  Serial.begin(115200);
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  dht.humidity().getSensor(&sensor);

  pinMode(SocketPIN1, OUTPUT);
  pinMode(SocketPIN2, OUTPUT);
  pinMode(SocketPIN3, OUTPUT);
  digitalWrite(SocketPIN1, LOW);
  digitalWrite(SocketPIN2, LOW);
  digitalWrite(SocketPIN3, LOW);

  setup_wifi();
  client.setServer(mqttServer, 1883);
  client.setCallback(callback);

  //set the resolution to 12 bits (0-4096)
  analogReadResolution(12);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    sensors_event_t event;
    dht.temperature().getEvent(&event);
    if (isnan(event.temperature)) {
      Serial.println(F("Error reading temperature!"));
    }
    else {
      Serial.print(F("Temperature: "));
      temp = event.temperature;
      Serial.print(temp);
      Serial.println(F(" °C"));
    }

    dht.humidity().getEvent(&event);
    if(isnan(event.relative_humidity)) {
      Serial.println(F("Error reading humidity!"));
    }
    else {
      Serial.print(F("Humidity: "));
      hum = event.relative_humidity;
      Serial.print(hum);
      Serial.println(F("%"));
    }
    msgStr = String(temp) + "," + String(hum) +",";
    byte arrSize = msgStr.length() + 1;
    char msg[arrSize];
    Serial.println("PUBLISH DATA: ");
    Serial.println(msgStr);
    msgStr.toCharArray(msg, arrSize);
    client.publish(topic, msg);

    msgStr = "";
    msgStr = String(analogReadMilliVolts(34));
    arrSize = msgStr.length() + 1;
    char msg2[arrSize];
    Serial.println(msgStr);
    msgStr.toCharArray(msg2, arrSize);
    client.publish("volt1", msg2);

    msgStr = "";
    msgStr = String(analogReadMilliVolts(35));
    arrSize = msgStr.length() + 1;
    char msg3[arrSize];
    Serial.println(msgStr);
    msgStr.toCharArray(msg3, arrSize);
    client.publish("volt2", msg3);

    msgStr = "";
    msgStr = String(analogReadMilliVolts(32));
    arrSize = msgStr.length() + 1;
    char msg4[arrSize];
    Serial.println(msgStr);
    msgStr.toCharArray(msg4, arrSize);
    client.publish("volt3", msg4);


    msgStr = "";
    delay(1);
  }
}