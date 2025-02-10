#include <iostream>
#include <fstream>
#include <cmath>

// Define the gravitational constant
const double G = 1.0;

// Define the masses of the particles
const double m1 = 1.0;
const double m2 = 1.0;

// Define the initial positions and velocities of the particles
const double x1_0 = 1.0;
const double y1_0 = -1.0;
const double vx1_0 = -0.5;
const double vy1_0 = 0.0;

const double x2_0 = -1.0;
const double y2_0 = 1.0;
const double vx2_0 = 0.5;
const double vy2_0 = 0.0;

// Define the time step and the time interval
const double h = 0.01;
const double t0 = 0.0;
const double tfinal = 300.0;

// Define a function to calculate the distance between two particles
double distance(double x1, double y1, double x2, double y2) {
    return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// Define a function to calculate the acceleration components of a particle
void acceleration(double x1, double y1, double x2, double y2, double &ax, double &ay) {
    const double epsilon = 1e-6;  // To prevent division by zero
    double r = distance(x1, y1, x2, y2) + epsilon;
    double factor = -G * m2 / (r * r * r);
    ax = factor * (x1 - x2);
    ay = factor * (y1 - y2);
}

int main() {
    // Initialize the positions and velocities of the particles
    double x1 = x1_0, y1 = y1_0, vx1 = vx1_0, vy1 = vy1_0;
    double x2 = x2_0, y2 = y2_0, vx2 = vx2_0, vy2 = vy2_0;

    // Open the output file
    std::ofstream outfile("output_euler.csv");
    if (!outfile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    outfile << "t,x1,y1,x2,y2,vx1,vy1,vx2,vy2" << std::endl;

    // Initialize the time and the number of time steps
    double t = t0;
    int nsteps = static_cast<int>((tfinal - t0) / h);

    // Evolve the system in time using Euler's method
    for (int i = 0; i <= nsteps; i++) {
        // Calculate the accelerations
        double ax1, ay1, ax2, ay2;
        acceleration(x1, y1, x2, y2, ax1, ay1);
        acceleration(x2, y2, x1, y1, ax2, ay2);

        // Update the velocities
        vx1 += ax1 * h;
        vy1 += ay1 * h;
        vx2 += ax2 * h;
        vy2 += ay2 * h;

        // Update the positions
        x1 += vx1 * h;
        y1 += vy1 * h;
        x2 += vx2 * h;
        y2 += vy2 * h;

        // Write the output to the file
        outfile << t << "," << x1 << "," << y1 << "," << x2 << "," << y2 << ","
                << vx1 << "," << vy1 << "," << vx2 << "," << vy2 << std::endl;

        // Update the time
        t += h;
    }

    // Close the output file
    outfile.close();
    
    std::cout << "Simulation complete. Data saved to output.csv" << std::endl;
    return 0;
}

