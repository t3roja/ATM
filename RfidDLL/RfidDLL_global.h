#ifndef RFIDDLL_GLOBAL_H
#define RFIDDLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RFIDDLL_LIBRARY)
#define RFIDDLL_EXPORT Q_DECL_EXPORT
#else
#define RFIDDLL_EXPORT Q_DECL_IMPORT
#endif

#endif // RFIDDLL_GLOBAL_H
