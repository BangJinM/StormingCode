#pragma once

#include <string>
#include <vector>
#include "Defines.h"

BEGIN_UTILS_NAMESPACE

class StringHelper
{
public:
    // UNICODE 转 ASCII
    static std::string UToA(const std::wstring &str);
    // ASCII 转 UNICODE
    static std::wstring AToU(const std::string &str);

    //字符串转小写
    static std::wstring StrLowerW(const std::wstring &str);
    //字符串转小写
    static std::string StrLowerA(const std::string &str);

    //字符串转大写
    static std::wstring StrUpperW(const std::wstring &str);
    //字符串转大写
    static std::string StrUpperA(const std::string &str);

    //宽字符串分割
    static bool SplitStringW(const std::wstring &strSource, const std::wstring &strFlag, std::vector<std::wstring> &paramList);
    //字符串分割
    static bool SplitStringA(const std::string &strSource, const std::string &strFlag, std::vector<std::string> &paramList);
};

END_UTILS_NAMESPACE