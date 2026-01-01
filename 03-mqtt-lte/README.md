# Connecting to an MQTT Broker

In this exercise from the *Cellular IoT Fundamentals* course at the Nordic Developer Academy, the main goal was to **connect an nRF91 Series device to an MQTT broker** and perform **bidirectional MQTT communication** between the device and another MQTT client (such as a PC or mobile phone) using cellular IoT technology (LTE-M / NB-IoT).

## 1. MQTT configuration on the device
The project was configured to use the MQTT helper library from the nRF Connect SDK:
- Enabled the MQTT library in `prj.conf`.
- Defined MQTT publish and subscribe topics (for example, `dancasi/publish/topic` and `dancasi/subscribe/topic`).

## 2. Connecting to the MQTT broker
The application connects the device to an MQTT broker (`mqtt.nordicsemi.academy`) over the cellular network:
- The device acts as an MQTT client.
- The broker acts as the central point for message exchange between the device and another client.
- The software MQTT-Explorer-0.3.5 was used to connect the PC as a second MQTT client.

## 3. Bidirectional MQTT communication
After the connection is established:
- When **Button 1 is pressed** on the device, it publishes a message to the configured MQTT topic.
- Another MQTT client (running on a PC or phone) can **subscribe to this topic** and receive the message.
- The external client can also **publish messages to the subscribed topic**, which are received by the device and used to control LEDs (e.g., `LED1ON`, `LED1OFF`).

## 4. Remote control of hardware components
With this setup, it was possible to:
- Publish data to the broker using hardware events (button presses).
- Receive MQTT commands from the broker to turn LEDs on and off on the device.

## References
- https://docs.nordicsemi.com/bundle/nrf-apis-latest/page/structmqtt_helper_cfg.html
- https://docs.nordicsemi.com/bundle/nrf-apis-latest/page/structmqtt_helper_cfg.html
- https://www.ibm.com/docs/en/ibm-mq/9.1.x?topic=tls-how-provides-identification-authentication-confidentiality-integrity
- https://docs.nordicsemi.com/bundle/ncs-latest/page/zephyr/connectivity/networking/api/sockets.html#tls_credentials_subsystem