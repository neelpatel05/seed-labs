from scapy.all import *

def spoof_chat(packet):

	if UDP in packet:
		if packet.haslayer(Raw):
			data = packet[Raw].load
		else:
			data = None

	print("Original packet")
	print("Packet Source: {}".format(packet[IP].src))
	print("Packet Destination: {}".format(packet[IP].dst))
	print("Packet Data: {}".format(data))
	print("-------------------------------------------------------")

sniff(filter="ip", prn=spoof_chat)