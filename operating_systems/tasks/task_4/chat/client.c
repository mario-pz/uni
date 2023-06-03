#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define SOCK_PATH "/tmp/average_socket"
#define MAX_SEQ_LEN 100
#define MAX_RESPONSE_LEN 30

int main(void) {
    int s, t, len;
    struct sockaddr_un remote;
    char seq[MAX_SEQ_LEN];
    
    // Creating Unix domain socket
    if ((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    
    // Connecting to the server
    remote.sun_family = AF_UNIX;
    strncpy(remote.sun_path, SOCK_PATH, sizeof(remote.sun_path)-1);
    len = sizeof(remote.sun_family) + strlen(remote.sun_path);
    if (connect(s, (struct sockaddr *)&remote, len) == -1) {
        perror("connect");
        exit(1);
    }
    
    printf("Connected to server.\n");
    
    // Sending sequences of integers to server
    while (1) {
        printf("Enter a sequence of integers (separated by spaces): ");
        fgets(seq, MAX_SEQ_LEN, stdin);
        if (seq[0] == '\n') break;
        if (send(s, seq, strlen(seq), 0) == -1) {
            perror("send");
            exit(1);
        }
        // Receiving response from server
        char response[MAX_RESPONSE_LEN];
        int numbytes = recv(s, response, MAX_RESPONSE_LEN - 1, 0);
        if (numbytes == -1) {
            perror("recv");
            exit(1);
        }
        response[numbytes] = '\0';
        printf("Server response: %s\n", response);
    }
    
    // Closing the connection
    close(s);
    return 0;
}

