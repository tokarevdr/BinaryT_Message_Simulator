#include "fake_sink.h"

#include <QDebug>

FakeSink::FakeSink()
{

}

void FakeSink::send(const QByteArray &payload)
{
    qDebug() << QString(payload);
}

bool FakeSink::open()
{
    qDebug() << "Device is open!";
    return true;
}

void FakeSink::close()
{
    qDebug() << "Device is close!";
}
