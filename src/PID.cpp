#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;

  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  //window_cte = std::vector<int>(window_size);
  window_position = 0;
}

void PID::UpdateError(double cte) {
  // Since p_error updates with cte, it can be used as the previous cte value before updating it
  d_error = p_error - cte;
  // Update integral error using a window of last window_size values
  //i_error += cte;


  if (window_cte.size() < window_size){
    i_error += cte;
    window_cte.push_back(cte);
  }
  else{
    i_error -= window_cte[window_position] + cte;
    window_cte[window_position] = cte;
  }
  window_position = (window_position+1)%window_size;

  p_error = cte;
}

double PID::TotalError() {
  return Kp*p_error + Ki*i_error + Kd*d_error;
}

