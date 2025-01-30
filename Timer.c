#include <REGX52.H>

void Timer_Init()
{
	TMOD = 0x16;
	TH0 = 0xff;
	TL0 = 0xff;
	TH1 = (65536 - 50000) / 256;
	TL1 = (65536 - 50000) % 256;
	TR0 = 1;
	TR1 = 1;
	EA = 1;
	ET0 = 1;
	ET1 = 1;
}

