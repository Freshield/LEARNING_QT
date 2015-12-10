/****************************************************************************
** Meta object code from reading C++ file 'dialogsrv.h'
**
** Created: Fri Dec 4 18:55:41 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestSrv/dialogsrv.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogsrv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogSrv[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      41,   10,   10,   10, 0x08,
      72,   59,   10,   10, 0x08,
      97,   10,   10,   10, 0x08,
     125,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DialogSrv[] = {
    "DialogSrv\0\0on_pushButtonListen_clicked()\0"
    "onNewConnection()\0strIPAndPort\0"
    "DeleteOneClient(QString)\0"
    "on_pushButtonStop_clicked()\0"
    "on_pushButtonSend_clicked()\0"
};

const QMetaObject DialogSrv::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogSrv,
      qt_meta_data_DialogSrv, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogSrv::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogSrv::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogSrv::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogSrv))
        return static_cast<void*>(const_cast< DialogSrv*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogSrv::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButtonListen_clicked(); break;
        case 1: onNewConnection(); break;
        case 2: DeleteOneClient((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: on_pushButtonStop_clicked(); break;
        case 4: on_pushButtonSend_clicked(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
