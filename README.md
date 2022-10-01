## Vex Automatic Two-Speed Automatic Transmission
This successful experimental project was to make an automatic two-speed transition on the VEX EDR platform. The number of speeds that can be added to the VEX EDR platform is limited due to the sizes given of the gears versus the relative sizes of the metal housing and axles. However, high torque and high-speed gear shift modes are possible with the given mechanical engineering limitations within the platforms.


![gearshift photo 6](https://user-images.githubusercontent.com/100094056/193386797-682124fe-7750-46a4-9b52-05b378f6e941.jpeg)



## Embedded Program Function:
The program embedded program written in RobotC (a derivative of the standard C programming language) has been compiled into machine code and loaded into the VEX EDR AMR Cortex Microcontroller. The microcontroller regulates and detects the gear alignment upon bootup and operation; if the gears are out of alignment (between gears, thus causing a mechanical malfunction), the microcontroller will automatically shift the gear system into first gear (high-torque). The program allows for the toggling of the primary motor and the gear shift function. Keep in mind that the gear shift cannot shift without the primary drive motor is on, so the microcontroller will temporarily start the drive and shift motors to shift the gears in any state. All functions, primary motor and gear shift, can be activated at any time during the gear shift operation, provided that the microcontroller is one. 



## Final Version of the Source Code:
The final Release of the gear shift software as a repo link:

[VEX Robotics Gear Shift Software V.1.0 [Official Development].c](https://github.com/Austin-Daigle/VexAutomaticGearShift/blob/main/VEX%20Robotics%20Gear%20Shift%20Software%20V.1.0%20%5BOfficial%20Development%5D.c)

## Repository Development Photo Album:
[Project Photos Album (GitHub Project Directory)](https://github.com/Austin-Daigle/VexAutomaticGearShift/tree/main/ProjectPhotos)

If there are size/compatibility issues with the images in the project images directory, an equivalent Google Album link has been linked:

[Google Photos Project Album](https://photos.app.goo.gl/tgFzxvXfa6HkvTrv8)
