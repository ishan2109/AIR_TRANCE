void get_pid() { 

error_roll = Angle[0] - desired_angle_roll;    
pid_roll_p = kp*error_roll;

if(-30 <error_roll <30)
{
  pid_roll_i = pid_roll_i+(ki*error_roll);  
}

pid_roll_d = kd*((error_roll - previous_error_roll)/elapsedTime);

PID_roll = pid_roll_p + pid_roll_i + pid_roll_d;

////////////////////////////////////////////////////////////////

error_pitch = Angle[1] - desired_angle_pitch;    
pid_pitch_p = kp*error_pitch;

if(-30 <error_pitch <30)
{
  pid_pitch_i = pid_pitch_i+(ki*error_pitch);  
}

pid_pitch_d = kd*((error_pitch - previous_error_pitch)/elapsedTime);

PID_pitch = pid_pitch_p + pid_pitch_i + pid_pitch_d;


/////////////////////////////////////////////////////


error_yaw = Angle[2] - desired_angle_yaw;    
pid_yaw_p = kp_yaw*error_yaw;

if(-180 <error_yaw <180)
{
  pid_yaw_i = pid_yaw_i+(ki_yaw*error_yaw);  
}

pid_yaw_d = kd_yaw*((error_yaw - previous_error_yaw)/elapsedTime);

PID_yaw = pid_yaw_p + pid_yaw_i + pid_yaw_d;


//////////////////////////////////////////////////////////////////////

pwm_esc_1 =  throttle + PID_roll + PID_pitch + PID_yaw;
pwm_esc_2 =  throttle - PID_roll + PID_pitch - PID_yaw;
pwm_esc_3 =  throttle + PID_roll - PID_pitch - PID_yaw;
pwm_esc_4 =  throttle - PID_roll - PID_pitch + PID_yaw;



if(pwm_esc_1 < 1000)
{
  pwm_esc_1= 1000;
}
if(pwm_esc_1 > 2000)
{
  pwm_esc_1=2000;
}

if(pwm_esc_2 < 1000)
{
  pwm_esc_2= 1000;
}
if(pwm_esc_2 > 2000)
{
  pwm_esc_2=2000;
}

if(pwm_esc_3 < 1000)
{
  pwm_esc_3= 1000;
}
if(pwm_esc_3 > 2000)
{
  pwm_esc_3=2000;
}

if(pwm_esc_4 < 1000)
{
  pwm_esc_4= 1000;
}
if(pwm_esc_4 > 2000)
{
  pwm_esc_4=2000;
}

previous_error_roll = error_roll;
previous_error_pitch = error_pitch;
previous_error_yaw = error_yaw;
 
}
