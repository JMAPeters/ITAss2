void _ServerSetup(){
  // Connect to WiFi access point.
  Serial.print("Connecting to "); Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());

  
  configTime(timezone * 3600, 0, "pool.ntp.org", "time.nist.gov");
  Serial.println("Waiting for time");
  while(!time(nullptr)){
    Serial.print(".");
    delay(1000);
  }

  t = time(nullptr);
  _time = (localtime(&t));
  
  // Setup MQTT subscription for feed.
  mqtt.subscribe(&s_waterPlant);
  mqtt.subscribe(&s_updateSensor);
}

void _Server(){
  MQTT_connect();

  //Subscriptions
  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(5000))) {
    if (subscription == &s_waterPlant) {
      Pump();
    }
    if (subscription == &s_updateSensor){
      bme280();
      lightSensor();
      soilSensor();
    }
  }

  //publishing
  if (_time->tm_min >= publishTimer){
    publishTimer = (_time->tm_min + publishWaitTime + 60) % 60;
    t_temp.publish(temperature);
    t_pressure.publish(pressure);
    t_humidity.publish(humidity);
    t_light.publish(lightValue);
    t_soil.publish(soilValue);\
    Serial.println("Publish values");
  }

  //time
  t = time(nullptr);
  _time = (localtime(&t));
}

void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}
