#include "ft_ping.h"

int main(int argc, char** argv)
{

	struct addrinfo hints;
	struct addrinfo *result;
	struct sockaddr_in *dest;
	struct icmp_packet pkt;
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
		fprintf(stderr, "ping: %s: %s\n", argv[1], gai_strerror(status));
		exit(EXIT_FAILURE);
	}


	dest = (struct sockaddr_in *)result->ai_addr;
	inet_ntop(AF_INET, &(dest->sin_addr), ipstr, sizeof(ipstr));

	build_icmp_echo(&pkt, 1);
	
	int socketfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (socketfd == -1) {
		perror("socket");
		freeaddrinfo(result);
		return 1;
	}

	// sendto(socketfd, &pkt, sizeof(pkt), 0, (struct sockaddr *)dest, sizeof(*dest));
		
	printf("PING %s (%s): 56 data bytes\n", argv[1], ipstr);

	freeaddrinfo(result);
	close(socketfd);
	return (0);
}
