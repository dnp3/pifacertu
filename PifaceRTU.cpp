
#include <opendnp3/LogToStdio.h>
#include <opendnp3/DNP3Manager.h>
#include <opendnp3/SlaveStackConfig.h>
#include <opendnp3/IChannel.h>
#include <opendnp3/IOutstation.h>
#include <opendnp3/ICommandHandler.h>

extern "C" {
#include <libpiface-1.0/pfio.h>
}

#include <thread>
#include <chrono>
#include <iostream>

using namespace std;
using namespace opendnp3;

class PifaceCommandHandler : public ICommandHandler {
public:
	

};


int main(int argc, char* argv[])
{
	if(pfio_init() < 0) {
		std::cerr << "Could not initialize piface" << std::endl;
		exit(-1);
	}

	const FilterLevel LOG_LEVEL = LEV_EVENT;
	DNP3Manager mgr(1);
	auto pServer = mgr.AddTCPServer("tcpserver", LOG_LEVEL, 5000, "0.0.0.0", 20000);

	SlaveStackConfig stackConfig;
	DeviceTemplate device(4, 0, 0, 0, 0);
	stackConfig.device = device;

	auto pOutstation = pServer->AddOutstation("outstation", LOG_LEVEL, SuccessCommandHandler::Inst(), stackConfig);
	auto pDataObserver = pOutstation->GetDataObserver();

	do {
		this_thread::sleep_for( chrono::milliseconds(100) );
	}
	while(true);

	pfio_deinit();

	return 0;
}
