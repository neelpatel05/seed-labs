from scapy.all import *

def process_packet(packet):

	if packet.haslayer(IP):
		ip = packet[IP]
		print("Connection, SRC IP: {}, DST IP: {}".format(ip.src, ip.dst))

	if packet.haslayer(UDP):
		udp = packet[UDP]
		print("Port, SRC Port: {}, DST Port: {}".format(udp.sport, udp.dport))

	if packet.haslayer(Raw):
		data = packet[Raw]
		print("Data: {}", data.load())

	print("------------------------------------------------------------------------------")

sniff(iface="ens33", filter="ip", prn=process_packet)
