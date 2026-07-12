#include "ft_ping.h"

void	init_hints(struct addrinfo *hints)
{
	memset(hints, 0, sizeof(*hints));
	hints->ai_family = AF_INET;    /* Allow IPv4 */
	hints->ai_socktype = SOCK_RAW;
	hints->ai_flags = 0;
	hints->ai_protocol = IPPROTO_ICMP;
}

void	build_icmp_echo(struct icmp_packet *pkt, int seq)
{
	memset(pkt, 0, sizeof(*pkt));
	pkt->hdr.type = ICMP_ECHO;
	pkt->hdr.code = 0;
	pkt->hdr.un.echo.id = htons(getpid() & 0XFFFF);
	pkt->hdr.un.echo.sequence = htons(seq);

	memset(pkt->msg, 0xA5, sizeof(pkt->msg));

	pkt->hdr.checksum = 0;
	pkt->hdr.checksum = checksum(pkt, sizeof(*pkt));
}

unsigned short checksum(void *b, int len)
{
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;

    if (len == 1)
        sum += *(unsigned char *)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);  // fold carry bits
    sum += (sum >> 16);                   // add any carry from folding
    result = ~sum;                        // one's complement
    return result;
}