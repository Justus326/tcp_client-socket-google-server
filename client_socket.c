#include <sys/socket.h>
#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);

    char* ip = "142.250.188.46";
    
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(80);
    inet_pton(AF_INET, ip, &address.sin_addr.s_addr);

    int result = connect(socketFD, (struct sockaddr *) &address, sizeof address);

    if(result == 0)
    printf("connection was successful");

    char* message;
    message = "GET \\ HTTP/1.1\r\nHost:google.com\r\n\r\n";
    send(socketFD, message, strlen(message), 0);

    char buffer[1024];
    recv(socketFD, buffer, 1024, 0);

    printf("Response was %s\n", buffer);

    return 0; 
}