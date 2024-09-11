/****************************************************************************
** Meta object code from reading C++ file 'topbtngroup.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainWidget/header/topbtngroup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'topbtngroup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TopBtnGroup_t {
    const uint offsetsAndSize[22];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TopBtnGroup_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TopBtnGroup_t qt_meta_stringdata_TopBtnGroup = {
    {
QT_MOC_LITERAL(0, 11), // "TopBtnGroup"
QT_MOC_LITERAL(12, 15), // "open_myFilePage"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 13), // "open_UserPage"
QT_MOC_LITERAL(43, 21), // "open_downloadListPage"
QT_MOC_LITERAL(65, 19), // "open_uploadListPage"
QT_MOC_LITERAL(85, 18), // "open_shareListPage"
QT_MOC_LITERAL(104, 14), // "sig_uploadfile"
QT_MOC_LITERAL(119, 20), // "sig_changedSelectBtn"
QT_MOC_LITERAL(140, 12), // "QToolButton*"
QT_MOC_LITERAL(153, 3) // "btn"

    },
    "TopBtnGroup\0open_myFilePage\0\0open_UserPage\0"
    "open_downloadListPage\0open_uploadListPage\0"
    "open_shareListPage\0sig_uploadfile\0"
    "sig_changedSelectBtn\0QToolButton*\0btn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TopBtnGroup[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,
       3,    0,   57,    2, 0x06,    2 /* Public */,
       4,    0,   58,    2, 0x06,    3 /* Public */,
       5,    0,   59,    2, 0x06,    4 /* Public */,
       6,    0,   60,    2, 0x06,    5 /* Public */,
       7,    0,   61,    2, 0x06,    6 /* Public */,
       8,    1,   62,    2, 0x06,    7 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void TopBtnGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TopBtnGroup *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->open_myFilePage(); break;
        case 1: _t->open_UserPage(); break;
        case 2: _t->open_downloadListPage(); break;
        case 3: _t->open_uploadListPage(); break;
        case 4: _t->open_shareListPage(); break;
        case 5: _t->sig_uploadfile(); break;
        case 6: _t->sig_changedSelectBtn((*reinterpret_cast< std::add_pointer_t<QToolButton*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QToolButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TopBtnGroup::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TopBtnGroup::open_myFilePage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TopBtnGroup::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TopBtnGroup::open_UserPage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TopBtnGroup::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TopBtnGroup::open_downloadListPage)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TopBtnGroup::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TopBtnGroup::open_uploadListPage)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TopBtnGroup::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TopBtnGroup::open_shareListPage)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TopBtnGroup::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TopBtnGroup::sig_uploadfile)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TopBtnGroup::*)(QToolButton * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TopBtnGroup::sig_changedSelectBtn)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject TopBtnGroup::staticMetaObject = { {
    QMetaObject::SuperData::link<MovableWidget::staticMetaObject>(),
    qt_meta_stringdata_TopBtnGroup.offsetsAndSize,
    qt_meta_data_TopBtnGroup,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TopBtnGroup_t
, QtPrivate::TypeAndForceComplete<TopBtnGroup, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QToolButton *, std::false_type>



>,
    nullptr
} };


const QMetaObject *TopBtnGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TopBtnGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TopBtnGroup.stringdata0))
        return static_cast<void*>(this);
    return MovableWidget::qt_metacast(_clname);
}

int TopBtnGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MovableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void TopBtnGroup::open_myFilePage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TopBtnGroup::open_UserPage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TopBtnGroup::open_downloadListPage()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TopBtnGroup::open_uploadListPage()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void TopBtnGroup::open_shareListPage()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void TopBtnGroup::sig_uploadfile()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void TopBtnGroup::sig_changedSelectBtn(QToolButton * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
