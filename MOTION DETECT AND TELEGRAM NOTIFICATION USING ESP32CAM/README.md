# MOTION DETECT TELEGRAM ALART USING ESP32CAM

## ABSTRACT
This project presents the development of an intelligent motion detection system using the ESP32-CAM module. The system is designed to detect motion in a specific area and promptly send real-time notification messages, along with captured images, to the user's Telegram account. The integration of the ESP32 microcontroller, a camera module, and the Telegram API enables seamless communication and remote monitoring capabilities.

The initial phase involves setting up the hardware, where the ESP32-CAM is connected to a computer via a USB-to-serial converter, and powered either through an external power supply or USB cable. The Arduino IDE is utilized to program the ESP32-CAM, and the necessary libraries are installed to facilitate communication with the camera module and Telegram API.

A Telegram bot is created using the Telegram BotFather, and the unique API token is obtained for communication between the ESP32-CAM and Telegram servers. The ESP32-CAM is then connected to a local Wi-Fi network, granting it access to the internet for sending Telegram messages.

The motion detection algorithm is implemented to analyze consecutive frames captured by the camera module. Any significant pixel differences between frames are identified as motion, triggering the capture of an image of the detected intruder.

Upon detecting motion, the system encodes the captured image, preparing it for transmission via the Telegram API. Telegram messages containing the captured images are instantly sent to the user's Telegram account, providing them with visual evidence of the intrusion.

To minimize false positives, the system incorporates adjustable sensitivity settings and compares multiple frames before confirming motion.

Additionally, energy-saving measures, such as deep sleep mode, are considered to optimize power management, ensuring the system's long-term efficiency.

Throughout the project's development, privacy, and security concerns are carefully addressed. The system respects individual privacy, and users are informed if they are under surveillance. Adherence to local laws and regulations regarding surveillance and privacy is a fundamental aspect of the project's design.

The project's successful implementation culminates in a cost-effective and reliable motion detection system, offering real-time Telegram notifications with visual evidence of intrusions. The system finds applications in home security, remote monitoring, and other scenarios where timely detection and notification are crucial.

Keywords: ESP32-CAM, Motion Detection, Telegram API, Image Capture, Remote Monitoring, Home Security, Privacy.


## To program the ESP32-CAM using the Arduino IDE, you'll need to follow these general steps:

1.Install Arduino IDE:
If you haven't already, download and install the Arduino IDE from the official Arduino website (https://www.arduino.cc/en/software).

2. Add ESP32 Board Support:
Open the Arduino IDE and go to "File" > "Preferences." In the "Additional Boards Manager URLs" field, paste the following URL:

3. Arduino
Copy code
https://dl.espressif.com/dl/package_esp32_index.json
Then, click "OK."

4. Install ESP32 Board Package:
Go to "Tools" > "Board" > "Boards Manager." Search for "esp32" and install the "esp32" board package by Espressif Systems.

5. Select ESP32-CAM Board:
After installing the ESP32 board package, go to "Tools" > "Board" and select the appropriate ESP32 board. For the ESP32-CAM, you might find options like "AI Thinker ESP32-CAM" or "ESP32 Wrover Module." You can choose the one that matches your board..

6. Connect ESP32-CAM to Computer:
Connect the ESP32-CAM to your computer using a USB-to-Serial converter. Connect the correct pins (e.g., GND, 5V, TX, RX) between the ESP32-CAM and the USB-to-Serial converter.

7. Select COM Port:
Go to "Tools" > "Port" and select the appropriate COM port that corresponds to the USB-to-Serial converter connected to the ESP32-CAM.

8. Upload a Sample Sketch:
To test the setup, you can upload a sample sketch. In the Arduino IDE, go to "File" > "Examples" > "ESP32" and select one of the example sketches (e.g., "Basics" > "Blink"). Click the "Upload" button to compile and upload the sketch to the ESP32-CAM.

9. Verify Upload and Functionality:
The Arduino IDE should show the upload progress, and if everything goes well, the sketch should be running on the ESP32-CAM. You can verify its functionality (e.g., blinking an LED) according to the uploaded sketch.

Once you've confirmed that you can upload and run sketches on the ESP32-CAM, you can proceed with the implementation of your motion detection and Telegram notification project, as outlined in the previous response.
### CIRCUIT DIAGRAM TO UPLOAD CODE TO ESP32CAM

![PROGRAMMING ESP32CAM USING ARDUINO UNO](https://github.com/SriKrishna74/MINI-PROJECTS/assets/127392900/41d258be-e58c-4e4d-b392-586fbf615289)

## Circuit Description

The circuit described below connects a PIR (Passive Infrared) sensor to IO13 of an ESP32-CAM module, and the ESP32-CAM is powered using an Arduino Uno.

## Components Used

1.ESP32-CAM module
2. PIR (Passive Infrared) motion sensor
3. Arduino Uno
4. Jumper wires

## Circuit Connections

1. Connect the GND (Ground) pin of the PIR sensor to the GND (Ground) pin of the Arduino Uno.

2. Connect the VCC (Power) pin of the PIR sensor to the 5V pin of the Arduino Uno to supply power to the sensor.

3. Connect the OUT (Output) pin of the PIR sensor to IO13 (GPIO13) of the ESP32-CAM module. This will be the signal pin through which the PIR sensor will communicate with the ESP32-CAM.

4. Power the ESP32-CAM module using the Arduino Uno. To do this, connect the 5V pin of the Arduino Uno to the 5V pin of the ESP32-CAM. Also, connect the GND pin of the Arduino Uno to the GND pin of the ESP32-CAM to provide a common ground reference.

5. Connect the Arduino Uno to your computer using a USB cable to power it and allow for programming the ESP32-CAM.

![CIRCUIT CONNECTION](https://github.com/SriKrishna74/MINI-PROJECTS/assets/127392900/ed0efdd8-d5de-47d7-af03-308560bbfac8)

## Circuit Functionality

The PIR sensor is a motion detection sensor that detects changes in infrared radiation within its field of view. When a person or object moves within the detection range of the PIR sensor, it generates a signal at its OUT pin, indicating motion detection.

The ESP32-CAM is programmed to monitor the state of IO13 (GPIO13), which is connected to the OUT pin of the PIR sensor. When the PIR sensor detects motion and sends a signal to IO13, the ESP32-CAM will capture an image using its built-in camera and send a notification to the user's Telegram account, as described in the project's abstract.

The ESP32-CAM is powered using the 5V output from the Arduino Uno. This setup ensures that the ESP32-CAM receives stable power during operation. However, it's important to ensure that the total power consumption of the ESP32-CAM and the camera module does not exceed the maximum current output that the Arduino Uno can provide.

Note: When powering the ESP32-CAM with an external power source (e.g., USB cable connected to a power adapter), make sure to provide an adequate power supply to meet the power requirements of the ESP32-CAM and the camera module. Using an Arduino Uno to power the ESP32-CAM is suitable for testing and prototyping purposes, but for long-term or standalone deployment, a dedicated and sufficient power supply for the ESP32-CAM is recommended.

## To create a Telegram bot and integrate it into your ESP32-CAM project, follow these steps

Step 1: Create a Telegram Bot

1. Open the Telegram app and search for the "BotFather" bot.
2. ![image](https://github.com/SriKrishna74/MINI-PROJECTS/assets/127392900/80be24ba-8bec-4d80-b97c-5efee5ce1534)
3. Start a chat with BotFather and send the command "/newbot" to create a new bot.
4. ![image](https://github.com/SriKrishna74/MINI-PROJECTS/assets/127392900/0e9b1ba7-e844-4223-94ef-7df03e1407ed)

5. Follow the instructions from BotFather, provide a name for your bot (e.g., "MyMotionBot"), and choose a username (e.g., "@MyMotionBot_username").
6. ![image](https://github.com/SriKrishna74/MINI-PROJECTS/assets/127392900/de5cc838-a247-4794-9895-34194d0835f5)

7. Once your bot is created, BotFather will provide you with an API token. Save this token as you will need it in your code to interact with the Telegram API.

Step 2: Replace Variables in Your ESP32-CAM Code
In your ESP32-CAM code, you will need to replace certain variables with your specific values:

1. Replace your_WIFI_SSID with the name of your Wi-Fi network (e.g., "MyWiFiNetwork").
2. Replace your_WIFI_PASSWORD with the password for your Wi-Fi network.
3. Replace your_TELEGRAM_BOT_TOKEN with the API token provided by BotFather for your Telegram bot.
4. Replace your_TELEGRAM_CHAT_ID with your Telegram user or chat ID. To find your chat ID, you can use the following method:
5. Temporarily comment out the lines related to sending Telegram messages and capturing images in your code.
6. Upload the code to your ESP32-CAM.
7. Open the Serial Monitor in the Arduino IDE and set the baud rate to 115200.
8. Look for the line that says "Connecting to Wi-Fi..." in the Serial Monitor.
9. Once connected to Wi-Fi, the ESP32-CAM will print the IP address and the message "Ready." Your Telegram chat ID will be displayed as well. It will look something like "-123456789".
10. Could you copy this chat ID and use it in your code?
Note: For security reasons, it's essential to avoid hardcoding sensitive information (e.g., Wi-Fi credentials, Telegram API token) directly in the code. You can store this information in a separate configuration file or use other methods (e.g., EEPROM) to retrieve it securely.

Step 3: Uncomment the Relevant Lines in Your Code
After replacing the variables, uncomment the lines related to sending Telegram messages and capturing images in your code. These lines were temporarily commented out during the process of finding the Telegram chat ID.

Step 4: Upload the Code to ESP32-CAM
Compile and upload the modified code to your ESP32-CAM using the Arduino IDE.

Step 5: Test the Motion Detection System
Power on your ESP32-CAM and the PIR sensor. When the PIR sensor detects motion, the ESP32-CAM should capture an image and send a Telegram notification to your Telegram account with the captured image as evidence of the intrusion.

Remember to test your system thoroughly and ensure it works as expected. Also, be mindful of privacy and security considerations, especially when capturing images of people or private areas. Always comply with local laws and regulations related to surveillance and privacy.







   
