/***********************************************************************
// OOP244 Workshop 10:
// File	validate.h
// Version 1.0
// Date	Winter of 2023
// Author	Suna Kim
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Data            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
template <typename T>
bool validate(const T& minimum, const T people[], int num, bool validation[])
{
    bool result = true;
    for (int i = 0; i < num; i++)
    {
        if (people[i] <= minimum)
        {
            if(minimum != people[i])
            {
               result = false;
               validation[i] = false;
            }
        }
        else
        {
            validation[i] = true;
        }
    }
    return result;
}