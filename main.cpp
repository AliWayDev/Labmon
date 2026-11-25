#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

bool printMemoryInfo()
{
    std::ifstream file("/proc/meminfo");

    if (!file)
    {
        std::cerr << "Cannot open /proc/meminfo\n";
        return 1;
    }

    std::string line;

    while (std::getline(file, line))
    {
        if (line.starts_with("MemTotal:") ||
            line.starts_with("MemAvailable:"))
        {
            std::istringstream row(line);

            std::string name;
            double valueKiB = 0;

            if (row >> name >> valueKiB)
            {
                double valueGiB = valueKiB / (1024.0 * 1024.0);

                std::cout << name << ' '
                          << std::fixed << std::setprecision(2)
                          << valueGiB << " GiB\n";
            }
        }
    }

    return true;
}

int main()
{
    while (true)
    {
        std::cout << "\x1b[2J\x1b[H"
                  << "LabMon | Ctrl+C to exit\n\n";

        if (!printMemoryInfo())
        {
            return 1;
        }

        std::cout << std::flush;

        std::this_thread::sleep_for(
            std::chrono::seconds(1));
    }
}