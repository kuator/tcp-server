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
  struct sockaddr_in server_addres, client_address;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
      printf("ERROR opening socket");
      exit(0);
  }
  memset(&server_addres, 0, sizeof(server_addres));
  server_addres.sin_family = AF_INET;
  server_addres.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addres.sin_port = htons(PORT);

  if(bind(sockfd, (struct sockaddr*)&server_addres, sizeof(server_addres)) != 0){
    printf("ERROR binding");
    exit(0);
  }

  if ((listen(sockfd, 5)) == -1) {
       printf("Listen failed...\n");
       exit(0);
   }

   int struct_size = sizeof(client_address);
   int connfd = accept(sockfd, (struct sockaddr *)&client_address, &struct_size);
   if (connfd < 0) {
     printf("server acccept failed...\n");
     exit(0);
  }
  
  read(connfd, buff, sizeof(buff));

  printf("%s\n", buff);
  printf("%s", "server is doing great!");

  write(connfd, buff, sizeof(buff));

  memset(buff, 0, MESSAGE_LEN);

  close(sockfd);
  close(connfd);
}
