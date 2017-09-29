#include "PacketSniffer.h"
#include <iostream>
using namespace std;

PacketSniffer::PacketSniffer(){
}
PacketSniffer::PacketSniffer( string* device ){

	PacketSniffer(); // call default constructor
	this->device = device;
}
void PacketSniffer::selectDevice( string* thatDevice ){
	this->device = thatDevice;
}
void PacketSniffer::setTimeout( int thatTimeout ){
	this->timeout = thatTimeout;
}
Result PacketSniffer::start(){
	handle = pcap_open_live( (char*) device->c_str(), BUFSIZ, 0, this->timeout, errBuff );
	if( handle == NULL ){
		cout << "Couldn't open device : " << device->c_str() << endl;
		cout << "Ensure you have access to this device." << endl; 
		return fail;
	}else{
		cout << device->c_str() << " : Ready."<< endl; 
	}
	
	// At this stage we are able to call readAPacket to read each packet on the wire....
	return success;	
	
	
}
void PacketSniffer::stop(){}
void PacketSniffer::restart(){}
void PacketSniffer::gotPacket( u_char* args, const struct pcap_pkthdr* header, const u_char* packet){
	/* We've got a packet. */
	/* Encapsulate it in class Packet */
	/* args contains link back to PacketSniffer class instance */


	Packet* ourPacket = new Packet(packet); 
	if (ourPacket->isValidIP()){
		cout << "[START]" << endl;
		cout << ourPacket->getSourceIP() << " --> " << ourPacket->getDestinationIP() << endl;
		cout << ourPacket->getSourceMAC() << " --> " << ourPacket->getDestinationMAC() << endl;
		cout << "[END]" << endl;

		// Monitor packets now here.
	}
}

Packet* PacketSniffer::readAPacket(){

// not allowed to run this in itergrated monior mode:

	// Read a packet from device->c_str() and return it to someone you wants to know
	Packet* packet = new Packet( pcap_next( handle, &header ) );
	return packet;
}
