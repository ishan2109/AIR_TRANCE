void get_angle(){

          AcX-=AcX_cal;
          AcY-=AcY_cal;
          GyX-=GyX_cal;
          GyY-=GyY_cal;

          Acc[1] = atan(-1*(AcX/A_R)/sqrt(pow((AcY/A_R),2) + pow((AcZ/A_R),2)))*RAD_TO_DEG;
          Acc[0] = atan((AcY/A_R)/sqrt(pow((AcX/A_R),2) + pow((AcZ/A_R),2)))*RAD_TO_DEG;

          Gy[0] = GyX/G_R;
          Gy[1] = GyY/G_R;

          Gy[0] += Gy[1] * sin(GyZ * 0.000001066);               //If the IMU has yawed transfer the roll angle to the pitch angel
          Gy[1] -= Gy[0] * sin(GyZ * 0.000001066);               //If the IMU has yawed transfer the pitch angle to the roll angel

         Angle[0] = 0.99*(Angle[0]+Gy[0]*0.010) + 0.01*Acc[0];
         Angle[1] = 0.99*(Angle[1]+Gy[1]*0.010) + 0.01*Acc[1];
         Angle[2] = (-1)*GyZ/G_R;
} 
