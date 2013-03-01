
#include <opendnp3/LogToStdio.h>
#include <opendnp3/DNP3Manager.h>
#include <opendnp3/SlaveStackConfig.h>
#include <opendnp3/IChannel.h>
#include <opendnp3/IOutstation.h>
#include <opendnp3/SimpleCommandHandler.h>

#include <thread>
#include <chrono>

using namespace std;
using namespace opendnp3;

int main(int argc, char* argv[])
{
	// Specify a FilterLevel for the stack/physical layer to use.
	// Log statements with a lower priority will not be logged.
	const FilterLevel LOG_LEVEL = LEV_EVENT;

	// This is the main point of interaction with the stack
	DNP3Manager mgr(1); // only 1 thread is needed for a single stack

	// You can optionally subcribe to log messages
	// This singleton logger just prints messages to the console
	// mgr.AddLogSubscriber(LogToStdio::Inst());

	// Add a TCPServer to the manager with the name "tcpserver".
	// The server will wait 3000 ms in between failed bind calls.
	auto pServer = mgr.AddTCPServer("tcpserver", LOG_LEVEL, 5000, "0.0.0.0", 20000);

	// The master config object for a slave. The default are
	// useable, but understanding the options are important.
	SlaveStackConfig stackConfig;

	// The DeviceTemplate struct specifies the structure of the
	// slave's database
	DeviceTemplate device(5, 5, 5, 5, 5);
	stackConfig.device = device;

	// Create a new slave with a log level, command handler, and
	// config info this	returns a thread-safe interface used for
	// updating the slave's database.
	auto pOutstation = pServer->AddOutstation("outstation", LOG_LEVEL, SuccessCommandHandler::Inst(), stackConfig);

	auto pDataObserver = pOutstation->GetDataObserver();
		
	do {				
		/*
		Transaction t(pDataObserver); //automatically calls Start()/End()
		pDataObserver->Update(Counter(count), 0);
		++count;
		*/
		this_thread::sleep_for( chrono::milliseconds(100) );
	}
	while(true);

	return 0;
}
