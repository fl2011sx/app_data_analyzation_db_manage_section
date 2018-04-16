#include "waitingthread.h"
#include "MainFunctions.hpp"

WaitingThread::WaitingThread(WaitingThreadDelegate *delegate): QThread(nullptr), delegate(delegate)
{
    if (delegate) {
//        connect(this, SIGNAL(finished()), (QObject *)delegate, SLOT(after_run())/*, Qt::BlockingQueuedConnection*/);
    }
}

void WaitingThread::run() {
    if (delegate) {
        delegate -> run();
    }

    emit after_run();
}
