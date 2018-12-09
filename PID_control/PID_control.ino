
/* (A) (B)     x
 *   \ /     z ↑
 *    X       \|
 *   / \       +----→ y
 * (C) (D) */

#include <Wire.h>
#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


#define ledpin 6

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

int32_t AcX, AcY, AcZ, GyX, GyY, GyZ;
int32_t AcX_cal,AcY_cal,AcZ_cal,GyX_cal,GyY_cal,GyZ_cal; 
#define MPU 0b01101000 
#define A_R 4096
#define G_R 65.5
#define RAD_A_DEG = 57.295779     //Rad to degree convertion ratio 180/PI


#define PIN_TWO  2
#define PIN_THREE  3
#define PIN_FOUR  4
#define PIN_FIVE  5 
Servo esc_1;
Servo esc_2;
Servo esc_3;
Servo esc_4;

//Start values
float Acc[2]; //16 bits values of the acceleration
float Gy[2];  //16 bits values of the gyro
float Angle[3]; //16 bits values of the angle
float value[4];


float elapsedTime, time, timePrev,loop_timer;

float PID_roll,PID_pitch,PID_yaw,PID_total, pwm_esc_1, pwm_esc_2,pwm_esc_3,pwm_esc_4, error_roll, error_pitch,error_yaw, previous_error_roll, previous_error_pitch,previous_error_yaw;
float desired_angle_roll,desired_angle_pitch,desired_angle_yaw;
float pid_roll_p=0,pid_roll_d=0,pid_roll_i=0;
float pid_pitch_p=0,pid_pitch_d=0,pid_pitch_i=0;
float pid_yaw_p=0,pid_yaw_d=0,pid_yaw_i=0;

/////////////////PID CONSTANTS/////////////////
double kp=0;           //3.55
double ki=0.000;       //0.003
double kd;             //2.05
double kp_yaw=0;       //3.55
double ki_yaw=0.000;   //0.003
double kd_yaw=0;       //2.05
int throttle=1200; 
///////////////////////////////////////////////


void setup() {
  
  Serial.begin(9600); 
  pinMode(ledpin,OUTPUT);
  setup_MPU();                                       
  calibrate_esc(); 
  setup_radio();
  calibrate_MPU();
  digitalWrite(ledpin,LOW);
  
}
//////////////////////////////////////////////////////////////////

void loop() {


    loop_timer = micros();           //Start counting time in microseconds
 
    check_radio();                   // check if radio is sending any value 

    read_acc();                      //take values from accelerometer
    
    read_gy();                       // take readings from gyroscope
    
    get_angle();                    // calculate angles by using readings of acc and gyro 

    get_pid();                      // get new correction values

    print_readings();    
    
    elapsedTime = (micros() - loop_timer);  //calculate elapsed time for loop

    while(micros() - loop_timer < 3980);    // wait until 4000us are passed

    write_to_motors();             // give new PWM signal to motors after correction
    

}


