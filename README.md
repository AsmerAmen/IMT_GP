# IMT_GP

### Hardware:
1. 2 AVR ATmega32
2. NodeMCU
3. LM35 temp. sensor
4. PIR motion sensor
5. LEDs
6. LCD
7. Keypad
8. Buzzer
9. DC motor
10. servo motor

### Software:
1. AVR:		Embedded C
2. node:	Arduino frimware
3. server:	Python

### Devices:
1. Laptop as server
2. Mobile application as controller

### Protocols:
1. SPI
2. MQTT
3. http

### Requirments:
1. turn devices on/off.
2. control using mobile app.
3. User has to open door using username and password.
4. system can register up to 10 users.
5. users data is updated on the database
6. user has up to 3 wrong trials.
7. system should check the room temp.
8. turn on fan if it's over threshold.
9. lights turn off after specific time in case of no motion.
10. lights doesn't turn on in case of motion, it the user closed the line.
