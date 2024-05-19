# Binovation

## Description
This repository contains Arduino programs for our MyScience project "Binovation". The Bin Sensor is designed to measure the height of the garbage inside a bin over a period of time that is triggered via button press. It then sends the measurements to the Serial console, which then can be inserted into the Binovation Website and processed.

## Installation
To use the Bin Sensor project, follow these steps:

1. Clone the repository to your local machine:
    ```
    git clone https://github.com/your-username/Binovation.git
    ```

2. Connect the Arduino board to your computer.

3. Open the Arduino IDE.

4. Open the `V5 deepsleep_final.ino` file from the cloned repository in the Arduino IDE.

5. Select the appropriate board and port in the Arduino IDE.

6. Click on the "Upload" button in the Arduino IDE to upload the code to the Arduino board.


## Building the sensor
Parts used:
- Arduino Nano Iot 33
- Ultrasonic Sensor HC-SR04P
- Button with four pins
- Battery case with two AA batteries 

This is the schematic for the sensor including the button and the ultrasonic sensor. If you want to connect an external battery, connect it to the VIN and Ground pin of the Arduino.

![Sensor Schematics](https://github.com/kaiwxn/Binovation/blob/main/img/Sensor_mit_Button_Schaltplan.png?raw=true)

We used a 3D-printed case to protect the Sensor from environmental factors, e.g. rain and snow, which has an openable lid and two holes for the MicroUSB cable and the button. The arrangement of the parts inside the case is shown in the following image.

![Cross Section picture](https://github.com/kaiwxn/Binovation/blob/main/img/Sensor_Querschnitt.jpg?raw=true)


## Contributing
If you have questions or would like to contribute to this project, please follow these guidelines:

- Fork the repository.
- Create a new branch for your feature or bug fix.
- Make your changes and commit them.
- Push your changes to your forked repository.
- Submit a pull request to the main repository.

## License
This project is licensed under the Apache License. See the [LICENSE](LICENSE) file for more information.

## Credits
Kaiwxn