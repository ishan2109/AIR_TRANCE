void calibrate_esc(){
  esc_1.attach(PIN_TWO);
  esc_2.attach(PIN_THREE);
  esc_3.attach(PIN_FOUR);
  esc_4.attach(PIN_FIVE);
  delay(2000);
  esc_1.writeMicroseconds(2000);
  esc_2.writeMicroseconds(2000);
  esc_3.writeMicroseconds(2000);
  esc_4.writeMicroseconds(2000); 
  Serial.println("connect power source");
  digitalWrite(ledpin,HIGH);
  delay(5000); 
  esc_1.writeMicroseconds(1000);
  esc_2.writeMicroseconds(1000);
  esc_3.writeMicroseconds(1000);
  esc_4.writeMicroseconds(1000); 
  delay(1000);
}

