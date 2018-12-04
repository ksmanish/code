
// Server side implementation of UDP client-server model 
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
    char *hello = "Hello from server"; 
    struct sockaddr_in servaddr, cliaddr; 
      
    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
      
    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr)); 
      
    // Filling server information 
    servaddr.sin_family    = AF_INET; // IPv4 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT); 
      
    // Bind the socket with the server address 
    if ( bind(sockfd, (const struct sockaddr *)&servaddr,  
            sizeof(servaddr)) < 0 ) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
      
    int len, n;
    char text[100]="dsfds\0"; 
    while(1){
        n = recvfrom(sockfd, (char *)buffer, MAXLINE,  
                    MSG_WAITALL, ( struct sockaddr *) &cliaddr, 
                    &len); 
         //printf("%d *********** \n",n );
        if(n==0){
            printf("client diconnected !!!!\n");
        }
        else{
            buffer[n] = '\0'; 
            printf("Client : %s \n\t\t\t",buffer); 
            printf("Server : ");
        }
        text[0]='\0';
        memset(buffer, 0, 1023);
        scanf ("%[^\n]%*c", text);
        if(strcmp(text,"`")==0 || strcmp(text,"`")==0)
            break;
        sendto(sockfd, text, strlen(text),  
            MSG_CONFIRM, (const struct sockaddr *) &cliaddr, 
                len); 
        //printf("Hello message sent.\n");  
    }  
    return 0; 
} 
