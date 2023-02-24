/**
* @brief C++ base64 编解码
* @author wid
* @date 2013-20-25
*
* @note 若代码存在 bug 或程序缺陷, 请留言反馈, 谢谢!
*/

#include "memory.hpp"
//base64 编解码函数声明
string b64encodestring(const string &strString);      //对 ASCII 字符串进行 base64 编码
string b64decodestring(const string &strString);      //对 base64 编码后的字符串进行解码

//base64 编解码函数实现
/**
* @brief 对 ASCII 字符串进行 base64 编码
*
* @param strString 待编码的字符串
*
* @return srs::string 返回编码后的字符串
*
* @note 对于字符串中含有非 ASCII 字符串型的字符, 代码将抛出 string 型异常, 请捕获
*/
string b64encodestring(const string &strString)
{
    int nByteSrc = strString.length();
    string pszSource = strString;

    int i = 0;
    for(i; i < nByteSrc; i++)
        if( pszSource[i] < 0 || pszSource[i] > 127 )
            throw "can not encode Non-ASCII characters";

    const char *enkey = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    string pszEncode(nByteSrc*4/3 + 4, '\0');
    int nLoop = nByteSrc %3 == 0 ? nByteSrc : nByteSrc - 3;
    int n = 0;
    for(i=0; i < nLoop; i+=3 )
    {
        pszEncode[n] = enkey[pszSource[i]>>2];
        pszEncode[n+1] = enkey[((pszSource[i]&3)<<4) | ((pszSource[i+1] & 0xF0)>>4)];
        pszEncode[n+2] = enkey[((pszSource[i+1] & 0x0f)<<2) | ((pszSource[i+2] & 0xc0 )>>6)];
        pszEncode[n+3] = enkey[pszSource[i+2] & 0x3F];
        n += 4;
    }

    switch(nByteSrc%3)
    {
    case 0:
        pszEncode[n] = '\0';
        break;

    case 1:
        pszEncode[n] = enkey[pszSource[i]>>2];
        pszEncode[n+1] = enkey[((pszSource[i]&3)<<4) | ((0&0xf0)>>4)];
        pszEncode[n+2] = '=';
        pszEncode[n+3] = '=';
        pszEncode[n+4] = '\0';
        break;

    case 2:
        pszEncode[n] = enkey[pszSource[i]>>2];
        pszEncode[n+1] = enkey[((pszSource[i]&3)<<4) | ((pszSource[i+1]&0xf0)>>4)];
        pszEncode[n+2] = enkey[(( pszSource[i+1]&0xf)<<2 ) | ((0&0xc0)>>6)];
        pszEncode[n+3] = '=';
        pszEncode[n+4] = '\0';
        break;
    }

    return pszEncode.c_str();
}

/**
* @brief 对 base64 编码后的字符串进行解码
*
* @param strString 待解码的字符串
*
* @return string 返回解码后的字符串
*
* @note 对于非base64编码的字符串或已损坏的base64字符串进行解码会抛出 string 型异常, 请捕获
*/
string b64decodestring(const string &strString)
{
    int nByteSrc = strString.length();
    string pszSource = strString;

    const int dekey[] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        62, // '+'
        -1, -1, -1,
        63, // '/'
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, // '0'-'9'
        -1, -1, -1, -1, -1, -1, -1,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, // 'A'-'Z'
        -1, -1, -1, -1, -1, -1,
        26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
        39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, // 'a'-'z'
    };

    if(nByteSrc%4 != 0)
        throw "bad base64 string";

    string pszDecode(nByteSrc*3/4+4, '\0');
    int nLoop = pszSource[nByteSrc-1]  == '=' ? nByteSrc - 4 : nByteSrc;
    int b[4];
    int i = 0, n = 0;
    for(i = 0; i < nLoop; i += 4 )
    {
        b[0] = dekey[pszSource[i]];        b[1] = dekey[pszSource[i+1]];
        b[2] = dekey[pszSource[i+2]];    b[3] = dekey[pszSource[i+3]];
        if(b[0] == -1 || b[1] == -1 || b[2] == -1 || b[3] == -1)
            throw "bad base64 string";

        pszDecode[n] = (b[0] << 2) | ((b[1] & 0x30) >> 4);
        pszDecode[n+1] = ((b[1] & 0xf) << 4) | ((b[2] & 0x3c) >> 2);
        pszDecode[n+2] =  ((b[2] & 0x3) << 6) | b[3];

        n+=3;
    }

    if( pszSource[nByteSrc-1] == '=' && pszSource[nByteSrc-2] == '=' )
    {
        b[0] = dekey[pszSource[i]];        b[1] = dekey[pszSource[i+1]];
        if(b[0] == -1 || b[1] == -1)
            throw "bad base64 string";

        pszDecode[n] = (b[0] << 2) | ((b[1] & 0x30) >> 4);
        pszDecode[n+1] = '\0';
    }

    if( pszSource[nByteSrc-1] == '=' && pszSource[nByteSrc-2] != '=' )
    {
        b[0] = dekey[pszSource[i]];        b[1] = dekey[pszSource[i+1]];
        b[2] = dekey[pszSource[i+2]];
        if(b[0] == -1 || b[1] == -1 || b[2] == -1)
            throw "bad base64 string";

        pszDecode[n] = (b[0] << 2) | ((b[1] & 0x30) >> 4);
        pszDecode[n+1] = ((b[1] & 0xf) << 4) | ((b[2] & 0x3c) >> 2);
        pszDecode[n+2] = '\0';
    }

    if( pszSource[nByteSrc-1] != '=' && pszSource[nByteSrc-2] != '=' )
        pszDecode[n] = '\0';

    return pszDecode;
}

//测试
int main()
{
    ///编码测试
    string str1 = "Hello, world!";
    cout << "对Hello, world!进行base64编码: " << b64encodestring(str1) << endl;

    ///解码测试
    string str2 = "SGVsbG8sIHdvcmxkIQ==";
    cout << "对SGVsbG8sIHdvcmxkIQ==进行base64解码: " << b64decodestring(str2) << endl;

    ///编码耗时测试
    string str3(10000000, 'A');    //生成 10000000 长的字符串
    cout << endl << "对 10000000 长的字符串进行编码耗时测试.." << endl;
    size_t t0 = clock();        //编码计时开始
    b64encodestring(str3);
    cout << "测试结束, 耗时 " << clock() - t0 << "ms" << endl;

    ///解码耗时测试
    string str4 = b64encodestring(str3);        //得到长度为 10000000 的字符串base64编码后的字符串
    cout << endl << "对 " << str4.length() << " 长的base64字符串进行解码耗时测试.." << endl;
    size_t t1 = clock();        //解码计时开始
    b64decodestring(str3);
    cout << "测试结束, 耗时 " << clock() - t1 << "ms" << endl;

    return 0;
}