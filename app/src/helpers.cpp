#include "helpers.h"

namespace
{

int randomInRange(int start, int end)
{
    return (qrand() % (end + 1 - start)) + start;
}

}

namespace DSSL
{

qreal primaryScreenDpi()
{
    return QApplication::screens().at(0)->logicalDotsPerInch();
}

int Helpers::pointsToPixels(double sizeInPoints, double dpi)
{
    if (dpi == 0)
    {
        dpi = primaryScreenDpi();
    }

    const double pointSizeInPixels = dpi / 72.0;
    return qRound(sizeInPoints * pointSizeInPixels);
}

double Helpers::pixelsToPoints(int sizeInPixels, double dpi)
{
    if (dpi == 0)
    {
        dpi = primaryScreenDpi();
    }

    return static_cast<double>(sizeInPixels) * 72.0 / dpi;
}


QColor Helpers::randomColor()
{
    return QColor(randomInRange(0, 255), randomInRange(0, 255), randomInRange(0, 255));
}

}