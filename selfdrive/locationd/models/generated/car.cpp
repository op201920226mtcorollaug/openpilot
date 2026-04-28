#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_5581358830196356020) {
   out_5581358830196356020[0] = delta_x[0] + nom_x[0];
   out_5581358830196356020[1] = delta_x[1] + nom_x[1];
   out_5581358830196356020[2] = delta_x[2] + nom_x[2];
   out_5581358830196356020[3] = delta_x[3] + nom_x[3];
   out_5581358830196356020[4] = delta_x[4] + nom_x[4];
   out_5581358830196356020[5] = delta_x[5] + nom_x[5];
   out_5581358830196356020[6] = delta_x[6] + nom_x[6];
   out_5581358830196356020[7] = delta_x[7] + nom_x[7];
   out_5581358830196356020[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_9184004160235458437) {
   out_9184004160235458437[0] = -nom_x[0] + true_x[0];
   out_9184004160235458437[1] = -nom_x[1] + true_x[1];
   out_9184004160235458437[2] = -nom_x[2] + true_x[2];
   out_9184004160235458437[3] = -nom_x[3] + true_x[3];
   out_9184004160235458437[4] = -nom_x[4] + true_x[4];
   out_9184004160235458437[5] = -nom_x[5] + true_x[5];
   out_9184004160235458437[6] = -nom_x[6] + true_x[6];
   out_9184004160235458437[7] = -nom_x[7] + true_x[7];
   out_9184004160235458437[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_342805382644012341) {
   out_342805382644012341[0] = 1.0;
   out_342805382644012341[1] = 0.0;
   out_342805382644012341[2] = 0.0;
   out_342805382644012341[3] = 0.0;
   out_342805382644012341[4] = 0.0;
   out_342805382644012341[5] = 0.0;
   out_342805382644012341[6] = 0.0;
   out_342805382644012341[7] = 0.0;
   out_342805382644012341[8] = 0.0;
   out_342805382644012341[9] = 0.0;
   out_342805382644012341[10] = 1.0;
   out_342805382644012341[11] = 0.0;
   out_342805382644012341[12] = 0.0;
   out_342805382644012341[13] = 0.0;
   out_342805382644012341[14] = 0.0;
   out_342805382644012341[15] = 0.0;
   out_342805382644012341[16] = 0.0;
   out_342805382644012341[17] = 0.0;
   out_342805382644012341[18] = 0.0;
   out_342805382644012341[19] = 0.0;
   out_342805382644012341[20] = 1.0;
   out_342805382644012341[21] = 0.0;
   out_342805382644012341[22] = 0.0;
   out_342805382644012341[23] = 0.0;
   out_342805382644012341[24] = 0.0;
   out_342805382644012341[25] = 0.0;
   out_342805382644012341[26] = 0.0;
   out_342805382644012341[27] = 0.0;
   out_342805382644012341[28] = 0.0;
   out_342805382644012341[29] = 0.0;
   out_342805382644012341[30] = 1.0;
   out_342805382644012341[31] = 0.0;
   out_342805382644012341[32] = 0.0;
   out_342805382644012341[33] = 0.0;
   out_342805382644012341[34] = 0.0;
   out_342805382644012341[35] = 0.0;
   out_342805382644012341[36] = 0.0;
   out_342805382644012341[37] = 0.0;
   out_342805382644012341[38] = 0.0;
   out_342805382644012341[39] = 0.0;
   out_342805382644012341[40] = 1.0;
   out_342805382644012341[41] = 0.0;
   out_342805382644012341[42] = 0.0;
   out_342805382644012341[43] = 0.0;
   out_342805382644012341[44] = 0.0;
   out_342805382644012341[45] = 0.0;
   out_342805382644012341[46] = 0.0;
   out_342805382644012341[47] = 0.0;
   out_342805382644012341[48] = 0.0;
   out_342805382644012341[49] = 0.0;
   out_342805382644012341[50] = 1.0;
   out_342805382644012341[51] = 0.0;
   out_342805382644012341[52] = 0.0;
   out_342805382644012341[53] = 0.0;
   out_342805382644012341[54] = 0.0;
   out_342805382644012341[55] = 0.0;
   out_342805382644012341[56] = 0.0;
   out_342805382644012341[57] = 0.0;
   out_342805382644012341[58] = 0.0;
   out_342805382644012341[59] = 0.0;
   out_342805382644012341[60] = 1.0;
   out_342805382644012341[61] = 0.0;
   out_342805382644012341[62] = 0.0;
   out_342805382644012341[63] = 0.0;
   out_342805382644012341[64] = 0.0;
   out_342805382644012341[65] = 0.0;
   out_342805382644012341[66] = 0.0;
   out_342805382644012341[67] = 0.0;
   out_342805382644012341[68] = 0.0;
   out_342805382644012341[69] = 0.0;
   out_342805382644012341[70] = 1.0;
   out_342805382644012341[71] = 0.0;
   out_342805382644012341[72] = 0.0;
   out_342805382644012341[73] = 0.0;
   out_342805382644012341[74] = 0.0;
   out_342805382644012341[75] = 0.0;
   out_342805382644012341[76] = 0.0;
   out_342805382644012341[77] = 0.0;
   out_342805382644012341[78] = 0.0;
   out_342805382644012341[79] = 0.0;
   out_342805382644012341[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_6135685919628686024) {
   out_6135685919628686024[0] = state[0];
   out_6135685919628686024[1] = state[1];
   out_6135685919628686024[2] = state[2];
   out_6135685919628686024[3] = state[3];
   out_6135685919628686024[4] = state[4];
   out_6135685919628686024[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_6135685919628686024[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_6135685919628686024[7] = state[7];
   out_6135685919628686024[8] = state[8];
}
void F_fun(double *state, double dt, double *out_360076128843478336) {
   out_360076128843478336[0] = 1;
   out_360076128843478336[1] = 0;
   out_360076128843478336[2] = 0;
   out_360076128843478336[3] = 0;
   out_360076128843478336[4] = 0;
   out_360076128843478336[5] = 0;
   out_360076128843478336[6] = 0;
   out_360076128843478336[7] = 0;
   out_360076128843478336[8] = 0;
   out_360076128843478336[9] = 0;
   out_360076128843478336[10] = 1;
   out_360076128843478336[11] = 0;
   out_360076128843478336[12] = 0;
   out_360076128843478336[13] = 0;
   out_360076128843478336[14] = 0;
   out_360076128843478336[15] = 0;
   out_360076128843478336[16] = 0;
   out_360076128843478336[17] = 0;
   out_360076128843478336[18] = 0;
   out_360076128843478336[19] = 0;
   out_360076128843478336[20] = 1;
   out_360076128843478336[21] = 0;
   out_360076128843478336[22] = 0;
   out_360076128843478336[23] = 0;
   out_360076128843478336[24] = 0;
   out_360076128843478336[25] = 0;
   out_360076128843478336[26] = 0;
   out_360076128843478336[27] = 0;
   out_360076128843478336[28] = 0;
   out_360076128843478336[29] = 0;
   out_360076128843478336[30] = 1;
   out_360076128843478336[31] = 0;
   out_360076128843478336[32] = 0;
   out_360076128843478336[33] = 0;
   out_360076128843478336[34] = 0;
   out_360076128843478336[35] = 0;
   out_360076128843478336[36] = 0;
   out_360076128843478336[37] = 0;
   out_360076128843478336[38] = 0;
   out_360076128843478336[39] = 0;
   out_360076128843478336[40] = 1;
   out_360076128843478336[41] = 0;
   out_360076128843478336[42] = 0;
   out_360076128843478336[43] = 0;
   out_360076128843478336[44] = 0;
   out_360076128843478336[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_360076128843478336[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_360076128843478336[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_360076128843478336[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_360076128843478336[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_360076128843478336[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_360076128843478336[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_360076128843478336[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_360076128843478336[53] = -9.8100000000000005*dt;
   out_360076128843478336[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_360076128843478336[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_360076128843478336[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_360076128843478336[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_360076128843478336[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_360076128843478336[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_360076128843478336[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_360076128843478336[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_360076128843478336[62] = 0;
   out_360076128843478336[63] = 0;
   out_360076128843478336[64] = 0;
   out_360076128843478336[65] = 0;
   out_360076128843478336[66] = 0;
   out_360076128843478336[67] = 0;
   out_360076128843478336[68] = 0;
   out_360076128843478336[69] = 0;
   out_360076128843478336[70] = 1;
   out_360076128843478336[71] = 0;
   out_360076128843478336[72] = 0;
   out_360076128843478336[73] = 0;
   out_360076128843478336[74] = 0;
   out_360076128843478336[75] = 0;
   out_360076128843478336[76] = 0;
   out_360076128843478336[77] = 0;
   out_360076128843478336[78] = 0;
   out_360076128843478336[79] = 0;
   out_360076128843478336[80] = 1;
}
void h_25(double *state, double *unused, double *out_7526111653416130910) {
   out_7526111653416130910[0] = state[6];
}
void H_25(double *state, double *unused, double *out_8910750465153302038) {
   out_8910750465153302038[0] = 0;
   out_8910750465153302038[1] = 0;
   out_8910750465153302038[2] = 0;
   out_8910750465153302038[3] = 0;
   out_8910750465153302038[4] = 0;
   out_8910750465153302038[5] = 0;
   out_8910750465153302038[6] = 1;
   out_8910750465153302038[7] = 0;
   out_8910750465153302038[8] = 0;
}
void h_24(double *state, double *unused, double *out_2431006176668596234) {
   out_2431006176668596234[0] = state[4];
   out_2431006176668596234[1] = state[5];
}
void H_24(double *state, double *unused, double *out_307928422487054353) {
   out_307928422487054353[0] = 0;
   out_307928422487054353[1] = 0;
   out_307928422487054353[2] = 0;
   out_307928422487054353[3] = 0;
   out_307928422487054353[4] = 1;
   out_307928422487054353[5] = 0;
   out_307928422487054353[6] = 0;
   out_307928422487054353[7] = 0;
   out_307928422487054353[8] = 0;
   out_307928422487054353[9] = 0;
   out_307928422487054353[10] = 0;
   out_307928422487054353[11] = 0;
   out_307928422487054353[12] = 0;
   out_307928422487054353[13] = 0;
   out_307928422487054353[14] = 1;
   out_307928422487054353[15] = 0;
   out_307928422487054353[16] = 0;
   out_307928422487054353[17] = 0;
}
void h_30(double *state, double *unused, double *out_3888662125162108560) {
   out_3888662125162108560[0] = state[4];
}
void H_30(double *state, double *unused, double *out_4383054135025693840) {
   out_4383054135025693840[0] = 0;
   out_4383054135025693840[1] = 0;
   out_4383054135025693840[2] = 0;
   out_4383054135025693840[3] = 0;
   out_4383054135025693840[4] = 1;
   out_4383054135025693840[5] = 0;
   out_4383054135025693840[6] = 0;
   out_4383054135025693840[7] = 0;
   out_4383054135025693840[8] = 0;
}
void h_26(double *state, double *unused, double *out_8955079643880451283) {
   out_8955079643880451283[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5169247146279245814) {
   out_5169247146279245814[0] = 0;
   out_5169247146279245814[1] = 0;
   out_5169247146279245814[2] = 0;
   out_5169247146279245814[3] = 0;
   out_5169247146279245814[4] = 0;
   out_5169247146279245814[5] = 0;
   out_5169247146279245814[6] = 0;
   out_5169247146279245814[7] = 1;
   out_5169247146279245814[8] = 0;
}
void h_27(double *state, double *unused, double *out_2524438385755285265) {
   out_2524438385755285265[0] = state[3];
}
void H_27(double *state, double *unused, double *out_6606648206209637057) {
   out_6606648206209637057[0] = 0;
   out_6606648206209637057[1] = 0;
   out_6606648206209637057[2] = 0;
   out_6606648206209637057[3] = 1;
   out_6606648206209637057[4] = 0;
   out_6606648206209637057[5] = 0;
   out_6606648206209637057[6] = 0;
   out_6606648206209637057[7] = 0;
   out_6606648206209637057[8] = 0;
}
void h_29(double *state, double *unused, double *out_1113011142498737085) {
   out_1113011142498737085[0] = state[1];
}
void H_29(double *state, double *unused, double *out_4893285479340086024) {
   out_4893285479340086024[0] = 0;
   out_4893285479340086024[1] = 1;
   out_4893285479340086024[2] = 0;
   out_4893285479340086024[3] = 0;
   out_4893285479340086024[4] = 0;
   out_4893285479340086024[5] = 0;
   out_4893285479340086024[6] = 0;
   out_4893285479340086024[7] = 0;
   out_4893285479340086024[8] = 0;
}
void h_28(double *state, double *unused, double *out_1766588240594466455) {
   out_1766588240594466455[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6856915750905412275) {
   out_6856915750905412275[0] = 1;
   out_6856915750905412275[1] = 0;
   out_6856915750905412275[2] = 0;
   out_6856915750905412275[3] = 0;
   out_6856915750905412275[4] = 0;
   out_6856915750905412275[5] = 0;
   out_6856915750905412275[6] = 0;
   out_6856915750905412275[7] = 0;
   out_6856915750905412275[8] = 0;
}
void h_31(double *state, double *unused, double *out_7801305715700636799) {
   out_7801305715700636799[0] = state[8];
}
void H_31(double *state, double *unused, double *out_8941396427030262466) {
   out_8941396427030262466[0] = 0;
   out_8941396427030262466[1] = 0;
   out_8941396427030262466[2] = 0;
   out_8941396427030262466[3] = 0;
   out_8941396427030262466[4] = 0;
   out_8941396427030262466[5] = 0;
   out_8941396427030262466[6] = 0;
   out_8941396427030262466[7] = 0;
   out_8941396427030262466[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_5581358830196356020) {
  err_fun(nom_x, delta_x, out_5581358830196356020);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_9184004160235458437) {
  inv_err_fun(nom_x, true_x, out_9184004160235458437);
}
void car_H_mod_fun(double *state, double *out_342805382644012341) {
  H_mod_fun(state, out_342805382644012341);
}
void car_f_fun(double *state, double dt, double *out_6135685919628686024) {
  f_fun(state,  dt, out_6135685919628686024);
}
void car_F_fun(double *state, double dt, double *out_360076128843478336) {
  F_fun(state,  dt, out_360076128843478336);
}
void car_h_25(double *state, double *unused, double *out_7526111653416130910) {
  h_25(state, unused, out_7526111653416130910);
}
void car_H_25(double *state, double *unused, double *out_8910750465153302038) {
  H_25(state, unused, out_8910750465153302038);
}
void car_h_24(double *state, double *unused, double *out_2431006176668596234) {
  h_24(state, unused, out_2431006176668596234);
}
void car_H_24(double *state, double *unused, double *out_307928422487054353) {
  H_24(state, unused, out_307928422487054353);
}
void car_h_30(double *state, double *unused, double *out_3888662125162108560) {
  h_30(state, unused, out_3888662125162108560);
}
void car_H_30(double *state, double *unused, double *out_4383054135025693840) {
  H_30(state, unused, out_4383054135025693840);
}
void car_h_26(double *state, double *unused, double *out_8955079643880451283) {
  h_26(state, unused, out_8955079643880451283);
}
void car_H_26(double *state, double *unused, double *out_5169247146279245814) {
  H_26(state, unused, out_5169247146279245814);
}
void car_h_27(double *state, double *unused, double *out_2524438385755285265) {
  h_27(state, unused, out_2524438385755285265);
}
void car_H_27(double *state, double *unused, double *out_6606648206209637057) {
  H_27(state, unused, out_6606648206209637057);
}
void car_h_29(double *state, double *unused, double *out_1113011142498737085) {
  h_29(state, unused, out_1113011142498737085);
}
void car_H_29(double *state, double *unused, double *out_4893285479340086024) {
  H_29(state, unused, out_4893285479340086024);
}
void car_h_28(double *state, double *unused, double *out_1766588240594466455) {
  h_28(state, unused, out_1766588240594466455);
}
void car_H_28(double *state, double *unused, double *out_6856915750905412275) {
  H_28(state, unused, out_6856915750905412275);
}
void car_h_31(double *state, double *unused, double *out_7801305715700636799) {
  h_31(state, unused, out_7801305715700636799);
}
void car_H_31(double *state, double *unused, double *out_8941396427030262466) {
  H_31(state, unused, out_8941396427030262466);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
