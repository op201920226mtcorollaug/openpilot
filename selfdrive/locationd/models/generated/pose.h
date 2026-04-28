#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_5401193060823608157);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6380590775890380336);
void pose_H_mod_fun(double *state, double *out_1549609507722461041);
void pose_f_fun(double *state, double dt, double *out_7751906740331149420);
void pose_F_fun(double *state, double dt, double *out_1291423531828480670);
void pose_h_4(double *state, double *unused, double *out_3497511478918473190);
void pose_H_4(double *state, double *unused, double *out_2303770509777173648);
void pose_h_10(double *state, double *unused, double *out_7281116020078811927);
void pose_H_10(double *state, double *unused, double *out_1322697005149897891);
void pose_h_13(double *state, double *unused, double *out_2057558907181508814);
void pose_H_13(double *state, double *unused, double *out_5516044335109506449);
void pose_h_14(double *state, double *unused, double *out_3962130451197114456);
void pose_H_14(double *state, double *unused, double *out_6267011366116658177);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}