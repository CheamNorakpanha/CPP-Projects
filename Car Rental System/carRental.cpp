#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct Coordinates {
    double latitude;
    double longitude;
};

struct Car {
    string brand;
    string model;
    double latitude;
    double longitude;
};

double calculateDistance(const Coordinates& coord1, const Coordinates& coord2) {
    const double R = 6371.0;
    double dlat = (coord2.latitude - coord1.latitude) * (M_PI / 180.0);
    double dlon = (coord2.longitude - coord1.longitude) * (M_PI / 180.0);

    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(coord1.latitude * (M_PI / 180.0)) * cos(coord2.latitude * (M_PI / 180.0)) *
               sin(dlon / 2) * sin(dlon / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c;
}

void displayAvailableCars(const Coordinates& userCoord, const vector<Car>& cars, double radius) {
    cout << "Available cars within " << radius << " kilometers:\n";

    for (const Car& car : cars) {
        double distance = calculateDistance(userCoord, {car.latitude, car.longitude});
        if (distance <= radius) {
            cout << "Brand: " << car.brand << ", Model: " << car.model << ", Distance: " << distance << " km\n";
        }
    }
}

int main() {
    ifstream carFile("cars.txt");
    if (!carFile.is_open()) {
        cerr << "Error opening file 'cars.txt'\n";
        return 1;
    }

    vector<Car> cars;
    while (true) {
        Car car;
        carFile >> car.brand;
        if (carFile.eof()) {
            break;
        }
        carFile >> car.model >> car.latitude >> car.longitude;
        cars.push_back(car);
    }

    carFile.close();

    Coordinates userCoord;
    cout << "Enter your current latitude: ";
    cin >> userCoord.latitude;
    cout << "Enter your current longitude: ";
    cin >> userCoord.longitude;

    double searchRadius;
    cout << "Enter the search radius (in kilometers): ";
    cin >> searchRadius;

    displayAvailableCars(userCoord, cars, searchRadius);

    return 0;
}

// Enter your current latitude: 37.7749
// Enter your current longitude: -122.4194
// Enter the search radius (in kilometers): 1000
// Available cars within 1000 kilometers:
// Brand: Toyota, Model: Camry, Distance: 617.563 km