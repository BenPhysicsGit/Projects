#include <cmath>
#include <iostream>

int N;    // number of space intervals
const int M = 1000;   // number of time intervals
const double L = 1.0; // length of space interval
const double T = 0.01; // length of time interval

// Initialize the wave function at time t = 0;
void initialize(double *wave) {
  for (int i = 0; i < N; i++) {
    double x = i * L / N;
    wave[i] = sin(2 * M_PI * x / L);
  }
}

int main() {
    using namespace std;
    cin >> N;
  double *wave = new double [N]; // wave function at current time;
  double *wave_dt = new double [N];
  // Initialize the wave function
  initialize(wave);
  // solve the wave equation using the finite difference method
  for (int t = 0; t < M; t++) {
    // store the current wave function in the previous array
    for (int i = 0; i < N; i++) {
      wave_dt[i] = wave[i];
    }
    // update the wave function at each space interval
    for (int i = 1; i < N - 1; i++) {
      double d2x =
          (wave_dt[i + 1] - 2 * wave_dt[i] + wave_dt[i - 1]) / (L * L);

        wave[i] = 2 * wave_dt[i] - wave[i] + T * T * d2x;
    }
    // Apply boundary conditions
    wave[0] = 0;
    wave[N - 1] = 0;
  }
    //error check
        for(int b=0; b<N; b++){
        double error = wave[b]-wave_dt[b];
        cout <<"step error = "<< error << endl;}
  // print the final wave function
  for (int i = 0; i < N; i++) {
    cout << wave[i] << endl;
  }
  return 0;
}

