import socket

addr = ("0.0.0.0", 9090)
socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
socket.bind(addr)

while True:
	data, (ip, port) = socket.recvfrom(1024)
	print("Client: {}".format(data.decode()))

	message = input("You: ")
	message = message.encode()
	socket.sendto(message, (ip, port))
