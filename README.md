## Vex Automatic Two-Speed Automatic Transmission
This successful experimental project was to make an automatic two-speed transition on the VEX EDR platform. The number of speeds that can be added to the VEX EDR platform is limited due to the sizes given of the gears versus the relative sizes of the metal housing and axles. However, high torque and high-speed gear shift modes are possible with the given mechanical engineering limitations within the platforms. I developed this gear shift as an independent engineering project as a junior in high school in 2017.

![gearshift photo 6](https://user-images.githubusercontent.com/100094056/193386797-682124fe-7750-46a4-9b52-05b378f6e941.jpeg)

## Final Demonstration Video:
[Gear Shift Demonstration](https://youtu.be/QJf6NvNYXGw)


## Embedded Program Function:
The program embedded program written in RobotC (a derivative of the standard C programming language) has been compiled into machine code and loaded into the VEX EDR AMR Cortex Microcontroller. The microcontroller regulates and detects the gear alignment upon bootup and operation; if the gears are out of alignment (between gears, thus causing a mechanical malfunction), the microcontroller will automatically shift the gear system into first gear (high-torque). The program allows for the toggling of the primary motor and the gear shift function. Keep in mind that the gear shift cannot shift without the primary drive motor is on, so the microcontroller will temporarily start the drive and shift motors to shift the gears in any state. All functions, primary motor and gear shift, can be activated at any time during the gear shift operation, provided that the microcontroller is one. 

## Developement Videos
In the attached Google Photo Album link are videos showing mechanical tests of the gear alignment sensors during different stages of trail, adjustment, and implementation:
[Gear Shift Developement Videos Folder.](https://photos.app.goo.gl/7Qm319Z7ymNctjct6)

## Final Version of the Source Code:
The final Release of the gear shift software as a repo link:

[VEX Robotics Gear Shift Software V.1.0 [Official Development].c](https://github.com/Austin-Daigle/VexAutomaticGearShift/blob/main/VEX%20Robotics%20Gear%20Shift%20Software%20V.1.0%20%5BOfficial%20Development%5D.c)

## Repository Development Photo Album:
[Project Photos Album (GitHub Project Directory)](https://github.com/Austin-Daigle/VexAutomaticGearShift/tree/main/ProjectPhotos)

[Google Photos Project Album](https://photos.app.goo.gl/tgFzxvXfa6HkvTrv8)
Google Album link(s) have been included along side the project photos directory incase there are issues regarding browser image size/compatibility.

