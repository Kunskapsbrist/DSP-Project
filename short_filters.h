//Short filters

//LOW PASS
#define N_LP_A 11

float a_lp[11] = {1.000000e+00, -3.322109e+00, 6.020131e+00, -7.073701e+00, 5.876516e+00, -3.538153e+00, 1.551121e+00, -4.849789e-01, 1.030105e-01, -1.336116e-02, 8.011624e-04, };

#define N_LP_B 11

float b_lp[11] = {1.164797e-04, 1.164797e-03, 5.241588e-03, 1.397757e-02, 2.446074e-02, 2.935289e-02, 2.446074e-02, 1.397757e-02, 5.241588e-03, 1.164797e-03, 1.164797e-04, };


//BAND PASS
#define N_BP_A 11

float a_bp[11] = {1.000000e+00, 1.242617e-15, 1.644849e+00, 1.843364e-15, 1.586615e+00, 1.154853e-15, 8.048819e-01, 4.161276e-16, 2.299491e-01, 5.409716e-17, 2.725227e-02, };

#define N_BP_B 11

float b_bp[11] = {1.061191e-02, 0.000000e+00, -5.305957e-02, 0.000000e+00, 1.061191e-01, 0.000000e+00, -1.061191e-01, 0.000000e+00, 5.305957e-02, 0.000000e+00, -1.061191e-02, };

//HIGH PASS
#define N_hP_A 11

float a_hp[11] = {1.000000e+00, 3.322109e+00, 6.020131e+00, 7.073701e+00, 5.876516e+00, 3.538153e+00, 1.551121e+00, 4.849789e-01, 1.030105e-01, 1.336116e-02, 8.011624e-04, };

#define N_hP_B 11

float b_hp[11] = {1.164797e-04, -1.164797e-03, 5.241588e-03, -1.397757e-02, 2.446074e-02, -2.935289e-02, 2.446074e-02, -1.397757e-02, 5.241588e-03, -1.164797e-03, 1.164797e-04, };

