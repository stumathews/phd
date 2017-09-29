
import com.stuartmathews.Client.Startup.*;
import com.stuartmathews.Client.Discovery.PacketSniffer.*;
class PHD {

	public static void main( String[] args ) {
		System.out.println("Passive Host Detection Started.");
		Platform platform = new Platform();
		Network network = new Network();
		PacketSniffer packetSniffer = new PacketSniffer();
	}
}
