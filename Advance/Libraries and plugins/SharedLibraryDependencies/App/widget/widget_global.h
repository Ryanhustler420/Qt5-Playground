#ifndef WIDGET_GLOBAL_H
#define WIDGET_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(WIDGET_LIBRARY)
#  define WIDGET_EXPORT Q_DECL_EXPORT
#else
#  define WIDGET_EXPORT Q_DECL_IMPORT
#endif

#endif // WIDGET_GLOBAL_H
