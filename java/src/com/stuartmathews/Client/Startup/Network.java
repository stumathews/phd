package com.stuartmathews.Client.Startup;
import jpcap.*;
public class Network {

	public Network(){
		System.out.println("Detecting network equipment");
		detectNetworkEquipment();
	}
	private void detectNetworkEquipment(){
		System.out.println(" + Detecting network interfaces as user : " + System.getProperty("user.name") );
		devices = JpcapCaptor.getDeviceList();		
		for( int i = 0 ; i < devices.length; i++){
			System.out.println( "  "+ i + ". " +  devices[i].name );
		}
	}
	// Network Interfaces found on the network
	private NetworkInterface[] devices;
}
