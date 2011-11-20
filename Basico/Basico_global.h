#ifndef BASICO_GLOBAL_H
#define BASICO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BASICO_LIBRARY)
#  define BASICOSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BASICOSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BASICO_GLOBAL_H
