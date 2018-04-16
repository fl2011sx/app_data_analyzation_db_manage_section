#ifndef WAITINGTHREAD_H
#define WAITINGTHREAD_H

#include <QThread>

class WaitingThreadDelegate {
public:
    virtual void run() = 0;
    virtual void after_run() {}
};

class WaitingThread : public QThread {
    Q_OBJECT
private:
    WaitingThreadDelegate *delegate;
public:
    WaitingThread(WaitingThreadDelegate *delegate);
    void run();
signals:
    void after_run();
};

#endif // WAITINGTHREAD_H
