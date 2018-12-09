void setup_MPU(){
  Wire.beginTransmission(0x68);                                        
  Wire.write(0x6B);                                                    
  Wire.write(0x00);                                                    
  Wire.endTransmission();                                              
  // accelerometer sensitivity 8g
  Wire.beginTransmission(0x68);                                        
  Wire.write(0x1C);                                                    
  Wire.write(0x10);                                                    
  Wire.endTransmission();                                              
  // gyroscope sensitivity 500dps
  Wire.beginTransmission(0x68);                                        
  Wire.write(0x1B);                                                  
  Wire.write(0x08);                                                    
  Wire.endTransmission();      
}

