#ifndef RFIDD_GLOBAL_H
#define RFIDD_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RFIDD_LIBRARY)
#define RFIDD_EXPORT Q_DECL_EXPORT
#else
#define RFIDD_EXPORT Q_DECL_IMPORT
#endif

#endif // RFIDD_GLOBAL_H
