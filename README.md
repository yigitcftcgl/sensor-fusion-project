# Sensor Fusion Project

This repository contains data and code for the sensor fusion project using GPS NEO-M8N and MPU-6050 sensors to model driver behavior during various driving conditions, including sudden braking and normal acceleration.

## Project Description

In this project, I conducted a braking test on a bus and collected data using Arduino connected to GPS NEO-M8N and MPU-6050 sensors. The goal is to perform sensor fusion using one of the proposed filters (Kalman, Unscented Kalman, Extended Kalman, Particle Filter) and model driver behavior.

## Filter Comparison

### Kalman Filter
- **Pros:**
  - Computationally efficient.
  - Optimal for linear systems.
- **Cons:**
  - Assumes linearity.
  - Not suitable for non-linear systems.

### Extended Kalman Filter (EKF)
- **Pros:**
  - Handles non-linear systems better than Kalman Filter.
- **Cons:**
  - Linearizes non-linear systems, which can introduce errors.
  - Requires Jacobian matrices.

### Unscented Kalman Filter (UKF)
- **Pros:**
  - Better handles non-linear systems without linearization.
  - Uses a set of points to capture mean and covariance estimates.
- **Cons:**
  - More computationally intensive than EKF.
  - More complex implementation.

### Particle Filter
- **Pros:**
  - Suitable for highly non-linear and non-Gaussian systems.
  - Can approximate any distribution.
- **Cons:**
  - Computationally very expensive.
  - Requires a large number of particles for accuracy.

### Chosen Filter: Unscented Kalman Filter (UKF)
- **Reason for Choosing UKF:**
  - UKF was chosen due to its superior handling of non-linearities without the need for linearization, making it more accurate for our sensor fusion needs. Although it is more computationally intensive than EKF, its accuracy and robustness justify its use in this project.

## Files and Data

- **Raw Data:**
  - `CoolTerm Capture (Untitled_0.stc) 2024-05-03 14-00-24-140.txt`: Raw sensor data captured during the test.
  
- **Processed Data:**
  - `fused_sensor_data.csv`: Fused sensor data.
  - `processed_data.csv`: Processed sensor data.
  - `processed_data_cleaned.csv`: Cleaned processed data.
  - `processed_data_complete.csv`: Complete processed data.
  - `processed_data_with_timestamps.csv`: Processed data with timestamps.
  - `processed_data_with_timestamps_test.csv`: Test data with timestamps.

- **Notebooks:**
  - `Untitled.ipynb`: Initial data analysis notebook.
  - `Untitled2.ipynb`: Further data analysis notebook.

## How to Use

1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/yourusername/sensor-fusion-project.git
