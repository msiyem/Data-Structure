#include <stdio.h>
#include <math.h>

#define H 6.626e-34      // Planck's constant (J·s)
#define C 3e8            // Speed of light (m/s)
#define K_B 1.381e-23    // Boltzmann's constant (J/K)

// Planck's law function
double planck_law(double wavelength, double T) {
    return (2 * H * C * C) / (pow(wavelength, 5) * (exp((H * C) / (wavelength * K_B * T)) - 1));
}

int main() {
    double T = 5000; // Temperature in Kelvin
    double wavelength;
    double intensity;
    FILE *file = fopen("blackbody_data.txt", "w");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Wavelength range from 1 nm to 3000 nm
    for (wavelength = 1e-9; wavelength <= 3000e-9; wavelength += 1e-9) {
        intensity = planck_law(wavelength, T);
        fprintf(file, "%e %e\n", wavelength * 1e9, intensity); // Writing wavelength in nm and intensity to file
    }

    fclose(file);
    printf("Data written to blackbody_data.txt\n");
    return 0;
}
