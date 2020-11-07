#将lua代码中的中文字符导出到Excel中.Excel表中ID和String,Count
# -*- coding:utf-8-*-
# 处理中文字符的情况将
import codecs
import re
import os
import sys
import chardet
import xlsxwriter
reload(sys)
sys.setdefaultencoding('utf-8')

m_str = {}

extensions = {'.lua'} #需要遍历文件的扩展名

ignoresDir = {".git", ".gitattributes", "config"} # 忽略的目录
ignoresFile = {}#忽略的文件

# 忽略规则
ignorerules = {ur'print\(\".*[\u4e00-\u9fa5]+.*\".*\)',  #忽略print后面的中文
               ur'\-\-.*[\u4e00-\u9fa5]+.*'} #忽略注释中的中文
# 匹配规则 截取前后n位
rules = ([ur'\"[\u4e00-\u9fa5]+\"', 1], # 刷选 "中文"
         [ur'\[\[[\u4e00-\u9fa5]+\]\]', 2], # 刷选 [[中文]]
         [ur'\[\[.*[\u4e00-\u9fa5]+.*\]\]', 2], # 刷选 [[da 中文 da]]
         [ur'\".*[\u4e00-\u9fa5]+.*\"', 1]) # 刷选 "da 中文 da"

extrules = {ur'[\u4e00-\u9fa5]+',}

index = 100000  # id 开始位置

class StringAttr:
    _string = ""
    _id = -1
    _count = 0

    def __init__(self, string, ID):
        self._string = string
        self._id = ID
        self._count = 0


def main():
    # root = raw_input("Enter a path: ")
    root = r''
    root = root.replace("\r", "")
    current_dir = os.path.realpath(root)
    foreachPath(current_dir)
    output2Excel()

# 遍历路径
def foreachPath(curPath):
    exists = os.path.exists(curPath)
    if exists == False:
        print("the file is not exists! file path = " + curPath)
        return
    filePath = os.listdir(curPath)
    for file in filePath:
        fullPath = os.path.join(curPath, file)
        isFile = os.path.isfile(fullPath)

        if isFile:
            oprateFile(fullPath, file)
        else:
            oprateDir(fullPath, file)


def oprateDir(fullPath, fileName):
    flag = True
    for ignore in ignoresDir:
        if ignore == fileName:
            flag = False
    if flag:
        foreachPath(fullPath)


def oprateFile(fullPath, fileName):
    flag = True
    for ignore in ignoresFile:
        if ignore == fileName:
            flag = False
    if flag:
        _, fileType = os.path.splitext(fullPath)
        for ext in extensions:  # 匹配扩展名
            if ext == fileType:
                marryChinese(fullPath)


# 匹配中文
def marryChinese(fullPath):
    print("marryChinese = {}\n".format(fullPath))
    fileData = openFile(fullPath)
    result = fileData

    for rule in ignorerules:
        pattern = re.compile(rule)
        searchs = pattern.findall(fileData)
        if searchs:
            flag = True
            for search in searchs:
                get_string_id = u"--------------------------------------"
                fileData = fileData.replace(search, get_string_id)

    exchanges = {}
    i = 0
    for rule in rules:
        pattern = re.compile(rule[0])
        searchs = pattern.findall(fileData)
        if searchs:
            
            for search in searchs:
                chineseStr = search[rule[1]:len(search)]
                chineseStr = chineseStr[0:len(chineseStr) - rule[1]]
                if not m_str.has_key(chineseStr):
                    m_str[chineseStr] = StringAttr(chineseStr, getString_ID())
                temp = m_str[chineseStr]
                temp._count = temp._count + 1
                m_str[chineseStr] = temp
                get_string_id = u"GET_STRING({})".format(
                    temp._id)  # 将优先级高的规则匹配完抛弃
                fileData = fileData.replace(search, get_string_id)
                exchanges[i] = StringAttr(search, temp._id)
                i = i + 1
    flag = False
    # for rule in extrules:
    #     flag = True
    #     pattern = re.compile(rule)
    #     searchs = pattern.findall(fileData)
    #     if searchs:
    #         for search in searchs:
    #             result = result.replace(search, "-----------------------------------------")
    
    for strKey in exchanges:  # 真正在文件上操作
        flag = True
        strV = exchanges[strKey]
        get_string_id = u"GET_STRING({})".format(strV._id)
        result = result.replace(strV._string, get_string_id)
        print("replace path = {} old = {} new = {}\n".format(
            fullPath, strV._string, get_string_id))

    if flag:
        output2File(fullPath, result)


def opStr(str):
    if m_str.has_key(str):
        return
    m_str[str] = StringAttr(str, getString_ID())


def getString_ID():
    global index
    index = index + 1
    return index


def openFile(fullPath):
    file = open(fullPath)
    filedata = file.read()
    filedata = filedata.decode('utf-8')
    print("openFile = {}\n".format(fullPath))
    file.close()
    return filedata


def output2File(fullPath, fileData):
    print("outputFile = " + fullPath)
    file = open(fullPath, "w+")
    file.write(fileData)
    # 关闭文件
    file.close()

# 输出到Excel


def output2Excel():
    workbook = xlsxwriter.Workbook('string.xlsx')  # 建立文件

    worksheet = workbook.add_worksheet("sheel1")

    worksheet.write('A1', 'ID')
    worksheet.write('B1', 'STRING')
    worksheet.write('C1', 'COUNT')
    worksheet.excel2003_style
    strIndex = 1
    for str in m_str:
        strAttr = m_str[str]
        worksheet.write(strIndex, 0, strAttr._id)
        worksheet.write(strIndex, 1, strAttr._string.encode("utf-8"))
        worksheet.write(strIndex, 2, strAttr._count)
        strIndex = strIndex + 1
    print(strIndex)
    workbook.close()

# 输出到代码


if __name__ == '__main__':
    main()
