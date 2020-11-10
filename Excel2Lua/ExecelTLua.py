import os
import sys
import xlrd
import math
import shutil
reload(sys)
sys.setdefaultencoding('utf8')

MAXSIZE = 5

def convertCoding(path):
    return path.decode('gbk').encode('utf-8')

config_path = ""
lua_path = ""
if len(sys.argv) > 2:
    config_path = convertCoding(sys.argv[1])
    lua_path = convertCoding(sys.argv[2])

# 获取某个路径下的所有文件
def readFilename(file_dir):
    for root, dirs, files in os.walk(file_dir):
        return files, dirs, root


class ChangeCenter:
    def __init__(self):
        pass
    #读操作
    def getValue(self, path, fileName):
        self.mData = ""
        xlsfile = xlrd.open_workbook(path)
        table = xlsfile.sheet_by_index(0)  # sheet1
        rownum = table.nrows  # 行
        colsnum = table.ncols  # 列
        #定义提示语
        self.mData = self.mData + \
            "--[[Notice: This lua config file is auto generate by {}，don't modify it manually! --]]\n\n".format(
                fileName)

        #定义头
        indexDataStr = "local indexData = {\n"
        indexData = {}
        for j in range(1, colsnum):
            desc = table.cell_value(1,j)
            name = table.cell_value(2,j)
            type = table.cell_value(3,j)
            indexData[j] = type
            indexDataStr += "\t{} = {}, \t\t\t-- type = {} desc = {}\n".format(name, j, type, desc)
        indexDataStr += "} \n\n"

        self.mData += indexDataStr

        #遍历每一行
        configStr = "local config = {\n"
        for row in range(MAXSIZE, rownum):
            item = "\t[{}] = ".format(row - MAXSIZE + 1)
            item += "{"
            for col in range(1,colsnum):  
                if table.cell_value(row, col) == "":
                    continue
                if indexData[col] == "string":
                    item += ' [{}] = "{}", '.format(col, table.cell_value(row, col))
                elif indexData[col] == "number":
                    num = table.cell_value(row, col)
                    if math.floor(num) == num:
                        item += " [{}] = {}, ".format(col, int(num))
                    else:
                        item += " [{}] = {}, ".format(col, num)
                elif indexData[col] == "table": 
                    str = table.cell_value(row, col)
                    str = str.replace("[", "{")
                    str = str.replace("]", "}")
                    item += " [{}] = {}, ".format(col, str)
            item += " },\n"
            configStr+= item
        configStr += "}\n"

        # 定义metetable
        self.mData+=configStr
        str ="local mt = { }\n" +"mt.__index = function(t,k)\n" +"\tif indexData[k] then\n" +"\t\treturn rawget(t,indexData[k]) \n" +"\tend\n" +"\treturn\n" +"end\n" +"mt.__newindex = function(t,k,v)\n" +"\terror('do not edit config')\n" +"end\n" +"mt.__metatable = false\n" +"for _,v in pairs(config) do\n\t" +"setmetatable(v,mt)\n" +"end\n\n" +"return config"

        self.mData += str
        print(self.mData)

    #写操作
    def write(self, path, filename):
        if not os.path.exists(path):
            os.makedirs(path)
        csvfile = file("tmp", "wb")
        csvfile.write(self.mData)
        csvfile.close()

        if os.path.exists(os.path.join(path, filename+".old")):
            os.remove(os.path.join(path, filename+".old"))
        if os.path.exists(os.path.join(path, filename)):
            os.remove(os.path.join(path, filename))
        os.rename('tmp', os.path.join(path, filename))

#遍历所有文件
def handleExcel():  
    files, dirs, root = readFilename(config_path)
    for file in files:
        splitext = os.path.splitext(file)
        fileName = splitext[0]
        ext = splitext[1]
        if ext == ".xls" or ext == ".xlsx":
            fullPath = os.path.join(config_path, file)
            if os.path.exists(fullPath):
                try:
                    center = ChangeCenter()
                    center.getValue(fullPath, fileName )
                    center.write(lua_path, fileName+ ".lua")
                except BaseException:
                    print("ERROR!!!!!!! path = {}".format(fullPath))

if __name__ == '__main__':
    
    if lua_path == "":
        lua_path = "F:\projects\my\Utils\Excel2Lua\lua"
    if config_path == "":
        config_path = "F:\projects\my\Utils\Excel2Lua"

    if os.path.isdir(lua_path):
        shutil.rmtree(lua_path)

    if not os.path.isdir(lua_path):
        os.makedirs(lua_path)
    handleExcel()
