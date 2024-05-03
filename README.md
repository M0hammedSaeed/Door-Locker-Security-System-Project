# Door Locker Security System
The project involves creating a password-based door unlocking system using AVR ATmega32. It utilizes various drivers including GPIO, Keypad, LCD, Timer, UART, I2C, INT2, EEPROM, Buzzer, and DC Motor for functionality.

There are two Electronic Control Units (ECUs) used here:

- Human-Machine Interface (HMI) ECU:
> Is just responsible interaction with the user just take inputs through keypad and display messages on the LCD.

> HMI_ECU MCAL: GPIO, UART, TIMER1, and INT2.

> HMI_ECU HAL: LCD and KEYPAD.

- Control ECU: 
> Is responsible for all the processing and decisions in the system like password checking, open the door and activate the system alarm.

> CONTROL_ECU MCAL: GPIO, UART, TIMER1, INT2, PWM_TIMER0, and I2C.

> CONTROL_ECU HAL: BUZZER, EEPROM, and DC MOTOR.

## The Project Hardware Connections
![Project Simulation](https://github.com/M0hammedSaeed/Door-Locker-Security-System-Project/assets/114070625/b242468e-29d5-44de-ae92-fdcbc25f64a7)

## Control_ECU Design
![Control Ecu Design](https://github.com/M0hammedSaeed/Door-Locker-Security-System-Project/assets/114070625/619d0571-49c4-409d-ba45-eb7ff272ebc9)

## HMI_ECU Design
![HMI  Ecu Design](https://github.com/M0hammedSaeed/Door-Locker-Security-System-Project/assets/114070625/6fe90c48-17c3-452b-8e45-5017565ec80c)
