import socket

addr = ("192.168.147.150", 9090)
socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socket.connect(addr)

while True:
	message = input("You: ")
	message = message.encode()

	socket.sendto(message, addr)

	data = socket.recvfrom(1024)
	print("Server: {}".format(data))