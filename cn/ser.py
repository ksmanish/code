from socket import*
server = socket(AF_INET,SOCK_STREAM)  #AF_INET refers to addresses from the internet, IP addresses specifically,,,
server.bind(('localhost',56743))
server.listen(2)
client,addr = server.accept()

while True:
    data = client.recv(1048576).decode()  
    print("client : " + data)
    m=input("You :")
    client.send(m.encode())				#encoded in utf-8 format and sent to client
