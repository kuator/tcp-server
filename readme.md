Simple tcp server that can be run in a local network.
To be able to send messages from one network to another, it is necessary to enable
port forwarding on your default gateway a.k.a router. Map the router's ip to server ip.
Port forwarding is necessary because router is the device which holds the public ip.
All the other devices are using private local IPs.

# TODO
1. Implement a chat using this tcp server
2. Build a simple http server based on this tcp server
