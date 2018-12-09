void write_to_motors(){
    esc_1.writeMicroseconds(pwm_esc_1);
    esc_2.writeMicroseconds(pwm_esc_2);
    esc_3.writeMicroseconds(pwm_esc_3);
    esc_4.writeMicroseconds(pwm_esc_4);  
    }
