#ifndef FT_PING
# define FT_PING

#define _POSIX_C_SOURCE 200112L

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 500

struct icmp_packet {
    struct icmphdr hdr;
    char msg[56];   // arbitrary payload, real ping uses 56 bytes of data
};

void	init_hints(struct addrinfo *hints);
void	build_icmp_echo(struct icmp_packet *pkt, int seq);
unsigned short checksum(void *b, int len);

#endif