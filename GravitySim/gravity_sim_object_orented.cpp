#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const double GRAVITATIONAL_CONSTANT = 6.67430 * pow(10, -11);

class Attractor {
    private:
        double mass;
        double radius;
    public:
        double x;
        double y;
    Attractor(double mass, double radius, double x_position, double y_position) {
        this->mass = mass;
        this->radius = radius;
        this->x = x_position;
        this->y = y_position;
    }

    double gravitationalAccelerationFromPoint(double x_position, double y_position) {
        double x_distance = x_position - this->x;
        double y_distance = y_position - this->y;
        double distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));
        double gravitaional_acceleration = (GRAVITATIONAL_CONSTANT * this->mass) / pow(distance, 2);
        return gravitaional_acceleration;
    }

    std::vector<double> getDirectionVectorFromPoint(double x_position, double y_position) {
        double x_distance = x_position - this->x;
        double y_distance = y_position - this->y;
        double distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));
        std::vector<double> direction_vector = {x_distance / distance, y_distance / distance};
        return direction_vector;
    }

    double getXPosition() {
        return this->x;
    }

    double getYPosition() {
        return this->y;
    }
};

class MovingAttractor : Attractor {
    private:
        double x_velocity;
        double y_velocity;
        double time_passed;
    public: MovingAttractor(double mass, double radius, double x, double y, double x_velocity, double y_velocity) : Attractor(mass, radius, x, y) {
        this->x_velocity = x_velocity;
        this->y_velocity = y_velocity;
    }

    double getXPosition() {
        return this->x;
    }

    double getYPosition() {
        return this->y;
    }

    double getXVelocity() {
        return this->x_velocity;
    }
    
    double getYVelocity() {
        return this->y_velocity;
    }

    std::vector<double> getGravitationalAcceleration(std::vector<MovingAttractor> attractors) {
        std::vector<double> acceleration;

        std::vector<double> x_acceleration;
        std::vector<double> y_acceleration;

        int attractor_count = attractors.size();
        for (int index = 0; index < attractor_count; index++) {
            double x_distance = attractors[index].getXPosition() - this->x;
            double y_distance = attractors[index].getYPosition() - this->y;
            double distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));
            double gravitaional_acceleration = attractors[index].gravitationalAccelerationFromPoint(this->x, this->y);
            x_acceleration.push_back(gravitaional_acceleration * (x_distance / distance));
            y_acceleration.push_back(gravitaional_acceleration * (y_distance / distance));
        }

        double x_acceleration_total = 0;
        double y_acceleration_total = 0;

        for (int index = 0; index < attractor_count; index++) {
            x_acceleration_total += x_acceleration[index];
            y_acceleration_total += y_acceleration[index];
        }

        return acceleration;
    }

    void updateVelocity(double x_acceleration, double y_acceleration, double time) {
        this->x_velocity += x_acceleration * time;
        this->y_velocity += y_acceleration * time;
    }

    void updatePosition(double time) {
        this->x += this->x_velocity * time;
        this->y += this->y_velocity * time;
    }

    void moveTick(double time, std::vector<double> acceleration) {
        updateVelocity(time/2, acceleration.at(0), acceleration.at(1));
        updatePosition(time);
        updateVelocity(time/2, acceleration.at(0), acceleration.at(1));
        this->time_passed += time;
    }
};

void tick(std::vector<Attractor> attractors, std::vector<MovingAttractor> moving_objects, double time) {
    cout << "starting tick" << endl;
        for (int moving_object_index = 0; moving_object_index < moving_objects.size(); moving_object_index++) {
            cout << "starting cycle: " << moving_object_index << endl;
            std::vector<double> acceleration = moving_objects[moving_object_index].getGravitationalAcceleration(moving_objects);
            //cout << acceleration[0] << endl;
            moving_objects[moving_object_index].moveTick(time, acceleration);
            cout << "completeed cycle: " << moving_object_index << endl;
        }
        cout << "completeed tick" << endl;
        return;
}

int main() {
    MovingAttractor attractor1(100, 10, 0, 0, 0, 0);
    MovingAttractor attractor2(10000000, 10, 100, 0, 0, 0);
    MovingAttractor attractor3(10000000, 10, 0, 100, 0, 0);
    MovingAttractor attractor4(10000000, 10, 100, 100, 0, 0);

    std::vector<MovingAttractor> attractors;
    attractors.push_back(attractor1);
    attractors.push_back(attractor2);
    attractors.push_back(attractor3);
    attractors.push_back(attractor4);

    cout << attractors[0].getXPosition() << endl;
    tick({}, attractors, 1);
    //tick({}, attractors, 1);
    cout << attractors[0].getXPosition() << endl;
}
