#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_5581358830196356020);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_9184004160235458437);
void car_H_mod_fun(double *state, double *out_342805382644012341);
void car_f_fun(double *state, double dt, double *out_6135685919628686024);
void car_F_fun(double *state, double dt, double *out_360076128843478336);
void car_h_25(double *state, double *unused, double *out_7526111653416130910);
void car_H_25(double *state, double *unused, double *out_8910750465153302038);
void car_h_24(double *state, double *unused, double *out_2431006176668596234);
void car_H_24(double *state, double *unused, double *out_307928422487054353);
void car_h_30(double *state, double *unused, double *out_3888662125162108560);
void car_H_30(double *state, double *unused, double *out_4383054135025693840);
void car_h_26(double *state, double *unused, double *out_8955079643880451283);
void car_H_26(double *state, double *unused, double *out_5169247146279245814);
void car_h_27(double *state, double *unused, double *out_2524438385755285265);
void car_H_27(double *state, double *unused, double *out_6606648206209637057);
void car_h_29(double *state, double *unused, double *out_1113011142498737085);
void car_H_29(double *state, double *unused, double *out_4893285479340086024);
void car_h_28(double *state, double *unused, double *out_1766588240594466455);
void car_H_28(double *state, double *unused, double *out_6856915750905412275);
void car_h_31(double *state, double *unused, double *out_7801305715700636799);
void car_H_31(double *state, double *unused, double *out_8941396427030262466);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}