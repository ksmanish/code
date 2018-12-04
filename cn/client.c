
// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080 
   
int main(int argc, char const *argv[]) 
{ 
    struct sockaddr_in address; 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
   // char *hello = "Hello from client"; 
    char buffer[1024] = {0}; 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    memset(&serv_addr, '0', sizeof(serv_addr)); 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
        printf("Client : ");
    char text[100]="dsfds\0";
    while(1){
        text[0]='\0';
        memset(buffer, 0, 1023);
        scanf ("%[^\n]%*c", text);
        if(strcmp(text,"`")==0 || strcmp(text,"`")==0)
            break;
        send(sock , text , strlen(text) , 0 ); 
        //printf("message sent!!\n *************_________________*************\n\n"); 
        valread = read( sock , buffer, 1024); 
        if(valread==0){
            printf("server diconnected !!!!\n");
        }
        else{
        printf("\t\t\t Server : %s\n",buffer ); 
        printf("Client : ");
        }
    }
    return 0; 
} 
