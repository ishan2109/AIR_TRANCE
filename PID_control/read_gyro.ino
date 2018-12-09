void read_gy(){
     Wire.beginTransmission(MPU);
     Wire.write(0x43);
     Wire.endTransmission(false);
     Wire.requestFrom(MPU,6,true);
     GyX=Wire.read()<<8|Wire.read();
     GyY=Wire.read()<<8|Wire.read();
     GyZ=Wire.read()<<8|Wire.read();
   
   } 
