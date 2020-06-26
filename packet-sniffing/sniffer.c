#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/ip.h>
#include<stdlib.h>
#include<linux/if_packet.h>
#include<net/ethernet.h>

int main()
{
        int PACKET_LEN = 1024;
        char buffer[PACKET_LEN];

        struct sockaddr saddr;
        struct packet_mreq mr;

        int sock = socket(AF_INET, SOCK_RAW, htons(ETH_P_ALL));

        mr.mr_type = PACKET_MR_PROMISC;
        setsockopt(sock, SOL_PACKET, PACKET_ADD_MEMBERSHIP, &mr, sizeof(mr));

        while(1)
        {
                int data_size = recvfrom(sock, buffer, PACKET_LEN, 0, &saddr, (socklen_t*)sizeof(saddr));
                if (data_size) 
                {
                        printf("Captured data\n");
                }
        }
}

