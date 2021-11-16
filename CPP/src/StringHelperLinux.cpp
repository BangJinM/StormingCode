#include "StringHelper.h"

BEGIN_UTILS_NAMESPACE

std::string StringHelper::UToA(const std::wstring &sToMatch)
{
    int   iLen = wcstombs(NULL, sToMatch.c_str(), 0);  // 计算转换后字符串的长度。（不包含字符串结束符）
    char *lpsz = new char[iLen + 1];
    int   i    = wcstombs(lpsz, sToMatch.c_str(), iLen);  // 转换。（没有结束符）
    lpsz[iLen] = '\0';
    std::string sResult(lpsz);
    delete[] lpsz;
    return sResult;
}

std::wstring StringHelper::AToU(const std::string &sToMatch)
{
    setlocale(LC_CTYPE, "");                                               // 很重要，没有这一句，转换会失败。
    int      iWLen = mbstowcs(NULL, sToMatch.c_str(), sToMatch.length());  // 计算转换后宽字符串的长度。（不包含字符串结束符）
    wchar_t *lpwsz = new wchar_t[iWLen + 1];
    int      i     = mbstowcs(lpwsz, sToMatch.c_str(), sToMatch.length());  // 转换。（转换后的字符串有结束符）
    std::wstring wsToMatch(lpwsz);
    delete[] lpwsz;
    return wsToMatch;
}

END_UTILS_NAMESPACE