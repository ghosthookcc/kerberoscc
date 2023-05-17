cd build
clear
./demo
echo "[ANY KEY] to continue..."
while [ true ] ; do
read -t 3 -n 1
if [ $? = 0 ] ; then
cd ..
clear
exit ;