#include "ft_ping.h"

int main(int argc, char** argv)
{

	struct addrinfo hints;
	struct addrinfo *result;
	struct sockaddr_in *dest;
	// struct icmphdr hdr;
	char ipstr[INET_ADDRSTRLEN];
	int status;
	// size_t len;
	// ssize_t nread;
	// char buf[BUF_SIZE];

	if (argc < 2) {
		fprintf(stderr, "ping: usage error: Destination address required\n");
		exit(EXIT_FAILURE);
	}

	init_hints(&hints);

	status = getaddrinfo(argv[1], NULL, &hints, &result);
	if (status != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
		exit(EXIT_FAILURE);
	}

	// 
	dest = (struct sockaddr_in *)result->ai_addr;
	inet_ntop(AF_INET, &(dest->sin_addr), ipstr, sizeof(ipstr));




	
	// int socketfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	// if (socketfd == -1) {
		// 	perror("socket");
		// 	return 1;
		// }
		
	printf("PING google.com (%s)...\n", ipstr);
	return (0);
}