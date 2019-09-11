# [PlatformIO device](https://github.com/Qitas/PlatformIO) 

Linux users have to install udev rules for PlatformIO supported boards/devices. The latest version of rules may be found at https://raw.githubusercontent.com/platformio/platformio-core/master/scripts/99-platformio-udev.rules

Please check that your board’s PID and VID are listed in the rules. You can list connected devices and their PID/VID using platformio device list command.

This file must be placed at /etc/udev/rules.d/99-platformio-udev.rules (preferred location) or /lib/udev/rules.d/99-platformio-udev.rules (required on some broken systems).


```
# Recommended
curl -fsSL https://raw.githubusercontent.com/platformio/platformio-core/master/scripts/99-platformio-udev.rules | sudo tee /etc/udev/rules.d/99-platformio-udev.rules

# OR, manually download and copy this file to destination folder
sudo cp 99-platformio-udev.rules /etc/udev/rules.d/99-platformio-udev.rules
```


```
sudo service udev restart

# or

sudo udevadm control --reload-rules
sudo udevadm trigger

```

```
sudo usermod -a -G dialout $USER
sudo usermod -a -G plugdev $USER
```

You will need to log out and log back in again (or reboot) for the user group changes to take effect.
After this file is installed, physically unplug and reconnect your board.

### 查看连接设备

*  platformio device list [OPTIONS]
*  pio device list [OPTIONS]


### 其他方式

```
openocd -f interface/stlink-v2.cfg -c "transport select hla_swd" -f target/stm32f4x.cfg
openocd -f interface/stlink-v2.cfg -c "transport select hla_swd" -f target/stm32f1x.cfg
```