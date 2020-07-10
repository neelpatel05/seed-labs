import socket

IP = "0.0.0.0"
PORT = 9090

socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
socket.bind((IP, PORT))

while True:
	data, (ip, port) = socket.recvfrom(1024)
	print("Sender: {} and port: {}".format(ip,port))
	print("Data recieved: {}".format(data))

	socket.sendto(b"Thank you", (ip,port))


