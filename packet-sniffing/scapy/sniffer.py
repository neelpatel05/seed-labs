from scapy.all import *

def process_packet(packet):
	packet.show()
	print("-----------------------------------------------------------------")

packet = sniff(iface="ens33", filter="icmp or udp", prn=process_packet)

packet.summary()
