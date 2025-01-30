#include <REGX52.H>

void Delay1ms(unsigned int time)//@11.0592MHz
{
		unsigned char data i, j;
		while(time--)
		{
			i = 11;
			j = 190;
			do
			{
				while (--j);
			} while (--i);
		}
}
