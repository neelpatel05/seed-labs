from scapy.all import *

E = Ether()
A = ARP()

packet = E/A
sendp(packet)

print(packet)
print(E)
print(A)
