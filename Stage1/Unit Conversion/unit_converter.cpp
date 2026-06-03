/*
=============================================================
  PROJECT 2 — UNIT CONVERTER
=============================================================

  INPUT VALIDATION (required):
    - Out of range menu     → error message, prompt again

  DONE WHEN:
    - All 3 categories convert correctly
    - Invalid input never crashes the program
    - Logic is split across functions, not dumped in main()
=============================================================
*/

#include <iostream>
#include <functional>
#include <unordered_map>

enum class Category {
    TEMPERATURE,
    DISTANCE,
    MASS
};

enum class TempUnit {
    CELSIUS,
    FAHRENHEIT,
    KELVIN
};

enum class DistUnit {
    METRES,
    KILOMETRES,
    MILES,
    FEET
};

enum class MassUnit {
    KILOGRAMS,
    GRAMS,
    POUNDS,
    OUNCES
};

double convertTemperature(double value, TempUnit from, TempUnit to);
double convertDistance(double value, DistUnit from, DistUnit to);
double convertMass(double value, MassUnit from, MassUnit to);
void   displayMenu();

int main() {
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {

        displayMenu();

        int num = 0;
        while (num < 1 || num > 3) {
            std::cin >> num;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input." << std::endl;
                num = 0;
                continue;
            }
            if (num < 1 || num > 3) {
                num = 0;
                std::cout << "Enter a valid number (1-3).";
            }
        }

        Category selection;
        selection = static_cast<Category>(num-1);

        switch(selection) {
            case Category::TEMPERATURE: {
                TempUnit from;
                TempUnit to;
                int n_f=0;
                int n_t=0;
                while (n_f == 0 || n_t == 0) {
                    std::cout << "Enter Initial units (1. Celsius, 2. Kelvin, 3. Fahrenheit)." << std::endl;
                    std::cin >> n_f;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Invalid input." << std::endl;
                        n_f = 0;
                        continue;
                    }
                    if (n_f < 1 || n_f > 3) {
                        n_f = 0;
                        std::cout << "Enter a valid number (1-3).";
                    }
                    std::cout << "Enter Desired units (1. Celsius, 2. Kelvin, 3. Fahrenheit)." << std::endl;
                    std::cin >> n_t;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Invalid input." << std::endl;
                        n_t = 0;
                        continue;
                    }
                    if (n_t < 1 || n_t > 3) {
                        n_t = 0;
                        std::cout << "Enter a valid number (1-3).";
                    }
                }

                from = static_cast<TempUnit>(n_f - 1);
                to = static_cast<TempUnit>(n_t - 1);

                double value;

                std::cout << "Enter numeral value: (e.g. 20.0)" << std::endl;
                std::cin >> value;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Invalid input." << std::endl;
                    continue;
                }

                double result = convertTemperature(value, from, to);

                std::cout << "Result: " << result << std::endl;

                break;
            }

            case Category::DISTANCE: {
                DistUnit dist_from;
                DistUnit dist_to;
                int n_df=0;
                int n_dt=0;
                while (n_df == 0 || n_dt == 0) {
                    std::cout << "Enter Initial units (1. Metres, 2. Kilometres, 3. Miles, 4. Feet)." << std::endl;
                    std::cin >> n_df;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Invalid input." << std::endl;
                        n_df = 0;
                        continue;
                    }
                    if (n_df < 1 || n_df > 4) {
                        n_df = 0;
                        std::cout << "Enter a valid number (1-4).";
                    }
                    std::cout << "Enter Desired units (1. Metres, 2. Kilometres, 3. Miles, 4. Feet)." << std::endl;
                    std::cin >> n_dt;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Invalid input." << std::endl;
                        n_dt = 0;
                        continue;
                    }
                    if (n_dt < 1 || n_dt > 4) {
                        n_dt = 0;
                        std::cout << "Enter a valid number (1-4).";
                    }
                }


                dist_from = static_cast<DistUnit>(n_df - 1);
                dist_to = static_cast<DistUnit>(n_dt - 1);

                double dist_value;

                std::cout << "Enter numeral value: (e.g. 20.0)" << std::endl;
                std::cin >> dist_value;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Invalid input." << std::endl;
                    continue;
                }

                double dist_result = convertDistance(dist_value, dist_from, dist_to);

                std::cout << "Result: " << dist_result << std::endl;
                break;
            }

            case Category::MASS: {
                MassUnit mass_from;
                MassUnit mass_to;
                int n_mf=0;
                int n_mt=0;
                while (n_mf == 0 || n_mt == 0) {
                    std::cout << "Enter Initial units (1. Kilograms, 2. Grams, 3. Pounds, 4. Ounces)." << std::endl;
                    std::cin >> n_mf;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Invalid input." << std::endl;
                        n_mf = 0;
                        continue;
                    }
                    if (n_mf < 1 || n_mf > 4) {
                        n_mf = 0;
                        std::cout << "Enter a valid number (1-4).";
                    }
                    std::cout << "Enter Desired units (1. Kilograms, 2. Grams, 3. Pounds, 4. Ounces)." << std::endl;
                    std::cin >> n_mt;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Invalid input." << std::endl;
                        n_mt = 0;
                        continue;
                    }
                    if (n_mt < 1 || n_mt > 4) {
                        n_mt = 0;
                        std::cout << "Enter a valid number (1-4).";
                    }
                }

                mass_from = static_cast<MassUnit>(n_mf - 1);
                mass_to = static_cast<MassUnit>(n_mt - 1);

                double mass_value;

                std::cout << "Enter numeral value: (e.g. 20.0)" << std::endl;
                std::cin >> mass_value;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Invalid input." << std::endl;
                    continue;
                }

                double mass_result = convertMass(mass_value, mass_from, mass_to);

                std::cout << "Result: " << mass_result << std::endl;
                break;
            }

        }
        std::cout << "Would you like to convert again? (Y/N)" << std::endl;
        std::cin >> choice;        
    }

    return 0;
}


double convertTemperature(double value, TempUnit from, TempUnit to)
{
    // 1. Convert 'from' to Kelvin
    double temp_kelvin;
    double result;

    switch (from) {
    case TempUnit::KELVIN:
        temp_kelvin = value;
        break;
    case TempUnit::FAHRENHEIT:
        temp_kelvin = (value - 32) / 1.8 + 273.15;
        break;
    case TempUnit::CELSIUS:
        temp_kelvin = value + 273.15;
        break;
    default:
        temp_kelvin = 0.0;
        break;
    }

    // 2. Convert Kelvin to 'to'
    switch (to) {
    case TempUnit::KELVIN:
        result = temp_kelvin;
        break;
    case TempUnit::FAHRENHEIT:
        result = (temp_kelvin - 273.15) * 1.8 + 32;
        break;
    case TempUnit::CELSIUS:
        result = temp_kelvin - 273.15;
        break;
    default:
        result = 0.0;
        break;
    }

    return result;
}

double convertDistance(double value, DistUnit from, DistUnit to)
{
    // 1. Convert 'from' to Metres
    double dist_metres;
    double result;

    switch (from) {
    case DistUnit::METRES:
        dist_metres = value;
        break;
    case DistUnit::KILOMETRES:
        dist_metres = value * 1000.0;
        break;
    case DistUnit::MILES:
        dist_metres = value * 1609.34;
        break;
    case DistUnit::FEET:
        dist_metres = value * 0.3048;
        break;
    default:
        dist_metres = 0.0;
        break;
    }

    // 2. Convert Metres to 'to'
    switch (to) {
    case DistUnit::METRES:
        result = dist_metres;
        break;
    case DistUnit::KILOMETRES:
        result = dist_metres / 1000.0;
        break;
    case DistUnit::MILES:
        result = dist_metres / 1609.34;
        break;
    case DistUnit::FEET:
        result = dist_metres / 0.3048;
        break;
    default:
        result = 0.0;
        break;
    }

    return result;
}

double convertMass(double value, MassUnit from, MassUnit to)
{
    // 1. Convert 'from' to Kilograms
    double mass_kilograms;
    double result;

    switch (from) {
    case MassUnit::KILOGRAMS:
        mass_kilograms = value;
        break;
    case MassUnit::GRAMS:
        mass_kilograms = value / 1000.0;
        break;
    case MassUnit::POUNDS:
        mass_kilograms = value * 0.453592;
        break;
    case MassUnit::OUNCES:
        mass_kilograms = value * 0.0283495;
        break;
    default:
        mass_kilograms = 0.0;
        break;
    }

    // 2. Convert Kilograms to 'to'
    switch (to) {
    case MassUnit::KILOGRAMS:
        result = mass_kilograms;
        break;
    case MassUnit::GRAMS:
        result = mass_kilograms * 1000.0;
        break;
    case MassUnit::POUNDS:
        result = mass_kilograms / 0.453592;
        break;
    case MassUnit::OUNCES:
        result = mass_kilograms / 0.0283495;
        break;
    default:
        result = 0.0;
        break;
    }

    return result;
}

void   displayMenu()
{
    std::cout << "==================================================" << std::endl;
    std::cout << "================== UNIT CONVERTER ================" << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << '\n';
    std::cout << "What kind of values would you like to convert? (1-3)" << std::endl;
    std::cout << "1. Temperature (Celsius, Kelvin, Fahrenheit)" << std::endl;
    std::cout << "2. Distance (Km, m, Miles, Feet)" << std::endl;
    std::cout << "3. Mass (Kg, g, Pounds, Ounces)" << std::endl;
}
