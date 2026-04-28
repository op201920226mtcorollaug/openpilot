#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_5401193060823608157) {
   out_5401193060823608157[0] = delta_x[0] + nom_x[0];
   out_5401193060823608157[1] = delta_x[1] + nom_x[1];
   out_5401193060823608157[2] = delta_x[2] + nom_x[2];
   out_5401193060823608157[3] = delta_x[3] + nom_x[3];
   out_5401193060823608157[4] = delta_x[4] + nom_x[4];
   out_5401193060823608157[5] = delta_x[5] + nom_x[5];
   out_5401193060823608157[6] = delta_x[6] + nom_x[6];
   out_5401193060823608157[7] = delta_x[7] + nom_x[7];
   out_5401193060823608157[8] = delta_x[8] + nom_x[8];
   out_5401193060823608157[9] = delta_x[9] + nom_x[9];
   out_5401193060823608157[10] = delta_x[10] + nom_x[10];
   out_5401193060823608157[11] = delta_x[11] + nom_x[11];
   out_5401193060823608157[12] = delta_x[12] + nom_x[12];
   out_5401193060823608157[13] = delta_x[13] + nom_x[13];
   out_5401193060823608157[14] = delta_x[14] + nom_x[14];
   out_5401193060823608157[15] = delta_x[15] + nom_x[15];
   out_5401193060823608157[16] = delta_x[16] + nom_x[16];
   out_5401193060823608157[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6380590775890380336) {
   out_6380590775890380336[0] = -nom_x[0] + true_x[0];
   out_6380590775890380336[1] = -nom_x[1] + true_x[1];
   out_6380590775890380336[2] = -nom_x[2] + true_x[2];
   out_6380590775890380336[3] = -nom_x[3] + true_x[3];
   out_6380590775890380336[4] = -nom_x[4] + true_x[4];
   out_6380590775890380336[5] = -nom_x[5] + true_x[5];
   out_6380590775890380336[6] = -nom_x[6] + true_x[6];
   out_6380590775890380336[7] = -nom_x[7] + true_x[7];
   out_6380590775890380336[8] = -nom_x[8] + true_x[8];
   out_6380590775890380336[9] = -nom_x[9] + true_x[9];
   out_6380590775890380336[10] = -nom_x[10] + true_x[10];
   out_6380590775890380336[11] = -nom_x[11] + true_x[11];
   out_6380590775890380336[12] = -nom_x[12] + true_x[12];
   out_6380590775890380336[13] = -nom_x[13] + true_x[13];
   out_6380590775890380336[14] = -nom_x[14] + true_x[14];
   out_6380590775890380336[15] = -nom_x[15] + true_x[15];
   out_6380590775890380336[16] = -nom_x[16] + true_x[16];
   out_6380590775890380336[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_1549609507722461041) {
   out_1549609507722461041[0] = 1.0;
   out_1549609507722461041[1] = 0.0;
   out_1549609507722461041[2] = 0.0;
   out_1549609507722461041[3] = 0.0;
   out_1549609507722461041[4] = 0.0;
   out_1549609507722461041[5] = 0.0;
   out_1549609507722461041[6] = 0.0;
   out_1549609507722461041[7] = 0.0;
   out_1549609507722461041[8] = 0.0;
   out_1549609507722461041[9] = 0.0;
   out_1549609507722461041[10] = 0.0;
   out_1549609507722461041[11] = 0.0;
   out_1549609507722461041[12] = 0.0;
   out_1549609507722461041[13] = 0.0;
   out_1549609507722461041[14] = 0.0;
   out_1549609507722461041[15] = 0.0;
   out_1549609507722461041[16] = 0.0;
   out_1549609507722461041[17] = 0.0;
   out_1549609507722461041[18] = 0.0;
   out_1549609507722461041[19] = 1.0;
   out_1549609507722461041[20] = 0.0;
   out_1549609507722461041[21] = 0.0;
   out_1549609507722461041[22] = 0.0;
   out_1549609507722461041[23] = 0.0;
   out_1549609507722461041[24] = 0.0;
   out_1549609507722461041[25] = 0.0;
   out_1549609507722461041[26] = 0.0;
   out_1549609507722461041[27] = 0.0;
   out_1549609507722461041[28] = 0.0;
   out_1549609507722461041[29] = 0.0;
   out_1549609507722461041[30] = 0.0;
   out_1549609507722461041[31] = 0.0;
   out_1549609507722461041[32] = 0.0;
   out_1549609507722461041[33] = 0.0;
   out_1549609507722461041[34] = 0.0;
   out_1549609507722461041[35] = 0.0;
   out_1549609507722461041[36] = 0.0;
   out_1549609507722461041[37] = 0.0;
   out_1549609507722461041[38] = 1.0;
   out_1549609507722461041[39] = 0.0;
   out_1549609507722461041[40] = 0.0;
   out_1549609507722461041[41] = 0.0;
   out_1549609507722461041[42] = 0.0;
   out_1549609507722461041[43] = 0.0;
   out_1549609507722461041[44] = 0.0;
   out_1549609507722461041[45] = 0.0;
   out_1549609507722461041[46] = 0.0;
   out_1549609507722461041[47] = 0.0;
   out_1549609507722461041[48] = 0.0;
   out_1549609507722461041[49] = 0.0;
   out_1549609507722461041[50] = 0.0;
   out_1549609507722461041[51] = 0.0;
   out_1549609507722461041[52] = 0.0;
   out_1549609507722461041[53] = 0.0;
   out_1549609507722461041[54] = 0.0;
   out_1549609507722461041[55] = 0.0;
   out_1549609507722461041[56] = 0.0;
   out_1549609507722461041[57] = 1.0;
   out_1549609507722461041[58] = 0.0;
   out_1549609507722461041[59] = 0.0;
   out_1549609507722461041[60] = 0.0;
   out_1549609507722461041[61] = 0.0;
   out_1549609507722461041[62] = 0.0;
   out_1549609507722461041[63] = 0.0;
   out_1549609507722461041[64] = 0.0;
   out_1549609507722461041[65] = 0.0;
   out_1549609507722461041[66] = 0.0;
   out_1549609507722461041[67] = 0.0;
   out_1549609507722461041[68] = 0.0;
   out_1549609507722461041[69] = 0.0;
   out_1549609507722461041[70] = 0.0;
   out_1549609507722461041[71] = 0.0;
   out_1549609507722461041[72] = 0.0;
   out_1549609507722461041[73] = 0.0;
   out_1549609507722461041[74] = 0.0;
   out_1549609507722461041[75] = 0.0;
   out_1549609507722461041[76] = 1.0;
   out_1549609507722461041[77] = 0.0;
   out_1549609507722461041[78] = 0.0;
   out_1549609507722461041[79] = 0.0;
   out_1549609507722461041[80] = 0.0;
   out_1549609507722461041[81] = 0.0;
   out_1549609507722461041[82] = 0.0;
   out_1549609507722461041[83] = 0.0;
   out_1549609507722461041[84] = 0.0;
   out_1549609507722461041[85] = 0.0;
   out_1549609507722461041[86] = 0.0;
   out_1549609507722461041[87] = 0.0;
   out_1549609507722461041[88] = 0.0;
   out_1549609507722461041[89] = 0.0;
   out_1549609507722461041[90] = 0.0;
   out_1549609507722461041[91] = 0.0;
   out_1549609507722461041[92] = 0.0;
   out_1549609507722461041[93] = 0.0;
   out_1549609507722461041[94] = 0.0;
   out_1549609507722461041[95] = 1.0;
   out_1549609507722461041[96] = 0.0;
   out_1549609507722461041[97] = 0.0;
   out_1549609507722461041[98] = 0.0;
   out_1549609507722461041[99] = 0.0;
   out_1549609507722461041[100] = 0.0;
   out_1549609507722461041[101] = 0.0;
   out_1549609507722461041[102] = 0.0;
   out_1549609507722461041[103] = 0.0;
   out_1549609507722461041[104] = 0.0;
   out_1549609507722461041[105] = 0.0;
   out_1549609507722461041[106] = 0.0;
   out_1549609507722461041[107] = 0.0;
   out_1549609507722461041[108] = 0.0;
   out_1549609507722461041[109] = 0.0;
   out_1549609507722461041[110] = 0.0;
   out_1549609507722461041[111] = 0.0;
   out_1549609507722461041[112] = 0.0;
   out_1549609507722461041[113] = 0.0;
   out_1549609507722461041[114] = 1.0;
   out_1549609507722461041[115] = 0.0;
   out_1549609507722461041[116] = 0.0;
   out_1549609507722461041[117] = 0.0;
   out_1549609507722461041[118] = 0.0;
   out_1549609507722461041[119] = 0.0;
   out_1549609507722461041[120] = 0.0;
   out_1549609507722461041[121] = 0.0;
   out_1549609507722461041[122] = 0.0;
   out_1549609507722461041[123] = 0.0;
   out_1549609507722461041[124] = 0.0;
   out_1549609507722461041[125] = 0.0;
   out_1549609507722461041[126] = 0.0;
   out_1549609507722461041[127] = 0.0;
   out_1549609507722461041[128] = 0.0;
   out_1549609507722461041[129] = 0.0;
   out_1549609507722461041[130] = 0.0;
   out_1549609507722461041[131] = 0.0;
   out_1549609507722461041[132] = 0.0;
   out_1549609507722461041[133] = 1.0;
   out_1549609507722461041[134] = 0.0;
   out_1549609507722461041[135] = 0.0;
   out_1549609507722461041[136] = 0.0;
   out_1549609507722461041[137] = 0.0;
   out_1549609507722461041[138] = 0.0;
   out_1549609507722461041[139] = 0.0;
   out_1549609507722461041[140] = 0.0;
   out_1549609507722461041[141] = 0.0;
   out_1549609507722461041[142] = 0.0;
   out_1549609507722461041[143] = 0.0;
   out_1549609507722461041[144] = 0.0;
   out_1549609507722461041[145] = 0.0;
   out_1549609507722461041[146] = 0.0;
   out_1549609507722461041[147] = 0.0;
   out_1549609507722461041[148] = 0.0;
   out_1549609507722461041[149] = 0.0;
   out_1549609507722461041[150] = 0.0;
   out_1549609507722461041[151] = 0.0;
   out_1549609507722461041[152] = 1.0;
   out_1549609507722461041[153] = 0.0;
   out_1549609507722461041[154] = 0.0;
   out_1549609507722461041[155] = 0.0;
   out_1549609507722461041[156] = 0.0;
   out_1549609507722461041[157] = 0.0;
   out_1549609507722461041[158] = 0.0;
   out_1549609507722461041[159] = 0.0;
   out_1549609507722461041[160] = 0.0;
   out_1549609507722461041[161] = 0.0;
   out_1549609507722461041[162] = 0.0;
   out_1549609507722461041[163] = 0.0;
   out_1549609507722461041[164] = 0.0;
   out_1549609507722461041[165] = 0.0;
   out_1549609507722461041[166] = 0.0;
   out_1549609507722461041[167] = 0.0;
   out_1549609507722461041[168] = 0.0;
   out_1549609507722461041[169] = 0.0;
   out_1549609507722461041[170] = 0.0;
   out_1549609507722461041[171] = 1.0;
   out_1549609507722461041[172] = 0.0;
   out_1549609507722461041[173] = 0.0;
   out_1549609507722461041[174] = 0.0;
   out_1549609507722461041[175] = 0.0;
   out_1549609507722461041[176] = 0.0;
   out_1549609507722461041[177] = 0.0;
   out_1549609507722461041[178] = 0.0;
   out_1549609507722461041[179] = 0.0;
   out_1549609507722461041[180] = 0.0;
   out_1549609507722461041[181] = 0.0;
   out_1549609507722461041[182] = 0.0;
   out_1549609507722461041[183] = 0.0;
   out_1549609507722461041[184] = 0.0;
   out_1549609507722461041[185] = 0.0;
   out_1549609507722461041[186] = 0.0;
   out_1549609507722461041[187] = 0.0;
   out_1549609507722461041[188] = 0.0;
   out_1549609507722461041[189] = 0.0;
   out_1549609507722461041[190] = 1.0;
   out_1549609507722461041[191] = 0.0;
   out_1549609507722461041[192] = 0.0;
   out_1549609507722461041[193] = 0.0;
   out_1549609507722461041[194] = 0.0;
   out_1549609507722461041[195] = 0.0;
   out_1549609507722461041[196] = 0.0;
   out_1549609507722461041[197] = 0.0;
   out_1549609507722461041[198] = 0.0;
   out_1549609507722461041[199] = 0.0;
   out_1549609507722461041[200] = 0.0;
   out_1549609507722461041[201] = 0.0;
   out_1549609507722461041[202] = 0.0;
   out_1549609507722461041[203] = 0.0;
   out_1549609507722461041[204] = 0.0;
   out_1549609507722461041[205] = 0.0;
   out_1549609507722461041[206] = 0.0;
   out_1549609507722461041[207] = 0.0;
   out_1549609507722461041[208] = 0.0;
   out_1549609507722461041[209] = 1.0;
   out_1549609507722461041[210] = 0.0;
   out_1549609507722461041[211] = 0.0;
   out_1549609507722461041[212] = 0.0;
   out_1549609507722461041[213] = 0.0;
   out_1549609507722461041[214] = 0.0;
   out_1549609507722461041[215] = 0.0;
   out_1549609507722461041[216] = 0.0;
   out_1549609507722461041[217] = 0.0;
   out_1549609507722461041[218] = 0.0;
   out_1549609507722461041[219] = 0.0;
   out_1549609507722461041[220] = 0.0;
   out_1549609507722461041[221] = 0.0;
   out_1549609507722461041[222] = 0.0;
   out_1549609507722461041[223] = 0.0;
   out_1549609507722461041[224] = 0.0;
   out_1549609507722461041[225] = 0.0;
   out_1549609507722461041[226] = 0.0;
   out_1549609507722461041[227] = 0.0;
   out_1549609507722461041[228] = 1.0;
   out_1549609507722461041[229] = 0.0;
   out_1549609507722461041[230] = 0.0;
   out_1549609507722461041[231] = 0.0;
   out_1549609507722461041[232] = 0.0;
   out_1549609507722461041[233] = 0.0;
   out_1549609507722461041[234] = 0.0;
   out_1549609507722461041[235] = 0.0;
   out_1549609507722461041[236] = 0.0;
   out_1549609507722461041[237] = 0.0;
   out_1549609507722461041[238] = 0.0;
   out_1549609507722461041[239] = 0.0;
   out_1549609507722461041[240] = 0.0;
   out_1549609507722461041[241] = 0.0;
   out_1549609507722461041[242] = 0.0;
   out_1549609507722461041[243] = 0.0;
   out_1549609507722461041[244] = 0.0;
   out_1549609507722461041[245] = 0.0;
   out_1549609507722461041[246] = 0.0;
   out_1549609507722461041[247] = 1.0;
   out_1549609507722461041[248] = 0.0;
   out_1549609507722461041[249] = 0.0;
   out_1549609507722461041[250] = 0.0;
   out_1549609507722461041[251] = 0.0;
   out_1549609507722461041[252] = 0.0;
   out_1549609507722461041[253] = 0.0;
   out_1549609507722461041[254] = 0.0;
   out_1549609507722461041[255] = 0.0;
   out_1549609507722461041[256] = 0.0;
   out_1549609507722461041[257] = 0.0;
   out_1549609507722461041[258] = 0.0;
   out_1549609507722461041[259] = 0.0;
   out_1549609507722461041[260] = 0.0;
   out_1549609507722461041[261] = 0.0;
   out_1549609507722461041[262] = 0.0;
   out_1549609507722461041[263] = 0.0;
   out_1549609507722461041[264] = 0.0;
   out_1549609507722461041[265] = 0.0;
   out_1549609507722461041[266] = 1.0;
   out_1549609507722461041[267] = 0.0;
   out_1549609507722461041[268] = 0.0;
   out_1549609507722461041[269] = 0.0;
   out_1549609507722461041[270] = 0.0;
   out_1549609507722461041[271] = 0.0;
   out_1549609507722461041[272] = 0.0;
   out_1549609507722461041[273] = 0.0;
   out_1549609507722461041[274] = 0.0;
   out_1549609507722461041[275] = 0.0;
   out_1549609507722461041[276] = 0.0;
   out_1549609507722461041[277] = 0.0;
   out_1549609507722461041[278] = 0.0;
   out_1549609507722461041[279] = 0.0;
   out_1549609507722461041[280] = 0.0;
   out_1549609507722461041[281] = 0.0;
   out_1549609507722461041[282] = 0.0;
   out_1549609507722461041[283] = 0.0;
   out_1549609507722461041[284] = 0.0;
   out_1549609507722461041[285] = 1.0;
   out_1549609507722461041[286] = 0.0;
   out_1549609507722461041[287] = 0.0;
   out_1549609507722461041[288] = 0.0;
   out_1549609507722461041[289] = 0.0;
   out_1549609507722461041[290] = 0.0;
   out_1549609507722461041[291] = 0.0;
   out_1549609507722461041[292] = 0.0;
   out_1549609507722461041[293] = 0.0;
   out_1549609507722461041[294] = 0.0;
   out_1549609507722461041[295] = 0.0;
   out_1549609507722461041[296] = 0.0;
   out_1549609507722461041[297] = 0.0;
   out_1549609507722461041[298] = 0.0;
   out_1549609507722461041[299] = 0.0;
   out_1549609507722461041[300] = 0.0;
   out_1549609507722461041[301] = 0.0;
   out_1549609507722461041[302] = 0.0;
   out_1549609507722461041[303] = 0.0;
   out_1549609507722461041[304] = 1.0;
   out_1549609507722461041[305] = 0.0;
   out_1549609507722461041[306] = 0.0;
   out_1549609507722461041[307] = 0.0;
   out_1549609507722461041[308] = 0.0;
   out_1549609507722461041[309] = 0.0;
   out_1549609507722461041[310] = 0.0;
   out_1549609507722461041[311] = 0.0;
   out_1549609507722461041[312] = 0.0;
   out_1549609507722461041[313] = 0.0;
   out_1549609507722461041[314] = 0.0;
   out_1549609507722461041[315] = 0.0;
   out_1549609507722461041[316] = 0.0;
   out_1549609507722461041[317] = 0.0;
   out_1549609507722461041[318] = 0.0;
   out_1549609507722461041[319] = 0.0;
   out_1549609507722461041[320] = 0.0;
   out_1549609507722461041[321] = 0.0;
   out_1549609507722461041[322] = 0.0;
   out_1549609507722461041[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_7751906740331149420) {
   out_7751906740331149420[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_7751906740331149420[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_7751906740331149420[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_7751906740331149420[3] = dt*state[12] + state[3];
   out_7751906740331149420[4] = dt*state[13] + state[4];
   out_7751906740331149420[5] = dt*state[14] + state[5];
   out_7751906740331149420[6] = state[6];
   out_7751906740331149420[7] = state[7];
   out_7751906740331149420[8] = state[8];
   out_7751906740331149420[9] = state[9];
   out_7751906740331149420[10] = state[10];
   out_7751906740331149420[11] = state[11];
   out_7751906740331149420[12] = state[12];
   out_7751906740331149420[13] = state[13];
   out_7751906740331149420[14] = state[14];
   out_7751906740331149420[15] = state[15];
   out_7751906740331149420[16] = state[16];
   out_7751906740331149420[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1291423531828480670) {
   out_1291423531828480670[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1291423531828480670[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1291423531828480670[2] = 0;
   out_1291423531828480670[3] = 0;
   out_1291423531828480670[4] = 0;
   out_1291423531828480670[5] = 0;
   out_1291423531828480670[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1291423531828480670[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1291423531828480670[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1291423531828480670[9] = 0;
   out_1291423531828480670[10] = 0;
   out_1291423531828480670[11] = 0;
   out_1291423531828480670[12] = 0;
   out_1291423531828480670[13] = 0;
   out_1291423531828480670[14] = 0;
   out_1291423531828480670[15] = 0;
   out_1291423531828480670[16] = 0;
   out_1291423531828480670[17] = 0;
   out_1291423531828480670[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1291423531828480670[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1291423531828480670[20] = 0;
   out_1291423531828480670[21] = 0;
   out_1291423531828480670[22] = 0;
   out_1291423531828480670[23] = 0;
   out_1291423531828480670[24] = 0;
   out_1291423531828480670[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1291423531828480670[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1291423531828480670[27] = 0;
   out_1291423531828480670[28] = 0;
   out_1291423531828480670[29] = 0;
   out_1291423531828480670[30] = 0;
   out_1291423531828480670[31] = 0;
   out_1291423531828480670[32] = 0;
   out_1291423531828480670[33] = 0;
   out_1291423531828480670[34] = 0;
   out_1291423531828480670[35] = 0;
   out_1291423531828480670[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1291423531828480670[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1291423531828480670[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1291423531828480670[39] = 0;
   out_1291423531828480670[40] = 0;
   out_1291423531828480670[41] = 0;
   out_1291423531828480670[42] = 0;
   out_1291423531828480670[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1291423531828480670[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1291423531828480670[45] = 0;
   out_1291423531828480670[46] = 0;
   out_1291423531828480670[47] = 0;
   out_1291423531828480670[48] = 0;
   out_1291423531828480670[49] = 0;
   out_1291423531828480670[50] = 0;
   out_1291423531828480670[51] = 0;
   out_1291423531828480670[52] = 0;
   out_1291423531828480670[53] = 0;
   out_1291423531828480670[54] = 0;
   out_1291423531828480670[55] = 0;
   out_1291423531828480670[56] = 0;
   out_1291423531828480670[57] = 1;
   out_1291423531828480670[58] = 0;
   out_1291423531828480670[59] = 0;
   out_1291423531828480670[60] = 0;
   out_1291423531828480670[61] = 0;
   out_1291423531828480670[62] = 0;
   out_1291423531828480670[63] = 0;
   out_1291423531828480670[64] = 0;
   out_1291423531828480670[65] = 0;
   out_1291423531828480670[66] = dt;
   out_1291423531828480670[67] = 0;
   out_1291423531828480670[68] = 0;
   out_1291423531828480670[69] = 0;
   out_1291423531828480670[70] = 0;
   out_1291423531828480670[71] = 0;
   out_1291423531828480670[72] = 0;
   out_1291423531828480670[73] = 0;
   out_1291423531828480670[74] = 0;
   out_1291423531828480670[75] = 0;
   out_1291423531828480670[76] = 1;
   out_1291423531828480670[77] = 0;
   out_1291423531828480670[78] = 0;
   out_1291423531828480670[79] = 0;
   out_1291423531828480670[80] = 0;
   out_1291423531828480670[81] = 0;
   out_1291423531828480670[82] = 0;
   out_1291423531828480670[83] = 0;
   out_1291423531828480670[84] = 0;
   out_1291423531828480670[85] = dt;
   out_1291423531828480670[86] = 0;
   out_1291423531828480670[87] = 0;
   out_1291423531828480670[88] = 0;
   out_1291423531828480670[89] = 0;
   out_1291423531828480670[90] = 0;
   out_1291423531828480670[91] = 0;
   out_1291423531828480670[92] = 0;
   out_1291423531828480670[93] = 0;
   out_1291423531828480670[94] = 0;
   out_1291423531828480670[95] = 1;
   out_1291423531828480670[96] = 0;
   out_1291423531828480670[97] = 0;
   out_1291423531828480670[98] = 0;
   out_1291423531828480670[99] = 0;
   out_1291423531828480670[100] = 0;
   out_1291423531828480670[101] = 0;
   out_1291423531828480670[102] = 0;
   out_1291423531828480670[103] = 0;
   out_1291423531828480670[104] = dt;
   out_1291423531828480670[105] = 0;
   out_1291423531828480670[106] = 0;
   out_1291423531828480670[107] = 0;
   out_1291423531828480670[108] = 0;
   out_1291423531828480670[109] = 0;
   out_1291423531828480670[110] = 0;
   out_1291423531828480670[111] = 0;
   out_1291423531828480670[112] = 0;
   out_1291423531828480670[113] = 0;
   out_1291423531828480670[114] = 1;
   out_1291423531828480670[115] = 0;
   out_1291423531828480670[116] = 0;
   out_1291423531828480670[117] = 0;
   out_1291423531828480670[118] = 0;
   out_1291423531828480670[119] = 0;
   out_1291423531828480670[120] = 0;
   out_1291423531828480670[121] = 0;
   out_1291423531828480670[122] = 0;
   out_1291423531828480670[123] = 0;
   out_1291423531828480670[124] = 0;
   out_1291423531828480670[125] = 0;
   out_1291423531828480670[126] = 0;
   out_1291423531828480670[127] = 0;
   out_1291423531828480670[128] = 0;
   out_1291423531828480670[129] = 0;
   out_1291423531828480670[130] = 0;
   out_1291423531828480670[131] = 0;
   out_1291423531828480670[132] = 0;
   out_1291423531828480670[133] = 1;
   out_1291423531828480670[134] = 0;
   out_1291423531828480670[135] = 0;
   out_1291423531828480670[136] = 0;
   out_1291423531828480670[137] = 0;
   out_1291423531828480670[138] = 0;
   out_1291423531828480670[139] = 0;
   out_1291423531828480670[140] = 0;
   out_1291423531828480670[141] = 0;
   out_1291423531828480670[142] = 0;
   out_1291423531828480670[143] = 0;
   out_1291423531828480670[144] = 0;
   out_1291423531828480670[145] = 0;
   out_1291423531828480670[146] = 0;
   out_1291423531828480670[147] = 0;
   out_1291423531828480670[148] = 0;
   out_1291423531828480670[149] = 0;
   out_1291423531828480670[150] = 0;
   out_1291423531828480670[151] = 0;
   out_1291423531828480670[152] = 1;
   out_1291423531828480670[153] = 0;
   out_1291423531828480670[154] = 0;
   out_1291423531828480670[155] = 0;
   out_1291423531828480670[156] = 0;
   out_1291423531828480670[157] = 0;
   out_1291423531828480670[158] = 0;
   out_1291423531828480670[159] = 0;
   out_1291423531828480670[160] = 0;
   out_1291423531828480670[161] = 0;
   out_1291423531828480670[162] = 0;
   out_1291423531828480670[163] = 0;
   out_1291423531828480670[164] = 0;
   out_1291423531828480670[165] = 0;
   out_1291423531828480670[166] = 0;
   out_1291423531828480670[167] = 0;
   out_1291423531828480670[168] = 0;
   out_1291423531828480670[169] = 0;
   out_1291423531828480670[170] = 0;
   out_1291423531828480670[171] = 1;
   out_1291423531828480670[172] = 0;
   out_1291423531828480670[173] = 0;
   out_1291423531828480670[174] = 0;
   out_1291423531828480670[175] = 0;
   out_1291423531828480670[176] = 0;
   out_1291423531828480670[177] = 0;
   out_1291423531828480670[178] = 0;
   out_1291423531828480670[179] = 0;
   out_1291423531828480670[180] = 0;
   out_1291423531828480670[181] = 0;
   out_1291423531828480670[182] = 0;
   out_1291423531828480670[183] = 0;
   out_1291423531828480670[184] = 0;
   out_1291423531828480670[185] = 0;
   out_1291423531828480670[186] = 0;
   out_1291423531828480670[187] = 0;
   out_1291423531828480670[188] = 0;
   out_1291423531828480670[189] = 0;
   out_1291423531828480670[190] = 1;
   out_1291423531828480670[191] = 0;
   out_1291423531828480670[192] = 0;
   out_1291423531828480670[193] = 0;
   out_1291423531828480670[194] = 0;
   out_1291423531828480670[195] = 0;
   out_1291423531828480670[196] = 0;
   out_1291423531828480670[197] = 0;
   out_1291423531828480670[198] = 0;
   out_1291423531828480670[199] = 0;
   out_1291423531828480670[200] = 0;
   out_1291423531828480670[201] = 0;
   out_1291423531828480670[202] = 0;
   out_1291423531828480670[203] = 0;
   out_1291423531828480670[204] = 0;
   out_1291423531828480670[205] = 0;
   out_1291423531828480670[206] = 0;
   out_1291423531828480670[207] = 0;
   out_1291423531828480670[208] = 0;
   out_1291423531828480670[209] = 1;
   out_1291423531828480670[210] = 0;
   out_1291423531828480670[211] = 0;
   out_1291423531828480670[212] = 0;
   out_1291423531828480670[213] = 0;
   out_1291423531828480670[214] = 0;
   out_1291423531828480670[215] = 0;
   out_1291423531828480670[216] = 0;
   out_1291423531828480670[217] = 0;
   out_1291423531828480670[218] = 0;
   out_1291423531828480670[219] = 0;
   out_1291423531828480670[220] = 0;
   out_1291423531828480670[221] = 0;
   out_1291423531828480670[222] = 0;
   out_1291423531828480670[223] = 0;
   out_1291423531828480670[224] = 0;
   out_1291423531828480670[225] = 0;
   out_1291423531828480670[226] = 0;
   out_1291423531828480670[227] = 0;
   out_1291423531828480670[228] = 1;
   out_1291423531828480670[229] = 0;
   out_1291423531828480670[230] = 0;
   out_1291423531828480670[231] = 0;
   out_1291423531828480670[232] = 0;
   out_1291423531828480670[233] = 0;
   out_1291423531828480670[234] = 0;
   out_1291423531828480670[235] = 0;
   out_1291423531828480670[236] = 0;
   out_1291423531828480670[237] = 0;
   out_1291423531828480670[238] = 0;
   out_1291423531828480670[239] = 0;
   out_1291423531828480670[240] = 0;
   out_1291423531828480670[241] = 0;
   out_1291423531828480670[242] = 0;
   out_1291423531828480670[243] = 0;
   out_1291423531828480670[244] = 0;
   out_1291423531828480670[245] = 0;
   out_1291423531828480670[246] = 0;
   out_1291423531828480670[247] = 1;
   out_1291423531828480670[248] = 0;
   out_1291423531828480670[249] = 0;
   out_1291423531828480670[250] = 0;
   out_1291423531828480670[251] = 0;
   out_1291423531828480670[252] = 0;
   out_1291423531828480670[253] = 0;
   out_1291423531828480670[254] = 0;
   out_1291423531828480670[255] = 0;
   out_1291423531828480670[256] = 0;
   out_1291423531828480670[257] = 0;
   out_1291423531828480670[258] = 0;
   out_1291423531828480670[259] = 0;
   out_1291423531828480670[260] = 0;
   out_1291423531828480670[261] = 0;
   out_1291423531828480670[262] = 0;
   out_1291423531828480670[263] = 0;
   out_1291423531828480670[264] = 0;
   out_1291423531828480670[265] = 0;
   out_1291423531828480670[266] = 1;
   out_1291423531828480670[267] = 0;
   out_1291423531828480670[268] = 0;
   out_1291423531828480670[269] = 0;
   out_1291423531828480670[270] = 0;
   out_1291423531828480670[271] = 0;
   out_1291423531828480670[272] = 0;
   out_1291423531828480670[273] = 0;
   out_1291423531828480670[274] = 0;
   out_1291423531828480670[275] = 0;
   out_1291423531828480670[276] = 0;
   out_1291423531828480670[277] = 0;
   out_1291423531828480670[278] = 0;
   out_1291423531828480670[279] = 0;
   out_1291423531828480670[280] = 0;
   out_1291423531828480670[281] = 0;
   out_1291423531828480670[282] = 0;
   out_1291423531828480670[283] = 0;
   out_1291423531828480670[284] = 0;
   out_1291423531828480670[285] = 1;
   out_1291423531828480670[286] = 0;
   out_1291423531828480670[287] = 0;
   out_1291423531828480670[288] = 0;
   out_1291423531828480670[289] = 0;
   out_1291423531828480670[290] = 0;
   out_1291423531828480670[291] = 0;
   out_1291423531828480670[292] = 0;
   out_1291423531828480670[293] = 0;
   out_1291423531828480670[294] = 0;
   out_1291423531828480670[295] = 0;
   out_1291423531828480670[296] = 0;
   out_1291423531828480670[297] = 0;
   out_1291423531828480670[298] = 0;
   out_1291423531828480670[299] = 0;
   out_1291423531828480670[300] = 0;
   out_1291423531828480670[301] = 0;
   out_1291423531828480670[302] = 0;
   out_1291423531828480670[303] = 0;
   out_1291423531828480670[304] = 1;
   out_1291423531828480670[305] = 0;
   out_1291423531828480670[306] = 0;
   out_1291423531828480670[307] = 0;
   out_1291423531828480670[308] = 0;
   out_1291423531828480670[309] = 0;
   out_1291423531828480670[310] = 0;
   out_1291423531828480670[311] = 0;
   out_1291423531828480670[312] = 0;
   out_1291423531828480670[313] = 0;
   out_1291423531828480670[314] = 0;
   out_1291423531828480670[315] = 0;
   out_1291423531828480670[316] = 0;
   out_1291423531828480670[317] = 0;
   out_1291423531828480670[318] = 0;
   out_1291423531828480670[319] = 0;
   out_1291423531828480670[320] = 0;
   out_1291423531828480670[321] = 0;
   out_1291423531828480670[322] = 0;
   out_1291423531828480670[323] = 1;
}
void h_4(double *state, double *unused, double *out_3497511478918473190) {
   out_3497511478918473190[0] = state[6] + state[9];
   out_3497511478918473190[1] = state[7] + state[10];
   out_3497511478918473190[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_2303770509777173648) {
   out_2303770509777173648[0] = 0;
   out_2303770509777173648[1] = 0;
   out_2303770509777173648[2] = 0;
   out_2303770509777173648[3] = 0;
   out_2303770509777173648[4] = 0;
   out_2303770509777173648[5] = 0;
   out_2303770509777173648[6] = 1;
   out_2303770509777173648[7] = 0;
   out_2303770509777173648[8] = 0;
   out_2303770509777173648[9] = 1;
   out_2303770509777173648[10] = 0;
   out_2303770509777173648[11] = 0;
   out_2303770509777173648[12] = 0;
   out_2303770509777173648[13] = 0;
   out_2303770509777173648[14] = 0;
   out_2303770509777173648[15] = 0;
   out_2303770509777173648[16] = 0;
   out_2303770509777173648[17] = 0;
   out_2303770509777173648[18] = 0;
   out_2303770509777173648[19] = 0;
   out_2303770509777173648[20] = 0;
   out_2303770509777173648[21] = 0;
   out_2303770509777173648[22] = 0;
   out_2303770509777173648[23] = 0;
   out_2303770509777173648[24] = 0;
   out_2303770509777173648[25] = 1;
   out_2303770509777173648[26] = 0;
   out_2303770509777173648[27] = 0;
   out_2303770509777173648[28] = 1;
   out_2303770509777173648[29] = 0;
   out_2303770509777173648[30] = 0;
   out_2303770509777173648[31] = 0;
   out_2303770509777173648[32] = 0;
   out_2303770509777173648[33] = 0;
   out_2303770509777173648[34] = 0;
   out_2303770509777173648[35] = 0;
   out_2303770509777173648[36] = 0;
   out_2303770509777173648[37] = 0;
   out_2303770509777173648[38] = 0;
   out_2303770509777173648[39] = 0;
   out_2303770509777173648[40] = 0;
   out_2303770509777173648[41] = 0;
   out_2303770509777173648[42] = 0;
   out_2303770509777173648[43] = 0;
   out_2303770509777173648[44] = 1;
   out_2303770509777173648[45] = 0;
   out_2303770509777173648[46] = 0;
   out_2303770509777173648[47] = 1;
   out_2303770509777173648[48] = 0;
   out_2303770509777173648[49] = 0;
   out_2303770509777173648[50] = 0;
   out_2303770509777173648[51] = 0;
   out_2303770509777173648[52] = 0;
   out_2303770509777173648[53] = 0;
}
void h_10(double *state, double *unused, double *out_7281116020078811927) {
   out_7281116020078811927[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_7281116020078811927[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_7281116020078811927[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_1322697005149897891) {
   out_1322697005149897891[0] = 0;
   out_1322697005149897891[1] = 9.8100000000000005*cos(state[1]);
   out_1322697005149897891[2] = 0;
   out_1322697005149897891[3] = 0;
   out_1322697005149897891[4] = -state[8];
   out_1322697005149897891[5] = state[7];
   out_1322697005149897891[6] = 0;
   out_1322697005149897891[7] = state[5];
   out_1322697005149897891[8] = -state[4];
   out_1322697005149897891[9] = 0;
   out_1322697005149897891[10] = 0;
   out_1322697005149897891[11] = 0;
   out_1322697005149897891[12] = 1;
   out_1322697005149897891[13] = 0;
   out_1322697005149897891[14] = 0;
   out_1322697005149897891[15] = 1;
   out_1322697005149897891[16] = 0;
   out_1322697005149897891[17] = 0;
   out_1322697005149897891[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_1322697005149897891[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_1322697005149897891[20] = 0;
   out_1322697005149897891[21] = state[8];
   out_1322697005149897891[22] = 0;
   out_1322697005149897891[23] = -state[6];
   out_1322697005149897891[24] = -state[5];
   out_1322697005149897891[25] = 0;
   out_1322697005149897891[26] = state[3];
   out_1322697005149897891[27] = 0;
   out_1322697005149897891[28] = 0;
   out_1322697005149897891[29] = 0;
   out_1322697005149897891[30] = 0;
   out_1322697005149897891[31] = 1;
   out_1322697005149897891[32] = 0;
   out_1322697005149897891[33] = 0;
   out_1322697005149897891[34] = 1;
   out_1322697005149897891[35] = 0;
   out_1322697005149897891[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_1322697005149897891[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_1322697005149897891[38] = 0;
   out_1322697005149897891[39] = -state[7];
   out_1322697005149897891[40] = state[6];
   out_1322697005149897891[41] = 0;
   out_1322697005149897891[42] = state[4];
   out_1322697005149897891[43] = -state[3];
   out_1322697005149897891[44] = 0;
   out_1322697005149897891[45] = 0;
   out_1322697005149897891[46] = 0;
   out_1322697005149897891[47] = 0;
   out_1322697005149897891[48] = 0;
   out_1322697005149897891[49] = 0;
   out_1322697005149897891[50] = 1;
   out_1322697005149897891[51] = 0;
   out_1322697005149897891[52] = 0;
   out_1322697005149897891[53] = 1;
}
void h_13(double *state, double *unused, double *out_2057558907181508814) {
   out_2057558907181508814[0] = state[3];
   out_2057558907181508814[1] = state[4];
   out_2057558907181508814[2] = state[5];
}
void H_13(double *state, double *unused, double *out_5516044335109506449) {
   out_5516044335109506449[0] = 0;
   out_5516044335109506449[1] = 0;
   out_5516044335109506449[2] = 0;
   out_5516044335109506449[3] = 1;
   out_5516044335109506449[4] = 0;
   out_5516044335109506449[5] = 0;
   out_5516044335109506449[6] = 0;
   out_5516044335109506449[7] = 0;
   out_5516044335109506449[8] = 0;
   out_5516044335109506449[9] = 0;
   out_5516044335109506449[10] = 0;
   out_5516044335109506449[11] = 0;
   out_5516044335109506449[12] = 0;
   out_5516044335109506449[13] = 0;
   out_5516044335109506449[14] = 0;
   out_5516044335109506449[15] = 0;
   out_5516044335109506449[16] = 0;
   out_5516044335109506449[17] = 0;
   out_5516044335109506449[18] = 0;
   out_5516044335109506449[19] = 0;
   out_5516044335109506449[20] = 0;
   out_5516044335109506449[21] = 0;
   out_5516044335109506449[22] = 1;
   out_5516044335109506449[23] = 0;
   out_5516044335109506449[24] = 0;
   out_5516044335109506449[25] = 0;
   out_5516044335109506449[26] = 0;
   out_5516044335109506449[27] = 0;
   out_5516044335109506449[28] = 0;
   out_5516044335109506449[29] = 0;
   out_5516044335109506449[30] = 0;
   out_5516044335109506449[31] = 0;
   out_5516044335109506449[32] = 0;
   out_5516044335109506449[33] = 0;
   out_5516044335109506449[34] = 0;
   out_5516044335109506449[35] = 0;
   out_5516044335109506449[36] = 0;
   out_5516044335109506449[37] = 0;
   out_5516044335109506449[38] = 0;
   out_5516044335109506449[39] = 0;
   out_5516044335109506449[40] = 0;
   out_5516044335109506449[41] = 1;
   out_5516044335109506449[42] = 0;
   out_5516044335109506449[43] = 0;
   out_5516044335109506449[44] = 0;
   out_5516044335109506449[45] = 0;
   out_5516044335109506449[46] = 0;
   out_5516044335109506449[47] = 0;
   out_5516044335109506449[48] = 0;
   out_5516044335109506449[49] = 0;
   out_5516044335109506449[50] = 0;
   out_5516044335109506449[51] = 0;
   out_5516044335109506449[52] = 0;
   out_5516044335109506449[53] = 0;
}
void h_14(double *state, double *unused, double *out_3962130451197114456) {
   out_3962130451197114456[0] = state[6];
   out_3962130451197114456[1] = state[7];
   out_3962130451197114456[2] = state[8];
}
void H_14(double *state, double *unused, double *out_6267011366116658177) {
   out_6267011366116658177[0] = 0;
   out_6267011366116658177[1] = 0;
   out_6267011366116658177[2] = 0;
   out_6267011366116658177[3] = 0;
   out_6267011366116658177[4] = 0;
   out_6267011366116658177[5] = 0;
   out_6267011366116658177[6] = 1;
   out_6267011366116658177[7] = 0;
   out_6267011366116658177[8] = 0;
   out_6267011366116658177[9] = 0;
   out_6267011366116658177[10] = 0;
   out_6267011366116658177[11] = 0;
   out_6267011366116658177[12] = 0;
   out_6267011366116658177[13] = 0;
   out_6267011366116658177[14] = 0;
   out_6267011366116658177[15] = 0;
   out_6267011366116658177[16] = 0;
   out_6267011366116658177[17] = 0;
   out_6267011366116658177[18] = 0;
   out_6267011366116658177[19] = 0;
   out_6267011366116658177[20] = 0;
   out_6267011366116658177[21] = 0;
   out_6267011366116658177[22] = 0;
   out_6267011366116658177[23] = 0;
   out_6267011366116658177[24] = 0;
   out_6267011366116658177[25] = 1;
   out_6267011366116658177[26] = 0;
   out_6267011366116658177[27] = 0;
   out_6267011366116658177[28] = 0;
   out_6267011366116658177[29] = 0;
   out_6267011366116658177[30] = 0;
   out_6267011366116658177[31] = 0;
   out_6267011366116658177[32] = 0;
   out_6267011366116658177[33] = 0;
   out_6267011366116658177[34] = 0;
   out_6267011366116658177[35] = 0;
   out_6267011366116658177[36] = 0;
   out_6267011366116658177[37] = 0;
   out_6267011366116658177[38] = 0;
   out_6267011366116658177[39] = 0;
   out_6267011366116658177[40] = 0;
   out_6267011366116658177[41] = 0;
   out_6267011366116658177[42] = 0;
   out_6267011366116658177[43] = 0;
   out_6267011366116658177[44] = 1;
   out_6267011366116658177[45] = 0;
   out_6267011366116658177[46] = 0;
   out_6267011366116658177[47] = 0;
   out_6267011366116658177[48] = 0;
   out_6267011366116658177[49] = 0;
   out_6267011366116658177[50] = 0;
   out_6267011366116658177[51] = 0;
   out_6267011366116658177[52] = 0;
   out_6267011366116658177[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_5401193060823608157) {
  err_fun(nom_x, delta_x, out_5401193060823608157);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6380590775890380336) {
  inv_err_fun(nom_x, true_x, out_6380590775890380336);
}
void pose_H_mod_fun(double *state, double *out_1549609507722461041) {
  H_mod_fun(state, out_1549609507722461041);
}
void pose_f_fun(double *state, double dt, double *out_7751906740331149420) {
  f_fun(state,  dt, out_7751906740331149420);
}
void pose_F_fun(double *state, double dt, double *out_1291423531828480670) {
  F_fun(state,  dt, out_1291423531828480670);
}
void pose_h_4(double *state, double *unused, double *out_3497511478918473190) {
  h_4(state, unused, out_3497511478918473190);
}
void pose_H_4(double *state, double *unused, double *out_2303770509777173648) {
  H_4(state, unused, out_2303770509777173648);
}
void pose_h_10(double *state, double *unused, double *out_7281116020078811927) {
  h_10(state, unused, out_7281116020078811927);
}
void pose_H_10(double *state, double *unused, double *out_1322697005149897891) {
  H_10(state, unused, out_1322697005149897891);
}
void pose_h_13(double *state, double *unused, double *out_2057558907181508814) {
  h_13(state, unused, out_2057558907181508814);
}
void pose_H_13(double *state, double *unused, double *out_5516044335109506449) {
  H_13(state, unused, out_5516044335109506449);
}
void pose_h_14(double *state, double *unused, double *out_3962130451197114456) {
  h_14(state, unused, out_3962130451197114456);
}
void pose_H_14(double *state, double *unused, double *out_6267011366116658177) {
  H_14(state, unused, out_6267011366116658177);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
