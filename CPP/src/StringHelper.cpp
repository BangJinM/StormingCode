#include "StringHelper.h"

USING_STL_NAMESPACE
BEGIN_UTILS_NAMESPACE std::wstring StringHelper::StrLowerW(const std::wstring &str)
{
    return std::wstring();
}
std::string StringHelper::StrLowerA(const std::string &str)
{
    return std::string();
}

std::wstring StrUpperW(const std::wstring &str)
{
    return std::wstring();
}

std::string StrUpperA(const std::string &str)
{
    return std::string();
}

bool StringHelper::SplitStringW(const std::wstring &strSource, const std::wstring &strFlag, std::vector<std::wstring> &paramList)
{
    if (strSource.empty() || strFlag.empty())
        return false;
    paramList.clear();
    size_t nBeg  = 0;
    size_t nFind = strSource.find(strFlag, nBeg);
    if (nFind == std::wstring::npos)
        paramList.push_back(strSource);
    else
    {
        while (true)
        {
            if (nFind != nBeg)
                paramList.push_back(strSource.substr(nBeg, nFind - nBeg));
            nBeg = nFind + strFlag.size();
            if (nBeg == strSource.size())
                break;
            nFind = strSource.find(strFlag, nBeg);
            if (nFind == std::wstring::npos)
            {
                paramList.push_back(wstring(strSource.begin() + nBeg, strSource.end()));
                break;
            }
        }
    }
    return true;
}

bool StringHelper::SplitStringA(const std::string &strSource, const std::string &strFlag, std::vector<std::string> &paramList)
{
    if (strSource.empty() || strFlag.empty())
        return false;
    paramList.clear();
    size_t nBeg  = 0;
    size_t nFind = strSource.find(strFlag, nBeg);
    if (nFind == std::string::npos)
        paramList.push_back(strSource);
    else
    {
        while (true)
        {
            if (nFind != nBeg)
                paramList.push_back(strSource.substr(nBeg, nFind - nBeg));
            nBeg = nFind + strFlag.size();
            if (nBeg == strSource.size())
                break;
            nFind = strSource.find(strFlag, nBeg);
            if (nFind == std::string::npos)
            {
                paramList.push_back(string(strSource.begin() + nBeg, strSource.end()));
                break;
            }
        }
    }
    return true;
}

END_UTILS_NAMESPACE