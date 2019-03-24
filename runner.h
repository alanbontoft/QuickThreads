#ifndef RUNNER_H
#define RUNNER_H

#include <QObject>
#include <QThread>
#include "worker.h"

class Runner : public QObject
{
    Q_OBJECT
public:
    explicit Runner(QObject *parent = nullptr);
    ~Runner();

signals:

public slots:
    void start(int i);
    void resume();
    void stop();
    int count();
    void endCount();

private:
    Worker *_worker;
    QThread *_thread;
    int _count;
};



#endif // RUNNER_H
