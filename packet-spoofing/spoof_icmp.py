from scapy.all import *
import time


def spoof_packet(packet):
	if ICMP in packet and packet[ICMP].type == 8:
		print("Original Packet")
		print("SRC IP: {}, DST IP: {}".format(packet[IP].src, packet[IP].dst))

		ip = IP(src=packet[IP].dst, dst=packet[IP].src, ihl=packet[IP].ihl)
		ip.ttl = 99
		icmp = ICMP(type=0, id=packet[ICMP].id, seq=packet[ICMP].seq)

		if packet.haslayer(Raw):
			data = packet[Raw].load
			new_packet = ip/icmp/data
		else:
			new_packet = ip/icmp

		print("Spoofed packet")
		print("SRC IP: {}, DST IP: {}".format(new_packet[IP].src, new_packet[IP].dst))

		time.sleep(2)
		print(new_packet.show())
		send(new_packet, verbose=0)

	print("--------------------------------------------------------------------------------------------")

sniff(filter="icmp and src host 192.168.147.150", prn=spoof_packet)