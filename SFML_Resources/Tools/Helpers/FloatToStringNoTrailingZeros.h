//
// Created by Brandon Hargitay on 4/28/23.
//

#ifndef DIZZLESTUDIOPRO_FLOATTOSTRINGNOTRAILINGZEROS_H
#define DIZZLESTUDIOPRO_FLOATTOSTRINGNOTRAILINGZEROS_H
#include <string>
#include <sstream>
class FloatToStringNoTrailingZeros{
public:
    static std::string floatToStringNoTrailingZeros(float value) {
        std::stringstream ss;
        ss << value;
        std::string str = ss.str();

        // Remove trailing zeros after the decimal point
        size_t found = str.find('.');
        if (found != std::string::npos) {
            str.erase(str.find_last_not_of('0') + 1, std::string::npos);
        }

        // Remove the trailing decimal point, if any
        if (str.back() == '.') {
            str.pop_back();
        }

        return str;
    }


};
#endif //DIZZLESTUDIOPRO_FLOATTOSTRINGNOTRAILINGZEROS_H
