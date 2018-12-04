
// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080 
int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
   // printf("%lld\n", address);
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
   // char *hello = "Hello from server"; 
       
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
    //char quit[30]="abx\0";
    char text[100]="dsfds\0";
    while(1){
        valread = read( new_socket , buffer, 1024); 
        if(valread==0){
            printf("client diconnected !!!!\n");
            //break;
        }
        else{
            printf("Client : %s \n\t\t\t",buffer); 
            printf("Server : ");
        }
        text[0]='\0';
        memset(buffer, 0, 1023);
        scanf ("%[^\n]%*c", text);
        if(strcmp(text,"`")==0 || strcmp(text,"`")==0)
            break;
        send(new_socket , text , strlen(text) , 0 ); 
        //printf("message sent!!\n *************_________________*************\n\n"); 
    }
    return 0; 
} 
