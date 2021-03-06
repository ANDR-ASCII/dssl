#pragma once

namespace DSSL
{

class Helpers
{
public:
    static int pointsToPixels(double sizeInPoints, double dpi = 0);
    
    static double pixelsToPoints(int sizeInPixels, double dpi = 0);
    
    static QColor randomColor();

    template <typename DestinationType, typename SourceType>
    static DestinationType fast_cast(SourceType* p)
    {
        if constexpr(std::is_pointer<DestinationType>::value)
        {
            DEBUG_ASSERT(dynamic_cast<DestinationType>(p));
            return static_cast<DestinationType>(p);
        }
        else
        {
            static_assert(!"Destination type must be a pointer");
        }
    }

    template <typename DestinationType, typename SourceType>
    static DestinationType fast_cast(SourceType&& p)
    {
        if constexpr(std::is_reference<DestinationType>::value)
        {
    #ifdef QT_DEBUG
            try
            {
                dynamic_cast<DestinationType>(p);
            }
            catch (...)
            {
                DEBUG_ASSERT(!"Actual type differs from DestinationType");
            }
    #endif

            return static_cast<DestinationType>(p);
        }
        else
        {
            static_assert(!"Destination type must be a reference");
        }
    }
};

}