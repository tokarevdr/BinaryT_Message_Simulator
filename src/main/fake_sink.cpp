#include "fake_sink.h"

#include <QDebug>

sink::FakeSink::FakeSink()
{

}

void sink::FakeSink::Send(std::unique_ptr<message::AbstractMessage> &message)
{
    qDebug() << message.get()->FormPackage();
}
