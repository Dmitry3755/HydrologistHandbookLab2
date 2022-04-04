#ifndef RIVER_H
#define RIVER_H
#include "QString"
#include <QObject>

class River: public QObject
{
    Q_OBJECT
public:
    River(QString id, QString name, QString lenght,QString fallsIn,
          QString annualRunoff,QString coolArea, QObject *parent = nullptr );
    virtual ~River();

    void setId(QString ID);
    void setName(QString Name);
    void setLenght(QString Lenght);
    void setFallsIn(QString FallsIn);
    void setAnnualRunoff(QString AnnualRunoff);
    void setCoolArea(QString CoolArea);

    QString Id();
    QString Name();
    QString Lenght();
    QString FallsIn();
    QString AnnualRunoff();
    QString CoolArea();
private:
    QString id;
    QString name;
    QString lenght;
    QString fallsIn;
    QString annualRunoff;
    QString coolArea;
};

#endif // RIVER_H
