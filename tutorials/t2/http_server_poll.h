#include <sys/poll.h>
#include <vector>

#include "http_server_base.h"

class HTTPServerPoll : public HTTPServerBase {
 public:
	void start_serving();

	HTTPServerPoll( int port ) : 
		HTTPServerBase( port ) { }
};
