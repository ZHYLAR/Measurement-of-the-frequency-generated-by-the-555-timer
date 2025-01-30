#include <REGX52.H>
#include "Timer.h"
#include "SMG.h"

unsigned int Freq;
void Disp()
{
	SMG_Show(1, 15);
	if(Freq / 10000 != 0)
	{
		SMG_Show(4, Freq / 10000);
		SMG_Show(5, Freq / 1000 % 10);
		SMG_Show(6, Freq / 100 % 10);
		SMG_Show(7, Freq / 10 % 10);
		SMG_Show(8, Freq % 10);
	} else if(Freq / 1000 != 0)
	{
		SMG_Show(4, 18);
		SMG_Show(5, Freq / 1000 % 10);
		SMG_Show(6, Freq / 100 % 10);
		SMG_Show(7, Freq / 10 % 10);
		SMG_Show(8, Freq % 10);
	} else if(Freq / 100 != 0)
	{
		SMG_Show(4, 18);
		SMG_Show(5, 18);
		SMG_Show(6, Freq / 100 % 10);
		SMG_Show(7, Freq / 10 % 10);
		SMG_Show(8, Freq % 10);
	} else if(Freq / 10 != 0)
	{
		SMG_Show(4, 18);
		SMG_Show(5, 18);
		SMG_Show(6, 18);
		SMG_Show(7, Freq / 10 % 10);
		SMG_Show(8, Freq % 10);
	} else 
	{
		SMG_Show(4, 18);
		SMG_Show(5, 18);
		SMG_Show(6, 18);
		SMG_Show(7, 18);
		SMG_Show(8, Freq % 10);
	}
}

void main()
{
	Timer_Init();
	while(1)
	{
		Disp();
	}
}

unsigned int Timer0Count;
void Timer0_Rounte() interrupt 1
{
	Timer0Count++;
}

unsigned char Timer1Count;
void Timer1_Rounte() interrupt 3
{
	TH1 = (65536 - 50000) / 256;
	TL1 = (65536 - 50000) % 256;
	Timer1Count++;
	if(Timer1Count >= 20)
	{
		Freq = Timer0Count;
		Timer0Count = 0;
		Timer1Count = 0;
	}
}