#include "chaine.h"

int gestionAccent(char* pchar)
{
	while (*pchar) {
		switch (*pchar)

		{

		case -1:
			*pchar = 152;
			break;
		case -3:
			*pchar = 235;
			break;
		case -4:
			*pchar = 129;
			break;
		case -5:
			*pchar = 150;
			break;
		case -6:
			*pchar = 163;
			break;
		case -7:
			*pchar = 151;
			break;
		case -10:
			*pchar = 148;
			break;
		case -12:
			*pchar = 147;
			break;
		case -13:
			*pchar = 224;
			break;
		case -14:
			*pchar = 149;
			break;
		case -15:
			*pchar = 164;
			break;
		case -17:
			*pchar = 139;
			break;
		case -18:
			*pchar = 140;
			break;
		case -19:
			*pchar = 161;
			break;
		case -20:
			*pchar = 141;
			break;
		case -21:
			*pchar = 137;
			break;
		case -22:
			*pchar = 136;
			break;
		case -23:
			*pchar = 130;
			break;
		case -24:
			*pchar = 138;
			break;
		case -25:
			*pchar = 135;
			break;
		case -26:
			*pchar = 145;
			break;
		case -27:
			*pchar = 134;
			break;
		case -28:
			*pchar = 132;
			break;
		case -29:
			*pchar = 198;
			break;
		case -30:
			*pchar = 131;
			break;
		case -31:
			*pchar = 160;
			break;
		case -32:
			*pchar = 133;
			break;
		case -36:
			*pchar = 154;
			break;
		case -37:
			*pchar = 233;
			break;
		case -38:
			*pchar = 234;
			break;
		case -39:
			*pchar = 232;
			break;
		case -43:
			*pchar = 153;
			break;
		case -44:
			*pchar = 226;
			break;
		case -46:
			*pchar = 227;
			break;
		case -47:
			*pchar = 165;
			break;
		case -49:
			*pchar = 216;
			break;
		case -50:
			*pchar = 215;
			break;
		case -51:
			*pchar = 214;
			break;
		case -53:
			*pchar = 211;
			break;
		case -54:
			*pchar = 210;
			break;
		case -55:
			*pchar = 144;
			break;
		case -56:
			*pchar = 212;
			break;
		case -57:
			*pchar = 128;
			break;
		case -58:
			*pchar = 146;
			break;
		case -59:
			*pchar = 143;
			break;
		case -60:
			*pchar = 142;
			break;
		case -61:
			*pchar = 199;
			break;
		case -62:
			*pchar = 182;
			break;
		case -63:
			*pchar = 181;
			break;
		case -64:
			*pchar = 183;
			break;
		}
		pchar = pchar + 1;
	}
	return *pchar;

}
void FormatAccent(unsigned char* pchar)
{
	while (*pchar)
	{
		switch (*pchar)
		{
		case 128:
			*pchar = 99;
			break; // ' Ç '
		case 129:
			*pchar = 117;
			break; // ' ü '
		case 130:
			*pchar = 101;
			break; // ' é '
		case 131:
			*pchar = 97;
			break; // ' â '
		case 132:
			*pchar = 97;
			break; // ' ä '
		case 133:
			*pchar = 97;
			break; // ' à '
		case 134:
			*pchar = 97;
			break; // ' å '
		case 135:
			*pchar = 99;
			break; // ' ç '
		case 136:
			*pchar = 101;
			break; // ' ê '
		case 137:
			*pchar = 101;
			break; // ' ë '
		case 138:
			*pchar = 101;
			break; // ' è '
		case 139:
			*pchar = 105;
			break; // ' ï '
		case 140:
			*pchar = 105;
			break; // ' î '
		case 141:
			*pchar = 105;
			break; // ' ì '
		case 142:
			*pchar = 97;
			break; // ' Ä '
		case 143:
			*pchar = 97;
			break; // ' Å '
		case 144:
			*pchar = 101;
			break; // ' É '
		case 145:
			*pchar = 97;
			break; // ' æ '
		case 146:
			*pchar = 97;
			break; // ' Æ '
		case 147:
			*pchar = 111;
			break; // ' ô '
		case 148:
			*pchar = 111;
			break; // ' ö '
		case 149:
			*pchar = 111;
			break; // ' ò '
		case 150:
			*pchar = 117;
			break; // ' û '
		case 151:
			*pchar = 117;
			break; // ' ù '
		case 152:
			*pchar = 121;
			break; // ' ÿ '
		case 153:
			*pchar = 111;
			break; // ' Ö '
		case 154:
			*pchar = 117;
			break; // ' Ü '
		case 160:
			*pchar = 97;
			break; // ' á '
		case 161:
			*pchar = 105;
			break; // ' í '
		case 162:
			*pchar = 111;
			break; // ' ó '
		case 163:
			*pchar = 117;
			break; // ' ú '
		case 164:
			*pchar = 110;
			break; // ' ñ '
		case 165:
			*pchar = 110;
			break; // ' Ñ '
		case 181:
			*pchar = 97;
			break; // ' Á '
		case 182:
			*pchar = 97;
			break; // ' Â '
		case 183:
			*pchar = 97;
			break; // ' À '
		case 198:
			*pchar = 97;
			break; // ' ã '
		case 199:
			*pchar = 97;
			break; // ' Ã '
		case 210:
			*pchar = 101;
			break; // ' Ê '
		case 211:
			*pchar = 101;
			break; // ' Ë '
		case 212:
			*pchar = 101;
			break; // ' È '
		case 214:
			*pchar = 105;
			break; // ' Í '
		case 215:
			*pchar = 105;
			break; // ' Î '
		case 216:
			*pchar = 105;
			break; // ' Ï '
		case 224:
			*pchar = 111;
			break; // ' ó '
		case 226:
			*pchar = 111;
			break; // ' Ô '
		case 227:
			*pchar = 111;
			break; // ' Ò '
		case 228:
			*pchar = 111;
			break; // ' Õ '
		case 232:
			*pchar = 117;
			break; // ' Ú '
		case 233:
			*pchar = 117;
			break; // ' Û '
		case 234:
			*pchar = 117;
			break; // ' Ù '
		case 235:
			*pchar = 121;
			break; // ' ý '
		}

		pchar++;
	}
}
