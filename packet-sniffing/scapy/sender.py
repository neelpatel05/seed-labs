import socket

addr = ("192.168.147.147",9090)
socket  = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

data = b"Hello World"

socket.sendto(data, addr)
