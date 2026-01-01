# Connecting to a CoAP Server

In this exercise from the *Cellular IoT Fundamentals* course, the goal was to **establish bidirectional communication between an nRF91 Series device and another CoAP client using a public CoAP server**. The board communicates with the server and with a client (like a PC or mobile) using the CoAP protocol over the cellular network.

### 1. Enabled the CoAP library
- Added `CONFIG_COAP=y` and related configuration in the `prj.conf` so that the CoAP support is compiled into the application.  
- Included the CoAP header (`#include <zephyr/net/coap.h>`) in the source code. :contentReference[oaicite:1]{index=1}

### 2. Configured the CoAP settings
- Set the CoAP server address (for example `californium.eclipseprojects.io`) via `CONFIG_COAP_SERVER_HOSTNAME`.  
- Defined resource names for sending (TX) and receiving (RX) CoAP messages. :contentReference[oaicite:2]{index=2}

### 3. Sending messages from the board
- When **Button 1** is pressed on the board, it sends a **GET request** to the CoAP server’s RX resource.  
- When **Button 2** is pressed, it sends a **PUT request** with a message from the board to the server. :contentReference[oaicite:3]{index=3}

### 4. Interacting with another CoAP client
- On a PC, tablet, or smartphone, a CoAP client (e.g., **cf-browser**) connects to the same CoAP server.
- The client sends **PUT requests** to the board’s RX resource to send messages to the device.
- The client sends **GET requests** to the board’s TX resource to receive messages from the device. :contentReference[oaicite:4]{index=4}

## Overall Logic Summary

1. **Configure CoAP in the firmware**
2. **Connect the board to the cellular network**
3. **Use CoAP to send GET/PUT messages via the server**
4. **Use a CoAP client (on PC/mobile) to interact with the board**

## Issues
Got the problem ncs/v2.9.1/zephyr/lib/posix/options/posix_clock.h:17:10: fatal error: zephyr/syscalls/posix_clock.h: No such file or directory.
In order to solved it, the CONFIG_POSIX_CLOCK=y was addeed to the prj.conf

## References
- https://docs.nordicsemi.com/bundle/ncs-latest/page/zephyr/connectivity/networking/api/coap.html#coap