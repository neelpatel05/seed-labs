import socket

addr = ("0.0.0.0",9090)
socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
socket.bind(addr)

while True:
	data, (ip,port) = socket.recvfrom(1024)
	print("Sender IP: {} and Port: {}".format(ip,port))
	print("Data: {}".format(data))
