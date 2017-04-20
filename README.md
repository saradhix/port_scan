# A minimalistic port scanner
This program will try to connect to all the ports in the given range for the given ip.

## Build ##
make port_scan

This does not need any special libraries. I tried this on ubuntu and it works. Let me know if it does not work on any other flavour.

## Usage ##
port_scan <ipaddress> <port_start> <port_end>

## Example ##
port_scan 127.0.0.1 2000 8000

The above command will scan for all the ports between 2000 and 8000 inclusive.
