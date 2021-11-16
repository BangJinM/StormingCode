#include "StringHelper.h"

#include <Windows.h>

BEGIN_UTILS_NAMESPACE

std::string StringHelper::UToA(const std::wstring &str)
{
    if (str.empty())
    {
        return "";
    }

    const auto size_needed = WideCharToMultiByte(CP_UTF8, 0, &str.at(0), (int)str.size(), nullptr, 0, nullptr, nullptr);
    if (size_needed <= 0)
    {
        return "";
    }

    std::string result(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, &str.at(0), (int)str.size(), &result.at(0), size_needed, nullptr, nullptr);
    return result;
}

std::wstring StringHelper::AToU(const std::string &str)
{
    if (str.empty())
    {
        return L"";
    }

    const auto size_needed = MultiByteToWideChar(CP_UTF8, 0, &str.at(0), (int)str.size(), nullptr, 0);
    if (size_needed <= 0)
    {
        return L"";
    }

    std::wstring result(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str.at(0), (int)str.size(), &result.at(0), size_needed);
    return result;
}

END_UTILS_NAMESPACE