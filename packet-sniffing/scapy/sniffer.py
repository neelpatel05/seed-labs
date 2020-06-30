from scapy.all import *

def process_packet(packet):
	if packet.haslayer(IP):
		ip = packet[IP]
		print("IP {} : {}".format(ip.src, ip.dst))

	if packet.haslayer(TCP):
		tcp = packet[TCP]
		print("TCP src: {}, dst: {}".format(tcp.sport, tcp.dport))
	elif packet.haslayer(UDP):
		udp = packet[UDP]
		print("UDP src: {}, dst: {}".format(udp.sport, udp.dport))
	elif packet.haslayer(ICMP):
		icmp = packet[ICMP];
		print("ICMP type: {}".format(icmp.type))
	print("-------------------------------------------------------------------------------")

packet = sniff(iface="ens33", filter="ip", prn=process_packet)

packet.summary()
