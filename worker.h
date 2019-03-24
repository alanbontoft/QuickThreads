#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <QThread>

class Worker : public QObject {
    Q_OBJECT
public:
    Worker();
    ~Worker();
    int count() const;
    void setCount(int count);

public slots:
    void process();
    void stop();
signals:
    void finished();
    void error(QString err);
private:
    // add your variables here
    bool _stopFlag;
    int _count;
};

#endif // WORKER_H
