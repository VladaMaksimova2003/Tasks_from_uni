#include "Aquarium.h"

ostream& operator<< (ostream& out,Aquarium Aquarium) {

    double Length = Aquarium.GetLength();
    double Width = Aquarium.GetWidth();
    double Heigth = Aquarium.GetHeigth();
    double LiquidLevel = Aquarium.GetLiquidLevel();

    out << Length << ", ";
    out << Width << ", ";
    out << Heigth << ", ";
    out << LiquidLevel;

    return out;
}

istream& operator>> (istream& in, Aquarium& Aquarium)
{
    double Length = Aquarium.GetLength();
    double Width = Aquarium.GetWidth();
    double Heigth = Aquarium.GetHeigth();
    double LiquidLevel = Aquarium.GetLiquidLevel();
    in >> Length;
    in >> Width;
    in >> Heigth;
    in >> LiquidLevel;

    return in;
}
Aquarium::Aquarium()
{
    Length = 5;
    Width = 5;
    Heigth = 5;
    LiquidLevel = 0;
}

Aquarium::Aquarium(double length, double width, double height, double liquid_level)
{
    Length = 5;
    Width = 5;
    Heigth = 5;
    LiquidLevel = 0;

    SetLength(length);
    SetWidth(width);
    SetHeigth(height);
    SetLiquidLevel(liquid_level);
}

double Aquarium::GetLength()
{
    return Length;
}

double Aquarium::GetWidth()
{
    return Width;
}

double Aquarium::GetHeigth()
{
    return Heigth;
}

double Aquarium::GetLiquidLevel()
{
    return LiquidLevel;
}

bool isValueCorrect(double value)
{
    return ((5 <= value) && (value <= 200));
}

void Aquarium::SetLength(double length)
{
    if (isValueCorrect(length))
    {
        Length = length;
    }
}

void Aquarium::SetWidth(double width)
{
    if (isValueCorrect(width))
    {
        Width = width;
    }
}

void Aquarium::SetHeigth(double heigth)
{
    if (isValueCorrect(heigth))
    {
        Heigth = heigth;
    }
}

void Aquarium::SetLiquidLevel(double liquid_level)
{
    if (liquid_level < 0)
    {
        liquid_level = 0;
        return;
    }
    if (liquid_level < Heigth)
    {
        LiquidLevel = liquid_level;
    }
    else
    {
        LiquidLevel = Heigth;
    }
}

double Aquarium::CalculateVolume()
{
    return Length * Width * Heigth / 1000;
}

double Aquarium::CalculateLiquidVolume()
{
    return Length * Width * LiquidLevel / 1000;
}

double Aquarium::CalculateFullness()
{
    return LiquidLevel / Heigth;
}

void Aquarium::Pour(double liquid_volume)
{
    double new_liquid_level = (liquid_volume * 1000 / Length / Width) + LiquidLevel;
    if (Heigth < new_liquid_level)
    {
        SetLiquidLevel(200);
        return;
    }
    SetLiquidLevel(new_liquid_level);
}

void Aquarium::PourOut(double liquid_volume)
{
    double new_liquid_level = LiquidLevel - (liquid_volume * 1000 / Length / Width);
    if (new_liquid_level < 0)
    {
        SetLiquidLevel(0);
        return;
    }
    SetLiquidLevel(new_liquid_level);
}