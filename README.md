# PQ_NANO

A little NanoApp integration of PQ primitives on a Nano.
The selected algorithme are NIST finalists:
- kyber (as the sole lattice KEM remaining)
- falcon (the lowest bandwidth/storage candidate)


## Building the project:

### install ledger ctrl :
> pip3 install "ledgercomm[hid]"
 
 
###  compile and install 
- compile inside docker the root of app :

> sudo docker run --rm -ti -v "/dev/bus/usb:/dev/bus/usb" -v "$(realpath .):/app" --privileged ledger-app-builder:latest
> BOLOS_SDK=$NANOSP_SDK make clean
> BOLOS_SDK=$NANOSP_SDK make 
> exit 
### move app to pkg 
> cp bin/app.hex pkg/nanosp/app_nanosp.hex 
### install (unlock nano with PIN, then type)
> ledgerctl install -f nanosp.json

## Related project:
- falcon low footprint: https://falcon-sign.info/Falcon-impl-20211101.zip
- pqm4 :https://github.com/mupq/pqm4
