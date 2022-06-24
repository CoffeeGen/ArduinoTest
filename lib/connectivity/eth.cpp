#include <eth.h>

Eth::Eth() {
    Ethernet.init(10);

    byte mac[] = {
        0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02
    };

    Serial.println("Initialize Ethernet with DHCP:");

    if (Ethernet.begin(mac) == 0) 
    {
        Serial.println("Failed to configure Ethernet using DHCP");

        if (Ethernet.hardwareStatus() == EthernetNoHardware) 
        {
            Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
        } 
        else if (Ethernet.linkStatus() == LinkOFF) 
        {
            Serial.println("Ethernet cable is not connected.");
        }
    }
}

IPAddress Eth::getIpAddress() {

    IPAddress localIp = Ethernet.localIP();
    return localIp;
}