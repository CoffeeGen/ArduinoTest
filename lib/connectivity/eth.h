#include <SPI.h>
#include <Ethernet.h>

// byte mac[] = {
//   0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02
// };

class Eth
{
    public:
        Eth();
        static IPAddress getIpAddress();
};