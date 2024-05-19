# Binovation

## Description
This repository contains Arduino programs for our MyScience project "Binovation". The Sensor is designed to measure the height of the garbage inside a garbage bin over a period of time. 
It then sends the measurements to the Serial console, which then can be inserted into the Binovation Website and processed.

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

## How to start a measurement
1. **Install this project** and upload it to the microcontroller. See [#Installation](#installation)

2. **Place the sensor** inside a garbage bin with the ultrasonic sensor poining downwards

3. **Start the measurement** with a button press. Note: You may have to configure the duration of the measurement inside the uploaded file.

4. **To finish the measurement** please connect the board to a device (e.g. your computer) and connect the board with Arduino IDE. Then press the button again. In the Serial monitor, it should ask you to reply with "1". After that, the measurements are printed to the console.


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