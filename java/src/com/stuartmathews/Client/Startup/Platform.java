package com.stuartmathews.Client.Startup;

public class Platform {
	public Platform(){
		System.out.println("Detecting architecture ... ");
		detectArch();
	
	}

	private void detectArch(){

		System.out.println(" + Platform architecture : " + System.getProperty("os.arch") );
		System.out.println(" + Operating system name : " + System.getProperty("os.name") );
		System.out.println(" + Operating system version : " + System.getProperty("os.version") );
	}
}
