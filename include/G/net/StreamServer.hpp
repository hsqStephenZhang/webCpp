#ifndef _STREAMSERVER_HPP_
#define _STREAMSERVER_HPP_

extern "C"
{
    #include "G/net/Gnet.h"
}

#include "G/net/Server.hpp"
#include "G/event/EventListener.hpp"

namespace G {

    class StreamServer: virtual public G::Server
    {
    // parent protected:
    //     virtual SOCKET initSocket() =0;
    // parent public:
    //     virtual int service(G::IOEvents *, int) =0;
        G::EventListener *listener;
        static void onData(Event *);
    protected:
        virtual int _service(G::Protocoler *, int) override;
    public:
        void init(G::EventListener *);
        StreamServer();
        virtual ~StreamServer() =0;
    };

}

#endif
