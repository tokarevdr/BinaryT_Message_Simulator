#ifndef FILESINK_H
#define FILESINK_H

#include "isink.h"

#include <QFile>
#include <QTextStream>

class FileSink : public ISink
{
public:
    FileSink(const QString &namepath);

    void send(const QByteArray &payload) override;
    bool open() override;
    void close() override;

private:
    QFile file_;
    QTextStream out_;
    bool open_ = false;
};

#endif // FILESINK_H
