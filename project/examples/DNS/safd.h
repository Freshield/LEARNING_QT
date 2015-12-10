#ifndef SAFD_H
#define SAFD_H

#include <QThread>

class safd : public QThread
{
    Q_OBJECT
public:
    explicit safd(QObject *parent = 0);

signals:

public slots:

};

#endif // SAFD_H
