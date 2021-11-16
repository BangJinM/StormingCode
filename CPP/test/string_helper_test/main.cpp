
#include "StringHelper.h"

int main(int argc, char const *argv[])
{
    std::wstring              str = Utils::StringHelper::AToU("我是中国人啊");
    std::vector<std::wstring> list;
    Utils::StringHelper::SplitStringW(L"我是中国人啊|dafasd|dfcxxxx|daw2", L"|", list);
    return 0;
}
