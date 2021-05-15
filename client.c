#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


int main(){

  int sockfd, PORT=8080;
  int MESSAGE_LEN = 100;
  char buff[MESSAGE_LEN];
  memset(buff, 0, MESSAGE_LEN);
  struct sockaddr_in server_addres;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
      printf("ERROR opening socket");
      exit(0);
  }
  memset(&server_addres, 0, sizeof(server_addres));
  server_addres.sin_family = AF_INET;
  server_addres.sin_addr.s_addr = inet_addr("127.0.0.1");
  server_addres.sin_port = htons(PORT);

  if(connect(sockfd, (struct sockaddr*)&server_addres, sizeof(server_addres)) != 0){
    printf("ERROR connecting");
    exit(0);
  }

  strcpy(buff, "Hey hey people!");
  
  write(sockfd, buff, sizeof(buff));

  memset(buff, 0, MESSAGE_LEN);

  read(sockfd, buff, sizeof(buff));

  printf("%s\n", buff);
  printf("%s", "Client reporting");

  close(sockfd);
}
