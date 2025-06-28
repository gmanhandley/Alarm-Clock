# Alarm-Clock
I created an alarm clock from scratch.
The goal of this project was to explore embedded programming and circuit design.
As a way to practice embedded programming I decided I would take an existing product and do my best to replicate it in a way that I liked.
This project was done before I adopted having previous versions of programs so I will only be uploading the final code and circuit diagram to this repository.
I will however describe the problems that I faced along the way and the steps I took to fix them.

For this project I wanted to use an arduino to dip my toes into the world of microcontrolers.
This turned out to be pretty simple as arduino is well documented and has its own IDE that makes uploading programs very easy.
I wanted to use a four-digit seven-segment display to display the time because I like the classic digital bedside clock look.
So I downloaded the avafruit display library and created a simple program where I could manualy enter the the time to display and upload it to the arduino.
I did this by creating a class that automatically sent the correct electrical signals to the four-digit seven-segment display based on the requested number and I created an object for each digit on the display.
This unfortunately did not work as the display that I used is only capable of displaying one number at a time.
Trying to display multiple numbers at once caused allof the internal LEDs to light up which was not usable.
I got around this by flashing one number at a time using a delay that I found to not look flashy and also keep the display readable.
After getting a static time to properly display, I wrote a small algorithm to slowly increment the displayed time with real time.
My first attempt involved using the millis() function built into the arduino system.
This was a good start however the algorithm that I initialy created to increment the time was dependant on reading very exact values from the millis function.
This was easily fixed by adjusting the calculations and logical operations of the algorithm.
With the algorithm working properly and the clock incrementing the time correctly, I needed create a way for the user to adjust the time on the device without flashing a new program every time.
I did this by wiring two buttons to the arduino.
One button increments the minutes by one and the other increments the hours by one.
I reused the incrementing algorithm and added some while loops and this solution worked well.
The next, and perhapse most important, feature that needed to be added to this alarm clock was an alarm and a way to set it.
This was accomplished by wiring up another button to toggle "alarmMode".
Inside of this mode I programmed the previous buttons to work the exact same but only change the alarm time.

In the end I did create a functioning alarm clock.
However, it is in no way perfect and there are many thing that I would change if I decide to redo or more likely edit the project.
Firstly, I would rewrite the code.
While the program I wrote is functional, it was not very forward thinking.
It would greatly benefit from moving much of the body of the code, like the incrementation algorithm, into methods.
Secondly, while it does technically work, the program does not distinguish between am and pm times effectively making this a true 12-hour clock.
Adding this would truely complete the project and make it an everyday usaable item.
Third, I would rewire everything.
To be specific I would wire it up to a shift register to reclaim some pins on the arduino and solder the system together to make it more compact.
This would allow for future expansion if I wanted to add something to it.
Fourth, I would make an enclosure for it.
This would be mostly for safety but also for aesthetics.
