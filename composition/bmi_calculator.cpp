#include <iostream>

int main() {
    float height, weight, bmi;

    std::cout << "Enter your height (in meters): ";
    std::cin >> height;

    std::cout << "Enter your weight (in kilograms): ";
    std::cin >> weight;

    // Calculate BMI
    bmi = weight / (height * height);

    // Categorize BMI
    if (bmi < 18.5) {
        std::cout << "Your BMI is: " << bmi << " (Underweight)" << std::endl;
    } else if (bmi >= 18.5 && bmi < 24.9) {
        std::cout << "Your BMI is: " << bmi << " (Normal)" << std::endl;
    } else {
        std::cout << "Your BMI is: " << bmi << " (Overweight)" << std::endl;
    }

    return 0;
}
