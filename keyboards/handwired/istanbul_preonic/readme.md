# handwired/istanbul_preonic

![handwired/istanbul_preonic](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [Andres Aravena](https://github.com/anaraven)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make handwired/istanbul_preonic:default

Flashing example for this keyboard:

    make handwired/istanbul_preonic:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
* QMK Toolbox 0.2.2 (https://qmk.fm/toolbox)
* Supported bootloaders:
*  - ARM DFU (APM32, Kiibohd, STM32, STM32duino) via dfu-util (http://dfu-util.sourceforge.net/)
*  - Atmel/LUFA/QMK DFU via dfu-programmer (http://dfu-programmer.github.io/)
*  - Atmel SAM-BA (Massdrop) via Massdrop Loader (https://github.com/massdrop/mdloader)
*  - BootloadHID (Atmel, PS2AVRGB) via bootloadHID (https://www.obdev.at/products/vusb/bootloadhid.html)
*  - Caterina (Arduino, Pro Micro) via avrdude (http://nongnu.org/avrdude/)
*  - HalfKay (Teensy, Ergodox EZ) via Teensy Loader (https://pjrc.com/teensy/loader_cli.html)
*  - LUFA/QMK HID via hid_bootloader_cli (https://github.com/abcminiuser/lufa)
*  - LUFA Mass Storage
* Supported ISP flashers:
*  - AVRISP (Arduino ISP)
*  - USBasp (AVR ISP)
*  - USBTiny (AVR Pocket)
Caterina device connected: Adafruit In Adafruit Feather (239A:000C:0001) [/dev/cu.usbmodem2101]
Attempting to flash, please don't remove device
> avrdude -p atmega32u4 -c avr109 -U flash:w:/Users/anaraven/Hobby/qmk_firmware/handwired_istanbul_preonic_default.hex:i -P /dev/cu.usbmodem2101 -C avrdude.conf
> 
> Connecting to programmer: .
> Found programmer: Id = "CATERIN"; type = S
>     Software Version = 1.0; No Hardware Version given.
> Programmer supports auto addr increment.
> Programmer supports buffered memory access with buffersize=128 bytes.
> 
> Programmer supports the following devices:
>     Device code: 0x44
> 
> avrdude: AVR device initialized and ready to accept instructions
> 
> Reading | ################################################## | 100% 0.00s
> 
> avrdude: Device signature = 0x1e9587 (probably m32u4)
> avrdude: NOTE: "flash" memory has been specified, an erase cycle will be performed
>          To disable this feature, specify the -D option.
> avrdude: erasing chip
> avrdude: reading input file "/Users/anaraven/Hobby/qmk_firmware/handwired_istanbul_preonic_default.hex"
> avrdude: writing flash (16386 bytes):
> 
> Writing | ################################################## | 100% 1.31s
> 
> avrdude: 16386 bytes of flash written
> avrdude: verifying flash memory against /Users/anaraven/Hobby/qmk_firmware/handwired_istanbul_preonic_default.hex:
> avrdude: load data flash data from input file /Users/anaraven/Hobby/qmk_firmware/handwired_istanbul_preonic_default.hex:
> avrdude: input file /Users/anaraven/Hobby/qmk_firmware/handwired_istanbul_preonic_default.hex contains 16386 bytes
> avrdude: reading on-chip flash data:
> 
> Reading | ################################################## | 100% 0.19s
> 
> avrdude: verifying ...
> avrdude: 16386 bytes of flash verified
> 
> avrdude done.  Thank you.
Flash complete
Caterina device disconnected: Adafruit In Adafruit Feather (239A:000C:0001) [/dev/cu.usbmodem2101]
