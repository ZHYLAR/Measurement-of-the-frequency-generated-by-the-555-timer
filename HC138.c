#include <REGX52.H>

void SelectHC138(unsigned char which)
{
	switch(which)
	{
		case 4:
			P2_7 = 1;
			P2_6 = 0;
			P2_5 = 0;
		break;
		case 5:
			P2_7 = 1;
			P2_6 = 0;
			P2_5 = 1;
		break;
		case 6:
			P2_7 = 1;
			P2_6 = 1;
			P2_5 = 0;
		break;
		case 7:
			P2_7 = 1;
			P2_6 = 1;
			P2_5 = 1;
		break;
		case 3:  //都不选
			P2_7 = 0;
			P2_6 = 1;
			P2_5 = 1;
		break;
	}
}