#include<stdio.h>


int main(int argc, char **argv)

  struct sockaddr_in servaddr;
  int sock = socket(AF_INET, SOCK_STREAM, 0);

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(6789);
  servaddr.sin_addr.s_addr = inet_addr(<ip_address_of_server>);

  while(1) {

    char message[161];
    fgets(message, 161, stdin);

    /* Replacing '\n' with '\0' */
    char *tmp = strchr(message, '\n');
    if (tmp) *tmp = '\0';

    connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
    send(sock, message, strlen(message), 0);
    close(sock);
  }
int main(int argc, char **argv) {

  struct sockaddr_in servaddr;
  int sock = socket(AF_INET, SOCK_STREAM, 0);

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(6789);

  bind(sock, (struct sockaddr *)&servaddr, sizeof(servaddr));
  listen(sock, 5);

  while(1) {
    int clisock = accept(sock, (struct sockaddr *) NULL, NULL);

    if (clisock >= 0) {
      int messageLength = 160;
      char message[messageLength+1];
      int in, index = 0, limit = messageLength;

      while ((in = recv(clisock, &message[index], messageLength, 0)) > 0) {
        index += in;
        limit -= in;
      }

      printf("%s\n", message);
    }

    close(clisock);
  }
}
