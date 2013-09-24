/*
 * RA_Wiznet5100.h
 *
 *  Created on: Sep 11, 2013
 *      Author: Benjamin
 */

#ifndef RA_WIZNET5100_H_
#define RA_WIZNET5100_H_

#ifdef ETH_WIZ5100
#include <SPI.h>
#include <Ethernet.h>
#include <EthernetDHCP.h>
#include <RA_Wifi.h>
#include <avr/wdt.h>

static EthernetServer NetServer(2000);
static byte NetMac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
static IPAddress NetIP(192,168,1,200);
const IPAddress PortalServer(198,171,134,6);
const IPAddress RelayServer(46,137,106,125);
static EthernetClient NetClient;
static EthernetClient RelayClient;
static boolean RelayConnected;
static int RelayIndex;
#define PORTAL_TIMEOUT  10000

class RA_Wiznet5100 : public RA_Wifi
{
public:
	RA_Wiznet5100();
	void Init();
	void ReceiveData();
	void ProcessEthernet();
	void ProcessRelayEthernet();
	void Update();
	void DirectAccess(String uniqueid);
	boolean PortalConnection;
	unsigned long PortalTimeOut;

private:
	boolean bIncomingR;
	unsigned long timeoutR;
	String uid;
protected:
	size_t write(uint8_t c);
	size_t write(unsigned long n);
	size_t write(long n);
	size_t write(unsigned int n);
	size_t write(int n);
};
#endif  // ETH_WIZ5100
#endif /* RA_WIZNET5100_H_ */

