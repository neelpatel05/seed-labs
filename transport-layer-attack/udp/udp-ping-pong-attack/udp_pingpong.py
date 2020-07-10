from scapy.all import *

ip = IP(src="192.168.147.149",dst="192.168.147.150")
udp = UDP(sport=9090, dport=9090)
data = "Lets start ping pong"
packet = ip/udp/data
send(packet, verbose=0)
