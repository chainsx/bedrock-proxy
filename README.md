Edit by chainsx - chainsx@outlook.com
Thank Blake Felt - blake.w.felt@gmail.com

Bedrock Proxy
=============

A program that allows Xbox One users of Minecraft to connect to any server they
want, similar to how Android, iOS, and Windows 10 users can. Note that this
requires a computer to be running this program any time you want to play.

Tested on Linux, should work out of the box on macOS.

Compiling
=========

Requires gcc and make. Then compile with `make` in the terminal.

Configuring
=========
You can simply edit the `bedrock-proxy.conf`.
```
MAX_CLIENTS 40 
TIMEOUT 15 // seconds
CLIENT_PORT 19132 // port that the Xbox One attempts to connect to, do not change
SERVER_PORT 19132
SERVER_ADDR "exampleserver.com"
```

Running
=======

Run by typing `./bedrock-proxy` into the terminal on your main device. Both the
Xbox and the device running this need to be on the same network. You should find
the server you want in the Minecraft Friends section under LAN Games.

I have included an example systemd service file to start this automatically at boot
for any Linux users of systemd.

How It Works
============

This works by sending all udp packets from the CLIENT_PORT to the server address
and vice-versa. This will appear to the Xbox as if the server is playing on your LAN.
