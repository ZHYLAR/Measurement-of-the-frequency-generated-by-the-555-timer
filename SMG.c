#include <REGX52.H>
#include "HC138.h"
#include "Delay.h"

code unsigned char Seg_Table[] =
{
0xc0, //0
0xf9, //1
0xa4, //2
0xb0, //3
0x99, //4
0x92, //5
0x82, //6
0xf8, //7
0x80, //8
0x90, //9
0x88, //A
0x83, //b
0xc6, //C
0xa1, //d
0x86, //E
0x8e, //F
0xbf, //-
0x00, //all 
0xff, //nall
};

void SMG_Show(unsigned char pos, unsigned char Num)
{
	SelectHC138(6);
	P0 = 0x01 << pos - 1;
	SelectHC138(7);
	P0 = Seg_Table[Num];
	Delay1ms(1);//消影
	SelectHC138(3);//锁
}

//void SMG_ShowDoc(unsigned char pos, unsigned char Num)
//{
//	SelectHC138(6);
//	P0 = 0x01 << pos - 1;
//	SelectHC138(7);
//	P0 = Seg_Table[Num] & 0x7f;
//	Delay1ms(1);//消影
//	SelectHC138(3);//锁
//}
