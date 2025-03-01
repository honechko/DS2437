# 1-wire meteo sensor

Development in progress

| Task | Status |
| ---  | ---    |
| firmware                    | READY     |
| web-interface (calibration) | READY     |
| Arduino library             | READY     |
| native PCB                  | NOT READY |
| documentation               | NOT READY |

This device is based on ATtiny13A with closed-source firmware with author's
features. It is not DS2437 or its replacement, but it is developed to be
possible to use it with a lot of software written for DS2437
(such as [OWFS](https://github.com/owfs/owfs) or Linux kernel modules).

## Main usage

* air temperature & relative humidity measurement
* analog nonlinear sensor reading

## Key features

* built-in NTC thermistor
* support for cheap HR202L/HR31 resistive humidity sensor (including alternating current & temperature compensation)
* one alalog input for user's sensor
* three optional conversion tables with linear interpolation between points
* sensors calibration at any time by modifying conversion tables in EEPROM
* ready to use results

## Example of web-interface

![Web-interface](https://github.com/honechko/DS2437/raw/main/Docs/setup.png)
