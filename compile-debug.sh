#! /bin/bash
meson setup build --buildtype=debug
ninja -C build
meson compile -C build
echo "[ANY KEY] to continue..."
while [ true ] ; do
read -t 3 -n 1
if [ $? = 0 ] ; then
clear
exit ;
