# PwrMgmt-Atmega328p
 Power Management of Arduino Nano (Atmega-328p) using the watch-dog for wake-up

This sequence offers the possibility to save power by keeping the processor in sleep mode.
Following sleep modes are available:
- SLEEP_MODE_IDLE
- SLEEP_MODE_ADC
- SLEEP_MODE_PWR_SAVE
- SLEEP_MODE_STANDBY
- SLEEP_MODE_PWR_DOWN

Different sleep durations are possible: 16ms, 32ms, 64ms, 0.125s, 0.25s, 0.5s, 1s, 2s, 4s, 8s.

For further information see http://donalmorrissey.blogspot.com/2010/04/putting-arduino-diecimila-to-sleep-part.html or chapter 14 in ATmega 328 datasheet.
![grafik](https://user-images.githubusercontent.com/75970114/153701514-ae80cb55-37e6-4053-8b0a-29e3de013a5f.png)
