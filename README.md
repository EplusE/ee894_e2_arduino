[![E+E_Logo](./images/epluse-logo.png)](https://www.epluse.com/en/)

# EE894 E2 with Arduino

|Standard | Compact|
|------------ | ------------|
|![EE894_standard](./images/EE894-co2-element_standard.png) | ![EE894_compact](./images/EE894-co2-element_compact.png)|


[![button1](./images/learn-more.png)](https://www.epluse.com/en/products/co2-measurement/co2-sensor/ee894/)   [![button2](./images/data-sheet.png)](https://downloads.epluse.com/fileadmin/data/product/ee894/datasheet_EE894.pdf) 



## QUICK START GUIDE  

### Components 
- EE894
- Arduino
- Breadboard 
- Wire jumper cable <br>
<br>

### Librarys
Please note that the library e2Interface must be included (https://github.com/EplusE/e2_interface_arduino)

| Step |                                                                                                                                                             |
|------|-------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 1    | Connect the EE894 sensor module with Arduino according to the following scheme: <br> __Standard:__ [<img src="images/EE894_arduino.png" width="25%"/>](images/EE894_arduino.png)  __Compact:__ [<img src="images/EE894_comp_arduino.png" width="25%"/>](images/EE894_comp_arduino.png)|
| 2    | Download and install the Arduino IDE (https://www.arduino.cc/en/software). Version >1.8.7 recommended.                                                            |
| 3    | Download the ZIP File of this project.|
| 4    | Open the arduino software.|
| 5    | Go to: <br>[<img src="images/add_library.png" width="550"/>](images/add_library.png) |
| 6    | Search for the downloaded ZIP File and open it.|
| 7    | Go to:<br>[<img src="images/open_file.png" width="500"/>](images/open_file.png)|
| 8    | Connect the Arduino to your PC via the USB cable. Select Board “Arduino Uno” and the appropriate COM-Port from Tools menu and upload the sketch |
| 9    | When the upload is finished, open the the "Serial Monitor" with the key combination (Control + Shift + M) or via the menu bar: <br> [<img src="images/serial_Monitor.png" width="400"/>](images/serial_Monitor.png) |
<br>



### Change bus line pins (E2_SCL,E2_SDA) 
Changing the pins can be easily done as follows:<br>
*  Open the file "SerialOutput.ino".
*  In line 11 and 12 of this file SerialOutput, you can find SDA_pin and SCL_pin. 
*  Replace the GPIO pin numbers according to your requirements.
<br> 

### Please note:
The Arduino Uno board has no hardware pull-up resistors. These are enabled internally in the <br>
microcontroller library. In case of communication problems, pull-up resistors can be added externally.<br>
For example:<br>
[<img src="images/pull_ups.PNG" width="700"/>](images/pull_ups.PNG)




<br>

## License 
See [LICENSE](LICENSE).