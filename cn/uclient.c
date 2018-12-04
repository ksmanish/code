
// Client side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
  
#define PORT     8080 
#define MAXLINE 1024 
  
// Driver code 
int main() { 
    int sockfd; 
    char buffer[MAXLINE]; 
    char *hello = "Hello from client"; 
    struct sockaddr_in     servaddr; 
  
    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
  
    memset(&servaddr, 0, sizeof(servaddr)); 
      
    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
      
    int n, len; 
    char text[100]="dsfds\0";
     printf("Client : ");
    while(1){  
        text[0]='\0';
        memset(buffer, 0, 1023);
         scanf ("%[^\n]%*c", text);
         if(strcmp(text,"`")==0 || strcmp(text,"`")==0)
            break;
        sendto(sockfd,text, strlen(text), 
            MSG_CONFIRM, (const struct sockaddr *) &servaddr,  
                sizeof(servaddr)); 
        //printf("Hello message sent.\n"); 
              
        n = recvfrom(sockfd, (char *)buffer, MAXLINE,  
                    MSG_WAITALL, (struct sockaddr *) &servaddr, 
                    &len); 

        if(n==0){
            printf("server diconnected !!!!\n");

        }
        else{
            buffer[n] = '\0'; 
            printf("\t\t\t Server : %s\n", buffer); 
            printf("Client : ");
        }
      
    }
        close(sockfd); 
    return 0; 
} 
