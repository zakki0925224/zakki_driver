# zakki_driver

## usage

```sh
# compile
$ make

# install driver
$ make install
$ sudo mknod -m 666 /dev/zakki c $(cat /proc/devices | grep zakki | cut -d ' ' -f 1) 0

$ cat /dev/zakki
# Hello! I'm Zakki, a low-level programmer!
# Check out my links below:
#         X: https://x.com/zakki0925224
#         GitHub: https://github.com/zakki0925224
#         Portfolio: https://zakki0925224.github.io

$ sudo dmesg | tail

# uninstall driver
$ make uninstall
$ sudo rm /dev/zakki

```
