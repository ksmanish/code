from socket import*
client = socket(AF_INET,SOCK_STREAM)			#AF_INET refers to addresses from the internet, IP addresses specifically,,,
client.connect(('localhost',56743))

while True:
    m=input("You :")
    client.send(m.encode())
    data = client.recv(1048576).decode()
    print("server : " + data)					#encoded in utf-8 format and sent to client
