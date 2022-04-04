#include "river.h"

River::River(QString ID, QString Name, QString Lenght,
             QString FallsIn, QString AnnualRunoff,
             QString CoolArea, QObject *parent): QObject(parent)
{
    id = ID;
    name = Name;
    lenght = Lenght;
    fallsIn = FallsIn;
    annualRunoff = AnnualRunoff;
    coolArea = CoolArea;
}

void River::setId(QString ID)
{
    id = ID;
}
void River::setName(QString Name)
{
    name = Name;
}
void River::setLenght(QString Lenght)
{
    lenght = Lenght;
}
void River::setFallsIn(QString FallsIn)
{
    fallsIn = FallsIn;
}
void River::setAnnualRunoff(QString AnnualRunoff)
{
    annualRunoff = AnnualRunoff;
}
void River::setCoolArea(QString CoolArea)
{
    coolArea = CoolArea;
}

QString River::Id()
{
    return id;
}
QString River::Name()
{
    return name;
}
QString River::Lenght()
{
    return lenght;
}
QString River::FallsIn()
{
    return fallsIn;
}
QString River::AnnualRunoff()
{
    return annualRunoff;
}
QString River::CoolArea()
{
    return coolArea;
}

 River::~River()
{
}
