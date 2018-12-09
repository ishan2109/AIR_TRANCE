void read_acc() {
     Wire.beginTransmission(MPU);
     Wire.write(0x3B);
     Wire.endTransmission(false);
     Wire.requestFrom(MPU,6,true); 
     AcX=Wire.read()<<8|Wire.read(); 
     AcY=Wire.read()<<8|Wire.read();
     AcZ=Wire.read()<<8|Wire.read();//Serial.print(AcX);Serial.println("");
   }
