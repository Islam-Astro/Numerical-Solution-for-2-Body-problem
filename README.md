# Two-Body Problem: Numerical Solutions (Euler & RK2)

This project numerically solves the **two-body problem** using **Euler's method** and the **second-order Runge-Kutta method (RK2, Midpoint method)**. The goal is to compare the accuracy and stability of these numerical integrators in simulating orbital motion.

## Overview
- Implements the **Euler method** (first-order) and **RK2 (Midpoint method)** to solve the equations of motion for a two-body system.
- Outputs position and velocity data over time.
- Visualizes the orbital trajectories using **Mathematica** to compare accuracy.

## Key Features
✅ **C++ Implementation** – Efficient numerical integration of Newtonian gravity equations.  
✅ **CSV Output** – Saves computed trajectories for easy visualization.  
✅ **Mathematica Plots** – Compares the divergence of Euler vs. RK2 solutions.   

## Results & Observations
**Euler's method** exhibits significant numerical errors, causing artificial orbital drift.
**RK2 (Midpoint method)** provides a more stable and accurate trajectory, better preserving orbital shape.

![Euler vs RK2](https://github.com/user-attachments/assets/aea45817-0546-4b4e-b8b2-276dc497a795)
