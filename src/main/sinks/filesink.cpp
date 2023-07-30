#include "filesink.h"

FileSink::FileSink(const QString &namepath)
{
    file_.setFileName(namepath);
    out_.setDevice(&file_);
}

void FileSink::send(const QByteArray &payload)
{
    if (!open_)
        return;

    out_ << payload << "\r\n";
}

bool FileSink::open()
{
    open_ = file_.open(QIODevice::WriteOnly);

    return open_;
}

void FileSink::close()
{
    open_ = false;

    file_.close();
}
