//==============================================================================
/**
 * @file       Fixed_Array.h
 *
 * Basic implementation of a fixed size array template class of typename T.
 * Essentially the same as Base_Array, but with updated name so there is a clear
 * distinction when using a fixed array and a resisable one in the same file.
 */
//==============================================================================

#ifndef _FIXED_ARRAY_H_
#define _FIXED_ARRAY_H_

#include "Array.h"

template <typename T, size_t N>
class Fixed_Array : public Base_Array<T>
{
public:
    /// Default constructor.
    Fixed_Array(void);

    /**
     * Copy constructor.
     *
     * @param[in]      arr        Source array
     */
    Fixed_Array(const Fixed_Array<T, N> &arr);

    /**
     * Initializing constructor. Fills the contents of the
     * array with the specified \a fill value.
     *
     * @param[in]      fill       The file value.
     */
    Fixed_Array(T fill);

    /// Destructor.
    ~Fixed_Array(void);
};

// include the source file since template class
#include "Fixed_Array.cpp"

#endif // defined _FIXED_ARRAY_H_