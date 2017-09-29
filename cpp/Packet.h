/**

-	Packet Class - Generic Packet Object
	Description  - This is a view of a Packet as an Object in OOP

**/



#include <iostream>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/if_ether.h>
#include <netinet/ether.h>
#include <pcap.h>
#include <arpa/inet.h>

using namespace std;
const int SIZE_ETHERNET = 14;




class Packet
{
public:
	// turn a raw packet from pcap into a Packet object :-)
	Packet( const u_char* packet){ loadAPacket( packet ); }

	// Public Interface to Packet Object:	
	
	char* getSourceIP();	
	char* getDestinationIP();
	char* getDestinationMAC();
	char* getSourceMAC();
	const u_char* getRawPacket(){ return packet; }
	bool  isValidIP();
	bool  isValidTCP();
private:
	// PRIVATE DATA MEMBERS
	const  u_char* packet; // raw network packet
	// Network headers structures
	struct ip* ip_header;
	struct ether_header* ethernet_header;
	struct tcphdr* tcp_header;
	int    size_ethernet_header;
	int    size_ip_header;
	int    size_tcp_header;
	// Network Address Structures
	struct ether_addr* ethernet_addr;
	struct in_addr ip_address;
	// Functions:
	//
	void   loadAPacket( const u_char* packet )
	{
		ethernet_header = (struct ether_header*)(packet);
		ip_header = (struct ip*)(packet + SIZE_ETHERNET); 
		tcp_header = (struct tcphdr*)(packet + SIZE_ETHERNET +size_ip_header);
		this->packet = packet;
		// Sizes please!
		size_ethernet_header = sizeof( struct ether_header );
		size_ip_header = sizeof( struct ip );
		size_tcp_header = sizeof( struct tcphdr );
	}
	
};
