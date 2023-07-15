#include "fake_sink.h"
//#include

#include <QDebug>

FakeSink::FakeSink()
{

}

void FakeSink::Send(const AbstractMessage message) const
{
    qDebug() << message.FormPackage();
}
