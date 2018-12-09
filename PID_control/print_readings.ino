void print_readings(){
      /*Serial.print(" pwm_esc_1 = ");Serial.print(pwm_esc_1);Serial.print("  ");
    Serial.print(" pwm_esc_2 = ");Serial.print(pwm_esc_2);Serial.print("  ");
    Serial.print(" pwm_esc_3 = ");Serial.print(pwm_esc_3);Serial.print("  ");
    Serial.print(" pwm_esc_4 = ");Serial.print(pwm_esc_4);Serial.print("  ");
    Serial.print(" New kd =");Serial.print("  ");Serial.print(kd);
    Serial.print(" Time = ");Serial.print("  ");Serial.println(elapsedTime);
    */

    Serial.print("Pitch = ");Serial.print(Angle[0]);Serial.print("  ");
    Serial.print("Roll =");Serial.print(Angle[1]);Serial.print("  ");
    Serial.print("Yaw = ");Serial.print(Angle[2]);Serial.print("  ");
    Serial.print("Throttle = ");Serial.print(throttle);Serial.print("  ");
    Serial.print("New kd =");Serial.print("  ");Serial.print(kd);
    Serial.print("Time = ");Serial.print("  ");Serial.println(elapsedTime);
}

