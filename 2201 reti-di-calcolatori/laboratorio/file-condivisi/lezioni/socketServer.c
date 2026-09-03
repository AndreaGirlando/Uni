#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define ever (;;)   //è una define per far fare un ciclo infintio al for scrivendo for ever
#define BACKLOG 4 //max clients in queue
#define PORT 8080

int create_server(uint16_t port) {

    int socketServerFD;
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    
    if ((socketServerFD = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind and listen
    if (bind(socketServerFD, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind failed");
        return -2;
    }

    if (listen(socketServerFD, BACKLOG) < 0) {
        perror("listen failed");
        return -3;
    }

    return socketServerFD;
}

int main() {

    int server_fd, client_fd;
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    
    server_fd = create_server(PORT);
    if (server_fd < 0) exit(1);
    printf("Server running on port %d\n", PORT);

    for ever {
        // Accept new connection
        if ((client_fd = accept(server_fd, (struct sockaddr*)&addr, &addr_len)) < 0) {
            perror("accept failed");
            continue;
        }
        
        // Fork a child process to handle client
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            close(client_fd);
        }
        else if (pid == 0) { // Child process (client)
            close(server_fd); // Child doesn't need listener

            // Get current time
            time_t now = time(NULL);
            struct tm *tm_info = gmtime(&now);
            char buffer[1024];

            // Format time string
            strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%SZ\n", tm_info);

            // Send response
            send(client_fd, buffer, strlen(buffer), 0);

            // Cleanup and exit
            close(client_fd);
            _exit(0);
        }
        else { // Server process
            close(client_fd); // Server doesn't need client socket
        }
    }

    close(server_fd);
    return 0;
}