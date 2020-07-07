from scapy.all import *

ID = 1000
destination_ip = "192.168.147.150"

udp = UDP(sport=7070, dport=9090, chksum=0)
udp.len = 8 + 32 + 40 + 20

ip = IP(dst=destination_ip, id=ID, frag=0, flags=1)
payload = "A"*31 + "\n"
packet = ip/udp/payload
send(packet, verbose=0)

ip = IP(dst=destination_ip, id=ID, frag=5, flags=1)
ip.proto = 17
payload = "B"*39 + "\n"
packet = ip/payload
send(packet, verbose=0)


ip = IP(dst=destination_ip, id=ID, frag=10, flags=0)
ip.proto = 17
payload = "C"*19 + "\n"
packet = ip/payload
send(packet, verbose=0)
