#include "runner.h"

Runner::Runner(QObject *parent) : QObject(parent)
{
    //_thread = new QThread();
    //_worker = new Worker();
}

Runner::~Runner()
{
//    delete _worker;
}

void Runner::start(int i)
{
    _thread = new QThread();
    _worker = new Worker();

    _worker->setCount(i);
    _worker->moveToThread(_thread);
    connect(_worker, SIGNAL (error(QString)), this, SLOT (onError(QString)));
    connect(_thread, SIGNAL (started()), _worker, SLOT (process()));
    connect(_worker, SIGNAL (finished()), _thread, SLOT (quit()));
    connect(_worker, SIGNAL (finished()), _worker, SLOT (deleteLater()));
    connect(_thread, SIGNAL (finished()), _thread, SLOT (deleteLater()));
    connect(_worker, SIGNAL (finished()), this, SLOT ( endCount()));
    connect(_worker, SIGNAL (newCount(int)), this, SLOT (countChanged(int)));
    _thread->start();
}

void Runner::resume()
{
    start(_count);
}

void Runner::stop()
{
    _worker->stop();
}

int Runner::count()
{
    if (_worker != nullptr)
        return  _worker->count();
    else {
        return 0;
    }
}

void Runner::setCount(int i)
{
    // do nothing
}

void Runner::endCount()
{
    _count = _worker->count();
}

void Runner::countChanged(int newcount)
{
    emit onCount(newcount);
}

void Runner::onError(QString error)
{
    _error = error;
}
