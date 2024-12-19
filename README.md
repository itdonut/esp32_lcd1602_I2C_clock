# Clock
## This project implements the clock using ESP32-wroom-32d and LCD 1602 I2C display.

### Details:

#### Used external libraries:
1. [NTPClient](https://github.com/taranais/NTPClient) | Click [HERE](https://github.com/taranais/NTPClient/archive/master.zip) to download
2. [LiquidCrystal_I2C](https://github.com/johnrickman/LiquidCrystal_I2C) | Click [HERE](https://github.com/marcoschwartz/LiquidCrystal_I2C/archive/master.zip) to download

#### Schematic diagram of connectiong lcd to esp32 via i2c:
NOTE! You may have to swap SCL and SDA

![Image](https://i.sstatic.net/FjBC1.png)

#### How it works:
ESP32 connects to wifi using wifi's ssid and password. It then gets date and time from NTP server using an NTP Client library. The final step is displaying the received date on the display using LiquidCrystal_I2C library.