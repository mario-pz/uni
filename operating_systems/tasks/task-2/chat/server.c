#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define SOCK_PATH "/tmp/average_socket"
#define MAX_SEQ_LEN 100

int main(void) {
    int s, s2, t, len;
    struct sockaddr_un local, remote;
    char seq[MAX_SEQ_LEN];
    int num_requests = 0;
    int num_accepted = 0;
    
    // Creating Unix domain socket
    if ((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    
    // Binding socket to a local address
    local.sun_family = AF_UNIX;
    strncpy(local.sun_path, SOCK_PATH, sizeof(local.sun_path)-1);
    unlink(local.sun_path);
    len = sizeof(local.sun_family) + strlen(local.sun_path);
    if (bind(s, (struct sockaddr *)&local, len) == -1) {
        perror("bind");
        exit(1);
    }
    
    // Listening for connections
    if (listen(s, 5) == -1) {
        perror("listen");
        exit(1);
    }
    
    printf("Server is running and waiting for clients...\n");
    
    while (1) {
        // Accepting connection
        int done, n;
        printf("Waiting for a connection...\n");
        t = sizeof(remote);
        if ((s2 = accept(s, (struct sockaddr *)&remote, &t)) == -1) {
            perror("accept");
            exit(1);
        }
        printf("Connection accepted.\n");
        done = 0;
        num_requests++;
        
        // Receiving sequence of integers
        while (!done) {
            n = recv(s2, seq, MAX_SEQ_LEN-1, 0);
            if (n <= 0) {
                if (n < 0) perror("recv");
                done = 1;
            }
            if (!done) {
                seq[n] = '\0';
                printf("Received sequence: %s\n", seq);
                int sum = 0, count = 0, i = 0;
                char *ptr = strtok(seq, " ");
                while (ptr != NULL && i < MAX_SEQ_LEN) {
                    sum += atoi(ptr);
                    count++;
                    i++;
                    ptr = strtok(NULL, " ");
                }
                double average = (double) sum / count;
                if (average > 10) {
                    // Sending acceptance message with average
                    char response[50];
                    snprintf(response, 50, "Sequence ok. Average is %.2f", average);
                    send(s2, response, strlen(response), 0);
                    num_accepted++;
                } else {
                    // Sending failure message
                    char response[] = "Check Failed";
                    send(s2, response, strlen(response), 0);
                }
            }
        }
        close(s2);
    }
    return 0;
}

