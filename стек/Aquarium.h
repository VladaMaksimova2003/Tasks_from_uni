#include <iostream>
using namespace std;

class Aquarium
{
private:
    double Length;
    double Width;
    double Heigth;
    double LiquidLevel;

public:
    Aquarium();
    Aquarium(double length, double width, double height, double liquid_level);

    double GetLength();
    double GetWidth();
    double GetHeigth();
    double GetLiquidLevel();

    void SetLength(double length);
    void SetWidth(double width);
    void SetHeigth(double heigth);
    void SetLiquidLevel(double liquid_level);

    double CalculateVolume();
    double CalculateLiquidVolume();
    double CalculateFullness();
    void Pour(double liquid_volume);
    void PourOut(double liquid_volume);
    friend ostream& operator<< (ostream& out, Aquarium Aquarium);
    friend istream& operator>> (istream& in, Aquarium& Aquarium);

};
