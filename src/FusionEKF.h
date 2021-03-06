#ifndef FusionEKF_H_
#define FusionEKF_H_

#include "measurement_package.h"
#include "Eigen/Dense"
#include <vector>
#include <string>
#include <fstream>
#include "kalman_filter.h"
#include "tools.h"

class FusionEKF {
public:
    /**
    * Constructor.
    */
    FusionEKF();

    /**
    * Destructor.
    */
    virtual ~FusionEKF();

    /**
    * Run the whole flow of the Kalman Filter from here.
    */
    void ProcessMeasurement(const MeasurementPackage &measurement_pack);

    /**
    * Kalman Filter update and prediction math lives in here.
    */
    KalmanFilter ekf_;
    
    
private:
    // check whether the tracking toolbox was initialized or not (first measurement)
    bool is_initialized_;

    // previous timestamp
    long long previous_timestamp_;
        
    //To conveniently invoke helper functions (Jacobian, RMSE etc.)
    Tools tools;

    //acceleration noise components
    const float noise_ax_ = 9;
    const float noise_ay_ = 9;
    
};

#endif /* FusionEKF_H_ */
