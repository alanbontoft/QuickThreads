#ifndef RUNNER_H
#define RUNNER_H

#include <QObject>
#include <QThread>
#include "worker.h"

class Runner : public QObject
{
    Q_OBJECT

     Q_PROPERTY(int count READ count WRITE setCount NOTIFY onCount)
public:
    explicit Runner(QObject *parent = nullptr);
    ~Runner();

Q_SIGNALS:
    void onCount(int i);

public slots:
    void start(int i);
    void resume();
    void stop();
    int count();
    void setCount(int i);
    void endCount();
    void countChanged(int newcount);
    void onError(QString error);

private:
    Worker *_worker;
    QThread *_thread;
    int _count;
    QString _error;
};



#endif // RUNNER_H
