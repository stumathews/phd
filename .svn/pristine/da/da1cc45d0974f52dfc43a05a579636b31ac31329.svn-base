#include <iostream>
#include "PacketSniffer.h"
using namespace std;

int main( int argc, char** argv ){

	if( argc > 1 ){
		// Start the PacketSniffer
		PacketSniffer* packetSniffer = new PacketSniffer(new string(argv[1]));
		if(packetSniffer->start() == fail)
			return 0;


		cout << "Getting each packet by hand" << endl;
		// for each packet on the wire
		Packet* packet = packetSniffer->readAPacket();
		while( packet != NULL ){
			// show the sourceIP of each packet
			cout << packet->getSourceIP() << endl;
			packet = packetSniffer->readAPacket();
		}
	}
	return 0;

}
