Project Codebase: https://github.com/nsafwan/cse321-project

Project Setup
--------------
This is an embedded systems project that requires some hardware and software components. The hardware needed and the connections required for that hardware to create the project is detailed below.

Hardware Components/Parts Required:
1) 1x Arduino UNO R3 Controller Board
2) 1x HC-SR501 PIR Motion Sensor Module
3) 1x DHT11 Temperature and Humidity Module
4) 1x 3-6v Motor
5) 1x Red LED
6) 1x Fan Blade
7) 1x Power Supply Module
8) 1x 9V Battery with Snap-on Connector Clip
9) 1x L293D (Motor Control Bridge)
10) 1x 220 Ohm Resistor
11) 10x Male-Male Jumper Wires
12) 3x Male-Female Jumper Wires
13) 1x Breadboard

The next steps detail the connections needed for the hardware components to create the project. An image with the connections is given in the Phase 3 Documentation file on figure 1.

Step 1:
Connect the Power Supply Module to an end of the breadboard. Connect the 9v battery to the Power supply module. Connect the ground lane of the breadboard (- lane) to the GND pin in the UNO.

Step 2: 
Connect the PIR sensor to the arduino pin 7 using the male-female jumper wires. Connect its ground and power pin to the breadboard.

Step 3: 
Using the breadboard, connect the Red LED to the Arduino. Its long leg should be connected with the 220 ohm resistor and the resistor should be connected to pin 13 on the Arduino using a jumper wire. The LED's short leg should be connected to the ground on the breadboard.

Step 4: 
Connect the DHT11 Temperature sensor to the breadboard. Its output pin should be connected to Pin 2 in the UNO. Its ground pin should be connected to the ground and power pin to the power in the breadboard using the jumper wires.

Step 5: 
Connect the 3-6v motor to the Arduino using the motor control bridge. First, connect the bridge to the two lanes of the breadboard. The 1st pin of the bridge is the enable pin which should be connected to 5th input in the uno. The 2nd pin is the input pin connected to the 4th pin in the uno. The 3rd in is the output pin connected to one of the wires of the motor. The 4th pin is the ground pin connected to ground on the breadboard. The 5th pin is unconnected. The 6th pin is the second output pin connected to the other wire of the motor. The 7th pin is the input 2 pin connected to the 3rd input in the Arduino. The last pin is the power pin connected to the power lane on the breadboard. 

Afterwards, the project code will need to be upload to the Arduino. First, download the DHT_nonblocking folder which is a library needed for this project. Upload that library using the Arduino software. The project code is available in the project_code folder in the codebase/repository linked above. Download that and use the Arduino software to upload it to the board.

The project should be ready to go after that. 

Project Use
--------------
After uploading the project .ino file into the Arduiono, the project should turn on.
After waiting around 1 min for the PIR sensor to give out accurate results, walk infront of the PIR sensor or move a hand infront of it. 
The Red LED should turn on once the PIR detects the motion. You should also see a message in the Serial Monitor for the board that says the Fan is turned on. 
If the current temperature is higher than the preset threshold temperature (set to 20C here), the motor and the fans should also turn on. 
The Serial monitor will display the speed of the fan. Otherwise, the fans will remain off.

To tweak the temperature threshold, simply modify the threshold variable in the project_code.ino file to the desired value.

Remove any sort of movement infront of the PIR sensor, and the fans and light should turn off after a few seconds.

The motion and the temperature are the factors that control the outputs which are the fans and the light. They together give out information that can be used to automatically turn on the lighting and cooling depending on the need (temperature and the presence of someone).
