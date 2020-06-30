import socket

addr = ("0.0.0.0", 9090)
socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socket.bind(addr)
socket.listen(10)
conn, addr = socket.accept()

while True:
	data = conn.recvfrom(1024)
	print("Client: {}".format(data))

	message = input("You: ")
	message = message.encode()
	conn.sendto(message, addr)