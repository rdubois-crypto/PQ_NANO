 sudo docker run --rm -ti -v "/dev/bus/usb:/dev/bus/usb" -v "$(realpath .):/app" --privileged ledger-app-builder:latest
 BOLOS_SDK=$NANOSP_SDK make load
 
# /* install ledger ctrl*/
 pip3 install "ledgercomm[hid]"
 
#/* compile and install */
#compile inside docker the root of app
sudo docker run --rm -ti -v "/dev/bus/usb:/dev/bus/usb" -v "$(realpath .):/app" --privileged ledger-app-builder:latest
BOLOS_SDK=$NANOSP_SDK make clean
BOLOS_SDK=$NANOSP_SDK make 
exit 
#move app to pkg 
cp bin/app.hex pkg/nanosp/app_nanosp.hex 
#install (unlock nano, then type)
ledgerctl install -f nanosp.json
