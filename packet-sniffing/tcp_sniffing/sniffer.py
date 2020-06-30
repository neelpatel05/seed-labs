from scapy.all import *

def process_packet(packet):

	if packet.haslayer(IP):
		ip = packet[IP]
		print("Connection, SRC IP: {}, DST IP: {}".format(ip.src, ip.dst))

	if packet.haslayer(TCP):
		tcp = packet[TCP]
		print("Port, SRC Port: {}, DST Port: {}".format(tcp.sport, tcp.dport))

	if packet.haslayer(Raw):
		data = packet[Raw]
		print("Data: {}".format(data.load))

	print("------------------------------------------------------------------------------")

sniff(iface="ens33", filter="ip", prn=process_packet)
