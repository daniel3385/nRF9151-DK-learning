# Cellular IoT Connection Using Nordic Libraries

## Overview
This project is a simple embedded application developed for a Nordic nRF91 Series cellular device.

## What the code does
- Initializes the cellular modem using the LTE Link Controller library  
- Connects the device to a cellular network (LTE-M or NB-IoT)  
- Waits until the device is successfully registered on the network  
- Turns on an LED to indicate that the network connection is established  
- Outputs modem status information to the console for debugging purposes  

## Reference
https://docs.nordicsemi.com/bundle/ncs-latest/page/nrf/libraries/modem/lte_lc.html#c.lte_lc_evt_type
https://docs.nordicsemi.com/bundle/nwp_042/page/WP/nwp_042/intro.html
https://docs.nordicsemi.com/bundle/ref_at_commands_nrf91x1/page/REF/at_commands/nw_service/cedrxs_set.html
https://docs.nordicsemi.com/bundle/ref_at_commands_nrf91x1/page/REF/at_commands/intro_nrf91x1.html
https://docs.nordicsemi.com/bundle/addon-serial_modem-latest/page/index.html
https://docs.nordicsemi.com/bundle/nwp_044/page/WP/nwp_044/intro.html
https://docs.nordicsemi.com/bundle/ncs-latest/page/nrfxlib/nrf_modem/README.html

## Useful Docs
https://devzone.nordicsemi.com/nordic/nordic-blog/b/blog/posts/ltem-vs-nbiot-field-test-how-distance-affects-power-consumption
https://www.gsma.com/solutions-and-impact/technologies/internet-of-things/deployment-map/