#include "worker.h"

Worker::Worker() { // Constructor
    // you could copy data from constructor arguments to internal variables here.
    _count = 1;
}

Worker::~Worker() { // Destructor
    // free resources
}

void Worker::process() { // Process. Start processing data.
    // allocate resources using new here

    _stopFlag = false;

    while(!_stopFlag)
    {
        qDebug() << QString("Count = %1").arg(_count);
        emit newCount(_count);
        _count++;
        QThread::msleep(1000);
    }
    emit finished();
}

void Worker::stop()
{
    _stopFlag = true;
}

int Worker::count() const
{
    return _count;
}

void Worker::setCount(int count)
{
    _count = count;
}
