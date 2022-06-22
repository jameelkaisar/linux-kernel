# linux-kernel
Modified Version of Linux Kernel

## Installation
### Before Installation
```
ajmi@burner:~$ uname -mrs
Linux 5.13.0-1031-azure x86_64
```

### Install Requirements
```
sudo apt update
sudo apt upgrade
sudo apt install build-essential libncurses-dev bison flex libssl-dev libelf-dev dwarves zstd
```

### Clone Linux Kernel Repository
```
git clone https://github.com/JameelKaisar/linux-kernel.git
```

### Change Directory
```
cd linux-kernel
```

### Copy Config File
```
cp -v /boot/config-$(uname -r) .config
```

### Modify Config File
```
sudo make menuconfig
```
- Save and Exit

### Edit Config File
```
sudo nano .config
```
- Set CONFIG_SYSTEM_TRUSTED_KEYS to ""
- Set CONFIG_SYSTEM_REVOCATION_KEYS to ""

### Compile Linux Kernel (takes time)
```
sudo make -j$(nproc)
```
#### Secret Command (skip this)
```
sleep 5 && echo start > ~/start.txt && sudo make -j$(nproc) > ~/logs.txt 2> ~/errors.txt && echo success > ~/success.txt || echo fail > ~/fail.txt & disown
```

### Install Linux Kernel Modules
```
sudo make modules_install -j$(nproc)
```

### Install the Linux Kernel
```
sudo make install -j$(nproc)
```

### Update GRUB Config
```
sudo update-initramfs -c -k 5.19.0-rc3
sudo update-grub
```

### Reboot Device
```
sudo reboot
```

### After Installation
```
ajmi@burner:~$ uname -mrs
Linux 5.19.0-rc3 x86_64
```
