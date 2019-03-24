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
    connect(_worker, SIGNAL (error(QString)), this, SLOT (errorString(QString)));
    connect(_thread, SIGNAL (started()), _worker, SLOT (process()));
    connect(_worker, SIGNAL (finished()), _thread, SLOT (quit()));
    connect(_worker, SIGNAL (finished()), _worker, SLOT (deleteLater()));
    connect(_thread, SIGNAL (finished()), _thread, SLOT (deleteLater()));
    connect(_worker, SIGNAL (finished()), this, SLOT ( endCount()));
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
    return  _worker->count();
}

void Runner::endCount()
{
    _count = _worker->count();
}
