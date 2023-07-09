#include "fake_sink.h"

#include <QDebug>

sink::FakeSink::FakeSink()
{

}

void sink::FakeSink::Send(std::unique_ptr<AbstractMessage> &message)
{
    qDebug() << message.get()->FormPackage();
}
