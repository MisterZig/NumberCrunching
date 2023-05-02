#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const double GRAVITATIONAL_CONSTANT = 6.67430;

struct StationaryAttractor {
    double mass;
    double radius;
    double x;
    double y;
};

struct MovingAttractor {
    double mass;
    double x;
    double y;
    double vx;
    double vy;
    double ax;
    double ay;
};

struct MasslessObject {
    double x;
    double y;
    double velocity[2];
    double acceleration[2];
    double ay;
};

MasslessObject objects[100];
MovingAttractor movingAttractors[100];
StationaryAttractor stationaryAttractors[100];
StationaryAttractor sun;

double calcGravitationalAccelerationFromPoint(double x_position, double y_position) {
    for (auto attractor : stationaryAttractors) {
        double x_distance = x_position - attractor.x;
        double y_distance = y_position - attractor.y;
        double distance = std::sqrt(pow(x_distance, 2) + pow(y_distance, 2));
        double gravitaional_acceleration = (GRAVITATIONAL_CONSTANT * attractor.mass) / pow(distance, 2);
    }
}

std::vector<double> calcGravitationalAccelation(MovingAttractor movingAttractor, StationaryAttractor stationaryAttractor) {
    double x_distance = movingAttractor.x - stationaryAttractor.x;
    double y_distance = movingAttractor.y - stationaryAttractor.y;
    double distance = std::sqrt(pow(x_distance, 2) + pow(y_distance, 2));
    double gravitaional_acceleration = (GRAVITATIONAL_CONSTANT * stationaryAttractor.mass) / pow(distance, 2);
    std::vector<double> acceleration;
    acceleration.push_back(gravitaional_acceleration * (x_distance / distance));
    acceleration.push_back(gravitaional_acceleration * (y_distance / distance));
    return acceleration;
} 

bool tick () {
    try {
        // Go through the lists of moving objects and calculate their velocity and accelerations
        for (auto movingAttractor: movingAttractors) {
            // Calculate the acceleration of the object by looking at attractors
            for (auto stationaryAttractor: stationaryAttractors) {
                // Calculate the acceleration of the object
                std::vector<std::vector<double>> acceleration; 
                acceleration.push_back(calcGravitationalAccelation(movingAttractor, stationaryAttractor)); 

            }
            // Calculate the velocity of the object
            // Calculate the position of the object
        }

        return true;
    } catch (exception e) {
        cout << "Error: " << e.what() << endl;
        return false;
    }
}
/*
int main() {

    sun.mass = 1.989e30;
    sun.radius = 6.957e8;
    sun.x = 0;
    sun.y = 0;
    cout << "Sun mass: " << sun.mass;
    return 0;
}*/