// �ַ���ת������
#pragma once
#include <string>
#include <vector>

#ifdef COMMON_MODULE
#define EXPORTCOMMONCLASS __declspec(dllexport)
#define EXPORTCOMMONAPI __declspec(dllexport)
#else
#define EXPORTCOMMONCLASS __declspec(dllimport)
#define EXPORTCOMMONAPI __declspec(dllimport)
#endif


class EXPORTCOMMONCLASS StringTool
{
public:
	static std::string Wchar_tToString(const wchar_t* wchar);

	/// @brief stringתwstring
	static std::wstring StrToWStr(const std::string& strValue);
	/// @brief wstringתstring
	static std::string WStrToStr(const std::wstring& strValue);
	/// @brief  UTF8תUnicode
	static std::wstring UTF8ToUnicode(const std::string& str);
	/// @brief  UnicodeתUTF8
	static std::string UnicodeToUTF8(const std::wstring& str);
	/// @brief  ANSIתUnicode
	static std::wstring ANSIToUnicode(const std::string& str);
	/// @brief  UnicodeתANSI
	static std::string UnicodeToANSI(const std::wstring& str);
	/// @brief UTF8תGBK
	static std::string UTF8ToGBK(const std::string& strUtf8);
	/// @brief GBKתUTF8
	static std::string GBKToUTF8(const std::string& strGBK);

	/// @brief wstringת��double
	static int StrToInt(const std::wstring& strValue);
	/// @brief wstringת��double
	static double StrToDouble(const std::wstring& strValue);
	/// @brief intת��wstring
	static std::wstring IntToStr(int nValue, int nRadix = 10);
	/// @brief doubleת��wstring
	static std::wstring DoubleToStr(const double& dValue, int accuracy = 8);

	/// @brief �ָ��ַ���
	static bool SplitStr(const std::wstring& str, const std::wstring& tag, std::vector<std::wstring>& vec);
	/// @brief �ַ���strValue�Ƿ�ȫΪstrInclude�ַ����
	static bool SpanIncluding(const std::wstring& strValue, const std::wstring& strInclude);

	/// @brief תСд
	static std::wstring ToLower(const std::wstring& strValue);
	/// @brief ת��д
	static std::wstring ToUpper(const std::wstring& strValue);

	/// @brief �Ƿ�����
	static bool IsDigit(const wchar_t& ch);
	static bool IsDigit(const std::wstring& strValue);
	/// @brief �Ƿ���ĸ
	static bool IsAlpha(const wchar_t& ch);
	static bool IsAlpha(const std::wstring& strValue);
	/// @brief �Ƿ�Сд��ĸ
	static bool IsLower(const wchar_t& ch);
	static bool IsLower(const std::wstring& strValue);
	/// @brief �Ƿ��д��ĸ
	static bool IsUpper(const wchar_t& ch);
	static bool IsUpper(const std::wstring& strValue);

	/// @brief ��ʽ���ַ���
	static std::string& StringFormat(std::string & _str, const char * _Format, ...);
	static std::wstring& WStringFormat(std::wstring & _str, const wchar_t * _Format, ...);

#ifdef QT
	static QString TCharToQString(const TCHAR* wp, size_t codePage = CP_ACP);
	static TCHAR* QStringToTChar(const QString &str);
	static std::string GBK2UTF8(const QString& qStr);
#endif

	static unsigned long getHashCode(const char* arkey, unsigned int nkeylength);
};
