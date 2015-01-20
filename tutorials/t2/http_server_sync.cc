#include "http_server_sync.h"

void HTTPServerSync::start_serving(){
	if( create_bind_listen() < 0 ){
		return;
	}

	int client_sock;

	while( true ){
		//accept a client
		client_sock = accept_client();
		
		if( client_sock < 0 )	continue;

		while( true ){
			//either error/remote close
			if( process_client(client_sock) == -1 ){
				close( client_sock );
				break;
			}
		}
	}
}
